#include "uzytkownik.h"

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

Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    glowaPrzedmiot = dodajPrzedmiot( glowaPrzedmiot, nazwa );
    return glowaPrzedmiot;
}

Osoba* wczytajUsuwanaOsobe( Osoba* glowa )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie usuwanej osoby: ");
    strcpy ( imie, wczytajNapis( napis ) );
    printf("Podaj nazwisko usuwanej osoby: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    glowa = usuwanieOsoby( glowa, imie, nazwisko);
    return glowa;
}
