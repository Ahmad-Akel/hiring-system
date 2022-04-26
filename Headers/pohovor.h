//
// Created by Ahmad.Akel on 3/31/2022.
//

#include "kandidat.h"
#include "pozice.h"

#ifndef AKEL_SEMPRACE_POHOVOR_H
#define AKEL_SEMPRACE_POHOVOR_H

typedef struct pohovor {
    int id;
    stKandidat *kandidat;
    stPozice * pozice;
    enum VYSLEDEK_POHOVORU vysledek;
} stPohovor;
//Deklaraci funkcí:
stPohovor *vytvorPohovor(stKandidat *kandidat, stPozice *idPozice) {}// vrací adresu dynamické alokace pozice, stav je nastaven na ‘nenastaveno’, id pohovoru roste automaticky (1,2,..

void vypisPohovor(stPohovor * pohovor) {}//vypíše pohovor(včetně kandidáta a pozice)

#endif //AKEL_SEMPRACE_POHOVOR_H
