#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "menu.h"
#include "utime.h"
#include "podst.h"

int main()
{
    Osoba* glowaStudent = NULL;
    printf("WITAJ W BAZIE UCZELNI!\n");
    rysujPrzerwe();
    char wybor;
    while ( wybor != 'e' )
    {
        wyswietlMenu();
        scanf("%c", &wybor);
        wyczyscBuf();
        switch( wybor ){
            case '1':
             glowaStudent = wczytajOsobe( glowaStudent );
             break;
            case '2':
             wyswietlListeOsob( glowaStudent );
             getchar();
             break;
            case '3':
             break;
            default:
             printf("Nieprawidlowy znak\n");
             usleep(1000);
             break;
        }
        wyczyscEkran();
    }
    zwolnij( glowaStudent );

    return 0;
}
