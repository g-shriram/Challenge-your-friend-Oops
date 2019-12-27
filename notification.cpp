void nwrite(char uname[100],char notification[100])
{
	FILE *f1;
	 char file[100];
 

 
 strcpy(file,"notification/");
 strcat(file,uname);
 strcat(file,".dat");

	
	time_t my_time = time(NULL);
	FILE *f;
	f=fopen(file,"a");
	strcpy(n.notification,notification);
strcpy(n.time,ctime(&my_time));
	fwrite(&n,sizeof(notify),1,f);
	fclose(f);
	
	
}

int ncheck()
{
 FILE *f;
 char file[100];
 strcpy(file,"notification/");
 strcat(file,username.username);
 strcat(file,".dat");
 f=fopen(file,"r");
 if(f!=NULL){
 		fclose(f);
 		 return 1;
 }

 else 
 {
 
 		fclose(f);
 		 return 0;
 }	
}


void viewnotification()
{
	
	cout<<"\nNotifications :\n";
	FILE *f;
 char file[100];
 strcpy(file,"notification/");
 strcat(file,username.username);
 strcat(file,".dat");
 f=fopen(file,"r");
 if(f==NULL)
 {
  cout<<"\nThere is no notification for U\n";
   }
 else {	

	fseek(f, 0, SEEK_SET);
	
	while(fread(&n,sizeof(freq),1,f)){
		cout<<"\nMessage : "<<n.notification<<"\nTime : "<<n.time;
	     }
	     
	    

}

fclose(f);
remove(file);
}
