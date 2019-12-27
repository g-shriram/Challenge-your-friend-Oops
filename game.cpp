
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;





int flag=0;

#include "classes.cpp"

user username;
points p;
	notify n;


#include "points.cpp"
#include "notification.cpp"
#include "reg_log.cpp"
#include "friend.cpp"
#include "statics.cpp"
#include "view.cpp"
#include "challenge.cpp"
#include "lead.cpp"
#include "avl tree.cpp"


void admin();
void user();

int main()
{

	loop:
	signin();

	if(strcmp(username.username,"admin")==0)
    {
        admin();
    }
	else
        {
           user();
        }


	goto loop;

}
void user()
{
    system("cls");
	pget();

	int choice;

	do{


	cout<<"\nWELCOME "<<username.username<<" to the game...\n\n\n\n\n";
		if(ncheck())
	{
		cout<<"\n\n********* You have some notifications *********\n\n";
	}

		cout<<"\nPress 1 to view your details...\nPress 2 to challenge your friend...\nPress 3 to accept challenge...\nPress 4 to add friends...\nPress 5 to accept friend request...\nPress 6 to view friends...\nPress 7 to view notifications...\nPress 8 to compare status...\nPress 9 to view leadership board...\nPress 0 to exit...\n";
		cin>>choice;
		switch(choice)
		{
			case 0:break;
			case 1:vdetails(username.username);break;
			case 2:challenge1();break;
			case 3:viewchallenge();break;
			case 4:addfriend();break;
			case 5:acceptfriend();break;
			case 6:viewfriend();break;
			case 7:viewnotification();break;
			case 8:compare();break;
			case 9:leaderb();break;
		}

	}while(choice!=0);
}
void admin()
{
    viewdetails *root=NULL;

    root=insertavl(root);

    int choice;

	do{


	cout<<"\nWELCOME "<<username.username<<" to the game...\n\n\n\n\n";
		if(ncheck())
	{
		cout<<"\n\n********* You have some notifications *********\n\n";
	}

		cout<<"\nPress 1 to list users...\nPress 2 view users...\nPress 3 to view leaderboard...\nPress 4 to view notifications...\nPress 5 to compare status...\nPress 0 to exit...\n";
		cin>>choice;
		switch(choice)
		{
			case 0:break;
			case 1:displayavl(root);break;
			case 2:avlsearch(root);break;
			case 4:viewnotification();break;
			case 5:compareavl(root);break;
			case 3:leadba();break;
		}

	}while(choice!=0);

}
