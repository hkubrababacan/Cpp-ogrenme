#include <iostream>
#include <fstream>
#include <string>

struct Sensor {
    std::string isim;
    double deger;
};

int main() {
    int adet;
    std::cout << "Kac sensor gireceksiniz? ";
    std::cin >> adet;

    Sensor* sensorler = new Sensor[adet];
    std::cin.ignore(); // Enter temizleme

    for (int i = 0; i < adet; i++) {
        std::cout << "Sensor " << (i+1) << " ismi: ";
        std::getline(std::cin, sensorler[i].isim);

        std::cout << sensorler[i].isim << " sensorunden gelen veri: ";
        std::cin >> sensorler[i].deger;
        std::cin.ignore();
    }

    std::ofstream dosya("sensor_data.txt");
    if (!dosya) {
        std::cerr << "Dosya acma hatasi!\n";
        delete[] sensorler;
        return 1;
    }

    dosya << adet << "\n";  // Sensor sayisini kaydet

    for (int i = 0; i < adet; i++) {
        dosya << sensorler[i].isim << "\n" << sensorler[i].deger << "\n";
    }

    dosya.close();

    std::ifstream dosyaOku("sensor_data.txt");
    if (!dosyaOku) {
        std::cerr << "Dosya acma hatasi!\n";
        delete[] sensorler;
        return 1;
    }

    int okunanAdet;
    dosyaOku >> okunanAdet;
    dosyaOku.ignore();

    Sensor* sensorlerOkunan = new Sensor[okunanAdet];

    for (int i = 0; i < okunanAdet; i++) {
        std::getline(dosyaOku, sensorlerOkunan[i].isim);
        dosyaOku >> sensorlerOkunan[i].deger;
        dosyaOku.ignore();
    }

    std::cout << "\nDosyadan okunan sensor verileri:\n";
    for (int i = 0; i < okunanAdet; i++) {
        std::cout << sensorlerOkunan[i].isim << " : " << sensorlerOkunan[i].deger << "\n";
    }

    dosyaOku.close();

    delete[] sensorler;
    delete[] sensorlerOkunan;

    return 0;
}
