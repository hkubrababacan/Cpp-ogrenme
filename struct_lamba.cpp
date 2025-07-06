#include <iostream>
using namespace std;

enum Durum { KAPALI, ACIK };

struct Lamba {
    string isim;
    bool isLED;
    Durum durum;

    void yazdir() {
        cout << isim << " (" << (isLED ? "LED" : "Normal") << ") şu an "
             << (durum == ACIK ? "AÇIK" : "KAPALI") << endl;
    }
};

int main() {
    Lamba lamba1, lamba2;

    // 1. Lamba isimlerini al
    cout << "1. lambanin ismini girin: ";
    getline(cin, lamba1.isim);

    cout << "2. lambanin ismini girin: ";
    getline(cin, lamba2.isim);

    // 2. LED mi normal mi?
    char secim;
    cout << lamba1.isim << " LED mi? (e/h): ";
    cin >> secim;
    lamba1.isLED = (secim == 'e' || secim == 'E');

    cout << lamba2.isim << " LED mi? (e/h): ";
    cin >> secim;
    lamba2.isLED = (secim == 'e' || secim == 'E');

    // 3. Başlangıçta kapalı
    lamba1.durum = KAPALI;
    lamba2.durum = KAPALI;

    // 4. Hangisini açmak istersin?
    int sec;
    cout << "\nHangi lambayi acmak istersiniz? (1 veya 2): ";
    cin >> sec;

    if (sec == 1) lamba1.durum = ACIK;
    else if (sec == 2) lamba2.durum = ACIK;
    else cout << "Gecersiz secim!" << endl;

    // 5. Durumlari yazdir
    cout << "\n--- Lamba Durumlari ---\n";
    lamba1.yazdir();
    lamba2.yazdir();

    return 0;
}
