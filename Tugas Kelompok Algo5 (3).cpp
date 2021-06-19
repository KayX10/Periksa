#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main();
void bubblesort();

struct InputData{
	string satuan, pakai, kode, guna, swap;
};
InputData id[20];
int jumlah = 0;
string namafile;

void swap(string *y, string *x){
	string temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

void copy(){
	string a, b, c, d;

	ifstream x(namafile.c_str());
	if (x.is_open()){
		jumlah = 0;
		x >> a >> b >> c >> d;

		while (!x.eof()){
			id[jumlah].kode  = a;
			id[jumlah].satuan = b;
			id[jumlah].pakai = c;
			id[jumlah].guna = d;
			jumlah++;
			x >> a >> b >> c >> d;
		}
		x.close();
	}
}

void paste(){
	ofstream f;
	f.open (namafile.c_str());
	for (int i = 0; i < jumlah; i++){
		f << id[i].kode << "\n" << id[i].satuan << "\n" << id[i].pakai << "\n" << id[i].guna << "\n";
 	}
 	f.close();
}

void table(){
	cout << "==============================================================================" << endl;
	cout << " Kode Narkotik\t| Satuan\t| Pemakaian Untuk\t| Penggunaan Jumlah" << endl;
	cout << "==============================================================================" << endl;
	for (int i=0; i<jumlah; i++){
		cout << " \t" << id[i].kode << "\t| " << id[i].satuan << "    \t| " << id[i].pakai << "\t\t\t| " << id[i].guna << endl;
	}
}

void gagal(){
	ifstream x(namafile.c_str());
	if (x.is_open()){
		x.close();
	}
	else {
		cout << "  File Gagal Dibuka!" << endl;
		system("pause");
		system("cls");
		main();
	}
}

// Input Program
void input(){
	int i, banyak;

	ofstream f;
	cout << "==================================" << endl;
	cout << "  INPUT DATA PEMAKAIAN NARKOTIKA  " << endl;
	cout << "==================================" << endl;
	cout << "  Masukkan nama file           = ";
	cin >> namafile;
	cout << endl;

	cout << " Banyaknya Data = ";
	cin >> banyak;

	f.open (namafile.c_str());
	for (i = 0; i < banyak; i++){
		cout << "\tKode Narkotik        = ";
		cin >> id[i].kode;
		cout << "\tSatuan               = ";
		cin >> id[i].satuan;
		cout << "\tPemakaian Untuk      = ";
		cin >> id[i].pakai;
		cout << "\tPenggunaan Jumlah    = ";
		cin >> id[i].guna;
		cout << endl;
		f << id[i].kode << "\n" << id[i].satuan << "\n" << id[i].pakai << "\n" << id[i].guna << "\n";
 	}
	f.close();
}

// Output Program
void output(){
	cout << "===================================" << endl;
	cout << "  OUTPUT DATA PEMAKAIAN NARKOTIKA" << endl;
	cout << "===================================" << endl;
	cout << " Masukkan nama file           = ";
	cin >> namafile;

	copy();
	gagal();
	table();
}

void sequentialsearch(){
	string cari;

	cout << "  Masukkan Kode Narkotika yang ingin dicari = ";
	cin >> cari;
	cout << endl;

	for(int i=0; i<jumlah; i++){
		if (id[i].swap == cari){
			cout << "\tKode Narkotik        = " << id[i].kode << endl;
			cout << "\tSatuan               = " << id[i].satuan << endl;
			cout << "\tPemakaian Untuk      = " << id[i].pakai << endl;
			cout << "\tPenggunaan Jumlah    = " << id[i].guna << endl;
			cout << endl;
		}
	}
}

// Sequential Search
void sequential(){
	int pilih;
	string keluar;

	cout << "===============================" << endl;
	cout << "  PENCARIAN DENGAN SEQUENTIAL" << endl;
	cout << "===============================" << endl;
	cout << "  1. Kode Narkotik" << endl;
	cout << "  2. Satuan" << endl;
	cout << "  3. Pemakaian Untuk" << endl;
	cout << "  4. Penggunaan Jumlah" << endl;
	cout << "===============================" << endl;
	cout << "  Masukkan Pilihan              = ";
	cin >> pilih;

	switch(pilih){
		case 1:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].kode;
			}
		break;

		case 2:
           	for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].satuan;
			}
		break;

		case 3:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].pakai;
			}
		break;

		case 4:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].guna;
			}
		break;
	}

	if(pilih<=4){
		sequentialsearch();

	}
	else if(pilih>4){
		cout << "Input Gagal!" << endl;
	}

	cout << "  Kembali ke menu Sequential Search? (Y/N)" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;

	if (keluar == "Y" || keluar == "y"){
		system("cls");
		sequential();
	}
}

