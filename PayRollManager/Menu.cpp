#include "SqlManager.h"

void Menu::wyswietlMenuGlowne()
{
	std::vector<const char*> zawartoscMenu =
	{
		 "PAYROLL MANAGER SYSTEM",
		 "WYBIERZ JEDNA Z OPCJI Z LISTY PONIZEJ",
		 "1. MENU PRACOWNIK",
		 "2. MENU WYPLATA",
		 "3. ZAKONCZ",
	};
	wyswietlMenu(zawartoscMenu);
}

void Menu::wyswietlMenuPracownik()
{
	std::vector<const char*> zawartoscMenu =
	{
		"MENU: PRACOWNICY",
		"WYBIERZ JEDNA Z OPCJI Z LISTY PONIZEJ",
		"1. NOWY PRACOWNIK",
		"2. WYSWIETL PRACOWNIKA",
		"3. LISTA PRACOWNIKOW",
		"4. USUN PRACOWNIKA",
		"5. EDYTUJ INFORMACJE PRACOWNIKA",
		"6. ROZLICZENIE",
		"7. POWROT",
	};
	wyswietlMenu(zawartoscMenu);
}

void Menu::wyswietlMenuWyplata()
{
	std::vector<const char*> zawartoscMenu =
	{
		"MENU: WYPLATA",
		"WYBIERZ JEDNA Z OPCJI Z LISTY PONIZEJ",
		"1. PRZELICZ ZAROBKI",
		"2. WYLICZ PODATEK",
		"3. WYDRUKUJ ROZLICZENIE",
		"4. POWROT",
	};
	wyswietlMenu(zawartoscMenu);
}

void Menu::wyswietlMenu(std::vector<const char*> zawartoscMenu)
{
	for (auto linia : zawartoscMenu)
	{
		std::cout << linia << std::endl;
	}
}

void Menu::menuStworz(MenuTypeEnum menuType)
{
	switch (menuType)
	{
	case MenuTypeEnum::Glowne:
		menuGlowne();
		break;
	case MenuTypeEnum::Pracownik:
		menuPracownik();
		break;
	case MenuTypeEnum::Wyplata:
		menuWyplata();
		break;
	}
}

void Menu::menuGlowne()
{
	int running = 1;
	char potwierdz;
	int wyborUzytkownika;

	do
	{
		wyswietlMenuGlowne();

		std::cin >> wyborUzytkownika;
		switch (wyborUzytkownika)
		{
		case 1:
			system("cls");
			menuStworz(MenuTypeEnum::Pracownik);
			break;
		case 2:
			system("cls");
			menuStworz(MenuTypeEnum::Wyplata);
			break;
		case 3:
			std::cout << "Czy chcesz zakonczyc prace" << std::endl << "T/N" << std::endl;
			std::cin >> potwierdz;
			if (potwierdz == 'T' || potwierdz == 't')
			{
				running = 0;
				break;
			}
			running = 1;
			break;
		default:
			running = 1;
			break;
		}
	} while (running != 0);
}

void Menu::menuPracownik()
{
	int running = 1;
	int wyborUzytkownika;
	Pracownik p;

	do
	{
		wyswietlMenuPracownik();

		std::cin >> wyborUzytkownika;
		switch (wyborUzytkownika)
		{
		case 1:
			system("cls");
			std::cout << "1" << std::endl;
			p.DodajPracownika();
			break;
		case 2:
			system("cls");
			std::cout << "wyswietl pracownika" << std::endl;
			break;
		case 3:
			system("cls");
			p.WyswietlListePracownikow();
			break;
		case 4:
			system("cls");
			std::cout << "usun pracownika" << std::endl;
			break;
		case 5:
			system("cls");
			std::cout << "edytuj info" << std::endl;
			break;
		case 6:
			system("cls");
			std::cout << "rozliczenie" << std::endl;
			break;
		case 7:
			system("cls");
			running = 0;
			break;
		default:
			running = 1;
			break;
		}
	} while (running != 0);
}

void Menu::menuWyplata()
{
	int running = 1;
	int wyborUzytkownika;

	do
	{
		wyswietlMenuWyplata();

		std::cin >> wyborUzytkownika;
		switch (wyborUzytkownika)
		{
		case 1:
			system("cls");
			std::cout << "PRZELICZ ZAROBKI" << std::endl;
			break;
		case 2:
			system("cls");
			std::cout << "WYLICZ PODATEK" << std::endl;
			break;
		case 3:
			system("cls");
			std::cout << "WYDRUK" << std::endl;
			break;
		case 4:
			system("cls");
			running = 0;
			break;
		default:
			running = 1;
			break;
		}
	} while (running != 0);
}