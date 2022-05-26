//
// Created by Ahmad on 5/22/2022.
//

#ifndef SEMPRACE_AKEL_POZICE_H
#define SEMPRACE_AKEL_POZICE_H
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
}stPozice;

stPozice * vytvorPozici(int id, char* pozice, enum KRAJ kraj, char* popis, char* pozadavky, char*nabidka, char* jazyky, float maxPlat);
void vypisPozici(stPozice* pozice);
#endif //SEMPRACE_AKEL_POZICE_H
