#ifndef SIMPLELIST_H_INCLUDED
#define SIMPLELIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define boolean unsigned char
#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;

typedef struct tElmtlist {
    infotype Info;
    address Next;
}ElmtList;

typedef struct {
    address First;
}List;

#define Info(P) (P)->Info
#define Next(P) (P)->Next
#define First(L) ((L).First)

// Prototype

// Test list kosong
boolean ListEmpty(List L);
// Mengirim true jika list kosong

// Pembuatan list kosong
void CreateList(List *L);

// Manajemen memory
address Alokasi(infotype X);

void Dealokasi(address *P);

void PrintInfo(List L);

// Insert and Delete

void InsertFirst(List *L, address P);

void InsertLast(List *L, address P);

void InsertTengah(List *L, address P, infotype X);

void InsertAfter(List *L, address P, address Prec);

void DelFirst(List *L, address *P);

void DelLast(List *L, address *P);

void DelAfter(List *L, address Prec, address *Pdel);

//Insert V and Delete V

void InsVFirst(List *L, infotype X);

void InsVLast(List *L, infotype X);

void DelVFirst(List *L, infotype *X);

void DelVLast(List *L, infotype *X);

void DelP(List *L, infotype X);

// Ganjil genap

boolean IsGengan(List L);

// Merge

void Konkat1(List *L1,List *L2,List *L3);

// Search

address Search(List L, infotype X);

address SearchPrec(List L, infotype X);

#endif // SIMPLELIST_H_INCLUDED


