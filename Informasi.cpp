#include <iostream>
#include <cstdio>
#include <string.h>
#include "Booking_tiket.cpp"
#include "Registrasi_akun.cpp"

using namespace std;

void infoPesawat();
void infoKereta();
void infoBus();



void Informasi() {
	int pilihan;
	
	system("cls");
	cout << "==========================" << endl;
	cout << "Informasi Keberangkatan" << endl;
	cout << "==========================" << endl;
	cout << "[1]. Pesawat" << endl;
	cout << "[2]. Kereta" << endl;
	cout << "[3]. Bus" << endl;
	cout << "==========================" << endl;
	cout << "Pilihan : ";
	cin >> pilihan;
	cin.ignore(1);

	if (pilihan == 1)
	{
		infoPesawat();
	} else if (pilihan == 2)
	{
		infoKereta();
	} else if (pilihan == 3)
	{
		infoBus();
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
	}

	return;
	
}

void infoPesawat () {
	FILE *handle;
	int i=0;
	char tmp_nama[32];
	struct User user;
	struct Tiket tiket;

	handle = fopen(file_database_user,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle)) {
			if (fread(&user, 1, sizeof(user), handle) == 0)
			{
				break;
			}
			strcpy(tmp_nama, user.nama);
		}
		fclose(handle);
	}


	handle = fopen(file_database_tiket_pesawat,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle)) {
			if (fread(&tiket, 1, sizeof(tiket), handle) == 0)
			{
				break;
			}

			if (strcmp(tiket.nama_pengguna, tmp_nama) == 0)
			{
				system("cls");
				cout << "===============================" << endl;
				cout << "Informasi Keberangkatan" << endl;
				cout << "===============================" << endl;
				cout << "Nama Maskapai\t\t: " << tiket.jadwal_buf[i].nama_maskapai << endl;
				cout << "Tgl Keberangkatan\t: " << tiket.jadwal_buf[i].tgl_keberangkatan << endl;
				cout << "Tujuan\t\t\t: " << tiket.jadwal_buf[i].tujuan << endl;
				cout << "Keberangkatan\t\t: " << tiket.jadwal_buf[i].keberangkatan << endl;
				cout << "Terminal\t\t: " << tiket.jadwal_buf[i].terminal << endl;
				cout << endl;
				
				break;
				
			}
		}
		// getchar();
		fclose(handle);
	}
}

void infoKereta () {
	FILE *handle;
	int i=0;
	char tmp_nama[32];
	struct User user;
	struct Tiket tiket;

	handle = fopen(file_database_user,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle)) {
			if (fread(&user, 1, sizeof(user), handle) == 0)
			{
				break;
			}
			strcpy(tmp_nama, user.nama);
		}
		fclose(handle);
	}


	handle = fopen(file_database_tiket_kereta,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle)) {
			if (fread(&tiket, 1, sizeof(tiket), handle) == 0)
			{
				break;
			}

			if (strcmp(tiket.nama_pengguna, tmp_nama) == 0)
			{
				system("cls");
				cout << "===============================" << endl;
				cout << "Informasi Keberangkatan" << endl;
				cout << "===============================" << endl;
				cout << "Nama Maskapai\t\t: " << tiket.jadwal_buf[i].nama_maskapai << endl;
				cout << "Tgl Keberangkatan\t: " << tiket.jadwal_buf[i].tgl_keberangkatan << endl;
				cout << "Tujuan\t\t\t: " << tiket.jadwal_buf[i].tujuan << endl;
				cout << "Keberangkatan\t\t: " << tiket.jadwal_buf[i].keberangkatan << endl;
				cout << "Terminal\t\t: " << tiket.jadwal_buf[i].terminal << endl;
				cout << endl;
				
				break;
				
			}
		}
		// getchar();
		fclose(handle);
	}
}

void infoBus () {
	FILE *handle;
	int i=0;
	char tmp_nama[32];
	struct User user;
	struct Tiket tiket;

	handle = fopen(file_database_user,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle)) {
			if (fread(&user, 1, sizeof(user), handle) == 0)
			{
				break;
			}
			strcpy(tmp_nama, user.nama);
		}
		fclose(handle);
	}


	handle = fopen(file_database_tiket_bus,"rb+");
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
		getchar();
	} else {
		while(!feof(handle)) {
			if (fread(&tiket, 1, sizeof(tiket), handle) == 0)
			{
				break;
			}

			if (strcmp(tiket.nama_pengguna, tmp_nama) == 0)
			{
				system("cls");
				cout << "===============================" << endl;
				cout << "Informasi Keberangkatan" << endl;
				cout << "===============================" << endl;
				cout << "Nama Maskapai\t\t: " << tiket.jadwal_buf[i].nama_maskapai << endl;
				cout << "Tgl Keberangkatan\t: " << tiket.jadwal_buf[i].tgl_keberangkatan << endl;
				cout << "Tujuan\t\t\t: " << tiket.jadwal_buf[i].tujuan << endl;
				cout << "Keberangkatan\t\t: " << tiket.jadwal_buf[i].keberangkatan << endl;
				cout << "Terminal\t\t: " << tiket.jadwal_buf[i].terminal << endl;
				cout << endl;
				
				break;
				
			}
		}
		// getchar();
		fclose(handle);
	}
}