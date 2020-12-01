#include <iostream>
#include <cstdio>
#include <string.h>
#include "User.cpp"
#include "Admin.cpp"

using namespace std;

struct Admin
{
	char username[10][10];
	char password[10][10];

	Admin() {
		strcpy(this->username[0], "ilham");
		strcpy(this->username[1], "rizka");
		strcpy(this->username[2], "dimas");
		strcpy(this->username[3], "fauzi");
		strcpy(this->username[4], "fandi");
		strcpy(this->username[5], "yuda");
		strcpy(this->username[6], "kiki");
		strcpy(this->username[7], "arini");
		strcpy(this->username[8], "sulis");
		strcpy(this->username[9], "aisyah");

		strcpy(this->password[0], "19113027");
		strcpy(this->password[1], "19113007");
		strcpy(this->password[2], "19113020");
		strcpy(this->password[3], "19113004");
		strcpy(this->password[4], "19113047");
		strcpy(this->password[5], "19113013");
		strcpy(this->password[6], "19113031");
		strcpy(this->password[7], "19113011");
		strcpy(this->password[8], "19113034");
		strcpy(this->password[9], "19113015");

	}	
}admin;

int main()
{
	
	int pilih;
	bool cek;
	char username[10], password[10];
	char tmp_buffer[64] = {0};
	char x;
	string menu [] = {

		"User",
		"Admin",
		"Exit"
	};

	Menu:
	system("cls");
	cout << "=========================" << endl;
	cout << "Program Tiket" << endl;
	cout << "=========================" << endl;
	for (int i = 0; i < (sizeof(menu)/sizeof(menu[0])); ++i)
	{
		cout << i+1 << ". " << menu[i] << endl;
	}
	cout << "\nPilih menu : ";
	fgets(tmp_buffer, 32, stdin);
	pilih = atoi(tmp_buffer);

	if (pilih == 1){
		User();
	} else if (pilih == 2){
		cout << "Masukkan username : ";
		cin.getline(username, 10);
		cout << "Masukkan password : ";
		cin.getline(password, 10);
		for (int i = 0; i < 10; i++)
		{
			if (!strcmp(admin.username[i],username) && !strcmp(admin.password[i], password))
			{
				Admin();
				cek = true;
				break;
			} 
		}
		if (!cek)
		{
			cout << "Username atau password salah, harap masukkan dengan benar!" << endl;
			getchar();
			goto Menu;		
		}

		
	} else if (pilih == 3){
		
		cout << "Apakah Anda Yakin Keluar Program ? [y/n] : ";
		cin >> x;
		cin.ignore(1);

		if (x == 'y' || x == 'Y') {
			exit(0);
		} else {
			goto Menu;
		}

	} else {

		cout << "Menu Tidak Tersedia" << endl;
		getchar();
		goto Menu;
	}
	
	goto Menu;
	return 0;
}
