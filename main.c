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
    glowy ->pracownikPrzedmiot = NULL;
    glowy ->studentPrzedmiot = NULL;
    printf("WITAJ W BAZIE UCZELNI!\n");
    rysujPrzerwe();
    char wybor;
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
        case 'e':
            break;
        case 'z':
            zapiszBaze( glowy, "baza.txt" );
            break;
        case 'w':
            wczytajBaze( glowy, "baza.txt" );
            break;
        default:
            printf("Nieprawidlowy znak\n");
            usleep(1000);
            break;
        }
        wyczyscEkran();
    }
    zwolnijOsoba( glowy ->student );
    zwolnijOsoba( glowy ->pracownik );
    zwolnijPrzedmiot( glowy ->przedmiot );
    zwolnijOsobaPrzedmiot( glowy ->studentPrzedmiot );
    zwolnijOsobaPrzedmiot( glowy ->pracownikPrzedmiot );
    free( glowy );
    return 0;
}
