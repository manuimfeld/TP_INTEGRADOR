#include <iostream>
#include "dados.h"

using namespace std;

int tirarDado()
{
    return rand() % 6 + 1;
}

void tiradaDeDados(int vDados[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        vDados[i] = tirarDado();
    }
}

void mostrarDados(int vDados[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << " " << vDados[i];
    }

    cout << endl;
}
