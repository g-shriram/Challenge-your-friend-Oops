void vdetails(char u[100])
{
    char file[100];
    viewdetails v;
    FILE *fptr;

    strcpy(file,"challenge/");
    strcat(file,u);
    strcat(file,".dat");
    fptr=fopen(file,"r");

    fread(&v.c,sizeof(challenge),1,fptr);
    fclose(fptr);

      strcpy(file,"points/");
    strcat(file,u);
    strcat(file,".dat");
    fptr=fopen(file,"r");

    fread(&v.p,sizeof(points),1,fptr);
    fclose(fptr);

  strcpy(v.u.username,u);
  if(strcmp(v.u.username,username.username)==0)
    strcpy(v.u.pin,username.pin);
  else
    strcpy(v.u.pin,"****");

  cout<<"\nUsername : "<<v.u.username;
  cout<<"\nPassword : "<<v.u.pin;
  cout<<"\nPoints : "<<v.p.point;
  cout<<"\nChallenge  Given  : "<<v.c.chalg;
  cout<<"\nChallenge  Accepted  : "<<v.c.chala;
  cout<<"\nChallenge  Won : "<<v.c.won;
  cout<<"\nChallenge  Lost  : "<<v.c.lost;

}

viewdetails vget(char u[100])
{

    char file[100];
    viewdetails v;
    FILE *fptr;

    strcpy(file,"challenge/");
    strcat(file,u);
    strcat(file,".dat");
    fptr=fopen(file,"r");

    fread(&v.c,sizeof(challenge),1,fptr);
    fclose(fptr);

      strcpy(file,"points/");
    strcat(file,u);
    strcat(file,".dat");
    fptr=fopen(file,"r");

    fread(&v.p,sizeof(points),1,fptr);
    fclose(fptr);

    strcpy(v.u.username,u);

return v;

}



void compare()
{
    char u[100];
    l:
    cout<<"\nEnter your friend name to compare ....\n";
    cin>>u;
    flag=0;
    fcheck(u);
    if(flag!=3)
    {
        cout<<"\nThe user is not your friend...\n";
        goto l;
    }
    flag=0;
    char file[100];
    viewdetails v,v1;
    FILE *fptr;

    strcpy(file,"challenge/");
    strcat(file,username.username);
    strcat(file,".dat");
    fptr=fopen(file,"r");

    fread(&v.c,sizeof(challenge),1,fptr);
    fclose(fptr);

      strcpy(file,"points/");
    strcat(file,username.username);
    strcat(file,".dat");
    fptr=fopen(file,"r");

    fread(&v.p,sizeof(points),1,fptr);
    fclose(fptr);

    v.u=username;


     strcpy(file,"challenge/");
    strcat(file,u);
    strcat(file,".dat");
    fptr=fopen(file,"r");

    fread(&v1.c,sizeof(challenge),1,fptr);
    fclose(fptr);

      strcpy(file,"points/");
    strcat(file,u);
    strcat(file,".dat");
    fptr=fopen(file,"r");

    fread(&v1.p,sizeof(points),1,fptr);
    fclose(fptr);

   strcpy(v1.u.username,u);

    cout<<" \n\n-----You-----";
  cout<<"\nUsername : "<<v.u.username;
  cout<<"\nPassword : "<<v.u.pin;
  cout<<"\nPoints : "<<v.p.point;
  cout<<"\nChallenge  Given  : "<<v.c.chalg;
  cout<<"\nChallenge  Accepted  : "<<v.c.chala;
  cout<<"\nChallenge  Won : "<<v.c.won;
  cout<<"\nChallenge  Lost  : "<<v.c.lost;

   cout<<"\n\n -----Your Friend-----";
  cout<<"\nUsername : "<<v1.u.username;
  cout<<"\nPassword : "<<v1.u.pin;
  cout<<"\nPoints : "<<v1.p.point;
  cout<<"\nChallenge  Given  : "<<v1.c.chalg;
  cout<<"\nChallenge  Accepted  : "<<v1.c.chala;
  cout<<"\nChallenge  Won : "<<v1.c.won;
  cout<<"\nChallenge  Lost  : "<<v1.c.lost;

}
