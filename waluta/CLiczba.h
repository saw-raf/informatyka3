#pragma once

using namespace std;

class CLiczba
{

public:// publiczne metody

	CLiczba(double Wartosc=0.0);//konsturktor
	CLiczba(double Wartosc, int Precyzja);//inny konsturktor
	CLiczba(CLiczba &Object);//konsturktor kopiujacy
	virtual ~CLiczba(void);//destruktor

	void Drukuj();//wypisuje na ekranie wartosc liczby ze zmiennej m_csWartoscString
	void UstawWartosc(double Wartosc);//setter dla m_fWartosc
	bool UstawPrecyzje(int Precyzja);//setter dla m_iPrecyzja

	//operatory
	CLiczba& operator+(CLiczba& LiczbaDodawana);
	CLiczba& operator+(double LiczbaRzeczywista);
	CLiczba& operator-(CLiczba& LiczbaOdejmowana);
	CLiczba& operator-(double LiczbaRzeczywista);
	CLiczba& operator*(CLiczba& LiczbaMnozona);
	CLiczba& operator*(double LiczbaRzeczywista);
	CLiczba& operator/(CLiczba& LiczbaDzielona);
	CLiczba& operator/(double LiczbaRzeczywista);
	CLiczba& operator+=(CLiczba& LiczbaDodawana);
	CLiczba& operator+=(double LiczbaRzeczywista);
	CLiczba& operator-=(CLiczba& LiczbaOdejmowana);
	CLiczba& operator-=(double LiczbaRzeczywista);
	CLiczba& operator*=(CLiczba& LiczbaMnozona);
	CLiczba& operator*=(double LiczbaRzeczywista);
	CLiczba& operator/=(CLiczba& LiczbaDzielona);
	CLiczba& operator/=(double LiczbaRzeczywista);
	CLiczba& operator=(CLiczba& LiczbaPrzyrownywana);
	CLiczba& operator=(double LiczbaRzeczywista);
	CLiczba& operator++(int);
	CLiczba& operator++();
    CLiczba& operator--(int);
	CLiczba& operator--();

	//akcesory ze slowkiem const- na pewno nie beda zmieniac obiektu
	const inline double DajWartosc(void) {return m_fWartosc;};//getter inline dla m_fWartosc
	const inline int DajPrecyzje(void) {return m_iPrecyzja;};//getter inline dla m_fWartosc
	const inline char* DajStringa(void) {return m_csWartoscString;};//getter inline dla m_fWartosc

protected:

	//chronione atrybuty
	double m_fWartosc;
	int m_iPrecyzja;
	char* m_csWartoscString;

	//chronione metody
	virtual void AktualizujString(void); //metoda wirtualna aktualizujaca m_csWartoscString

};
