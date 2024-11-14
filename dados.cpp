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
    int posx = 1, posy = 10; // Posición inicial de los dados
    for (int i = 0; i < dadosDisponibles; i++)
    {
        int dadoPosX = posx + i * 10; // Ajuste el espaciado horizontal entre dados
        int dadoPosY = posy;          // Mantiene todos los dados en la misma fila

        if (vDados[i] == bloqueador1 || vDados[i] == bloqueador2)
        {
            rlutil::setColor(rlutil::RED); // Si el dado es igual a algún bloqueador, lo mostramos en rojo
            dibujarDados(vDados[i], dadoPosX, dadoPosY);
        }
        else
        {
            rlutil::setColor(rlutil::WHITE); // Mostramos los otros dados de color blanco
            dibujarDados(vDados[i], dadoPosX, dadoPosY);
        }
        rlutil::resetColor(); // Restablecemos el color después de cada dado
    }

    cout << endl; // Salto de línea después de mostrar todos los dados
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

/*
mostrar dados originales

void mostrarDados(int vDados[], int dadosDisponibles, int bloqueador1, int bloqueador2)
{
    for (int i = 0; i < dadosDisponibles; i++)
    {
        if (vDados[i] == bloqueador1 || vDados[i] == bloqueador2)
        {
            cout << " " << "\033[31m" << vDados[i] << "\033[35m"; // Si el dado es igual a algun bloqueador, lo mostramos en rojo
        }
        else
        {
            cout << " " << vDados[i];
        }
    }
*/