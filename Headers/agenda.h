//
// Created by Ahmad on 5/22/2022.
//

#ifndef SEMPRACE_AKEL_AGENDA_H
#define SEMPRACE_AKEL_AGENDA_H

#include "kandidat.h"
#include "pozice.h"
#include "pohovor.h"

void nactiSeznamKandidatu (char* nazevSouboru);
void vypisSeznamKandidatu();
void pridejKandidata(stKandidat * kandidat);
stKandidat *odeberKandidataZeSeznamu(int cisloKandidata);
stKandidat *najdiKandidataZeSeznamu(int cisloKandidata);
void zrusSeznamKandidatu();


void nactiSeznamPozic (char* nazevSouboru);
void vypisSeznamPozic();
void pridejPozice(stPozice * pozice);
stPozice *odeberPoziciZeSeznamu(int cisloPozice);
stPozice *najdiPoziciZeSeznamu(int cisloPozice);
void zrusSeznamPozic();

void alokujPolePohovoru();
void pridejPohovor(stPohovor * pohovor);
void zmenStavPohovor(int id, enum STAV_POHOVORU vysledek);
void vypisPohovory();
#endif //SEMPRACE_AKEL_AGENDA_H
