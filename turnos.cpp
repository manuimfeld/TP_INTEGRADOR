#include <iostream>
#include "tirada.h"
#include "dados.h"

int ejecutarTurnoJugador(string nombreJugador, int dados[], int &dadosDisponibles, int bloqueador1, int bloqueador2)
{
    int puntajeTurno = 0;
    bool continuarTirada = true;

    while (continuarTirada && dadosDisponibles > 0)
    {
        cout << "Turno de " << nombreJugador << endl;
        int puntajeTirada = ejecutarTirada(dados, dadosDisponibles, bloqueador1, bloqueador2);
        puntajeTurno += puntajeTirada;

        dadosDisponibles -= calcularDadosDisponibles(dados, dadosDisponibles, bloqueador1, bloqueador2);
        continuarTirada = (dadosDisponibles > 0) ? nuevaTirada() : false;

        if (dadosDisponibles == 0)
        {
            cout << "Sin dados disponibles. Puntaje de turno reiniciado." << endl;
            puntajeTurno = 0; // Puntaje a cero si se queda sin dados
        }
    }
    return puntajeTurno;
}