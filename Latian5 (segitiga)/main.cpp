#include <iostream>

using namespace std;

int main()
{
    int a;
    printf("Masukkan panjang segitiga : ");
    cin >> a;

    printf("\nSegitiga siku-siku\n");
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= i; j++){
            printf("1");
        }
        printf("\n");
    }

    printf("\nSegitiga siku-siku terbalik\n");
    for(int i = 1; i <= a; i++){
        for(int j = a; j >= i; j--){
            printf("*");
        }
        printf("\n");
    }

    printf("\nSegitiga siku-siku terflip\n");
    for(int i = 1; i <= a; i++){
        for(int j = a; j >= i; j--){
            printf(" ");
        }
        for(int k = 1; k <= i; k++){
            printf("*");
        }
        printf("\n");
    }

    printf("\nSegitiga siku-siku terbalik yang terflip\n");
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= i; j++){
            printf(" ");
        }
        for(int k = a; k >= i; k--){
            printf("*");
        }
        printf("\n");
    }

    printf("\nSegitiga sama kaki\n");
    for(int i = 1; i <= a; i++){
        for(int j = a; j >= i; j--){
            printf(" ");
        }
        for(int k = 1; k <= (2*i - 1); k++){
            printf("*");
        }
        printf("\n");
    }

    printf("\nSegitiga sama kaki terbalik\n");
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= i; j++){
            printf(" ");
        }
        for(int k = a; k >= (2*i - a); k--){
            printf("*");
        }
        printf("\n");
    }
    printf("\nBelah ketupat\n");
    for(int i = 1; i <= a; i++){
        for(int j = a; j >= i; j--){
            printf(" ");
        }
        for(int k = 1; k <= (2*i - 1); k++){
            printf("*");
        }
        printf("\n");
    }
    for(int i = 2; i <= a; i++){
        for(int j = 1; j <= i; j++){
            printf(" ");
        }
        for(int k = a; k >= (2*i - a); k--){
            printf("*");
        }
        printf("\n");
    }

    cin.get();
    return 0;
}
