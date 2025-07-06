#include <iostream>
using namespace std;

union Veri {
    int sayi;
    char harf;
};

int main() {
    Veri v;

    v.sayi = 65;
    cout << "Sayi olarak: " << v.sayi << endl;
    cout << "Harf olarak: " << v.harf << endl;

    v.harf = 'B';
    cout << "\nYeni harf atandı: " << v.harf << endl;
    cout << "Sayi tekrar: " << v.sayi << endl;

    return 0;
}
