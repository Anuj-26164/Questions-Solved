#include <iostream>
#include <optional> // C++17 feature

int main() {
    std::optional<int> opt = 42; // C++17 feature
    if (opt) {
        std::cout << "C++17 is enabled, value: " << *opt << std::endl;
    } else {
        std::cout << "C++17 is not enabled." << std::endl;
    }
    return 0;
}
