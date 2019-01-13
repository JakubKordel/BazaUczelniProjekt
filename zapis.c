#include "zapis.h"

void zapiszBaze( Glowy* glowy, char* nazwaPliku )
{
    FILE *fp = NULL;
    fp = fopen( nazwaPliku, "w");
    Osoba* osoba;
    Przedmiot* przedmiot = glowy ->przedmiot;
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
    fclose( fp );
}

void wczytajBaze( Glowy* glowy, char* nazwaPliku )
{
    char imie[ MAX ];
    char nazwisko[ MAX ];
    char nazwa[ MAX ];
    int id;
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
                glowy ->student = dodajOsobe( glowy ->student, imie, nazwisko, id );
            if ( i == 1 )
                glowy ->pracownik = dodajOsobe( glowy ->pracownik, imie, nazwisko, id );
        }
    }
    strcpy( znacznik, "*PRZEDMIOTY*" );
    while ( fscanf( fp, "%s ", linia ) && porownajNapisy( linia, znacznik ) == 0 )
        {
        }
    while ( fscanf( fp, "%s ", nazwa ) && porownajNapisy( nazwa, "." ) == 0)
        {
            glowy ->przedmiot = dodajPrzedmiot( glowy ->przedmiot, nazwa );
        }
    fclose( fp );
}
