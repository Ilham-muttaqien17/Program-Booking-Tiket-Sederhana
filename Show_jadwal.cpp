#ifndef SHOW
#define SHOW 
#include <iostream>
#include <cstdio>
#include <iomanip>
#include "Create_jadwal.cpp"

using namespace std;

#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"

void jadwalPesawat();
void jadwalKereta();
void jadwalBus();


void Show(){

	FILE *handle;
	int pilih,i=1,nomor=0;
	string pagar = "==================";
	char tmp_buffer[64] = {0};
	struct Jadwal jadwal;
		
	string jenis_kendaraan [] = {

		"Pesawat Terbang",
		"Kereta Api",
		"Bus",
		"Back",
	};

	Menu_jadwal:
	system("cls");
	cout << "========================" << endl;
	cout << "Jadwal Keberangkatan" << endl;
	cout << "========================" << endl;
	for (int i = 0; i < (sizeof(jenis_kendaraan)/sizeof(jenis_kendaraan[0])); ++i)
	{
		cout << i+1 << ". " << jenis_kendaraan[i] << endl;
	}
	cout << "========================" << endl;
	cout << "\nPilih Jenis Kendaraan : ";
	fgets(tmp_buffer, 32, stdin);
	pilih = atoi(tmp_buffer);
	cout << endl;

	while(pilih != 4) {
		switch(pilih){
			case 1: jadwalPesawat(); getchar(); break;

			case 2: jadwalKereta(); getchar(); break;

			case 3: jadwalBus(); getchar(); break;

			default:
				cout << "Pilihan tidak tersedia" << endl;
				getchar();
				// goto Menu_jadwal;
				break;
		}
		goto Menu_jadwal;
	}

	return;
	
}

void jadwalPesawat() {
	FILE *handle;
	int pilih,i=1,nomor=0;
	string pagar = "===================";
	struct Jadwal jadwal;

	cout << "Jadwal Keberangkatan Pesawat" << endl;
	handle = fopen(file_database_pesawat,"rb");
	if (handle == NULL){
		cout << "Database Kosong";
		getchar();
	} else {
		cout << endl;
		for (int i = 0; i < 8; ++i)
		{
			cout << pagar;
		}
		cout << endl;
		cout << left << setw(6) << "|No.";
		cout << left << setw(17) << "|Nama.";
		cout << left << setw(9) << "|Kode";
		cout << left << setw(25) << "|Tgl. Penerbangan";
		cout << left << setw(19) << "|Tujuan";
		cout << left << setw(23) << "|Keberangkatan";
		cout << left << setw(19) << "|Kedatangan";
		cout << left << setw(20) << "|Bandara";
		cout << left << setw(13) << "|Status";
		cout << left << setw(1) << "|";
		cout << endl;
		for (int i = 0; i < 8; ++i)
		{
			cout << pagar;
		}
		cout << endl;
		while(!feof(handle)){
			if (fread(&jadwal, 1, sizeof(jadwal), handle) == 0) break;
			if (jadwal.deleted) continue;
			cout << left << setw(1) << "|" << setw(5) << nomor + 1;
			cout << left << setw(1) << "|" << setw(16) << jadwal.nama_maskapai;
			cout << left << setw(1) << "|" << setw(8) << jadwal.kode;
			cout << left << setw(1) << "|" << setw(24) << jadwal.tgl_keberangkatan;
			cout << left << setw(1) << "|" << setw(18) << jadwal.tujuan;
			cout << left << setw(1) << "|" << setw(22) << jadwal.keberangkatan;
			cout << left << setw(1) << "|" << setw(18) << jadwal.kedatangan;
			cout << left << setw(1) << "|" << setw(19) << jadwal.terminal;
			cout << left << setw(1) << "|" << setw(12) << jadwal.status;
			cout << left << setw(1) << "|";
			cout << endl;
			nomor++;
			i++;
		}
		for (int i = 0; i < 8; ++i){
			cout << pagar;
		}
		cout << endl;
		nomor = 0;
		fclose(handle);
	}
}

