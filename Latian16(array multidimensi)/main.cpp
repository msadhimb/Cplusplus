#include <iostream>

using namespace std;

void printArray(int *arrayPtr, int baris, int kolom);


int main(){
  //int arrayMd[baris][kolom]
    int arrayMd[4][3]={1,2,3,4,5,6,7,8,9,10,11,12};

    printArray(*arrayMd,4,3);

    return 0;
}

void printArray(int *arrayPtr, int baris, int kolom){
    int index=0;

    for(int i = 0; i < baris;i++){
        for(int j = 0; j < kolom;j++){
            cout<< *(arrayPtr + index) << " ";
            index++;
        }
        cout<<endl;
    }
}
