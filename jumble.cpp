



void jlost(jumb j)
{
        chall(username.username);
    chalw(j.username);
    char user[100];
     pget();
    float pt=p.point-j.points;
    pwrite(pt);
    strcpy(user,"points/");
	strcat(user,j.username);
	strcat(user,".dat");
	FILE *fp;
    fp=fopen(user,"r");
    points p1;

    fread(&p1,sizeof(points),1,fp);
    p1.point+=j.points;

    fclose(fp);
    fp=fopen(user,"w");

      fwrite(&p1,sizeof(points),1,fp);
	fclose(fp);

	cout<<"\nOops ....\n\nYou lost the challenge ...\n\nPoints lost : "<<j.points<<"\n\nPoints you have : ";
	pget();
	cout<<p.point;
	char notify[100];
	strcpy(notify,"Your friend ");
		strcat(notify,username.username);
		strcat(notify," lost your challenge ....\n\nYou earned points :");

	char buf[10];

    gcvt(j.points, 6, buf);

		strcat(notify,buf);
		strcat(notify,"\nCongrats...\n");
	nwrite(j.username,notify);


}

void jwon(jumb j)
{
    chalw(username.username);
    chall(j.username);
    FILE *f;
    pget();
    float pt=p.point+j.points;
    pwrite(pt);

	cout<<"\nCongrats ....\n\nYou won the challenge ...\n\nPoints earned : "<<j.points<<"\n\nPoints you have : ";
	pget();
	cout<<p.point;
	char notify[100];
	strcpy(notify,"Your friend ");
		strcat(notify,username.username);
		strcat(notify," won your challenge ....\n\nYou lost points :");

	char buf[10];

    gcvt(j.points, 6, buf);

		strcat(notify,buf);
		strcat(notify,"\nBetter luck next time...\n");
	nwrite(j.username,notify);


}


void jwrite(char file[100],jumb j)
{
    FILE *f;
	f=fopen(file,"a");
	fwrite(&j,sizeof(jumb),1,f);
	cout<<"\nChallenge submitted successfully...\n";
		fclose(f);

}


void jumble()
{
	jumb j;
	time_t my_time = time(NULL);
	while(1){
	cout<<"\nFix the challenge amount...\n";
    cin>>j.points;
    if(j.points>p.point)
    {
    	cout<<"\nFix the points less than what U have ...\nTry Again...\n";
    	continue;
	}
	cout<<"\nEnter the correct word :\n";
	cin>>j.cword;

	if(strlen(j.cword)<5)
	{
		cout<<"\nEnter the word with minimum of 5 letters...\nTry Again...\n";
    	continue;
	}
	cout<<"\nEnter the jumbled word :\n";
	cin>>j.jword;
	if(strlen(j.jword)!=strlen(j.cword)){
		cout<<"\nYou can only jumble the above given word...\nTry Again...\n";
    	continue;
	}
	cout<<"\nEnter no of trial you want to give";
	cin>>j.chance;
	if(j.chance<=0)
	{
		cout<<"\nNo of trial should atleast 1";
		continue;
	}

	strcpy(j.time,ctime(&my_time));



	user u1;

	l:
	cout<<"\nEnter the name of user u want to challenge...\n";
	cin>>u1.username;
	flag=0;
	fcheck(u1.username);
	if(flag==3){

            chalg(username.username);
		strcpy(j.username,username.username);
	char file[100];
	strcpy(file,"challenge/jumble/");
	strcat(file,u1.username);
	strcat(file,".dat");
	jwrite(file,j);
	char  notify[100];
	strcpy(notify,"You got a challenge from your friend  : ");
    strcat(notify,username.username);
	nwrite(u1.username,notify);
	cout<<"\nMatch points are deducted ";
  FILE *f;
	char user[100];
    strcpy(user,"points/");
	strcat(user,username.username);
	strcat(user,".dat");
    f=fopen(user,"r");
    points p1;

    fread(&p1,sizeof(points),1,f);
    p1.point-=j.points;

    fclose(f);
      f=fopen(user,"w");
      fwrite(&p1,sizeof(points),1,f);fclose(f);

  }
  else
  {
  	cout<<"\nThe user is not your friend...\nPress 1 to Try again...\n";
    int d;
    cin>>d;
    if(d==1)
  	goto l;
  }
	break;
  }
}

void jumbgame()
{
	jumb j;
	char jum[100];

	strcpy(jum,"challenge/jumble/");
	strcat(jum,username.username);
	strcat(jum,".dat");
	FILE *f1;
	f1=fopen(jum,"r");


	if(f1!=NULL)
	{
		cout<<"\nJumble word Challenges ....";

		fseek(f1, 0, SEEK_SET);
	int ch;
    while(fread(&j,sizeof(jumb),1,f1)){

    cout<<"\nChallenge From : "<<j.username<<"\nTime : "<<j.time<<"\nFixed points : "<<j.points<<"\n\nGiven word : "<<j.jword;

    cout<<"\n Can U Accept the challenge ...?(1 - Yes / 2 - Postpond / 0 - No)";
    cin>>ch;
    if(ch==1)
    {
        chala(username.username);
      cout<<"\nYou have "<<j.chance<<" trials ...\n";
	  int c=1;char cword[100],f=0;
	  while(c<=j.chance){
	  cout<<"\nTrial : "<<c;
	 	cout<<"\nEnter the correct word : ";
	 	cin>>cword;
	 	if(strcmp(cword,j.cword)==0)
	 	{ f=1;
	 		jwon(j);
	 		getch();
	 		break;
		 }
		 if(f==0)
	{
		cout<<"\nWrong Answer...Try again...\n";
	}
	c++;
	}

if(f==0)
{
	jlost(j);
}

	}
	else if(ch==0)
	{
		cout<<"\nChallenge rejected ...";
		char notify[100];
	strcpy(notify,"Your friend ");
		strcat(notify,username.username);
		strcat(notify," rejected your challenge ....\n\nMatch points :");

	char buf[10];

    gcvt(j.points, 6, buf);

		strcat(notify,buf);
		strcat(notify," is refunded to you...\n");
	nwrite(j.username,notify);
	  char user[100];

	strcpy(user,"points/");
	strcat(user,j.username);
	strcat(user,".dat");
	FILE *fp;
    fp=fopen(user,"r");
    points p1;

    fread(&p1,sizeof(points),1,fp);
    p1.point+=j.points;

    fclose(fp);
    fp=fopen(user,"w");

      fwrite(&p1,sizeof(points),1,fp);
	fclose(fp);

	}
		else if(ch==2)
	{
		//dchalj(j);
	}


}

//rchalj();
fclose(f1);	}



		f1=fopen(jum,"r");
	fseek(f1, 0, SEEK_SET);
	if(fread(&j,sizeof(jumb),1,f1))
	{
	}
	else
	remove(jum);

	fclose(f1);
}
