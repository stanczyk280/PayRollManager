#include "Pracownik.h"

Pracownik::Pracownik(char* imie, char* nazwisko, char* pesel, char* status, char* zarobki)
{
	this->imie_ = imie;
	this->nazwisko_ = nazwisko;
	this->pesel_ = pesel;
	this->status_ = status;
	this->zarobki_ = zarobki;
}

Pracownik::~Pracownik()
{
}

void Pracownik::dodajPracownika(char* imie, char* nazwisko, char* pesel, char* status, char* zarobki)
{
	std::cout << "Wprowad� dane pracownika:" << std::endl;
	std::cout << "Imi�: ";
	std::cin >> imie_;
	std::cout << std::endl;
	std::cout << "Nazwisko: ";
	std::cin >> nazwisko_;
	std::cout << std::endl;
	std::cout << "Numer pesel: ";
	std::cin >> pesel_;
	std::cout << std::endl;
	std::cout << "Status(student/niepe�nosprawny/zwyk�y: ";
	std::cin >> status_;
	std::cout << std::endl;
	std::cout << "Rodzaj umowy: ";
	std::cin >> zarobki_;
	std::cout << std::endl;
}