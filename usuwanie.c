#include "usuwanie.h"
#include <stdlib.h>

Osoba* usuwaniePierwszejOsoby( Osoba* glowa )
{
    if ( glowa )
    {
        Osoba* pierwszy = glowa;
        glowa = glowa -> nast;
        free( pierwszy );
    }
    return glowa;
}

Osoba* usuwanieOsoby( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] )
{
    Osoba* poprzednik = NULL;
    if ( glowa != NULL )
    {
        if ( porownajNapisy( glowa ->imie, im ) && porownajNapisy( glowa ->nazwisko, nazw ) )
            glowa = usuwaniePierwszejOsoby( glowa );
        else
        {
            Osoba* usuwana = wyszukajOsobe( glowa, im, nazw );
            if ( usuwana )
            {
                poprzednik = poprzednikOsoby( glowa, im, nazw );
                poprzednik ->nast = usuwana ->nast;
                free( usuwana );
            }
        }
    }
        return glowa;
}

Przedmiot* usuwaniePierwszegoPrzedmiotu( Przedmiot* glowa )
{
    if ( glowa )
    {
        Przedmiot* pierwszy = glowa;
        glowa = glowa -> nast;
        free( pierwszy );
    }
    return glowa;
}

Przedmiot* usuwaniePrzedmiotu( Przedmiot* glowa, char nazw[ MAX ] )
{
    if ( porownajNapisy( glowa ->nazwa, nazw ) )
        glowa = usuwaniePierwszegoPrzedmiotu( glowa );
    else
    {
        Przedmiot* usuwany = wyszukajPrzedmiot( glowa, nazw );
        if ( usuwany )
        {
            poprzednikPrzedmiotu( glowa, nazw ) ->nast = usuwany ->nast;
            free( usuwany );
        }
    }
    return glowa;
}

OsobaPrzedmiot* usuwaniePierwszejOsobaPrzedmiot( OsobaPrzedmiot* glowa )
{
    if ( glowa )
    {
        OsobaPrzedmiot* pierwszy = glowa;
        glowa = glowa -> nast;
        free( pierwszy );
    }
    return glowa;
}

OsobaPrzedmiot* usuwanieOsobaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* os, Przedmiot* przedm )
{
        if ( glowa ->osoba == os && glowa ->przedmiot == przedm )
        glowa = usuwaniePierwszejOsobaPrzedmiot( glowa );
    else
    {
        OsobaPrzedmiot* usuwany = wyszukajOsobaPrzedmiot( glowa, os, przedm );
        if ( usuwany )
        {
            poprzednikOsobaPrzedmiot( glowa, os, przedm ) ->nast = usuwany ->nast;
            free( usuwany );
        }
    }
    return glowa;
}
