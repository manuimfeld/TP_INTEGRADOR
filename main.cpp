#include <iostream>
#include <ctime>
#include "menu.h"
#include "juego.h"

using namespace std;



int main()
{
     int estadisticasGanador=0, estadisticasRondas=0;
     srand(time(0));

menu(estadisticasGanador, estadisticasRondas);

return 0;
}
