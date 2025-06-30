#include <iostream>

struct Ogrenci {
    std::string isim;
    int yas;
    double ort;
    };

int main() {
    Ogrenci ogr;
    Ogrenci* ptr = &ogr;
    
    std::cout << "İsim giriniz: ";
    std::cin.ignore(); // önceki cin'i temizler
    std::getline(std::cin, ptr->isim);
    

    std::cout << "Yaş giriniz: ";
    std::cin >> ptr->yas;

    std::cout << "Ortalama giriniz: ";
    std::cin >> ptr->ort;


    std::cout << "Öğrencinin ismi: " << ptr->isim << "\n";
    std::cout << "Öğrencinin yaşı: " << ptr->yas << "\n";
    std::cout << "Öğrencinin ortalaması: " << ptr->ort << "\n";

    return 0;

}