//
// Created by Ahmad on 5/22/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Headers/kandidat.h"
#include "../Headers/pozice.h"
#include "../Headers/pohovor.h"

static stKandidat *prvniKandi = NULL, *aktKandi;
static stPozice *prvniPozice = NULL, *aktPozice = NULL;
static stPohovor **polePohovoru = NULL;
static int currentFreeSlot = 0;
static int poleDimension = 10;

static char *my_strtok_r(char *str, const char *delims, char **store) {
    char *p, *wk;
    if (str != NULL) {
        *store = str;
    }
    if (*store == NULL) return NULL;
    //*store += strspn(*store, delims);//skip delimiter
    if (**store == '\0') return NULL;
    p = strpbrk(wk = *store, delims);
    if (p != NULL) {
        *p = '\0';
        *store = p + 1;
    } else {
        *store = NULL;
    }
    return wk;
}

static char *my_strtok(char *str, const char *delims) {
    static char *p;
    return my_strtok_r(str, delims, &p);
}


void pridejKandidata(stKandidat *kandidat) {
    stKandidat **head_ref = &prvniKandi;
    stKandidat *new_node = malloc(sizeof(stKandidat));

    stKandidat *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->id = kandidat->id;
    new_node->obor = kandidat->obor;
    strcpy(new_node->jmeno, kandidat->jmeno);
    strcpy(new_node->tel, kandidat->tel);
    strcpy(new_node->mail, kandidat->mail);
    strcpy(new_node->jazyky, kandidat->jazyky);
    /* 3. This new node is going to be the last node, so make next
        of it as NULL*/
    new_node->dalsi = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->dalsi != NULL)
        last = last->dalsi;

    /* 6. Change the next of last node */
    last->dalsi = new_node;
    return;
}

void pridejPozice(stPozice *pozice) {
    stPozice **head_ref = &prvniPozice;
    stPozice *new_node = malloc(sizeof(stPozice));

    stPozice *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->id = pozice->id;
    strcpy(new_node->pozice, pozice->pozice);
    strcpy(new_node->popis, pozice->popis);
    strcpy(new_node->pozadavky, pozice->pozadavky);
    strcpy(new_node->nabidka, pozice->nabidka);
    strcpy(new_node->jazyky, pozice->jazyky);
    new_node->maxPlat = pozice->maxPlat;
    new_node->kraj = pozice->kraj;
    /* 3. This new node is going to be the last node, so make next
        of it as NULL*/
    new_node->dalsi = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->dalsi != NULL)
        last = last->dalsi;

    /* 6. Change the next of last node */
    last->dalsi = new_node;
    return;
}

void pridejPohovor(stPohovor *pohovor) {
    polePohovoru[currentFreeSlot++] = pohovor;
}

void nactiSeznamKandidatu(char *nazevSouboru) {
    FILE *file = fopen(nazevSouboru, "r");
    if (!file)
        printf("Can't open file\n");
    else {
        char buffer[1024];

        int row = 0;
        int column = 0;
        while (fgets(buffer,
                     1024, file)) {
            column = 0;
            row++;
            stKandidat kandidat;
            aktKandi = &kandidat;

            if (row == 1)
                continue;

            // Splitting the data
            char *value = my_strtok(buffer, ";");

            int id = 0;
            char jmeno[50];
            enum OBOR obor;
            char tel[50];
            char mail[50];
            char jazyky[50];

            while (value != NULL) {


                //Column 1
                if (column == 0) {
                    id = atoi(value);
                }

                // Column 2
                if (column == 1) {
                    strcpy(jmeno, value);
                }

                // Column 3
                if (column == 2) {
                    if (strlen(value) == 0) {
                        obor = 0;
                    } else {
                        obor = atoi(value);
                    }

                }

                // Column 4
                if (column == 3) {
                    strcpy(tel, value);
                }

                // Column 5
                if (column == 4) {
                    strcpy(mail, value);
                }
                // Column 6
                if (column == 5) {
                    strcpy(jazyky, value);
                }

                //   printf("%s", value);


                value = my_strtok(NULL, ";");
                column++;
            }
            pridejKandidata(vytvorKandidata(id, jmeno, obor, tel, mail, jazyky));

        }

        fclose(file);
    }
}

void nactiSeznamPozic(char *nazevSouboru) {
    FILE *file = fopen(nazevSouboru, "r");
    if (!file)
        printf("Can't open file\n");
    else {
        char buffer[1024];

        int row = 0;
        int column = 0;
        while (fgets(buffer,
                     1024, file)) {
            column = 0;
            row++;

            if (row == 1)
                continue;

            // Splitting the data
            char *value = my_strtok(buffer, ";");

            int id;
            char pozice[100];
            char popis[50];
            char pozadavky[50];
            char nabidka[50];
            char jazyky[50];
            float maxPlat;
            enum KRAJ kraj;
            while (value != NULL) {

//id;pozice;popis;pozadavky;nabidka;jazyky;maxPlat;kraj
                //Column 1
                if (column == 0) {
                    id = atoi(value);
                }

                // Column 2
                if (column == 1) {
                    strcpy(pozice, value);
                }

                // Column 3
                if (column == 2) {
                    strcpy(popis, value);
                }

                // Column 4
                if (column == 3) {
                    strcpy(pozadavky, value);
                }

                // Column 5
                if (column == 4) {
                    strcpy(nabidka, value);
                }
                // Column 6
                if (column == 5) {
                    strcpy(jazyky, value);
                }

                // Column 7
                if (column == 6) {
                    maxPlat = atof(value);
                }

                // Column 8
                if (column == 7) {
                    if (strlen(value) == 0) {
                        kraj = 0;
                    } else {
                        kraj = atoi(value);
                    }

                }


                value = my_strtok(NULL, ";");
                column++;
            }
            pridejPozice(vytvorPozici(id, pozice, kraj, popis, pozadavky, nabidka, jazyky, maxPlat));

        }

        fclose(file);
    }
}

