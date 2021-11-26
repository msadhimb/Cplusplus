#include <iostream>
#include <string>

using namespace std;

typedef struct{
    string nama;
    string nim;
}datamahasiswa;

int main()
{
    datamahasiswa siswa[20];

    for(int i = 0;i <= 20;i++){
        printf("\n\tSilahkan Menginputkan Data Mahasiswa\n");
        printf("Data ke - %d\n", i+1);

        printf("Nama\t: ");
        getline(cin, siswa[i].nama);

        printf("Nim\t: ");
        getline(cin, siswa[i].nim);
        printf("\n");

        printf("Apakah anda ingin menampilkan data ?(ya/tidak)");
        string jawab;
        getline(cin, jawab);
        if (jawab == "ya"){
            printf("\n");
            for (int x = 0; x <= i;x++){
                cout << x + 1 << ". " << "Nama mahasiswa adalah " << siswa[x].nama << " dengan NIM " << siswa[x].nim << ", telah berstatus AKTIF sebagai";
                cout << " mahasiswa di Universitas Dian Nuswantoro. " << endl;
            }
            break;
        }else{
            continue;
        }
    }


    return 0;
}
