// C++ program to delete a node from AVL Tree
#include<bits/stdc++.h>


// A utility function to get maximum
// of two integers
int max(int a, int b);

// A utility function to get height
// of the tree
int height(viewdetails* b)
{
	if (b == NULL)
		return 0;
	return b->height;
}

// A utility function to get maximum
// of two integers
int max(int a, int b)
{
	return (a > b)? a : b;
}


viewdetails *rightRotate(viewdetails *y)
{
	viewdetails *x = y->left;
	viewdetails *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),
					height(y->right)) + 1;
	x->height = max(height(x->left),
					height(x->right)) + 1;

	// Return new root
	return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
viewdetails *leftRotate(viewdetails *x)
{
	viewdetails *y = x->right;
	viewdetails *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),
					height(x->right)) + 1;
	y->height = max(height(y->left),
					height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(viewdetails *b)
{
	if (b == NULL)
		return 0;
	return height(b->left) -
		height(b->right);
}

viewdetails* avlinsert(viewdetails* node,viewdetails* b)
{
	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(b);

	if (strcmp(b->u.username,node->u.username)<0)
		node->left = avlinsert(node->left, b);
	else if (strcmp(b->u.username,node->u.username)>0)
		node->right = avlinsert(node->right, b);
	else // Equal keys not allowed
		return node;


	node->height = 1 + max(height(node->left),
						height(node->right));


	int balance = getBalance(node);


	if (balance > 1 && strcmp(b->u.username,node->left->u.username)<0)
		return rightRotate(node);

	if (balance < -1 && strcmp(b->u.username,node->right->u.username)>0 )
		return leftRotate(node);

	if (balance > 1 && strcmp(b->u.username,node->left->u.username)>0 )
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}


	if (balance < -1 && strcmp(b->u.username,node->right->u.username)<0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}


	return node;
}







// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
void displayavl(viewdetails* root)
{
	if(root != NULL)
	{
		displayavl(root->left);
		root->display();
		cout<<"\n\n";
		displayavl(root->right);
	}
}



viewdetails* searchavl(viewdetails* root, char u[100])
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || strcmp(u,root->u.username)==0)
       return root;

    // Key is greater than root's key
    if (strcmp(u,root->u.username)<0)
       return searchavl(root->left, u);

    // Key is smaller than root's key
    return searchavl(root->right, u);
}

viewdetails * insertavl(viewdetails *root)
{
   viewdetails arr[100];
    user u;
    FILE *fptr;
    int i;
    fptr=fopen("user.txt","r");
   i=0;
   while(fread(&u,sizeof(user),1,fptr))
   {
      arr[i]=vget(u.username);
      i++;
   }


    while(i--)
  {
      viewdetails *vd=new viewdetails();
      vd=&arr[i];
      root=avlinsert(root,vd);

  }

   fclose(fptr);

   return root;

}

void avlsearch(viewdetails *root)
{
    viewdetails *vd;
    char u[100];
    cout<<"\nEnter username : ";
    cin>>u;
    vd=searchavl(root,u);
    if(vd!=NULL)
        vd->display();
}

void compareavl(viewdetails *root)
{
    viewdetails *vd;
    char u[100],u1[100];
    cout<<"\nEnter user 1 :";
    cin>>u;
    cout<<"\nEnter user 2 :";
    cin>>u1;
    vd=searchavl(root,u);
    if(vd!=NULL)
        vd->display();
        vd=searchavl(root,u1);
    if(vd!=NULL)
        vd->display();
}
