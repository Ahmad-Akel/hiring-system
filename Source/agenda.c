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