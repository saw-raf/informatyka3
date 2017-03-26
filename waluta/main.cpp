#include "CLiczba.h"
#include "CWaluta.h"
#include "locale.h"
#include <iostream>

using namespace std;

double DajWartosc(CWaluta& Kwota)
{
	cout<<"Wywolano funkcje zaprzyjazniona DajWartosc()"<<endl;
	return Kwota.m_fWartosc*Kwota.m_fPrzelicznik;
}

int main()
{
	setlocale(LC_ALL,"polish");//ustawienie wyswietlania polskich znakow

	CLiczba Obj1(23.456,4);
	CLiczba Obj2(100.0,2);
	CLiczba Obj3;
	Obj3=Obj2+Obj1;
	Obj1++;
	++Obj1;
	Obj1.Drukuj();
	Obj3.Drukuj();
	CWaluta Stan("PLN",1.0,100,2);
	CWaluta Stan2("EUR",3.14,100,2);
	Stan=Stan+Stan2;
	Stan=Stan+100.00;
	Stan.Drukuj();
	return 0;
}