int binarySearch(string names[], int size, string value){
    int first = 0,             // Elemen array pertama
        last = size - 1,       // Elemen array terakhir
        middle,                // Posisi tengah
        position = -1;         // Posisi nilai cari
    bool found = false;        // Flag

    while (!found && first <= last){
        middle = (first + last) / 2;     // Hitung
        if (names[middle] == value){      // Nilai ketemu di tengah
            found = true;
            position = middle;
        }
        else if (names[middle] > value){  // Nilai ketemu di bawah
            last = middle - 1;
        }
        else{
            first = middle + 1;
		}         // Nilai ketemu di atas
    }
    return position;
}

void binarysearch(){
	string cari, arr[jumlah], x;

	bubblesort();
	for (int i=0; i<jumlah; i++){
		arr[i] = id[i].swap;
	}
	cout << "  Masukkan Kode Narkotika yang ingin dicari = "; cin >> x;
	int n = jumlah;
	int result = binarySearch(arr, n, x);

	if(result == -1){
   		cout << ("Elemen tidak ditemukan") << endl;
    }
	else{
   		cout << endl;
		cout << "\tKode Narkotik        = " << id[result].kode << endl;
		cout << "\tSatuan               = " << id[result].satuan << endl;
		cout << "\tPemakaian Untuk      = " << id[result].pakai << endl;
		cout << "\tPenggunaan Jumlah    = " << id[result].guna << endl;
    }
}

// Binary Search
void binary(){
	int pilih;
	string keluar;

	cout << "===========================" << endl;
	cout << "  PENCARIAN DENGAN BINARY" << endl;
	cout << "===========================" << endl;
	cout << "  1. Kode Narkotik" << endl;
	cout << "  2. Satuan" << endl;
	cout << "  3. Pemakaian Untuk" << endl;
	cout << "  4. Penggunaan Jumlah" << endl;
	cout << "===========================" << endl;
	cout << "  Masukkan Pilihan          = ";
	cin >> pilih;

	switch(pilih){
		case 1:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].kode;
			}
		break;

		case 2:
           	for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].satuan;
			}
		break;

		case 3:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].pakai;
			}
		break;

		case 4:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].guna;
			}
		break;
	}

	if(pilih<=4){
		binarysearch();

	}
	else if(pilih>4){
		cout << "Input Gagal!" << endl;
	}

	cout << endl;
	cout << "  Kembali ke menu Binary Search? (Y/N)" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;

	if (keluar == "Y" || keluar == "y"){
		system("cls");
		binary();
	}
}

// Searching Data
void search(){
	int i, pilih;

	cout << "=================================" << endl;
	cout << "  CARI DATA PEMAKAIAN NARKOTIKA  " << endl;
	cout << "=================================" << endl;
	cout << " Masukkan nama file           = ";
	cin >> namafile;
	gagal();
	system("cls");

	cout << "=================================" << endl;
	cout << "  CARI DATA PEMAKAIAN NARKOTIKA" << endl;
	cout << "=================================" << endl;
	cout << "  1. Sequential" << endl;
	cout << "  2. Binary" << endl;
	cout << "=================================" << endl;
	cout << "  Masukkan Pilihan             = ";
	cin >> pilih;
	system("cls");

	copy();
	switch (pilih){
		case 1:
			sequential();
		break;

		case 2:
			binary();
		break;

		default:
			cout << "  Input Salah!" << endl;
		break;
	}
}

void bubblesort(){
	string begin, next;

	for(int i = 0; i < jumlah; i++){
		for(int j = 0 ; j < jumlah - i - 1; j++){
			begin = id[j].swap;
			next = id[j + 1].swap;

			if(begin[0] > next[0]){
				swap(&id[j].swap, &id[j + 1].swap);
				swap(&id[j].kode, &id[j + 1].kode);
				swap(&id[j].satuan, &id[j + 1].satuan);
				swap(&id[j].pakai, &id[j + 1].pakai);
				swap(&id[j].guna, &id[j + 1].guna);
			}
		}
	}
}

