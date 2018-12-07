#include "wyswietlanie.h"

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
