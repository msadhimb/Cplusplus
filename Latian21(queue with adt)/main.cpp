//Nama : Muhamad Salman Adhim Baqy
//Nim : A11.2020.12641
//Kelas : 4309

#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    int d,s,p,m,o;
    Queue Q;

    printf("Berapa Queue yang dibuat ?");scanf("%d",&d);
    printf("\n");
    CreateEmpty(&Q,d);
    for(m=1;m<=d;m++){
        printf("Masukkan elemen queue %d : ",m);scanf("%i",&s);
        Add(&Q,s);
    }
    printf("\n Banyak elemen queue = %i",NBElmt(Q));
    printf("\n Is Empty ? %s",IsEmpty(Q)?"Ya":"Tidak");
    printf("\n Is Full ? %s",IsFull(Q)?"Ya":"Tidak");
    printf("Masukkan elemen queue yang akan dihapus ?");scanf("%i",&o);
    for(m=1;m<=o;m++){
        Del(&Q,&p);
    }

    printf("\n Sisa elemen queue : %d",NBElmt(Q));
    printf("\n Is Empty ? %s",IsEmpty(Q)?"Ya":"Tidak");
    printf("\n Is Full ? %s",IsFull(Q)?"Ya":"Tidak");
    DeAlokasi(&Q);
    return 0;
}
