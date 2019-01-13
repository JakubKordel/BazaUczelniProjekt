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
    if ( wyszukajOsobe( glowaOsoba, imie, nazwisko ) )
    {
        printf("Taka osoba juz istnieje!\n" );
        getchar();
        return glowaOsoba;
    }
    glowaOsoba = dodajOsobe( glowaOsoba, imie, nazwisko, 0 );
    return glowaOsoba;
}

Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    if ( wyszukajPrzedmiot( glowaPrzedmiot, nazwa ) )
    {
        printf("Taki Przedmiot juz istnieje!\n" );
        getchar();
        return glowaPrzedmiot;
    }
    glowaPrzedmiot = dodajPrzedmiot( glowaPrzedmiot, nazwa );
    return glowaPrzedmiot;
}

void wczytajUsuwanaOsobe( Glowy* glowy, int typOsoby )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    if ( typOsoby == 1 )
        printf("Podaj imie usuwanego studenta: ");
    if ( typOsoby == 2 )
        printf("Podaj imie usuwanego pracownika: ");
    strcpy ( imie, wczytajNapis( napis ) );
    if ( typOsoby == 1 )
        printf("Podaj nazwisko usuwanego studenta: ");
    if ( typOsoby == 2 )
        printf("Podaj nazwisko usuwanego pracownika: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* usuwany = NULL;
    if ( typOsoby == 1 )
        usuwany = wyszukajOsobe( glowy ->student, imie, nazwisko );
    if ( typOsoby == 2 )
        usuwany = wyszukajOsobe( glowy ->pracownik, imie, nazwisko );
    if ( !usuwany )
    {
        printf("Taka osoba nie istnieje!\n" );
        getchar();
    }
    else
    {
        if ( typOsoby == 1 )
            usuwanieStudenta( glowy, usuwany );
        if ( typOsoby == 2 )
            usuwaniePracownika( glowy, usuwany );
    }
}

void wczytajUsuwanyPrzedmiot( Glowy* glowy )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe usuwanego przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* usuwany = wyszukajPrzedmiot( glowy ->przedmiot, nazwa );
    if ( !usuwany )
    {
        printf("Taki przedmiot nie istnieje!\n" );
        getchar();
    }
    else
        usuwaniePrzedmiotu( glowy, usuwany );
}

void podepnijOsobeNaPrzedmiot( Glowy *glowy, Osoba* osoba, Przedmiot* przedm, int typOsoby )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char nazwa[ MAX ];
    char napis[ MAX ];
    int blad = 0 ;
    if ( osoba == NULL )
    {
        if ( typOsoby == 1 )
            printf("Podaj imie podpinanego na przedmiot studenta: ");
        if ( typOsoby == 2 )
            printf("Podaj imie prowadzacego, ktory ma prowadzic przedmiot: ");
        strcpy ( imie, wczytajNapis(napis) );
        if ( typOsoby == 1 )
            printf("Podaj nazwisko podpinanego na przedmiot studenta: ");
        if ( typOsoby == 2 )
            printf("Podaj nazwisko prowadzacego, ktory ma prowadzic przedmiot: ");
        strcpy ( nazwisko, wczytajNapis( napis ) );
        if ( typOsoby == 1 )
            osoba = wyszukajOsobe( glowy ->student, imie, nazwisko );
        if ( typOsoby == 2 )
            osoba = wyszukajOsobe( glowy ->pracownik, imie, nazwisko );
        if ( osoba == NULL )
        {
            if ( typOsoby == 1 )
                printf("Taki student nie istnieje!\n" );
            if ( typOsoby == 2 )
                printf("Taki pracownik nie istnieje!\n" );
            getchar();
            blad = 1;
        }
    }
    if ( przedm == NULL && blad == 0 )
    {
        printf("Podaj nazwe przedmiotu: ");
        strcpy ( nazwa, wczytajNapis( napis ) );
        przedm = wyszukajPrzedmiot( glowy ->przedmiot, nazwa );
        if ( przedm == NULL )
        {
            printf("Taki przedmiot nie istnieje!\n" );
            getchar();
            blad = 1;
        }
    }
    if ( typOsoby == 1 && blad == 0 )
    {
        if ( wyszukajOsobaPrzedmiot( glowy ->studentPrzedmiot, osoba, przedm ) && blad == 0 )
        {
            printf("Student juz jest zapisany na ten przedmiot!\n" );
            getchar();
            blad = 1;
        }
        if ( blad == 0 )
            glowy ->studentPrzedmiot = dodajOsobaPrzedmiot( glowy ->studentPrzedmiot, osoba, przedm );
    }
    if ( typOsoby == 2 && blad == 0 )
    {
        OsobaPrzedmiot* x = glowy ->pracownikPrzedmiot;
        while ( x )
        {
            if ( x ->przedmiot == przedm )
            {
                printf("Ten przedmiot ma juz prowadzacego!\n" );
                getchar();
                blad = 1;
            }
            x = x ->nast;
        }
        if ( blad == 0)
            glowy ->pracownikPrzedmiot = dodajOsobaPrzedmiot( glowy ->pracownikPrzedmiot, osoba, przedm );
    }
}

