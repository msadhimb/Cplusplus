#include <iostream>
#include "singlelinklist.h"

using namespace std;

int main(){
    string jawab;
    int jawab2,jawab3;

    printf("Ingin membuat list ?"); scanf("%s", &jawab);
    if(jawab == "ya"){
        head = Nil;
        printf("List telah dibuat\n");
        printf("\nSilahkan memilih nomor dibawah ini \n");
        printf("1. Tambahkan list didepan\n");
        printf("2. Tambahkan list dibelakang\n");
        scanf("%d", &jawab2);
        switch(jawab2){
            case(1):
                printf("Angka yang akan anda inputkan adalah : "); scanf("%d", &jawab3);
                addBegin(jawab3);
                printNode();
        }
    }else{
        return 0;
    }
}
