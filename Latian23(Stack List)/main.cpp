#include "stacklink.h"
#include <iostream>

using namespace std;

int main()
{
    Stack S;
    address P;
    int N,i,X;
    CreateStack(&S);
    printf("Apakah Stack S kosong ? %d \n", IsEmpty(S));

    //Pop(&S,&X);
    cout << "Berapa banyak elemen yang diinginkan ? ";
    cin >> N;
    for(i = 1;i <= N; i++){
        cout << "Elemen ke " << i << " stack : ";
        cin >> X;
        Alokasi(&S,X);
        Push(&S,X);
    }
    cout << "Stack S: ";PrintInfo(S);
    cout << "\n";

    Pop(&S, &X);
    cout << "\n" << X << " sudah diPOP\n";
    cout << "Stack S setelah POP : ";PrintInfo(S);
    cout << "\n\n";
    cout << "Info Top Stack S : " << info(Top(S)) << endl;
    printf("Apakah Stack S kosong ? %d\n", IsEmpty(S));
    return 0;
}
