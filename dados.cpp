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

void mostrarDados(int vDados[], int dadosDisponibles)
{
    for (int i = 0; i < dadosDisponibles; i++)
    {
        cout << " " << vDados[i];
    }

    cout << endl;
}
