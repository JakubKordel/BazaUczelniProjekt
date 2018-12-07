#ifndef struktury.h
#define struktury.h

#define MAX 128
#include <stdio.h>
#include "podst.h"

typedef struct Osoba
{
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
Osoba* wczytajOsobe( Osoba* glowaOsoba );
Przedmiot* dodajPrzedmiot( Przedmiot* glowaPrzedmiot, char nazwa[ MAX ] );
Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot );
OsobaPrzedmiot* dodajOsobaPrzedmiot( OsobaPrzedmiot* glowaOsobaPrzedmiot, Osoba* osoba, Przedmiot* przedmiot );

#endif
