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

Osoba* wczytajUsuwanaOsobe( Osoba* glowa )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char napis[ MAX ];
    printf("Podaj imie usuwanej osoby: ");
    strcpy ( imie, wczytajNapis( napis ) );
    printf("Podaj nazwisko usuwanej osoby: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    if ( !wyszukajOsobe( glowa, imie, nazwisko ) )
    {
        printf("Taka osoba nie istnieje!\n" );
        getchar();
        return glowa;
    }
    glowa = usuwanieOsoby( glowa, imie, nazwisko);
    return glowa;
}

Przedmiot* wczytajUsuwanyPrzedmiot( Przedmiot* glowa )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe usuwanego przedmiotu: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    if ( !wyszukajPrzedmiot( glowa, nazwa ) )
    {
        printf("Taki przedmiot nie istnieje!\n" );
        getchar();
        return glowa;
    }
    glowa = usuwaniePrzedmiotu( glowa, nazwa );
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
    if ( pracownik == NULL )
    {
        printf("Taki pracownik nie istnieje!\n" );
        getchar();
        return glowa;
    }
    printf("Podaj nazwe przedmiotu ktory prowadzi pracownik: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* przedmiot = wyszukajPrzedmiot( przedmGlowa, nazwa );
    if ( przedmiot == NULL )
    {
        printf("Taki przedmiot nie istnieje!\n" );
        getchar();
        return glowa;
    }
    OsobaPrzedmiot* x = glowa;
    while ( x )
    {
        if ( x ->przedmiot == przedmiot )
        {
            printf("Ten przedmiot ma juz prowadzacego!\n" );
            getchar();
            return glowa;
        }
        x = x ->nast;
    }
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
    printf("Podaj nazwisko studenta: ");
    strcpy ( nazwisko, wczytajNapis( napis ) );
    Osoba* student = wyszukajOsobe( glowaStudent, imie, nazwisko );
    if ( student == NULL )
    {
        printf("Taki student nie istnieje!\n" );
        getchar();
    }
    else
    {
        wyczyscEkran();
        wypisStudent( student, glowaOsobaPrzedmiot );
        getchar();
    }
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
    Osoba* pracownik = wyszukajOsobe( glowaPracownik, imie, nazwisko );
    if ( pracownik == NULL )
    {
        printf("Taki pracownik nie istnieje!\n" );
        getchar();
    }
    else
    {
        wyczyscEkran();
        wypisPracownik( pracownik, glowaPracownikPrzedmiot, glowaStudentPrzedmiot );
        getchar();
    }
}

void wczytajPrzedmiotDoWypisania( Przedmiot* glowaPrzedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot, OsobaPrzedmiot* glowaPracownikPrzedmiot )
{
    char nazwa[ MAX ];
    char napis[ MAX ];
    printf("Podaj nazwe przedmiotu do wypisania: ");
    strcpy ( nazwa, wczytajNapis( napis ) );
    Przedmiot* przedmiot = wyszukajPrzedmiot( glowaPrzedmiot, nazwa );
    if ( przedmiot == NULL )
    {
        printf("Taki przedmiot nie istnieje!\n" );
        getchar();
    }
    else
    {
        wyczyscEkran();
        wypisPrzedmiot( przedmiot, glowaStudentPrzedmiot, glowaPracownikPrzedmiot );
        getchar();
    }
}
