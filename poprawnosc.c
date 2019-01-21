#include "poprawnosc.h"

int czyPlikPoprawny ( char nazwaPliku[ MAX ] )
{
    FILE *fp = NULL;
    fp = fopen( nazwaPliku, "r");
    char linia[MAX];
    int numer;
    while ( fscanf( fp, "%s", linia ) != 0 && feof( fp ) == 0 )
    {
        if ( strlen( linia ) > MAX - 4 )
        {
            fclose( fp );
            return 0;
        }
    }
    fclose( fp );
    fp = fopen( nazwaPliku, "r");
    if ( !fscanf( fp, "%s", linia ) || !porownajNapisy( linia, "*STUDENCI*")  )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, "." ) && feof( fp ) == 0 )
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
    if ( !porownajNapisy( linia, "." ) )
    {
        fclose( fp );
        return 0;
    }
    if ( !fscanf( fp, "%s", linia ) || !porownajNapisy( linia, "*PRACOWNICY*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, "." ) && feof( fp ) == 0 )
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
    if ( !porownajNapisy( linia, "." ) )
    {
        fclose( fp );
        return 0;
    }
    if ( !fscanf( fp, "%s", linia ) || !porownajNapisy( linia, "*PRZEDMIOTY*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, "." ) && feof( fp ) == 0 )
    {
    }
    if ( !fscanf( fp, "%s ", linia ) || !porownajNapisy( linia, "*STUDENT-PRZEDMIOT*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%d", &numer ) && feof( fp ) == 0 )
    {
        if ( !fscanf( fp, "%s", linia ) )
        {
            fclose( fp );
            return 0;
        }
    }
    if ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, ".") )
    {
        fclose( fp );
        return 0;
    }
    if ( !fscanf( fp, "%s", linia ) || !porownajNapisy( linia, "*PRACOWNIK-PRZEDMIOT*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%d", &numer ) && feof( fp ) == 0 )
    {
        if ( !fscanf( fp, "%s", linia ) )
        {
            fclose( fp );
            return 0;
        }
    }
    if ( fscanf( fp, "%s", linia ) && !porownajNapisy( linia, "." ) )
    {
        fclose( fp );
        return 0;
    }
    fclose( fp );
    return 1;
}
