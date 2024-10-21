#pragma once

using namespace std;

string nombreJugador();
void jugarModoSolitario(string nombreJugador);
bool nuevaTirada();
bool nuevaRonda();
int ejecutarTirada(int dados[5], int dadosDisponibles, int bloqueador1, int bloqueador2);
int calcularPuntaje(int vDados[5], int dadosDisponibles, int bloqueador1, int bloqueador2);
void mensaje();
int calcularBloqueados(int vDados[], int dadosDisponibles, int bloqueador1, int bloqueador2);