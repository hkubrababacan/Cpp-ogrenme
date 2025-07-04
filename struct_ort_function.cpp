#include <iostream>

struct Sensor {
    std::string isim;
    double deger;
};

void yazdir(const Sensor* dizi, int adet) {
    for (int i = 0; i < adet; i++) {
        std::cout << i+1 << ". sensörün ismi: " << dizi[i].isim << " değeri: " << dizi[i].deger << "\n";
    }
}

double ortalama(const Sensor* dizi, int adet) {
    double toplam = 0;
    for (int i = 0; i < adet; i++) {
        toplam += dizi[i].deger;
    }

    return toplam / adet;
}

void yuksek_degerleri_yazdir(const Sensor* dizi, int adet, double sinir) {
    for (int i = 0; i < adet; i++) {
        if (dizi[i].deger > sinir) {
            std::cout << dizi[i].isim << " sensorünün değeri " << dizi[i].deger <<" "<< sinir << " değerinden yüksektir.\n";
        }
    }
}

void en_yuksek_deger_yazdir(const Sensor* dizi, int adet) {
    double max = dizi[0].deger;
    for (int i = 1; i < adet; i++) {
        if (max < dizi[i].deger) {
            max = dizi[i].deger;
        }
    }

    std::cout << "Verilen sensörlerden maksimum deger: " << max << "\n";
}

int main() {
    int adet;
    std::cout << "Kaç adet Sensör gireceksiniz?\n";
    std::cin >> adet;

    Sensor* sensorler = new Sensor[adet];
    std::cin.ignore();

    for (int i = 0; i < adet; i++) {
        std::cout << i+1 << ". sensörün ismini giriniz: ";
        std::getline(std::cin, sensorler[i].isim);
        
        std::cout << i+1 << ". sensörün değerini giriniz: ";
        std::cin >> sensorler[i].deger;

        std::cin.ignore();
    }

    double ort = ortalama(sensorler, adet);

    yazdir(sensorler, adet);
    std::cout << "Sensörlerden gelen verilerin ortalaması: " << ort << "\n";
    yuksek_degerleri_yazdir(sensorler, adet , ort);
    en_yuksek_deger_yazdir(sensorler, adet);


    delete[] sensorler;

    return 0;
}