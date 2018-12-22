//
// Created by 18146 on 2018/12/21.
//

#ifndef BOOK_BOOKS_H
#define BOOK_BOOKS_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "database.h"
#include "dataB.h"
using namespace std;
class book
{
public:
	char isbn[35],auth[45];
	char name[45],keyw[100];
	int ben;
	double price;
	book()
	{
		isbn[0]='\0';
		auth[0]='\0';
		name[0]='\0';
		keyw[0]='\0';
		ben=0;price=0;
	}
	~book()=default;

	book(const book &x)
	{
		strcpy(isbn,x.isbn);
		strcpy(auth,x.auth);
		strcpy(name,x.name);
		strcpy(keyw,x.keyw);
		ben=x.ben;price=x.price;
	}
	book &operator=(const book &x)
	{
		strcpy(isbn,x.isbn);
		strcpy(auth,x.auth);
		strcpy(name,x.name);
		strcpy(keyw,x.keyw);
		ben=x.ben;price=x.price;
		return *this;
	}
	void print()
	{
		cout<<isbn<<'\t';
		cout<<name<<'\t';
		cout<<auth<<'\t';
		cout<<keyw<<'\t';
		cout.setf(ios::fixed);
		cout<<fixed<<setprecision(2)<<price<<'\t';
		cout<<ben<<"±¾"<<endl;
	}
	bool operator<(const book &b)
	{
		int i=0;
		while (isbn[i]==b.isbn[i]&&isbn[i]!='\0'&&b.isbn[i]!='\0') i++;
		if (isbn[i]==b.isbn[i]) return false;
		if (isbn[i]=='\0') return true;
		if (b.isbn[i]=='\0') return false;
		return isbn[i]<b.isbn[i];
	}

};


class books:public Database
{
private:
	string UMM;

public:
	books(const char Umain[], const char Uroad[]) :
	Database(Umain, Uroad, 100, 1000),Author("Au.bin"),Keyword("Ke.bin"),Name("Na.bin")
	{
		UMM=Umain;
		Nowplace=-1;
	}

	book Nowbook;
	int Nowplace;
	DataB Author,Keyword,Name;

	~books() = default;

	int addbook(const book &x);

	void altISBN(const char *id1,const char *id2,int pla);

	void writeMainway(int place,const book &id);

	void readMainway(int place, book &id);

	void altNowbook(book &X);

	char* ProcessKey(char* &keys);
};
#endif //BOOK_BOOKS_H
