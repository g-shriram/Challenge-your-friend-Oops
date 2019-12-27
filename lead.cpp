
void heapify(viewdetails arr[], int n, int i)
{
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(viewdetails arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i=n-1; i>=0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

void leadba()
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
   heapSort(arr, i);
   int x=1;
 cout<<"\n\n---------LeaderBoard----------\n\n";
   while(i--)
  {
    cout<<"\n\nRank : "<<x<<'\n';
    vdetails(arr[i].u.username);
    x++;
  }
   cout<<i;
    fclose(fptr);
}



void leadbf()
{
   viewdetails arr[100];
    user u;
    FILE *fptr;
    int i;
    fptr=fopen("user.txt","r");
   i=0;
   while(fread(&u,sizeof(user),1,fptr))
   {
       flag=0;
       fcheck(u.username);
       if(flag==3){
            flag=0;
      arr[i]=vget(u.username);
      i++;}
   }
   arr[i++]=vget(username.username);

   heapSort(arr, i);
   int x=1;
 cout<<"\n\n---------LeaderBoard----------\n\n";
   while(i--)
  {
    cout<<"\n\nRank : "<<x<<'\n';
    vdetails(arr[i].u.username);
    x++;
  }
   cout<<i;
    fclose(fptr);
}


int leadba1()
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
   heapSort(arr, i);
int x=1;
   while(i--)
   {
       if(strcmp(arr[i].u.username,username.username)==0)
       {
           return x;
           break;
       }
      x++;
   }

    fclose(fptr);
}



int leadbf1()
{
   viewdetails arr[100];
    user u;
    FILE *fptr;
    int i;
    fptr=fopen("user.txt","r");
   i=0;
   while(fread(&u,sizeof(user),1,fptr))
   {
       flag=0;
       fcheck(u.username);
       if(flag==3){
            flag=0;
      arr[i]=vget(u.username);
      i++;}
   }
   arr[i++]=vget(username.username);
   heapSort(arr, i);
int x=1;
      while(i--)
   {

       if(strcmp(arr[i].u.username,username.username)==0)
       {
           return x;
           break;
       }
       x++;
   }

    fclose(fptr);
}


void leaderb()
{
    int ch;
    cout<<"\nPress 1 to view leaderboard among friends...\nPress 2 to view leaderboard among all...\nPress 3 to view your place in leaderboard ...\n" ;
    cin>>ch;

     if(ch==1)
        leadba();
     if(ch==2)
        leadbf();
     if(ch==3)
     {
         int a,f;
         a=leadba1();
         f=leadbf1();

         cout<<"\n\nYou got "<<a<<" place in overall leaderboard...\n";
              cout<<"\n\nYou got "<<f<<" place in your friends leaderboard...\n";
     }


}


