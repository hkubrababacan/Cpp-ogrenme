#include <iostream>
#include <string>

enum Durum {ACIK , KAPALI};

struct Lamba {
    std::string isim;
    bool isLed;
    Durum durum;

    void yazdir() {
        std::string led_normal;
        std::string acik_kapali;
        if (isLed == true) {
            led_normal = "Led";
        }

         else {
            led_normal = "Normal";
        }

        if (durum == ACIK) {
            acik_kapali = "Açık";
        } 
    
        else {
            acik_kapali = "Kapalı";
        }
        std::cout << isim << "(" << led_normal << ") şuanda " << acik_kapali << "\n";
    }
};

struct kontrol_paneli {
    Lamba lambalar[3];

    void hepsini_ac() {
        for (int i = 0; i < 3; i++) {
            lambalar[i].durum = ACIK;
        }
    }

    void hepsini_kapat() {
        for (int i = 0; i < 3; i++) {
            lambalar[i].durum = KAPALI;
        }
    }

    void yazdir() {
        for (int i = 0; i < 3; i++) {
            lambalar[i].yazdir();
        }
    }
};

int main() {
    kontrol_paneli panel;
    panel.lambalar[0] = {"Salon", true, ACIK};
    panel.lambalar[1] = {"Mutfak", false, ACIK};
    panel.lambalar[2] = {"Çocuk odası", true, KAPALI};

    std::cout << "Lambaların ilk durumları \n";
    panel.yazdir();

    std::cout << "Lambaların hepsi açılıyor...\n";
    panel.hepsini_ac();
    std::cout << "Lambalar açıldı\n";
    panel.yazdir();

    std::cout << "Lambaların hepsi kapatılıyor...\n";
    panel.hepsini_kapat();
    std::cout << "Lambalar kapatıldı\n";
    panel.yazdir();

    return 0;
}