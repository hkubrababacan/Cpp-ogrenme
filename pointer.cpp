#include <iostream>


int main() {
int sayi = 42;
int* ptr = &sayi;

std::cout << "Sayının değeri: " << sayi << "\n";
std::cout << "Pointer ile erişilen değer: " << *ptr << "\n";  
*ptr = 99;
std::cout << "Pointer ile değer " << *ptr << " olarak değiştirildi.\n";
std::cout << "Yeni sayı değeri: " << sayi << "\n";

}