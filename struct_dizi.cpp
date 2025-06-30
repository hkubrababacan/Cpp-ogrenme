#include <iostream>

struct Sensor {
    std::string isim;
    double deger;
};

void yazdir(const Sensor* dizi, int adet) {
    std::cout << "\n--- Sensör Değerleri ---\n";
    for (int i = 0; i < adet; i++) {
        std::cout << dizi[i].isim << " sensöründen gelen veri: " << dizi[i].deger << "\n";
    }
}

void guncelle(Sensor* dizi, int adet) {
    std::cout << "\n--- Yeni Değer Girişi ---\n";
    for (int i = 0; i < adet; i++) {
        std::cout << dizi[i].isim << " için yeni bir değer giriniz: ";
        std::cin >> dizi[i].deger;
    }
}
const Sensor* enYuksekDeger(const Sensor* dizi, int adet) {
    const Sensor* maxSensor = &dizi[0];
    for (int i = 1; i < adet; i++) {
        if (dizi[i].deger > maxSensor->deger) {
            maxSensor = &dizi[i];
        }
    }
    return maxSensor;
}




int main() {
    Sensor sensorler[3] = {
        {"Sıcaklık", 26.5},
        {"Nem", 40.0},
        {"Basınç", 90.0}
    };

    int adet = 3;

    yazdir(sensorler, adet);
    guncelle(sensorler, adet);
    yazdir(sensorler, adet);
    const Sensor* enBuyuk = enYuksekDeger(sensorler, adet);
    std::cout << "En yüksek değere sahip sensör: " << enBuyuk->isim << " (" << enBuyuk->deger << " birim)\n";


    return 0;
}
