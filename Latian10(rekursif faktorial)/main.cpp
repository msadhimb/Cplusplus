#include <iostream>

using namespace std;

int faktorial(int a){
    if (a==1){
        return a;
    }else{
        return a * faktorial(a-1);
    }
}

void faktorialIterasi(int a){
    int hasil=1;
    for(int i=1;i<=a;i++){
        hasil=hasil*i;
    }
    cout<<hasil;
}

int main(){
    int a;
    printf("Masukkan Nilai Faktorial: ");
    cin >> a;

    //printf("Nilai faktorial (rekursif) dari %d! adalah %d.\n", a, faktorial(a));
    faktorialIterasi(a);

    return 0;
}
