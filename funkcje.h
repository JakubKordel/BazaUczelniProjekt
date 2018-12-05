#include <stdio.h>
#include "podst.h"

typedef struct Osoba{
    int id_o;
    char imie[20];
    char nazwisko[20];
    struct Osoba* nast;
}Osoba;

typedef struct Przedmiot{
    id_p;
    char nazwa[20];
    struct Przedmiot* nast;
}Przedmiot;

Osoba* dodajOsobe( Osoba* glowa, char imie[20], char nazwisko[20] );
Osoba* wczytajOsobe( Osoba* glowaOsoba );
Przedmiot* dodajPrzedmiot( Przedmiot* glowaPrzedmiot, char nazwa[20] );
Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot );
void wyswietlListeOsob( Osoba* glowaOsoba );
void wyswietlListePrzedmiotow( Przedmiot* glowaPrzedmiot );





