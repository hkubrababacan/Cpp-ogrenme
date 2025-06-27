#include <iostream>

int main() {
    int sayilar[5];
    
    std::cout << "5 sayı girin:\n";

    for (int i = 0; i < 5; i++) {
        std::cin >> sayilar[i];
    }
    

    int* ptr = sayilar;

    std::cout << "Girdiğiniz sayılar: ";
    for (int i = 0; i < 5; i++) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << "\n";

    int max = sayilar[0];
    int min = sayilar[0];

    for (int i = 1; i < 5; i++) {
        if (*(ptr + i) > max) {
            max = *(ptr + i);
        }
    }

    for (int i = 1; i < 5; i++) {
        if (*(ptr + i) < min) {
            min = *(ptr + i);
        }
    }

    double toplam = 0;
    double ort;

    for (int i = 0; i < 5; i++) {
        toplam += *(ptr + i);
    }

     ort = toplam / 5;
    
    std::cout << "Girdiğiniz sayıların tersten yazılmış hali: ";
    for (int i = 4; i >= 0; i--) {
        std::cout << *(ptr + i) << " ";
    }
    std::cout << "\n";

    std::cout << "Bu dizideki en büyük sayı " << max << "'dır.\n";
    std::cout << "Bu dizideki en küçük sayı " << min << "'dır.\n";
    std::cout << "Bu dizideki sayıların toplamı " << toplam << "'dır.\n";
    std::cout << "Bu dizinin ortalaması " << ort << "'dır.\n";

    return 0;
}
