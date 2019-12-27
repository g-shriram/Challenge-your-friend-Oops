user check(char uname[100])
{
	user u1;
	FILE *fp;
		fp=fopen("user.txt","r");
		fseek(fp, 0, SEEK_SET);
	flag=2;
		while(fread(&u1,sizeof(user),1,fp)){
				if(strcmp(uname,u1.username)==0)
				{
					flag=4;
					fclose(fp);
					return u1;
				}
			}
			fclose(fp);
return u1;
}

void fcheck(char uname[100])
{
	FILE *f;
	char user[110];
	strcpy(user,"friend/");
	strcat(user,username.username);
	strcat(user,".dat");
	f=fopen(user,"r");
	if(f==NULL)
	{
	
		return;
	}
	
		fseek(f, 0, SEEK_SET);
	freq fr;
	while(fread(&fr,sizeof(freq),1,f)){
			if(strcmp(uname,fr.username)==0)	 
			{
				flag=3;
				break;
			}
	     }
	     fclose(f);
}
void addfriend()
{
	flag=0;
	user u1;
	char user[110];
	char uname[100];
	cout<<"\nEnter your friend username  : ";
	cin>>uname;
	flag=0;
	
	if(strcmp(uname,username.username)==0)
	flag=1;	
	if(flag!=1)
	u1=check(uname);
	if(flag!=2)
	fcheck(uname);

	if(flag==4){
		flag=0;
		
	strcpy(user,"friend/");
	strcat(user,u1.username);
	strcat(user,"req.dat");
	
	freq fr;
	  time_t my_time = time(NULL);
	strcpy(fr.username,username.username);
	strcpy(fr.time,ctime(&my_time));
	cout<<"\nRequest Sent ... Time : "<<fr.time;
	
	char  notify[100];
	strcpy(notify,"You have a friend request from  :");
 strcat(notify,username.username);
	nwrite(u1.username,notify);
	FILE *f;
	f=fopen(user,"a");
	
	fwrite(&fr,sizeof(freq),1,f);
	fclose(f); 
}
else
{
	switch(flag)
	{
		case 1:cout<<"\nYou can't be your friend...\n";break;
		case 2:cout<<"\nUser not found...\n";break;
		case 3:cout<<"\nThe user is aldready your friend...\n";break;
	}
}

}
void acceptfriend()
{
	char user[110];
	int ch;
	FILE *f;	
	strcpy(user,"friend/");
	strcat(user,username.username);
	strcat(user,"req.dat");
	f=fopen(user,"r");
	if(f==NULL)
	{
		cout<<"\nYou have no requests...\n";
		return ;
	}
	
	else
	{
		freq fr;
		while(fread(&fr,sizeof(freq),1,f)){
			flag=0;
			fcheck(fr.username);
			if(flag==3)
			{
				flag=0;
				continue;
			}
			
			cout<<"\nUsername : "<<fr.username<<'\t'<<"Time : "<<fr.time;
			cout<<"\nAccept request ..?(1 - Yes / 0 - No)";
			cin>>ch;
			if(ch==1){
				
				FILE *fpt;
	char user1[110];
    strcpy(user1,"friend/");
	strcat(user1,fr.username);
	strcat(user1,".dat");
	fpt=fopen(user1,"a");
	freq fr1;
	time_t my_time = time(NULL);
	strcpy(fr1.username,username.username);
	strcpy(fr1.time,ctime(&my_time));

fwrite(&fr1,sizeof(freq),1,fpt);
fclose(fpt);
FILE *fp;
	strcpy(user1,"friend/");
	strcat(user1,username.username);
	strcat(user1,".dat");
	fp=fopen(user1,"a");
	if(fp!=NULL)
	{
	fwrite(&fr,sizeof(freq),1,fp);
		cout<<"\nFriend Added Successfully...\n";
		
		char  notify[100];
		strcpy(notify,"Your friend request is accepted by  :");
        strcat(notify,username.username);
	nwrite(fr.username,notify);
	}
	 fclose(fp);			
			}	 
	     }
	}
	
		fclose(f);
	remove(user);	
}

void viewfriend()
{
	cout<<"\nYour friend list :\n";
	FILE *f;
	char user[110];
	strcpy(user,"friend/");
	strcat(user,username.username);
	strcat(user,".dat");
	f=fopen(user,"r");
	if(f==NULL)
	{
		cout<<"\nYou have no friends...\n";
		return;
	}
	fseek(f, 0, SEEK_SET);
	freq fr;
	while(fread(&fr,sizeof(freq),1,f)){
			cout<<"\nUsername : "<<fr.username<<'\t'<<"Time : "<<fr.time;	 
	     }
	     fclose(f);
}
