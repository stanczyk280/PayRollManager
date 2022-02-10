#pragma once
#include <vector>
#include "MenuTypeEnum.h"
#include "SqlManager.h"

class Menu : SqlManager
{
public:
	Menu();
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