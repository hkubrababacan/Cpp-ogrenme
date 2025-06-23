#include <iostream>

int main() {
    int i = 1;
    int sayi;
    int faktoriyel = 1;

    std::cout << "Sayı giriniz.\n";
    std::cin >> sayi;

    if (sayi == 0) {
        std::cout << "Faktoriyel = 1";
    }

    else {
    while (i <= sayi) {
        faktoriyel *= i;
        i++;
}
    std::cout << "Faktoriyel: " << faktoriyel << "\n";
    }
}