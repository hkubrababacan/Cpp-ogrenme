#include <iostream>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()

int main() {
    srand(time(NULL));           // Rastgeleliği başlat
    int gizli = rand() % 10 + 1; // 1 ile 10 arasında sayı üret

    int sayi;
    int tahmin = 0;

    std::cout << "1 ile 10 arasında bir sayı tahmin ediniz: ";
    std::cin >> sayi;
    tahmin++;

    while (sayi != gizli) {
        if (sayi < gizli) {
            std::cout << "Daha büyük bir sayı girin: ";
        } else {
            std::cout << "Daha küçük bir sayı girin: ";
        }
        std::cin >> sayi;
        tahmin++;
    }

    std::cout << "Tebrikler! Doğru tahmin ettiniz.\n";
    std::cout << tahmin << " tahminde bulundunuz.\n";
    return 0;
}
