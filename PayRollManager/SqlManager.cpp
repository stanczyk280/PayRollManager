#include "SqlManager.h"

SqlManager::SqlManager(sqlite3* db, char* zErrMsg, int rc)
{
	this->db_ = db;
	this->zErrMsg_ = zErrMsg;
	this->rc_ = rc;
}

void SqlManager::SqlOpen(sqlite3* db)
{
	rc_ = sqlite3_open("pracownicy.db", &db_);

	if (rc_)
	{
		std::cout << "Nie uda�o si� po��czy� z baz� danych: " << sqlite3_errmsg(db) << std::endl;
	}
	else
	{
		std::cout << "Uda�o si� po��czy� z baz� danych";
	}
}

int SqlManager::Callback(void* data, int argc, char** argv, char** zColName)
{
	for (int i = 0; i < argc; i++)
	{
		std::cout << zColName[i] << ";" << (argv[i] ? argv[i] : "NULL") << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

void SqlManager::CreateTablePracownicy()
{
	SqlOpen(db_);

	const char* createTablePracownicyQuery =
		"CREATE TABLE IF NOT EXISTS PRACOWNICY("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"IMI�           TEXT    NOT NULL," \
		"NAZWISKO       TEXT    NOT NULL," \
		"PESEL          CHAR[11] NOT NULL," \
		"STATUS         CHAR[50] NOT NULL," \
		"ZAROBKI        REAL     NOT NULL);";

	rc_ = sqlite3_exec(db_, createTablePracownicyQuery, this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "B��D SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Tabela zosta�a utworzona pomy�lnie." << std::endl;
	}

	sqlite3_close(db_);
}

void SqlManager::InsertTablePracownicy(std::string imie, std::string nazwisko,
	std::string pesel, std::string status, std::string zarobki)
{
	SqlOpen(db_);

	std::string insertTablePracownicyQuery = "INSERT INTO PRACOWNICY (" + imie + "," + nazwisko + ","
		+ pesel + "," + status + "," + zarobki + ");";

	rc_ = sqlite3_exec(db_, insertTablePracownicyQuery.c_str(), this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "B��D SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zosta�y dodane pomy�lnie." << std::endl;
	}
	sqlite3_close(db_);
}

void SqlManager::SelectFromTablePracownicy()
{
	SqlOpen(db_);
	std::string SelectFromTablePracownicyQuery = " SELECT * FROM PRACOWNICY;";
	rc_ = sqlite3_exec(db_, SelectFromTablePracownicyQuery.c_str(), this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "B��D SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zosta�y dodane pomy�lnie." << std::endl;
	}
	sqlite3_close(db_);
}