void jadwalKereta() {
	FILE *handle;
	int pilih,i=1,nomor=0;
	string pagar = "===================";
	struct Jadwal jadwal;

	cout << "Jadwal Keberangkatan Kereta Api" << endl;
	handle = fopen(file_database_kereta,"rb");
	if (handle == NULL){
		cout << "Database Kosong";
		getchar();
	} else {
		cout << endl;
		for (int i = 0; i < 8; ++i)
		{
			cout << pagar;
		}
		cout << endl;
		cout << left << setw(6) << "|No.";
		cout << left << setw(17) << "|Nama.";
		cout << left << setw(9) << "|Kode";
		cout << left << setw(25) << "|Tgl. Keberangkatan";
		cout << left << setw(19) << "|Tujuan";
		cout << left << setw(23) << "|Keberangkatan";
		cout << left << setw(19) << "|Kedatangan";
		cout << left << setw(20) << "|Stasiun";
		cout << left << setw(13) << "|Status";
		cout << left << setw(1) << "|";
		cout << endl;
		for (int i = 0; i < 8; ++i)
		{
			cout << pagar;
		}
		cout << endl;

		while(!feof(handle)){
			if (fread(&jadwal, 1, sizeof(jadwal), handle) == 0) break;
			if (jadwal.deleted) continue;
			cout << left << setw(1) << "|" << setw(5) << nomor + 1;
			cout << left << setw(1) << "|" << setw(16) << jadwal.nama_maskapai;
			cout << left << setw(1) << "|" << setw(8) << jadwal.kode;
			cout << left << setw(1) << "|" << setw(24) << jadwal.tgl_keberangkatan;
			cout << left << setw(1) << "|" << setw(18) << jadwal.tujuan;
			cout << left << setw(1) << "|" << setw(22) << jadwal.keberangkatan;
			cout << left << setw(1) << "|" << setw(18) << jadwal.kedatangan;
			cout << left << setw(1) << "|" << setw(19) << jadwal.terminal;
			cout << left << setw(1) << "|" << setw(12) << jadwal.status;
			cout << left << setw(1) << "|";
			cout << endl;
			nomor++;
			i++;
		}
		for (int i = 0; i < 8; ++i)
		{
			cout << pagar;
		}
		cout << endl;
		nomor = 0;
		fclose(handle);
	}
}

void jadwalBus() {
	FILE *handle;
	int pilih,i=1,nomor=0;
	string pagar = "===================";
	struct Jadwal jadwal;

	cout << "Jadwal Keberangkatan Bus" << endl;
	handle = fopen(file_database_bus,"rb");
	if (handle == NULL){
		cout << "Database Kosong";
		getchar();
	} else {
		cout << endl;
		for (int i = 0; i < 8; ++i)
		{
			cout << pagar;
		}
		cout << endl;
		cout << left << setw(6) << "|No.";
		cout << left << setw(17) << "|Nama.";
		cout << left << setw(9) << "|Kode";
		cout << left << setw(25) << "|Tgl. Keberangkatan";
		cout << left << setw(19) << "|Tujuan";
		cout << left << setw(23) << "|Keberangkatan";
		cout << left << setw(19) << "|Kedatangan";
		cout << left << setw(20) << "|Terminal";
		cout << left << setw(13) << "|Status";
		cout << left << setw(1) << "|";
		cout << endl;
		for (int i = 0; i < 8; ++i)
		{
			cout << pagar;
		}
		cout << endl;

		while(!feof(handle)){
			if (fread(&jadwal, 1, sizeof(jadwal), handle) == 0) break;
			if (jadwal.deleted) continue;
			cout << left << setw(1) << "|" << setw(5) << nomor + 1;
			cout << left << setw(1) << "|" << setw(16) << jadwal.nama_maskapai;
			cout << left << setw(1) << "|" << setw(8) << jadwal.kode;
			cout << left << setw(1) << "|" << setw(24) << jadwal.tgl_keberangkatan;
			cout << left << setw(1) << "|" << setw(18) << jadwal.tujuan;
			cout << left << setw(1) << "|" << setw(22) << jadwal.keberangkatan;
			cout << left << setw(1) << "|" << setw(18) << jadwal.kedatangan;
			cout << left << setw(1) << "|" << setw(19) << jadwal.terminal;
			cout << left << setw(1) << "|" << setw(12) << jadwal.status;
			cout << left << setw(1) << "|";
			cout << endl;
			nomor++;
			i++;
		}
		for (int i = 0; i < 8; ++i)
		{
			cout << pagar;
		}
		cout << endl;
		nomor = 0;
		fclose(handle);
	}	
}

#endif