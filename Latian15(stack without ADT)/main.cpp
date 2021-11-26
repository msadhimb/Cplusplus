#include <iostream>

#define MAX 5
int stack[MAX];
int top;

//deklarasi fungsi
int menu();
void push(int e);
int pop();
void show();

using namespace std;

int main(){
    int e,m;

    do{
        m = menu();
        switch(m){
            case(1):
                push(e);
                break;
            case(2):
                pop();
                break;
            case(3):
                show();
                break;
        }
    } while (m != 4);

    return 0;
}

void push(int e){
    if(top>=MAX){
        printf("Stack is full.\n");
    }else{
        printf("Push : ");
        scanf("%d", &e);
        stack[top]=e;
        top++;
    }
    printf("\n");
}

int pop(){
    if(top<=0){
        printf("Stack is empty.");
        return 0;
    }else{
        top--;
        return stack[top];
    }
    printf("\n");
}

void show(){
    if(top<=0){
        printf("Stack is empty.");
    }else{
        printf("Stack cosist of : ");
        for(int i=0;i<top;i++){
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    printf("\n");
}

int menu(){
    int choose;

    printf("\nStack Demo.\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Show\n");
    printf("4. Exit\n");
    printf("Choose : ");
    scanf("%d", &choose);

    return choose;
}






