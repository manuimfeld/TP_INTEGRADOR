#include "dados.h"
#include "tirada.h"
#include "puntaje.h"
#include "ronda.h"
#include "estadisticas.h"
#include "menu.h"
#include "modosdejuego.h"
#include <iostream>
#include "mensajes.h"
#include "turnos.h"
#include "modoDosJugadores.h"

using namespace std;

void modoDosJugadores(string nombreJugador1, string nombreJugador2, string &actualMejorJugador, int &actualMejorPuntuacion) 
{
    system("cls");
    int dados[5];
    int dadosDisponibles = 5;
    int rondaActual = 0;
    int puntajeTotalJugador1 = 0;
    int puntajeTotalJugador2 = 0;
    bool continuarRonda = true;
    bool turnoJugador1 = true; /// Indicador de quien tiene el turno (true para jugador1, false para jugador2)

    /// Empezamos las rondas, alternando entre los dos jugadores
    while (continuarRonda) {
        rondaActual++;
        int bloqueador1, bloqueador2;
        iniciarBloqueadores(bloqueador1, bloqueador2);  /// Generamos los bloqueadores de la ronda


    /// Determinar el nombre del jugador que tiene el turno

        string nombreJugador;
        int puntajeTotal;

        if (turnoJugador1) {
            nombreJugador = nombreJugador1;
            puntajeTotal = puntajeTotalJugador1;
        } else {
            nombreJugador = nombreJugador2;
            puntajeTotal = puntajeTotalJugador2;
        }


        cout << "Turno de: " << nombreJugador << endl;
        cout << "------------" << endl;
        cout << "Ronda: " << rondaActual << endl;
        cout << "Bloqueadores: " << bloqueador1 << " " << bloqueador2 << endl;

        /// Ejecutamos el turno del jugador, y calculamos el puntaje de esa ronda
        int puntajeRonda = ejecutarTurnoJugador(nombreJugador, dados, dadosDisponibles, bloqueador1, bloqueador2, puntajeTotal);

        /// Preguntamos si el jugador desea continuar con una nueva ronda
        continuarRonda = finalizarRonda(puntajeRonda, puntajeTotal, rondaActual);

        /// Si el puntaje del jugador es mayor que el mejor puntaje hasta ahora, actualizamos las estadísticas
        if (puntajeTotal > actualMejorPuntuacion) {
            actualizarEstadisticas(actualMejorJugador, actualMejorPuntuacion, nombreJugador, puntajeTotal);
        }

        /// Cambiamos de turno entre los jugadores
        turnoJugador1 =!turnoJugador1;

        dadosDisponibles = 5;  /// Reiniciamos los dados disponibles al empezar la siguiente ronda
    }

    /// Finalizamos la partida, mostrando los puntajes totales de ambos jugadores

    cout << "Partida finalizada." << endl;
    cout << "Puntaje total de " << nombreJugador1 << ": " << puntajeTotalJugador1 << " puntos" << endl;
    cout << "Puntaje total de " << nombreJugador2 << ": " << puntajeTotalJugador2 << " puntos" << endl;

    /// Determinamos quién ganó

    if (puntajeTotalJugador1 > puntajeTotalJugador2) {
        cout << nombreJugador1 << " ha ganado la partida!" << endl;
    } else if (puntajeTotalJugador2 > puntajeTotalJugador1) {
        cout << nombreJugador2 << " ha ganado la partida!" << endl;
    } else {
        cout << "La partida ha terminado en empate!" << endl;
    }

}
