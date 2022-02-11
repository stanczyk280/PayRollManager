#pragma once
#include "SqlManager.h"

class Menu
{
public:
	void wyswietlMenuGlowne();
	void wyswietlMenuPracownik();
	void wyswietlMenuWyplata();
	void wyswietlMenu(std::vector<const char*> zawartoscMenu);
	void menuPracownik();
	void menuGlowne();
	void menuWyplata();
	void menuStworz(MenuTypeEnum menuType);
private:
};