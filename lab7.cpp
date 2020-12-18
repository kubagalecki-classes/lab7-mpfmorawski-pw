#include <iostream>
#include <vector>

/* Zadanie 1 */

void zadanie1()
{
    std::cout << "Podaj liczbe elementow wektora" << std::endl;
    int n;
    std::cin >> n;
    try {
        std::vector< int > wektor(n, 0);
    }
    catch (...) {
        std::cout << "Zostal rzucony wyjatek" << std::endl;
    }
}

int main()
{
    zadanie1();
}

/* Po uruchomieniu otrzymano:
  Podaj liczbe elementow wektora
  -2
  Zostal rzucony wyjatek
*/