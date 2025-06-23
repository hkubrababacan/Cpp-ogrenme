#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> liste = {"a", "b", "c", "d"};

    for (const std::string& i : liste) {
        std::cout << i << std::endl;
    }

    return 0;
}
