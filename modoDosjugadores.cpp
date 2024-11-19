#include "dados.h"
#include "tirada.h"
#include "puntaje.h"
#include "ronda.h"
#include "estadisticas.h"
#include "menu.h"
#include "modoUnJugador.h"
#include <iostream>
#include "turnos.h"
#include "modoDosJugadores.h"

void modoDosJugadores(string nombreJugador2, string nombreJugador1, string &actualMejorJugador, int &actualMejorPuntuacion)
{
    system("cls");
    int dados[5];
    int dadosDisponibles = 5;
    int rondaActual = 0;
    int puntajeTotal1 = 0;
    int puntajeTotal2 = 0;
    int rondasrestantes = 3;

    while (rondasrestantes > 0)
    {
        rondaActual++;
        int bloqueador1, bloqueador2;
        iniciarBloqueadores(bloqueador1, bloqueador2);

        int puntajeRonda = ejecutarTurnoJugador(rondaActual, nombreJugador1, dados, dadosDisponibles, bloqueador1, bloqueador2, puntajeTotal1);

        if (puntajeTotal1 > actualMejorPuntuacion)
        {
            actualizarEstadisticas(actualMejorJugador, actualMejorPuntuacion, nombreJugador1, puntajeTotal1);
        }

        system("cls");

        dadosDisponibles = 5;
        iniciarBloqueadores(bloqueador1, bloqueador2);

        puntajeRonda = ejecutarTurnoJugador(rondaActual, nombreJugador2, dados, dadosDisponibles, bloqueador1, bloqueador2, puntajeTotal2);

        if (puntajeTotal2 > actualMejorPuntuacion)
        {
            actualizarEstadisticas(actualMejorJugador, actualMejorPuntuacion, nombreJugador2, puntajeTotal2);
        }

        system("cls");

        dadosDisponibles = 5;
        rondasrestantes = calcularRondasRestantes(rondasrestantes);
    }

    cout << "Partida Finalizada" << endl
         << endl;
    cout << "Puntaje total de " << nombreJugador1 << puntajeTotal1 << " puntos" << endl
         << endl;
    cout << "Puntaje total de " << nombreJugador2 << puntajeTotal2 << " puntos" << endl
         << endl;

    if (puntajeTotal1 > puntajeTotal2)
    {
        cout << "Felicidades a " << nombreJugador1 << " por la victoria, te ganaste un aplauso del profe" << endl
             << endl;
    }
    else if (puntajeTotal2 > puntajeTotal1)
    {
        cout << "Felicidades a " << nombreJugador2 << " por la victoria, te ganaste un aplauso del profe" << endl
             << endl;
    }
    else
    {
        cout << "Tenemos un empate, jueguen de nuevo" << endl;
    }
}
