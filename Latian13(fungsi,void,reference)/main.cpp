#include <iostream>

using namespace std;

int restart();
void referencE(int&);
void kuadrat(int&);
void faktorial(int&);
void fibonacci(int&);
void fibonacci2(int&);

int main(){

    int a;
    int jawab;

    printf("Masukkan nilai a : ");
    cin>>a;
    printf("\n");

    printf("Nilai dari a adalah %d\n",a);
    printf("Alamat dari a adalah %d\n\n", &a);

    referencE(a);
    printf("\nSilahkan pilih fungsi dibawah.\n1. Kuadrat\n2. Faktorial(!)\n3. Fibonacci\nAnda akan memilih jawaban nomor ");
    cin>>jawab;

    if(jawab==1){
        printf("\n");
        kuadrat(a);
        printf("\n");
        restart();
    }else if(jawab==2){
        printf("\n");
        faktorial(a);
        printf("\n");
        restart();
    }else if(jawab==3){
        printf("\n");
        fibonacci2(a);
        printf("\n");
        restart();
    }else{
        printf("\n");
        printf("Silahkan pilih jawaban yang disediakan.");
        printf("\n");
        restart();
    }
}

int restart(){
    char jawab1;

    printf("Apakah anda ingin memulai lagi ? (y/t)");
    cin>>jawab1;
    if(jawab1=='y'){
        printf("\n");
        main();
    }else{
        return 0;
    }
}

void referencE(int &b){
    printf("\nNilai dari b adalah %d\n",b);
    printf("Alamat dari b adalah %d\n", &b);
}

void kuadrat(int &c){
    c = c * c;
    printf("Nilai dari FUNGSI KUADRAT adalah %d\n",c);
    printf("Alamat dari FUNGSI KUADRAT adalah %d\n", &c);
}

void faktorial(int &fakt){
    int hasil=1;
    int *hasil2;

    for(int i=1;i<=fakt;i++){
        hasil=hasil*i;
        hasil2=&hasil;
    }

    fakt=*hasil2;
    printf("Nilai dari FUNGSI FAKTORIAL adalah %d\n",fakt);
    printf("Alamat dari FUNGSI FAKTORIAL adalah %d\n", &fakt);
}

void fibonacci2(int &fib){
    int *ahh;
    int angka,angka1,angka2;
    int fibarray[fib];

    angka=1;
    angka1=1;
    angka2=0;

    printf("Deret FIBONACCI adalah 1 ");
    for(int i=2;i<=fib;i++){
        angka=angka1+angka2;
        angka2=angka1;
        angka1=angka;
        for(int x=0;x<=fib;x++){
            fibarray[x]=angka1;
            printf("%d ", fibarray[x]);
            break;
        }
    }
    printf("\nNilai dari FUNGSI FIBONACCI adalah %d",fibarray[-1]);

    printf("\nAlamat FUNGSI FIBONACCI adalah masing-masing ");
    for(int nilai:fibarray){
            ahh=&nilai;
            fib=*ahh;
            printf("%d ", &fib);
    }
    printf("\n");
}
