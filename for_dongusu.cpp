#include <iostream>
#include <vector>

int main() {
    std::vector<int> liste; // çift sayıları tutacak
    int toplam = 0;         // toplamı tutacak
    int sayi;

    std::cout << "Bir sayı giriniz: \n";
    std::cin >> sayi; // sayı al

    for (int i = 0; i <= sayi; i++) {
        if (i % 2 == 0) {
            toplam += i;
            liste.push_back(i);
        }
    }

    std::cout << "Çift sayılar: ";
    for (int i = 0; i < liste.size(); i++) {
        std::cout << liste[i] << " ";
    }
    std::cout << "\nÇift sayıların toplamı: " << toplam << "\n";

    return 0;
}
