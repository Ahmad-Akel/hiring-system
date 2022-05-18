#include <vcruntime.h>
#include <stdio.h>
#include "../Headers/kandidat.h"
#include "stdlib.h"
//
// Created by Ahmad on 5/12/2022.
//
stKandidat * vytvorKandidata(int id, char* jmeno, enum OBOR obor, char* tel, char* mail, char* jazyky){
    struct kandidat novyKandidat;
    novyKandidat.id=id;
    novyKandidat.jmeno == *jmeno;
    novyKandidat.obor=obor;
    novyKandidat.tel == *tel;
    novyKandidat.mail==*mail;
    novyKandidat.jazyky==*jazyky;
    return &novyKandidat;
} // vrací adresu dynamické alokace kandidáta, ukazatel dalsi se nastaví na NULL
void vypisKandidata(stKandidat * kandidat){
    while (kandidat!=NULL){
        printf("%d , %s, %s, %d, %s, %s",kandidat->id,kandidat->jmeno,kandidat->obor,kandidat->tel,kandidat->mail,kandidat->jazyky);
        kandidat=kandidat->dalsi;
    }
}
