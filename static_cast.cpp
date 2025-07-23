#include <iostream>

int main() {
    double ondalik_sicaklik = 9.87;

    int tam_sayi = static_cast<int>(ondalik_sicaklik);

    std::cout << "Ondalik: " << ondalik_sicaklik << std::endl;
    std::cout << "Tam sayi (static_cast ile): " << tam_sayi << std::endl;

    char karakter = 'c';
    int karsilik = static_cast<int>(karakter);

    std::cout << "Karakter: " << karakter << std::endl;
    std::cout << "ASCII degeri: " << karsilik << std::endl;


    return 0;
}
