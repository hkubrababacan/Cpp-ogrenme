#include <iostream>
using namespace std;

union Veri {
    int tamsayi;
    float ondalik;
};

int main() {
    Veri v;
    v.tamsayi = 42;
    cout << v.tamsayi << endl;

    v.ondalik = 3.14;
    cout << v.ondalik << endl;

    // Dikkat: Son atama diğerini geçersiz kılar!
}
