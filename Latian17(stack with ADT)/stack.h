#ifndef STACK1_H_INCLUDE
#define STACK1_H_INCLUDE

#include <stdio.h>
#include <stdlib.h>

//membuat boolean
#define true 1
#define false 0
#define boolean unsigned char

//Modul Stack
#define Nil 0 //Nil adalah stack dengan elemen kosong
#define MaxEl 10 //Max adalah max elemen dari stack

typedef int infotype;
typedef int address;

typedef struct{
    infotype T[MaxEl+1];
    address TOP;
}Stack;

//Akses deklarasi selektor
//S adalah struct dari stack
//T adalah array untuk memasukkan elemen
//TOP adalah alamat dari elemen
#define Info(S) S.T[S.TOP] //menyederhanakan perintah S.T[S.TOP]
#define TOP(S) S.TOP //menyederhanakan perintah S.TOP menjadi TOP(S)

//untuk memuat empty Stack dengan kapasitas max dan inisialisasi TOP adalah Nil
void CreateEmpty(Stack *S);
//fungsi untuk mendapatkan informasi bahwa Stack itu kosong
boolean IsEmpty(Stack S);
//fungsi untuk mendapatkan informasi bahwa Stack itu penuh
boolean IsFull(Stack S);


void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X)


#endif // STACK1_H_INCLUDE
