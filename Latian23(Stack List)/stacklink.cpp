#include "stacklink.h"

void CreateStack(Stack *S){
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S){
    return (Top(S) == Nil);
}

boolean IsFull(Stack S){
    return (NbElmt(S) == MaxEl);
}

int NbElmt(Stack S){
    int jum = 0;
    address P;

    if(IsEmpty(S)){
        return jum;
    }else{
        P = Top(S);
        while(P != Nil){
            jum++;
            P = Next(P);
        }
    }
    return jum;
}

void Alokasi(Stack *S, infotype X){
    address P;

    P = (address)malloc(sizeof(ElmtStack));
    if(P != Nil){
        info(P) = X;
        Next(P) = Nil;
    }else{
        P = Nil;
    }
}

void Dealokasi(address *P){
    free(*P);
}

void Push(Stack *S, infotype X){
    address P;

    Alokasi(&(*S), X);
    if(IsEmpty(*S)){
        Top(*S) = P;
    }else if(IsFull(*S)){
        printf("Stack Penuh \n");
    }else{
        Next(P) = Top(*S);
        Top(*S) = P;
    }
}

void Pop(Stack *S, infotype *X){
    address P;

    if(IsEmpty(*S)){
        printf("Stack Kosong \n");
    }else{
        P = Top(*S);
        *X = info(P);
        if(Next(P) == Nil){
            Top(*S) = Nil;
        }else{
            Top(*S) = Next(Top(*S));
        }
        Next(P) = Nil;
        Dealokasi(&P);
    }
}

void PrintInfo(Stack S){
    address P;

    if(IsEmpty(S)){
        printf("Stack Kosong \n");
    }else{
        P = Top(S);
        do{
            printf("|%d| ", info(P));
            P = Next(P);
        }while(P != Nil);
    }
}
