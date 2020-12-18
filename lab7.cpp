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

/* Zadanie 4 */

void zadanie4()
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
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

/* Zadanie 5 */

float podziel(int a, int b)
{
    if (b == 0)
        throw 0;
    else
        return (float)a / (float)b;
}

void zadanie5(int a, int b)
{
    try {
        std::cout << podziel(a, b) << std::endl;
    }
    catch (int& i) {
        std::cout << "Nie możesz dzielić przez " << i << std::endl;
    }
}

/* Zadanie 6 */
class Informer
{
public:
    Informer() { std::cout << "Utworzono Informera" << std::endl; }
    ~Informer() { std::cout << "Zniszczono Informera" << std::endl; }
};

void zadanie6(int a, int b)
{
    try {
        Informer informer1;
        std::cout << podziel(a, b) << std::endl;
    }
    catch (int& i) {
        std::cout << "Nie możesz dzielić przez " << i << std::endl;
    }
}

int main()
{
    zadanie6(1, 2);
    zadanie6(20, 0);
}

/* Po uruchomieniu otrzymano:
  Utworzono Informera
  0.5
  Zniszczono Informera
  Utworzono Informera
  Zniszczono Informera
  Nie możesz dzielić przez 0
*/