#include "wyswietlanie.h"

void wyswietlListeOsob( Osoba* glowaOsoba )
{
    while( glowaOsoba )
    {
        printf( "%d %s %s\n", glowaOsoba ->id, glowaOsoba ->imie, glowaOsoba ->nazwisko );
        glowaOsoba = glowaOsoba ->nast;
    }
}

void wyswietlListePrzedmiotow( Przedmiot* glowaPrzedmiot )
{
    while( glowaPrzedmiot )
    {
        printf( "%s \n", glowaPrzedmiot->nazwa );
        glowaPrzedmiot = glowaPrzedmiot->nast;
    }
}
