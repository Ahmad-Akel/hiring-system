//
// Created by Ahmad.Akel on 3/31/2022.
//

#include "enums.h"

#ifndef AKEL_SEMPRACE_KANDIDAT_H
#define AKEL_SEMPRACE_KANDIDAT_H
typedef struct kandidat {
    int id;
    char jmeno[50];
    enum OBOR obor;
    char tel[50];
    char mail[50];
    char jazyky[50];
    struct kandidat *dalsi;
} stKandidat;
//Deklaraci	funkcí:
stKandidat * vytvorKandidata(int id, char* jmeno, enum OBOR obor, char* tel, char* mail, char* jazyky); // vrací adresu dynamické alokace kandidáta, ukazatel dalsi se nastaví na NULL
void vypisKandidata(stKandidat * kandidat);
#endif //AKEL_SEMPRACE_KANDIDAT_H
