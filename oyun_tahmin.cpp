#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));
    char tekrar = 'e';
    int enIyiSkor = 8; 

    while (tekrar == 'e') {
        int rastgeleSayi = rand() % 100 + 1;
        int tahmin;
        int deneme = 0;
        bool bildiMi = false;

        std::cout << "\n🎯 1 ile 100 arasında bir sayı tuttum. 7 tahmin hakkın var!\n";

        do {
            std::cout << "Tahmininiz: ";
            std::cin >> tahmin;
            deneme++;

            if (tahmin < rastgeleSayi) {
                std::cout << "Daha büyük bir sayı girin.\n";
            } else if (tahmin > rastgeleSayi) {
                std::cout << "Daha küçük bir sayı girin.\n";
            } else {
                std::cout << "\n🎉 Tebrikler! Sayıyı buldunuz.\n";
                std::cout << "🔢 " << deneme << " denemede bildiniz.\n";
                bildiMi = true;

                if (deneme < enIyiSkor) {
                    enIyiSkor = deneme;
                    std::cout << "🏆 Yeni en iyi skor!\n";
                }
            }

            
            if (!bildiMi && deneme < 7) {
                if (rastgeleSayi > tahmin) {
                    std::cout << "📌 İpucu: Sayı " << tahmin << "'ten büyük.\n";
                } else {
                    std::cout << "📌 İpucu: Sayı " << tahmin << "'ten küçük.\n";
                }
            }

        } while (!bildiMi && deneme < 7);

        if (!bildiMi) {
            std::cout << "\n😔 Üzgünüm! Tahmin hakkınız bitti.\n";
            std::cout << "Sayı: " << rastgeleSayi << "\n";
        }

        std::cout << "\n🏅 En iyi skor (en az deneme): ";
        if (enIyiSkor <= 7) {
            std::cout << enIyiSkor << " deneme\n";
        } else {
            std::cout << "Henüz bulunamadı.\n";
        }

        std::cout << "\nTekrar oynamak istiyor musunuz? (e/h): ";
        std::cin >> tekrar;
    }

    std::cout << "\nGörüşmek üzere, başarılar! 👋\n";
    return 0;
}
