//
// Created by 18146 on 2018/12/17.
//
#include "database.h"
Database::Database(const char* Umain,const char* Uroad,int siz1,int siz2)
{
//	cout<<"build"<<endl;
	modSize=siz1;
	stckSize=siz2;
	UM=Umain;
	UR=Uroad;
	mainway.open(UM,fstream::in);
	if (!mainway) init();
	else mainway.close();
}

void Database::init()
{
	int x=0;
	mainway.close();
	mainway.open(UM,ios::binary|ios_base::out);
	roadway.open(UR,ios::binary|ios_base::out);
	mainway.seekp(0,ios::beg);
	mainway.write(reinterpret_cast<const char *>(&x), sizeof(int));
	roadway.seekp(0,ios::beg);
	for (int i=0;i<modSize;i++)
	{
		x=0;
		roadway.seekp(i*(sizeof(rec)*stckSize+sizeof(int)),ios::beg);
		roadway.write((reinterpret_cast<char * > (&x)), sizeof(int));
	}

	mainway.close();
	roadway.close();
}

int Database::altNum(int alt)
{
	mainway.open(UM,ios::binary|ios_base::in|ios_base::out);
	int ans;
	mainway.seekg(0,ios::beg);
	mainway.read((reinterpret_cast<char * > (&ans)), sizeof(int));
	if (alt==0){mainway.close();return ans;}
	ans+=alt;
	mainway.seekp(0,ios::beg);
	mainway.write(reinterpret_cast<const char *>(&ans), sizeof(int));
	mainway.close();
	return ans;
}
int Database::altPartNum(int partId,int alt)
{
	roadway.open(UR,ios::binary|ios_base::in|ios_base::out);
	int ans;
	roadway.seekg(partId*(sizeof(rec)*stckSize+sizeof(int)),ios::beg);
	roadway.read((reinterpret_cast<char * > (&ans)), sizeof(int));
	if (alt==0){roadway.close();return ans;}
	ans+=alt;
	roadway.seekp(partId*(sizeof(rec)*stckSize+sizeof(int)),ios::beg);
	roadway.write(reinterpret_cast<const char *>(&ans), sizeof(int));
	roadway.close();
	return ans;
}

int Database::getIdPart1(const char *id)
{
	return (int(id[0]))%modSize;
}

int Database::getIdPart2(const char *id,int Id)
{

	int x=altPartNum(Id,0),y=-1;
	//cout<<Id<<"Id"<<x<<"partnum"<<endl;
	rec R;
	for (int i=1;i<=x;i++)
	{
		readRoadway(Id,i,R);
		//cout<<x<<i<<"XI"<<R.id<<endl;
		if (strcmp(id,R.id)==0&&R.place>=0) {y=i;break;}
	}
	return y;

}

int Database::getIdPlace(int partId1,int partId2)
{
	if (partId2==-1) return -1;
	rec R;
	readRoadway(partId1,partId2,R);
	return R.place;
}



int Database::getIdFinalPlace(const char *id)
{
	int id1=getIdPart1(id);
	int id2=getIdPart2(id,id1);
//	cout<<id1<<" "<<id2<<" "<<getIdPlace(id1,id2)<<endl;
	return getIdPlace(id1,id2);
}


