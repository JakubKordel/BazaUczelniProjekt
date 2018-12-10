#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#include "menu.h"
#include "unistd.h"
#include "struktury.h"
#include "wyswietlanie.h"
#include "uzytkownik.h"
#include "sortowanie.h"

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
        switch( wybor ){
            case '1':
             glowy ->student = wczytajOsobe( glowy ->student );
             break;
            case '2':
             glowy ->pracownik = wczytajOsobe( glowy ->pracownik );
             break;
            case '3':
             glowy ->przedmiot = wczytajPrzedmiot( glowy ->przedmiot );
            break;
            case '4':
             wyswietlListeOsob( glowy ->student );
             getchar();
             break;
            case '5':
             wyswietlListeOsob( glowy ->pracownik );
             getchar();
             break;
            case '6':
             wyswietlListePrzedmiotow( glowy ->przedmiot );
             getchar();
             break;
            case '7':
             wczytajUsuwanegoStudenta( glowy );
             break;
            case '8':
             glowy ->student = posortujWedlugNazwiska( glowy ->student );
             break;
            case '9':
             glowy ->studentPrzedmiot = podepnijStudentaNaPrzedmiot( glowy ->studentPrzedmiot, glowy ->student, glowy ->przedmiot );
             break;
            case 'a':
             wczytajStudentaDoWypisania( glowy ->student, glowy ->studentPrzedmiot );
             break;
            case 'b':
             glowy ->pracownikPrzedmiot = dajPracownikowiPrzedmiot( glowy ->pracownikPrzedmiot, glowy ->pracownik, glowy ->przedmiot );
             break;
            case 'c':
             wczytajPracownikaDoWypisania( glowy ->pracownik, glowy ->pracownikPrzedmiot, glowy ->studentPrzedmiot );
             break;
            case 'd':
             wczytajPrzedmiotDoWypisania( glowy ->przedmiot, glowy ->studentPrzedmiot, glowy ->pracownikPrzedmiot );
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
    return 0;
}
