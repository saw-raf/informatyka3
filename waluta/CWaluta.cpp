#include "CWaluta.h"
#include <string.h>
#include <cstdio>
#include <iostream>

using namespace std;

void CWaluta::AktualizujString(void)
{
	char buf[100];
	sprintf(buf,"%.*lf %s",m_iPrecyzja,m_fWartosc,m_csWaluta);
	if(m_csWartoscString!=NULL)//zabezpieczenie przed wyciekiem pamieci
	{
		delete[] m_csWartoscString;
		m_csWartoscString=NULL;
	}
	m_csWartoscString=new char[strlen(buf)+1];//nadajemy odpowiedni rozmiar,  wielkosc buf + 1 miejsce na znak \0
	strcpy(m_csWartoscString,buf);//kopiowanie buf do atrybutu
}


CWaluta::CWaluta(void)
	:CLiczba(0,2), m_fPrzelicznik(1.0)
{
	//cout<<"Konstruktor CWaluta(void)"<<endl;
	strcpy(m_csWaluta,"PLN");
	AktualizujString();
}

CWaluta::CWaluta(const char* Waluta, double Przelicznik, double Wartosc, int Precyzja)
	:CLiczba(Wartosc,Precyzja), m_fPrzelicznik(Przelicznik)
{
	//cout<<"Konstruktor CWaluta(const char* Waluta, double Przelicznik, double Wartosc, int Precyzja)"<<endl;
	strcpy(m_csWaluta,Waluta);
	AktualizujString();
}

CWaluta::CWaluta(CWaluta& Obj)
	:CLiczba(Obj.m_fWartosc,Obj.m_iPrecyzja), m_fPrzelicznik(Obj.m_fPrzelicznik)
{
	//cout<<"Konstruktor CWaluta(CWaluta& Obj)"<<endl;
	UstawWalute(Obj.m_csWaluta);
	AktualizujString();
}

CWaluta::~CWaluta(void)
{
	//cout<<"Destruktor CWaluta. Skasowano"<<endl;
}

CWaluta& CWaluta::operator+(CWaluta& LiczbaDodawana)
{
    CWaluta tmp(*this);
    tmp.UstawWartosc(m_fWartosc+LiczbaDodawana.m_fPrzelicznik*LiczbaDodawana.m_fWartosc/m_fPrzelicznik);
    return tmp;
}

CWaluta& CWaluta::operator+(double LiczbaRzeczywista)
{
    CWaluta tmp(*this);
    tmp.UstawWartosc(m_fWartosc+LiczbaRzeczywista);
    return tmp;
}

CWaluta& CWaluta::operator-(CWaluta& LiczbaOdejmowana)
{
    CWaluta tmp(*this);
    tmp.UstawWartosc(m_fWartosc-LiczbaOdejmowana.m_fPrzelicznik*LiczbaOdejmowana.m_fWartosc/m_fPrzelicznik);
    return tmp;
}

CWaluta& CWaluta::operator-(double LiczbaRzeczywista)
{
    CWaluta tmp(*this);
    tmp.UstawWartosc(m_fWartosc-LiczbaRzeczywista);
    return tmp;
}

CWaluta& CWaluta::operator*(double LiczbaRzeczywista)
{
    CWaluta tmp(*this);
    tmp.UstawWartosc(m_fWartosc*LiczbaRzeczywista);
    return tmp;
}

CWaluta& CWaluta::operator/(double LiczbaRzeczywista)
{
    CWaluta tmp(*this);
    if(LiczbaRzeczywista==0)
        cout<<"Nie dziel przez zero"<<endl;
    else
        tmp.UstawWartosc(m_fWartosc*LiczbaRzeczywista);
    return tmp;
}

CWaluta& CWaluta::operator+=(CWaluta& LiczbaDodawana)
{
    UstawWartosc(m_fWartosc+LiczbaDodawana.m_fPrzelicznik*LiczbaDodawana.m_fWartosc/m_fPrzelicznik);
    return (*this);
}

CWaluta& CWaluta::operator+=(double LiczbaRzeczywista)
{
    UstawWartosc(m_fWartosc+LiczbaRzeczywista);
    return (*this);
}

CWaluta& CWaluta::operator-=(CWaluta& LiczbaOdejmowana)
{
    UstawWartosc(m_fWartosc-LiczbaOdejmowana.m_fPrzelicznik*LiczbaOdejmowana.m_fWartosc/m_fPrzelicznik);
    return (*this);
}

CWaluta& CWaluta::operator-=(double LiczbaRzeczywista)
{
    UstawWartosc(m_fWartosc-LiczbaRzeczywista);
    return (*this);
}

CWaluta& CWaluta::operator*=(double LiczbaRzeczywista)
{
    UstawWartosc(m_fWartosc*LiczbaRzeczywista);
    return (*this);
}
CWaluta& CWaluta::operator/=(double LiczbaRzeczywista)
{
    if(LiczbaRzeczywista==0)
        cout<<"Nie dziel przez zero"<<endl;
    else
        UstawWartosc(m_fWartosc/LiczbaRzeczywista);
    return (*this);
}

CWaluta& CWaluta::operator=(CWaluta& LiczbaPrzyrownywana)
{
    if(&LiczbaPrzyrownywana!=this)
    {
        m_iPrecyzja=LiczbaPrzyrownywana.m_iPrecyzja;
        m_fWartosc=LiczbaPrzyrownywana.m_fWartosc;
        strcpy(m_csWaluta,LiczbaPrzyrownywana.m_csWaluta);
        AktualizujString();
    }
    return (*this);
}

CWaluta& CWaluta::operator=(double LiczbaRzeczywista)
{
    UstawWartosc(LiczbaRzeczywista);
    return (*this);
}

CWaluta& CWaluta::operator++(int)
{
    CWaluta tmp(*this);
    UstawWartosc(m_fWartosc+1.0);
    return tmp;
}

CWaluta& CWaluta::operator++()
{
    UstawWartosc(m_fWartosc+1.0);
    return (*this);
}

CWaluta& CWaluta::operator--(int)
{
    CWaluta tmp(*this);
    UstawWartosc(m_fWartosc-1.0);
    return tmp;
}

CWaluta& CWaluta::operator--()
{
    UstawWartosc(m_fWartosc-1.0);
    return (*this);
}

void CWaluta::UstawWalute(const char* Waluta)
{
	strcpy(m_csWaluta,Waluta);
}

bool CWaluta::UstawPrzelicznik(double Przelicznik)
{
	if(Przelicznik>0)
	{
		m_fPrzelicznik=Przelicznik;
		return true;
	}
	else
	{
		m_fPrzelicznik=1;
		return false;
	}
}
