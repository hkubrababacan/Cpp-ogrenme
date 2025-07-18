#include <iostream>
#include <vector>
#include <thread>
#include <chrono>


class KontrolEdilebilir {
    public: 
    virtual void ac() = 0;
    virtual void kapat() = 0;
    virtual void yazdir() = 0;
    virtual ~KontrolEdilebilir() {}
};

class Motor : public KontrolEdilebilir {
    private:
    bool calisiyor = false;
    public:
    void ac() override {
        calisiyor = true;
        std::cout << "Motor calisiyor.\n";
    }
    void kapat() override {
        calisiyor = false;
        std::cout << "Motor calismiyor.\n";
    }
    void yazdir() override {
        std::cout << "motor suanda " << (calisiyor ? "calisiyor.\n" : "calismiyor.\n");
    }
};

class Radyo : public KontrolEdilebilir {
    private:
    bool durum = false;
    public:
    void ac() override {
        durum = true;
        std::cout << "Radyo acildi.\n";
    }
    void kapat() override {
        durum = false;
        std::cout << "Radyo kapatildi.\n";
    }
    void yazdir() override {
        std::cout << "Radyo suanda " << (durum ? "acik.\n" : "kapali.\n");
    }
};

class Klima : public KontrolEdilebilir {
    private:
    bool durum = false;
    public:
    void ac() override {
        durum = true;
        std::cout << "Klima acildi.\n";
    }
    void kapat() override {
        durum = false;
        std::cout << "Klima kapatildi.\n";
    }
    void yazdir() override {
        std::cout << "Klima suanda " << (durum ? "acik.\n" : "kapali.\n");
    }
};

class Buzzer : public KontrolEdilebilir {
    private:
    bool aktif = false;
    public:
    void ac() override {
        aktif = true;
        std::cout << "Buzzer: Bipp bipp (aktif)\n";
    }
    void kapat() override {
        aktif =  false;
        std::cout << "Buzzer: sessiz (pasif)\n";
    }
    void yazdir() override {
        std::cout << "Buzzer suanda " << (aktif ? "aktif.\n" : "pasif.\n");
    }
};

void SistemiAc(std::vector<KontrolEdilebilir*>& chz) {
    std::cout << "\n[!] Sistem Baslatiliyor...\n";
    for (auto c : chz) {
        c->ac();
        c->yazdir();
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "\n\n";
}

void SistemiKapat(std::vector<KontrolEdilebilir*>& chz) {
    std::cout << "\n[!] Sistem Kapatiliyor...\n";
    for (auto c : chz) {
        c->kapat();
        c->yazdir();
    }
    std::cout << "\n\n";
}

int main() {
    Motor m1;
    Radyo r1;
    Klima k1;
    Buzzer b1;

    std::vector<KontrolEdilebilir*> cihazlar = {&m1, &r1, &k1, &b1};

    char secim;
do {
    std::cout << "Sistemi [a]c / [k]apat / [q]uit? ";
    std::cin >> secim;

    if (secim == 'a') {
        SistemiAc(cihazlar);
    } else if (secim == 'k') {
        SistemiKapat(cihazlar);
    }
    } while (secim != 'q');


    return 0;
}