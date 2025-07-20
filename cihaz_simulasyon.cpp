#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

class ICihaz {
public:
    virtual void ac() = 0;
    virtual void kapat() = 0;
    virtual void durum_bilgi() = 0;
    virtual std::string get_isim() = 0;
    virtual std::string get_tur() = 0;
    virtual void deger_guncelle() = 0;
    virtual ~ICihaz() {}
};

class Lamba : public ICihaz {
    std::string isim;
    bool durum = false;
    std::string tur = "Lamba";

public:
    Lamba(std::string verilen_isim) : isim(verilen_isim) {}

    void ac() override {
        durum = true;
        std::cout << isim << " ismindeki lamba acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " ismindeki lamba kapatildi.\n";
    }

    void durum_bilgi() override {
        std::cout << isim << " ismindeki lamba suanda " << (durum ? "acik.\n" : "kapali.\n");
    }

    std::string get_isim() override {
        return isim;
    }

    std::string get_tur() override {
        return tur;
    }

    void deger_guncelle() override {}
};

class Fan : public ICihaz {
    std::string isim;
    bool durum = false;
    std::string tur = "Fan";

public:
    Fan(std::string verilen_isim) : isim(verilen_isim) {}

    void ac() override {
        durum = true;
        std::cout << isim << " ismindeki fan acildi.\n";
    }

    void kapat() override {
        durum = false;
        std::cout << isim << " ismindeki fan kapatildi.\n";
    }

    void durum_bilgi() override {
        std::cout << isim << " ismindeki fan suanda " << (durum ? "acik.\n" : "kapali.\n");
    }

    std::string get_isim() override {
        return isim;
    }

    std::string get_tur() override {
        return tur;
    }

    void deger_guncelle() override {}
};

class Sensor : public ICihaz {
    std::string isim;
    bool aktif;
    int deger;
    std::string tur = "Sensor";

public:
    Sensor(std::string verilen_isim) : isim(verilen_isim) {
        aktif = true;
        srand(time(0)); // sadece 1 kez çağrılmalı (main içinde daha iyi)
        deger = rand() % 101;
    }

    void ac() override {
        aktif = true;
    }

    void kapat() override {
        aktif = false;
    }

    void durum_bilgi() override {
        std::cout << isim << " ismindeki sensor " << (aktif ? "aktif" : "kapali") << " - deger: " << deger << "\n";
    }

    std::string get_isim() override {
        return isim;
    }

    void deger_guncelle() override {
        srand(time(0)); // sadece 1 kez çağrılmalı (main içinde daha iyi)
        deger = rand() % 101;
        std::cout << isim << " isimli sensorun yeni degeri: " << deger << "\n";
    }

    std::string get_tur() override {
        return tur;
    }
};

class KontrolPaneli {
    std::vector<ICihaz*> chz;

public:
    void cihaz_ekle(ICihaz* cihaz) {
        chz.push_back(cihaz);
    }

    void tumunu_ac() {
        std::cout << "Tum cihazlar aciliyor...\n";
        for (auto c : chz) c->ac();
    }

    void tumunu_kapat() {
        std::cout << "Tum cihazlar kapatiliyor...\n";
        for (auto c : chz) c->kapat();
    }

    void tumunu_yazdir() {
        std::cout << "Tum cihazlarin durumu:\n";
        for (auto c : chz) {
            c->durum_bilgi();
        }
    }


    void secileni_ac(std::string isim) {
        for (auto c : chz) {
            if (c->get_isim() == isim)
                c->ac();
        }
    }

    void secileni_kapat(std::string isim) {
        for (auto c : chz) {
            if (c->get_isim() == isim)
                c->kapat();
        }
    }

    void isimleri_listele() {
        for (auto c : chz) {
            std::cout << c->get_isim() << "\n";
        }
    }

    void sensorleri_guncelle() {
        for (auto c : chz) {
            Sensor* s = dynamic_cast<Sensor*>(c);
            if (s != nullptr) {
                s->deger_guncelle();
            }
        }
    }

