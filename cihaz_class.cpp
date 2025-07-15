#include <iostream>
#include <vector>

class Cihaz {
    private:
    std::string isim;
    std::string tur;
    bool durum;
    
    public:
    Cihaz(std::string verilen_isim, std::string verilen_tur) {
        isim = verilen_isim;
        tur = verilen_tur;
        durum = false;
    }

    void ac() {
        durum = true;
        std::cout << isim << " ( Tur: " << tur << " ) acildi\n"; 
    }

    void kapat() {
        durum = false;
        std::cout << isim << " ( Tur: " << tur << " ) kapatildi\n";
    }

    std::string get_isim() const {
        return isim;
    }

    std::string get_tur() const {
        return tur;
    }
    
    bool get_durum() const {
        return durum;
    }

    void yazdir() const {
        std::cout << isim << " ( Tur: " << tur << " ) suanda " << (durum ? "acik" : "kapali") << "\n";
    }
 };


class Kontrol_Paneli {
    private:
    std::vector<Cihaz> Cihazlar;
    
    public:
    
    void cihazEkle(const Cihaz& k) {
        Cihazlar.push_back(k);
    }

    void hepsini_ac() {
        for (auto& c : Cihazlar) {
            c.ac();
        }
    }

    void hepsini_kapat() {
        for (auto& c : Cihazlar) {
            c.kapat();
        }
    }

    void durumlari_yazdir() const {
        std::cout << "----------CIHAZ DURUMLARI------------\n";
        for (const auto& c : Cihazlar) {
            c.yazdir();
        }
    }

    void cihaz_ac(const std::string& isim) {
        for (auto& c : Cihazlar) {
            if (c.get_isim() == isim) {
                c.ac();
                return;
            }
        }
        std::cout << isim << " adinda bir cihaz bulunamadi!\n";
    }
    

    void cihaz_kapat(const std::string& isim) {
        for (auto& c : Cihazlar) {
            if (c.get_isim() == isim) {
                c.kapat();
                return;
            }
        }
        std::cout << isim << " adinda bir cihaz bulunamadi!\n";
    }

    void cihazlariTureGoreListele(const std::string& tur_adi) {
        std::cout << "----" << tur_adi << " turundeki cihazlar----\n";
        for (const auto& c : Cihazlar) {
            if (c.get_tur() == tur_adi) {
                c.yazdir();
            }  
        }
    }

    void acikCihazlariListele() const {
        std::cout << "------- Acik Cihazlar-------\n";
        for (const auto& c : Cihazlar) {
            if (c.get_durum() == true) {
                c.yazdir();
            }
        }
    }

};

int main() {
    Kontrol_Paneli panel;
    Cihaz lamba("lamba1", "Lamba");
    Cihaz fan("fan1", "Fan");

    panel.cihazEkle(lamba);
    panel.cihazEkle(fan);

    panel.durumlari_yazdir();

    std::cout << "-----------------------------\n\n";

    panel.hepsini_ac();

    panel.durumlari_yazdir();

    std::cout << "-----------------------------\n\n";

    panel.cihaz_kapat("lamba1");
    panel.durumlari_yazdir();

    
    std::string alinan_isim;
    int yapilacak_gorev;

    while(true) {
        std::cout << "Islem yapmak istediginiz cihazin ismini giriniz. (Cikmak için 'q' basiniz.)\n";
        std::cin >> alinan_isim;

        if (alinan_isim == "q") {
            std::cout << "Cikis yapiliyor...\n";
            break;
        }

        std::cout << "Yapmak istediginiz islemi seciniz. (acmak icin: 1, kapatmak icin: 2)\n";
        std::cin >> yapilacak_gorev;

        if (yapilacak_gorev == 1) {
            panel.cihaz_ac(alinan_isim);
        }

        else if (yapilacak_gorev == 2) {
            panel.cihaz_kapat(alinan_isim);
        }

        else {
            std::cout << "Gecersiz bir cihaz ismi ya da komut girdiniz. Tekrar deneyiniz.\n";
        }

        panel.durumlari_yazdir();
    }

    std::cout << "---------------------------------------------\n\n";
    panel.acikCihazlariListele();

    return 0;
}