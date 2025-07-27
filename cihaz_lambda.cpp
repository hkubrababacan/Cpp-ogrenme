#include <iostream>
#include <vector>
#include <algorithm>

class Cihaz {
public:
    std::string isim;
    int sicaklik;

    Cihaz(std::string isim, int sicaklik) : isim(isim), sicaklik(sicaklik) {}

    void yazdir() const {
        std::cout << isim << " - Sicaklik: " << sicaklik << "°C\n";
    }
};

int main() {
    std::vector<Cihaz> cihazlar = {
        Cihaz("Sensor-1", 25),
        Cihaz("Sensor-2", 34),
        Cihaz("Sensor-3", 29),
        Cihaz("Sensor-4", 42),
        Cihaz("Sensor-5", 18)
    };
    std::vector<Cihaz> yeni_liste;

    std::cout << ">> Tum cihazlar:\n";
    std::for_each(cihazlar.begin(), cihazlar.end(), [](const Cihaz& c) {
        c.yazdir();
    });

    std::cout << "\n>> Sicakligi 30'dan buyuk olan cihazlar:\n";
    std::for_each(cihazlar.begin(), cihazlar.end(), [](const Cihaz& c) {
        if (c.sicaklik > 30)
            c.yazdir();
    });

    int toplam = 0;
    std::for_each(cihazlar.begin(), cihazlar.end(), [&toplam](const Cihaz& c) {
        toplam += c.sicaklik;
    });

    float ort = static_cast<float>(toplam) / cihazlar.size();
    std::cout << "\n>> Ort. sicaklik: " << ort << "°C\n";

    int en_yuksek = 0;
    std::string en_yuksek_isim;
    std::for_each(cihazlar.begin(), cihazlar.end(), [&en_yuksek, &en_yuksek_isim](const Cihaz& c) {
        if (c.sicaklik > en_yuksek) {
            en_yuksek = c.sicaklik;
            en_yuksek_isim = c.isim;
        }
    });

    std::cout << "\n>> En yuksek sicaklik: " << en_yuksek << "°C (" << en_yuksek_isim << ")\n";

    std::cout<< "Sicaklik degeri 20'den fazla olanlar listeye aliniyor...\n";
    std::for_each(cihazlar.begin(), cihazlar.end(), [&yeni_liste](const Cihaz& c) {
        if (c.sicaklik > 20) {
            yeni_liste.push_back(c);
        }
    });
    std::cout << "Liste hazirlandi yazdiriliyor...\n";
    std::for_each(yeni_liste.begin(), yeni_liste.end(), [](const Cihaz& c) {
        c.yazdir();
    });

    std::cout << "\n\n";

    auto new_end = std::remove_if(yeni_liste.begin(), yeni_liste.end(), [](const Cihaz& c) {
        return c.sicaklik > 40;
    });

    yeni_liste.erase(new_end, yeni_liste.end());

    std::cout << "Sicaklik 40 dereceden yuksek olanlar listeden silindi. Liste tekrar yazdiriliyor.\n";
    std::for_each(yeni_liste.begin(), yeni_liste.end(), [](const Cihaz& c) {
        c.yazdir();
    });

    return 0;
}
