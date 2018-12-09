#include "struktury.h"

Osoba* dodajOsobe( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] )
{
    Osoba* nowaOsoba = malloc( sizeof( Osoba ) );
    nowaOsoba ->id = znajdzMaxId( glowa ) + 1 ;
    strcpy ( nowaOsoba ->imie, im );
    strcpy ( nowaOsoba ->nazwisko, nazw );
    nowaOsoba ->nast = glowa;
    return nowaOsoba;
}

Przedmiot* dodajPrzedmiot( Przedmiot* glowa, char nazw[ MAX ] )
{
    Przedmiot* nowyPrzedmiot = malloc( sizeof( Przedmiot ) );
    strcpy ( nowyPrzedmiot ->nazwa, nazw );
    nowyPrzedmiot ->nast = glowa;
    return nowyPrzedmiot;
}



OsobaPrzedmiot* dodajOsobaPrzedmiot( OsobaPrzedmiot* glowaOsobaPrzedmiot, Osoba* os, Przedmiot* przedm )
{
    OsobaPrzedmiot* nowyOsobaPrzedmiot = malloc ( sizeof( OsobaPrzedmiot ) );
    nowyOsobaPrzedmiot ->osoba = os;
    nowyOsobaPrzedmiot ->przedmiot = przedm;
    nowyOsobaPrzedmiot ->nast = glowaOsobaPrzedmiot;
    return nowyOsobaPrzedmiot;
}
