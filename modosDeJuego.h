#pragma once
#include <string>

using namespace std;

string nombreJugador();
void jugarModoSolitario(string nombreJugador, string &actualMejorJugador, int &actualMejorPuntuacion);
bool nuevaTirada();
bool nuevaRonda();
int ejecutarTirada(int dados[5], int dadosDisponibles, int bloqueador1, int bloqueador2);
int calcularPuntaje(int vDados[5], int dadosDisponibles, int bloqueador1, int bloqueador2);