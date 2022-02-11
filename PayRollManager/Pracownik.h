#pragma once
#include "SqlManager.h"

class Pracownik
{
public:
	Pracownik(std::string, std::string, std::string, std::string, std::string zarobki);
	Pracownik();
	~Pracownik();
	void DodajPracownika();
	void WyswietlListePracownikow();
	void UsunPracownika();
	void ModyfikujPracownika();
protected:
	std::string imie_;
	std::string nazwisko_;
	std::string pesel_;
	std::string status_;
	std::string zarobki_;
};