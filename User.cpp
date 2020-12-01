#include <iostream>
#include <cstdio>
#include <limits>
#include "Registrasi_akun.cpp"
#include "Dashboard_user.cpp"

using namespace std;


void User()
{
	int pilihan;
	char x,confirm,tmp_buffer[64] = {0};

	Login:
	system("cls");
	cout << "=====================" << endl;
	cout << "Login user menu" << endl;
	cout << "=====================" << endl;
	cout << "\nApakah anda sudah memiliki akun ? [y/n] : ";
	cin >> x;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	

	if (x == 'y' || x == 'Y')
	{
		Dashboard();
	} else if (x == 'N' || x == 'n')
	{
		Sign_up:
		cout << "Buat akun baru ? [y/n] : ";
		cin >> confirm;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		if (confirm == 'Y' || confirm == 'y'){
			Registrasi();
		} else if (confirm == 'N' || confirm == 'n'){
			cout << "Gagal membuat akun baru" << endl;
			getchar();
			return;
		} else {
			cout << "Harap masukkan inputan yang benar!" << endl;
			getchar();
			goto Sign_up;
		}

	} else {
		cout << "Harap masukkan inputan yang benar!" << endl;
		getchar();
		goto Login;
	}

	return;
	
}
