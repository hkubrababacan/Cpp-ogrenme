#include <iostream>
#include <vector>

class Cihaz {
    public:
    virtual void yazdir() = 0;
};

class Sensor : public Cihaz {
    private:
    std::string tur = "sensor";
    std::string isim;

    public:
    Sensor(std::string verilen_isim) {
        isim = verilen_isim;
    }
    void yazdir() override {
        std::cout << isim << " " << tur << std::endl;
    }
};

class Motor : public Cihaz {
    private:
    std::string tur = "motor";
    std::string isim;

    public:
    Motor(std::string verilen_isim) {
        isim = verilen_isim;
    }
    void yazdir() override {
        std::cout << isim << " " << tur << std::endl;
    }
};

int main() {
    Sensor s1("s1");
    Sensor s2("s2");
    Motor m1("m1");
    Motor m2("m2");
    std::vector<Cihaz*> cihazlar = {&s1, &s2, &m1, &m2};

    for (auto c : cihazlar)  {
    Sensor* s = dynamic_cast<Sensor*>(c);
        if (s != nullptr) {
            s->yazdir();
        }
    }

    return 0;
}
    