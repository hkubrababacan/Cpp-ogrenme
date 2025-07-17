#include <iostream>
#include <vector>

class Cihaz{
    public:
    virtual void ac() = 0;
    virtual void kapat() = 0;
    virtual void durum_yaz() = 0;
    virtual std::string get_isim() = 0;
    virtual std::string get_tur() = 0;
    virtual bool get_durum() = 0;
};

class Lamba : public Cihaz {
    private:
    std::string isim;
    std::string tur;
    bool durum;
    std::string renk;

    public:
    Lamba(std::string verilen_isim, std::string verilen_renk) {
        isim = verilen_isim;
        renk = verilen_renk;
        tur = "Lamba";
        durum = false;
    }
    
    void ac() override {
        durum = true;
        std::cout << renk << " renginde " << isim << " isimli " << tur << " acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << renk << " renginde " << isim << " isimli " << tur << " kapatildi.\n";
    }

    void durum_yaz() override {
        std::cout << renk << " renginde " << isim << " isimli " << tur << " suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    std::string get_isim() override {
        return isim;
    }

    std::string get_tur() override {
        return tur;
    }

    bool get_durum() override {
        return durum;
    }

    std::string get_renk() {
        return renk;
    }
};

class Fan : public Cihaz {
    private:
    std::string isim;
    std::string tur;
    bool durum;
    int hiz_seviyesi;

    public:
    Fan(std::string verilen_isim, int verilen_hiz) {
        isim = verilen_isim;
        hiz_seviyesi = verilen_hiz;
        tur = "Fan";
        durum = false;
    }
    
    void ac() override {
        durum = true;
        std::cout << (durum ? hiz_seviyesi : 0) << " hizinda " << isim << " isimli " << tur << " acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << (durum ? hiz_seviyesi : 0) << " hizinda " << isim << " isimli " << tur << " kapatildi.\n";
    }

    void durum_yaz() override {
        std::cout << (durum ? hiz_seviyesi : 0) << " hizinda " << isim << " isimli " << tur << " suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    std::string get_isim() override {
        return isim;
    }

    std::string get_tur() override {
        return tur;
    }

    bool get_durum() override {
        return durum;
    }
    int get_hiz() {
        return hiz_seviyesi;
    }
};

class Klima : public Cihaz {
    private:
    std::string isim;
    std::string tur;
    bool durum;
    int sicaklik;

    public:
    Klima(std::string verilen_isim, int verilen_sicaklik) {
        isim = verilen_isim;
        sicaklik = verilen_sicaklik;
        tur = "Klima";
        durum = false;
    }
    
    void ac() override {
        durum = true;
        sicaklik = 20;
        std::cout << (durum ? sicaklik : 0) << " sicakliğinda " << isim << " isimli " << tur << " acildi.\n";
    }

    void kapat() override {
        durum = false;
        sicaklik = 0;
        std::cout << (durum ? sicaklik : 0) << " sicakliğinda " << isim << " isimli " << tur << " kapatildi.\n";
    }

    void durum_yaz() override {
        std::cout << (durum ? sicaklik : 0) << " sicakliğinda " << isim << " isimli " << tur << " suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    std::string get_isim() override {
        return isim;
    }

    std::string get_tur() override {
        return tur;
    }

    bool get_durum() override {
        return durum;
    }
    int get_sicaklik() {
        return sicaklik;
    }
};

class Cihaz_Kontrolcu {
    private:
    std::vector<Cihaz*> Cihazlar;

    public:
    void cihaz_ekle(Cihaz* yeni_chz) {
        Cihazlar.push_back(yeni_chz);
    }

    void tumunu_ac() {
        for (auto c : Cihazlar) {
            c->ac();
        }
    }

    void tumunu_kapat() {
        for (auto c : Cihazlar) {
            c->kapat();
        }
    }

    void durum_yazdir() {
        for (auto c : Cihazlar) {
            c->durum_yaz();
        }
    }
};

int main() {
    Cihaz_Kontrolcu chz;
    chz.cihaz_ekle(new Lamba("l1", "sari"));
    chz.cihaz_ekle(new Lamba("l2", "beyaz"));
    chz.cihaz_ekle(new Fan("f1", 50));
    chz.cihaz_ekle(new Fan("f2", 100));
    chz.cihaz_ekle(new Klima("k1", 20));
    chz.cihaz_ekle(new Klima("k2", 15));

    chz.tumunu_ac();

    chz.durum_yazdir();

    return 0;
}