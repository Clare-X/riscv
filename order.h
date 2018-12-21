//
// Created by 18146 on 2018/12/18.
//

#ifndef BOOK_ORDER_H
#define BOOK_ORDER_H
#include "users.h"
#include "books.h"
#include "finance.h"
#include <algorithm>
void Processline(char* x,int size,users &Ux,books &Bx,Finance &Fx);


char *Processtoken(char* &x,int &size,int maxsize);
char *ProcesstokenD(char* &x,int &size,int maxsize);
char* Processorder(char* &x,int &size,int maxsize);
int STI(char *t);
double STD(char *t);

void Su(char* x,int size,users &Ux);
void Logout(char* x,int size,users &Ux);
void Useradd(char* x,int size,users &Ux);
void Register(char* x,int size,users &Ux);
void Delete(char* x,int size,users &Ux);
void Passwd(char* x,int size,users &Ux);

void Select(char* x,int size,users &Ux,books &Bx);
void Modify(char* x,int size,users &Ux,books &Bx);
void Import(char* x,int size,users &Ux,books &Bx,Finance &Fx);
void Buy(char* x,int size,users &Ux,books &Bx,Finance &Fx);

void Show(char* x,int size,users &Ux,books &Bx,Finance &Fx);
void ShowA(books &Bx);
void ShowB(vector<int> X,books &Bx);
//void ShowF(char* x,int size,users &Ux,books &Bx);
#endif //BOOK_ORDER_H
