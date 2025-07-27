#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> veriler = {10, 22, 13, 5, 42};
    std::vector<int> sayilar;
    int max_sayi = 0;
    float toplam = 0;
    float ort;

    std::cout << "20'den buyuk veriler:\n";
    std::for_each(veriler.begin(), veriler.end(), [](int x) {
        if (x > 20)
            std::cout << x << "\n";
    });

    std::cout << "\n\n";
    std::cout << "En buyuk sayi: ";
    std::for_each(veriler.begin(), veriler.end(), [&max_sayi](int x) {
        if (x > max_sayi) {
            max_sayi = x;
        }
    });

    std::cout << max_sayi << std::endl;

    std::cout << "\n\n";
    std::cout << "Verilerin ortalamasi: ";
    std::for_each(veriler.begin(), veriler.end(), [&toplam, &ort, &veriler](int x) {
        toplam += x;
        ort = toplam / veriler.size();
    });

    std::cout << ort << std::endl;

    std::cout << "\n\n";
    std::cout << "10'dan kucuk sayilarin tutuldugu vector hazirlaniyor...\n";
    std::for_each(veriler.begin(), veriler.end(), [&sayilar](int x) {
        if (x < 10) {
            sayilar.push_back(x);
        }
    });

    std::cout << "Vector hazir.\n";

    for (int i = 0; i < sayilar.size(); i++) {
        std::cout << sayilar[i] << std::endl;
    }


    return 0;
}
