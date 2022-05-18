//
// Created by Ahmad.Akel on 3/31/2022.
//

#include "kandidat.h"
#include "pohovor.h"

#ifndef AKEL_SEMPRACE_AGENDA_H
#define AKEL_SEMPRACE_AGENDA_H

void nactiSeznamKandidatu (char* nazevSouboru); // postupně načte jednotlivé kandidáty ze souboru a popřidává je za sebe do lineárního seznamu
void nactiSeznamPozic (char* nazevSouboru); // postupně načte jednotlivé pozice ze souboru a popřidává je za sebe do lineárního seznamu
void vypisSeznamKandidatu(); // vypíše kandidáty se seznamu na každý řádek jednoho (používá opakovaně funkci pro výpis jednoho kandidáta)
void pridejKandidata(stKandidat * kandidat);// přidá kandidáta na konec lineárního seznamu stKandidat *odeberKandidataZeSeznamu(int cisloKandidata)// odebere kandidata z lin. seznamu podle jeho čísla, vrací ho, a následně dealokuje
stKandidat *odeberKandidataZeSeznamu(int cisloKandidata); // odebere kandidata z lin. seznamu podle jeho čísla, vrací ho, a následně dealokuje
stKandidat *najdiKandidataZeSeznamu(int cisloKandidata); //najde kandidata z lin. seznamu podle jeho čísla
void zrusSeznamKandidatu();// dealokuje celý lin. seznam(nestačí jen první/aktuální nastavit naNULL)
void vypisSeznamPozic();// vypíše pozice se seznamu na každý řádek jednoho (používá opakovaně funkci pro výpis jedné pozice)
void pridejPozice(stPozice * pozice);// přidá pozici na konec lineárního seznamu
stPozice *odeberPoziciZeSeznamu(int cisloPozice) {}//odebere pozici z lin. sez. jeho čísla, vrací ji, a následně dealokuje
stPozice *najdiPoziciZeSeznamu(int cisloPozice);//najde pozici z lin. sez. podle čísla
void zrusSeznamPozic();//dealokuje celý lin.sez.(nestačí jen první/akt nastavit na NULL)
void alokujPolePohovoru();//alokuje pole ukazatelů pro pohovory, výchozí dimenze=10, v případě hrozícího přetečení se pole realokuje
void pridejPohovor(stPohovor * pohovor);//přidá pohovor do pole na
void zmenStavPohovor(int id, enum STAV_POHOVORU vysledek); //změní stav pohovoru
void vypisPohovory();//vypíše všechny pohovory

#endif //AKEL_SEMPRACE_AGENDA_H
