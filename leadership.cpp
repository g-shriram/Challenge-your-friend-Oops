void clead()
{
   
	user u1;
	challenge c1;
		points p1;
	
	lead l;
	FILE *f;
	f=fopen("user.txt","r");
	fseek(f, 0, SEEK_SET);
	while(&u1,sizeof(user),1,f)
	{
		
		FILE *f1,*f2;
	
		char file[100];
		strcpy(file,"challenge/");
		strcat(file,u1.username);
		strcat(file,".dat");
		f1=fopen(file,"r");
		strcpy(file,"points/");
		strcat(file,u1.username);
		strcat(file,".dat");
		f2=fopen(file,"r");
		
		fread(&c1,sizeof(challenge),1,f1);
		fread(&p1,sizeof(points),1,f2);
		l.c5=c1;
		l.p5=p1;
		strcpy(l.username,u1.username);
		cout<<l.username<<l.p5.point<<l.c5.won;
		fclose(f1);fclose(f2);
		
	}
	fclose(f);
}
void leadership()
{
	int ch;
	cout<<"Press 1 to view leadership among your friends...\nPress 2 to view leadership among all users...\n";
	cin>>ch;
	if(ch==1)
	{
		
	}
	else if(ch==2)
	{
		lead();
	}
}
