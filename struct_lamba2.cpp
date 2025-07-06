#include <iostream>
#include <string> // string tanımı için

enum Durum { KAPALI, ACIK };

struct Lamba {
    std::string isim;
    bool isLED;
    Durum durum;

    void yazdir() {
        std::string led_normal;
        std::string acik_kapali;

        if (isLED == true) {
            led_normal = "LED";
        } else {
            led_normal = "Normal";
        }

        if (durum == KAPALI) {
            acik_kapali = "Kapalı";
        } else {
            acik_kapali = "Açık";
        }

        std::cout << isim << " (" << led_normal << ") şu anda " << acik_kapali << "\n";
    }
};

int main() {
    Lamba lamba1, lamba2, lamba3;

    std::cin.ignore(); // getline'dan önce varsa cin temizlik

    std::cout << "1. lambanin ismini giriniz: ";
    std::getline(std::cin, lamba1.isim);

    std::cout << "2. lambanin ismini giriniz: ";
    std::getline(std::cin, lamba2.isim);

    std::cout << "3. lambanin ismini giriniz: ";
    std::getline(std::cin, lamba3.isim);

    char secim;
    std::cout << lamba1.isim << " LED mi? (e/h): ";
    std::cin >> secim;
    lamba1.isLED = (secim == 'e' || secim == 'E');

    std::cout << lamba2.isim << " LED mi? (e/h): ";
    std::cin >> secim;
    lamba2.isLED = (secim == 'e' || secim == 'E');

    std::cout << lamba3.isim << " LED mi? (e/h): ";
    std::cin >> secim;
    lamba3.isLED = (secim == 'e' || secim == 'E');

   
    lamba1.durum = KAPALI;
    lamba2.durum = KAPALI;
    lamba3.durum = KAPALI;

    char sec;
    std::cout << "\nLamba açma işlemi başlıyor...\n";
    while (true) {
        std::cout << "\nHangi lambayi acmak istersiniz? (1 / 2 / 3 - bitirmek için h): ";
        std::cin >> sec;

        if (sec == 'h' || sec == 'H') break;

        switch (sec) {
            case '1':
                lamba1.durum = ACIK;
                break;
            case '2':
                lamba2.durum = ACIK;
                break;
            case '3':
                lamba3.durum = ACIK;
                break;
            default:
                std::cout << "Geçersiz seçim yaptınız.\n";
                break;
        }
    }

    std::cout << "\n--- Lamba Durumlari ---\n";
    lamba1.yazdir();
    lamba2.yazdir();
    lamba3.yazdir();

    return 0;
}
