#include "poprawnosc.h"

int czyPlikPoprawny ( char nazwaPliku[ MAX ] )
{
    FILE *fp = NULL;
    printf("test");
    fp = fopen( nazwaPliku, "r");
    char linia[MAX];
    int numer;
    printf("test");
    while ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, "") )
    {
        if ( strlen( linia ) > MAX - 4 )
        {
            fclose( fp );
            return 0;
        }
    }
    fclose( fp );
    printf("test");
    fp = fopen( nazwaPliku, "r");
    if ( !fscanf( fp, "%s", linia ) || !porownajNapisy( linia, "*STUDENCI*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, "." ) && !porownajNapisy( linia, "") )
    {
        if ( !fscanf( fp, "%s", linia ) )
        {
            fclose( fp );
            return 0;
        }
        if ( !fscanf( fp, "%d", &numer ) )
        {
            fclose( fp );
            return 0;
        }
    }
    if ( !porownajNapisy( linia, ".") )
    {
        fclose( fp );
        return 0;
    }
    if ( !fscanf( fp, "%s", linia ) || !porownajNapisy( linia, "*PRACOWNICY*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, "." ) && !porownajNapisy( linia, "") )
    {
        if ( !fscanf( fp, "%s", linia ) )
        {
            fclose( fp );
            return 0;
        }
        if ( !fscanf( fp, "%d", &numer ) )
        {
            fclose( fp );
            return 0;
        }
    }
    if ( !porownajNapisy( linia, ".") )
    {
        fclose( fp );
        return 0;
    }
    if ( !fscanf( fp, "%s", linia ) || !porownajNapisy( linia, "*PRZEDMIOTY*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, "." ) && !porownajNapisy( linia, "") )
    {
    }
    if ( !porownajNapisy( linia, ".") || !fscanf( fp, "%s ", linia ) || !porownajNapisy( linia, "*STUDENT-PRZEDMIOT*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%d", &numer ) && !porownajNapisy( linia, "." ) && !porownajNapisy( linia, "" ) )
    {
        if ( !fscanf( fp, "%s", linia ) )
        {
            fclose( fp );
            return 0;
        }
    }
    if ( !porownajNapisy( linia, ".") )
    {
        fclose( fp );
        return 0;
    }
    if ( !porownajNapisy( linia, ".") || !fscanf( fp, "%s", linia ) || !porownajNapisy( linia, "*PRACOWNIK-PRZEDMIOT*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%d", &numer ) && !porownajNapisy( linia, "." ) && !porownajNapisy( linia, "") )
    {
        if ( !fscanf( fp, "%s", linia ) )
        {
            fclose( fp );
            return 0;
        }
    }
    if ( !porownajNapisy( linia, ".") )
    {
        fclose( fp );
        return 0;
    }
    fclose( fp );
    return 1;
}
