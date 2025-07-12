#include <iostream>

class Sensor {
    private:
    std::string isim;
    int deger;

    public:
    Sensor(std::string verilen_isim, int verilen_sayi) {
        isim =verilen_isim;
        deger = verilen_sayi;
    }

    void yazdir() {
        std::cout << isim << " degeri: " << deger << " \n";
    }

    ~Sensor() {
        std::cout << isim << " yok edildi\n";
    }
};

int main() {
    Sensor isi("Isı", 27);
    Sensor nem("Nem", 50);

    isi.yazdir();
    nem.yazdir(); 
    
    return 0;
}