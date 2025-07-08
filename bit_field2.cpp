#include <iostream>

struct Ayar {
    unsigned int wifiAcik : 1;     // sadece 1 bit yer kaplar
    unsigned int bluetoothAcik : 1;
    unsigned int sesSeviyesi : 4;
    unsigned int ekranParlakligi : 4;
};

int main() {
    Ayar Cihaz1{};
    Cihaz1.wifiAcik = 1;
    Cihaz1.bluetoothAcik = 0;
    Cihaz1.sesSeviyesi = 12;
    Cihaz1.ekranParlakligi = 7;

    std::cout << "Cihaz 1: WİFİ: " << (Cihaz1.wifiAcik == 1 ? "Açık" : "Kapalı") << " Bluetooth: " << (Cihaz1.bluetoothAcik == 1 ? "Açık" : "Kapalı") << " Ses: " << Cihaz1.sesSeviyesi << " Parlaklık: " << Cihaz1.ekranParlakligi << "\n";

    return 0;
}


