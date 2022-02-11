#pragma once
#include "SqlManager.h"

class Pracownik
{
public:
	Pracownik(char* imie, char* nazwisko, char* pesel, char* status, char* zarobki);
	Pracownik();
	~Pracownik();
	void DodajPracownika();
	void WyswietlListePracownikow();
	void UsunPracownika();
	void ModyfikujPracownika();
protected:
	char* imie_;
	char* nazwisko_;
	char* pesel_;
	char* status_;
	char* zarobki_;
};