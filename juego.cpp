#include <iostream>
#include <limits>
#include "dados.h"
#include "juego.h"
#include "ronda.h"
#include "tirada.h"

using namespace std;

int calcularPuntaje(int vDados[5], int dadosDisponibles, int bloqueador1, int bloqueador2)
{
    int puntos = 0;

    for (int i = 0; i < dadosDisponibles; i++)
    {
        if (vDados[i] != bloqueador1 && vDados[i] != bloqueador2)
        {
            puntos += vDados[i]; // Suma los puntos de los dados que no sean igual a los bloqueadores
        }
    }

    return puntos;
}

int calcularBloqueados(int vDados[], int dadosDisponibles, int bloqueador1, int bloqueador2)
{
    int bloqueados = 0;

    for (int i = 0; i < dadosDisponibles; i++)
    {
        if (vDados[i] == bloqueador1 || vDados[i] == bloqueador2)
        {
            bloqueados++;
        }
    }

    return bloqueados;
}

int ejecutarTirada(int dados[5], int dadosDisponibles, int bloqueador1, int bloqueador2)
{
    int puntajeTirada;

    tiradaDeDados(dados, dadosDisponibles);                                             // Generar los dados
    puntajeTirada = calcularPuntaje(dados, dadosDisponibles, bloqueador1, bloqueador2); // Calcular el puntaje de la tirada

    // Mostrar los bloqueadores, dados y puntaje de tirada
    cout << "Bloqueadores: " << bloqueador1 << " " << bloqueador2 << endl;
    cout << "Dados: ";
    mostrarDados(dados, dadosDisponibles);
    cout << endl;
    cout << "Puntaje de la tirada: " << puntajeTirada << endl;

    return puntajeTirada; // Devuelve el puntaje de la tirada, para sumar en puntajeTotalRonda (en jugarModoSolitario)
}

void jugarModoSolitario(string nombreJugador)
{
    int dados[5];
    int rondaActual = 0;
    int puntajeTotal = 0; // Total acumulado de todas las rondas
    int dadosDisponibles = 5;
    bool continuarRonda = true;

    // Si la ronda se sigue jugando, se ejecuta el bucle
    while (continuarRonda)
    {
        rondaActual++;
        int puntajeTotalRonda = 0; // Puntaje acumulado en la ronda actual
        bool continuarTirada = true;
        int tiradaActual = 0;

        cout << "-----------------------------" << endl;
        cout << "Ronda #" << rondaActual << endl;

        // Generamos los bloqueadores para la nueva ronda
        int bloqueador1 = tirarDado();
        int bloqueador2 = tirarDado();

        // Se ejecuta una tirada de dados para la ronda, siempre que el jugador quiera o tenga dados disponibles
        while (continuarTirada)
        {
            tiradaActual++;

            // Mostramos el número de la tirada
            cout << "Tirada #" << tiradaActual << " del jugador: " << nombreJugador << endl;
            cout << endl;

            // Ejecutar la tirada y obtener su puntaje y dados
            int puntajeTirada = ejecutarTirada(dados, dadosDisponibles, bloqueador1, bloqueador2);

            // Sumamos el puntaje de la tirada al puntaje total de la ronda
            puntajeTotalRonda += puntajeTirada;

            // Mostramos los puntos totales acumulados de la ronda
            cout << "Puntaje total de la ronda: " << puntajeTotalRonda << endl;

            dadosDisponibles -= calcularBloqueados(dados, dadosDisponibles, bloqueador1, bloqueador2);

            if (dadosDisponibles > 0)
            {
                continuarTirada = nuevaTirada(); // Le preguntamos al jugador si quiere una nueva tirada de dados en esta ronda
            }
            else
            {
                puntajeTotalRonda = 0;
                break;
            }
        }

        // **
        // ** HAY QUE OMITIR LA SEGUNDA nuevaRonda() (LINEA 218 a 229 cuando el usuario ya no tiene puntajetotalronda 0)
        // **
        if (puntajeTotalRonda == 0)
        {
            cout << "Fin de la ronda #" << rondaActual << endl;
            cout << "Te quedaste sin dados, tu puntaje en esta ronda fue 0" << endl;
            cout << "Puntaje total de la partida hasta ahora: " << puntajeTotal << endl;
            dadosDisponibles = 5;
            continuarRonda = nuevaRonda();
        }

        // Sumamos el puntaje de la ronda en el puntaje total de la partida
        puntajeTotal += puntajeTotalRonda;

        // Mostrar el puntaje total acumulado al final de la ronda
        cout << "Fin de la ronda #" << rondaActual << endl;
        cout << endl;
        cout << "Puntaje total de la ronda: " << puntajeTotalRonda << endl;
        cout << "Puntaje total de la partida: " << puntajeTotal << endl;

        // Le preguntamos al jugador si quiere jugar otra ronda

        continuarRonda = nuevaRonda();
    }

    cout << "Partida finalizada." << endl;
    cout << "Tu puntuacion en esta partida fue de: " << puntajeTotal << " puntos" << endl;
}