//
// Created by 18146 on 2018/12/11.
//

#ifndef BOOK_USERS_H
#define BOOK_USERS_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "database.hpp"
using namespace std;

//#define Umain "usermain.txt"
//#define Uroad "userroad.txt"

class user
{
public:
	char id[35],passwd[35];
	char name[35];
	int pow;
	user()
	{
		id[0]='\0';
		passwd[0]='\0';
		name[0]='\0';
		pow=0;
	}
	~user()=default;

	user(const user &x)
	{
		strcpy(id,x.id);
		strcpy(passwd,x.passwd);
		strcpy(name,x.name);
		pow=x.pow;
	}
	user &operator=(const user &x)
	{
		strcpy(id,x.id);
		strcpy(passwd,x.passwd);
		strcpy(name,x.name);
		pow=x.pow;
		return *this;
	}

};

class users:public Database
{
private:
	string UMM;

public:
	users(const char* Umain,const char* Uroad):Database(Umain,Uroad,1000,100)
	{
		Nowpow=7;
		UMM=Umain;
		user sjtu;
		strcpy(sjtu.id,"root");
		strcpy(sjtu.name,"boss");
		strcpy(sjtu.passwd,"sjtu");
		sjtu.pow=7;
		adduser(sjtu);
		Nowpla=1;
	}

	~users()=default;

	int Nowpow,Nowpla;

	user* show(char *id);

	void adduser(const user &x);

	void deluser(char *id);

	void writeMainway(int place,const user &id);

	void readMainway(int place, user &id);
};
user *users::show(char *id)
{

	int x=getIdFinalPlace(id);
	if (x==-1) throw 0;
	//cout<<"statshow\n";
	user *u=new user;
	//cout<<getIdFinalPlace(id)<<"showid\n";
	readMainway(x,*u);
	return u;
}

void users::adduser(const user &x)
{
	int t0=altNum(1);
	writeMainway(t0,x);
	//user xx;
	//readMainway(t0,xx);
	//cout<<t0<<xx.passwd<<"main\n";
	int t1=getIdPart1(x.id);
	int t2=altPartNum(t1,1);
	rec X;
	strcpy(X.id,x.id);
	X.place=t0;
	writeRoadway(t1,t2,X);
//	cout<<t0<<" "<<t1<<" "<<t2<<endl;
}

void users::deluser(char *id)
{
	int t0 = getIdPart1(id);
	int t1 = getIdPart2(id, t0);
	if (t1==-1) throw 0;
	rec x;
	strcpy(x.id,id);
	x.place=-1;
	writeRoadway(t0,t1,x);
}
void users::readMainway(int place, user &id)
{
	fstream mainway;
	mainway.open(UMM,ios::binary|ios_base::in|ios_base::out);
	mainway.seekg((place-1)*(sizeof(user))+sizeof(int),ios::beg);
	mainway.read(reinterpret_cast<char *>(&id), sizeof(user));
	mainway.close();
}
void users::writeMainway(int place,const user &id)
{
	fstream mainway;
	mainway.open(UMM,ios::binary|ios_base::in|ios_base::out);
	mainway.seekp((place-1)*(sizeof(user))+sizeof(int),ios::beg);
	mainway.write(reinterpret_cast<const char *>(&id), sizeof(user));
	mainway.close();
}

#endif //BOOK_USERS_H
