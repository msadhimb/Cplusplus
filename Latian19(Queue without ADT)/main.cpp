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

void initial();

bool isEmpty();

bool isFull();
int isFull2();
bool isFull3();
bool isFull();

void enqueue1(string e);
void enqueue2(string e);
void enqueue3(string e);
void enqueue(string e);

void dequeue1(string *e);
void dequeue2(string *e);
int dequeue3(string *e);
void dequeue(string *e);

void clear1();

void show1_2();
void show3();
void show();

int countdown(string &e); //hanya untuk alternatif 3 dan 4

int menu();


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
            case(5):
                countdown(e);
                printf("\n");
                break;
        }
    }while(m!=6);
    return 0;
}

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






//membuat fungsi isFull
//FUNGSI isFull UNTUK ALTERNATIF
bool isFull1(){
    if(queue1.tail==MAX-1){
        return true; //jadi ketika queue penuh maka akan mereturn nilai true
    }else{
        return false; //jika queue tidak penuh maka akan mereturn nilai false
    }
}
//FUNGSI isFull UNTUK ALTERNATIF 2
int isFull2(){
    if((queue1.head==0) && (queue1.tail==MAX-1)){
        return 1; //jadi ketika queue penuh maka akan mereturn nilai 1
    }else if((queue1.head>0) && (queue1.tail==MAX-1)){
        return 2; //jika head lebih dari 0 dan tail full, maka akan meretun 2
    }else{
        return 0; //jika queue tidak penuh maka akan mereturn nilai 0
    }
}
//FUNGSI isFull UNTUK ALTERNATIF 3
bool isFull3(){
    if((queue1.tail+1==queue1.head) || ((queue1.head==0) && (queue1.tail==MAX-1))){
        return true; //jadi ketika queue penuh maka akan mereturn nilai true
    }else{
        return false; //jika queue tidak penuh maka akan mereturn nilai false
    }
}
//FUNGSI isFull UNTUK ALTERNATIF 4
bool isFull(){
    if(queue1.tail==MAX){
        return true; //jadi ketika queue penuh maka akan mereturn nilai true
    }else{
        return false; //jika queue tidak penuh maka akan mereturn nilai false
    }
}






//membuat fungsi untuk memasukkan data ke queue
//UNTUK ALTERNATIF 1
void enqueue1(string data){
    if(isEmpty()==true){
        queue1.head = queue1.tail = 0;
        queue1.data[queue1.tail]=data;
        cout << queue1.data[queue1.tail] << ", nama anda sukses dimasukkan kedalam antrian\n";
    }else{
        if(isFull()==false){
            queue1.tail++;
            queue1.data[queue1.tail] = data;
            cout << queue1.data[queue1.tail] << ", nama anda sukses dimasukkan kedalam antrian\n";
        }else{
            cout << "Antrian sudah penuh\n";
        }
    }
}
//UNTUK ALTERNATIF 2
void enqueue2(string data){
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
//UNTUK ALTERNATIF 3
void enqueue3(string data){
    if(isEmpty()==true){
        queue1.head=0;
        queue1.tail=0;
        queue1.data[queue1.tail]=data;
        cout << queue1.data[queue1.tail] << ", nama anda sukses dimasukkan kedalam antrian\n";
    }else{
        if(isFull()==false){
            queue1.tail = (queue1.tail+1)%MAX;
            queue1.data[queue1.tail] = data;
            cout << queue1.data[queue1.tail] << ", nama anda sukses dimasukkan kedalam antrian\n";
        }else{
            cout << "Antrian sudah penuh\n";
        }
    }
}
//UNTUK ALTERNATIF 4
void enqueue(string data){
    if(isFull()){
        printf("Antrian penuh. Silahkan kembali lagi nanti.\n");
    }else{
        if(isEmpty()==true){
            queue1.head=0;
            queue1.tail=0;
            queue1.data[0]=data;
            queue1.tail++;
        }else{
            queue1.data[queue1.tail]=data;
            queue1.tail++;
        }
    }
}






//membuat fungsi menghapus antrian dengan aturan FIFO (FIRST IN FIRST OUT)
//ALTERNATIF 1
void dequeue1(string *e){
    if(isEmpty()==false){
        *e = queue1.data[queue1.tail];
        queue1.head++;
        cout << *e << ", berhasil dihapus dari antrian";
    }else{
        printf("Antrian kosong\n");
    }

}
//ALTERNATIF 2
void dequeue2(string *e){
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
//ALTERNATIF 3
int dequeue3(string *e){
    if(isEmpty()==false){
        *e = queue1.data[queue1.head];
        queue1.head = (queue1.head + 1)%MAX;
        cout << *e << ", berhasil dihapus dari antrian\n";
    }else{
        printf("Antrian kosong\n");
    }

}
//ALTERNATIF 4
void dequeue(string *e){
    if(isEmpty()==true){
        printf("Antrian Kosong");
    }else{
        *e = queue1.data[queue1.head];
        cout << *e << ", berhasil dihapus dari antrian\n";
        queue1.data[0] = queue1.data[1];
        queue1.data[1] = queue1.data[2];
        queue1.data[2] = queue1.data[3];
        queue1.data[3] = queue1.data[4];
        queue1.data[4] = "";
        queue1.tail--;
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
void show1_2(){
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
//SHOW UNTUK ALTERNATIF 3
void show3(){
    int i;
    if(isEmpty()==false){
        if(queue1.head == queue1.tail){
            cout << "- " << queue1.data[queue1.head] << endl;
        }else{
            for(i = queue1.head;i != queue1.tail;i=(i+1)%MAX){
                cout << "- "<< queue1.data[i] << endl;
            }
            cout << "- "<< queue1.data[queue1.tail] << endl;
        }
        printf("\n");
    }else{
        printf("Antrian kosong\n");
    }
}
//SHOW UNTUK ALTERNATIF 4
void show(){
    if(isEmpty()==true){
        printf("Antrian kosong.\n");
    }else{
        for(int i=0;i<queue1.tail;i++){
            if(queue1.data[i]!=""){
                cout << i+1 << ". " << queue1.data[i] << endl;
            }else{
                printf("%d. (Masih Kosong)\n", i+1);
            }
        }
    }
}






//hanya berlaku untuk ALTERNATIF 4
//Membuat fungsi countdown
int countdown(string &e){
    for(int x=queue1.head;x<= queue1.tail;x++){
        int detik=5;
        printf("\nPasien dipanggil dalam ");
        while(true){
            printf(" %d ", detik);
            detik--;
            if(detik==0){
                printf("\n");
                dequeue(&e);
                queue1.tail--;
                break;
            }
            sleep(1);
        }
        printf("\n");
    }
}



int menu(){
    int choose;
    printf("Antrian Demo\n");
    printf("1. Tambah Antrian\n");
    printf("2. Hapus Antrian\n");
    printf("3. Tampilkan Antrian\n");
    printf("4. Membersihkan Antrian\n");
    printf("5. CountDown Antrean\n");
    printf("6. Exit\n");
    printf("Choose : ");
    cin >> choose;
    return choose;
}

