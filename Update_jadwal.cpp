#include <iostream>
#include <cstdio>
#include <string.h>
#include "Create_jadwal.cpp"

using namespace std;

#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"


void Update() {

	FILE *handle;
	int pilih,i=1,tmp=0;
	char tmp_kode[8], tmp_buffer[64] = {0};
	unsigned int nread;
	Jadwal jadwal;

	struct tm *timeinfo;
	int tanggal, bulan, tahun;
	char buffer[1024], *tgl, *cvt;

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
	cout << "Edit Jadwal Keberangkatan" << endl;
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

			cout << "Masukkan kode penerbangan : ";
			cin.getline(tmp_kode,8);
			i=0;

			while(!feof(handle)){
				nread = fread (&jadwal, 1, sizeof(jadwal), handle);
								
				if (nread == 0){
					break;
				}
				tmp = tmp + nread;

				if (!strcmp(jadwal.kode, tmp_kode) && !jadwal.deleted){
					i++;
					cout << "New Nama Maskapai\t\t: ";
					cin.getline(jadwal.nama_maskapai,31);
				input_tanggal:
					cout << "New Tanggal Keberangkatan\t: ";
					fgets(buffer, 1024, stdin);
					// cin.getline(jadwal.tgl_keberangkatan,31);
					cout << "New Tujuan\t\t\t: ";
					cin.getline(jadwal.tujuan,31);
					cout << "New Keberangkatan\t\t: ";
					cin.getline(jadwal.keberangkatan,31);
					cout << "New Kedatangan\t\t\t: ";
					cin.getline(jadwal.kedatangan,31);
					cout << "New Bandara\t\t\t: ";
					cin.getline(jadwal.terminal,15);
					cout << "New Status\t\t\t: ";
					cin.getline(jadwal.status,7);

					if (!parse_tanggal(buffer, &tanggal, &bulan, &tahun)) {
					printf("Format tanggal salah!\n");
					printf("Mohon masukkan format tanggal yang tepat!\n");
					printf("Contoh format tanggal yang tepat: 10 Juni 2020\n");
					goto input_tanggal;
					}

					time(&jadwal.rawtime);
					timeinfo = localtime(&jadwal.rawtime);
					timeinfo->tm_year = tahun;
					timeinfo->tm_mon  = bulan;
					timeinfo->tm_mday = tanggal;
					jadwal.rawtime = mktime(timeinfo);

					cvt = convert_human_readable(timeinfo);
					strcpy(jadwal.tgl_keberangkatan,cvt);
					free(cvt);

					fseek(handle, tmp-(sizeof(jadwal)), SEEK_SET);
					fwrite(&jadwal, 1, sizeof(jadwal), handle);
					break;
					
				}
			}
			
			if (i == 0){
				cout << "Kode tidak ditemukan" << endl;
			}
			cout << "Data berhasil diedit" << endl;
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

			cout << "Masukkan kode keberangkatan : ";
			cin.getline(tmp_kode,8);
			i=0;

			while(!feof(handle)){
				nread = fread (&jadwal, 1, sizeof(jadwal), handle);
								
				if (nread == 0){
					break;
				}
				tmp = tmp + nread;

				if (!strcmp(jadwal.kode, tmp_kode) && !jadwal.deleted){
					i++;
					cout << "New Nama Maskapai\t\t: ";
					cin.getline(jadwal.nama_maskapai,31);
				input_tanggal1:
					cout << "New Tanggal Keberangkatan\t: ";
					fgets(buffer, 1024, stdin);
					// cin.getline(jadwal.tgl_keberangkatan,15);
					cout << "New Tujuan\t\t\t: ";
					cin.getline(jadwal.tujuan,31);
					cout << "New Keberangkatan\t\t: ";
					cin.getline(jadwal.keberangkatan,31);
					cout << "New Kedatangan\t\t\t: ";
					cin.getline(jadwal.kedatangan,31);
					cout << "New Stasiun\t\t\t: ";
					cin.getline(jadwal.terminal,15);
					cout << "New Status\t\t\t: ";
					cin.getline(jadwal.status,7);

					if (!parse_tanggal(buffer, &tanggal, &bulan, &tahun)) {
					printf("Format tanggal salah!\n");
					printf("Mohon masukkan format tanggal yang tepat!\n");
					printf("Contoh format tanggal yang tepat: 10 Juni 2020\n");
					goto input_tanggal1;
					}

					time(&jadwal.rawtime);
					timeinfo = localtime(&jadwal.rawtime);
					timeinfo->tm_year = tahun;
					timeinfo->tm_mon  = bulan;
					timeinfo->tm_mday = tanggal;
					jadwal.rawtime = mktime(timeinfo);

					cvt = convert_human_readable(timeinfo);
					strcpy(jadwal.tgl_keberangkatan,cvt);
					free(cvt);

					fseek(handle, tmp-(sizeof(jadwal)), SEEK_SET);
					fwrite(&jadwal, 1, sizeof(jadwal), handle);
					break;
					
				}
			}
			
			if (i == 0){
				cout << "Kode tidak ditemukan" << endl;
			}
			cout << "Data berhasil diedit" << endl;
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

			cout << "Masukkan kode keberangkatan : ";
			cin.getline(tmp_kode,8);
			i=0;

			while(!feof(handle)){
				nread = fread (&jadwal, 1, sizeof(jadwal), handle);
								
				if (nread == 0){
					break;
				}
				tmp = tmp + nread;

				if (!strcmp(jadwal.kode, tmp_kode) && !jadwal.deleted){
					i++;
					cout << "New Nama Maskapai\t\t: ";
					cin.getline(jadwal.nama_maskapai,31);
				input_tanggal2:
					cout << "New Tanggal Keberangkatan\t: ";
					fgets(buffer, 1024, stdin);
					// cin.getline(jadwal.tgl_keberangkatan,15);
					cout << "New Tujuan\t\t\t: ";
					cin.getline(jadwal.tujuan,31);
					cout << "New Keberangkatan\t\t: ";
					cin.getline(jadwal.keberangkatan,31);
					cout << "New Kedatangan\t\t\t: ";
					cin.getline(jadwal.kedatangan,31);
					cout << "New Terminal\t\t\t: ";
					cin.getline(jadwal.terminal,15);
					cout << "New Status\t\t\t: ";
					cin.getline(jadwal.status,7);

					if (!parse_tanggal(buffer, &tanggal, &bulan, &tahun)) {
					printf("Format tanggal salah!\n");
					printf("Mohon masukkan format tanggal yang tepat!\n");
					printf("Contoh format tanggal yang tepat: 10 Juni 2020\n");
					goto input_tanggal2;
					}

					time(&jadwal.rawtime);
					timeinfo = localtime(&jadwal.rawtime);
					timeinfo->tm_year = tahun;
					timeinfo->tm_mon  = bulan;
					timeinfo->tm_mday = tanggal;
					jadwal.rawtime = mktime(timeinfo);

					cvt = convert_human_readable(timeinfo);
					strcpy(jadwal.tgl_keberangkatan,cvt);
					free(cvt);

					fseek(handle, tmp-(sizeof(jadwal)), SEEK_SET);
					fwrite(&jadwal, 1, sizeof(jadwal), handle);
					break;
					
				}
			}
			
			if (i == 0){
				cout << "Kode tidak ditemukan" << endl;
			}
			cout << "Data berhasil diedit" << endl;
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