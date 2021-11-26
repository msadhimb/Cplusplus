#include <iostream>

using namespace std;

int main()
{
    int nilai,nilai1,nilai2,nilai3;

    printf("Masukkan jumlah dari panjang deret fibonacci : ");
    cin >> nilai;
    printf("\n");

    nilai1 = 1;
    nilai2 = 1;
    nilai3 = 0;

    if (nilai == 1){
        printf("1 ");
    }
    else if (nilai == 2){
        printf("1 1");
    }
    else{
        printf("1 ");
        for(int i = 2; i <= nilai; i++){
            nilai1 = nilai2 + nilai3;
            nilai3 = nilai2;
            nilai2 = nilai1;
            cout << nilai1 << " ";
        }

    }

    printf("\n");

    cin.get();
    return 0;
}
