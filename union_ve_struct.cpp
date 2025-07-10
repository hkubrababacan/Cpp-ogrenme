#include <iostream>

union Veri {
    uint8_t tum_veri;
    struct {
        unsigned int Led : 1;
        unsigned int Motor : 1;
        unsigned int Sistem_Hazir : 1;
        unsigned int Hata_var : 1;
        unsigned int Rezerve_alan : 4;
    } bayraklar;
};


void yazdirDurum(const Veri& veri) {
    if (veri.bayraklar.Hata_var == 1) {
        std::cout << "⚠️ Hata tespit edildi!\n";
    }

    if (veri.bayraklar.Led == 1 && veri.bayraklar.Motor == 1) {
        std::cout << "Sistem aktif.\n";
    }
}

int main() {
    Veri k;
    k.tum_veri = 0b00001101;

    std::cout << "LED durumu: " << k.bayraklar.Led << "\n";
    std::cout << "Motor durumu: " << k.bayraklar.Motor << "\n";
    std::cout << "Sistem Hazır: " << k.bayraklar.Sistem_Hazir << "\n";
    std::cout << "Hata Var: " << k.bayraklar.Hata_var << "\n\n";

    std::cout << "------------------------------------------------\n\n";

    
    yazdirDurum(k);

    return 0;
}
