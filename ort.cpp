#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

double ortalama(std::vector<double> notlar) {
    double toplam = 0;

    for (int i = 0; i < (notlar.size()); i++) {
        toplam += notlar[i];
    }

    return toplam/(notlar.size());
}


double maksimum(std::vector<double> notlar) {
    double max = notlar[0];

    for (int i = 0; i < (notlar.size()); i++) {
        for (int j = i; j < (notlar.size()); j++) {
            if (i < j) {
                max = notlar[j];
            }
        }
    }

    return max;
}


double minimum(std::vector<double> notlar) {
    double min = notlar[0];

    for (int i = 1; i < notlar.size(); i++) {
        if (notlar[i] < min) {
            min = notlar[i];
        }
    }
    
    return min;
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
    int adet;
    std::vector<double> notlar;
    double ort;

    std::cout << "Kaç tane not gireceksiniz? ";
    std::cin >> adet;

    for (int i = 0; i < adet; i++) {
        double n;
        std::cout << i+1 << ". notu giriniz: ";
        std::cin >> n;
        notlar.push_back(n);
    }

    ort = ortalama(notlar);

    std::cout << "Ortalama: " << ort << "\n";
    std::cout << "En yüksek not: " << maksimum(notlar) << "\n";
    std::cout << "En düşük not: " << minimum(notlar) << "\n";
    std::cout << "Yorum: " << yorumla(ort) << "\n";

}