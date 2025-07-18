#include <iostream>
#include <vector>

class cihaz {
    public:
    virtual void ac() = 0;
    virtual void kapat() = 0;
    virtual void yazdir() = 0;
};

class lamba : public cihaz {
    private:
    bool durum = false;
    public:
    void ac() override {
        durum = true;
        std::cout << "lamba acildi.\n"; 
    }

    void kapat() override {
        durum = false;
        std::cout << "lamba kapatildi.\n";
    }

    void yazdir() override {
        std::cout << "lamba suanda " << (durum ? "acik" : "kapali") << "\n";
    }
};

class fan : public cihaz {
    private:
    bool durum = false;
    public:
    void ac() override {
        durum = true;
        std::cout << "fan acildi.\n"; 
    }

    void kapat() override {
        durum = false;
        std::cout << "fan kapatildi.\n";
    }

    void yazdir() override {
        std::cout << "fan suanda " << (durum ? "acik" : "kapali") << "\n";
    }
};

void sistemBaslat(std::vector<cihaz*>& cihazlar) {
    for (auto c : cihazlar) {
        c->ac();
        c->yazdir();
    }
}

void sistemKapat(std::vector<cihaz*>& cihazlar) {
    for (auto c : cihazlar) {
        c->kapat();
        c->yazdir();
    }
}

int main() {
    lamba l1;
    fan f1;

    std::vector<cihaz*> chz = {&l1, &f1};

    sistemBaslat(chz);

    return 0;
}