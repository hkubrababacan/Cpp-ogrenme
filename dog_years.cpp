#include <iostream>

int main() {
  int dog_year;
  float human_year=0;
  
  std::cout << "write your how old your dog is: ";
  std::cin >> dog_year;

  if (dog_year>2) {
     human_year = dog_year * 10.5;
     std::cout << "your dog is " << human_year << " old in human years.\n";

      }
  else {
    dog_year = dog_year-2;
    human_year = 21 + dog_year * 4;
    std::cout << "your dog is " << human_year << " old in human years.\n";
  }
  
  return 0;
  
}