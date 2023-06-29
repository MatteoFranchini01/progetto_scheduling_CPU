//
// Created by Matteo Franchini on 25/04/23.
//
#include <iostream>

#include "auxyliary_functions.h"


/*!
 * Questa funzione viene chiamata nell'esecuzione dell'algoritmo SRTF
 * e permette di analizzare quali processi vengono chiamati in un particolare istante
 * di tempo e li ordina in base alla durata
 * @param Processo p
 * @param int num_processi
 * @param int time
 * @return list<Processo> processi_in_arrivo
 */

list<Processo> analisi_processi (Processo *p, int num_processi, int time) {
    list<Processo> processi_in_arrivo;
    for (int i = 0; i < num_processi; i++) {
        if (p[i].istante_arrivo == time) {
            processi_in_arrivo.push_back(p[i]);
            processi_in_arrivo.sort(confronto_durata);
        }
    }
    return processi_in_arrivo;
}

/*!
 * Insieme alla funzione "analisi_processi" permette l'ordinamento dei processi in
 * base alla durata
 * @param Processo a
 * @param Processo b
 * @return bool
 */

bool confronto_durata (const Processo& a, const Processo& b) {
    return a.durata < b.durata;
}

/*!
 * Creazione di una funzione che trasforma un array in una coda
 * @param Processo p
 * @param int num_processi
 * @return queue<Processo> coda
 */

queue<Processo> from_array_to_queue(Processo *p, int num_processi) {
    queue<Processo> var;
    for (int i = 0; i < num_processi; i++) {
        if (p[i].nome == "") {
            continue;
        }
        Processo temp;
        temp.nome = p[i].nome;
        temp.durata = p[i].durata;
        temp.priorita = p[i].priorita;
        var.push(temp);
    }
    return var;
}


/*!
 * Funzione di calcolo del tempo medio
 * @param int durata
 * @param int size
 * @return float avg
 */
float avg (int *durata, int size) {
    // Tempo di attesa del singolo processo

    int sum_int = 0;

    // Tempo di attesa complessivo

    int sum = 0;

    for (int j = 0; j < size-1; j++) {
        sum_int += durata[j];
        sum += sum_int;
    }
    return sum/size;
}


/*!
 * Funzione di calcolo del tempo medio per l'algoritmo Round Robin
 * @param Processo durata
 * @param int size
 * @param int num_processi
 * @return float avg
 */

float avg_RR (Processo *durata, int size, int num_processi) {
    bool flag = false;
    int sum = 0;
    for (int i = 0; i < num_processi; i++) {
        for (int j = size; j >= 0; j--) {
            if (durata[i].nome == durata[j].nome) {
                flag = true;
            }
            if (flag == true && durata[i].nome != durata[j].nome) {
                sum += durata[j].durata;
            }
        }
        flag = false;
    }
    return sum/num_processi;
}