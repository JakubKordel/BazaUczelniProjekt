#include "zapis.h"

void zapiszBaze( Glowy* glowy, char* nazwaPliku )
{
    FILE *fp = NULL;
    fp = fopen( nazwaPliku, "w");
    Osoba* osoba;
    Przedmiot* przedmiot = glowy ->przedmiot;
    time_t czas;
    czas = time(0);
    fprintf( fp, "%lld\n", ( long long int )czas);
    for ( int i = 0; i < 2; ++i )
    {
        if  ( i == 0 )
        {
            fprintf( fp, "*STUDENCI*\n" );
            osoba = glowy ->student;
        }
        else
        {
            fprintf( fp, "*PRACOWNICY*\n" );
            osoba = glowy ->pracownik;
        }
        while ( osoba != NULL )
        {
            fprintf( fp, "%s\n", osoba ->imie );
            fprintf( fp, "%s\n", osoba ->nazwisko );
            fprintf( fp, "%d\n", osoba ->id );
            osoba  = osoba ->nast;
        }
        fprintf( fp, ".\n" );
    }
    fprintf( fp, "*PRZEDMIOTY*\n" );
    while ( przedmiot != NULL )
    {
        fprintf( fp, "%s\n", przedmiot ->nazwa );
        przedmiot  = przedmiot ->nast;
    }
    fprintf( fp, ".\n" );
    OsobaPrzedmiot* relacja = NULL;
    for ( int i = 0; i < 2; ++i )
    {
        if  ( i == 0 )
        {
            fprintf( fp, "*STUDENT-PRZEDMIOT*\n" );
            relacja = glowy ->studentPrzedmiot;
        }
        else
        {
            fprintf( fp, "*PRACOWNIK-PRZEDMIOT*\n" );
            relacja = glowy ->pracownikPrzedmiot;
        }
        while ( relacja != NULL )
        {
            fprintf( fp, "%d\n", relacja ->osoba ->id );
            fprintf( fp, "%s\n", relacja ->przedmiot ->nazwa );
            relacja = relacja ->nast;
        }
        fprintf( fp, ".\n" );
    }
    fclose( fp );
}

void wczytajBaze( Glowy* glowy, char* nazwaPliku )
{
    zwolnijOsoba( glowy ->student );
    zwolnijOsoba( glowy ->pracownik );
    zwolnijPrzedmiot( glowy ->przedmiot );
    zwolnijOsobaPrzedmiot( glowy ->studentPrzedmiot );
    zwolnijOsobaPrzedmiot( glowy ->pracownikPrzedmiot );
    glowy ->pracownik = NULL;
    glowy ->student = NULL;
    glowy ->przedmiot = NULL;
    glowy ->pracownikPrzedmiot = NULL;
    glowy ->studentPrzedmiot = NULL;
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char nazwa[ MAX ];
    int id;
    Osoba* osoba = NULL;
    Przedmiot* przedmiot = NULL;
    FILE *fp = NULL;
    fp = fopen( nazwaPliku, "r");
    char linia[MAX];
    char znacznik[MAX];
    for ( int i = 0; i < 2; ++i )
    {
        if  ( i == 0 )
            strcpy(znacznik, "*STUDENCI*");
        if ( i == 1 )
            strcpy(znacznik, "*PRACOWNICY*");
        while ( fscanf( fp, "%s ", linia ) && porownajNapisy( linia, znacznik ) == 0 )
        {
        }
        while ( fscanf( fp, "%s ", imie ) && porownajNapisy( imie, "." ) != 1)
        {
            fscanf( fp, "%s ", nazwisko );
            fscanf( fp, "%d ", &id );
            if  ( i == 0 )
            {
                if ( wyszukajOsobe( glowy ->student, imie, nazwisko ) == NULL && wyszukajOsobeWedlugId( glowy ->student, id ) == NULL )
                    glowy ->student = dodajOsobe( glowy ->student, imie, nazwisko, id );
            }
            if ( i == 1 )
            {
                if ( wyszukajOsobe( glowy ->pracownik, imie, nazwisko ) == NULL && wyszukajOsobeWedlugId( glowy ->pracownik, id ) == NULL )
                    glowy ->pracownik = dodajOsobe( glowy ->pracownik, imie, nazwisko, id );
            }
        }
    }
    strcpy( znacznik, "*PRZEDMIOTY*" );
    while ( fscanf( fp, "%s ", linia ) && porownajNapisy( linia, znacznik ) == 0 )
    {
    }
    while ( fscanf( fp, "%s ", nazwa ) && porownajNapisy( nazwa, "." ) == 0)
    {
        if ( wyszukajPrzedmiot( glowy ->przedmiot, nazwa ) == NULL )
            glowy ->przedmiot = dodajPrzedmiot( glowy ->przedmiot, nazwa );
    }
    for ( int i = 0; i < 2; ++i )
    {
        if  ( i == 0 )
            strcpy(znacznik, "*STUDENT-PRZEDMIOT*");
        if ( i == 1 )
            strcpy(znacznik, "*PRACOWNIK-PRZEDMIOT*");
        while ( fscanf( fp, "%s ", linia ) && porownajNapisy( linia, znacznik ) == 0 )
        {
        }
        while ( fscanf( fp, "%d ", &id ) )
        {
            fscanf( fp, "%s ", nazwa );
            if  ( i == 0 )
            {
                osoba = wyszukajOsobeWedlugId( glowy ->student, id );
                przedmiot = wyszukajPrzedmiot( glowy->przedmiot, nazwa );
                if ( osoba && przedmiot )
                    glowy ->studentPrzedmiot = dodajOsobaPrzedmiot( glowy ->studentPrzedmiot, osoba, przedmiot );
            }
            if ( i == 1 )
            {
                osoba = wyszukajOsobeWedlugId( glowy ->pracownik, id );
                przedmiot = wyszukajPrzedmiot( glowy->przedmiot, nazwa );
                if ( osoba && przedmiot )
                    glowy ->pracownikPrzedmiot = dodajOsobaPrzedmiot( glowy ->pracownikPrzedmiot, osoba, przedmiot );
            }
        }
    }
    fclose( fp );
}

void wczytajNazwyPlikow( Glowy* glowy )
{
    zwolnijNazwaPliku( glowy ->nazwaPliku );
    DIR* strumien = opendir( "." );
    struct dirent* nazwy = readdir( strumien );
    long long int czas = 0;
    while ( nazwy != NULL )
    {
        if ( czyPrawidloweRozszerzenie( nazwy ->d_name ) )
        {
            FILE *fp = NULL;
            fp = fopen( nazwy ->d_name, "r");
            if ( !fscanf( fp, "%llu", &czas ) )
                czas = 0;
            glowy ->nazwaPliku = dodajNazwaPliku( glowy ->nazwaPliku, nazwy ->d_name, czas );
            fclose( fp );
        }
        nazwy = readdir( strumien );
    }
}

