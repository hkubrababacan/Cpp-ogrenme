#include <iostream>

class Lamba {
    private: 
    bool durum = false;

    public:
    void ac_kapa() {
        if (durum == false) {
            durum = true; 
            std::cout << "Lamba acildi.\n";
        }
        else {
            durum = false;
            std::cout << "Lamba kapatildi.\n";
        }
    }

    void yazdir() {
        std::cout << (durum ? "Acik" : "Kapali") << "\n";
    }
};

class Oda {
    private:
    Lamba lamba;

    public:
    void lamba_durumu_yazdir() {
        lamba.yazdir();
    }
    void lamba_degistir() {
        lamba.ac_kapa();
    }
};

class Ev {
    private:
    Oda oda1;
    Oda oda2;

    public:
    void ev_durumu_yazdir() {
        std::cout << "Ev durumu: \n";
        std::cout << "Oda 1: ";
        oda1.lamba_durumu_yazdir();
        std::cout << "Oda 2: ";
        oda2.lamba_durumu_yazdir();
    }

    void odadaki_lambayi_degistir(int oda_no) {
        switch (oda_no)
        {
        case 1:
            oda1.lamba_degistir();
            std::cout << "Oda 1'deki lambaya basildi.\n";
            break;
        case 2:
            oda2.lamba_degistir();
            std::cout << "Oda 2'deki lambaya basildi.\n";
            break;
        default:
            std::cout << "Gecersiz sayi girdiniz\n";
            break;
        }
    }
};

int main() {
    int secim;
    Ev ev;

    ev.ev_durumu_yazdir();

    while (true) {
    std::cout << "Hangi odadaki lambaya basmak istersiniz? (1 ya da 2 seciniz. Cikmak icin -1)\n";
    std::cin >> secim;

    if (secim == -1) {
        std::cout << "Cikis yapiliyor...\n";
        break;
    }

    ev.odadaki_lambayi_degistir(secim);
    ev.ev_durumu_yazdir();
    }

    return 0;
}