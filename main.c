#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "menu.h"
#include "unistd.h"
#include "struktury.h"
#include "wyswietlanie.h"
#include "uzytkownik.h"

int main()
{
    Osoba* glowaStudent = NULL;
    Osoba* glowaPracownik = NULL;
    Przedmiot* glowaPrzedmiot = NULL;
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
             glowaPracownik = wczytajOsobe( glowaPracownik );
             break;
            case '3':
             glowaPrzedmiot = wczytajPrzedmiot( glowaPrzedmiot );
            break;
            case '4':
             wyswietlListeOsob( glowaStudent );
             getchar();
             break;
            case '5':
             wyswietlListeOsob( glowaPracownik );
             getchar();
             break;
            case '6':
             wyswietlListePrzedmiotow( glowaPrzedmiot );
             getchar();
             break;
            case '7':
             glowaStudent = wczytajUsuwanaOsobe( glowaStudent );
             break;
            case '8':
             break;
            default:
             printf("Nieprawidlowy znak\n");
             usleep(1000);
             break;
        }
        wyczyscEkran();
    }
    zwolnijOsoba( glowaStudent );
    zwolnijOsoba( glowaPracownik );
    zwolnijPrzedmiot( glowaPrzedmiot );
    return 0;
}
