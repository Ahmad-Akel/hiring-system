#include <stdlib.h>
#include <stdio.h>
#include "../Headers/pohovor.h"
#include "../Headers/kandidat.h"
#include "../Headers/pozice.h"

//
// Created by Ahmad on 5/22/2022.
//
static int pohovorId=1;
stPohovor *vytvorPohovor(stKandidat *kandidat, stPozice * pozice){
    struct pohovor *newPohovor= malloc(sizeof( stPohovor));

    newPohovor->kandidat = kandidat;
    newPohovor->pozice = pozice;
    newPohovor->id = pohovorId++;
    newPohovor->vysledek = 0;
    return newPohovor;
}
void vypisPohovor(stPohovor * pohovor){
     printf("Id: %d \n",pohovor->id);
    printf("Kandidate :");
    vypisKandidata(pohovor->kandidat);
    printf("Pozice :");
    vypisPozici(pohovor->pozice);
}