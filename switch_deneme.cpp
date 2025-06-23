#include <iostream>

int main() {
    char secim;

    std::cout << "Bir harf giriniz (Çıkmak için 0): \n";
    std::cin >> secim;

    while (secim != '0') {
        switch (secim) {
            case 'a':
            case 'A':
                std::cout << "Elma\n";
                break;
            case 'b':
            case 'B':
                std::cout << "Balık\n";
                break;
            case 'c':
            case 'C':
                std::cout << "Ceviz\n";
                break;
            default:
                std::cout << "Geçersiz harf girdiniz.\n";
        }

        std::cout << "\nBir harf giriniz (Çıkmak için 0): ";
        std::cin >> secim;
    }

    return 0;
}
