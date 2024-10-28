#include <iostream>
#include <limits>
#include "dados.h"
#include "ronda.h"
#include "tirada.h"
#include "puntaje.h"
#include "mensajes.h"
#include "estadisticas.h"
#include "turnos.h"

using namespace std;

void jugarModoSolitario(string nombreJugador, string &actualMejorJugador, int &actualMejorPuntuacion)
{
    system("cls");
    int dados[5];
    int dadosDisponibles = 5;
    int rondaActual = 0;
    int puntajeTotal = 0;
    bool continuarRonda = true;

    while (continuarRonda)
    {
        rondaActual++;
        int bloqueador1, bloqueador2;
        iniciarRonda(bloqueador1, bloqueador2);

        int puntajeTurno = ejecutarTurnoJugador(nombreJugador, dados, dadosDisponibles, bloqueador1, bloqueador2);
        continuarRonda = finalizarRonda(puntajeTurno, puntajeTotal, rondaActual);

        if (puntajeTotal > actualMejorPuntuacion)
        {
            actualizarEstadisticas(actualMejorJugador, actualMejorPuntuacion, nombreJugador, puntajeTotal);
        }

        dadosDisponibles = 5; // Reiniciar dados para la próxima ronda
    }
    cout << "Partida finalizada. Puntaje total: " << puntajeTotal << " puntos" << endl;
}