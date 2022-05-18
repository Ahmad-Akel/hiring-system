//
// Created by Ahmad.Akel on 3/31/2022.
//
#include <stdio.h>
#include "../Headers/kandidat.h"
#include "../Headers/pozice.h"
#include "../Headers/pohovor.h"

static stKandidat *prvniKandi = NULL, *aktKandi = NULL;
static stPozice *prvniPozice = NULL, *aktPozice = NULL;
static stPohovor **polePohovoru= NULL;
// static, aby byly vidět jen v tomto souboru a implementuje	funkce z agenda.h

void nactiSeznamKandidatu (char* nazevSouboru) {} //gradually load individual candidates from the file and adds them to a linear list

void nactiSeznamPozic (char* nazevSouboru) {} // load each position from the file one by one and adds them one by one to the linear list

void vypisSeznamKandidatu() {} // lists the candidates with a list on each line of one (used by repeated function for listing one candidate)

void pridejKandidata(stKandidat * kandidat) {} // adds the candidate to the end of the linear list

stKandidat *odeberKandidataZeSeznamu(int cisloKandidata){} // remove the candidate from lin. list by its numbers, returns it, and then deallocates

stKandidat *najdiKandidataZeSeznamu(int cisloKandidata) {}  // find candidate from lin. list by his numbers

void zrusSeznamKandidatu() {} // deallocates the entire lin. list (it is not enough to just set the first / current to NULL)


void vypisSeznamPozic() {} // prints the list position on each line of one (used repeatedly function for listing one position)

void pridejPozice(stPozice * pozice) {} // adds a position to the end of the linear list


stPozice *odeberPoziciZeSeznamu(int cisloPozice); // remove position from lin. sez. his numbers, he returns it, and then deallocates


stPozice *najdiPoziciZeSeznamu(int cisloPozice); // find position from lin. sez. By number

void zrusSeznamPozic() {} // dealocates the entire line list (it is not enough to just set the first / act to NULL)

void alokujPolePohovoru() {} // allocates an array of pointers for interviews, default dimension = 10, in case the field overflows, the field reallocates

void pridejPohovor(stPohovor * pohovor) {} // adds the interview to the on box

void zmenStavPohovor(int id, enum STAV_POHOVORU vysledek) {} // change interview status

void vypisPohovory() {} // lists all interviews
