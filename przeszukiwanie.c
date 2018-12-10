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

Osoba* poprzednikOsoby( Osoba* glowa, Osoba* osoba)
{
    Osoba* poprzednik = NULL;
    while ( glowa != NULL )
    {
        if ( glowa == osoba )
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

Przedmiot* poprzednikPrzedmiotu( Przedmiot* glowa, Przedmiot* przedmiot )
{
    Przedmiot* poprzednik = NULL;
    while ( glowa != NULL )
    {
        if ( glowa == przedmiot )
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

OsobaPrzedmiot* wyszukajOsobaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* os, Przedmiot* przedm )
{
    while ( glowa != NULL )
    {
        if ( glowa ->osoba == os && glowa ->przedmiot == przedm )
            return glowa;
        glowa = glowa ->nast;
    }
    return glowa;
}

OsobaPrzedmiot* poprzednikOsobaPrzedmiot( OsobaPrzedmiot* glowa, OsobaPrzedmiot* osobaPrzedmiot )
{
    OsobaPrzedmiot* poprzednik = NULL;
    while ( glowa != NULL )
    {
        if ( osobaPrzedmiot == glowa )
            return poprzednik;
        poprzednik = glowa;
        glowa = glowa ->nast;
    }
    return glowa;
}

int znajdzMaxId( Osoba* glowa )
{
    int idMax = 0;
    while ( glowa )
    {
        if ( glowa ->id > idMax )
            idMax = glowa ->id;
        glowa = glowa ->nast;
    }
    return idMax;
}
