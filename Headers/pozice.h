//
// Created by Ahmad.Akel on 3/31/2022.
//

#ifndef AKEL_SEMPRACE_POZICE_H
#define AKEL_SEMPRACE_POZICE_H

#include "kandidat.h"

typedef struct pozice {
    int id;
    char pozice[100];
    char popis[50];
    char pozadavky[50];
    char nabidka[50];
    char jazyky[50];
    float maxPlat;
    enum KRAJ kraj;
    struct pozice *dalsi;
   // Deklaraci funkcí:
} stPozice;

stPozice * vytvorPozici(int id, char* pozice, enum KRAJ kraj, char* popis, char* pozadavky, char*nabidka, char* jazyky, float maxPlat){} // vrací adresu dynamické alokace pozice, ukazatel dalsi se nastaví na NULL

void vypisPozici(stPozice* pozice){} //vypíše pozice na obrazovku

#endif //AKEL_SEMPRACE_POZICE_H