void bubble(){
	int pilih;
	string keluar;

	cout << "==========================" << endl;
	cout << "  PENGURUTAN DATA BUBBLE  " << endl;
	cout << "==========================" << endl;
	cout << "  1. Kode Narkotik" << endl;
	cout << "  2. Satuan" << endl;
	cout << "  3. Pemakaian Untuk" << endl;
	cout << "  4. Penggunaan Jumlah" << endl;
	cout << "==========================" << endl;
	cout << "  Masukkan Pilihan     = ";
	cin >> pilih;

	switch(pilih){
		case 1:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].kode;
			}
		break;
		case 2:
           	for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].satuan;
			}
		break;
		case 3:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].pakai;
			}
		break;
		case 4:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].guna;
			}
		break;
	}

	if(pilih<=4){
		bubblesort();
		cout << endl;
		cout << "  Hasil setelah disort : " << endl;
		table();
		paste();
	}
	else if(pilih>4){
		cout << "Input Gagal!" << endl;
	}

	cout << "  Kembali ke menu Bubble Sort? (Y/N)" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;
	if (keluar == "Y" || keluar == "y"){
		system("cls");
		bubble();
	}
}

void selectionsort(){
	int low;
	string temp, temp1, temp2, temp3, temp4;
	for (int i=0; i< (jumlah-1); i++){
            low=i;
        for (int j=i+1; j<jumlah; j++){
            if (id[j].swap<id[low].swap){
                low=j;
            }
        }
        temp = id[low].swap;
        temp1 = id[low].kode;
        temp2 = id[low].satuan;
        temp3 = id[low].pakai;
        temp4 = id[low].guna;

		id[low].swap = id[i].swap;
        id[low].kode = id[i].kode;
        id[low].satuan = id[i].satuan;
        id[low].pakai = id[i].pakai;
        id[low].guna = id[i].guna;

		id[i].swap = temp;
        id[i].kode = temp1;
        id[i].satuan = temp2;
        id[i].pakai = temp3;
        id[i].guna = temp4;
	}
}

void selection(){
    int pilih;
	string keluar;

	cout << "=============================" << endl;
	cout << "  PENGURUTAN DATA SELECTION  " << endl;
	cout << "=============================" << endl;
	cout << "  1. Kode Narkotik" << endl;
	cout << "  2. Satuan" << endl;
	cout << "  3. Pemakaian Untuk" << endl;
	cout << "  4. Penggunaan Jumlah" << endl;
	cout << "=============================" << endl;
	cout << "  Masukkan Pilihan     = ";
	cin >> pilih;

	switch(pilih){
		case 1:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].kode;
			}
		break;

		case 2:
           	for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].satuan;
			}
		break;

		case 3:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].pakai;
			}
		break;

		case 4:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].guna;
			}
		break;
	}

	if(pilih<=4){
		selectionsort();
		cout << endl;
		cout << "  Hasil setelah disort : " << endl;
		table();
		paste();
	}
	else if(pilih>4){
		cout << "Input Gagal!" << endl;
	}

	cout << endl;
	cout << "  Kembali ke menu Selection Sort? (Y/N)" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;

	if (keluar == "Y" || keluar == "y"){
		system("cls");
		selection();
	}
}

void insertionsort(){
    string temp, temp2, temp3, temp4;
    for(int i=0; i<jumlah; i++){
        temp = id[i].kode;
        temp2 = id[i].satuan;
        temp3 = id[i].pakai;
        temp4 = id[i].guna;
        int j= i-1;
        while (id[j].swap>temp && j>=0){
            id[j+1].kode = id[j].kode;
            id[j+1].satuan = id[j].satuan;
            id[j+1].pakai = id[j].pakai;
            id[j+1].guna = id[j].guna;
            j--;
        }
        id[j+1].kode = temp;
        id[j+1].satuan = temp2;
        id[j+1].pakai = temp3;
        id[j+1].guna = temp4;
    }
}

