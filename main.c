#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "menu.h"
#include "unistd.h"
#include "struktury.h"
#include "wyswietlanie.h"
#include "uzytkownik.h"
#include "sortowanie.h"
#include "zapis.h"

int main()
{
    Glowy* glowy = malloc( sizeof( Glowy ) );
    glowy ->pracownik = NULL;
    glowy ->student = NULL;
    glowy ->przedmiot = NULL;
    glowy ->pracownikPrzedmiot = NULL;
    glowy ->studentPrzedmiot = NULL;
    glowy ->nazwaPliku = NULL;
    printf("WITAJ W BAZIE UCZELNI!\n");
    rysujPrzerwe();
    char wybor = 1;
    while ( wybor != 'e' )
    {
        wyswietlMenu();
        scanf("%c", &wybor);
        wyczyscBuf();
        switch( wybor )
        {
        case 'S':
            wyswietlListeStudentow( glowy );
            break;
        case 'P':
            wyswietlListePracownikow( glowy );
            break;
        case 'R':
            wyswietlListePrzedmiotow( glowy );
            break;
        case 'W':
            menuWczytywania( glowy );
            break;
        case 'Z':
            menuZapisywania( glowy );
            break;
        case 'U':
            menuUsuwania( glowy );
            break;
        case 'e':
            break;
        case 'C':
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
            break;
        default:
            printf("Nieprawidlowy znak\n");
            usleep(1000);
            break;
        }
        wyczyscEkran();
    }
    zapiszBaze( glowy, "zapasowy.ucb");
    zwolnijOsoba( glowy ->student );
    zwolnijOsoba( glowy ->pracownik );
    zwolnijPrzedmiot( glowy ->przedmiot );
    zwolnijOsobaPrzedmiot( glowy ->studentPrzedmiot );
    zwolnijOsobaPrzedmiot( glowy ->pracownikPrzedmiot );
    zwolnijNazwaPliku( glowy ->nazwaPliku );
    free( glowy );
    return 0;
}
