#include <iostream>

class Lamba {
    private:
    std::string isim;
    bool durum;

    public:
    Lamba(std::string h) {
        isim = h;
        durum= false;
    }

    bool get_durum() {
        return durum;
    }

    void ac() {
        durum = true;
        std::cout << isim << " lambasi acildi.\n";
    }

    void kapat() {
        durum = false;
        std::cout << isim << " lambasi kapatildi.\n";
    }
    
    void yazdir() const {
        std::cout << isim << " lambasi " << (durum ? "acik" : "kapali") << "\n";
    }
};

void lamba_durum(const Lamba& lamba) {
    lamba.yazdir();   
}

int main() {
    Lamba lamba("Salon");
    lamba.ac();
    lamba_durum(lamba);

    return 0;
}