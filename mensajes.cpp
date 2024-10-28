#include <iostream>

using namespace std;

void mostrarPuntajeRonda(int puntajeTotalRonda, int puntajeTotal)
{
    cout << "Puntaje total de la ronda: " << puntajeTotalRonda << endl;
    cout << "Puntaje total de la partida: " << puntajeTotal << endl;
}

void mostrarResultadosFinales(int rondaActual, int puntajeTotalRonda, int puntajeTotal)
{
    cout << "-----------------------------" << endl;
    cout << "Fin de la ronda #" << rondaActual << endl;
    cout << "Puntaje total de la ronda: " << puntajeTotalRonda << endl;
    cout << "Puntaje total de la partida: " << puntajeTotal << endl;
}