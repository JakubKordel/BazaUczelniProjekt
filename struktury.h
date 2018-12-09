#pragma once

#define MAX 128
#include <stdio.h>
#include "podst.h"

typedef struct Osoba
{
    int id;
    char imie[ MAX ];
    char nazwisko[ MAX ];
    struct Osoba* nast;
} Osoba;

typedef struct Przedmiot
{
    char nazwa[ MAX ];
    struct Przedmiot* nast;
} Przedmiot;

typedef struct OsobaPrzedmiot
{
    Osoba* osoba;
    Przedmiot* przedmiot;
    struct OsobaPrzedmiot* nast;
} OsobaPrzedmiot;

Osoba* dodajOsobe( Osoba* glowa, char imie[ MAX ], char nazwisko[ MAX ] );
Przedmiot* dodajPrzedmiot( Przedmiot* glowaPrzedmiot, char nazwa[ MAX ] );
OsobaPrzedmiot* dodajOsobaPrzedmiot( OsobaPrzedmiot* glowaOsobaPrzedmiot, Osoba* osoba, Przedmiot* przedmiot );

