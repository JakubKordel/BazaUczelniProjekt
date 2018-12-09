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

OsobaPrzedmiot* podepnijStudentaNaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* studentGlowa, Przedmiot* przedmGlowa )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie podpinanego na przedmiot studenta: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko podpinanego na przedmiot studenta: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* student = wyszukajOsobe( studentGlowa, imie, nazwisko );
    printf("Podaj nazwe przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* przedmiot = wyszukajPrzedmiot( przedmGlowa, nazwa );
    glowa = dodajOsobaPrzedmiot( glowa, student, przedmiot );
    return glowa;
}

OsobaPrzedmiot* dajPracownikowiPrzedmiot( OsobaPrzedmiot* glowa, Osoba* pracownikGlowa, Przedmiot* przedmGlowa )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie pracownika: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko pracownika: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* pracownik = wyszukajOsobe( pracownikGlowa, imie, nazwisko );
    printf("Podaj nazwe przedmiotu ktory prowadzi pracownik: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* przedmiot = wyszukajPrzedmiot( przedmGlowa, nazwa );
    glowa = dodajOsobaPrzedmiot( glowa, pracownik, przedmiot );
    return glowa;
}

void wczytajStudentaDoWypisania( Osoba* glowaStudent, OsobaPrzedmiot* glowaOsobaPrzedmiot )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie studenta: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    wyczyscEkran();
    wypisStudent( wyszukajOsobe( glowaStudent, imie, nazwisko ), glowaOsobaPrzedmiot );
    getchar();
}

void wczytajPracownikaDoWypisania( Osoba* glowaPracownik, OsobaPrzedmiot* glowaPracownikPrzedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie pracownika: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko pracownika: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    wyczyscEkran();
    wypisPracownik( wyszukajOsobe( glowaPracownik, imie, nazwisko ), glowaPracownikPrzedmiot, glowaStudentPrzedmiot );
    getchar();
}

void wczytajPrzedmiotDoWypisania( Przedmiot* glowaPrzedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot, OsobaPrzedmiot* glowaPracownikPrzedmiot )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe przedmiotu do wypisania: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    wyczyscEkran();
    wypisPrzedmiot( wyszukajPrzedmiot( glowaPrzedmiot, nazwa ), glowaStudentPrzedmiot, glowaPracownikPrzedmiot );
    getchar();
}
