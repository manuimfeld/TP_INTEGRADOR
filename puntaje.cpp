#include <iostream>
#include "puntaje.h"

using namespace std;

bool multiplicarDados(int vDados[5], int dadosDisponibles, int bloqueador1, int bloqueador2)
{
    int dadosIguales = 0;
    
    for (int i = 0; i < dadosDisponibles; i++)
    {
        if (vDados[i] != bloqueador1 && vDados[i] != bloqueador2 && vDados[i] == vDados[0])
        {
            dadosIguales++;
        }
    }
        if (dadosDisponibles > 1 && dadosIguales == dadosDisponibles)
        {
            return true;
        }

    return false;
                         
}

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