    void cihazlariTureGoreListele(std::string tur) {
        for (auto c : chz) {
            if (c->get_tur() == tur) {
                c->durum_bilgi();
            }
        }
    }
};

int main() {
    srand(time(0)); 
    Lamba* l1 = new Lamba("l1");
    Fan* f1 = new Fan("f1");
    Sensor* s1 = new Sensor("s1");

    KontrolPaneli panel;
    panel.cihaz_ekle(l1);
    panel.cihaz_ekle(f1);
    panel.cihaz_ekle(s1);

    int yapilacak_islem;
    while (true) {
        std::cout << "Yapmak istediginiz islemi seciniz.\n";
        std::cout << "1 - Tum cihazlari ac\n";
        std::cout << "2 - Tum cihazlari kapat\n"; 
        std::cout << "3 - Tum cihazlari yazdir\n"; 
        std::cout << "4 - Cihaz ac\n";
        std::cout << "5 - Cihaz kapat\n";
        std::cout << "6 - Sensor degerini güncelle.\n";
        std::cout << "7 - Yeni cihaz ekle.\n";
        std::cout << "8 - Isimlere gore sirala\n";
        std::cout << "9 - Turlere gore sirala\n";
        std::cout << "0 - Cikis\n";
        std::cout << "-> ";
        std::cin >> yapilacak_islem;

        if (yapilacak_islem == 1) {
            panel.tumunu_ac();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 2) {
            panel.tumunu_kapat();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 3) {
            panel.tumunu_yazdir();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 4) {
            std::string alinan_isim;
            std::cout << "Islem yapilacak cihazin ismini giriniz. (Cikmak icin 'q' tuslayiniz.)\n";
            std::cout << "-> ";
            std::cin >> alinan_isim;

            if (alinan_isim == "q") {
                std::cout << "Cikis yapiliyor...\n";
                break;
            }
            panel.secileni_ac(alinan_isim);
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 5) {
            std::string alinan_isim;
            std::cout << "Islem yapilacak cihazin ismini giriniz. (Cikmak icin 'q' tuslayiniz.)\n";
            std::cout << "-> ";
            std::cin >> alinan_isim;

            if (alinan_isim == "q") {
                std::cout << "Cikis yapiliyor...\n";
                break;
            }
            panel.secileni_kapat(alinan_isim);
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 6) {
            panel.sensorleri_guncelle();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 7) {
            std::string verilecek_tur;
            std::string verilecek_isim;

            std::cout << "Yeni cihaz icin turu belirleyiniz.('Lamba', 'Fan' ya da 'Sensor' secebilirsiniz.)\n";
            std::cout << "-> ";
            std::cin >> verilecek_tur;
            std::cout << "Yeni cihaz icin isim belirleyiniz.\n";
            std::cout << "-> ";
            std::cin.ignore(); 
            std::getline(std::cin, verilecek_isim);

            if (verilecek_tur == "Lamba") {
                Lamba* yeni = new Lamba(verilecek_isim);
                panel.cihaz_ekle(yeni);
            } else if (verilecek_tur == "Fan") {
                Fan* yeni = new Fan(verilecek_isim);
                panel.cihaz_ekle(yeni);
            } else if (verilecek_tur == "Sensor") {
                Sensor* yeni = new Sensor(verilecek_isim);
                panel.cihaz_ekle(yeni);
            } else {
            std::cout << "Gecersiz cihaz turu!\n";
            }

        }

        else if (yapilacak_islem == 8) {
            panel.isimleri_listele();
            std::cout << "\n\n";
        }

        else if (yapilacak_islem == 9) {
            std::string tur;
            std::cout << "Listelemek istediginiz turu giriniz.\n";
            std::cout << "-> ";
            std::cin >> tur;
            panel.cihazlariTureGoreListele(tur);
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

    delete l1;
    delete f1;
    delete s1;

    return 0;
}


/* Komut giriniz:
1 - Tüm cihazları aç
2 - Tüm cihazları kapat
3 - Cihaz durumu göster
4 - Belirli cihazı aç
5 - Belirli cihazı kapat
6 - Sensör değerini güncelle
0 - Çıkış
*/