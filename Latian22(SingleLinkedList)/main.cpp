#include <iostream>
#include "simpleList.h"

using namespace std;

int main()
{
    List L,L1,L2,L3;
    address P, A;
    int i,x,s,c,a,j,b;

    CreateList(&L);
    CreateList(&L1);
    CreateList(&L2);

    do{
        printf("\n\nSIMPLE LIST \n");
        if(ListEmpty(L) && ListEmpty(L1) && ListEmpty(L2)){
            printf("");
        }else if(ListEmpty(L) && ListEmpty(L1)){
            printf("List Gabungan : %s \n", ListEmpty(L2) ? "true" : "false");
            printf("List Gabungan  = "); PrintInfo(L2);
            printf("\n");
        }else{
            printf("L Kosong : %s \n", ListEmpty(L) ? "true" : "false");
            printf("L = "); PrintInfo(L);
            if(ListEmpty(L1)){
                printf("\n");
            }else{
                printf("\nL1 Kosong : %s \n", ListEmpty(L1) ? "true" : "false");
                printf("L1 = "); PrintInfo(L1);
                printf("\n");
            }
        }
        printf("\n");
        printf("1. Insert First \n");
        printf("2. Insert Last \n");
        printf("3. Gabungkan List \n");
        printf("4. Insert Tengah (Dengan Metode Insert First) \n");
        printf("5. Delete First \n");
        printf("6. Delete Last \n");
        printf("7. Delete (Pilih Angka) \n");
        printf("8. Exit \n");

        printf("Masukkan nomor yang anda pilih : ");
        scanf("%d", &j);
        switch(j){
                case(1):
                    printf("\n INSERT FIRST \n");
                    printf("Input banyak elemen : ");
                    scanf("%d", &s);
                    for(i = 1; i <= s; i++){
                        printf("Elemen %d : ", i); scanf("%d", &x);
                        P = Alokasi(x);
                        InsertFirst(&L, P);
                    }
                    printf("L = "); PrintInfo(L);
                    printf("\nList Genap-Gajil : %s ", IsGengan(L) ? "true" : "false");
                    printf("\n");
                    break;
                case(2):
                    printf("\n INSERT LAST \n");
                    printf("Input banyak elemen : ");
                    scanf("%d", &s);
                    for(i = 1; i <= s; i++){
                        printf("Elemen %d : ", i); scanf("%d", &x);
                        P = Alokasi(x);
                        InsertLast(&L1, P);
                    }
                    printf("L1 = "); PrintInfo(L1);
                    printf("\nList Genap-Gajil : %s ", IsGengan(L1) ? "true" : "false");
                    printf("\n");
                    break;
                case(3):
                    Konkat1(&L,&L1,&L2);
                    printf("\n");
                    printf("Penggabungan List L dan List L1 adalah L2 = "); PrintInfo(L2);
                    break;
                case(4):
                    printf("\n INSERT Tengah \n");
                    printf("List = "); PrintInfo(L2);
                    printf("\nAngka yang akan anda inputkan akan disisipkan(Dengan Metode Insert Tengah) ke angka : ", i); scanf("%d", &a);
                    printf("Input banyak elemen : ");
                    scanf("%d", &s);
                    for(i = 1; i <= s; i++){
                        printf("Elemen %d : ", i); scanf("%d", &x);
                        P = Alokasi(x);
                        InsertTengah(&L2,P,a);
                    }
                    printf("List = "); PrintInfo(L2);
                    printf("\nList Genap-Gajil : %s ", IsGengan(L2) ? "true" : "false");
                    printf("\n");
                    break;
                case(5):
                    DelFirst(&L2, &P);
                    printf("\n");
                    printf("L2 = "); PrintInfo(L2);
                    printf("\nElemen pertama telah dihapus");
                    break;
                case(6):
                    DelLast(&L2, &P);
                    printf("\n");
                    printf("L2 = "); PrintInfo(L2);
                    printf("\nElemen Terakhir telah dihapus");
                    break;
                case(7):
                    printf("\nAngka berapa yang ingin anda hapus ? Silahkan masukan jawaban : "); scanf("%d", &b);
                    DelP(&L2, b);
                    printf("%d telah dihapus dari list. \n");
                    break;
        }
    }while(j != 8);

    return 0;
}