void insert(){
    int pilih;
	string keluar;

	cout << "==========================" << endl;
	cout << "  PENGURUTAN DATA INSERTION" << endl;
	cout << "==========================" << endl;
	cout << "  1. Kode Narkotik" << endl;
	cout << "  2. Satuan" << endl;
	cout << "  3. Pemakaian Untuk" << endl;
	cout << "  4. Penggunaan Jumlah" << endl;
	cout << "==========================" << endl;
	cout << "  Masukkan Pilihan     = ";
	cin >> pilih;

	switch(pilih){
		case 1:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].kode;
			}
		break;

		case 2:
           	for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].satuan;
			}
		break;

		case 3:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].pakai;
			}
		break;

		case 4:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].guna;
			}
		break;
	}

	if(pilih<=4){
		insertionsort();
		cout << endl;
		cout << "  Hasil setelah disort : " << endl;
		table();
		paste();
	}
	else if(pilih>4){
		cout << "Input Gagal!" << endl;
	}

	cout << endl;
	cout << "  Kembali ke menu Insertion Sort? (Y/N)" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;

	if (keluar == "Y" || keluar == "y"){
		system("cls");
		insert();
	}
}

void shellsort(){
	string temp, temp1, temp2, temp3, temp4;

	for (int gap = jumlah/2; gap > 0; gap = gap/2){
		for (int i = gap; i < jumlah; i++){
			temp = id[i].swap;
			temp1 = id[i].kode;
	        temp2 = id[i].satuan;
	        temp3 = id[i].pakai;
	        temp4 = id[i].guna;
	        int j;
	        for (j = i; j >= gap && id[j-gap].swap > temp; j = j-gap){
	        	id[j].swap = id[j-gap].swap;
	        	id[j].kode = id[j-gap].kode;
	            id[j].satuan = id[j-gap].satuan;
	            id[j].pakai = id[j-gap].pakai;
	            id[j].guna = id[j-gap].guna;
	        }
	        id[j].swap = temp;
	        id[j].kode = temp1;
	        id[j].satuan = temp2;
	        id[j].pakai = temp3;
	        id[j].guna = temp4;
		}
	}
}

void shell(){
    int pilih;
	string keluar;

	cout << "=========================" << endl;
	cout << "  PENGURUTAN DATA SHELL  " << endl;
	cout << "=========================" << endl;
	cout << "  1. Kode Narkotik" << endl;
	cout << "  2. Satuan" << endl;
	cout << "  3. Pemakaian Untuk" << endl;
	cout << "  4. Penggunaan Jumlah" << endl;
	cout << "=========================" << endl;
	cout << "  Masukkan Pilihan     = ";
	cin >> pilih;

	switch(pilih){
		case 1:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].kode;
			}
		break;
		case 2:
           	for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].satuan;
			}
		break;
		case 3:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].pakai;
			}
		break;
		case 4:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].guna;
			}
		break;
	}

	if(pilih<=4){
		shellsort();
		cout << endl;
		cout << "  Hasil setelah disort : " << endl;
		table();
		paste();
	}
	else if(pilih>4){
		cout << "Input Gagal!" << endl;
	}

	cout << endl;
	cout << "  Kembali ke menu Shell Sort? (Y/N)" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;
	if (keluar == "Y" || keluar == "y"){
		system("cls");
		shell();
	}
}

int partition (string arr[], int low, int high){
	int l1, l2, pi, object;
	bool same;

    string pivot = arr[high];
    int i = (low - 1);
 	l1 = pivot.length();
	char char_array1[l1 + 1];
	pi = char_array1[0];
	strcpy(char_array1, pivot.c_str());

	for(int j = low; j <= high - 1; j++){
    	l2 = arr[j].length();
		char char_array2[l2 + 1];
		strcpy(char_array2, arr[j].c_str());
		object = char_array2[0];

        if(object <= pi){
            i++;
            if(object < pi){
				cout << "\nyang di swap lebih besar: " << arr[i] << " & " << arr[j] << endl;
				swap(&arr[i],&arr[j]);
				swap(&id[i].kode,&id[j].kode);
				swap(&id[i].pakai, &id[j].pakai);
				swap(&id[i].guna, &id[j].guna);
				swap(&id[i].satuan, &id[j].satuan);
				cout << "Proses Sort : ";
				for(int i = low; i <= high; i++){
					cout << arr[i] << " ";
				}
				cout << endl;
			}
			else if(pi == object){
				same = false;
				int index = 0;
				int  a,b;
				while(!same){
					++index;
					a = char_array1[index];
					b = char_array2[index];

					if(a == b){
						continue;
					}
					else if(a != b){
						if(b < a){
							cout << "\nyang di swap sama dengan: " << arr[i] << " & " << arr[j] << endl;
							swap(&arr[i],&arr[j]);
							swap(&id[i].kode,&id[j].kode);
							swap(&id[i].pakai, &id[j].pakai);
							swap(&id[i].guna, &id[j].guna);
							swap(&id[i].satuan, &id[j].satuan);
							same = true;
							cout << "Proses Sort : ";
							for(int i = low; i <= high; i++){
								cout << arr[i] << " ";
							}
							cout << endl;
						}
					else{
						same = true;
						}
					}

				}
			}
        }
    }
    return (i + 1);
}

