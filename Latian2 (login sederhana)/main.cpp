#include <iostream>

using namespace std;

int main()
{
    int a;
    cout << "Masukkan pin anda : ";
    cin >> a;

    if (a == 189536){
        cout << "Selamat Datang \n Silahkan Melakukan Login ke Akun Anda" << endl;
        string b;
        cout << "Username : ";
        cin >> b;
        string c;
        cout << "Password : ";
        cin >> c;
        if (c == "salatiga123"){
            cout << "\n Halo " << b << endl;
        } else{
            cout << "Maaf password yang anda masukkan salah." << endl;
        }
    }
    else{
        cout << "Maaf pin yang anda masukkan salah." << endl;
    }
    cin.get();
    return 0;
}
