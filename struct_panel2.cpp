#include <iostream>
#include <string>
#include <iomanip>

#define LAMBA_SAYISI 4

enum Durum {ACIK, KAPALI};

struct Lamba {
    std::string isim;
    bool isLED;
    Durum durum;

    void yazdir() {
        std::string led_normal = isLED ? "LED" : "Normal";
        std::string acik_kapali = (durum == ACIK) ? "Açık" : "Kapalı";
        std::string ikon = (durum == ACIK) ? "🟢" : "🔴";

        std::cout << std::setw(15) << isim
                  << std::setw(10) << led_normal
                  << std::setw(10) << acik_kapali 
                  << " " << ikon << "\n";
    }
};

struct Kontrol_Paneli {
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

    void sadece_ac(int index) {
        if (index >= 0 && index < LAMBA_SAYISI) {
            lambalar[index].durum = ACIK;
        }
    }

     void sadece_kapat(int index) {
        if (index >= 0 && index < LAMBA_SAYISI) {
            lambalar[index].durum = KAPALI;
        }
    }

    void yazdir() {
        std::cout << std::setw(15) << "ISIM"
                  << std::setw(10) << "TUR"
                  << std::setw(10) << "DURUM"
                  << "   " << "İKON\n";
        
        std::cout << "--------------------------------------\n";
        for (int i = 0; i < LAMBA_SAYISI; i++) {
            lambalar[i].yazdir();
        }
        std::cout << "\n";
    }
};

int main() {
    Kontrol_Paneli panel;
    panel.lambalar[0] = {"Salon", true, ACIK};
    panel.lambalar[1] = {"Mutfak", false, KAPALI};
    panel.lambalar[2] = {"Yatak Odası", false, ACIK};
    panel.lambalar[3] = {"Çocuk Odası", true, KAPALI};

    int secim = 0;
    int islem = 0;

    std::cout << "Başlangıç Durumu:\n";
    panel.yazdir();

    while(true) {
        std::cout << "İşlem yapmak istediğiniz odayı seçiniz. (0:Salon, 1:Mutfak, 2:Yatak Odası, 3:Çocuk Odası, -1:ÇIK)\n";
        std::cin >> secim;

        if (secim == -1) {
            std::cout << "Çıkış yapılıyor...\n";
            break;
        }

        if (secim < 0 || secim >= LAMBA_SAYISI) {
            std::cout << "Geçersiz işlem girdiniz. Tekrar deneyin... \n\n";
            continue;
        }

        std::cout << "Yapmak istediğiniz işlemi seçiniz. (1:Aç, 2:Kapat)\n";
        std::cin >> islem;

        if (islem == 1) {
            panel.sadece_ac(secim);
        }

        else if (islem == 2) {
            panel.sadece_kapat(secim);
        }

        else {
            std::cout << "Geçersiz işlem girdiniz\n";
        }

        std::cout << "\nGüncel durum:\n";
        panel.yazdir();
    }
}