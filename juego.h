#pragma once

using namespace std;

void jugarModoSolitario(int jugador);
bool nuevaTirada();
bool nuevaRonda();
int ejecutarTirada(int bloqueador1, int bloqueador2);
int calcularPuntaje(int vDados[], int cantidad, int bloqueador1, int bloqueador2);
