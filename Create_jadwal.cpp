#ifndef JADWAL
#define JADWAL
#include <iostream>
#include <cstdio>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <cstring>


using namespace std;

#define file_database_pesawat "database_jadwal_pesawat.txt"
#define file_database_kereta "database_jadwal_kereta.txt"
#define file_database_bus "database_jadwal_bus.txt"

struct Jadwal{
	time_t rawtime;
	bool deleted = false;
	char kode[8];
	char nama_maskapai[32];
	char tgl_keberangkatan[64];
	char tujuan[32];
	char keberangkatan[32];
	char kedatangan[32];
	char terminal[16];
	char status[8];
};

static const char *str_hari[] = {
  "Minggu", "Senin", "Selasa",
  "Rabu", "Kamis", "Jum'at", "Sabtu"
};
static const char *str_bulan[] = {
  "Januari", "Februari", "Maret",
  "April", "Mei", "Juni", "Juli",
  "Agustus", "September", "Oktober",
  "November", "Desember"
};

char *strtolower(char *str, unsigned int len);
char *convert_human_readable(struct tm *timeinfo);
bool parse_tanggal(char *buffer, int *tanggal, int *bulan, int *tahun);

void Create(){

	FILE *handle;

	struct tm *timeinfo;
	int tanggal, bulan, tahun;
	char buffer[1024], *tgl, *cvt;

	int pilih,latest_code;
	char x, tmp_buffer[64] = {0};
	Jadwal jadwal,tmp;

	memset(&tmp, 0, sizeof(tmp));
	memset(&jadwal, 0, sizeof(jadwal));

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
	fgets(tmp_buffer, 32, stdin);
	pilih = atoi(tmp_buffer);
	// cin.ignore();

	if (pilih == 1)
	{
		// Pesawat
		cout << "Create Jadwal Pesawat" << endl;
		cout << "Nama Maskapai\t\t: ";
		cin.getline(jadwal.nama_maskapai,31);
	input_tanggal:
		cout << "Tanggal Keberangkatan\t: ";
		fgets(buffer, 1024, stdin);
		cout << "Tujuan\t\t\t: ";
		cin.getline(jadwal.tujuan,31);
		cout << "Keberangkatan\t\t: ";
		cin.getline(jadwal.keberangkatan,31);
		cout << "Kedatangan\t\t: ";
		cin.getline(jadwal.kedatangan,31);
		cout << "Bandara\t\t\t: ";
		cin.getline(jadwal.terminal,15);
		cout << "Status\t\t\t: ";
		cin.getline(jadwal.status,7);
		cout << endl;

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
		// printf("Tanggal yang Anda masukkan adalah: %s\n", cvt);
		// printf("Bentuk epoch: %ld\n", rawtime);
		// free(cvt);
		// goto input_tanggal; 
		strcpy(jadwal.tgl_keberangkatan,cvt);
		free(cvt);

		cout << "Nama Maskapai\t\t: " << jadwal.nama_maskapai << endl;
		cout << "Tanggal Keberangkatan\t: " << jadwal.tgl_keberangkatan << endl;
		cout << "Tujuan\t\t\t: " << jadwal.tujuan << endl;
		cout << "Keberangkatan\t\t: " << jadwal.keberangkatan << endl;
		cout << "Kedatangan\t\t: " << jadwal.kedatangan << endl;
		cout << "Bandara\t\t\t: " << jadwal.terminal << endl;
		cout << "Status\t\t\t: " << jadwal.status << endl;
		cout << "\nSimpan jadwal baru ? [y/n] : ";
		cin >> x;
		cin.ignore();

		if (x == 'Y' || x == 'y'){
			handle = fopen(file_database_pesawat,"ab+");
			if (handle == NULL){
				strcpy(jadwal.kode,"PS01");
			} else {
				while(!feof(handle)){
					fread(&tmp, sizeof(struct Jadwal), 1, handle);
				}
				latest_code = atoi(&(tmp.kode[2])) + 1;
				sprintf(jadwal.kode, "PS%02d", latest_code);
				fwrite(&jadwal, sizeof(jadwal), 1, handle); 
				fclose(handle);
			}

			cout << "Data Berhasil Disimpan" << endl;
			getchar();
			
		} else {
			cout << "Data Gagal Disimpan" << endl;
			getchar();
		}

	} else if (pilih == 2){
		// Kereta
		cout << "Create Jadwal Kereta" << endl;
		cout << "Nama Maskapai\t\t: ";
		cin.getline(jadwal.nama_maskapai,31);
		
		input_tanggal1:
		cout << "Tanggal Keberangkatan\t: ";
		fgets(buffer, 1024, stdin);
		cout << "Tujuan\t\t\t: ";
		cin.getline(jadwal.tujuan,31);
		cout << "Keberangkatan\t\t: ";
		cin.getline(jadwal.keberangkatan,31);
		cout << "Kedatangan\t\t: ";
		cin.getline(jadwal.kedatangan,31);
		cout << "Stasiun\t\t\t: ";
		cin.getline(jadwal.terminal,15);
		cout << "Status\t\t\t: ";
		cin.getline(jadwal.status,7);
		cout << endl;

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
		// printf("Tanggal yang Anda masukkan adalah: %s\n", cvt);
		// printf("Bentuk epoch: %ld\n", rawtime);
		// free(cvt);
		// goto input_tanggal; 
		strcpy(jadwal.tgl_keberangkatan,cvt);
		free(cvt);

		cout << "Nama Maskapai\t\t: " << jadwal.nama_maskapai << endl;
		cout << "Tanggal Keberangkatan\t: " << jadwal.tgl_keberangkatan << endl;
		cout << "Tujuan\t\t\t: " << jadwal.tujuan << endl;
		cout << "Keberangkatan\t\t: " << jadwal.keberangkatan << endl;
		cout << "Kedatangan\t\t: " << jadwal.kedatangan << endl;
		cout << "Stasiun\t\t\t: " << jadwal.terminal << endl;
		cout << "Status\t\t\t: " << jadwal.status << endl;
		cout << "\nSimpan jadwal baru ? [y/n] : ";
		cin >> x;
		cin.ignore();

		if (x == 'Y' || x == 'y'){
			handle = fopen(file_database_kereta,"ab+");
			if (handle == NULL){
				strcpy(jadwal.kode,"KA01");
			} else {
				while(!feof(handle)){
					fread(&tmp, sizeof(struct Jadwal), 1, handle);
				}
				latest_code = atoi(&(tmp.kode[2])) + 1;
				sprintf(jadwal.kode, "KA%02d", latest_code);
				fwrite(&jadwal, sizeof(jadwal), 1, handle); 
				fclose(handle);
			}

			cout << "Data Berhasil Disimpan" << endl;
			getchar();
			
		} else {
			cout << "Data Gagal Disimpan" << endl;
			getchar();
		}

	} else if (pilih == 3){
		// Bus
		cout << "Create Jadwal Terminal" << endl;
		cout << "Nama Maskapai\t\t: ";
		cin.getline(jadwal.nama_maskapai,31);
		
		input_tanggal2:
		cout << "Tanggal Keberangkatan\t: ";
		fgets(buffer, 1024, stdin);
		cout << "Tujuan\t\t\t: ";
		cin.getline(jadwal.tujuan,31);
		cout << "Keberangkatan\t\t: ";
		cin.getline(jadwal.keberangkatan,31);
		cout << "Kedatangan\t\t: ";
		cin.getline(jadwal.kedatangan,31);
		cout << "Terminal\t\t: ";
		cin.getline(jadwal.terminal,15);
		cout << "Status\t\t\t: ";
		cin.getline(jadwal.status,7);
		cout << endl;

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
		// printf("Tanggal yang Anda masukkan adalah: %s\n", cvt);
		// printf("Bentuk epoch: %ld\n", rawtime);
		// free(cvt);
		// goto input_tanggal; 
		strcpy(jadwal.tgl_keberangkatan,cvt);
		free(cvt);

		cout << "Nama Maskapai\t\t: " << jadwal.nama_maskapai << endl;
		cout << "Tanggal Keberangkatan\t: " << jadwal.tgl_keberangkatan << endl;
		cout << "Tujuan\t\t\t: " << jadwal.tujuan << endl;
		cout << "Keberangkatan\t\t: " << jadwal.keberangkatan << endl;
		cout << "Kedatangan\t\t: " << jadwal.kedatangan << endl;
		cout << "Terminal\t\t: " << jadwal.terminal << endl;
		cout << "Status\t\t\t: " << jadwal.status << endl;
		cout << "\nSimpan jadwal baru ? [y/n] : ";
		cin >> x;
		cin.ignore();

		if (x == 'Y' || x == 'y'){
			handle = fopen(file_database_bus,"ab+");
			if (handle == NULL){
				strcpy(jadwal.kode,"BS01");
			} else {
				while(!feof(handle)){
					fread(&tmp, sizeof(struct Jadwal), 1, handle);
				}
				latest_code = atoi(&(tmp.kode[2])) + 1;
				sprintf(jadwal.kode, "BS%02d", latest_code);
				fwrite(&jadwal, sizeof(jadwal), 1, handle); 
				fclose(handle);
			}

			cout << "Data Berhasil Disimpan" << endl;
			getchar();
			
		} else {
			cout << "Data Gagal Disimpan" << endl;
			getchar();
		}
	} else {
		cout << "Pilihan tidak tersedia" << endl;
		getchar();
		goto Menu_jadwal;
	}
	return ;
}



