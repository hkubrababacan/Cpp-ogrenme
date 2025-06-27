#include <iostream>


void yazdir() {
    std::cout << "Görev tamamlandı!\n";
}

int kare(int sayi) {
    int kare;
    kare = sayi * sayi;
    return kare;
}

int main() {
    yazdir();
    std::cout << kare(5) << "\n";
    return 0;
}