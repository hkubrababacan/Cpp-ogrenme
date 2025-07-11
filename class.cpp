#include <iostream>

class Cihaz {
    private: 
    std::string isim;
    bool durum;

    public:
    Cihaz(std::string verilen_isim) {
        isim = verilen_isim;
        durum = false;
    }

    void ac() {
        durum = true;
        std::cout << isim << " açıldı.\n";
    }

    
    void kapat() {
        durum = false;
        std::cout << isim << " kapatıldı.\n";
    }

    void yazdir() {
        std::cout << isim << " şuanda" << (durum ? " açık." : " kapalı") << "\n";
    }

    bool durum_getir() {
        return durum;
    }

    void durum_degistir(bool yeni_durum) {
        durum = yeni_durum;
    }

};

int main() {
    Cihaz led("Led");

    led.yazdir();
    led.ac();
    std::cout << "--------------\n\n";
    led.yazdir();
    led.kapat();
    std::cout << "--------------\n\n";
    led.yazdir();

    Cihaz telefon("Telefon");

    telefon.ac();
    telefon.yazdir();

    telefon.durum_degistir(false);

    if (telefon.durum_getir()) {
        std::cout << "şuanda açık";
    }
    else {
        std::cout << "Şuanda kapalı";
    }

    return 0; 
}