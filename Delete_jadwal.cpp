#include <iostream>
#include <cstdio>
#include <string.h>
#include "Create_jadwal.cpp"


using namespace std;

#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"


void Delete() {

	FILE *handle;
	int pilih,i=1,tmp=0;
	char tmp_kode[8], tmp_buffer[64] = {0};
	unsigned int nread;
	Jadwal jadwal;

	memset(tmp_kode, 0 , sizeof(tmp_kode));
	memset(&jadwal, 0, sizeof(jadwal));
	string jenis_kendaraan [] = {

		"Pesawat Terbang",
		"Kereta Api",
		"Bus",
		"Back",
	};

	Menu:
	system("cls");
	cout << "================================" << endl;
	cout << "Delete Jadwal Keberangkatan" << endl;
	cout << "================================" << endl;
	for (int i = 0; i < (sizeof(jenis_kendaraan)/sizeof(jenis_kendaraan[0])); ++i)
	{
		cout << i+1 << ". " << jenis_kendaraan[i] << endl;
	}
	cout << "================================" << endl;
	cout << "\nPilih Kendaraan : ";
	fgets(tmp_buffer, 32, stdin);
	pilih = atoi(tmp_buffer);

	if (pilih == 1){
		// Pesawat
		handle = fopen(file_database_pesawat,"rb+");
		if (handle == NULL)
		{
			cout << "Database Kosong";
		} else {
			i=0;
			cout << "\nMasukkan kode penerbangan : ";
			cin.getline(tmp_kode,8);
			

			while(!feof(handle)){
				nread = fread (&jadwal, 1, sizeof(jadwal), handle);
								
				if (nread == 0){
					break;
				}
				tmp = tmp + nread;

				if (!strcmp(jadwal.kode, tmp_kode)){
					i++;
					
					jadwal.deleted = true;
					fseek(handle, tmp-(sizeof(jadwal)), SEEK_SET);
					fwrite(&jadwal, 1, sizeof(jadwal), handle);
					break;
					
				}
			}
			
			if (i == 0){
				cout << "Kode tidak ditemukan" << endl;
			}
			cout << "Data berhasil dihapus" << endl;
			getchar();
			fclose(handle);
			
		}
			

	} else if (pilih == 2){
		// Kereta
		handle = fopen(file_database_kereta,"rb+");
		if (handle == NULL)
		{
			cout << "Database Kosong";
		} else {
			i=0;
			cout << "\nMasukkan kode keberangkatan : ";
			cin.getline(tmp_kode,8);
			

			while(!feof(handle)){
				nread = fread (&jadwal, 1, sizeof(jadwal), handle);
								
				if (nread == 0){
					break;
				}
				tmp = tmp + nread;

				if (!strcmp(jadwal.kode, tmp_kode)){
					i++;
					
					jadwal.deleted = true;
					fseek(handle, tmp-(sizeof(jadwal)), SEEK_SET);
					fwrite(&jadwal, 1, sizeof(jadwal), handle);
					break;
					
				}
			}
			
			if (i == 0){
				cout << "Kode tidak ditemukan" << endl;
			}
			cout << "Data berhasil dihapus" << endl;
			getchar();
			fclose(handle);
			
		}

	} else if (pilih == 3){
		// Bus
		handle = fopen(file_database_bus,"rb+");
		if (handle == NULL)
		{
			cout << "Database Kosong";
		} else {
			i=0;
			cout << "\nMasukkan kode keberangkatan : ";
			cin.getline(tmp_kode,8);
			

			while(!feof(handle)){
				nread = fread (&jadwal, 1, sizeof(jadwal), handle);
								
				if (nread == 0){
					break;
				}
				tmp = tmp + nread;

				if (!strcmp(jadwal.kode, tmp_kode)){
					i++;
					
					jadwal.deleted = true;
					fseek(handle, tmp-(sizeof(jadwal)), SEEK_SET);
					fwrite(&jadwal, 1, sizeof(jadwal), handle);
					break;
					
				}
			}
			
			if (i == 0){
				cout << "Kode tidak ditemukan" << endl;
			}
			cout << "Data berhasil dihapus" << endl;
			getchar();
			fclose(handle);
			
		}

	} else if (pilih == 4){
		return;
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		system("pause");
		goto Menu;
	}



}