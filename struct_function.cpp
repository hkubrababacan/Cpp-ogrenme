#include <iostream>

struct Sensor {
    std::string isim;
    double deger;
};

void yazdir(const Sensor* ptr) {
    std::cout << ptr->isim << " sensöründen gelen veri: " << ptr->deger << "\n";
}

void degistir(Sensor* ptr, float yeni_deger) {
    
    std::cout << ptr->isim << " sensöründen gelen ilk veri: " << ptr->deger << "\n";
    ptr->deger = yeni_deger;
    std::cout << ptr->isim << " sensöründen gelen değişen veri: " << ptr->deger << "\n";
}

int main() {
    Sensor nem = {"Nem", 40.8};
    Sensor sicaklik = {"Sıcaklık", 24.5};
    Sensor basinc = {"Basınç", 90};

    yazdir(&nem);
    yazdir(&sicaklik);
    yazdir(&basinc);

    float deger;
    std::cout << "Yeni değer girin: ";
    std::cin >> deger;

    degistir(&nem, deger);

    return 0;
}
