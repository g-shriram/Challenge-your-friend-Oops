#include<iostream>
#include<stdio.h>
#include<string.h>
#include "classes.cpp"
using namespace std;
int main()
{
  challenge u1;
	FILE *f;
	f=fopen("challenge/123.dat","r");

   fread(&u1,sizeof(challenge),1,f);
	cout<<u1.username<<u1.chala<<u1.chalg;
	fclose(f);
}
