#include <iostream>
#include "reglas.h"

using namespace std;


void reglas()
{
    cout << "Las reglas del juego son las siguientes: " << endl;
    cout << "El juego consiste en una serie de tres rondas, en las cuales los jugadores deberán tirar dos dados llamados bloqueadores y ";
    cout << "numerosas tiradas de hasta cinco dados." << endl << endl;
    cout << "Por cada tirada de una ronda se deberan sumar todos los dados de la tirada cuyos valores no coincidan con los dados bloqueadores." << endl << endl;
    cout << "Cada dado cuyo valor sea igual al de un bloqueador, no podrá utilizarse en las siguientes tiradas de la ronda.";
    cout << "Disminuyendo asi la cantidad de dados a tirar." << endl << endl;
    cout << "Al finalizar cada tirada se preguntara si desea continuar tirando o no" << endl << endl;
    cout << "Si un jugador obtiene todos los dados iguales y estos no son iguales a los bloqueadores";
    cout << "Se duplicara el puntaje obtenido esa tirada pero estara obligado a tirar nuevamente" << endl << endl;
    cout << "La ronda tambien finaliza si el jugador se queda sin dados disponibles, en cuyo caso su puntaje pasara a ser 0" << endl << endl;
    cout << "Ganara el jugador que mas puntos haya realizado al finalizar las tres rondas" << endl << endl;
    cout << "Pulse 0 para continuar con el juego"<< endl << endl;
}