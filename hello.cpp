#include <iostream>
#include <string>

int main() {
    std::string nombre;
    
    std::cout << "Por favor, ingresa tu nombre: ";
    std::cin >> nombre;
    
    std::cout << "¡Hola, " << nombre << "! ¡Bienvenido al mundo de C++!" << std::endl;

    return 0;
}
