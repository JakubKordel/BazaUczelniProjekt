#include <stdio.h>
#include "podst.h"

typedef struct Osoba{
    char imie[20];
    char nazwisko[20];
    struct Osoba* nast;
}Osoba;

typedef struct Przedmiot{
    unsigned int id_prz;
    char nazwa[20];
}Przedmiot;

Osoba* dodajOsobe( Osoba* glowa, char imie[20], char nazwisko[20] );

Osoba* wczytajOsobe( Osoba* glowaOsoba );
void wyswietlListeOsob( Osoba* glowaOsoba );






