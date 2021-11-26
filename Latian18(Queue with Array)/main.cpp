#include <iostream>
#include <unistd.h> //fungsi sleep

#define MAX 5

using namespace std;

string antriandokter[MAX];
int top = 0;
int bottom = 0;


bool isFull(){
    if(bottom == MAX){
        return true;
    }else{
        return false;
    }
}

bool isEmpty(){
    if(bottom == 0){
        return true;
    }else{
        return false;
    }
}

void pushQueue(string data){
    if(isFull()){
        printf("Antrian penuh. Silahkan kembali lagi nanti.");
    }else{
        if(isEmpty()==true){
            antriandokter[0]=data;
            top++;
            bottom++;
        }else{
            antriandokter[bottom]=data;
            bottom++;
        }
    }
}

void popQueue(){
    if(isEmpty()==true){
        printf("Antrian Kosong");
    }else{
        antriandokter[0] = antriandokter[1];
        antriandokter[1] = antriandokter[2];
        antriandokter[2] = antriandokter[3];
        antriandokter[3] = antriandokter[4];
        antriandokter[4] = "";
        bottom--;
    }
}

void viewQueue(){
    printf("Data Antrian Dr Salman. S.Pd, M.Pd, PhD\n");
    if(isEmpty()==true){
        printf("Antrian kosong.\n");
    }else{
        for(int i=0;i<MAX;i++){
            if(antriandokter[i]!=""){
                cout << i+1 << ". " << antriandokter[i] << endl;

            }else{
                printf("%d. (Masih Kosong)\n", i+1);
            }
        }
    }
}

int timer(){
    int detik=5;
    printf("\nPasien dipanggil dalam ");
    while(true){
        printf(" %d ", detik);
        detik--;
        if(detik==0){
            popQueue();
            break;
        }
        sleep(1);
    }
    printf("\n\n");
}

int main()
{
    string namaPasien;

    printf("Selamat Datang di Klinik Reproduksi Dr.Salman Boyke \n");
    cout << "Setiap harinya dokter Salman hanya mampu memeriksa 5 pasien\n"
         <<"masing masing pasien hanya diperiksa selama 5 detik dan dijamin langsung kuat.\n"<< endl;

    if(isEmpty()){
        for(int i=1;i<=5;i++){
            printf("%d. Nama anda adalah ", i);
            cin>>namaPasien;
            pushQueue(namaPasien);
        }

        for(int x=0;x<5;x++){
            cout << "\nSaudara " << antriandokter[0] << " silahkan masuk" << endl;
            timer();
            printf("Jumlah data antrian adalah %d \n", bottom);
            viewQueue();
            sleep(2);
        }

        printf("\nTerimakasih telah datang ke Klinik kami.\n");

    }
    return 0;
}
