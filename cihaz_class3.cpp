#include <iostream>
#include <vector>

class Cihaz {
    protected:
    std::string isim;
    bool durum;

    public:
    Cihaz(std::string verilen_isim) {
        isim = verilen_isim;
        durum = false;
    }

    virtual void ac() = 0;
    virtual void kapat() = 0;
    virtual void durum_yazdir() = 0;
    virtual ~Cihaz() {}
};

class Sensor : public Cihaz {
    public:
    Sensor(std::string ad) : Cihaz(ad) {}

    void ac() override {
        durum = true;
        std::cout << isim << " sensor acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " sensor kapatildi.\n";
    }

    void durum_yazdir() override {
        std::cout << isim << " sensor suanda " << (durum ? "acik" : "kapali") << "\n";
    }
};

class Motor : public Cihaz {
    public:
    Motor(std::string ad) : Cihaz(ad) {}

    void ac() override {
        durum = true;
        std::cout << isim << " motor acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " motor kapatildi.\n";
    }

    void durum_yazdir() override {
        std::cout << isim << " motor suanda " << (durum ? "acik" : "kapali") << "\n";
    }
};

class Lamba : public Cihaz {
    public:
    Lamba(std::string ad) : Cihaz(ad) {}

    void ac() override {
        durum = true;
        std::cout << isim << " lamba acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " lamba kapatildi.\n";
    }

    void durum_yazdir() override {
        std::cout << isim << " lamba suanda " << (durum ? "acik" : "kapali") << "\n";
    }
};

int main() {
    std::vector<Cihaz*> Cihazlar;

    Cihazlar.push_back(new Sensor("s1"));
    Cihazlar.push_back(new Sensor("s2"));
    Cihazlar.push_back(new Motor("m1"));
    Cihazlar.push_back(new Motor("m2"));
    Cihazlar.push_back(new Lamba("l1"));
    Cihazlar.push_back(new Lamba("l2"));

    std::cout << "Tum cihazlari aciyoruz...\n";
    for (auto c : Cihazlar) {
        c->ac();
    }
    std::cout << "\n\n";

    std::cout << "Cihazlarin durumlarini yazdiriyoruz.\n";
    for (auto c : Cihazlar) {
        c->durum_yazdir();
    }

    std::cout << "\n\n";

    std::cout << "Tum cihazlari kapatiyoruz...\n";
    for (auto c : Cihazlar) {
        c->kapat();
    }

    std::cout << "\n\n";

    std::cout << "\n--- Bellek Temizleniyor ---\n";
    for (auto c : Cihazlar) {
        delete c;
    }

    return 0;
}