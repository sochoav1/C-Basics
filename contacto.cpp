#include <iostream>
#include <string>
#include <vector>

struct Contacto {
    std::string nombre;
    std::string numero;
};

void agregarContacto(std::vector<Contacto>& agenda) {
    Contacto nuevo;
    std::cout << "Introduce el nombre del contacto: ";
    std::cin.ignore();
    std::getline(std::cin, nuevo.nombre);
    std::cout << "Introduce el número del contacto: ";
    std::cin >> nuevo.numero;
    agenda.push_back(nuevo);
    std::cout << "Contacto agregado exitosamente.\n";
}

void mostrarContactos(const std::vector<Contacto>& agenda) {
    std::cout << "Lista de contactos:\n";
    for (const Contacto& c : agenda) {
        std::cout << "Nombre: " << c.nombre << ", Número: " << c.numero << "\n";
    }
}

void buscarContacto(const std::vector<Contacto>& agenda) {
    std::string nombre;
    std::cout << "Introduce el nombre del contacto a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    bool encontrado = false;
    for (const Contacto& c : agenda) {
        if (c.nombre == nombre) {
            std::cout << "Número de " << nombre << ": " << c.numero << "\n";
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        std::cout << "Contacto no encontrado.\n";
    }
}

int main() {
    std::vector<Contacto> agenda;
    int opcion;
    do {
        std::cout << "\nAgenda de contactos\n";
        std::cout << "1. Agregar contacto\n";
        std::cout << "2. Mostrar contactos\n";
        std::cout << "3. Buscar contacto\n";
        std::cout << "4. Salir\n";
        std::cout << "Elige una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: agregarContacto(agenda); break;
            case 2: mostrarContactos(agenda); break;
            case 3: buscarContacto(agenda); break;
            case 4: std::cout << "¡Hasta luego!\n"; break;
            default: std::cout << "Opción no válida.\n";
        }
    } while (opcion != 4);

    return 0;
}
