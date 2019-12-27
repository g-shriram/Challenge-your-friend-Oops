void pget()
{
	char user[110],user1[110];
	strcpy(user,"points/");
	strcat(user,username.username);
	strcat(user,".dat");
	
	FILE *f;
	f=fopen(user,"r");
	fseek(f, 0, SEEK_SET);
	fread(&p,sizeof(points),1,f);
	
	fclose(f); 
}

void pwrite(float x)
{
	char user[110],user1[110];
	strcpy(user,"points/");
	strcat(user,username.username);
	strcat(user,".dat");
	strcpy(p.username,username.username);
	p.point=x;
	FILE *f;
	f=fopen(user,"w");
	fseek(f, 0, SEEK_SET);
	fwrite(&p,sizeof(points),1,f);
	
	fclose(f); 
}
void ipwrite(user u)
{
	char user[110],user1[110];
	strcpy(user,"points/");
	strcat(user,u.username);
	strcat(user,".dat");
	strcpy(p.username,u.username);
	p.point=1000.0;
	FILE *fp;
	fp=fopen(user,"w");
	fseek(fp, 0, SEEK_SET);
	fwrite(&p,sizeof(points),1,fp);
	
	fclose(fp); 
	 
	 
		cout<<"\nRegistered successfully...\nYou were rewarded 1000 points...\n";
	getch();
}
