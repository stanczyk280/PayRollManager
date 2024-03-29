#include "SqlManager.h"

SqlManager::SqlManager(sqlite3* db, char* zErrMsg, int rc)
{
	this->db_ = db;
	this->zErrMsg_ = zErrMsg;
	this->rc_ = rc;
}

SqlManager::SqlManager()
{
}

SqlManager::~SqlManager()
{
}

void SqlManager::SqlOpen(sqlite3* db)
{
	rc_ = sqlite3_open("pracownicy.db", &db_);

	if (rc_)
	{
		std::cout << "Nie udalo sie polaczy� z baza danych: " << sqlite3_errmsg(db) << std::endl;
	}
	else
	{
		std::cout << "Udalo sie polaczyc z baza danych" << std::endl;
	}
}

int SqlManager::Callback(void* data, int argc, char** argv, char** zColName)
{
	for (int i = 0; i < argc; i++)
	{
		std::cout << zColName[i] << ":" << (argv[i] ? argv[i] : "NULL") << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

void SqlManager::CreateTablePracownicy()
{
	SqlOpen(db_);

	const char* createTablePracownicyQuery = "CREATE TABLE IF NOT EXISTS PRACOWNICY("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
		"IMIE                  TEXT     NOT NULL,"
		"NAZWISKO              TEXT     NOT NULL,"
		"PESEL                 TEXT     NOT NULL,"
		"STATUS                TEXT     NOT NULL,"
		"ZAROBKI               INT      NOT NULL);";
	rc_ = sqlite3_exec(db_, createTablePracownicyQuery, this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "BLAD SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Polaczenie z tabela ustanowiono pomyslnie." << std::endl;
	}

	sqlite3_close(db_);
}

void SqlManager::InsertTablePracownicy(std::string imie, std::string nazwisko,
	std::string pesel, std::string status, std::string zarobki)
{
	SqlOpen(db_);

	std::string insertTablePracownicyQuery = "INSERT INTO pracownicy (IMIE, NAZWISKO, PESEL, STATUS, ZAROBKI) VALUES ('"
		+ imie + "','"
		+ nazwisko + "','"
		+ pesel + "','"
		+ status + "','"
		+ zarobki + "');";

	rc_ = sqlite3_exec(db_, insertTablePracownicyQuery.c_str(), this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "BLAD SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zostaly dodane pomyslnie." << std::endl;
	}
	sqlite3_close(db_);
}

void SqlManager::SelectFromTablePracownicy(std::string pesel)
{
	SqlOpen(db_);
	std::string SelectFromTablePracownicyQuery = " SELECT * FROM PRACOWNICY WHERE PESEL = " + pesel + ";";

	rc_ = sqlite3_exec(db_, SelectFromTablePracownicyQuery.c_str(), this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "BLAD SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zostaly wyswietlone pomyslnie" << std::endl;
	}
	sqlite3_close(db_);
}

void SqlManager::SelectAllFromTablePracownicy()
{
	SqlOpen(db_);
	std::string SelectAllFromTablePracownicyQuery = " SELECT * FROM PRACOWNICY;";
	rc_ = sqlite3_exec(db_, SelectAllFromTablePracownicyQuery.c_str(), this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "BLAD SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zostaly wyswietlone pomyslnie" << std::endl;
	}
	sqlite3_close(db_);
}

void SqlManager::SelectSpecificFromTable(std::string col, std::string value, std::string op)
{
	SqlOpen(db_);
	std::string SelectAllFromTablePracownicyQuery = " SELECT * FROM pracownicy WHERE " + col + " "
		+ op + " '" + value + "';";

	rc_ = sqlite3_exec(db_, SelectAllFromTablePracownicyQuery.c_str(), this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "BLAD SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zostaly wyswietlone pomyslnie" << std::endl;
	}
	sqlite3_close(db_);
}

void SqlManager::DeleteFromTable(std::string pesel)
{
	SqlOpen(db_);
	std::string DeleteFromTableQuery = "DELETE FROM pracownicy WHERE PESEL = " + pesel + ";";

	rc_ = sqlite3_exec(db_, DeleteFromTableQuery.c_str(), this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "BLAD SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zostaly usuniete pomyslnie" << std::endl;
	}
	sqlite3_close(db_);
}

void SqlManager::ModifyInTable(std::string pesel, std::string data, std::string col)
{
	SqlOpen(db_);
	std::string ModifyInTableQuery = "UPDATE pracownicy SET " + col + " = '" + data + "' WHERE PESEL = " + pesel + "; ";

	rc_ = sqlite3_exec(db_, ModifyInTableQuery.c_str(), this->Callback, 0, &zErrMsg_);

	if (rc_ != SQLITE_OK) {
		std::cout << "BLAD SQL: " << zErrMsg_ << std::endl;
		sqlite3_free(zErrMsg_);
	}
	else
	{
		std::cout << "Dane zostaly zmodyfikowane pomyslnie" << std::endl;
	}
	sqlite3_close(db_);
}