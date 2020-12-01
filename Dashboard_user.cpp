#include <iostream>
#include <cstdio>
#include <limits>
#include <string.h>
#include "Registrasi_akun.cpp"
#include "Show_jadwal.cpp"
// #include "Informasi_penerbangan.cpp"
#include "Booking_tiket.cpp"
#include "Informasi.cpp"

#define file_database_user "database_user.txt"
#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"

using namespace std;


void Dashboard2 (char email[64], char password[16]);
void Profile (char email[64], char password[16]);


void Dashboard () {

	FILE *handle;
	bool cek;
	unsigned int nread = 0;
	struct User user,tmp;

	cout << "Masukkan Email\t\t: ";
	cin.getline(tmp.email,63);
	cout << "Masukkan Password\t: ";
	cin.getline(tmp.password,15);

	handle = fopen(file_database_user,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle)){
			nread = fread(&user, sizeof(user), 1, handle);
			if (nread == 0)
			{
				break;
			}

			if (!strcmp(user.email,tmp.email) && !strcmp(user.password,tmp.password)){
				cout << "Login Berhasil" << endl;
				cek = true;
				Dashboard2(tmp.email,tmp.password);
			} 
		}

		if (!cek){
			cout << "Login Gagal" << endl;
			getchar();
		}
		fclose(handle);
	}
}

void Dashboard2 (char email[64], char password[16]) {
	FILE *handle;
	int pilihan;
	char x,tmp_buffer[64] = {0};
	struct User user;
	string menu_user[] = {
		"Profile",
		"Informasi Penerbangan",
		// "Perubahan Jadwal",
		// "Cancel Penerbangan",
		"Booking Tiket",
		"Logout"
	};

	Menu_user:
	system("cls");
	cout << "====================" << endl;
	cout << "Menu User" << endl;
	cout << "====================" << endl;
	for (int i = 0; i < sizeof(menu_user)/sizeof(menu_user[0]); ++i)
	{
		cout << i+1 << ". " << menu_user[i] << endl;
	}
	cout << "\nPilih menu : ";
	fgets(tmp_buffer, 32, stdin);
	pilihan = atoi(tmp_buffer);

	enum option{PROFILE = 1, INFO, BOOKING, FINISH};
	while (pilihan != FINISH) {
		switch (pilihan) {
			case PROFILE: Profile(email,password); break;
			case INFO: Informasi(); break;
			// case CANCEL: break;
			case BOOKING: Booking(); break;
			default: cout << "Pilihan tidak tersedia" << endl; getchar(); break;
		}
		goto Menu_user;
	}

	if (pilihan == FINISH){
		Konfirmasi:
		cout << "Apakah anda yakin ingin logout ? [y/n] : ";
		cin >> x;
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		if (x == 'Y' || x == 'y'){
			return;
		} else if (x == 'N' || x == 'n')
		{
			goto Menu_user;
		} else {
			cout << "Inputkan pilihan dengan benar!" << endl;
			goto Konfirmasi;
		}
		
	}
	return;

}

void Profile (char email[64], char password[16]) {
	FILE *handle;
	struct User user;
	int i=1, tmp=0;
	unsigned int nread=0;

	system("cls");
	cout << "=================" << endl;
	cout << "Profile User" << endl;
	cout << "=================" << endl;
	handle = fopen(file_database_user, "r");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
	} else {
		while (!feof(handle)) {
			nread = fread(&user, 1, sizeof(user), handle);
			if (nread == 0) break;
			if (!strcmp(user.email,email) && !strcmp(user.password,password))
			{

				cout << "Nama Lengkap\t\t: " << user.nama << endl;
				cout << "Nomor ID \t\t: " << user.id << endl;
				cout << "Tempat & Tanggal Lahir\t: " << user.ttl << endl;
				cout << "Alamat Lengkap\t\t: " << user.alamat << endl;
				cout << "Username\t\t: " << user.username << endl;
				cout << "Password\t\t: " << user.password << endl;
				cout << "Riwayat Penyakit\t: " << user.riwayat_penyakit << endl;
				cout << "No Telepon\t\t: " << user.kontak << endl;
				cout << "Email Aktif\t\t: " << user.email << endl;
			}
		}
		cout << "\nPress Enter to Back!" << endl;
		getchar();
		fclose(handle);

	}
}

