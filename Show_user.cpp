#include <iostream>
#include <cstdio>
#include <string.h>
#include <iomanip>
#include "Create_jadwal.cpp"
#include "Registrasi_akun.cpp"

using namespace std;

#define file_database_user "database_user.txt"



void showUser() {

	FILE *handle;
	int len, nomor=0;
	struct User user,buf;

	system("cls");
	cout << "Daftar User yang berhasil Sign Up" << endl;

	handle = fopen(file_database_user,"rb+");
	fseek(handle, 0, SEEK_END);  
	len = ftell(handle); 
	fseek(handle, 0, SEEK_SET); 

	int ukuran_data = len / sizeof(user);

	struct User tmp[ukuran_data];
	if (handle == NULL)
	{
		cout << "Database Kosong" << endl;
	} else {
		int i = 0;
		while(!feof(handle)){
			if(fread(&(tmp[i]), 1, sizeof(tmp[i]), handle) == 0 ) break;
			i++;
			
		}

		fclose(handle);
		
		for (int i = 1; i < ukuran_data; ++i)
		{
			for (int j = 0; j < ukuran_data - i; ++j)
			{
				if (strcmp(tmp[j].nama, tmp[j+1].nama) > 0)
				{
					buf = tmp[j];
					tmp[j] = tmp[j+1];
					tmp[j+1] = buf;
				}
			}
		}

		cout << endl;

		cout << "============================" << endl;
		cout << "|No   |Nama Pengguna       |" << endl;
		cout << "============================" << endl;
		for (int i = 0; i < ukuran_data; ++i)
		{
			cout << left << setw(1) << "|" << setw(5) << nomor + 1; 
			cout << left << setw(1) << "|" << setw(20) << tmp[i].nama;
			cout << left << setw(1) << "|";
			cout << endl;
			nomor++;
		}
		cout << "============================" << endl;

		getchar();
		
	}
}