#include <iostream>
#include "dados.h"
#include "rlutil.h"
#include "dibujos.h"

using namespace std;

int tirarDado()
{
    return rand() % 6 + 1;
}

void tiradaDeDados(int vDados[], int dadosDisponibles)
{
    for (int i = 0; i < dadosDisponibles; i++)
    {
        vDados[i] = tirarDado();
    }
}

void mostrarDados(int vDados[], int dadosDisponibles, int bloqueador1, int bloqueador2)
{
    bool fueBloqueado = false;
    int posx = 1, posy = 10; // Posición inicial de los dados (X e Y)
    for (int i = 0; i < dadosDisponibles; i++)
    {
        int dadoPosX = posx + i * 13; // Aumentamos el espaciado horizontal a 13
        int dadoPosY = posy;          // No aumentamos nada para tener todos los dados en la misma fila sin overflow

        if (vDados[i] == bloqueador1 || vDados[i] == bloqueador2)
        {
            fueBloqueado = true;
            dibujarDados(vDados[i], dadoPosX, dadoPosY, fueBloqueado);
        }
        else
        {
            fueBloqueado = false;
            dibujarDados(vDados[i], dadoPosX, dadoPosY, fueBloqueado);
        }
        rlutil::resetColor();
        // Reseteamos el color después de cada dado
    }

    cout << endl;
}

void mostrarBloqueadores(int bloqueador1, int bloqueador2)
{
    cout << "Bloqueadores: " << bloqueador1 << " " << bloqueador2 << endl;
};

int calcularDadosDisponibles(int vDados[], int dadosDisponibles, int bloqueador1, int bloqueador2)
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
