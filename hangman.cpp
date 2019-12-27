

void hlost(hang h)
{

    chall(username.username);
    chalw(h.username);

    char user[100];

     pget();
    float pt=p.point-h.points;
    pwrite(pt);

    strcpy(user,"points/");
	strcat(user,h.username);
	strcat(user,".dat");
	FILE *fp;
    fp=fopen(user,"r");
    points p1;

    fread(&p1,sizeof(points),1,fp);
    p1.point+=h.points;

    fclose(fp);
    fp=fopen(user,"w");

      fwrite(&p1,sizeof(points),1,fp);
	fclose(fp);

	cout<<"\nOops ....\n\nYou lost the challenge ...\n\nPoints lost : "<<h.points<<"\n\nPoints you have : ";
	pget();
	cout<<p.point;
	char notify[100];
	strcpy(notify,"Your friend ");
		strcat(notify,username.username);
		strcat(notify," lost your challenge ....\n\nYou earned points :");

	char buf[10];

    gcvt(h.points, 6, buf);

		strcat(notify,buf);
		strcat(notify,"\nCongrats...\n");
	nwrite(h.username,notify);


}

void hwon(hang h)
{
    chalw(username.username);
    chall(h.username);
    FILE *f;
    pget();
    float pt=p.point+h.points;
    pwrite(pt);

	cout<<"\nCongrats ....\n\nYou won the challenge ...\n\nPoints earned : "<<h.points<<"\n\nPoints you have : ";
	pget();
	cout<<p.point;
	char notify[100];
	strcpy(notify,"Your friend ");
		strcat(notify,username.username);
		strcat(notify," won your challenge ....\n\nYou lost points :");

	char buf[10];

    gcvt(h.points, 6, buf);

		strcat(notify,buf);
		strcat(notify,"\nBetter luck next time...\n");
	nwrite(h.username,notify);


}







void hgame(hang h){
	int i=0,j=0,f=0;
	while(h.cword[i]!='\0')
	{
		f=0;j=0;
		while(h.mletter[j]!='\0')
		{
			if(h.cword[i]==h.mletter[j])
			{
				f=1;
				break;
			}
			j++;
		}
		if(f==0)
		cout<<' '<<h.cword[i]<<' ';
		else
		cout<<'_';
		i++;
	}
}

void hwrite(char file[100],hang h)
{
    FILE *f;
	f=fopen(file,"a");
	fwrite(&h,sizeof(hang),1,f);
	cout<<"\nChallenge submitted successfully...\n";
		fclose(f);

}


void hangman()
{
	hang h;
	time_t my_time = time(NULL);
	while(1){
	cout<<"\nFix the challenge amount...\n";
    cin>>h.points;
    if(h.points>p.point)
    {
    	cout<<"\nFix the points less than what U have ...\nTry Again...\n";
    	continue;
	}
	cout<<"\nEnter the full word :\n";
	cin>>h.cword;

	if(strlen(h.cword)<5)
	{
		cout<<"\nEnter the word with minimum of 5 letters...\nTry Again...\n";
    	continue;
	}
	cout<<"\nEnter the letters to be hidden :\n";
	cin>>h.mletter;
	if(strlen(h.mletter)>strlen(h.cword)/2){
		cout<<"\nYou can only hide less then half of given words...\nTry Again...\n";
    	continue;
	}
	cout<<"\nEnter no of trial you want to give";
	cin>>h.chance;
		if(h.chance<=0)
	{
		cout<<"\nNo of trial should atleast 1";
		continue;
	}

	strcpy(h.time,ctime(&my_time));



	user u1;

	l:
	cout<<"\nEnter the name of user u want to challenge...\n";
	cin>>u1.username;
	flag=0;
	fcheck(u1.username);
	if(flag==3){
            chalg(username.username);
		strcpy(h.username,username.username);
	char file[100];
	strcpy(file,"challenge/hangman/");
	strcat(file,u1.username);
	strcat(file,".dat");
	hwrite(file,h);
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
    p1.point-=h.points;

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


void hanggame()
{
	hang h;
	char han[100];

	strcpy(han,"challenge/hangman/");
	strcat(han,username.username);
	strcat(han,".dat");

	FILE *f;
	f=fopen(han,"r");

	if(f==NULL)
	{
		cout<<"\nYou have no Hangman challenges ...";
		return;
	}

	if(f!=NULL)
	{
		cout<<"\nHangman Challenges ....";

		fseek(f, 0, SEEK_SET);
	int ch;
    while(fread(&h,sizeof(hang),1,f)){

    cout<<"\nChallenge From : "<<h.username<<"\nTime : "<<h.time<<"\nFixed points : "<<h.points<<"\n\nGiven word : ";
    hgame(h);

    cout<<"\n Can U Accept the challenge ...?(1 - Yes / 2 - Postpond / 0 - No)";
    cin>>ch;
    if(ch==1)
    {
    chala(username.username);
      cout<<"\nYou have "<<h.chance<<" trials ...\n";
	  int c=1;char cword[100],f=0;
	  while(c<=h.chance){
	  cout<<"\nTrial : "<<c;
	 	cout<<"\nEnter the correct word : ";
	 	cin>>cword;
	 	if(strcmp(cword,h.cword)==0)
	 	{ f=1;
	 		hwon(h);

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

	hlost(h);
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

    gcvt(h.points, 6, buf);

		strcat(notify,buf);
		strcat(notify," is refunded to you...\n");
	nwrite(h.username,notify);
	  char user[100];

	strcpy(user,"points/");
	strcat(user,h.username);
	strcat(user,".dat");
	FILE *fp;
    fp=fopen(user,"r");
    points p1;

    fread(&p1,sizeof(points),1,fp);
    p1.point+=h.points;

    fclose(fp);
    fp=fopen(user,"w");

      fwrite(&p1,sizeof(points),1,fp);
	fclose(fp);

	}
		else if(ch==2)
	{
//	dchalh(h);
	}


}

fclose(f);
}
	f=fopen(han,"r");
	fseek(f, 0, SEEK_SET);
	if(fread(&h,sizeof(hang),1,f))
	{
	}
	else
	remove(han);

		fclose(f);

}
