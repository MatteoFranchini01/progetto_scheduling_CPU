//
// Created by Matteo Franchini on 04/04/23.
//

#ifndef PROGETTO_SISTEMI_OPERATIVI_ALGORITMI_H
#define PROGETTO_SISTEMI_OPERATIVI_ALGORITMI_H

#include <string>

using namespace std;

struct Processo{
    string nome;
    int durata;
    int priorita;
};

void algoritmo_FCFS (Processo *p, int num_processi);
void algoritmo_priorita (Processo *p, int num_processi);
void algoritmo_BJP (Processo *p, int num_processi);

#endif //PROGETTO_SISTEMI_OPERATIVI_ALGORITMI_H