void QuickSort(string arr[], int low,int high){
	if(low < high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void quick(){
    int pilih, i, sumData;
	string keluar, arr[20];
	sumData = jumlah;

	cout << "=========================" << endl;
	cout << "  PENGURUTAN DATA QUICK  " << endl;
	cout << "=========================" << endl;
	cout << "  1. Kode Narkotik" << endl;
	cout << "  2. Satuan" << endl;
	cout << "  3. Pemakaian Untuk" << endl;
	cout << "  4. Penggunaan Jumlah" << endl;
	cout << "=========================" << endl;
	cout << "  Masukkan Pilihan     = ";
	cin >> pilih;

	switch(pilih){
		case 1:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].kode;
			}
		break;

		case 2:
           	for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].satuan;
			}
		break;

		case 3:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].pakai;
			}
		break;

		case 4:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].guna;
			}
		break;
	}

	if(pilih<=4){
		QuickSort(arr, 0, sumData-1);
		cout << endl;
		cout << "  Hasil setelah disort : " << endl;
		table();
		paste();
	}
	else if(pilih>4){
		cout << "Input Gagal!" << endl;
	}

	cout << endl;
	cout << "  Kembali ke menu Quick Sort? (Y/N)" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;
	if (keluar == "Y" || keluar == "y"){
		system("cls");
		quick();
	}
}

void merge1(string *arr, int low, int high, int mid)
{
    int i, j, k;
    string c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}

void merge_sort(string *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge1(arr,low,high,mid);
    }
}
// Merge sort

// read input array and call mergesort

void merge(){
    int pilih, i, sumData;
	string keluar, arr[20];
	sumData = jumlah;

	cout << "=========================" << endl;
	cout << "  PENGURUTAN DATA MERGE  " << endl;
	cout << "=========================" << endl;
	cout << "  1. Kode Narkotik" << endl;
	cout << "  2. Satuan" << endl;
	cout << "  3. Pemakaian Untuk" << endl;
	cout << "  4. Penggunaan Jumlah" << endl;
	cout << "=========================" << endl;
	cout << "  Masukkan Pilihan     = ";
	cin >> pilih;

	switch(pilih){
		case 1:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].kode;
			}
		break;

		case 2:
           	for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].satuan;
			}
		break;

		case 3:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].pakai;
			}
		break;

		case 4:
			for(int i=0; i<jumlah; i++){
				id[i].swap = id[i].guna;
			}
		break;
	}

	if(pilih<=4){
		merge_sort(arr, 0, sumData-1);
		cout << endl;
		cout << "  Hasil setelah disort : " << endl;
		table();
		paste();
	}
	else if(pilih>4){
		cout << "Input Gagal!" << endl;
	}

	cout << endl;
	cout << "  Kembali ke menu Merge Sort? (Y/N)" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;
	if (keluar == "Y" || keluar == "y"){
		system("cls");
		quick();
	}
}

// Sorting Data
void sort(){
	int i, pilih;
	string a, b, c, d, namafile;

	cout << "=======================================" << endl;
	cout << "  PENGURUTAN DATA PEMAKAIAN NARKOTIKA" << endl;
	cout << "=======================================" << endl;
	cout << " Masukkan nama file           = ";
	cin >> namafile;
	gagal();
	system("cls");

	copy();
	cout << "=======================================" << endl;
	cout << "  PENGURUTAN DATA PEMAKAIAN NARKOTIKA" << endl;
	cout << "=======================================" << endl;
	cout << "  1. Bubble Sort" << endl;
	cout << "  2. Selection Sort" << endl;
	cout << "  3. Insertion Sort" << endl;
	cout << "  4. Shell Sort" << endl;
	cout << "  5. Quick Sort" << endl;
	cout << "  6. Merge Sort" << endl;
	cout << "=======================================" << endl;
	cout << "  Masukkan Pilihan                  = ";
	cin >> pilih;
	system("cls");

	switch (pilih){
		case 1:
			bubble();
			break;

		case 2:
			selection();
			break;

		case 3:
			insert();
			break;

		case 4:
			shell();
			break;

		case 5:
			quick();
			break;

        case 6:
            merge();
            break;
		}

	if (pilih > 6){
		cout << "  Input Salah!" << endl;
	}
}

