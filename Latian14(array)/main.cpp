#include <iostream>
#include <array>

using namespace std;

int main(){
    int jumlah=0;

    array<int,11>nilai;

    printf("Memasukkan nilai kedalam array\n");
    for(int i=0; i<=nilai.size()-1; i++){
        printf("Jumlah mahasiswa dengan nilai ");
        if(i == 0){
            printf("00 - 10 : ");
        }else if(i == 10){
            printf("100     : ");
        }else{
            printf("%d - %d : ",i*10, (i*10)+9);
        }
        cin>>nilai[i];
    }

    for (int x=0;x<=nilai.size()-1;x++){
        jumlah = jumlah + nilai[x];
    }
    printf("\nJumlah siswa adalah %d", jumlah);
    printf(" dengan Grafik\n\n");

    for(int i=0; i<=nilai.size()-1; i++){
        if(i == 0){
            printf("00 - 10 : ");
        }else if(i == 10){
            printf("100     : ");
        }else{
            printf("%d - %d : ",i*10, (i*10)+9);
        }

        for(int bintang = 0; bintang < nilai[i]-1; bintang++){
           printf(" ");
        }
        printf("*");
        printf("\n");
    }

    return 0;
}
