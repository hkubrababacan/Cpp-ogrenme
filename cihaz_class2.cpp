#include <iostream>
#include <vector>

// ----- TEMEL SINIF -----
class Cihaz {
protected:
    std::string isim;
    bool durum;

public:
    Cihaz(std::string verilen_isim) {
        isim = verilen_isim;
        durum = false;
    }

    virtual void ac() {
        durum = true;
    }

    virtual void kapat() {
        durum = false;
    }

    std::string get_isim() const {
        return isim;
    }

    bool get_durum() const {
        return durum;
    }

    virtual std::string get_tur() const = 0; // SOYUT fonksiyon

    virtual void yazdir() const = 0; // SOYUT fonksiyon

    virtual void isim_yazdir() const = 0; // SOYUT fonksiyon
};

// ----- ALT SINIF: LAMBA -----
class Lamba : public Cihaz {
public:
    Lamba(std::string verilen_isim) : Cihaz(verilen_isim) {}

    void ac() override {
        durum = true;
        std::cout << isim << " (Tur: Lamba) acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " (Tur: Lamba) kapatildi.\n";
    }

    std::string get_tur() const override {
        return "Lamba";
    }

    void yazdir() const override {
        std::cout << isim << " (Tur: Lamba) suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    void isim_yazdir() const override {
        std::cout << isim << "\n";
    }
};

// ----- ALT SINIF: FAN -----
class Fan : public Cihaz {
public:
    Fan(std::string verilen_isim) : Cihaz(verilen_isim) {}

    void ac() override {
        durum = true;
        std::cout << isim << " (Tur: Fan) acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " (Tur: Fan) kapatildi.\n";
    }

    std::string get_tur() const override {
        return "Fan";
    }

    void yazdir() const override {
        std::cout << isim << " (Tur: Fan) suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    void isim_yazdir() const override {
        std::cout << isim << "\n";
    }
};

class Televizyon : public Cihaz {
public:
    Televizyon(std::string verilen_isim) : Cihaz(verilen_isim) {}

    void ac() override {
        durum = true;
        std::cout << isim << " (Tur: Televizyon) acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " (Tur: Televizyon) kapatildi.\n";
    }

    std::string get_tur() const override {
        return "Televizyon";
    }

    void yazdir() const override {
        std::cout << isim << " (Tur: Televizyon) suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    void isim_yazdir() const override {
        std::cout << isim << "\n";
    }
};

class Alarm : public Cihaz {
public:
    Alarm(std::string verilen_isim) : Cihaz(verilen_isim) {}

    void ac() override {
        durum = true;
        std::cout << isim << " (Tur: Alarm) acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " (Tur: Alarm) kapatildi.\n";
    }

    std::string get_tur() const override {
        return "Alarm";
    }

    void yazdir() const override {
        std::cout << isim << " (Tur: Alarm) suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    void isim_yazdir() const override {
        std::cout << isim << "\n";
    }
};

class Klima : public Cihaz {
public:
    Klima(std::string verilen_isim) : Cihaz(verilen_isim) {}

    void ac() override {
        durum = true;
        std::cout << isim << " (Tur: Klima) acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " (Tur: Klima) kapatildi.\n";
    }

    std::string get_tur() const override {
        return "Klima";
    }

    void yazdir() const override {
        std::cout << isim << " (Tur: Klima) suanda " << (durum ? "acik" : "kapali") << "\n";
    }

    void isim_yazdir() const override {
        std::cout << isim << "\n";
    }
};

// ----- KONTROL PANELİ SINIFI -----
class Kontrol_Paneli {
private:
    std::vector<Cihaz*> cihazlar;

public:
    void cihazEkle(Cihaz* k) {
        cihazlar.push_back(k);
    }

    void hepsini_ac() {
        for (auto& c : cihazlar) {
            c->ac();
        }
    }

    void hepsini_kapat() {
        for (auto& c : cihazlar) {
            c->kapat();
        }
    }

    void durumlari_yazdir() const {
        std::cout << "----------CIHAZ DURUMLARI------------\n";
        for (const auto& c : cihazlar) {
            c->yazdir();
        }
    }

    void cihaz_ac(const std::string& isim) {
        for (auto& c : cihazlar) {
            if (c->get_isim() == isim) {
                c->ac();
                return;
            }
        }
        std::cout << isim << " adinda bir cihaz bulunamadi!\n";
    }

    void cihaz_kapat(const std::string& isim) {
        for (auto& c : cihazlar) {
            if (c->get_isim() == isim) {
                c->kapat();
                return;
            }
        }
        std::cout << isim << " adinda bir cihaz bulunamadi!\n";
    }

