#include <iostream>
#include "dados.h"

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
    cout << "Dados:";
    for (int i = 0; i < dadosDisponibles; i++)
    {
        if (vDados[i] == bloqueador1 || vDados[i] == bloqueador2)
        {
            cout << " " << "\033[31m" << vDados[i] << "\033[0m"; // Si el dado es igual a algun bloqueador, lo mostramos en rojo
        }
        else
        {
            cout << " " << vDados[i];
        }
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
