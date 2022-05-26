#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/kandidat.h"

//
// Created by Ahmad on 5/22/2022.
//
stKandidat *vytvorKandidata(int id, char *jmeno, enum OBOR obor, char *tel, char *mail, char *jazyky) {
    struct kandidat *newKandidat= malloc(sizeof( stKandidat));

    newKandidat->id = id;
    strcpy(newKandidat->jmeno, jmeno);
    newKandidat->obor = obor;
    strcpy(newKandidat->tel, tel);
    strcpy(newKandidat->mail, mail);
    strcpy(newKandidat->jazyky, jazyky);

    return newKandidat;
}

void vypisKandidata(stKandidat *kandidat) {
    printf("Id:%d, Jmeno:%s, Obor:%d, Tel:%s, Mail:%s, Jazyky:%s \n", kandidat->id, kandidat->jmeno,
           kandidat->obor, kandidat->tel, kandidat->mail, kandidat->jazyky);
}