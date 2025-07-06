#include <iostream>
using namespace std;

struct Durum {
    unsigned int sistemAcik : 1;   // sadece 1 bit
    unsigned int hataVar : 1;      // 1 bit
    unsigned int pilSeviye : 3;    // 3 bit (0-7)
};

int main() {
    Durum d;

    d.sistemAcik = 1;
    d.hataVar = 0;
    d.pilSeviye = 5;

    cout << "Sistem açık mı? " << d.sistemAcik << endl;
    cout << "Hata var mı? " << d.hataVar << endl;
    cout << "Pil seviyesi: " << d.pilSeviye << endl;

    return 0;
}
