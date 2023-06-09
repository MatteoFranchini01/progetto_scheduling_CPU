//
// Created by Matteo Franchini on 03/04/23.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include "algoritmi.h"
#include "auxyliary_functions.h"

using namespace std;

const int CONST = 100;
const int NUM_ALGORITMI = 6;

int main(int argc, char *argv[]) {

    /// @brief Controllo del numero di argomenti passati da riga di comando
    if (argc != 2) {
        cout << "Errore: inserire il nome del file di input" << endl;
        return 1;
    }

    /// @brief Se il numero di argomenti è corretto, si procede con l'esecuzione del programma
    else {

    /// @brief Inizializzazione delle variabili
    string nome; int durata; int priorita; int istante_arrivo;
    string str1; string str2; string str3; string str4; string str5;
    int num_processi;
    int quanto;
    int counter = -1;
    int scelta_algoritmo = 0;


    /// @brief Creazione di un array di tipo Processo con allocazione dinamica
    int n = CONST;
    Processo* arr = new Processo[n];

    /// @brief Lettura da file
    ifstream myfile (argv[1]);

    if (myfile.is_open()) {
        while (getline(myfile, str5, ' ')) {
            if (counter == -1) {
                getline(myfile, str3, ' ');
                istringstream tk3 (str3);
                tk3 >> num_processi;
                getline(myfile, str4);
                istringstream tk4 (str4);
                tk4 >> quanto;
                counter++;
            }
            else {
                istringstream tk5(str5);
                tk5 >> istante_arrivo;
                getline(myfile, nome, ' ');
                getline(myfile, str1, ' ');
                istringstream tk1(str1);
                tk1 >> durata;
                getline(myfile, str2);
                istringstream tk2(str2);
                tk2 >> priorita;
                arr[counter].nome = nome;
                arr[counter].istante_arrivo = istante_arrivo;
                arr[counter].durata = durata;
                arr[counter].priorita = priorita;
                counter++;
            }
        }
        myfile.close();
    } else cout << "Impossibile aprire il file";

    /*!
     * @brief
     * Creazione di un array di copia per far si che l'array originale venga mantenuto
     * anche dopo l'esecuzione di un algoritmo
     */

    Processo arr_copia[num_processi];

    /// @brief Esecuzione degli algoritmi

    for (int j = 0; j < NUM_ALGORITMI; j++) {

        /*!
         * @brief
         * Reset dell'array di copia dopo ogni esecuzione di un algoritmo
         * in modo che l'array di copia sia sempre uguale all'array originale
         */

        reset_array(arr, arr_copia, num_processi);
        switch (j) {
            case 0:
                cout << "Esecuzione algoritmo FCFS" << endl;
                algoritmo_FCFS(arr_copia, num_processi);
                break;
            case 1:
                cout << "<------------------------------------------->" << endl;
                cout << "Esecuzione algoritmo BJP" << endl;
                algoritmo_BJP(arr_copia, num_processi);
                break;
            case 2:
                cout << "<------------------------------------------->" << endl;
                cout << "Esecuzione algoritmo Priorità" << endl;
                algoritmo_priorita(arr_copia, num_processi);
                break;
            case 3:
                cout << "<------------------------------------------->" << endl;
                cout << "Esecuzione algoritmo RR" << endl;
                algoritmo_RR(arr_copia, num_processi, quanto);
                break;
            case 4:
                cout << "<------------------------------------------->" << endl;
                cout << "Esecuzione algoritmo SRTF" << endl;
                algoritmo_SRTF(arr_copia, num_processi);
                break;
            case 5:
                cout << "<------------------------------------------->" << endl;
                cout << "Esecuzione algoritmo priorità RR" << endl;
                algoritmo_priorita_RR(arr_copia, num_processi, quanto);
                break;
        }
    }

    cout << "<------------------------------------------->" << endl;
    /// @brief Cancellazione degli array creati con allocazione dinamica

    delete[] arr;

    return 0;
    }
}