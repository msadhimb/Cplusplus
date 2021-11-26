#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //fungsi sleep

using namespace std;

#define MAX 5 //maximal elemen dari queue
typedef struct{
    string data[MAX]; //variable untuk memasukkan data queue
    int head; // pointer head dari queue
    int tail; // pointer tail dari queue
}dataqueue;

dataqueue queue1; //deklarasi variabel global menggunakan dataqueue datatype dari typedef

//untuk membuat dan mengidentafikasi queueu baru
void initial(){
    queue1.head = -1;
    queue1.tail = -1;
}

//membuat fungsi isEmpty
bool isEmpty(){
    if(queue1.tail == -1){
        return true; //jadi ketika queue kosong maka akan mereturn nilai true
    }else{
        return false; //jika queue tidak kosong maka akan mereturn nilai false
    }
}

//FUNGSI isFull UNTUK ALTERNATIF 2
int isFull(){
    if((queue1.head==0) && (queue1.tail==MAX-1)){
        return 1; //jadi ketika queue penuh maka akan mereturn nilai 1
    }else if((queue1.head>0) && (queue1.tail==MAX-1)){
        return 2; //jika head lebih dari 0 dan tail full, maka akan meretun 2
    }else{
        return 0; //jika queue tidak penuh maka akan mereturn nilai 0
    }
}

//UNTUK ALTERNATIF 2
void enqueue(string data){
    if(isEmpty()==true){
        queue1.head = queue1.tail = 0;
        queue1.data[queue1.tail]=data;
        cout << queue1.data[queue1.tail] << ", nama anda sukses dimasukkan kedalam antrian\n";
    }else{
        if(isFull()==0){
            queue1.tail++;
            queue1.data[queue1.tail] = data;
            cout << queue1.data[queue1.tail] << ", nama anda sukses dimasukkan kedalam antrian\n";
        }else if(isFull()==2){
            int i;
            int a = 0;
            for(i=queue1.head;i<=queue1.tail;i++,a++){
                queue1.data[a]=queue1.data[i];
            }
            queue1.data[a]=data;
            queue1.head=0;
            queue1.tail=a;
            cout << queue1.data[queue1.tail] << ", nama anda sukses dimasukkan kedalam antrian\n";
        }else{
            cout << "Antrian sudah penuh\n";
        }
    }
}

//membuat fungsi menghapus antrian dengan aturan FIFO (FIRST IN FIRST OUT)
//ALTERNATIF 2
void dequeue(string *e){
    if(isEmpty()==false){
        if(queue1.head==queue1.tail){
            *e = queue1.data[queue1.head];
            queue1.tail = -1;
            queue1.head = -1;
        }else{
            *e = queue1.data[queue1.head];
            queue1.head++;
            cout << *e << ", berhasil dihapus dari antrian\n";
        }
    }else{
        printf("Antrian kosong\n");
    }
}

//membuat fungsi untuk membersihkan queue
void clear1(){
    if(isEmpty()==false){
        queue1.head = -1;
        queue1.tail = -1;
        printf("Antrian telah dikosongan\n");
    }else{
        printf("Antrian sudah kosong\n");
    }
}

//membuat fungsi untuk menampilkan queue
//SHOW UNTUK ALTERNATIF 1 DAN 2
void show(){
    if(isEmpty()==false){
        printf("Data antrian adalah \n");
        for(int i=queue1.head;i<=queue1.tail;i++){
            cout << "- "<< queue1.data[i] << endl;
        }
        printf("\n");
    }else{
        printf("Antrian kosong\n");
    }
}

int menu(){
    int choose;
    printf("Antrian Demo\n");
    printf("1. Tambah Antrian\n");
    printf("2. Hapus Antrian\n");
    printf("3. Tampilkan Antrian\n");
    printf("4. Membersihkan Antrian\n");
    printf("5. Exit\n");
    printf("Choose : ");
    cin >> choose;
    return choose;
}

int main()
{
    string e;
    int m = 0;

    initial();
    do{
        m = menu();
        switch(m){
            case(1):
                printf("Data yang akan anda masukkan adalah : ");
                cin >> e;
                enqueue(e);
                printf("\n");
                break;
            case(2):
                dequeue(&e);
                printf("\n");
                break;
            case(3):
                show();
                printf("\n");
                break;
            case(4):
                clear1();
                printf("\n");
                break;
        }
    }while(m!=5);
    return 0;
}
