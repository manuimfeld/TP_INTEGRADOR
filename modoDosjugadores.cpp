#include "dados.h"
#include "tirada.h"
#include "puntaje.h"
#include "ronda.h"
#include "estadisticas.h"
#include "menu.h"
#include "modoUnJugador.h"
#include <iostream>
#include "mensajes.h"
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

        cout << "Turno de: " << nombreJugador1 << endl;
        cout << "------------" << endl;
        cout << "Ronda: " << rondaActual << endl;
        cout << "Bloqueadores: " << bloqueador1 << " " << bloqueador2 << endl;

      
        int puntajeRonda = ejecutarTurnoJugador(nombreJugador1, dados, dadosDisponibles, bloqueador1, bloqueador2, puntajeTotal1); 

        if (puntajeTotal1 > actualMejorPuntuacion)
        {
            actualizarEstadisticas(actualMejorJugador, actualMejorPuntuacion, nombreJugador1, puntajeTotal1);
        }
        

        dadosDisponibles = 5;
        iniciarBloqueadores(bloqueador1, bloqueador2); 

        cout << "Turno de: " << nombreJugador2 << endl;
        cout << "------------" << endl;
        cout << "Ronda: " << rondaActual << endl;
        cout << "Bloqueadores: " << bloqueador1 << " " << bloqueador2 << endl;

        puntajeRonda = ejecutarTurnoJugador(nombreJugador2, dados, dadosDisponibles, bloqueador1, bloqueador2, puntajeTotal2); 

        if (puntajeTotal2 > actualMejorPuntuacion)
        {
            actualizarEstadisticas(actualMejorJugador, actualMejorPuntuacion, nombreJugador2, puntajeTotal2);
        }

        system("cls");

        dadosDisponibles = 5;
        rondasrestantes = calcularRondasRestantes(rondasrestantes);
    }

    

    cout << "Partida Finalizada" << endl;
    cout << "Puntaje total jugador 1: " << puntajeTotal1 << " puntos" << endl;
    cout << "Puntaje total jugador 2: " << puntajeTotal2 << " puntos" << endl;

    if (puntajeTotal1 > puntajeTotal2)
    {
        cout << "Felicidades a " << nombreJugador1 << " por la victoria, te ganaste un chocolate" << endl;
    }
    else if (puntajeTotal2 < puntajeTotal1)
    {
        cout << "Felicidades a " << nombreJugador2 << " por la victoria, te ganaste un chocolate" << endl;
    }
}

