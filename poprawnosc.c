#include "poprawnosc.h"

int czyPlikPoprawny ( char nazwaPliku[ MAX ] )
{
    FILE *fp = NULL;
    char linia[MAX];
    int numer;
    fp = fopen( nazwaPliku, "r");
    if ( !fscanf( fp, "%124s", linia ) || !porownajNapisy( linia, "*STUDENCI*")  )
    {
        if ( !fscanf( fp, "%124s", linia ) || !porownajNapisy( linia, "*STUDENCI*")  )
        {
            fclose( fp );
            return 0;
        }
    }
    while ( fscanf( fp, "%124s", linia ) && !porownajNapisy( linia, "." ) && feof( fp ) == 0 )
    {
        if ( !fscanf( fp, "%124s", linia ) )
        {
            fclose( fp );
            return 0;
        }
        if ( !fscanf( fp, "%d", &numer ) && numer < 0 )
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
    if ( !fscanf( fp, "%124s", linia ) || !porownajNapisy( linia, "*PRACOWNICY*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%124s", linia ) && !porownajNapisy( linia, "." ) && feof( fp ) == 0 )
    {
        if ( !fscanf( fp, "%124s", linia ) )
        {
            fclose( fp );
            return 0;
        }
        if ( !fscanf( fp, "%d", &numer ) && numer < 0 )
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
    if ( !fscanf( fp, "%124s", linia ) || !porownajNapisy( linia, "*PRZEDMIOTY*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%124s", linia ) && !porownajNapisy( linia, "." ) && feof( fp ) == 0 )
    {
    }
    if ( !fscanf( fp, "%124s ", linia ) || !porownajNapisy( linia, "*STUDENT-PRZEDMIOT*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%d", &numer ) && feof( fp ) == 0 && numer < 0 )
    {
        if ( !fscanf( fp, "%124s", linia ) )
        {
            fclose( fp );
            return 0;
        }
    }
    if ( fscanf( fp, "%124s", linia ) && !porownajNapisy( linia, ".") )
    {
        fclose( fp );
        return 0;
    }
    if ( !fscanf( fp, "%124s", linia ) || !porownajNapisy( linia, "*PRACOWNIK-PRZEDMIOT*") )
    {
        fclose( fp );
        return 0;
    }
    while ( fscanf( fp, "%d", &numer ) && feof( fp ) == 0 && numer < 0)
    {
        if ( !fscanf( fp, "%124s", linia ) )
        {
            fclose( fp );
            return 0;
        }
    }
    if ( fscanf( fp, "%124s", linia ) && !porownajNapisy( linia, "." ) )
    {
        fclose( fp );
        return 0;
    }
    fclose( fp );
    return 1;
}
