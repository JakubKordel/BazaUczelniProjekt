#include "funkcje.h"
#include <stdlib.h>

void zwolnijOsoba( Osoba* glowa )
{
    Osoba* poprzedni = NULL;
    while( glowa )
    {
        poprzedni = glowa;
        glowa = glowa -> nast;
        free( poprzedni );
    }
}

void zwolnijPrzedmiot( Przedmiot* glowa )
{
    Przedmiot* poprzedni = NULL;
    while( glowa )
    {
        poprzedni = glowa;
        glowa = glowa -> nast;
        free( poprzedni );
    }
}

void zwolnijOsobaPrzedmiot( OsobaPrzedmiot* glowa )
{
    OsobaPrzedmiot* poprzedni = NULL;
    while( glowa )
    {
        poprzedni = glowa;
        glowa = glowa -> nast;
        free( poprzedni );
    }

}


