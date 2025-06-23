#include <iostream>

int main() {
    int secim;
    char devam = 'e';

    while (devam == 'e') {
        std::cout << "1-9 arası bir rakam seçiniz.\n";
        std::cin >> secim;

        switch (secim) {
            case 1: 
                std::cout << "Bir sayısını seçtiniz.\n"; 
                break;

            case 2: 
                std::cout << "İki sayısını seçtiniz.\n"; 
                break;

            case 3: 
                std::cout << "Üç sayısını seçtiniz.\n"; 
                break;

            case 4: 
                std::cout << "Dört sayısını seçtiniz.\n"; 
                break;

            case 5: 
                std::cout << "Beş sayısını seçtiniz.\n"; 
                break;

            case 6: 
                std::cout << "Altı sayısını seçtiniz.\n"; 
                break;

            case 7: 
                std::cout << "Yedi sayısını seçtiniz.\n"; 
                break;

            case 8: 
                std::cout << "Sekiz sayısını seçtiniz.\n"; 
                break;

            case 9: 
                std::cout << "Dokuz sayısını seçtiniz.\n"; 
                break;

            default: 
                std::cout << "Geçersiz sayı girdiniz.\n"; 
                break;
        }

        std::cout << "Devam etmek istiyorsanız 'e', istemiyorsanız 'h' tuşlayınız.\n";
        std::cin >> devam;
    }

    return 0;
}
