#include <iostream>
#include <vector>
void sicaklikUyari() {
    std::cout << "Sicaklik siniri asildi.\n";
}
void nemUyari() {
    std::cout << "Nem siniri asildi.\n";
}
void gazUyari(){
    std::cout << "Gaz siniri asildi.\n";
}
void olay_kontrol(void (*handler)()) {
    std::cout << "Olay algilandi...\n";
    handler();
}

int main() {
    std::vector<void(*)()> dizi = {nemUyari , gazUyari , sicaklikUyari};
    olay_kontrol(sicaklikUyari);

    for (auto c : dizi) {
        olay_kontrol(c);
    }

    return 0;
}