    void cihazlariTureGoreListele(const std::string& tur_adi) const {
        std::cout << "----" << tur_adi << " turundeki cihazlar----\n";
        for (const auto& c : cihazlar) {
            if (c->get_tur() == tur_adi) {
                c->yazdir();
            }
        }
    }

    void acikCihazlariListele() const {
        std::cout << "------- Acik Cihazlar-------\n";
        for (const auto& c : cihazlar) {
            if (c->get_durum()) {
                c->yazdir();
            }
        }
    }

    void isimleri_listele() const {
        std::cout << "----------Cihazlarin isimleri-------\n";
        for (const auto& c : cihazlar) {
            c->isim_yazdir();
        }

    }

    void temizle() {
        for (auto& c : cihazlar) {
            delete c;
        }
        cihazlar.clear();
    }

};

int main() {
    Kontrol_Paneli panel;

    Lamba* l1 = new Lamba("lamba1");
    Fan* f1 = new Fan("fan1");
    Klima* k1 = new Klima("klima1");
    Televizyon* t1 = new Televizyon("televizyon1");
    Alarm* a1 = new Alarm("alarm1");

    panel.cihazEkle(l1);
    panel.cihazEkle(f1);
    panel.cihazEkle(k1);
    panel.cihazEkle(t1);
    panel.cihazEkle(a1);

    std::string alinan_isim;
    int yapilacak_islem;

    while (true) {
        std::cout << "Yapmak istediginiz islemi seciniz.\n";
        std::cout << "1 - Cihaz ac\n";
        std::cout << "2 - Cihaz kapat\n";
        std::cout << "3 - Tum cihazlari ac\n";
        std::cout << "4 - Tum cihazlari kapat\n";
        std::cout << "5 - Acik cihazlari listele\n";
        std::cout << "6 - Ture gore listele\n";
        std::cout << "7 - Tum cihazlari yazdir\n";
        std::cout << "8 - Yeni cihaz girisi yap\n";
        std::cout << "9 - Cihazlarin isimlerini yazdir\n";
        std::cout << "0 - Cikis\n";
        std::cout << "-> ";
        std::cin >> yapilacak_islem;

        if (yapilacak_islem == 1) {
            std::cout << "Islem yapilacak cihazin ismini giriniz. (Cikmak icin 'q' tuslayiniz.)\n";
            std::cout << "-> ";
            std::cin >> alinan_isim;

            if (alinan_isim == "q") {
                std::cout << "Cikis yapiliyor...\n";
                break;
            }
            panel.cihaz_ac(alinan_isim);
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 2) {
            std::cout << "Islem yapilacak cihazin ismini giriniz. (Cikmak icin 'q' tuslayiniz.)\n";
            std::cout << "-> ";
            std::cin >> alinan_isim;

            if (alinan_isim == "q") {
                std::cout << "Cikis yapiliyor...\n";
                break;
            }
            panel.cihaz_kapat(alinan_isim);
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 3) {
            panel.hepsini_ac();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 4) {
            panel.hepsini_kapat();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 5) {
            panel.acikCihazlariListele();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 6) {
            std::string tur;
            std::cout << "Listelemek istediginiz turu giriniz.\n";
            std::cout << "-> ";
            std::cin >> tur;
            panel.cihazlariTureGoreListele(tur);
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 7) {
            panel.durumlari_yazdir();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 8) {
            std::string verilecek_tur;
            std::string verilecek_isim;

            std::cout << "Yeni cihaz icin turu belirleyiniz.('Lamba', 'Fan', 'Klima', 'Televizyon' ya da 'Alarm' secebilirsiniz.)\n";
            std::cout << "-> ";
            std::cin >> verilecek_tur;
            std::cout << "Yeni cihaz icin isim belirleyiniz.\n";
            std::cout << "-> ";
            std::cin.ignore(); 
            std::getline(std::cin, verilecek_isim);

            if (verilecek_tur == "Lamba") {
                Cihaz* yeni = new Lamba(verilecek_isim);
                panel.cihazEkle(yeni);
            } else if (verilecek_tur == "Fan") {
                Cihaz* yeni = new Fan(verilecek_isim);
                panel.cihazEkle(yeni);
            } else {
            std::cout << "Gecersiz cihaz turu!\n";
            }

        }

        else if (yapilacak_islem == 9) {
            panel.isimleri_listele();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 0) {
            std::cout << "Cikis yapiliyor...\n";
            std::cout << "\n\n";
            break;
        }

        else {
            std::cout << "Gecersiz bir islem sectiniz. Tekrar deneyiniz.\n";
            std::cout << "\n\n";
        }

    }

    panel.temizle();

    return 0;
}
