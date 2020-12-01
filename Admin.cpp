#include <iostream>
#include <cstdio>
#include "Create_jadwal.cpp"
#include "Show_jadwal.cpp"
#include "Update_jadwal.cpp"
#include "Delete_jadwal.cpp"
#include "Show_user.cpp"
// #include "Antrean_takeoff.cpp"
#include "Antrean.cpp"

using namespace std;

void Admin() {

	int pilih;
	char tmp_buffer[64] = {0};
	string menu_admin [] = {

		"Create Jadwal",
		"Show Jadwal",
		"Update Jadwal",
		"Delete Jadwal",
		"Show User Sorting [ASC]",
		"Antrean Keberangkatan",
		"Back",
	};

	Menu:
	system("cls");
	cout << "====================" << endl;
	cout << "Menu Admin" << endl;
	cout << "====================" << endl;
	for (int i = 0; i < (sizeof(menu_admin)/sizeof(menu_admin[0])); ++i)
	{
		cout << i+1 << ". " << menu_admin[i] << endl;
	}
	cout << "====================" << endl;
	cout << "\nPilih Menu: ";
	fgets(tmp_buffer, 32, stdin);
	pilih = atoi(tmp_buffer);

	enum option{CREATE = 1, READ, UPDATE, DELETE, SHOW_USR, ANTREAN, FINISH};

	while(pilih != FINISH) {
		switch(pilih){
			case CREATE: Create(); break;
			case READ: Show(); break;
			case UPDATE: Update(); break;
			case DELETE: Delete(); break;
			case SHOW_USR: showUser(); break;
			case ANTREAN : Antrean(); break;
			default: cout << "Menu tidak tersedia" << endl; getchar(); break;
		}
		goto Menu;
	}

	return;

}