#include <iostream>

class Buton {
    private:
    std::string isim;
    bool basildi_mi;

    public:
    Buton(std::string a) {
        isim = a;
        basildi_mi = false;
    }

    void bas() {
        basildi_mi = true;
        std::cout << isim << " butonuna basildi.\n";
        std::cout << isim << " suanda " << (basildi_mi ? "acik" : "kapali") << "\n";
    }

    void yazdir() {
        std::cout << isim << " suanda " <<  (basildi_mi ? "acik" : "kapali") << "\n";
    }
};

class Kumanda {
    private:
    Buton btn1;
    Buton btn2;

    public:
   Kumanda(std::string isim1, std::string isim2) : btn1(isim1), btn2(isim2) {}

    void Kumanda_bilgisi() {
        std::cout << "Kumanda bilgisi: \n";
        btn1.yazdir();
        btn2.yazdir();
    }

    void Butona_bas(int number) {
        switch (number) {
            case 1:
                btn1.bas();
                break;
            case 2: 
                btn2.bas();
                break;
            default :
                std::cout << "Gecersiz sayi girdiniz.\n";
        }
    }
};

int main() {
    int secim;
    Kumanda kmd1("Ses" , "Kanal");

    kmd1.Kumanda_bilgisi();
    std::cout << "Hangi butona basmak istiyorsunuz. (1 ya da 2 seciniz)\n";
    std::cin >> secim;
    kmd1.Butona_bas(secim);
    kmd1.Kumanda_bilgisi();

    return 0;

}