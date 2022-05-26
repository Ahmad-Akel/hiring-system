#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Headers/pozice.h"

//
// Created by Ahmad on 5/22/2022.
//
stPozice *vytvorPozici(int id, char *pozice, enum KRAJ kraj, char *popis, char *pozadavky, char *nabidka, char *jazyky,
                       float maxPlat) {

    struct pozice *newPozice= malloc(sizeof( stPozice));

    newPozice->id = id;
    strcpy(newPozice->pozice, pozice);
    strcpy(newPozice->popis, popis);
    strcpy(newPozice->pozadavky, pozadavky);
    strcpy(newPozice->nabidka, nabidka);
    strcpy(newPozice->jazyky, jazyky);
    newPozice->maxPlat = maxPlat;
    newPozice->kraj = kraj;

    return newPozice;
}

void vypisPozici(stPozice *pozice) {
    printf("Id:%d, Pozice:%s, Popis:%s, Pozadavky:%s, Nabidka:%s, Jazyky:%s, MaxPlat:%f, Kraj:%d\n ",
           pozice->id,
           pozice->pozice,
           pozice->popis,
           pozice->pozadavky,
           pozice->nabidka,
           pozice->jazyky,
           pozice->maxPlat,
           pozice->kraj);
}