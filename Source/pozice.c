#include <stdio.h>
#include "../Headers/pozice.h"

//
// Created by Ahmad on 5/12/2022.
//
stPozice * vytvorPozici(int id, char* pozice, enum KRAJ kraj, char* popis, char* pozadavky, char*nabidka, char* jazyky, float maxPlat){
    struct pozice novyPozice;
    novyPozice.id=id;
    novyPozice.pozice==*pozice;
    novyPozice.kraj=kraj;
    novyPozice.popis==*popis;
    novyPozice.pozadavky==*pozadavky;
    novyPozice.nabidka==*nabidka;
    novyPozice.jazyky==*jazyky;
    novyPozice.maxPlat==maxPlat;
    return &novyPozice;
} // vrací adresu dynamické alokace pozice, ukazatel dalsi se nastaví na NULL

void vypisPozici(stPozice* pozice){
    printf("%d, %s, %s, %s, %s, %s, %d",pozice->id,pozice->pozice,pozice->kraj,pozice->pozadavky,pozice->nabidka,pozice->jazyky,pozice->maxPlat);
} //vypíše pozice na obrazovku
