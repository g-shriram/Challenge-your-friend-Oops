int sign()
{
	int i;
	char ch;
	user u,u1;
	int fl=0,c;
		FILE *fp;
		fp=fopen("user.txt","r");
		cout<<"\n\nLogin\n\n";

	while(1)
	{
		fseek(fp, 0, SEEK_SET);
		cout<<"\nEnter your username...";
		cin>>u.username;
		if(strcmp(u.username,"admin")==0)
        {
             cout<<"\nEnter your pin : ";
            cin>>u.pin;
            if(strcmp(u.pin,"2311")==0)
            {

                flag=1;
                     strcpy(username.username,"admin");
                     return 0;
            }
            else{
                cout<<"Invalid Pin...\nTry again...\n";
                continue;
            }
        }
			while(fread(&u1,sizeof(user),1,fp)){
				if(strcmp(u.username,u1.username)==0)
				{
					fl=1;
					break;
				}
			}
				if(fl==1){
					fl=0;
					cout<<"\nEnter your pin : ";
					i=0;
						while (i<4){
    					u.pin[i]=getch();
					    ch=u.pin[i];
					    printf("*");
  						  i++;
						}
						u.pin[i]='\0';
						i=0;
					if(strcmp(u.pin,u1.pin)==0){
				  username=u1;
					flag=1;
					break;
					}
					else
					{
						cout<<"\nInvalid Pin...\nTry Again...\n";
						continue;
					}
				}
				else{
					cout<<"\nUsername not found...\nPress 1 to Try  again...\n";
					cin>>c;
					if(c!=1)
					break;

				}
	}

fclose(fp);
   return 0;
}

int reg()
{
	user u,u1;
		FILE *f1;
		f1=fopen("user.txt","r");
	fseek(f1, 0, SEEK_SET);
	cout<<"\n\nRegistering\n\n";
	int fl=0,i=0;
	char ch;
	while(1){
			cout<<"\nEnter user name : ";
			cin>>u.username;
				while(fread(&u1,sizeof(user),1,f1)){
				if(strcmp(u.username,u1.username)==0)
				{
					cout<<"\nUsername aldready taken , Try different...";
					fl=1;
					break;
				}
			}
				if(fl==1){
				fl=0;fseek(f1, 0, SEEK_SET);
				continue;}


			cout<<"\nEnter your pin (4 digits): ";
		while (i<4){
    u.pin[i]=getch();
    ch=u.pin[i];
    if(ch=='\n') break;
    else printf("*");
    i++;
}
u.pin[i]='\0';
i=0;
break;

	}

	fclose(f1);

	FILE *f;
	f=fopen("user.txt","a");


if(fwrite(&u,sizeof(user),1,f))
	{
	    char  notify[100];
		strcpy(notify,"New user is registered  :");
        strcat(notify,u.username);
	nwrite("admin",notify);
	ipwrite(u);
}
	else
	cout<<"\nError Registering...Try Again...\n";

	fclose(f);
}
void signin()
{
	int choice;
	flag=0;

	while(flag==0){
	cout<<"\nPress 1 to register...\nPress 2 to sign in...\nPress  0 to exit...\n\n";
	cin>>choice;
	if(choice==1)
	reg();
	else if(choice==2)
	sign();
	else if(choice==0)
	exit(0);

}
}
