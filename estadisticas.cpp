#include <iostream>

using namespace std;

void actualizarEstadisticas(string &actualMejorJugador, int &actualMejorPuntuacion, string jugador, int puntuacion)
{
    if (puntuacion > actualMejorPuntuacion) // Si la puntuacion es mayor a la que alguien hizo antes, se actualiza para mostrar en estadisticas
    {
        actualMejorJugador = jugador;
        actualMejorPuntuacion = puntuacion;
    }
}

void mostrarEstadisticas(string actualMejorJugador, int actualMejorPuntuacion)
{
    system("cls");
    cout << "-----------------------------" << endl;
    cout << "El mejor jugador hasta ahora fue: " << actualMejorJugador << endl;
    cout << "Y su puntuacion fue: " << actualMejorPuntuacion << endl;
}