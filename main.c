#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/agenda.h"
#include "Headers/pohovor.h"

int main() {
    int iputNum = 0;
    stPozice inputPozice;
    stKandidat inputKandidat;

    printf("\n***************  Modul  Main  ***************\n\n\n");
    printf("1. Nacti data do seznamu kandidatu/pozic ze souboru CSV\n\n"
           "2. Vypis seznam kandidatu/pozic\n\n"
           "3. Pridej z klavesnice kandidata/pozici do seznamu\n\n"
           "4. Odeber kandidata/pozici ze seznamu\n\n"
           "5. Zrus seznam kandidatu/pozic\n\n"
           "6. Najdi kandidata/pozici\n\n"
           "7. Pridej pohovor\n\n"
           "8. Edituj stav pohovoru\n\n"
           "9. Vypis pohovory\n\n"
           "10. Ukoncit program\n\n");

    label:
    printf("Stisknete cislo operace, kterou chcete provest:\n\n\n");
    while (iputNum != 10) {
        scanf("%d", &iputNum);
        if (iputNum == 1) {
            nactiSeznamKandidatu("../kandidati.csv");
            printf("\nSiznam Kandidati Added Successfuly\n");
            nactiSeznamPozic("../pozice.csv");
            printf("\nSiznam Pozice Added Successfuly\n");
        }
        if (iputNum == 2) {
            printf("\n\n\n********************************   Sezname Kandidati   ********************************\n\n\n");
            vypisSeznamKandidatu();
            printf("\n\n\n******************************** Sezname Pozice  ********************************\n\n\n");
            vypisSeznamPozic();
        }

        if (iputNum == 3) {
            printf("\nZadejte prosím datum kandidáta: \n\n");

            printf("\nZadejte ID kandidáta: \n");
            scanf("%d", &inputKandidat.id);

            printf("\nZadejte jméno kandidáta: \n");
            scanf("%s", &inputKandidat.jmeno);

            printf("\nZadejte pole kandidáta: \n");
            scanf("%d", &inputKandidat.obor);

            printf("\nZadejte kandidata tel: \n");
            scanf("%s", &inputKandidat.tel);

            printf("\nZadejte e-mail kandidáta: \n");
            scanf("%s", &inputKandidat.mail);

            printf("\nZadejte kandidatsky jazyk: \n");
            scanf("%s", &inputKandidat.jazyky);

            printf("********************Novy seznam kandidátů: \n\n");
            pridejKandidata(&inputKandidat);
            vypisSeznamKandidatu();

            printf("\nZadejte datum pozice: \n\n");

            printf("\nZadejte ID pozice: \n");
            scanf("%d", &inputPozice.id);

            printf("\nZadejte typ pozice: \n");
            scanf("%s", &inputPozice.pozice);

            printf("\nZadejte popis pozice: \n");
            scanf("%s", &inputPozice.popis);

            printf("\nZadejte požadavky na pozici: \n");
            scanf("%s", &inputPozice.pozadavky);

            printf("\nEnter the position offer: \n");
            scanf("%s", &inputPozice.nabidka);

            printf("\nZadejte nabídku pozice: \n");
            scanf("%s", &inputPozice.jazyky);

            printf("\nZadejte pozici max. plat: \n");
            scanf("%f", &inputPozice.maxPlat);

            printf("\nZadejte oblast pozice: \n");
            scanf("%d", &inputPozice.kraj);

            printf("********************Novy seznam pozic: \n\n");
            pridejPozice(&inputPozice);
            vypisSeznamPozic();
        }
        if (iputNum == 4) {
            int tmp = 0, id;
            label2:
            printf("Chcete-li smazat konkretniho kandidáta, zadejte 1\nChcete-li smazat konkrétní pozici, napiste 2\n");
            scanf("%d", &tmp);
            if (tmp == 1) {
                printf("\nZadejte prosím ID kandidáta, ktereho chcete smazat: \n");
                scanf("%d", &id);
                odeberKandidataZeSeznamu(id);
            }
            if (tmp == 2) {
                printf("\nZadejte prosim ID pozice, kterou chcete smazat: \n");
                scanf("%d", &id);
                odeberPoziciZeSeznamu(id);
            }
            if (tmp != 1 | tmp != 2) {
                printf("\nZadane cislo nen  platne, zkuste to prosim znovu\n");
                goto label2;
            }
        }
        if (iputNum == 5) {
            int tmp = 0;
            label3:
            printf("In order to cancel the list of candidates please type 1\nIn order to cancel the list of positions please type 2\n");
            scanf("%d", &tmp);
            if (tmp == 1) {
                zrusSeznamKandidatu();
            }
            if (tmp == 2) {
                zrusSeznamPozic();
            }
            if (tmp != 1 | tmp != 2) {
                printf("\nChcete-li zrušit seznam kandidátů, zadejte 1\n"
                       "Chcete-li zrušit seznam pozic, zadejte 2\n");
                goto label3;
            }
        }

        if(iputNum==6){
            int tmp=0,id=0;
            label4: printf("Chcete-li najít konkrétního kandidáta, zadejte 1\n"
                           "Chcete-li najít konkrétní pozici, zadejte 2");
            scanf("%d", &tmp);

            if (tmp == 1) {
                printf("\nZadejte prosím ID kandidáta, kterého chcete najít:\n");
                scanf("%d", &id);
                najdiKandidataZeSeznamu(id);
            }

            if (tmp == 2) {
                printf("\nZadejte prosím ID pozice, kterou chcete najít: \n");
                scanf("%d", &id);
                najdiPoziciZeSeznamu(id);
            }
            if (tmp != 1 | tmp != 2) {
                printf("\nZadané číslo není platné, zkuste to prosím znovu\n");
                goto label4;
            }
        }

        if(iputNum==7){
            printf("\nZadejte prosím údaje z rozhovoru: \n");
        }
        if(iputNum==8){
            int id=0,vysledek=0;
            printf("\nZadejte prosím ID rozhovoru, který chcete upravit: \n");
            scanf("id: %d",&id);
            printf("\nZadejte prosím novy rozhovoru vysledek: \n");
            scanf("%d",&vysledek);
        }
        if(iputNum==9){
            printf("\n\n\n******************************** Sezname Pohovri  ********************************\n\n\n");
            vypisPohovory();
        }

        if (iputNum == 10) {
            printf("\n\nProgram skončil");
        }
        if (iputNum < 1 || iputNum > 10) {
            printf("\n\n Zadaný vstup %d není platný, zkuste zadat hodnotu 1 -> 10\n\n", iputNum);
            goto label;
        }

    }

    return 0;

}
