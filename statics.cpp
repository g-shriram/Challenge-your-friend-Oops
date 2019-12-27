void chalg(char un[100])
{
	challenge c;
	char file[100];
	strcpy(file,"challenge/");
	strcat(file,un);
	strcat(file,".dat");
	FILE *f;
	f=fopen(file,"r");
	if(fread(&c,sizeof(challenge),1,f))
	{
	  c.chalg+=1;
	  f=fopen(file,"w");
	  fwrite(&c,sizeof(challenge),1,f);
	 }
	 else{
	 	f=fopen(file,"w");
	 	strcpy(c.username,username.username);
	 	c.chala=0;
	 	c.chalg=1;
	 	c.lost=0;
	 	c.won=0;
	 	fwrite(&c,sizeof(challenge),1,f);
	 }
	fclose(f);
}

void chala(char un[100])
{
	challenge c;
	char file[100];
	strcpy(file,"challenge/");
	strcat(file,un);
	strcat(file,".dat");
	FILE *f;
	f=fopen(file,"r");
	if(fread(&c,sizeof(challenge),1,f))
	{
	  c.chala+=1;
	  f=fopen(file,"w");
	  fwrite(&c,sizeof(challenge),1,f);
	 }
	 else{
	 	f=fopen(file,"w");
	 	strcpy(c.username,username.username);
	 	c.chala=1;
	 	c.chalg=0;
	 	c.lost=0;
	 	c.won=0;
	 	fwrite(&c,sizeof(challenge),1,f);
	 }
	fclose(f);
}

void chalw(char un[100])
{
	challenge c;
	char file[100];
	strcpy(file,"challenge/");
	strcat(file,un);
	strcat(file,".dat");
	FILE *f;
	f=fopen(file,"r");
	if(fread(&c,sizeof(challenge),1,f))
	{
	  c.won+=1;
	  f=fopen(file,"w");
	  fwrite(&c,sizeof(challenge),1,f);
	 }
	 else{
	 	f=fopen(file,"w");
	 	strcpy(c.username,username.username);
	 	c.chala=0;
	 	c.chalg=0;
	 	c.lost=0;
	 	c.won=1;
	 	fwrite(&c,sizeof(challenge),1,f);
	 }
	fclose(f);
}

void chall(char un[100])
{
	challenge c;
	char file[100];
	strcpy(file,"challenge/");
	strcat(file,un);
	strcat(file,".dat");
	FILE *f;
	f=fopen(file,"r");
	if(fread(&c,sizeof(challenge),1,f))
	{
	  c.lost+=1;
	  f=fopen(file,"w");
	  fwrite(&c,sizeof(challenge),1,f);
	 }
	 else{
	 	f=fopen(file,"w");
	 	strcpy(c.username,username.username);
	 	c.chala=0;
	 	c.chalg=0;
	 	c.lost=1;
	 	c.won=0;
	 	fwrite(&c,sizeof(challenge),1,f);
	 }
	fclose(f);
}

