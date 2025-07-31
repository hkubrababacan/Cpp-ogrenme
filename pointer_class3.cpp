#include <iostream>
using namespace std;

class Sensor {
    private:
    void (*uyariFonksiyonu)(int); 

    public:
    Sensor(void (*fonk)(int)) {
        uyariFonksiyonu = fonk;
    }

    void degerOku(int deger) {
        if (deger > 100) {
            uyariFonksiyonu(deger);
        }
    }
};

class NemSensoru {
    private:
    void (*uyariFonksiyonu)(int);

    public:
    NemSensoru(void (*fonk)(int)) {
        uyariFonksiyonu = fonk;
    }

    void deger_oku(int deger) {
        if (deger > 50) {
            uyariFonksiyonu(deger);
        }
    }
};

void basincUyarisi(int d) {
    cout << "UYARI! Basinc cok yuksek: " << d << endl;
}

void nemuyarisi(int deger) {
    cout << "UYARI! Nem cok yuksek: " << deger << endl;
}

int main() {
    Sensor basincSensoru(basincUyarisi);
    NemSensoru n(nemuyarisi);

    int okunanDeger = 120;
    basincSensoru.degerOku(okunanDeger);
    
    int deger = 60;
    n.deger_oku(deger);

    return 0;

}
