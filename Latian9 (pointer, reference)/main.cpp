#include <iostream>

using namespace std;

void pointer();
void referencE();

int main(){

    pointer();
    referencE();

    return 0;
}

void pointer(){
    int a = 5;
    int *p;
    int **q;
    char tanya='y';


    while (tanya=='y'){
        p=&a;
        *q = p;

        printf("Alamat a adalah : %d \n", &a);
        printf("a bernilai : %d \n", a);
        printf("Alamat a adalah : %d \n", p);
        printf("a bernilai : %d \n", *p);
        printf("Alamat a adalah : %d \n", *q);
        printf("a bernilai : %d \n \n", **q);

        printf("Ingin merubah nilai a ?(y/t)\n");
        cin >> tanya;

        if (tanya == 'y'){
            printf("a akan dirubah menjadi ");
            cin >> a;
            printf("\n");
        }
    }

}

void referencE(){
    int a = 5;
    int &b = a;
    char tanya='y', tanya1;

    while (tanya=='y'){
        printf("Alamat dari a adalah %d \n", &a);
        printf("Nilai dari a adalah %d \n", a);

        printf("Nilai dari b adalah %d \n", b);
        printf("Alamat dari b adalah %d \n \n", &b);

        printf("Ingin mengubah nilai ?(y/t}\n");
        cin >> tanya;

        if (tanya=='y'){
            printf("Ingin mengubah nilai a atau b : \n");
            cin >> tanya1;
            if (tanya1=='a'){
                printf("Angka a akan dirubah menjadi ");
                cin >> a;
                printf("\n");
            }else{
                printf("Angka b akan dirubah menjadi ");
                cin >> b;
                printf("\n");
            }
        }
    }

}
