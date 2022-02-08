#include "SqlManager.h"

SqlManager::SqlManager(sqlite3* db, char* zErrMsg, int rc)
{
	this->db_ = db;
	this->zErrMsg_ = zErrMsg;
	this->rc_ = rc;
}

SqlManager::~SqlManager()
{
}

void SqlManager::SqlOpen(sqlite3* db)
{
	rc_ = sqlite3_open("pracownicy.db", &db);

	if (rc_)
	{
		std::cout << "Nie uda³o siê po³¹czyæ z baz¹ danych: " << sqlite3_errmsg(db) << std::endl;
	}
	else
	{
		std::cout << "Uda³o siê po³¹czyæ z baz¹ danych";
	}
}

void SqlManager::CreateTablePracownicy()
{
	SqlOpen(db_);

	const char* createTablePracownicyQuery =
		"CREATE TABLE IF NOT EXISTS PRACOWNICY("  \
		"ID INT PRIMARY KEY     NOT NULL," \
		"IMIÊ           TEXT    NOT NULL," \
		"NAZWISKO       TEXT    NOT NULL," \
		"PESEL          CHAR[11] NOT NULL," \
		"STATUS         CHAR[50] NOT NULL," \
		"ZAROBKI        REAL     NOT NULL);";

	rc_ = sqlite3_exec(db_, createTablePracownicyQuery, NULL, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "B£¥D SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Tabela zosta³a utworzona pomyœlnie." << std::endl;
	}

	sqlite3_close(db_);
}

void SqlManager::InsertTablePracownicy(std::string imie, std::string nazwisko,
	std::string pesel, std::string status, std::string zarobki)
{
	SqlOpen(db_);

	std::string insertTablePracownicyQuery = "INSERT INTO PRACOWNICY (" + imie + "," + nazwisko + ","
		+ pesel + "," + status + "," + zarobki + ");";

	const char* insertTablePracownicyQueryParsed = insertTablePracownicyQuery.c_str();

	rc_ = sqlite3_exec(db_, insertTablePracownicyQueryParsed, NULL, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "B£¥D SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zosta³y dodane pomyœlnie." << std::endl;
	}
	sqlite3_close(db_);
}