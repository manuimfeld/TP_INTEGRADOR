#pragma once

using namespace std;

void jugarModoSolitario(int jugador);
int tirarDado();
bool nuevaTirada();
bool nuevaRonda();
void tiradaDeDados(int vDados[], int cantidad);
void mostrarDados(int vDados[], int cantidad);
int ejecutarTirada(int bloqueador1, int bloqueador2);
int calcularPuntaje(int vDados[], int cantidad, int bloqueador1, int bloqueador2);
