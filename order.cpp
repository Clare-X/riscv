//
// Created by 18146 on 2018/12/18.
//

#include "order.h"
void Processline(char* x,int size,users &Ux,books &Bx)
{

	strcat(x," ");size++;
//	cout<<x<<"#\n";
	char *y;
	y=Processtoken(x,size,10);
	if (strcmp(y,"su")==0)
	{
		delete[] y;
		Su(x,size,Ux);
		return;
	}
	if (strcmp(y,"logout")==0)
	{
		delete[] y;
		Logout(x,size,Ux);
		return;
	}
	if (strcmp(y,"useradd")==0)
	{
		delete[] y;
		Useradd(x,size,Ux);
		//	cout<<Add.id<<"Id"<<endl;
		//	cout<<Add.passwd<<"Passwd"<<endl;
		//	cout<<Add.pow<<"pow"<<endl;
		//	cout<<Add.name<<"Name"<<endl;
		return;
	}
	if (strcmp(y,"register")==0)
	{
		delete[] y;
		Register(x,size,Ux);
		return;
	}
	if (strcmp(y,"delete")==0)
	{
		delete[] y;
		Delete(x,size,Ux);
		return;
	}
	if (strcmp(y,"passwd")==0)
	{
		delete[] y;
		Passwd(x,size,Ux);
		return;
	}
	if (strcmp(y,"select")==0)
	{
		delete[] y;
		Select(x,size,Ux,Bx);
		return;
	}
	if (strcmp(y,"modify")==0)
	{
		delete[] y;
		Modify(x,size,Ux,Bx);
		return;
	}
	if (strcmp(y,"import")==0)
	{
		delete[] y;
		Import(x,size,Ux,Bx);
		return;
	}
	if (strcmp(y,"buy")==0)
	{
		delete[] y;
		Buy(x,size,Ux,Bx);
		return;
	}
	if (strcmp(y,"show")==0)
	{
		delete[] y;
		Show(x,size,Ux,Bx);
		return;
	}
	throw 0;
}



int STI(char *t)
{
	int ans=0,i=0;
	while (t[i]!=' '&&t[i]!='\0')
	{
		if (t[i]<'0'||t[i]>'9'){delete[] t;throw 0;}
		ans=ans*10+t[i]-'0';
		i++;
	}
	return ans;
}