void vypisSeznamKandidatu() {
    stKandidat *tmp = prvniKandi;
    while (tmp != NULL) {
        vypisKandidata(tmp);
        tmp = tmp->dalsi;
    }
}

void vypisSeznamPozic() {
    stPozice *tmp = prvniPozice;
    while (tmp != NULL) {
        vypisPozici(tmp);
        tmp = tmp->dalsi;
    }
}

void vypisPohovory() {
    stPohovor *tmp;
    while (tmp != NULL) {
        vypisPohovor(tmp);
    }
}

stKandidat *odeberKandidataZeSeznamu(int cisloKandidata) {
    stKandidat *kandidatNaSmazat = prvniKandi, *prev, deletedKandidat;
    if (kandidatNaSmazat != NULL && kandidatNaSmazat->id == cisloKandidata) {
        prvniKandi = prvniKandi->dalsi;
        free(kandidatNaSmazat);
        return kandidatNaSmazat;
    }
    while (kandidatNaSmazat != NULL && kandidatNaSmazat->id != cisloKandidata) {
        prev = kandidatNaSmazat;
        kandidatNaSmazat = kandidatNaSmazat->dalsi;
    }
    if (kandidatNaSmazat == NULL) {
        return NULL;
    }
    prev->dalsi = kandidatNaSmazat->dalsi;
    deletedKandidat.id = kandidatNaSmazat->id;
    deletedKandidat.obor = kandidatNaSmazat->obor;
    strcpy(deletedKandidat.jmeno, kandidatNaSmazat->jmeno);
    strcpy(deletedKandidat.tel, kandidatNaSmazat->tel);
    strcpy(deletedKandidat.mail, kandidatNaSmazat->mail);
    strcpy(deletedKandidat.jazyky, kandidatNaSmazat->jazyky);

    free(kandidatNaSmazat);
    return &deletedKandidat;
}

stPozice *odeberPoziciZeSeznamu(int cisloPozice) {
    stPozice *poziceNaSmazat = prvniPozice, *prev, deletedPozice;
    if (poziceNaSmazat != NULL && poziceNaSmazat->id == cisloPozice) {
        prvniPozice = prvniPozice->dalsi;
        free(poziceNaSmazat);
        return poziceNaSmazat;
    }
    while (poziceNaSmazat != NULL && poziceNaSmazat->id != cisloPozice) {
        prev = poziceNaSmazat;
        poziceNaSmazat = poziceNaSmazat->dalsi;
    }
    if (poziceNaSmazat == NULL) {
        return NULL;
    }
    prev->dalsi = poziceNaSmazat->dalsi;
    poziceNaSmazat->id = poziceNaSmazat->id;
    strcpy(deletedPozice.pozice, poziceNaSmazat->pozice);
    strcpy(deletedPozice.popis, poziceNaSmazat->popis);
    strcpy(deletedPozice.pozadavky, poziceNaSmazat->pozadavky);
    strcpy(deletedPozice.nabidka, poziceNaSmazat->nabidka);
    strcpy(deletedPozice.jazyky, poziceNaSmazat->jazyky);
    poziceNaSmazat->maxPlat = poziceNaSmazat->maxPlat;
    poziceNaSmazat->kraj = poziceNaSmazat->kraj;

    free(poziceNaSmazat);
    return &deletedPozice;
}

stKandidat *najdiKandidataZeSeznamu(int cisloKandidata) {
    struct kandidat *tmp = prvniKandi;
    while (tmp != NULL) {
        if (tmp->id == cisloKandidata) {
            return tmp;
        }
        tmp = tmp->dalsi;
    }
    return NULL;
}

stPozice *najdiPoziciZeSeznamu(int cisloPozice) {
    struct pozice *tmp = prvniPozice;
    while (tmp != NULL) {
        if (tmp->id == cisloPozice) {
            return tmp;
        }
        tmp = tmp->dalsi;
    }
    return NULL;
}

void zrusSeznamKandidatu() {

    while (prvniKandi != NULL) {
        struct kandidat *tmp = prvniKandi;
        prvniKandi = prvniKandi->dalsi;
        free(tmp);
    }
}

void zrusSeznamPozic() {
    while (prvniPozice != NULL) {
        struct kandidat *tmp = prvniPozice;
        prvniPozice = prvniPozice->dalsi;
        free(tmp);
    }
}

void alokujPolePohovoru() {

    polePohovoru = (stPohovor *) malloc(sizeof(stPohovor) * poleDimension);
    int length = sizeof polePohovoru / sizeof polePohovoru[0];
    for (int i = 0; i < poleDimension; ++i) {
        polePohovoru[i]->pozice = (stPozice *) malloc(sizeof(stPozice *) * (length + 1));
        polePohovoru[i]->kandidat = (stKandidat *) malloc(sizeof(stKandidat *) * (length + 1));
    }
}

void zmenStavPohovor(int id, enum STAV_POHOVORU vysledek) {
    polePohovoru[id - 1]->vysledek = vysledek;
}
