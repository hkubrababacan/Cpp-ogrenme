#include <iostream>
#include <bitset>
using namespace std;

union SistemDurumu {
    uint8_t tum_bayraklar;
    struct {
        unsigned int LED : 1;
        unsigned int Motor : 1;
        unsigned int SistemHazir : 1;
        unsigned int HataVar : 1;
        unsigned int Rezerve : 4;
    } bayraklar;
};

int main() {
    SistemDurumu durum;
    durum.tum_bayraklar = 0;

    // Şuanda bit yapısı: 00000000 şeklindedir.
    //                    7 6 5 4 3 2 1 0 şekilde yerleştirilir.

    durum.bayraklar.LED = 1; // yukarıda 0. indekse sahip o yüzden şuanda 00000001
    durum.bayraklar.SistemHazir = 1; // 2. indekse sahip şuanda 00000101

    cout << "Ilk bayraklar: " << bitset<8>(static_cast<int>(durum.tum_bayraklar)) << endl;

    /* bitset sayıyı 8 bitlik binary şekline çevirir.
    static_cast<int> yapısı ise farklı türde bulunan veriyi int türüne çevirir.
    */

    // Motor'u da açalım
    durum.bayraklar.Motor = 1; // 1. indekse sahip 00000111 olmuş oldu

    cout << "Guncel bayraklar: " << bitset<8>(static_cast<int>(durum.tum_bayraklar)) << endl;

    durum.tum_bayraklar = 0; // hepsini sıfırladık 00000000 olacak 


    cout << "Guncel bayraklar: " << bitset<8>(static_cast<int>(durum.tum_bayraklar)) << endl;

    return 0;
}
