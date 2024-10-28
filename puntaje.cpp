#include <iostream>

using namespace std;

int calcularPuntaje(int vDados[5], int dadosDisponibles, int bloqueador1, int bloqueador2)
{
    int puntos = 0;
    int dadosIguales = 0;

    for (int i = 0; i < dadosDisponibles; i++)
    {
        if (vDados[i] != bloqueador1 && vDados[i] != bloqueador2)
        {
            puntos += vDados[i]; // Suma los puntos de los dados que no sean igual a los bloqueadores
            dadosIguales ++;
        }
    }
        
        if (dadosIguales == dadosDisponibles)
        {
            return puntos = puntos * 2;
            
        }

    return puntos;
}