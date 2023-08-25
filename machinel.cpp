#include <iostream>
#include <vector>
#include <cmath>

struct Transaccion {
    double monto;
    double hora;  // Normalizada entre 0 y 1, donde 0 es 12:00 AM y 1 es 11:59 PM
    bool esFraudulenta;
};

//pesos calculados
double w_monto = -2.5;
double w_hora = 1.2;
double bias = 0.5;

// Función sigmoide
double sigmoide(double z) {
    return 1.0 / (1.0 + exp(-z));
}

// Predicción utilizando regresión logística
bool predecirFraude(const Transaccion& transaccion) {
    double z = w_monto * transaccion.monto + w_hora * transaccion.hora + bias;
    double probabilidad = sigmoide(z);
    return probabilidad > 0.5;  // Si la probabilidad es mayor que 0.5, clasificamos como fraudulenta
}

int main() {
    Transaccion t1 = {1000.0, 0.9, false};  // Transacción de $1000 a las 9:00 PM
    Transaccion t2 = {10.0, 0.2, false};    // Transacción de $10 a las 4:48 AM

    if (predecirFraude(t1)) {
        std::cout << "La transacción 1 es potencialmente fraudulenta.\n";
    } else {
        std::cout << "La transacción 1 es legítima.\n";
    }

    if (predecirFraude(t2)) {
        std::cout << "La transacción 2 es potencialmente fraudulenta.\n";
    } else {
        std::cout << "La transacción 2 es legítima.\n";
    }

    return 0;
}
