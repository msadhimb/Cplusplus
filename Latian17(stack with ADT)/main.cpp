#include <iostream>
#include "stack1.h"

using namespace std;

Stack S;

void printStack();
void pushturret();
void popturret();

int main(){
    char jawab2, jawab3;

    printf("Stack S penuh ? %d \n", IsFull(S));
    printf("Stack S kosong ? %d \n\n", IsEmpty(S));

    printf("Apakah anda ingin memasukkan elemen ke dalam Stack ? ");
    cin >> jawab3;
    if(jawab3=='y'){
        printf("\n");
        pushturret();
    }else{
        return 0;
    }

    printf("\n");
    printf("Pointer Stack S adalah %d \n", TOP(S));
    printf("Isi dari Stack S adalah %d \n", Info(S));
    printStack();
    printf("\n");
    printf("Stack S penuh ? %d/%d \n", TOP(S), MaxEl);

    printf("\n");
    printf("Apakah anda ingin menghapus elemen terakhir dari Stack ? ");
    cin >> jawab2;
    if(jawab2=='y'){
        popturret();
    }else{
        return 0;
    }
}

void printStack(){
    printf("Anggota dari Stack S adalah ");
    for(int i=1;i <= S.T[MaxEl+1]; i++){
        printf("%d ", S.T[i]);
    }
}

void pushturret(){
    int jawab;
    char jawab1;
    for(int i=1;i<=MaxEl+1;i++){
        printf("%d. Anda akan memasukkan angka ", i);
        cin >> jawab;
        Push(&S,jawab);
        printf("ingin memasukkan angka lagi ? ");
        cin >> jawab1;
        if(jawab1== 'y' ){
            printf("\n");
            continue;
        }else{
            break;
        }
    }
}

void popturret(){
    infotype e;

    Pop(&S,&e);
    printf("\n");
    printf("%d berhasil dihapus \n", e);
    printf("Pointer Stack S adalah %d \n", TOP(S));
    printf("Isi dari Stack S adalah %d \n", Info(S));
    printStack();
    printf("\n");
    printf("Stack S penuh ? %d \n", IsFull(S));

}
