#include "hangman.cpp"
#include "jumble.cpp"



void challenge1()
{ 
	int choice; 
	cout<<"\nPress 1 to challenge with Hangman game...\nPress 2 to challenge with Jumble words game...";
	cin>>choice;
	if(choice==1)
	hangman();
	else if(choice==2)
	jumble();
	
}

void viewchallenge()
{
	
	hanggame();
	jumbgame();
}


