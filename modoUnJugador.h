#pragma once
#include <string>

using namespace std;

string nombreJugador();
void jugarModoSolitario(string nombreJugador, string &actualMejorJugador, int &actualMejorPuntuacion);
bool nuevaTirada();
int calcularPuntaje(int vDados[5], int dadosDisponibles, int bloqueador1, int bloqueador2);