#include <iostream>
#include <limits>
#include "dados.h"
#include "juego.h"
#include "ronda.h"
#include "tirada.h"
#include "puntaje.h"
#include "mensajes.h"

using namespace std;

int ejecutarTirada(int dados[5], int dadosDisponibles, int bloqueador1, int bloqueador2)
{
    tiradaDeDados(dados, dadosDisponibles);                                                 // Tirada de dados
    int puntajeTirada = calcularPuntaje(dados, dadosDisponibles, bloqueador1, bloqueador2); // Calcular el puntaje de la tirada

    // Mostrar los bloqueadores, dados y puntaje de tirada
    mostrarResultadosTirada(dados, dadosDisponibles, bloqueador1, bloqueador2, puntajeTirada);

    return puntajeTirada; // Devuelve el puntaje de la tirada, para sumar en puntajeTotalRonda (en jugarModoSolitario)
}

void jugarModoSolitario(string nombreJugador)
{
    int dados[5];
    int dadosDisponibles = 5;
    int rondaActual = 0;
    int puntajeTotal = 0; // Total acumulado de todas las rondas

    bool continuarRonda = true;

    // Se ejecuta el bucle cuando arranca la partida o si el usuario quiere seguir jugando la imsma ronda
    while (continuarRonda)
    {
        rondaActual++;
        int puntajeTotalRonda = 0; // Puntaje acumulado en la ronda actual
        int tiradaActual = 0;
        bool continuarTirada = true;

        cout << "-----------------------------" << endl;
        cout << "Ronda #" << rondaActual << endl;

        // Generamos los bloqueadores para la ronda
        int bloqueador1 = tirarDado();
        int bloqueador2 = tirarDado();

        // Se ejecuta el siguiente bucle siempre y cuando el jugador quiera seguir una tirada más (decisión al final)
        while (continuarTirada && dadosDisponibles > 0)
        {
            tiradaActual++;

            // Mostramos el número de la tirada y el nombre del jugador
            cout << "Tirada #" << tiradaActual << " del jugador: " << nombreJugador << endl;
            cout << endl;

            // // Se ejecuta la tirada y sumamos la puntuación
            int puntajeTirada = ejecutarTirada(dados, dadosDisponibles, bloqueador1, bloqueador2);
            puntajeTotalRonda += puntajeTirada;

            cout << "Puntaje total de la ronda: " << puntajeTotalRonda << endl;

            // Actualizamos los dados disponibles
            dadosDisponibles -= calcularDadosDisponibles(dados, dadosDisponibles, bloqueador1, bloqueador2);

            if (dadosDisponibles > 0)
            {
                continuarTirada = nuevaTirada(); // Le preguntamos al jugador si quiere una nueva tirada de dados en esta ronda
            }
            else
            {
                cout << "Te quedaste sin dados, tu puntaje en esta ronda fue 0" << endl;
                puntajeTotalRonda = 0;   // Aseguramos que el puntaje de la ronda sea 0
                continuarTirada = false; // Salimos del bucle de tiradas
            }
        }

        // Sumamos el puntaje de la ronda al total de la partida
        puntajeTotal += puntajeTotalRonda;

        // Mostrar los resultados finales de la ronda
        mostrarResultadosFinales(rondaActual, puntajeTotalRonda, puntajeTotal);

        // Le preguntamos al jugador si quiere otra ronda (tenga o no dados disponibles)
        continuarRonda = nuevaRonda();

        // Se reinician los dados disponibles para la siguiente ronda
        if (continuarRonda)
        {
            dadosDisponibles = 5;
        }
    }

    // Finalizamos el juego
    cout << "Partida finalizada." << endl;
    cout << "Tu puntuacion en esta partida fue de: " << puntajeTotal << " puntos" << endl;
}