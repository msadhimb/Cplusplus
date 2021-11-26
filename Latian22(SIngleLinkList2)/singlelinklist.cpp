#include "singlelinklist.h"

int isEmpty(){
    if(head == Nil){
        return 1;
    }
    else{
        return 0;
    }
}

void printNode(){
    struct Node *temp = head;
    printf("List : ");
    while(temp != Nil){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void addEnd(int x){
    struct Node *neew;
    struct Node *temp = head;

    neew = (struct Node*) malloc(sizeof(struct Node));
    neew->data = x;
    neew->next=Nil;
    if(isEmpty()==0){ //jika list tidak kosong
        while(temp->next != Nil){
            temp = temp->next;
        }
        temp->next=neew;
    }
    else{ //jika list kosong
        head = neew;
    }
}

void addBegin(int x){
    struct Node *neew;
    neew = (struct Node*) malloc(sizeof(struct Node));
    neew->data = x;
    neew->next = Nil;
    if(head != Nil) neew->next = head;
    head = neew;
}

void addNth(int data, int nth){
    struct Node *neew, *temp;
    int i;

    neew = (struct Node*) malloc(sizeof(struct Node));
    neew->data = data;
    neew->next = Nil;

    if(nth == 1){
        neew->next = head;
        head = neew;
    }
    else if(isEmpty() == 0){
        temp = head;
        for(int i; i < nth-2; i++){
            temp = temp->next;
        }
        neew->next = temp->next;
        temp->next = neew;
    }
    else{
        printf("List Kosong");
    }
}

void deleteBegin(){
    struct Node *temp = head;
    if(isEmpty() == 0){
        head = temp->next;
        free(temp);
    }
    else{
        printf("List kosong");
    }
}


