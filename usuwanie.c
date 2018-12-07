#include "usuwanie.h"

Osoba* usuwaniePierwszejOsoby( Osoba* glowa )
{
    if ( glowa )
    {
        Osoba* pierwszy = NULL;
        pierwszy = glowa;
        glowa = glowa -> nast;
        free( pierwszy );
    }
    return glowa;
}

Osoba* usuwanieOsoby( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] )
{
    if ( glowa ->imie == im && glowa ->nazwisko == nazw )
        glowa = usuwaniePierwszejOsoby( glowa );
    else
    {
        Osoba* usuwana = wyszukajOsobe( glowa, im, nazw );
        if ( usuwana )
        {
            poprzednikOsoby( glowa, im, nazw ) ->nast = usuwana ->nast;
            free( usuwana );
        }
    }
    return glowa;
}

Przedmiot* usuwaniePierwszegoPrzedmiotu( Przedmiot* glowa )
{
    if ( glowa )
    {
        Przedmiot* pierwszy = NULL;
        pierwszy = glowa;
        glowa = glowa -> nast;
        free( pierwszy );
    }
    return glowa;
}

Przedmiot* usuwaniePrzedmiotu( Przedmiot* glowa, char nazw[ MAX ] )
{
    if ( glowa ->nazwa == nazw )
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
