#include <iostream>
#include <string>

int main () {
    std::string isim;
    int yas;
    double boy;

    std::cout << "İsim giriniz: \n";
    std::getline(std::cin, isim);

    std::cout << "Yaşınızı giriniz: \n";
    std::cin >> yas;

    std::cout << "Boyunuzu giriniz: \n";
    std::cin >> boy;

    std::cout << "Merhaba " << isim << "\n";
    std::cout << "Yaşınız: " << yas << "\n";
    std::cout << "Boyunuz: " << boy << "\n";

    return 0;

}