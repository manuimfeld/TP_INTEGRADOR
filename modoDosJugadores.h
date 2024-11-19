#pragma once

using namespace std;

string nombreJugador1();
string nombreJugador2();
bool nuevaTirada();
int calcularPuntaje(int vDados[5], int dadosDisponibles, int bloqueador1, int bloqueador2);
void modoDosJugadores(string nombreJugador1, string nombreJugador2, string &actualMejorJugador, int &actualMejorPuntuacion);