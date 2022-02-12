#include "SqlManager.h"

SqlManager sqlmanager;

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
	std::cout << "Wprowadz pesel pracownika, ktorego danego chcialbys wyswietlic: ";
	std::cin >> pesel_;
	sqlmanager.SelectFromTablePracownicy(pesel_);
}

void Pracownik::WyswietlListePracownikow()
{
	sqlmanager.SelectAllFromTablePracownicy();
}

void Pracownik::UsunPracownika()
{
	std::cout << "Wprowadz pesel pracownika, ktorego chcialbys usunac z bazy danych: ";
	std::cin >> pesel_;
	sqlmanager.DeleteFromTable(pesel_);
}

void Pracownik::ModyfikujPracownika()
{
	int wyborUzytkownika;
	char potwierdz;
	int running = 1;
	int finish = 1;
	std::string data;
	std::string col;

	std::cout << "Wprowadz pesel pracownika, ktorego dane chcesz zmodyfikowac: " << std::endl;
	std::cin >> pesel_;
	sqlmanager.SelectFromTablePracownicy(pesel_);

	do
	{
		std::cout << "Jaka rubryke edytowac? " << std::endl;
		std::cout << "1. Imie " << std::endl;
		std::cout << "2. Nazwisko " << std::endl;
		std::cout << "3. Pesel " << std::endl;
		std::cout << "4. Status " << std::endl;
		std::cout << "5. Zarobki" << std::endl;
		std::cout << "6. Zakoncz edycje" << std::endl;
		std::cin >> wyborUzytkownika;

		switch (wyborUzytkownika)
		{
		case 1:
			system("cls");
			col = "IMIE";
			std::cout << "Wprowadz nowe imie pracownika: ";
			std::cin >> data;
			sqlmanager.ModifyInTable(pesel_, data, col);
			system("cls");
			sqlmanager.SelectFromTablePracownicy(pesel_);
			break;
		case 2:
			system("cls");
			col = "NAZWISKO";
			std::cout << "Wprowadz nowe nazwisko pracownika: ";
			std::cin >> data;
			sqlmanager.ModifyInTable(pesel_, data, col);
			system("cls");
			sqlmanager.SelectFromTablePracownicy(pesel_);
			break;
		case 3:
			system("cls");
			col = "PESEL";
			do
			{
				std::cout << "Wprowadz nowy pesel pracownika: ";
				std::cin >> data;
				if (data.length() != 11)
				{
					std::cout << std::endl << "Niepoprawny pesel! " << std::endl;
				}
				else
				{
					finish = 0;
				}
			} while (finish != 0);

			sqlmanager.ModifyInTable(pesel_, data, col);
			system("cls");
			pesel_ = data;
			sqlmanager.SelectFromTablePracownicy(pesel_);
			break;
		case 4:
			system("cls");
			col = "STATUS";
			std::cout << "Wprowadz nowy status pracownika: ";
			std::cin >> data;
			sqlmanager.ModifyInTable(pesel_, data, col);
			system("cls");
			sqlmanager.SelectFromTablePracownicy(pesel_);
			break;
		case 5:
			system("cls");
			col = "ZAROBKI";
			std::cout << "Wprowadz nowe zarobki pracownika: ";
			std::cin >> data;;
			sqlmanager.ModifyInTable(pesel_, data, col);
			system("cls");
			sqlmanager.SelectFromTablePracownicy(pesel_);
			break;
		case 6:
			system("cls");
			running = 0;
			break;
		default:
			running = 1;
			break;
		}

		std::cout << "Czy dalej chcesz modyfikowac dane pracownika?" << std::endl << "T/N" << std::endl;
		std::cin >> potwierdz;
		if (potwierdz == 'n' || potwierdz == 'N')
		{
			running = 0;
		}
	} while (running != 0);
}

void Pracownik::WyswietlPodaneDane()
{
	std::string col;
	std::string op;
	std::string value;

	std::cout << "Wprowadz rodzaj danych do wyswietlenia: " << std::endl;
	std::cin >> col;
	std::cout << "Wyswietl " + col + " gdzie wartosc jest (=, =<, =>, <, >, !=), wprowadz odpowiedni operator:" << std::endl;
	std::cin >> op;
	std::cout << "Wyswietl " + col + " gdzie wartosc jest " + op + " wprowadz wartosc wedlug, ktorej beda wyswietlane dane:" << std::endl;
	std::cin >> value;
	sqlmanager.SelectSpecificFromTable(col, value, op);
}