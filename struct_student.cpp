#include <iostream>

struct Ogrenci {
    std::string isim;
    int yas;
    double ortalama;
};

void yazdir(const Ogrenci* dizi, int adet) {
    for (int i = 0; i < adet; i++) {
        std::cout << dizi[i].isim << " ismindeki öğrenci " << dizi[i].yas << " yaşındandır ve ortalaması " << dizi[i].ortalama << " kadardır.\n";
    }
}

int main() {
    int ogrenci_sayisi;
    std::cout << "Kaç öğrenci gireceksiniz? ";
    std::cin >> ogrenci_sayisi;
    std::cin.ignore();
    Ogrenci* ogrenciler = new Ogrenci[ogrenci_sayisi];

    for (int i = 0; i < ogrenci_sayisi; i++) {
        std::cout << i+1 << ". Öğrencinin adını giriniz: ";
        std::getline(std::cin, ogrenciler[i].isim);
        std::cout << i+1 << ". öğrencinin yaşını giriniz: ";
        std::cin >> ogrenciler[i].yas;
        std::cout << i+1 << ". öğrencinin ortalamasını giriniz: ";
        std::cin >> ogrenciler[i].ortalama;
        std::cin.ignore();
    }

    yazdir(ogrenciler, ogrenci_sayisi);

    delete[] ogrenciler;

    return 0;
    

}