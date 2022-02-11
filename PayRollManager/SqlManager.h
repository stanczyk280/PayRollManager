#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "MenuTypeEnum.h"
#include "sqlite3.h"
#include "Menu.h"
#include "Pracownik.h"

class SqlManager
{
public:
	SqlManager(sqlite3* db, char* zErrMsg, int rc);
	SqlManager() = default;
	~SqlManager();
	void SqlOpen(sqlite3* db);
	static int Callback(void* data, int argc, char** argv, char** zColName);
	void CreateTablePracownicy();
	void InsertTablePracownicy(std::string imie, std::string nazwisko,
		std::string pesel, std::string status, std::string zarobki);
	void SelectFromTablePracownicy();
protected:
	sqlite3* db_;
	char* zErrMsg_ = 0;
	int rc_;
};