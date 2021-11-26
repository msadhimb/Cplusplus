#include <iostream>

using namespace std;

string data[3] = {"sapi", "kuda", "monyet"};

void question1();
void question2();
void question3();

string jawab;

int main()
{
    question1();
    return 0;
}

void question1(){
    printf("1. Aku adalah hewan herbivora berkaki empat\n tubuhku besar, aku suka digunakan dalam pertandingan di madura\n kadang aku juga digunakan sebagai alat untuk membajak sawah\n Siapakah aku ?");
    printf("\n");
    cin >> jawab;
    if(jawab == data[0]){
        printf("Selamat anda benar dan bisa lanjut ke pertanyaan berikutnya\n\n");
        question2();
    }else{
        printf("\nJawaban anda salah\n");
        question1();
    }
}

void question2(){
    printf("2. Aku adalah hewan herbivora berkaki empat\n tubuhku besar, aku sering digunakan sebagai kendaraan sebelum ada mobil\n lariku sangat kencang jika dibandingkan dengan hewan bertubuh besar seperti aku\n Siapakah aku ?");
    printf("\n");
    cin >> jawab;
    if(jawab == data[1]){
        printf("Selamat anda benar dan bisa lanjut ke pertanyaan berikutnya\n\n");
        question3();
    }else{
        printf("\nJawaban anda salah\n");
        question2();
    }
}

void question3(){
    printf("3. Aku adalah hewan omnivore berkaki dua\n hewan dispesiesku ada yang bertubuh besar dan kecil, kadang aku lucu dan menjadi peliharaan manusia, namun aku juga bisa menjadi liar\n aku adalah hewan yang paling mirip dengan manusia\n Siapakah aku ?");
    printf("\n");
    cin >> jawab;
    if(jawab == data[2]){
        printf("Selamat anda benar dan bisa lanjut ke pertanyaan berikutnya\n\n");
    }else{
        printf("\nJawaban anda salah\n");
        question3();
    }
}
