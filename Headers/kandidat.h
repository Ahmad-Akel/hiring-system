//
// Created by Ahmad on 5/22/2022.
//

#ifndef SEMPRACE_AKEL_KANDIDAT_H
#define SEMPRACE_AKEL_KANDIDAT_H
typedef struct kandidat {
    int id;
    char jmeno[50];
    enum OBOR obor;
    char tel[50];
    char mail[50];
    char jazyky[50];
    struct kandidat *dalsi;
} stKandidat;

stKandidat * vytvorKandidata(int id, char* jmeno, enum OBOR obor, char* tel, char* mail, char*jazyky);
void vypisKandidata(stKandidat * kandidat);
#endif //SEMPRACE_AKEL_KANDIDAT_H
