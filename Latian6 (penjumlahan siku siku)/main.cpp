#include <iostream>

using namespace std;

int main()
{
    int a, b, hasil;
    printf("Massukkan nilai : ");
    cin >> a;
    printf("\n");

    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= i; j++){
            if(i == j){
                hasil = i * j;
                cout << i << " = ";
                cout << hasil;
            }else{
                cout << i << " + ";
            }

        }

        printf("\n");
    }

    cin.get();
    return 0;
}
