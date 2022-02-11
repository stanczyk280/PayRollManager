#include "SqlManager.h"

int main()
{
	Menu m;
	SqlManager sql;

	sql.CreateTablePracownicy();
	m.menuStworz(MenuTypeEnum::Glowne);
	return 0;
}