#include <iostream>
#include <vector>

class Cihaz {
    private:
    std::string isim;
    bool durum;

    public:
    Cihaz(std::string yeni_isim) {
        isim = yeni_isim;
        durum = false;
    }

    void ac() {
        durum = true;
        std::cout << isim << " suanda aciliyor\n";
    }

    void kapat() {
        durum = false;
        std::cout << isim << " suanda kapatiliyor\n";
    }

    void yazdir() {
        std::cout << isim << " suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    bool get_durum() {
        return durum;
    }

    void yeni_durum(bool yeni_durum) {
        durum = yeni_durum;
    }
};

int main() {
    std::vector<Cihaz> Cihazlar = {
        Cihaz("LED"),
        Cihaz("Motor"),
        Cihaz("Fan"),
        Cihaz("Isıtıcı")
    };

    for (auto& cihaz : Cihazlar){
        cihaz.ac();
    }

    for (auto& cihaz : Cihazlar){
        cihaz.yazdir();
    }

    return 0;
}