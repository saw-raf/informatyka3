#include "CLiczba.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


void CLiczba::AktualizujString(void)
{
	char buf[100];
	sprintf(buf,"%.*lf",m_iPrecyzja,m_fWartosc);
	if(m_csWartoscString!=NULL)//zabezpieczenie przed wyciekiem pamieci
	{
		delete[] m_csWartoscString;
		m_csWartoscString=NULL;
	}
	m_csWartoscString=new char[strlen(buf)+1];//nadajemy odpowiedni rozmiar,  wielkosc buf + 1 miejsce na znak \0
	strcpy(m_csWartoscString,buf);//kopiowanie buf do atrybutu
}


CLiczba::CLiczba(double Wartosc)
	:m_fWartosc(Wartosc),m_iPrecyzja(3),m_csWartoscString(NULL)
{
	//cout<<"Konstruktor CLiczba(double Wartosc)"<<endl;
	AktualizujString();
}

CLiczba::CLiczba(double Wartosc,int Precyzja)
	:m_fWartosc(Wartosc),m_iPrecyzja(Precyzja),m_csWartoscString(NULL)
{
	//cout<<"Konstruktor CLiczba(double Wartosc,int Precyzja)"<<endl;
	AktualizujString();
}

//kostruktor kopiujacy - zabezpieczenie przed wskazaniem na to samo przez m_csWartoscString
CLiczba::CLiczba(CLiczba& Object)
	:m_fWartosc(Object.m_fWartosc),m_iPrecyzja(Object.m_iPrecyzja),m_csWartoscString(NULL)
{
	//cout<<"Konstruktor CLiczba(CLiczba% Object)"<<endl;
	AktualizujString();
}

CLiczba::~CLiczba(void)
{
	if(m_csWartoscString!=NULL)//zabezpieczenie przed wyciekiem pamieci
	{
		delete[] m_csWartoscString;
		m_csWartoscString=NULL;
	}

	//cout<<"Destruktor CLiczba. Skasowano"<<endl;
}

CLiczba& CLiczba::operator+(CLiczba& LiczbaDodawana)
{
    CLiczba tmp(*this);
    tmp.UstawWartosc(m_fWartosc+LiczbaDodawana.m_fWartosc);
    return tmp;
}

CLiczba& CLiczba::operator+(double LiczbaRzeczywista)
{
    CLiczba tmp(*this);
    tmp.UstawWartosc(m_fWartosc+LiczbaRzeczywista);
    return tmp;
}

CLiczba& CLiczba::operator-(CLiczba& LiczbaOdejmowana)
{
    CLiczba tmp(*this);
    tmp.UstawWartosc(m_fWartosc-LiczbaOdejmowana.m_fWartosc);
    return tmp;
}

CLiczba& CLiczba::operator-(double LiczbaRzeczywista)
{
    CLiczba tmp(*this);
    tmp.UstawWartosc(m_fWartosc-LiczbaRzeczywista);
    return tmp;
}

CLiczba& CLiczba::operator*(CLiczba& LiczbaMnozona)
{
    CLiczba tmp(*this);
    tmp.UstawWartosc(m_fWartosc*LiczbaMnozona.m_fWartosc);
    return tmp;
}

CLiczba& CLiczba::operator*(double LiczbaRzeczywista)
{
    CLiczba tmp(*this);
    tmp.UstawWartosc(m_fWartosc*LiczbaRzeczywista);
    return tmp;
}

CLiczba& CLiczba::operator/(CLiczba& LiczbaDzielona)
{
    CLiczba tmp(*this);
    if(LiczbaDzielona.m_fWartosc==0)
        cout<<"Niedozwolone dzielenie przez 0 !!!"<<endl;
    else
        tmp.UstawWartosc(m_fWartosc*1.0/LiczbaDzielona.m_fWartosc);
    return tmp;
}

CLiczba& CLiczba::operator/(double LiczbaRzeczywista)
{
    CLiczba tmp(*this);
    if(LiczbaRzeczywista==0)
        cout<<"Niedozwolone dzielenie przez 0 !!!"<<endl;
    else
        tmp.UstawWartosc(m_fWartosc*1.0/LiczbaRzeczywista);
    return tmp;
}

CLiczba& CLiczba::operator+=(CLiczba& LiczbaDodawana)
{
    UstawWartosc(m_fWartosc+LiczbaDodawana.m_fWartosc);
    return (*this);
}

CLiczba& CLiczba::operator+=(double LiczbaRzeczywista)
{
    UstawWartosc(m_fWartosc+LiczbaRzeczywista);
    return (*this);
}

CLiczba& CLiczba::operator-=(CLiczba& LiczbaOdjemowana)
{
    UstawWartosc(m_fWartosc-LiczbaOdjemowana.m_fWartosc);
    return (*this);
}

CLiczba& CLiczba::operator-=(double LiczbaRzeczywista)
{
    UstawWartosc(m_fWartosc-LiczbaRzeczywista);
    return (*this);
}

CLiczba& CLiczba::operator*=(CLiczba& LiczbaMnozona)
{
    UstawWartosc(m_fWartosc*LiczbaMnozona.m_fWartosc);
    return (*this);
}

CLiczba& CLiczba::operator*=(double LiczbaRzeczywista)
{
    UstawWartosc(m_fWartosc*LiczbaRzeczywista);
    return (*this);
}

CLiczba& CLiczba::operator/=(CLiczba& LiczbaDzielona)
{
    if(LiczbaDzielona.m_fWartosc==0)
        cout<<"Nie dziel przez zero"<<endl;
    else
        UstawWartosc(m_fWartosc*1.0/LiczbaDzielona.m_fWartosc);
    return (*this);
}

CLiczba& CLiczba::operator/=(double LiczbaRzeczywista)
{
    if(LiczbaRzeczywista==0)
        cout<<"Nie dziel przez zero"<<endl;
    else
        UstawWartosc(m_fWartosc*1.0/LiczbaRzeczywista);
    return (*this);
}

CLiczba& CLiczba::operator=(CLiczba& LiczbaPrzyrownywana)
{
    if(&LiczbaPrzyrownywana!=this)
    {
        m_iPrecyzja=LiczbaPrzyrownywana.m_iPrecyzja;
        m_fWartosc=LiczbaPrzyrownywana.m_fWartosc;
        AktualizujString();
    }
    return (*this);
}

CLiczba& CLiczba::operator=(double LiczbaRzeczywista)
{
    UstawWartosc(LiczbaRzeczywista);
    return (*this);
}

CLiczba& CLiczba::operator++(int)
{
    CLiczba tmp(*this);
    UstawWartosc(m_fWartosc+1.0);
    return tmp;
}

CLiczba& CLiczba::operator++()
{
    UstawWartosc(m_fWartosc+1.0);
    return (*this);
}

CLiczba& CLiczba::operator--(int)
{
    CLiczba tmp(*this);
    UstawWartosc(m_fWartosc-1.0);
    return tmp;
}

CLiczba& CLiczba::operator--()
{
    UstawWartosc(m_fWartosc-1.0);
    return (*this);
}

void CLiczba::Drukuj(void)
{
	cout<<m_csWartoscString<<endl;
}

void CLiczba::UstawWartosc(double Wartosc)
{
	m_fWartosc=Wartosc;
	AktualizujString();
}

bool CLiczba::UstawPrecyzje(int Precyzja)
{
	if(Precyzja>=0 && Precyzja<10)
	{
		m_iPrecyzja=Precyzja;
		AktualizujString();
		return true;
	}
	return false;
}
