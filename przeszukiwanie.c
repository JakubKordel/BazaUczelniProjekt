#include "przeszukiwanie.h"

Osoba* wyszukajOsobe( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] )
{
    while ( glowa != NULL )
    {
        if ( porownajNapisy( glowa ->imie, im ) && porownajNapisy( glowa ->nazwisko, nazw ) )
            return glowa;
        glowa = glowa ->nast;
    }
    return glowa;
}

Osoba* poprzednikOsoby( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] )
{
    Osoba* poprzednik = NULL;
    while ( glowa != NULL )
    {
        if ( porownajNapisy( glowa ->imie, im ) && porownajNapisy( glowa ->nazwisko, nazw ) )
            return poprzednik;
        poprzednik = glowa;
        glowa = glowa ->nast;
    }
    return glowa;
}

unsigned int policzOsoby( Osoba* glowa )
{
    unsigned int licznik = 0;
    while ( glowa )
    {
        ++licznik;
        glowa = glowa ->nast;
    }
    return licznik;
}

Przedmiot* wyszukajPrzedmiot( Przedmiot* glowa, char nazw[ MAX ] )
{
    while ( glowa != NULL )
    {
        if ( porownajNapisy( glowa ->nazwa, nazw ) )
            return glowa;
        glowa = glowa ->nast;
    }
    return glowa;
}

Przedmiot* poprzednikPrzedmiotu( Przedmiot* glowa, char nazw[ MAX ] )
{
    Przedmiot* poprzednik = NULL;
    while ( glowa != NULL )
    {
        if ( porownajNapisy(glowa ->nazwa, nazw ) )
            return poprzednik;
        poprzednik = glowa;
        glowa = glowa ->nast;
    }
    return glowa;
}

unsigned int policzPrzedmioty ( Przedmiot* glowa )
{
    unsigned int licznik = 0;
    while ( glowa )
    {
        ++licznik;
        glowa = glowa ->nast;
    }
    return licznik;
}
