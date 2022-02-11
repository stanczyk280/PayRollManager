#include "SqlManager.h"

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

void Pracownik::DodajPracownika()
{
	SqlManager sqlmanager;
	std::cout << "WprowadŸ dane pracownika:" << std::endl;
	std::cout << "Imiê: ";
	std::cin >> imie_;
	std::cout << std::endl;
	std::cout << "Nazwisko: ";
	std::cin >> nazwisko_;
	std::cout << std::endl;
	std::cout << "Numer pesel: ";
	std::cin >> pesel_;
	std::cout << std::endl;
	std::cout << "Status(student/niepe³nosprawny/zwyk³y: ";
	std::cin >> status_;
	std::cout << std::endl;
	std::cout << "Rodzaj umowy: ";
	std::cin >> zarobki_;
	std::cout << std::endl;
	sqlmanager.InsertTablePracownicy(imie_, nazwisko_,
		pesel_, status_, zarobki_);
}

void Pracownik::WyswietlListePracownikow()
{
	SqlManager sqlmanager;
	sqlmanager.SelectFromTablePracownicy();
}