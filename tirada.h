#pragma once

using namespace std;

void mostrarResultadosTirada(int dados[], int dadosDisponibles, int bloqueador1, int bloqueador2, int puntajeTirada);
int ejecutarTirada(int dados[5], int dadosDisponibles, int bloqueador1, int bloqueador2, int tiradaActual, int &puntajeTurno);
bool nuevaTirada();
