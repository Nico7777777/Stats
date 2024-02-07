//
// Created by nick on 12/15/23.
//
#include "stats.h"
#ifndef STATISTNICK_EVALS_H
#define STATISTNICK_EVALS_H
// FUNCTIILE SUNT IMPLEMENTATE AICI DOAR PENTRU O SINGURA VARIABILA DE INTRARE


// Distanta Euclidiana are doar valori reale(POATE avea intregi FOARTE rar)
LD euclidean_distance(const ULL* real_x, const ULL* pred_x, int n);

//Distanta Manhattan are valori reale(POATE avea si intregi in functie de input)
ULL manhattan_distance(const ULL* real_x, const ULL* pred_x, int n);
LD manhattan_distance(const LD* real_x, const LD* pred_x, int n);

//Distanta Minkowski are valori reale(POATE avea intregi FOARTE rar)
ULL minkowski_distance(const ULL* real_x, const ULL* pred_x, int n, int p);

//Distanta Hamming are doar valori intregi
int hamming_distance(char* a, char* b, int n);
#endif //STATISTNICK_EVALS_H
