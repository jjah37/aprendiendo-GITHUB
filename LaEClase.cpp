#include<iostream>
#include<string>
using namespace std;

class Empleado {

public:
    
    string nombre, primerApellido;
    float sueldoAnual;
    static const int numPagos = 12;
    float calcularSueldoMensual();
    string nombreCompleto();

private:
    
};

int main(){

    // Manejo automatico de memoria
    Empleado *empleado1 = new Empleado();
    empleado1->nombre = "Luis";
    empleado1->primerApellido = "Garces";
    empleado1->sueldoAnual = 80000.50;

    cout << "El sueldo anual de empleado 1  " << empleado1-> nombreCompleto() <<  " es  " << empleado1-> calcularSueldoMensual();


    return 0;
}

float Empleado::calcularSueldoMensual() {

    return (sueldoAnual/numPagos);

}

string Empleado::nombreCompleto() {

    return (nombre + " " + primerApellido);

}