char *convert_human_readable(struct tm *timeinfo)
{
  char *heap = (char *)malloc(64);
  sprintf(heap, "%s, %02d %s %d",
    (char *)str_hari[timeinfo->tm_wday],
    timeinfo->tm_mday,
    (char *)str_bulan[timeinfo->tm_mon],
    timeinfo->tm_year + 1900
  );
  return heap;
}



bool parse_tanggal(char *buffer, int *tanggal, int *bulan, int *tahun)
{
  bool ret;
  char *p1, *p2;
  unsigned int i, len = strlen(buffer);

  ret  = (len < (sizeof("x xxxx xxxx") - 1));
  ret |= (buffer[0] < '0' || buffer[0] > '9');
  ret |= (buffer[1] < '0' || buffer[1] > '9') && (buffer[1] != ' ');

  if (ret) {
    ret = false;
    goto rt;
  }

  if (buffer[1] == ' ') {
    buffer[1] = '\0';
    p1 = &(buffer[2]);
  } else if (buffer[2] == ' ') {
    buffer[2] = '\0';
    p1 = &(buffer[3]);
  } else {
    ret = false;
    goto rt;
  }

  *tanggal = atoi(buffer);
  if (*tanggal < 1 || *tanggal > 31) {
    ret = false;
    goto rt;
  }

  i = 0;
  p2 = p1;
  while (*p1++ != ' ') {
    if (i++ > 9) {
      ret = false;
      goto rt;
    }
  }
  *(p1 - 1) = '\0';

  strtolower(p2, strlen(p2));
  if (p2[0] >= 'a' && p2[0] <= 'z') {
    p2[0] -= 32;
  } else {
    ret = false;
    goto rt;
  }

  ret = false;
  for (i = 0; i < (sizeof(str_bulan) / sizeof(str_bulan[0])); i++) {
    if (!strcmp(p2, str_bulan[i])) {
      *bulan = (int)i;
      ret = true;
      break;
    }
  }
  if (!ret) goto rt;

  ret  = (p1[0] < '0' || p1[0] > '9');
  ret |= (p1[1] < '0' || p1[1] > '9');
  ret |= (p1[2] < '0' || p1[2] > '9');
  ret |= (p1[3] < '0' || p1[3] > '9');

  if (ret) {
    ret = false;
    goto rt;
  }
  p1[4] = '\0';
  *tahun = atoi(p1) - 1900;
  ret = true;
rt:
  return ret;
}

char *strtolower(char *str, unsigned int len)
{
  for (unsigned int i = 0; i < len; i++) {
    if ((str[i] >= 'A') && (str[i] <= 'Z')) {
      str[i] += 32;
    }
  }
  return str;
}

#endif