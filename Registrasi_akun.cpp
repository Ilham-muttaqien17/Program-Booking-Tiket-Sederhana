#ifndef USER
#define USER
#include <iostream>
#include <cstdio>
#include <limits>

#define file_database_user "database_user.txt"

using namespace std;

struct User{
	char nama[32];
	char id[32];
	char ttl[32];
	char alamat[64];
	char riwayat_penyakit[32];
	char username[16];
	char password[16];
	char kontak[16];
	char email[64];
};

void Registrasi () {

	FILE *handle;
	struct User user;
	char buffer[32], simpan;

	system("cls");
	cout << "======================" << endl ;
	cout << "Registrasi Akun" << endl;
	cout << "======================" << endl ;
	cout << "Nama Lengkap\t\t\t: ";
	cin.getline(user.nama,31);
	cout << "Nomor ID [KTP/PASSPORT/dll]\t: ";
	cin.getline(user.id,31);
	cout << "Tempat & Tanggal Lahir\t\t: ";
	cin.getline(user.ttl,31);
	cout << "Alamat Lengkap\t\t\t: ";
	cin.getline(user.alamat,63);
	cout << "Username\t\t\t: ";
	cin.getline(user.username,15);
	cout << "Password\t\t\t: ";
	cin.getline(user.password,15);
	cout << "Riwayat Penyakit\t\t: ";
	cin.getline(user.riwayat_penyakit,31);
	cout << "No Telepon\t\t\t: ";
	cin.getline(user.kontak,31);
	
	cout << "Email Aktif\t\t\t: ";
	cin.getline(user.email,63);

	Konfirmasi:
	system("cls");
	cout << "======================" << endl ;
	cout << "Biodata User" << endl;
	cout << "======================" << endl ;
	cout << "Nama Lengkap\t\t: " << user.nama << endl;
	cout << "Nomor ID \t\t: " << user.id << endl;
	cout << "Tempat & Tanggal Lahir\t: " << user.ttl << endl;
	cout << "Alamat Lengkap\t\t: " << user.alamat << endl;
	cout << "Username\t\t: " << user.username << endl;
	cout << "Password\t\t: " << user.password << endl;
	cout << "Riwayat Penyakit\t: " << user.riwayat_penyakit << endl;
	cout << "No Telepon\t\t: " << user.kontak << endl;
	cout << "Email Aktif\t\t: " << user.email << endl;
	cout << "\nSimpan biodata ? [y/n] : ";
	cin >> simpan;
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	if (simpan == 'Y' || simpan == 'y'){	
		handle = fopen(file_database_user,"ab+");
		if (handle == NULL)
		{
			cout << "Database Kosong" << endl;
		} else {
			fwrite(&user, sizeof(user), 1, handle);
			fclose(handle);	
		}
		cout << "Data berhasil disimpan" << endl;
		getchar();

	} else if (simpan == 'N' || simpan == 'n'){
		cout << "Data gagal disimpan" << endl;
		getchar();
		return;
	} else {
		cout << "Inputkan pilihan dengan benar!" << endl;
		getchar();
		goto Konfirmasi;
	}

	return;
}
#endif