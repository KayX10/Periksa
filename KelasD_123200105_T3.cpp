#include <iostream>

using namespace std;

int main()
{
    double ipk;
    int ls;
    int lma;
    int bmkap;
    int jp;
    int bp;
    int skor;
    int rumusipk;
    int rumusls;
    int rumuslma;
    int rumusjp;
    int jumlahskor;

    cout << "IPK\t\t\t\t= "; cin>>ipk;
    cout << "Lama Studi (semester)\t\t= "; cin>>ls;
    cout << "Lama menjadi Asisten (semester)\t= "; cin>>lma;
    cout << "Banyaknya MKA Praktikum\t\t= "; cin>>bmkap;
    cout << "Jenis publikasi ([4]internasional, [3]nasional, [2]regional, [1]upn) = "; cin>>jp;
    cout << "Banyaknya publikasi\t\t= "; cin>>bp;

    if (ipk>=3.500 && ipk<=3.625){
        rumusipk=20*1;
    }
    if (ipk>=3.626 && ipk<=3.750){
        rumusipk=20*2;
    }
    if (ipk>=3.751 && ipk<=3.875){
        rumusipk=20*3;
    }
    if (ipk>=3.876 && ipk<=4.00){
        rumusipk=20*4;
    }

    if (ls=7){
        rumusls=10*4;
    }
    if (ls=8){
        rumusls=10*3;
    }
    if (ls=9){
        rumusls=10*2;
    }
    if (ls=10){
        rumusls=10*1;
    }

    if (lma>=4){
        rumuslma=10*4*bmkap;
    }
    if (lma=3){
        rumuslma=10*3*bmkap;
    }
    if (lma=2){
        rumuslma=10*2*bmkap;
    }
    if (lma=1){
        rumuslma=10*1*bmkap;
    }

    if (jp=4){
        rumusjp=10*4*bp;
    }
    if (jp=3){
        rumusjp=10*3*bp;
    }
    if (jp=2){
        rumusjp=10*2*bp;
    }
    if (jp=1){
        rumusjp=10*1*bp;
    }

    jumlahskor=rumusipk+rumusls+rumuslma+rumusjp;

    cout <<"\n";

    if (ipk>3.5){
            if (ls<=10){
                    if (lma>0){
                            if (bp>0){
                            cout << "Mahasiswa tersebut berhak mendapat Karya Cendikia\n";
                            cout << "Jumlah skor = " <<jumlahskor;
                            } else {
                            }
                    } else {
                    }
            } else {
            }
    } else {
    cout << "Mahasiswa tersebut tidak berhak mendapat Karya Cendikia";
    }


    return 0;

}
