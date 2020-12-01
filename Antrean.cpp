#include <iostream>
#include <limits>
#include <cstdio>
#include <string.h>
#include <iomanip>
#include "Create_jadwal.cpp"

using namespace std;

#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"


struct queue{
	int head;
	int tail;
	struct Jadwal jadwal_buf[5];
}antre;

void init();
int isFull();
int isEmpty();
void inQueuePesawat();
void inQueueKereta();
void inQueueBus();
void EnQueue();
void clear();
void print();
void AntreanPesawat();
void AntreanKereta();
void AntreanBus();

void Antrean() {
	int pilih;
	string jenis_kendaraan [] = {

		"Pesawat Terbang",
		"Kereta Api",
		"Bus",
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
	cin >> pilih;
	cin.ignore(1);

	if (pilih == 1)
	{
		AntreanPesawat();
	} else if (pilih == 2)
	{
		AntreanKereta();
	} else if (pilih == 3)
	{
		AntreanBus();
	} else {
		cout << "Pilihan tidak tersedia" << endl;
	}
	getchar();
	return;
}

void init() {
	antre.head = antre.tail = -1 ;
}

int isFull() {
	if (antre.tail == 4)
	{
		return 1;
	} else {
		return 0;
	}
}

int isEmpty() {
	if (antre.tail == -1)
	{
		antre.head = -1;
		return 1;
	} else {
		return 0;
	}
}

void inQueuePesawat() {
	FILE *handle;
	struct Jadwal jadwal;
	char tmp_kode[8];

	if (isFull() != 1){

		cout << "Masukkan kode : ";
		cin.getline(tmp_kode, 7);

		handle = fopen(file_database_pesawat, "rb+");
		if (handle == NULL)
		{
			cout << "Database Kosong" << endl;
		} else {
			while(!feof(handle)){
				if (fread(&jadwal, 1, sizeof(jadwal), handle) == 0){
					break;
				}

				if (strcmp(jadwal.kode, tmp_kode) == 0)
				{
					antre.head = 0;
					antre.tail++;
					antre.jadwal_buf[antre.tail] = jadwal;
					cout << "Data berhasil ditambahkan" << endl;
				}
			}
			
			getchar();
			fclose(handle);
		}

	} else {
		cout << "\nAntrean Penuh!\n";
		getchar();
	}
	
}

void inQueueKereta() {
	FILE *handle;
	struct Jadwal jadwal;
	char tmp_kode[8];

	if (isFull() != 1){

		cout << "Masukkan kode : ";
		cin.getline(tmp_kode, 7);

		handle = fopen(file_database_kereta, "rb+");
		if (handle == NULL)
		{
			cout << "Database Kosong" << endl;
		} else {
			while(!feof(handle)){
				if (fread(&jadwal, 1, sizeof(jadwal), handle) == 0){
					break;
				}

				if (strcmp(jadwal.kode, tmp_kode) == 0)
				{
					antre.head = 0;
					antre.tail++;
					antre.jadwal_buf[antre.tail] = jadwal;
					cout << "Data berhasil ditambahkan" << endl;
				}
			}
			getchar();
			fclose(handle);
		}

	} else {
		cout << "\nAntrean Penuh!\n";
		getchar();
	}
	
}

void inQueueBus() {
	FILE *handle;
	struct Jadwal jadwal;
	char tmp_kode[8];

	if (isFull() != 1){

		cout << "Masukkan kode : ";
		cin.getline(tmp_kode, 7);

		handle = fopen(file_database_bus, "rb+");
		if (handle == NULL)
		{
			cout << "Database Kosong" << endl;
		} else {
			while(!feof(handle)){
				if (fread(&jadwal, 1, sizeof(jadwal), handle) == 0){
					break;
				}

				if (strcmp(jadwal.kode, tmp_kode) == 0)
				{
					antre.head = 0;
					antre.tail++;
					antre.jadwal_buf[antre.tail] = jadwal;
					cout << "Data berhasil ditambahkan" << endl;
				}
			}
			
			getchar();
			fclose(handle);
		}

	} else {
		cout << "\nAntrean Penuh!\n";
		getchar();
	}
	
}

void deQueue(){
	if (isEmpty() != 1){

		for (int i = antre.head; i < antre.tail; i++)
		{
			antre.jadwal_buf[i] = antre.jadwal_buf[i+1];
			
		}
		antre.tail--;
		cout << "Data berhasil dihapus" << endl;
		getchar();
	} else {
		cout << "\nData Kosong\n";
		getchar();
	}
	
}

void clear() {
	antre.head = antre.tail = -1 ;
	cout << "\nSemua data dihapus" << endl;
	getchar();
}

void print() {
	string pagar = "====================";

	if (isEmpty() != 1){

		for (int i = 0; i < 4; ++i)
		{
			cout << pagar;
		}
		cout << endl;
		cout << left << setw(17) << "|Nama.";
		cout << left << setw(25) << "|Tgl. Keberangkatan";
		cout << left << setw(19) << "|Tujuan";
		cout << left << setw(18) << "|Keberangkatan";
		cout << left << setw(1) << "|";
		cout << endl;
		for (int i = 0; i < 4; ++i)
		{
			cout << pagar;
		}
		cout << endl;

		for (int i = 0; i <= antre.tail; i++){
			cout << left << setw(1) << "|" << setw(16) << antre.jadwal_buf[i].nama_maskapai;
			cout << left << setw(1) << "|" << setw(24) << antre.jadwal_buf[i].tgl_keberangkatan;
			cout << left << setw(1) << "|" << setw(18) << antre.jadwal_buf[i].tujuan;
			cout << left << setw(1) << "|" << setw(17) << antre.jadwal_buf[i].keberangkatan;
			cout << left << setw(1) << "|";
			cout << endl;
		}

		for (int i = 0; i < 4; ++i)
		{
			cout << pagar;
		}
		cout << endl;

	} else {
		cout << "\nData Kosong!\n";
	}
	getchar();
}

void AntreanPesawat() {

	char buffer[64] = {0};
	int pilih;
	init();

	do {

		system("cls");
		cout << "==================" << endl;
		cout << "Antrean Takeoff" << endl;
		cout << "==================" << endl;
		cout << "[1]. EnQueue" << endl;
		cout << "[2]. DeQueue" << endl;
		cout << "[3]. Show" << endl;
		cout << "[4]. Clear" << endl;
		cout << "[5]. Back" << endl;
		cout << "==================" << endl;
		cout << "Pilih menu: ";
		fgets(buffer, 64, stdin);

		pilih = atoi(buffer);

		switch(pilih){
			case 1 : inQueuePesawat();
						break;
			case 2 : deQueue();
						break;
			case 3 : print();
						break;
			case 4 : clear(); break; 
			default : break;
		}
	} while (pilih != 5);
	init(); 

	return ;
}

void AntreanKereta() {

	char buffer[64] = {0};
	int pilih;
	init();

	do {

		system("cls");
		cout << "==================" << endl;
		cout << "Antrean Takeoff" << endl;
		cout << "==================" << endl;
		cout << "[1]. EnQueue" << endl;
		cout << "[2]. DeQueue" << endl;
		cout << "[3]. Show" << endl;
		cout << "[4]. Clear" << endl;
		cout << "[5]. Back" << endl;
		cout << "==================" << endl;
		cout << "Pilih menu: ";
		fgets(buffer, 64, stdin);

		pilih = atoi(buffer);
		// cin >> pilih;
		// cin.ignore(1,'\n');

		switch(pilih){
			case 1 : inQueueKereta();
						break;
			case 2 : deQueue();
						break;
			case 3 : print();
						break;
			case 4 : clear(); break; 
			default : break;
		}
	} while (pilih != 5); 

	init(); 
	return ;
}

void AntreanBus() {

	char buffer[64] = {0};
	int pilih;
	init();

	do {

		system("cls");
		cout << "==================" << endl;
		cout << "Antrean Takeoff" << endl;
		cout << "==================" << endl;
		cout << "[1]. EnQueue" << endl;
		cout << "[2]. DeQueue" << endl;
		cout << "[3]. Show" << endl;
		cout << "[4]. Clear" << endl;
		cout << "[5]. Back" << endl;
		cout << "==================" << endl;
		cout << "Pilih menu: ";
		fgets(buffer, 64, stdin);

		pilih = atoi(buffer);

		switch(pilih){
			case 1 : inQueueBus();
						break;
			case 2 : deQueue();
						break;
			case 3 : print();
						break;
			case 4 : clear(); break; 
			default : break;
		}
	} while (pilih != 5); 

	init(); 
	return ;
}