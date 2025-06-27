#include <iostream>

int main() {
    int sayi;

    std::cout << "Kaç sayı gireceksiniz?\n";
    std::cin >> sayi;

    int* sayilar = new int[sayi];

    for (int i = 0; i < sayi; i++) {
        std::cin >> sayilar[i];
    }

    std::cout << "Girdiğiniz sayılar: ";
    for (int i = 0; i < sayi; i++ ) {
        std::cout << sayilar[i] << " ";
    }

    delete[] sayilar;

    return 0;
}