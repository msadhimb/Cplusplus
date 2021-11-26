#include <iostream>

using namespace std;

int main()
{
    float nilai1,nilai2,hasil;
    cout << "Masukkan nilai : ";
    cin >> nilai1;

    char aritmatika;
    cout << "Pilih operator +(ditambah),-(dikurang),/(dibagi),*(dikali): ";
    cin >> aritmatika;

    cout << "Masukkan nilai : ";
    cin >> nilai2;

    switch (aritmatika){
        case '+':
            hasil = nilai1 + nilai2;
            cout << "Hasil dari " << nilai1 << " " << aritmatika<< " " << nilai2 << " adalah " << hasil << endl;
            break;
        case '-':
            hasil = nilai1 - nilai2;
            cout << "Hasil dari " << nilai1 << " " << aritmatika<< " " << nilai2 << " adalah " << hasil << endl;
            break;
        case '/':
            hasil = nilai1 / nilai2;
            cout << "Hasil dari " << nilai1 << " " << aritmatika<< " " << nilai2 << " adalah " << hasil << endl;
            break;
        case '*':
            hasil = nilai1 * nilai2;
            cout << "Hasil dari " << nilai1 << " " << aritmatika<< " " << nilai2 << " adalah " << hasil << endl;
            break;
    }


    return 0;
}
