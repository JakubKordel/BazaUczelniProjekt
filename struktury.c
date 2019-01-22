#include "struktury.h"
#include "przeszukiwanie.h"

Osoba* dodajOsobe( Osoba* glowa, char im[ MAX ], char nazw[ MAX ], int id )
{
    Osoba* nowaOsoba = malloc( sizeof( Osoba ) );
    if ( id == 0 )
        nowaOsoba ->id = znajdzMaxId( glowa ) + 1 ;
    else
        nowaOsoba ->id = id;
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

NazwaPliku* dodajNazwaPliku( NazwaPliku* glowa, char nazw[ MAX ], long long int czasLiczba )
{
    NazwaPliku* nowaNazwa = malloc( sizeof( NazwaPliku ) );
    strcpy ( nowaNazwa ->nazwa, nazw );
    nowaNazwa ->czas = czasLiczba;
    nowaNazwa ->nast = glowa;
    return nowaNazwa;
}
