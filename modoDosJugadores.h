#pragma once

using namespace std;

string nombreJugador1();
strin nombreJugador2();
bool nuevaTirada();
bool nuevaRonda();
int ejecutarTirada(int dados[5], int dadosDisponibles, int bloqueador1, int bloqueador2);
int calcularPuntaje(int vDados[5], int dadosDisponibles, int bloqueador1, int bloqueador2);
void modoDosJugadores(string nombreJugador1, string nombreJugador2, string &actualMejorJugador, int &actualMejorPuntuacion);