#include "funkcje.h"
#include <stdlib.h>
#include <string.h>

Osoba* dodajOsobe( Osoba* glowa, char im[20], char nazw[20] )
{
    Osoba* nowaOsoba = malloc( sizeof( Osoba ) );
    strcpy ( nowaOsoba->imie, im );
    strcpy ( nowaOsoba->nazwisko, nazw );
    nowaOsoba->nast = glowa;
    return nowaOsoba;
}


Osoba* wczytajOsobe( Osoba* glowaOsoba )
{
    char imie[20];
    char nazwisko[20];
    char napis[20];
    printf("Podaj imie: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    glowaOsoba = dodajOsobe(glowaOsoba, imie, nazwisko);
    return glowaOsoba;
}

Przedmiot* dodajPrzedmiot( Przedmiot* glowa, char nazw[30] )
{
    Przedmiot* nowyPrzedmiot = malloc( sizeof( Przedmiot ) );
    strcpy ( nowyPrzedmiot -> nazwa, nazw );
    nowyPrzedmiot->nast = glowa;
    return nowyPrzedmiot;
}

Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot )
{
    char nazwa[20];
    char napis[20];
    printf("Podaj nazwe przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    glowaPrzedmiot = dodajPrzedmiot( glowaPrzedmiot, nazwa );
    return glowaPrzedmiot;
}

void wyswietlListeOsob( Osoba* glowaOsoba )
{
    Osoba* x = glowaOsoba;
    while( x )
    {
        printf( "%s %s\n", x->imie, x->nazwisko );
        x = x->nast;
    }
}

void wyswietlListePrzedmiotow( Przedmiot* glowaPrzedmiot )
{
    Przedmiot* x = glowaPrzedmiot;
    while( x )
    {
        printf( "%s \n", x->nazwa );
        x = x->nast;
    }
}

void zwolnij( Osoba* glowa )
{
    Osoba* poprzedni=NULL;
    while( glowa )
    {
        poprzedni = glowa;
        glowa = glowa -> nast;
        free( poprzedni );
    }
}
