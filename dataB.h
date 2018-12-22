//
// Created by 18146 on 2018/12/22.
//

#ifndef BOOK_DATAB_H
#define BOOK_DATAB_H
#include "database.h"
#include <vector>
using namespace std;
class Rec
{
public:
	char Key[45];
	int place[100];
	int numb;
	Rec()
	{
		Key[0]='\0';
		place[0]=-1;
		numb=0;
	}
	~Rec()=default;
};
class DataB
{
public:
	explicit DataB(const char* Bmain);

	~DataB()=default;

	void init();

	void Addkey(int pla,const char* key);

	void Delkey(int pla,const char* key);

	vector<int> Showkey(const char* key);

	int HASHKEY(const char* key);

	string BM;
	fstream mainway;
	int modSize,stckSize;

};




#endif //BOOK_DATAB_H
