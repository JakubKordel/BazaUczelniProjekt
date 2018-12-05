#include "funkcje.h"
#include <stdlib.h>
#include <string.h>

Osoba* dodajOsobe( Osoba* glowa, char imie[20], char nazwisko[20] )
{
    Osoba* nowaOsoba = malloc( sizeof( Osoba ) );
    strcpy ( nowaOsoba->imie, imie );
    strcpy ( nowaOsoba->nazwisko, nazwisko );
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
    strcpy ( nazwisko, wczytajNapis(napis) );
    glowaOsoba = dodajOsobe(glowaOsoba, imie, nazwisko);
    return glowaOsoba;
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



