#include "sortowanie.h"

Osoba* posortujWedlugNazwiska( Osoba* glowa )
{
    unsigned int n, flaga;
    Osoba* poprzedni = NULL;
    Osoba* pierwszy = NULL;
    Osoba* drugi = NULL;
    n = policzOsoby( glowa );
    if ( n < 2 )
        return glowa;
    do
    {
        flaga = 0;
        pierwszy = glowa;
        drugi = glowa ->nast;
        for ( int i = 0 ; i < n - 1 ; ++i )
        {
            int wskaznik = czyNapisyKolejneAlfabetycznie( pierwszy ->nazwisko, drugi ->nazwisko );
            if ( wskaznik == 2 )
                wskaznik = czyNapisyKolejneAlfabetycznie( pierwszy ->imie, drugi ->imie );
            if ( wskaznik == 0 )
            {
                pierwszy ->nast = drugi ->nast;
                drugi ->nast = pierwszy;
                if ( i == 0)
                    glowa = drugi;
                else
                    poprzedni ->nast = drugi;
                poprzedni = drugi;
                drugi = pierwszy ->nast;
                flaga = 1;
            }
            else
            {
                poprzedni = pierwszy;
                pierwszy = drugi;
                drugi = drugi ->nast;
            }
        }
        --n;
    }
    while ( flaga );
    return glowa;
}

Osoba* posortujWedlugImienia( Osoba* glowa )
{
    unsigned int n, flaga;
    Osoba* poprzedni = NULL;
    Osoba* pierwszy = NULL;
    Osoba* drugi = NULL;
    n = policzOsoby( glowa );
    if ( n < 2 )
        return glowa;
    do
    {
        flaga = 0;
        pierwszy = glowa;
        drugi = glowa ->nast;
        for ( int i = 0 ; i < n - 1 ; ++i )
        {
            if ( !czyNapisyKolejneAlfabetycznie( pierwszy ->imie, drugi ->imie ) )
            {
                pierwszy ->nast = drugi ->nast;
                drugi ->nast = pierwszy;
                if ( i == 0)
                    glowa = drugi;
                else
                    poprzedni ->nast = drugi;
                poprzedni = drugi;
                drugi = pierwszy ->nast;
                flaga = 1;
            }
            else
            {
                poprzedni = pierwszy;
                pierwszy = drugi;
                drugi = drugi ->nast;
            }
        }
        --n;
    }
    while ( flaga );
    return glowa;
}

Przedmiot* posortujWedlugNazwy( Przedmiot* glowa )
{
    unsigned int n, flaga;
    Przedmiot* poprzedni = NULL;
    Przedmiot* pierwszy = NULL;
    Przedmiot* drugi = NULL;
    n = policzPrzedmioty( glowa );
    if ( n < 2 )
        return glowa;
    do
    {
        flaga = 0;
        pierwszy = glowa;
        drugi = glowa ->nast;
        for ( int i = 0 ; i < n - 1 ; ++i )
        {
            if ( !czyNapisyKolejneAlfabetycznie( pierwszy ->nazwa, drugi ->nazwa ) )
            {
                pierwszy ->nast = drugi ->nast;
                drugi ->nast = pierwszy;
                if ( i == 0)
                    glowa = drugi;
                else
                    poprzedni ->nast = drugi;
                poprzedni = drugi;
                drugi = pierwszy ->nast;
                flaga = 1;
            }
            else
            {
                poprzedni = pierwszy;
                pierwszy = drugi;
                drugi = drugi ->nast;
            }
        }
        --n;
    }
    while ( flaga );
    return glowa;
}

Osoba* posortujWedlugIndeksu( Osoba* glowa )
{
    unsigned int n, flaga;
    Osoba* poprzedni = NULL;
    Osoba* pierwszy = NULL;
    Osoba* drugi = NULL;
    n = policzOsoby( glowa );
    if ( n < 2 )
        return glowa;
    do
    {
        flaga = 0;
        pierwszy = glowa;
        drugi = glowa ->nast;
        for ( int i = 0 ; i < n - 1 ; ++i )
        {
            if ( pierwszy ->id > drugi ->id )
            {
                pierwszy ->nast = drugi ->nast;
                drugi ->nast = pierwszy;
                if ( i == 0)
                    glowa = drugi;
                else
                    poprzedni ->nast = drugi;
                poprzedni = drugi;
                drugi = pierwszy ->nast;
                flaga = 1;
            }
            else
            {
                poprzedni = pierwszy;
                pierwszy = drugi;
                drugi = drugi ->nast;
            }
        }
        --n;
    }
    while ( flaga );
    return glowa;
}

