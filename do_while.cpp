#include <iostream>
#include <string>

int main() {
    std::string sifre;
    int hak = 0;

    do {
        if (hak < 3) {
            std::cout << "Şifreyi girin: ";
            std::cin >> sifre;
            hak++;
        }

        else {
            std::cout << "Hakkınız kalmadı.\n";
            break;
        }

    } while (sifre != "2025") ;

    if (sifre == "2025") {
        std::cout << "Giriş başarılı!\n";
    }
    return 0;
}
