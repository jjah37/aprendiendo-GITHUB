#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables principales
    double flujoAgregado;   // toneladas por hora
    double flujoBetun;      // litros por hora
    double temperatura;     // °C

    // Parámetros de control
    const double tempMin = 140.0;   // temperatura mínima aceptable
    const double tempMax = 160.0;   // temperatura máxima aceptable
    const double ratioMin = 0.045;  // proporción mínima de betún respecto al agregado
    const double ratioMax = 0.060;  // proporción máxima de betún respecto al agregado

    cout << "=== Simulador Planta Asfaltica ===" << endl;
    cout << "Ingrese flujo de agregados (t/h): ";
    cin >> flujoAgregado;
    cout << "Ingrese flujo de betun (L/h): ";
    cin >> flujoBetun;
    cout << "Ingrese temperatura del tambor (°C): ";
    cin >> temperatura;

    // Cálculo de proporción betún/agregado
    double ratio = flujoBetun / (flujoAgregado * 1000); 
    // Nota: se asume 1 tonelada = 1000 kg, y betún densidad ~1 kg/L

    cout << "\n--- Resultados ---" << endl;
    cout << "Proporción betún/agregado: " << ratio * 100 << " %" << endl;

    // Verificación de temperatura
    if (temperatura < tempMin) {
        cout << "ALERTA: Temperatura demasiado baja, mezcla no adecuada." << endl;
    } else if (temperatura > tempMax) {
        cout << "ALERTA: Temperatura demasiado alta, riesgo de oxidación." << endl;
    } else {
        cout << "Temperatura dentro del rango óptimo." << endl;
    }

    // Verificación de proporción
    if (ratio < ratioMin) {
        cout << "ALERTA: Falta de betún, mezcla seca." << endl;
    } else if (ratio > ratioMax) {
        cout << "ALERTA: Exceso de betún, mezcla blanda." << endl;
    } else {
        cout << "Proporción dentro del rango óptimo." << endl;
    }

    cout << "Proceso simulado finalizado." << endl;
    return 0;
}