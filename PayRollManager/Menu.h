#pragma once
#include <iostream>
#include <string>
#include "MenuTypeEnum.h"
#include <vector>
#include <winsqlite/winsqlite3.h>
#include <fstream>
#include <sql.h>
#include "sqlite3.h"
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
	void menuStworz(TypeEnum menuType);
private:
};