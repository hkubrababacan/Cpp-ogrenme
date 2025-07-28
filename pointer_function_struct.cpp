#include <iostream>

struct Veri {
    int sicaklik;
    int nem;
    int basinc;
};

void durum_yazdir(Veri v) {
    std::cout << "Sicaklik: " << v.sicaklik << " Nem: " << v.nem << " Basinc: " << v.basinc << std::endl;
}

void uyari_kontrol(Veri v) {
    if (v.sicaklik > 30 || v.nem > 70 || v.basinc > 50) {
        std::cout << "Degerler siniri asti. UYARII!!!\n";
    }
}

void veriyi_gonder(void(*callback)(Veri) ,void(*callback2)(Veri)){
    Veri veriler = {rand() % 100, rand() % 100, rand() % 100};
    callback(veriler);
    callback2(veriler);
}

int main() {
    veriyi_gonder(durum_yazdir, uyari_kontrol);

    return 0;
}