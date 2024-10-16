#include <iostream>
#include "juego.h"

using namespace std;

int tirarDado()
{
    return rand() % 6 + 1;
}

void tiradaDeDados(int vDados[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        vDados[i] = tirarDado();
    }
}

void mostrarDados(int vDados[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << " " << vDados[i];
    }

    cout << endl;
}

int calcularPuntaje(int vDados[], int cantidad, int bloqueador1, int bloqueador2)
{
    int puntos = 0;


    for (int i = 0; i < cantidad; i++)
    {
        if (vDados[i] != bloqueador1 && vDados[i] != bloqueador2)
        {
            puntos += vDados[i]; // Suma los puntos de los dados que no sean igual a los bloqueadores
        }
    }


    return puntos;
}

int ejecutarRonda(int jugador, int bloqueador1, int bloqueador2)
{
    int dados[5], puntajeRonda;

    tiradaDeDados(dados, 5);
    cout << "Jugador #" << jugador << " - Dados: ";
    mostrarDados(dados, 5);
    puntajeRonda = calcularPuntaje(dados, 5, bloqueador1, bloqueador2);
    cout << "Puntos de la ronda jugador #" << jugador << ": " << puntajeRonda << endl;

    return puntajeRonda;
}
void jugar(int &estadisticasGanador, int &estadisticasRondas)
{
    int dados[5], puntajeRonda1, puntajeRonda2, puntajeTotal1 = 0, puntajeTotal2 = 0;
    int cantidadRondas = 0;
    do
    {
        cantidadRondas++;
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "Ronda #" << cantidadRondas << endl;

        // Bloqueadores diferentes para cada jugador
        int bloqueador1Jugador1 = tirarDado();
        int bloqueador2Jugador1 = tirarDado();
        int bloqueador1Jugador2 = tirarDado();
        int bloqueador2Jugador2 = tirarDado();

        // jugador1 - puntos, bloqueadores
        cout << "Jugador #1 - Bloqueador 1: " << bloqueador1Jugador1 << " | Bloqueador 2: " << bloqueador2Jugador1 << endl;
        puntajeTotal1 += ejecutarRonda(1, bloqueador1Jugador1, bloqueador2Jugador1);
        cout << "Puntaje total jugador #1: " << puntajeTotal1 << endl;

        // jugador2 - puntos, bloqueadores
        cout << "Jugador #2 - Bloqueador 1: " << bloqueador1Jugador2 << " | Bloqueador 2: " << bloqueador2Jugador2 << endl;
        puntajeTotal2 += ejecutarRonda(2, bloqueador1Jugador2, bloqueador2Jugador2);
        cout << "Puntaje total jugador #2: " << puntajeTotal2 << endl;
    }
    while(puntajeTotal1 < 25 && puntajeTotal2 < 25);
}
