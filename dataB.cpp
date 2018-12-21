//
// Created by 18146 on 2018/12/22.
//

#include "dataB.h"
DataB::DataB(const char Bmain[])
{
	BM=Bmain;
	modSize=920;
	stckSize=100;
	mainway.open(BM,fstream::in);
	if (!mainway) init();
	else mainway.close();
}

void DataB::init()
{
	mainway.close();
	mainway.open(BM,ios::binary|ios_base::out);
	mainway.seekp(0,ios::beg);
	int x;
	for (int i=0;i<modSize;i++)
	{
		x=0;
		mainway.seekp(i*(sizeof(Rec)*stckSize+sizeof(int)),ios::beg);
		mainway.write((reinterpret_cast<char * > (&x)), sizeof(int));
	}
	mainway.close();
}

void DataB::Addkey(int pla,const char* key)
{
	int id1=HASHKEY(key),num=0,P=-1;
	Rec X;
	mainway.open(BM,ios::binary|ios_base::out|ios::in);
	mainway.seekg(id1*(sizeof(Rec)*stckSize+sizeof(int)),ios::beg);
	mainway.read((reinterpret_cast<char * > (&num)), sizeof(int));
	for (int i=1;i<=num;i++)
	{
		mainway.read((reinterpret_cast<char * > (&X)), sizeof(Rec));
		if (strcmp(X.Key,key)==0) {P=i;break;}
	}
	if (P==-1)
	{
		num++;
		strcpy(X.Key,key);
		X.numb=1;
		X.place[1]=pla;
		mainway.seekp(id1*(sizeof(Rec)*stckSize+sizeof(int)),ios::beg);
		mainway.write(reinterpret_cast<const char *>(&num), sizeof(int));
		mainway.seekp((num-1)*sizeof(Rec),ios::cur);
		mainway.write(reinterpret_cast<const char *>(&X), sizeof(Rec));
	} else
	{
		bool flag=false;
		for (int i=1;i<=X.numb;i++) if (X.place[i]==pla) flag=true;
		if (flag) {mainway.close();return;}
		X.numb++;
		X.place[X.numb]=pla;
		mainway.seekp(id1*(sizeof(Rec)*stckSize+sizeof(int)),ios::beg);
		mainway.seekp((P-1)*sizeof(Rec)+sizeof(int),ios::cur);
		mainway.write(reinterpret_cast<const char *>(&X), sizeof(Rec));
	}
	mainway.close();
}


void DataB::Delkey(int pla,const char* key)
{
	int id1=HASHKEY(key),num=0,P=-1,t=0;
	Rec X;
	mainway.open(BM,ios::binary|ios_base::out|ios::in);
	mainway.seekg(id1*(sizeof(Rec)*stckSize+sizeof(int)),ios::beg);
	mainway.read((reinterpret_cast<char * > (&num)), sizeof(int));
	for (int i=1;i<=num;i++)
	{
		mainway.read((reinterpret_cast<char * > (&X)), sizeof(Rec));
		if (strcmp(X.Key,key)==0) {P=i;break;}
	}
	if (P==-1) {mainway.close();throw 0;}
	for (int i=1;i<=X.numb;i++)
	{
		if (X.place[i]==pla) {t=i;break;}
	}
	if (t==0){mainway.close();throw 0;}
	if (t!=X.numb) X.place[t]=X.place[X.numb];
	X.numb--;
	mainway.seekp(id1*(sizeof(Rec)*stckSize+sizeof(int)),ios::beg);
	mainway.seekp((P-1)*sizeof(Rec)+sizeof(int),ios::cur);
	mainway.write(reinterpret_cast<const char *>(&X), sizeof(Rec));
	mainway.close();
}

vector<int> DataB::Showkey(const char* key)
{
	vector<int> Ans;
	Ans.clear();
	int id1=HASHKEY(key),num=0,P=-1;
	Rec X;
	mainway.open(BM,ios::binary|ios_base::out|ios::in);
	mainway.seekg(id1*(sizeof(Rec)*stckSize+sizeof(int)),ios::beg);
	mainway.read((reinterpret_cast<char * > (&num)), sizeof(int));
	for (int i=1;i<=num;i++)
	{
		mainway.read((reinterpret_cast<char * > (&X)), sizeof(Rec));
		if (strcmp(X.Key,key)==0) {P=i;break;}
	}
	mainway.close();
	if (P==-1) {return Ans;}
	for (int i=1;i<=X.numb;i++)
		Ans.push_back(X.place[i]);
	return Ans;
}


int DataB::HASHKEY(const char* key)
{
	int i=0,ans=1;
	while (key[i]!='\0'&&key[i]!=' ')
	{
		ans=(ans*113+key[i])%911;
		i++;
	}
	return ans;
}