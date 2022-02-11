#include "SqlManager.h"

Pracownik::Pracownik(std::string imie, std::string nazwisko, std::string pesel, std::string status, std::string zarobki)
{
	this->imie_ = imie;
	this->nazwisko_ = nazwisko;
	this->pesel_ = pesel;
	this->status_ = status;
	this->zarobki_ = zarobki;
}

Pracownik::Pracownik()
{
}

Pracownik::~Pracownik()
{
}

void Pracownik::DodajPracownika()
{
	SqlManager sqlmanager;
	int running = 1;

	std::cout << "WprowadŸ dane pracownika:" << std::endl;
	std::cout << "Imie: ";
	std::cin >> imie_;
	std::cout << std::endl;
	std::cout << "Nazwisko: ";
	std::cin >> nazwisko_;
	std::cout << std::endl;
	do
	{
		std::cout << "Numer pesel: ";
		std::cin >> pesel_;
		if (pesel_.length() != 11)
		{
			std::cout << std::endl << "Niepoprawny pesel! " << std::endl;
		}
		else
		{
			running = 0;
		}
	} while (running != 0);
	std::cout << std::endl;
	std::cout << "Status(student/niepelnosprawny/zwykly: ";
	std::cin >> status_;
	std::cout << std::endl;
	std::cout << "Zarobki: ";
	std::cin >> zarobki_;
	std::cout << std::endl;
	sqlmanager.InsertTablePracownicy(imie_, nazwisko_,
		pesel_, status_, zarobki_);
}

void Pracownik::WyswietlPracownika()
{
	SqlManager sqlmanager;
	std::cout << "Wprowadz pesel pracownika, ktorego danego chcialbys wyswietlic: ";
	std::cin >> pesel_;
	sqlmanager.SelectFromTablePracownicy(pesel_);
}

void Pracownik::WyswietlListePracownikow()
{
	SqlManager sqlmanager;
	sqlmanager.SelectAllFromTablePracownicy();
}

void Pracownik::UsunPracownika()
{
	SqlManager sqlmanager;

	std::cout << "Wprowadz pesel pracownika, ktorego chcialbys usunac z bazy danych: ";
	std::cin >> pesel_;
	sqlmanager.DeleteFromTable(pesel_);
}