void mergesambung(){
	int i, kode, guna;
	string namafile, satuan, pakai;
	string a, b, c, d;

	cout << "===================" << endl;
	cout << "  MERGING SAMBUNG  " << endl;
	cout << "===================" << endl;
	cout << "  Nama File : "; cin >> namafile;

	gagal();
	copy();
	table();
	cout << endl;

	cout << "Nama File Kedua: "; cin >> namafile;
	gagal();

	ifstream x(namafile.c_str());
	if (x.is_open()){
		x >> a >> b >> c >> d;

		while (!x.eof()){
			id[jumlah].kode  = a;
			id[jumlah].satuan = b;
			id[jumlah].pakai = c;
			id[jumlah].guna = d;
			jumlah++;
			x >> a >> b >> c >> d;
		}
		x.close();
	}
	table();
}

void update(){
	string kode;

	cout << "===================" << endl;
	cout << "\tUPDATE  " << endl;
	cout << "===================" << endl;
	cout << "  Nama File : "; cin >> namafile;
	gagal();
	copy();
	table();

	cout << endl;
	cout << "  Masukkan Kode Narkotika		= "; cin >> kode;
	for (int i=0; i<jumlah; i++){
		if (kode == id[i].kode){
			cout <<	"  			Satuan Narkotika	= " << id[i].satuan << endl;
			cout <<	"  			Pemakaian Untuk		= " << id[i].pakai << endl;;
			cout <<	"  			Penggunaan Jumlah	= " << id[i].guna << endl;
			cout << "  Masukkan Data Update 	: " << endl;
			cout <<	"  			Satuan Narkotika	= "; cin >> id[i].satuan;
			cout <<	"  			Pemakaian Untuk		= "; cin >> id[i].pakai;
			cout <<	"  			Penggunaan Jumlah	= "; cin >> id[i].guna;

			cout << "  Masukkan nama file hasil Updating	= "; cin >> namafile;
			ofstream f;
			f.open (namafile.c_str());
			for (int i=0; i<jumlah; i++){
				f << id[i].kode << "\n" << id[i].satuan << "\n" << id[i].pakai << "\n" << id[i].guna << "\n";
			}
			f.close();
		}
		else if (i>jumlah && id[i].kode != kode){
			cout << "  Update Gagal!" << endl;
		}
	}
}

void transaksi(){
	int pilih;

	cout << "===================" << endl;
	cout << "     TRANSAKSI     " << endl;
	cout << "===================" << endl;
	cout << "1. Merging Sambung" << endl;
	cout << "2. Updating" << endl;
	cout << "Masukkan Pilihan : "; cin >> pilih;
	system("cls");

	switch(pilih){
		case 1:
			mergesambung();
		break;

		case 2:
			update();
		break;
	}
}

int main(){
	int pilih;
	string keluar;

    cout << "====================================" << endl;
    cout << "  PEMAKAIAN NARKOTIKA DI PUSKESMAS  " << endl;
    cout << "====================================" << endl;
    cout << "\t1. INPUT DATA     " << endl;
    cout << "\t2. TAMPILKAN DATA " << endl;
    cout << "\t3. SEARCHING DATA " << endl;
    cout << "\t4. SORTING DATA   " << endl;
    cout << "\t5. TRANSAKSI      " << endl;
	cout << "\t6. KELUAR         " << endl;
	cout << "====================================" << endl;
	cout << "====================================" << endl;
	cout << endl;
	cout << "Masukkan Pilihan          = ";
	cin >> pilih;
	system("cls");

	switch (pilih){
		case 1:
			input();
		break;

		case 2:
			output();
		break;

		case 3:
			search();
		break;

		case 4:
			sort();
		break;

		case 5:
			transaksi();
		break;
	}

	cout << endl << endl;
	cout << "  Kembali ke Menu Utama (Y/N) ?" << endl;
	cout << "  Masukkan Pilihan            = ";
	cin >> keluar;

	if (keluar == "Y" || keluar == "y"){
		system("cls");
		main();
	}

	return 0;
}
