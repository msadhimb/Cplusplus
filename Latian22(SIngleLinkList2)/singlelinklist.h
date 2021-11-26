#ifndef SINGLELINKLIST_H_INCLUDED
#define SINGLELINKLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define Nil NULL

struct Node{ // membuat tipe node
    int data;
    struct Node *next;
};

struct Node *head; // membuat head node sebagai global variabel

int isEmpty(); // cek list kosong atau tidak

void printNode();

void addEnd(int x);

void addBegin(int x);

void addNth(int x);

void deleteBegin();



#endif // SINGLELINKLIST_H_INCLUDED
