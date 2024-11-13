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
    int puntajeTotal = 0; // Acá vamos a guardar los puntos que sumamos a lo largo de todas las rondas y tiradas
    int rondasrestantes = 3;

    // Cada vez que empiece una ronda, se ejecutan las siguientes funciones del bucle
    while (rondasrestantes > 0)
    {
        rondaActual++;
        int bloqueador1, bloqueador2;
        iniciarBloqueadores(bloqueador1, bloqueador2); // Guardamos los bloqueadores de la ronda

        cout << "Turno de: " << nombreJugador << endl;
        cout << "------------" << endl;
        cout << "Ronda: " << rondaActual << endl;
        cout << "Bloqueadores: " << bloqueador1 << " " << bloqueador2 << endl;

        // Se inician las tiradas del jugador (ejecutarTurnoJugador)
        // IMPORTANTE: leer bien la función por dentro
        // Esta misma se encarga se preguntarle al jugador si quiere nuevas tiradas, al final, devuelve un numero (la puntuación total de todas las tiradas)
        int puntajeRonda = ejecutarTurnoJugador(nombreJugador, dados, dadosDisponibles, bloqueador1, bloqueador2, puntajeTotal); // Guardamos el puntaje de la ronda al finalizar las tiradas

        rondasrestantes = calcularRondasRestantes(rondasrestantes);

        if (puntajeTotal > actualMejorPuntuacion)
        {
            actualizarEstadisticas(actualMejorJugador, actualMejorPuntuacion, nombreJugador, puntajeTotal);
        }

        dadosDisponibles = 5; // Al iniciar una nueva ronda, reiniciamos los dados disponibles y se vuelven a ejecutar las funciones del bucle de principio a fin
    }
    cout << "Partida finalizada. Puntaje total: " << puntajeTotal << " puntos" << endl;
}