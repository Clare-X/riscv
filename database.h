//
// Created by 18146 on 2018/12/17.
//

#ifndef BOOK_DATABASE_H
#define BOOK_DATABASE_H
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class rec
{
public:
	char id[35];
	int place;
	rec()
	{
		id[0]='\0';
		place=-1;
	}
	~rec()=default;
};

class Database
{

public:
	fstream mainway;
	fstream roadway;
	string UM,UR;
	int modSize,stckSize;
public:
	Database(const char Umain[],const char Uroad[],int siz1=100,int siz2=1000);

	virtual ~Database()=default;

	void init();

	int altNum(int alt);

	int altPartNum(int partId,int alt);

	int getIdPart1(const char *id);

	int getIdPart2(const char *id,int partId);

	int getIdPlace(int partId1,int partId2);

	void writeRoadway(int partId1,int partId2,const rec &id)
	{
		roadway.open(UR,ios::binary|ios_base::in|ios_base::out);
		roadway.seekp(partId1*(sizeof(rec)*stckSize+sizeof(int)),ios::beg);
		roadway.seekp(sizeof(int)+(partId2-1)*sizeof(rec),ios::cur);
		roadway.write(reinterpret_cast<const char *>(&id), sizeof(rec));
		roadway.close();
	}

	void readRoadway(int partId1,int partId2,rec &id)
	{
		roadway.open(UR,ios::binary|ios_base::in|ios_base::out);
		roadway.seekg(partId1*(sizeof(rec)*stckSize+sizeof(int)),ios::beg);
		roadway.seekg(sizeof(int)+(partId2-1)*sizeof(rec),ios::cur);
		roadway.read(reinterpret_cast<char *>(&id), sizeof(rec));
		roadway.close();
	}

	int getIdFinalPlace(const char *id);
};




#endif //BOOK_DATABASE_H
