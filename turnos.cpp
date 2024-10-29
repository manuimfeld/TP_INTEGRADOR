#include <iostream>
#include "tirada.h"
#include "dados.h"
#include "puntaje.h"

int ejecutarTurnoJugador(string nombreJugador, int dados[], int &dadosDisponibles, int bloqueador1, int bloqueador2, int &puntajeTotal)
{
    int puntajeRonda = 0; // Acá vamos a ir guardando el puntaje de la ronda
    int tiradaActual = 0;
    bool continuarTirada = true;

    // Cada vez que empiece una tirada o el jugador tenga dados disponibles, se ejecutan las siguientes funciones del bucle
    while (continuarTirada && dadosDisponibles > 0)
    {
        tiradaActual++;
        int puntajeTirada = ejecutarTirada(dados, dadosDisponibles, bloqueador1, bloqueador2, tiradaActual, puntajeRonda); // Guardamos el puntaje de la tirada
        dadosDisponibles -= calcularDadosDisponibles(dados, dadosDisponibles, bloqueador1, bloqueador2); // Si hubo algun dado igual a un bloqueador, restamos los dados disponibles

        if (dadosDisponibles == 0)
        {
            cout << "Te quedaste sin dados disponibles, el puntaje de la ronda vuelve a 0" << endl;
            puntajeRonda = 0; // Puntaje a cero si se queda sin dados
            continuarTirada = false;
        }

        else if (multiplicarDados(dados, dadosDisponibles, bloqueador1, bloqueador2))
        {
            cout << "Que suerte!!!, tus dados fueron todos iguales, tus puntos se multiplican." << endl;
            puntajeTotal += puntajeTirada * 2;
            puntajeRonda += puntajeTirada * 2;
            cout << "---------------------" << endl;
            cout << "Puntaje de la ronda: " << puntajeRonda << endl;
            cout << "Puntaje total: " << puntajeTotal << endl;
            continuarTirada = true;
        } 

        else
        {
            puntajeRonda += puntajeTirada;   
            puntajeTotal += puntajeTirada; // Sumamos este puntaje al TOTAL de la partida (el puntaje que obtuvo a lo largo de las rondas)
            cout << "---------------------" << endl;
            cout << "Puntaje de la ronda: " << puntajeRonda << endl;
            cout << "Puntaje total: " << puntajeTotal << endl;
            continuarTirada = nuevaTirada(); // Le preguntamos al jugador si quiere una tirada más
        }
    }
    return puntajeRonda;
}