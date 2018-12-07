#include "podst.h"

void wyczyscBuf(){
    char c;
    do
     c = getchar();
    while (  c != '\n' && c != EOF );
}

void wyczyscEkran( ) {
    system( "clear" );
}

void rysujPrzerwe()
{
    printf( "-------------------------------------------------\n" );
}

char* wczytajNapis( char napis[ MAX ] )
{
    scanf( "%s", napis );
    wyczyscBuf();
    return napis;
}
