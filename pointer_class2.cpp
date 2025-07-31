#include <iostream>
using namespace std;

class Alarm {
public:
    void sicaklikUyari(int derece) {
        cout << "ALARM! Sicaklik cok yüksek: " << derece << " derece!" << endl;
    }
    void nemUyari(int nem) {
        cout << "ALARM! Nem cok yuksek: " << nem << "%" << endl;
}

};

class Sensor {
    void (Alarm::*callback)(int);  
    Alarm* hedef;                 

public:
    Sensor(void (Alarm::*cb)(int), Alarm* h) : callback(cb), hedef(h) {}

    void olcumYap(int derece) {
        cout << "Sensor olcutu: " << derece << " derece." << endl;

        if (derece > 30) {
            (hedef->*callback)(derece);
        }
    }
};

int main() {
    Alarm alarm;

    Sensor sicaklikSensoru(&Alarm::sicaklikUyari, &alarm);
    Sensor nemSensoru(&Alarm::nemUyari, &alarm);

    sicaklikSensoru.olcumYap(28);  
    sicaklikSensoru.olcumYap(35);  

    nemSensoru.olcumYap(70);

    return 0;
}
