#include <iostream>
#include <stdlib.h> // rand()
#include <time.h> // srand(time(0))

using namespace std;


int main()
{
    string jawab;
    printf("Ingin acak dadu sekali ? (ya/tidak) \n");
    cin >> jawab;
    printf("\n");

    srand(time(0));
    if (jawab == "ya"){
        cout << 1 + (rand() % 6) << endl;
        printf("\n");
    }else if(jawab == "tidak"){
        int a;
        printf("Ingin mengulang berapa kali ? ");
        cin >> a;

        for(int i = 0; i <= a; i++){
            cout << 1 + (rand() % 6);

        printf("\n");
        }
    }else{
        cout << "Jawaban anda tidak teridentifikasi (jawaban yang teridentifikasi adalah ya atau tidak)" << endl;
    }

    string jawaban2;
    printf("Masih ingin mengacak dadu ? (ya/tidak) \n");
    cin >> jawaban2;

    if (jawaban2 == "ya"){
        main();
        printf("\n");
    }else if (jawaban2 == "tidak"){
        cin.get();
    }else{
        cout << "Jawaban anda tidak teridentifikasi (jawaban yang teridentifikasi adalah ya atau tidak)" << endl;
    }
    return 0;
}