void wczytajOsobeDoWypisania( Glowy* glowy, int typOsoby )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    if ( typOsoby == 1 )
        printf("Podaj imie studenta: ");
    if ( typOsoby == 2 )
        printf("Podaj imie pracownika: ");
    strcpy ( imie, wczytajNapis(napis) );
    if ( typOsoby == 1 )
        printf("Podaj nazwisko studenta: ");
    if ( typOsoby == 2 )
        printf("Podaj nazwisko pracownika: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* osoba = NULL;
    if ( typOsoby == 1 )
        osoba = wyszukajOsobe( glowy ->student, imie, nazwisko );
    if ( typOsoby == 2 )
        osoba = wyszukajOsobe( glowy ->pracownik, imie, nazwisko );
    if ( osoba == NULL )
    {
        printf("Taka osoba nie istnieje!\n" );
        getchar();
    }
    else
    {
        wyczyscEkran();
        if ( typOsoby == 1 )
            wypisStudent( osoba, glowy );
        if ( typOsoby == 2 )
            wypisPracownik( glowy, osoba );
        getchar();
    }
}

void wczytajPrzedmiotDoWypisania( Glowy* glowy )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe przedmiotu do wypisania: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* przedmiot = wyszukajPrzedmiot( glowy ->przedmiot, nazwa );
    if ( przedmiot == NULL )
    {
        printf("Taki przedmiot nie istnieje!\n" );
        getchar();
    }
    else
    {
        wyczyscEkran();
        wypisPrzedmiot( przedmiot, glowy );
        getchar();
    }
}

void usunZprzedmiotuStudenta( Glowy* glowy, Przedmiot* przedmiot )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie usuwanego studenta z przedmiotu: ");
    strcpy ( imie, wczytajNapis( napis ) );
    printf("Podaj nazwisko usuwanego studenta z przedmiotu: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* student = wyszukajOsobe( glowy ->student, imie, nazwisko );
    if ( student == NULL )
    {
        printf("Taki student nie istnieje!\n" );
        getchar();
    }
    else
    {
        OsobaPrzedmiot* usuwany = wyszukajOsobaPrzedmiot( glowy ->studentPrzedmiot, student, przedmiot );
        if ( !usuwany )
        {
            printf("Taka osoba nie widnieje na liscie!\n" );
            getchar();
        }
        else
            glowy ->studentPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->studentPrzedmiot, usuwany );
    }
}

void usunZprzedmiotuProwadzacego( Glowy* glowy, Przedmiot* przedm )
{
    OsobaPrzedmiot* x = glowy ->pracownikPrzedmiot;
    Osoba* pracownik = NULL;
    while ( x )
    {
        if ( x ->przedmiot == przedm )
            pracownik = x ->osoba;
        x = x ->nast;
    }
    if ( pracownik )
    {
        x = wyszukajOsobaPrzedmiot( glowy ->pracownikPrzedmiot, pracownik, przedm );
        glowy ->pracownikPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->pracownikPrzedmiot, x );
    }
}

