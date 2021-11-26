#include "stack1.h";

void CreateEmpty(Stack *S){
    TOP((*S)) = Nil;
    Info((*S)) = Nil;
}

boolean IsEmpty(Stack S){
    return (TOP(S)==Nil);
}

boolean IsFull(Stack S){
    return (TOP(S)==MaxEl);
}

void Push(Stack *S, infotype X){
    TOP((*S))++;
    Info((*S)) = X;
}

void Pop(Stack *S, infotype *X){
    *X = Info((*S));
    TOP((*S))--;
}

