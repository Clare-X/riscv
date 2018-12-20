//
// Created by 18146 on 2018/12/18.
//

#include "order.h"
void Processline(char* x,int size,users &Ux)
{

	strcat(x," ");size++;
//	cout<<x<<"#\n";
	char *y,*t1,*t2,*t3,*t4;
	y=Processtoken(x,size,10);
	if (strcmp(y,"su")==0)
	{
		delete[] y;
		t1=Processtoken(x,size,35);
		//cout<<t1<<"#"<<endl;
		user *Su=Ux.show(t1);
		delete[] t1;
		if ((*Su).pow<Ux.nowpow)
		{
			if (x[0]!=' '&&x[0]!='\0') {delete Su;throw 0;}
			else Ux.nowpow=(*Su).pow;
		}
		else {
			t2=Processtoken(x,size,35);
			int l=strcmp(t2,(*Su).passwd);
		//	cout<<t2<<"t2"<<endl;
		//	cout<<(*Su).passwd<<"Supass"<<endl;
			delete[] t2;
			if (x[0]!=' '&&x[0]!='\0') {delete Su;throw 0;}
			if (l!=0) {delete Su;throw 0;}
			Ux.nowpow=(*Su).pow;
		}
		delete Su;
		return;
	}
	if (strcmp(y,"logout")==0)
	{
		delete[] y;
		if (Ux.nowpow==0) throw 0;
		if (x[0]!=' '&&x[0]!='\0') {throw 0;}
		Ux.nowpow=0;
		return;
	}
	if (strcmp(y,"useradd")==0)
	{
		delete[] y;
		if (Ux.nowpow<3) throw 0;
		t1=Processtoken(x,size,35);
		t2=Processtoken(x,size,35);
		t3=Processtoken(x,size,1);
		if (strcmp(t3,"1")!=0&&strcmp(t3,"3")!=0) {delete[] t1;delete[] t2;delete[] t3;throw 0;}
		int l=t3[0]-'0';delete[] t3;
		if (l>=Ux.nowpow||Ux.getIdFinalPlace(t1)!=-1) {delete[] t1;delete[] t2;throw 0;}
		t4=Processtoken(x,size,35);
		if (x[0]!=' '&&x[0]!='\0') {		delete[] t1;delete[] t2;delete[] t4;throw 0;}
		user Add;
		strcpy(Add.id,t1);
		strcpy(Add.passwd,t2);
		Add.pow=l;
		strcpy(Add.name,t4);
		delete[] t1;delete[] t2;
		delete[] t4;
		Ux.adduser(Add);
	//	cout<<Add.id<<"Id"<<endl;
	//	cout<<Add.passwd<<"Passwd"<<endl;
	//	cout<<Add.pow<<"pow"<<endl;
	//	cout<<Add.name<<"Name"<<endl;
		return;
	}
	if (strcmp(y,"register")==0)
	{
		delete[] y;
		t1=Processtoken(x,size,31);
		t2=Processtoken(x,size,31);
		t3=Processtoken(x,size,31);
		if (x[0]!=' '&&x[0]!='\0') {		delete[] t1;delete[] t2;delete[] t3;throw 0;}
		user Add;
		strcpy(Add.id,t1);
		strcpy(Add.passwd,t2);
		Add.pow=1;
		strcpy(Add.name,t3);
		delete[] t1;delete[] t2;delete[] t3;
		Ux.adduser(Add);
		return;
	}
	if (strcmp(y,"delete")==0)
	{
		delete[] y;
		if (Ux.nowpow<7) throw 0;
		t1=Processtoken(x,size,31);
		if (x[0]!=' '&&x[0]!='\0') {		delete[] t1;throw 0;}
		Ux.deluser(t1);
		delete[] t1;
		return;
	}
	if (strcmp(y,"passwd")==0)
	{
		delete[] y;
		if (Ux.nowpow<=0) throw 0;
		t1=Processtoken(x,size,31);
		user (*P)=Ux.show(t1);
		delete[] t1;
		if (strcmp((*P).id,"root")!=0)
		{
			t2=Processtoken(x,size,31);
			if (strcmp(t2,(*P).passwd)!=0) {delete[] t2;throw 0;}
			delete[] t2;
		}
		t2=Processtoken(x,size,31);
		strcpy((*P).passwd,t2);delete[] t2;
		if (x[0]!=' '&&x[0]!='\0') {		delete P;throw 0;}
		Ux.writeMainway(Ux.getIdFinalPlace((*P).id),(*P));
		delete P;
		return;
	}
	throw 0;
}





char *Processtoken(char* &x,int &size,int maxsize)
{
	int flag=maxsize+1;
	for(int i=0;i<size;i++)
	{
		if (x[i]==' ') {flag=i;break;}
	}
	if (flag>maxsize) throw 0;
	char *y=new char[maxsize];y[flag]='\0';
	strncpy(y,x,flag);
	x+=flag+1;
	size-=flag+1;
	return y;
}