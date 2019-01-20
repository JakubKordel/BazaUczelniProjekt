#include "podst.h"

void wyczyscBuf()
{
    char c;
    do
        c = getchar();
    while (  c != '\n' && c != EOF );
}

void wyczyscEkran( )
{
    system( "clear" );
}

void rysujPrzerwe()
{
    printf( "-------------------------------------------------\n" );
}

char* wczytajNapis( char napis[ MAX ] )
{
    do
    {
        scanf( "%s", napis );
    }
    while ( strlen ( napis ) > MAX - 2 );
    wyczyscBuf();
    return napis;
}

int porownajNapisy( char pierwszy[ MAX ], char drugi[ MAX ] )
{
    int dlugoscPierwszy = strlen( pierwszy );
    int dlugoscDrugi = strlen( drugi );
    if ( dlugoscPierwszy == dlugoscDrugi )
    {
        for ( int i = 0; i < dlugoscPierwszy; ++i )
        {
            if ( pierwszy[i] != drugi[i] )
                return 0;
        }
        return 1;
    }
    return 0;
}

int czyNapisyKolejneAlfabetycznie( char pierwszy[ MAX ], char drugi[ MAX ] )
{
    int i = 0;
    while ( i < MAX )
    {
        if ( pierwszy[i] < drugi[i] )
            return 1;
        if ( pierwszy[i] > drugi[i] )
            return 0;
        ++i;
    }
    return 2;
}

int czyPrawidloweRozszerzenie( char nazwa[ MAX ] )
{
    if ( strstr( nazwa, ".ucb" ) )
        return 1;
    return 0;
}
