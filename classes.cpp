class user{
	public:
		char username[100],pin[10];

		user()
		{
			username[0]='\0';
				pin[0]='\0';
		}

};

class points{
	public:
		float point;
		char username[100];
		points()
		{
			point=0.0;
			username[0]='\0';
		}

};

class freq{
	public:
		char username[100];
		char time[100];


};

class notify{
	public:
		char notification[100];
			char time[100];
};

class jumb{
	public:
		char username[100],cword[100],jword[100],time[100];
		int chance;
		float points;
		jumb()
			{
				username[0]='\0';
				cword[0]='\0';
				jword[0]='\0';
				time[0]='\0';
				chance=0;
				points=0.0;
			}
};

class hang{
	public:
		char username[100],cword[100],mletter[50],time[100];
		int chance;
			float points;
			hang()
			{
				points=0.0;
				chance=0;
				username[0]='\0';
				cword[0]='\0';
			mletter[0]='\0';
			time[0]='\0';
			}


};

class challenge{
	public:
		char username[100];
		int chalg,chala,lost,won;
		challenge()
		{
			username[0]='\0';
			chalg=0;
			chala=0;
			lost=0;
			won=0;
		}
};



class viewdetails{
    public:
      user u;
      challenge c;
      points p;
      viewdetails *left,*right;
      int height;


    viewdetails()
    {
        left=right=NULL;
        height=0;
    }

    void display()
    {
         cout<<"\nUsername : "<<u.username;
  cout<<"\nPassword : "<<u.pin;
  cout<<"\nPoints : "<<p.point;
  cout<<"\nChallenge  Given  : "<<c.chalg;
  cout<<"\nChallenge  Accepted  : "<<c.chala;
  cout<<"\nChallenge  Won : "<<c.won;
  cout<<"\nChallenge  Lost  : "<<c.lost;
    }

      int operator <(viewdetails v)
      {
          if(this->p.point<v.p.point)
            return 1;
          else if(this->p.point==v.p.point && this->c.won <v.c.won )
            return 1;
                      else if(this->p.point==v.p.point && this->c.won == v.c.won  && this->c.chalg<v.c.chalg )
            return 1;

            else if(this->p.point==v.p.point && this->c.won == v.c.won  && this->c.chalg==v.c.chalg && this->c.chala==v.c.chala)
            return 1;

            else
                return 0;
      }

      int operator >(viewdetails v)
      {
          if(this->p.point<v.p.point)
            return 0;
          else if(this->p.point==v.p.point && this->c.won <v.c.won )
            return 0;
                      else if(this->p.point==v.p.point && this->c.won == v.c.won  && this->c.chalg<v.c.chalg )
            return 0;

            else if(this->p.point==v.p.point && this->c.won == v.c.won  && this->c.chalg==v.c.chalg && this->c.chala==v.c.chala)
            return 0;

            else
                return 1;
      }
};
