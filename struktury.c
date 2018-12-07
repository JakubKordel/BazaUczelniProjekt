#include "struktury.h"

Osoba* dodajOsobe( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] )
{
    Osoba* nowaOsoba = malloc( sizeof( Osoba ) );
    strcpy ( nowaOsoba ->imie, im );
    strcpy ( nowaOsoba ->nazwisko, nazw );
    nowaOsoba ->nast = glowa;
    return nowaOsoba;
}


Osoba* wczytajOsobe( Osoba* glowaOsoba )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    glowaOsoba = dodajOsobe(glowaOsoba, imie, nazwisko);
    return glowaOsoba;
}

Przedmiot* dodajPrzedmiot( Przedmiot* glowa, char nazw[ MAX ] )
{
    Przedmiot* nowyPrzedmiot = malloc( sizeof( Przedmiot ) );
    strcpy ( nowyPrzedmiot ->nazwa, nazw );
    nowyPrzedmiot ->nast = glowa;
    return nowyPrzedmiot;
}

Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    glowaPrzedmiot = dodajPrzedmiot( glowaPrzedmiot, nazwa );
    return glowaPrzedmiot;
}

OsobaPrzedmiot* dodajOsobaPrzedmiot( OsobaPrzedmiot* glowaOsobaPrzedmiot, Osoba* os, Przedmiot* przedm )
{
    OsobaPrzedmiot* nowyOsobaPrzedmiot = malloc ( sizeof( OsobaPrzedmiot ) );
    nowyOsobaPrzedmiot ->osoba = os;
    nowyOsobaPrzedmiot ->przedmiot = przedm;
    nowyOsobaPrzedmiot ->nast = glowaOsobaPrzedmiot;
    return nowyOsobaPrzedmiot;
}
