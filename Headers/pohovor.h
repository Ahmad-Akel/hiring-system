//
// Created by Ahmad on 5/22/2022.
//

#ifndef SEMPRACE_AKEL_POHOVOR_H
#define SEMPRACE_AKEL_POHOVOR_H

#include "kandidat.h"
#include "pozice.h"

typedef struct pohovor {
    int id;
    stKandidat *kandidat;
    stPozice * pozice;
    enum VYSLEDEK_POHOVORU vysledek;
} stPohovor;

stPohovor *vytvorPohovor(stKandidat *kandidat, stPozice * pozice);
void vypisPohovor(stPohovor * pohovor);
#endif //SEMPRACE_AKEL_POHOVOR_H
