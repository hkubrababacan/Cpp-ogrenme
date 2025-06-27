#include <iostream>
#include <vector>
#include <string>

double ort_hesapla(double ders1, double ders2, double ders3) {
    return (ders1+ders2+ders3)/3;
}

std::string yorumla(double ortalama) {
    if (ortalama >=85) {
        return "Mükemmel";
    }

    else if (ortalama > 70) {
        return "Başarılı";
    }

    else if (ortalama > 60) {
        return "Geçer";
    }

    else {
        return "Başarısız";
    }

}

int main() {
    double not1, not2, not3;

    std::cout << "1. notu giriniz: ";
    std::cin >> not1;

    std::cout << "2. notu giriniz: ";
    std::cin >> not2;

    std::cout << "3. notu giriniz: ";
    std::cin >> not3;
    
    std::cout << "Ortalama: " << ort_hesapla(not1, not2, not3) << "\n";
    
    std::cout << yorumla(ort_hesapla(not1, not2, not3)) << "\n";
    return 0;
}