#include <iostream>

using namespace std;


struct node     //make node for linked list using structure
{
    int value;            //value part of node contains the element
    struct node *next;    //the next part of node contains the address of next element of list
};

struct node *head;    //contains the address of first element of linked list

void init()
{
    head=NULL;    //initialize the beginning(head) of list to NULL
}

void insertfirst(int element)   //inserts element in linked list
{
    struct node *New;
    New=(struct node*)malloc(sizeof(struct node));    //New named node declared with size of node declared before
    New->value=element;       //inserts the new element to the value part of node New
    New->next=NULL;           //makes the next part of node New NULL so that no garbage value remains
    New->next=head;         //the address of previously first node, which was stored in head is now assigned to next part of node New
    head=New;              //the address of new first element which is present in node New is assigned to head node
}

void print()
{
    if(head==NULL)    //condition to check whether list is empty
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur=head;
    while(cur!=NULL)                  //the loop traverse until it gets any NULL node
    {
        printf("|%d|",cur->value);             //counts the number of nodes or elements present in list
        cur=cur->next;                //moves cur pointer to next node to check and get value
    }
}

void deleteitem(int ele)
{
    if(head==NULL)
        printf("list is empty and nothing to delete\n");
    struct node* cur=head;
    struct node* prev=NULL;
    while(cur->value!=ele)
    {
        prev=cur;
        cur=cur->next;
    }
    if(prev!=NULL)
    prev->next=cur->next;       //the address of next node after the node containing element to be deleted is assigned to the previous node of the node containing the element to be deleted
    free(cur);  //memory of the structure cur is deallocated
}

void insertlast(int ele)    //insert at the last of linked list
{
    struct node *New, *temp;
    New = (struct node*)malloc(sizeof(struct node));
    if(New== NULL)
    {
        printf("Unable to allocate memory.");
        return;
    }
    else
    {
        New->value = ele;
        New->next = NULL;
        temp = head;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = New;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void insertafter(int elem, int num)   //inserts element for any given element present in linked list
{
    struct node* New;
    New=(struct node*)malloc(sizeof(struct node));
    New->value=elem;
    New->next=NULL;
    struct node* prev=head;
    while(prev->value!=num)
    {
        prev=prev->next;
    }
    New->next=prev->next;
    prev->next=New;
}


int main(){

    init();

    int ch,element;

    while(true){
        printf("1. Masukkan Elemen Kedepan\n");
        printf("2. Hapus Elemen\n");
        printf("3. Masukkan Elemen Kebelakang\n");
        printf("4. Tampilkan list\n");
        printf("5. Masukkan Elemen Diantara Elemen\n");
        printf("6. Keluar\n");
        printf("enter choice of input: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("enter element to list: ");
            scanf("%d",&element);
            insertfirst(element);
        }
        else if(ch==2)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d",&de);
            deleteitem(de);
        }
        else if(ch==3)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d",&le);
            insertlast(le);
        }
        else if(ch==4)
        {
            print();
        }
        else if(ch==5){
            int ie,p;
            printf("enter element to insert: ");
            scanf("%d",&ie);
            printf("enter after which element to insert: ");
            scanf("%d",&p);
            insertafter(ie,p);
        }
        else if(ch==6){
            return 0;
        }
    }
}
