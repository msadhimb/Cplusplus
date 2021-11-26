#include <iostream>

using namespace std;


int fibonacciRekursif(int a);

int main()
{
    int a;

    printf("Masukkan jumlah deret : ");
    cin >> a;

    printf("\nAbaikan angka dibelakang 0 pertama \n");

    fibonacciRekursif(a);
    printf("\n");



    return 0;
}

int fibonacciRekursif(int a){
        printf("%d ",a);

        if((a==0)||(a==1)){
            return a;
        }else{
            return fibonacciRekursif(a-1) + fibonacciRekursif(a-2);
        }
}
