#include <iostream>
#include <variant>
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

/* Zadanie 2 */

void zadanie2()
{
    std::cout << "Podaj liczbe elementow wektora" << std::endl;
    int n;
    std::cin >> n;
    try {
        std::vector< int > wektor(n, 0);
    }
    catch (const std::bad_alloc& ba) {
        std::cout << ba.what() << std::endl;
    }
}

/* Zadanie 3 */

void zadanie3()
{
    int a, b;
    std::cout << "Podaj liczbe a" << std::endl;
    std::cin >> a;
    std::cout << "Podaj liczbe b" << std::endl;
    std::cin >> b;
    try {
        std::vector< int >                      wektor(a, 0);
        std::variant< int, float, std::string > wariant;
        if (b % 2 == 0)
            wariant = 42;
        else
            wariant = "nieparzyste";
        std::cout << std::get< int >(wariant) << std::endl;
    }
    catch (const std::bad_alloc& ba) {
        std::cout << ba.what() << std::endl;
    }
    catch (const std::bad_variant_access& bva) {
        std::cout << bva.what() << std::endl;
    }
}

int main()
{
    zadanie3();
}

/* Po uruchomieniu otrzymano:
  Podaj liczbe a
  10
  Podaj liczbe b
  3
  Unexpected index
*/