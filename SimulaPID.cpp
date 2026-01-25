#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

class PID {
private:
    double Kp, Ki, Kd;   // Ganancias proporcional, integral y derivativa
    double prevError;    // Error anterior
    double integral;     // Acumulador integral

public:
    PID(double Kp, double Ki, double Kd) {
        this->Kp = Kp;
        this->Ki = Ki;
        this->Kd = Kd;
        prevError = 0.0;
        integral = 0.0;
    }

    double calculate(double setpoint, double processVariable, double dt) {
        double error = setpoint - processVariable;
        integral += error * dt;
        double derivative = (error - prevError) / dt;
        prevError = error;

        // Señal de control
        return Kp * error + Ki * integral + Kd * derivative;
    }
};

int main() {
    // Parámetros del PID (ajustables según el proceso)
    PID controller(1.2, 0.4, 0.1);

    double setpoint = 100.0;   // Valor deseado (ej. temperatura en °C)
    double processVariable = 20.0; // Valor inicial del proceso
    double dt = 1.0;           // Intervalo de tiempo (segundos)

    cout << fixed << setprecision(2);
    cout << "Simulacion de Control PID en un proceso industrial\n";
    cout << "Setpoint: " << setpoint << " °C\n\n";

    // Simulación de 20 iteraciones
    for (int t = 0; t < 20; t++) {
        double controlSignal = controller.calculate(setpoint, processVariable, dt);

        // Modelo simple del proceso: la señal de control afecta la variable
        processVariable += controlSignal * 0.1; // factor de respuesta del sistema

        cout << "Tiempo " << t << "s -> PV: " << processVariable 
             << " °C | Control: " << controlSignal << endl;
    }

    return 0;
}