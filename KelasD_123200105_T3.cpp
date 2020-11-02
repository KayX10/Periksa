#include <iostream>

using namespace std;

int main()
{
    double ipk;
    int lsa;
    int lma;
    int bmkap;
    int jpa;
    int bpa;
    int skor;
    int rumusipk;
    int rumusls;
    int rumuslma;
    int rumusjp;
    int jumlahskor;

    cout << "IPK\t\t\t\t= "; cin>>ipk;
    cout << "Lama Studi (semester)\t\t= "; cin>>lsa;
    cout << "Lama menjadi Asisten (semester)\t= "; cin>>lma;
    cout << "Banyaknya MKA Praktikum\t\t= "; cin>>bmkap;
    cout << "Jenis publikasi ([4]internasional, [3]nasional, [2]regional, [1]upn) = "; cin >> jpa;
    cout << "Banyaknya publikasi\t\t= "; cin>>bpa;

    if (ipk>=3.500 && ipk<=3.625){
        rumusipk=20*1;
    }
    else if (ipk>=3.626 && ipk<=3.750){
        rumusipk=20*2;
    }
    else if (ipk>=3.751 && ipk<=3.875){
        rumusipk=20*3;
    }
    else if (ipk>=3.876 && ipk<=4.00){
        rumusipk=20*4;
    }

    if (lsa==7){
        rumusls=10*4;
    }
    else if (lsa==8){
        rumusls=10*3;
    }
    else if (lsa==9){
        rumusls=10*2;
    }
    else if (lsa==10){
        rumusls=10*1;
    }

    if (lma>=4){
        rumuslma=10*4*bmkap;
    }
    else if (lma==3){
        rumuslma=10*3*bmkap;
    }
    else if (lma==2){
        rumuslma=10*2*bmkap;
    }
    else if (lma==1){
        rumuslma=10*1*bmkap;
    }

    if (jpa==4){
        rumusjp=10*4*bpa;
    }
    else if (jpa==3){
        rumusjp=10*3*bpa;
    }
    else if (jpa==2){
        rumusjp=10*2*bpa;
    }
    else if (jpa==1){
        rumusjp=10*1*bpa;
    }

    jumlahskor=(rumusipk+rumusls+rumuslma+rumusjp);

    cout <<"\n";

    if (ipk>3.5){
            if (lsa<=10){
                    if (lma>0){
                            if (bpa>0){
                            cout << "Mahasiswa tersebut berhak mendapat Karya Cendikia\n";
                            cout << "Jumlah skor = " <<jumlahskor;
                            } else {
                            cout << "Mahasiswa tersebut tidak berhak mendapat Karya Cendikia";
                            }
                    } else {
                    cout << "Mahasiswa tersebut tidak berhak mendapat Karya Cendikia";
                    }
            } else {
            cout << "Mahasiswa tersebut tidak berhak mendapat Karya Cendikia";
            }
    } else {
    cout << "Mahasiswa tersebut tidak berhak mendapat Karya Cendikia";
    }


    return 0;

}
