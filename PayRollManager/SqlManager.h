#pragma once
#include "Menu.h"
#include "Pracownik.h"

class SqlManager
{
public:
	SqlManager(sqlite3* db, char* zErrMsg, int rc);
	~SqlManager();
	void SqlOpen(sqlite3* db);
	void CreateTablePracownicy();
	void InsertTablePracownicy(std::string imie, std::string nazwisko,
		std::string pesel, std::string status, std::string zarobki);
protected:
	sqlite3* db_;
	char* zErrMsg_ = 0;
	int rc_;
};