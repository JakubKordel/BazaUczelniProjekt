#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128

void wyczyscBuf();
void wyczyscEkran();
void rysujPrzerwe();
char* wczytajNapis();
int porownajNapisy( char pierwszy[ MAX ], char drugi[ MAX ] );
int czyNapisyKolejneAlfabetycznie( char pierwszy[ MAX ], char drugi[ MAX ]);

