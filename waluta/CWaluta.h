#pragma once
#include "CLiczba.h"
class CWaluta :
	public CLiczba
{

public:
	CWaluta(void);
	CWaluta(const char* Waluta, double Przelicznik, double Wartosc, int Precyzja);
	CWaluta(CWaluta& Obj);
	~CWaluta(void);
	void UstawWalute(const char* Waluta);
	bool UstawPrzelicznik(double Przelicznik);
	const char* DajWalute(){return m_csWaluta;}
	const int DajPrzelicznik(){return m_fPrzelicznik;}
	friend double DajWartosc(CWaluta& Kwota);

	CWaluta& operator+(CWaluta& LiczbaDodawana);
	CWaluta& operator+(double LiczbaRzeczywista);
	CWaluta& operator-(CWaluta& LiczbaOdejmowana);
	CWaluta& operator-(double LiczbaRzeczywista);
	CWaluta& operator*(double LiczbaRzeczywista);
	CWaluta& operator/(double LiczbaRzeczywista);
	CWaluta& operator+=(CWaluta& LiczbaDodawana);
	CWaluta& operator+=(double LiczbaRzeczywista);
	CWaluta& operator-=(CWaluta& LiczbaOdejmowana);
	CWaluta& operator-=(double LiczbaRzeczywista);
	CWaluta& operator*=(double LiczbaRzeczywista);
	CWaluta& operator/=(double LiczbaRzeczywista);
	CWaluta& operator=(CWaluta& LiczbaPrzyrownywana);
	CWaluta& operator=(double LiczbaRzeczywista);
	CWaluta& operator++(int);
	CWaluta& operator++();
    CWaluta& operator--(int);
	CWaluta& operator--();

private:
	double m_fPrzelicznik;
	char m_csWaluta[4];
	virtual void AktualizujString();
};

