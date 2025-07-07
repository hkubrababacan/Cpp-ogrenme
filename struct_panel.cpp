#include <iostream>
#include <string>
#include <iomanip>

#define LAMBA_SAYISI 4

enum Durum { ACIK, KAPALI };

struct Lamba {
    std::string isim;
    bool isLED;
    Durum durum;

    void yazdir() {
        std::string led_normal = isLED ? "LED" : "Normal";
        std::string acik_kapali = (durum == ACIK) ? "Açık" : "Kapalı";

        std::cout << std::setw(15) << isim
                  << std::setw(10) << led_normal
                  << std::setw(10) << acik_kapali << "\n";
    }
};

struct KontrolPaneli {
    Lamba lambalar[LAMBA_SAYISI];

    void hepsini_ac() {
        for (int i = 0; i < LAMBA_SAYISI; i++) {
            lambalar[i].durum = ACIK;
        }
    }

    void hepsini_kapat() {
        for (int i = 0; i < LAMBA_SAYISI; i++) {
            lambalar[i].durum = KAPALI;
        }
    }

    void sadece_ac(int secim) {
        if (secim >= 0 && secim < LAMBA_SAYISI) {
            lambalar[secim].durum = ACIK;
        }
    }

    void sadece_kapat(int secim) {
        if (secim >= 0 && secim < LAMBA_SAYISI)
            lambalar[secim].durum = KAPALI;
    }

    void yazdir() {
        std::cout << std::setw(15) << "İSİM"
                  << std::setw(10) << "TÜR"
                  << std::setw(10) << "DURUM" << "\n";
        std::cout << "----------------------------------\n";
        for (int i = 0; i < LAMBA_SAYISI; i++) {
            lambalar[i].yazdir();
        }
        std::cout << "\n";
    }
};

int main() {
    KontrolPaneli panel;
    panel.lambalar[0] = {"Salon", true, ACIK};
    panel.lambalar[1] = {"Mutfak", false, KAPALI};
    panel.lambalar[2] = {"Çocuk Odası", true, KAPALI};
    panel.lambalar[3] = {"Yatak Odası", false, ACIK};

    std::cout << "İlk durum:\n";
    panel.yazdir();

    int secim;
    std::cout << "Hangi lambayı açmak istersiniz? (0:Salon, 1:Mutfak, 2:Çocuk Odası, 3:Yatak Odası): ";
    std::cin >> secim;
    panel.sadece_ac(secim);

    std::cout << "Yeni durum:\n";
    panel.yazdir();

    return 0;
}
