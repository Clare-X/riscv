//
// Created by 18146 on 2018/12/11.
//

#ifndef BOOK_USERS_H
#define BOOK_USERS_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "database.h"
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
	users(const char Umain[],const char Uroad[]):Database(Umain,Uroad,1000,100)
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


#endif //BOOK_USERS_H
