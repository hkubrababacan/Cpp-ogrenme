#include <iostream>

int main() {
    int sayi;
    double toplam = 0;
    double ort;

    std::cout << "Kaç sayı gireceksiniz?\n";
    std::cin >> sayi;

    int* sayilar = new int[sayi];

    std::cout << "Sayıları giriniz: \n";

    for (int i = 0; i < sayi; i++) {
        std::cin >> sayilar[i];
    }

    std::cout << "Girdiğiniz sayılar: ";
    for (int i = 0; i < sayi; i++ ) {
        std::cout << sayilar[i] << " ";
        toplam += sayilar[i];
    }

    std::cout << "\n";

    ort = toplam / sayi;

    std::cout << "Girdiğiniz sayıların ortalaması: " << ort;

    delete[] sayilar;

    return 0;
}