double STD(char *t)
{
	double ans=0;
	int i=0;
	while (t[i]!=' '&&t[i]!='\0'&&t[i]!='.')
	{
		if (t[i]<'0'||t[i]>'9'){delete[] t;throw 0;}
		ans=ans*10+t[i]-'0';
		i++;
	}
	if (t[i]!='.')return ans;
	double m=1;
	i++;
	while (t[i]!=' '&&t[i]!='\0')
	{
		if (t[i]<'0'||t[i]>'9'){delete[] t;throw 0;}
		m=m/10;
		ans+=m*(t[i]-'0');
		i++;
	}
	return ans;
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
char *ProcesstokenD(char* &x,int &size,int maxsize)
{
	if (x[0]!='\"') throw 0;
	x++;size--;
	int flag=maxsize+1;
	for(int i=0;i<size;i++)
	{
		if (x[i]=='\"') {flag=i;break;}
	}
	if (flag>maxsize) throw 0;
	char *y=new char[maxsize];y[flag]='\0';
	strncpy(y,x,flag);
	x+=flag+1;
	size-=flag+1;
	if (x[0]==' ') {x++;size--;}
//	cout<<y<<"ProD\n";
	return y;
}
char* Processorder(char* &x,int &size,int maxsize)
{
	if (x[0]!='-') throw 0;
	x++;size--;
	int flag=maxsize+1;
	for(int i=0;i<size;i++)
	{
		if (x[i]=='=') {flag=i;break;}
	}
	if (flag>maxsize) throw 0;
	char *y=new char[maxsize];y[flag]='\0';
	strncpy(y,x,flag);
	x+=flag+1;
	size-=flag+1;
//	cout<<y<<"Prorder\n";
	return y;
}


void Su(char* x,int size,users &Ux)
{
	char *t1,*t2;
	t1=Processtoken(x,size,35);
	//cout<<t1<<"#"<<endl;
	int temp=Ux.getIdFinalPlace(t1);
	delete[] t1;
	if (temp==-1) throw 0;
	user Su;
	Ux.readMainway(temp,Su);
	if (Su.pow<Ux.Nowpow)
	{
		if (x[0]!=' '&&x[0]!='\0') throw 0;
		else {Ux.Nowpow=Su.pow;Ux.Nowpla=temp;}
	}
	else {
		t2=Processtoken(x,size,35);
		int l=strcmp(t2,Su.passwd);
		//	cout<<t2<<"t2"<<endl;
		//	cout<<(*Su).passwd<<"Supass"<<endl;
		delete[] t2;
		if (x[0]!=' '&&x[0]!='\0') throw 0;
		if (l!=0) throw 0;
		Ux.Nowpow=Su.pow;Ux.Nowpla=temp;
	}
}
void Logout(char* x,int size,users &Ux)
{
	if (Ux.Nowpow==0) throw 0;
	if (x[0]!=' '&&x[0]!='\0') {throw 0;}
	Ux.Nowpow=0;Ux.Nowpla=-1;
}
void Useradd(char* x,int size,users &Ux)
{
	char *t1,*t2,*t3,*t4;
	if (Ux.Nowpow<3) throw 0;
	t1=Processtoken(x,size,35);
	t2=Processtoken(x,size,35);
	t3=Processtoken(x,size,1);
	if (strcmp(t3,"1")!=0&&strcmp(t3,"3")!=0) {delete[] t1;delete[] t2;delete[] t3;throw 0;}
	int l=t3[0]-'0';delete[] t3;
	if (l>=Ux.Nowpow||Ux.getIdFinalPlace(t1)!=-1) {delete[] t1;delete[] t2;throw 0;}
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
}
void Register(char* x,int size,users &Ux)
{
	char *t1,*t2,*t3;
	t1=Processtoken(x,size,35);
	t2=Processtoken(x,size,35);
	t3=Processtoken(x,size,35);
	if (x[0]!=' '&&x[0]!='\0') {		delete[] t1;delete[] t2;delete[] t3;throw 0;}
	user Add;
	strcpy(Add.id,t1);
	strcpy(Add.passwd,t2);
	Add.pow=1;
	strcpy(Add.name,t3);
	delete[] t1;delete[] t2;delete[] t3;
	Ux.adduser(Add);
}
void Delete(char* x,int size,users &Ux)
{
	char *t1;
	if (Ux.Nowpow<7) throw 0;
	t1=Processtoken(x,size,35);
	if (x[0]!=' '&&x[0]!='\0') {		delete[] t1;throw 0;}
	Ux.deluser(t1);
	delete[] t1;
}
void Passwd(char* x,int size,users &Ux)
{
	char *t1,*t2;
	if (Ux.Nowpow<=0) throw 0;
	t1=Processtoken(x,size,35);
	user (*P)=Ux.show(t1);
	delete[] t1;
	if (strcmp((*P).id,"root")!=0)
	{
		t2=Processtoken(x,size,35);
		if (strcmp(t2,(*P).passwd)!=0) {delete[] t2;throw 0;}
		delete[] t2;
	}
	t2=Processtoken(x,size,35);
	strcpy((*P).passwd,t2);delete[] t2;
	if (x[0]!=' '&&x[0]!='\0') {		delete P;throw 0;}
	Ux.writeMainway(Ux.getIdFinalPlace((*P).id),(*P));
	delete P;
}

//book

void Select(char* x,int size,users &Ux,books &Bx)
{
	if (Ux.Nowpow<3) throw 0;
	char *t1;
	t1=Processtoken(x,size,35);
	if (x[0]!=' '&&x[0]!='\0') {delete[] t1;throw 0;}
	int l=Bx.getIdFinalPlace(t1);
	if (l==-1)
	{
		Bx.Nowbook.auth[0]='\0';
		Bx.Nowbook.name[0]='\0';
		Bx.Nowbook.keyw[0]='\0';
		Bx.Nowbook.ben=0;
		Bx.Nowbook.price=0;
		strcpy(Bx.Nowbook.isbn,t1);
		Bx.Nowplace=Bx.addbook(Bx.Nowbook);
	}
	else
	{
		Bx.readMainway(l,Bx.Nowbook);
		Bx.Nowplace=l;
	}
	delete[] t1;
}
void Import(char* x,int size,users &Ux,books &Bx)
{
	if (Ux.Nowpow<3) throw 0;
	if (Bx.Nowplace==-1) throw 0;
	char *t1,*t2;
	t1=Processtoken(x,size,10);
	t2=Processtoken(x,size,20);
	if (x[0]!=' '&&x[0]!='\0') {delete[] t1;delete[] t2;throw 0;}
	int altben=STI(t1);
	double cost=STD(t2);
	delete[] t1;
	delete[] t2;
	Bx.Nowbook.ben+=altben;
	Bx.writeMainway(Bx.Nowplace,Bx.Nowbook);
//finance
}
void Buy(char* x,int size,users &Ux,books &Bx)
{
	if (Ux.Nowpow<1) throw 0;
	char *t1,*t2;
	t1=Processtoken(x,size,35);
	t2=Processtoken(x,size,10);
	if (x[0]!=' '&&x[0]!='\0') {delete[] t1;delete[] t2;throw 0;}
	int altben=STI(t2);
	delete[] t2;
	int pla=Bx.getIdFinalPlace(t1);
	delete[] t1;
	if (pla==-1) throw 0;
	book X;
	Bx.readMainway(pla,X);
	X.ben-=altben;
	Bx.writeMainway(pla,X);
	double cost=altben*X.price;
	//finance
}

void Modify(char* x,int size,users &Ux,books &Bx)
{
	if (Ux.Nowpow<3) throw 0;
	if (Bx.Nowplace==-1) throw 0;
	char *t1,*t2;
	book X(Bx.Nowbook);
	while (x[0]!=' '&&x[0]!='\0')
	{
		t1=Processorder(x,size,10);
		if (strcmp(t1,"ISBN")==0)
		{
			delete[] t1;
			t2=Processtoken(x,size,35);
			strcpy(X.isbn,t2);
			delete[] t2;
		}
		else if (strcmp(t1,"name")==0)
		{
			delete[] t1;
			t2=ProcesstokenD(x,size,45);
			strcpy(X.name,t2);
			delete[] t2;
		}
		else if (strcmp(t1,"author")==0)
		{
			delete[] t1;
			t2=ProcesstokenD(x,size,45);
			strcpy(X.auth,t2);
			delete[] t2;
		}
		else if (strcmp(t1,"keyword")==0)
		{
			delete[] t1;
			t2=ProcesstokenD(x,size,45);
			strcpy(X.keyw,t2);
			delete[] t2;
		}
		else if (strcmp(t1,"price")==0)
		{
			delete[] t1;
			t2=Processtoken(x,size,15);
			X.price=STD(t2);
			delete[] t2;
		}
	}
	Bx.altNowbook(X);

}
void Show(char* x,int size,users &Ux,books &Bx)
{
	if (Ux.Nowpow<1) throw 0;
	if (x[0]==' '||x[0]=='\0') {ShowA(Bx);return;}
	if (x[0]!='-')
	{
		char *t0=Processtoken(x,size,10);
		if (strcmp(t0,"finance")!=0) {delete[] t0;throw 0;}
		//finance
	}
	char *t1=Processorder(x,size,10),*t2;
	if (strcmp(t1,"ISBN")==0)
	{
		delete[] t1;
		t2=Processtoken(x,size,35);
		book X;
		int pla=Bx.getIdFinalPlace(t2);
		if (pla==-1) {delete[] t2;return;}
		Bx.readMainway(pla,X);
		delete[] t2;
		X.print();
	}
	else if (strcmp(t1,"name")==0)
	{
		delete[] t1;
		t2=ProcesstokenD(x,size,45);
		ShowB(Bx.Name.Showkey(t2),Bx);
		delete[] t2;
	}
	else if (strcmp(t1,"author")==0)
	{
		delete[] t1;
		t2=ProcesstokenD(x,size,45);
		ShowB(Bx.Author.Showkey(t2),Bx);
		delete[] t2;
	}
	else if (strcmp(t1,"keyword")==0)
	{
		delete[] t1;
		t2=ProcesstokenD(x,size,45);
		ShowB(Bx.Keyword.Showkey(t2),Bx);
		delete[] t2;
	}

}
void ShowA(books &Bx)
{
	vector<book> X;
	book x;
	int n=Bx.altNum(0);
	for (int i=1;i<=n;i++)
	{
		Bx.readMainway(i,x);
		X.push_back(x);
	}
	sort(X.begin(),X.end());
	for (auto I=X.begin();I!=X.end();I++)
		(*I).print();
}
void ShowB(vector<int> X,books &Bx)
{
	book B;
	vector<book> x;
	for (auto I=X.begin();I!=X.end();I++)
	{
		Bx.readMainway(*I,B);
		x.push_back(B);
	}
	sort(x.begin(),x.end());
	for (auto I=x.begin();I!=x.end();I++)
		(*I).print();
}
