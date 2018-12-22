//
// Created by 18146 on 2018/12/21.
//

#ifndef BOOK_BOOKS_H
#define BOOK_BOOKS_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "database.hpp"
#include "dataB.hpp"
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
		cout<<ben<<"本"<<endl;
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
	books(const char* Umain, const char* Uroad) :
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

	char *ProcessKey(char* &keys);
};


int books::addbook(const book &x)
{
	int t0=altNum(1);
	writeMainway(t0,x);
	int t1=getIdPart1(x.isbn);
	int t2=altPartNum(t1,1);
	rec X;
	strcpy(X.id,x.isbn);
	X.place=t0;
	writeRoadway(t1,t2,X);
	return t0;
}

void books::altISBN(const char *id1,const char *id2,int pla)
{
	int t0,t1;
	int temp=getIdFinalPlace(id2);
	if (temp!=-1) throw 0;

	rec x;
	strcpy(x.id,id1);
	x.place=-1;
	writeRoadway(t0,t1,x);

	strcpy(x.id,id2);
	x.place=pla;
	t0=getIdPart1(id2);
	t1=altPartNum(t1,1);
	writeRoadway(t0,t1,x);
}
void books::readMainway(int place, book &id)
{
	fstream mainway;
	mainway.open(UMM,ios::binary|ios_base::in|ios_base::out);
	mainway.seekg((place-1)*(sizeof(book))+sizeof(int),ios::beg);
	mainway.read(reinterpret_cast<char *>(&id), sizeof(book));
	mainway.close();
}
void books::writeMainway(int place,const book &id)
{
	fstream mainway;
	mainway.open(UMM,ios::binary|ios_base::in|ios_base::out);
	mainway.seekp((place-1)*(sizeof(book))+sizeof(int),ios::beg);
	mainway.write(reinterpret_cast<const char *>(&id), sizeof(book));
	mainway.close();
}


void books::altNowbook(book &X)
{
	writeMainway(Nowplace,X);
	if (strcmp(X.isbn,Nowbook.isbn)!=0) altISBN(Nowbook.isbn,X.isbn,Nowplace);
	if (strcmp(X.name,Nowbook.name)!=0)
	{
		if (Nowbook.name[0]!='\0')Name.Delkey(Nowplace,Nowbook.name);
		if (X.name[0]!='\0')Name.Addkey(Nowplace,X.name);
	}
	if (strcmp(X.auth,Nowbook.auth)!=0)
	{
		if (Nowbook.auth[0]!='\0')Author.Delkey(Nowplace,Nowbook.auth);
		if (X.auth[0]!='\0')Author.Addkey(Nowplace,X.auth);
	}
	if (strcmp(X.keyw,Nowbook.keyw)!=0)
	{
		char *y=Nowbook.keyw,*t0;
		if (y[0]!='\0')
			while (y!=nullptr)
			{
				t0=ProcessKey(y);
				Keyword.Delkey(Nowplace,t0);
			}
		y=X.keyw;
		if (y[0]!='\0')
			while (y!=nullptr)
			{
				t0=ProcessKey(y);
				Keyword.Addkey(Nowplace,t0);
			}
	}
	Nowbook=X;
}
char* books::ProcessKey(char* &keys)
{
	int flag = -1;
	for (int i = 0; i < strlen(keys); i++)
	{
		if (keys[i] == '|')
		{
			flag = i;
			break;
		}
	}
	if (flag == -1)
	{
		char *y = keys;
		keys = nullptr;
		return y;
	}
	char *y = new char[45];
	y[flag] = '\0';
	strncpy(y, keys, flag);
	keys += flag + 1;
	return y;
}
#endif //BOOK_BOOKS_H
