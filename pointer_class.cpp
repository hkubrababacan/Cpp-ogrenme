#include <iostream>
using namespace std;

class UyariSistemi {
public:
    void mesajGoster(int deger) {
        cout << "Uyari Mesaji! Deger: " << deger << endl;
    }

    void kritik_uyari(int deger) {
        if (deger > 30) {
            cout << "Deger siniri asti.\n";
        }
    }
};

int main() {
    UyariSistemi sistem;
    
    void (UyariSistemi::*callback)(int);  
    callback = &UyariSistemi::mesajGoster; 

    void (UyariSistemi::*f)(int);
    f = &UyariSistemi::kritik_uyari;
    
    (sistem.*callback)(42);  
    (sistem.*f)(99);
    
    return 0;
}
