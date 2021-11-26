#ifndef STACKLINK_H_INCLUDED
#define STACKLINK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define boolean unsigned char

#define Nil NULL
#define MaxEl 10

typedef int infotype;
typedef struct tElmtStack *address;
typedef struct tElmtStack{
    infotype info;
    address next;
}ElmtStack;

typedef struct{
    address TOP;
}Stack;

#define info(P) (P)->info
#define Next(P) (P)->next
#define Top(S) (S).TOP

void CreateStack(Stack *S);
boolean IsEmpty(Stack S);
boolean IsFull(Stack S);

int NbElmt(Stack S);
void Alokasi(Stack *S, infotype X);
void Dealokasi(address *P);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void PrintInfo(Stack S);


#endif // STACKLINK_H_INCLUDED
