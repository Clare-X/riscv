//
// Created by 18146 on 2018/12/21.
//

#ifndef BOOK_FINANCE_H
#define BOOK_FINANCE_H
#include "database.h"
class Fi
{
public:
	double MoneyA,MoneyB;
	int userpla;
	Fi()
	{
		MoneyA=0;MoneyB=0;userpla=-1;
	}

};

class Finance
{
public:
	explicit Finance(const char Fmain[]);

	~Finance()=default;

	void init();

	void AddF(int pla,double m);

	void GetLas(int las);

	string FM;
	fstream mainway;
};
#endif //BOOK_FINANCE_H
