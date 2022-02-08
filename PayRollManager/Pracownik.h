#pragma once
#include "Menu.h"

class Pracownik
{
public:
	Pracownik(char* imie, char* nazwisko, char* pesel, char* status, char* zarobki);
	~Pracownik();
	void dodajPracownika(char* imie, char* nazwisko, char* pesel, char* status, char* zarobki);
	void usunPracownika();
	void modyfikujPracownika();
protected:
	char* imie_;
	char* nazwisko_;
	char* pesel_;
	char* status_;
	char* zarobki_;
};