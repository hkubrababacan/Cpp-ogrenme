#include <iostream>


void sicaklikUyari(int derece) {
    std::cout << "Sicaklik sinir asildi." << "Sicaaklik degeri: " << derece << "\n";
}
void nemUyari(int nem) {
    std::cout << "Nem sinir asildi." << "Nem degeri: " << nem << "\n";
}
void kontrolEt(int deger, int sinir, void (*uyariF)(int)) {
    if (deger > sinir) {
        uyariF(deger);
    }
}

int main() {
    int nem_okunan_deger = 80;
    int sicaklik_okunan_deger = 37;
    kontrolEt(nem_okunan_deger, 70, nemUyari);
    kontrolEt(sicaklik_okunan_deger, 35, sicaklikUyari);

    return 0;
}
