#include <iostream>

int main() {
    double sayi1,sayi2;
    char islem;

    std::cout << "Sayı giriniz.\n";
    std::cin >> sayi1;

    std::cout << "Sayı giriniz.\n";
    std::cin >> sayi2;

    std::cout << "Yaptırmak istediğiniz işlemi (+,-,*,/) giriniz.\n";
    std::cin >> islem;

    switch (islem) {
        case '+':
            std::cout << sayi1 + sayi2;
            break;
        case '-':
            std::cout << sayi1 - sayi2;
            break;
        case '*':
            std::cout << sayi1 * sayi2;
            break;
        case '/':
            if (sayi2 !=0) {  
                std::cout << sayi1 / sayi2;
                break;
            }
            else {
                std::cout << "Sıfıra bölünemez.\n";
                break;
            }
        default:
            std::cout << "Geçersiz işlem girdiniz.";
            break;
    }
    return 0;
}