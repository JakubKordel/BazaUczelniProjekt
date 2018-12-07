#include "funkcje.h"
#include <stdlib.h>
#include <string.h>

void zwolnijOsoba( Osoba* glowa )
{
    Osoba* poprzedni=NULL;
    while( glowa )
    {
        poprzedni = glowa;
        glowa = glowa -> nast;
        free( poprzedni );
    }
}

void zwolnijPrzemdiot( Przedmiot* glowa )
{
    Przedmiot* poprzedni = NULL;
    while( glowa )
    {
        poprzedni = glowa;
        glowa = glowa -> nast;
        free( poprzedni );
    }
}



