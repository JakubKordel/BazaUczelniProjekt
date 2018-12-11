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
    glowaOsoba = dodajOsobe( glowaOsoba, imie, nazwisko );
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

void wczytajUsuwanegoStudenta( Glowy* glowy )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie usuwanego studenta: ");
    strcpy ( imie, wczytajNapis( napis ) );
    printf("Podaj nazwisko usuwanego studenta: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* usuwany = wyszukajOsobe( glowy ->student, imie, nazwisko );
    if ( !usuwany )
    {
        printf("Taka osoba nie istnieje!\n" );
        getchar();
    }
    else
        usuwanieStudenta( glowy, usuwany );
}

void wczytajUsuwanegoPracownika( Glowy* glowy )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie usuwanego pracownika: ");
    strcpy ( imie, wczytajNapis( napis ) );
    printf("Podaj nazwisko usuwanego pracownika: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* usuwany = wyszukajOsobe( glowy ->pracownik, imie, nazwisko );
    if ( !usuwany )
    {
        printf("Taka osoba nie istnieje!\n" );
        getchar();
    }
    else
        usuwaniePracownika( glowy, usuwany );
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
    if ( student == NULL )
    {
        printf("Taki student nie istnieje!\n" );
        getchar();
        return glowa;
    }
    printf("Podaj nazwe przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* przedmiot = wyszukajPrzedmiot( przedmGlowa, nazwa );
    if ( przedmiot == NULL )
    {
        printf("Taki przedmiot nie istnieje!\n" );
        getchar();
        return glowa;
    }
    if ( wyszukajOsobaPrzedmiot( glowa, student, przedmiot ) )
    {
        printf("Student juz jest zapisany na ten przedmiot!\n" );
        getchar();
        return glowa;
    }
    glowa = dodajOsobaPrzedmiot( glowa, student, przedmiot );
    return glowa;
}

void dajStudentowiPrzedmiot( Glowy* glowy, Osoba* student )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* przedmiot = wyszukajPrzedmiot( glowy ->przedmiot, nazwa );
    if ( przedmiot == NULL )
    {
        printf("Taki przedmiot nie istnieje!\n" );
        getchar();
    }
    else
    {
        if ( wyszukajOsobaPrzedmiot( glowy ->studentPrzedmiot, student, przedmiot ) )
        {
            printf("Student juz jest zapisany na ten przedmiot!\n" );
            getchar();
        }
        else
            glowy ->studentPrzedmiot = dodajOsobaPrzedmiot( glowy ->studentPrzedmiot, student, przedmiot );
    }
}

void dajPrzedmiotowiStudenta( Glowy* glowy, Przedmiot *przedmiot )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie podpinanego na przedmiot studenta: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko podpinanego na przedmiot studenta: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* student = wyszukajOsobe( glowy ->student, imie, nazwisko );
    if ( student == NULL )
    {
        printf("Taki student nie istnieje!\n" );
        getchar();
    }
    else
    {
        if ( wyszukajOsobaPrzedmiot( glowy ->studentPrzedmiot, student, przedmiot ) )
        {
            printf("Student juz jest zapisany na ten przedmiot!\n" );
            getchar();
        }
        else
            glowy ->studentPrzedmiot = dodajOsobaPrzedmiot( glowy ->studentPrzedmiot, student, przedmiot );
    }
}

void dajPrzedmiotowiProwadzacego( Glowy* glowy, Przedmiot *przedmiot )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie pracownika: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko pracownika: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* pracownik = wyszukajOsobe( glowy ->pracownik, imie, nazwisko );
    int flaga = 0;
    if ( pracownik == NULL )
    {
        printf("Taki pracownik nie istnieje!\n" );
        getchar();
        flaga = 1;
    }
    OsobaPrzedmiot* x = glowy ->pracownikPrzedmiot;
    while ( x && flaga == 0 )
    {
        if ( x ->przedmiot == przedmiot )
        {
            printf("Ten przedmiot ma juz prowadzacego!\n" );
            getchar();
            flaga = 1;
        }
        x = x ->nast;
    }
    if ( flaga == 0)
        glowy ->pracownikPrzedmiot = dodajOsobaPrzedmiot( glowy ->pracownikPrzedmiot, pracownik, przedmiot );
}

void dajPracownikowiPrzedmiot( Glowy* glowy, Osoba* pracownik )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe przedmiotu ktory ma prowadzic pracownik: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* przedmiot = wyszukajPrzedmiot( glowy ->przedmiot, nazwa );
    int flaga = 0;
    if ( przedmiot == NULL )
    {
        printf("Taki przedmiot nie istnieje!\n" );
        getchar();
        flaga = 1;
    }
    OsobaPrzedmiot* x = glowy ->pracownikPrzedmiot;
    while ( x && flaga == 0 )
    {
        if ( x ->przedmiot == przedmiot )
        {
            printf("Ten przedmiot ma juz prowadzacego!\n" );
            getchar();
            flaga = 1;
        }
        x = x ->nast;
    }
    if ( flaga == 0)
        glowy ->pracownikPrzedmiot = dodajOsobaPrzedmiot( glowy ->pracownikPrzedmiot, pracownik, przedmiot );

}

void wczytajStudentaDoWypisania( Glowy* glowy )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie studenta: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko studenta: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* student = wyszukajOsobe( glowy ->student, imie, nazwisko );
    if ( student == NULL )
    {
        printf("Taki student nie istnieje!\n" );
        getchar();
    }
    else
    {
        wyczyscEkran();
        wypisStudent( student, glowy );
        getchar();
    }
}

void wczytajPracownikaDoWypisania( Glowy* glowy )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie pracownika: ");
    strcpy ( imie, wczytajNapis(napis) );
    printf("Podaj nazwisko pracownika: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* pracownik = wyszukajOsobe( glowy ->pracownik, imie, nazwisko );
    if ( pracownik == NULL )
    {
        printf("Taki pracownik nie istnieje!\n" );
        getchar();
    }
    else
    {
        wyczyscEkran();
        wypisPracownik( glowy, pracownik );
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

