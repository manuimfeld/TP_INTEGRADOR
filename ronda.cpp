#include <iostream>
#include <limits>
#include "dados.h"

using namespace std;

void iniciarBloqueadores(int &bloqueador1, int &bloqueador2)
{
    bloqueador1 = tirarDado();
    bloqueador2 = tirarDado();
}

int calcularRondasRestantes(int rondasrestantes)
{
rondasrestantes -=1;
return rondasrestantes;

}