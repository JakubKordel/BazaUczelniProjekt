#include "wyswietlanie.h"

void wyswietlListeOsob( Osoba* glowaOsoba )
{
    while( glowaOsoba )
    {
        printf( "%d %s %s\n", glowaOsoba ->id, glowaOsoba ->imie, glowaOsoba ->nazwisko );
        glowaOsoba = glowaOsoba ->nast;
    }
}

void wyswietlListePrzedmiotow( Przedmiot* glowaPrzedmiot )
{
    while( glowaPrzedmiot )
    {
        printf( "%s \n", glowaPrzedmiot->nazwa );
        glowaPrzedmiot = glowaPrzedmiot->nast;
    }
}

void wypisStudent( Osoba* student, OsobaPrzedmiot* glowa )
{
    printf( "IMIE:          %s\n", student ->imie );
    printf( "NAZWISKO:      %s\n", student ->nazwisko );
    printf( "NUMER INDEKSU: %d\n", student ->id );
    printf( "PRZEDMIOTY UCZNIA:\n" );
    while ( glowa )
    {
        if ( glowa ->osoba == student )
            printf( "%s \n", glowa ->przedmiot ->nazwa );
        glowa = glowa ->nast;
    }
}

void wyswietlListeStudentowZapisanychNaPrzedmiot( Przedmiot* przedmiot, OsobaPrzedmiot* glowa )
{
    while ( glowa )
    {
        if ( glowa ->przedmiot == przedmiot )
            printf( "%s %s\n", glowa ->osoba ->imie, glowa ->osoba ->nazwisko );
        glowa = glowa ->nast;
    }
}

void wypisPrzedmiot( Przedmiot* przedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot, OsobaPrzedmiot* glowaPracownikPrzedmiot )
{
    printf("NAZWA PRZEDMIOTU: %s\n", przedmiot ->nazwa );
    printf( "PROWADZACY: " );
    while ( glowaPracownikPrzedmiot )
    {
        if ( glowaPracownikPrzedmiot ->przedmiot == przedmiot )
        {
            printf( "%s %s ", glowaPracownikPrzedmiot ->osoba ->imie, glowaPracownikPrzedmiot ->osoba ->nazwisko );
            break;
        }
        glowaPracownikPrzedmiot = glowaPracownikPrzedmiot ->nast;
    }
    printf("\nLISTA STUDENTOW ZAPISAYCH NA PRZEDMIOT\n");
    wyswietlListeStudentowZapisanychNaPrzedmiot( przedmiot, glowaStudentPrzedmiot );
}

void wypisPracownik( Osoba* pracownik, OsobaPrzedmiot* glowaPracownikPrzedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot )
{
    printf( "IMIE:          %s\n", pracownik ->imie );
    printf( "NAZWISKO:      %s\n", pracownik ->nazwisko );
    printf( "PRZEDMIOTY PROWADZONE PRZEZ PRACOWNIKA:\n" );
    while ( glowaPracownikPrzedmiot )
    {
        if ( glowaPracownikPrzedmiot ->osoba == pracownik )
        {
            printf("NAZWA PRZEDMIOTU: %s\n", glowaPracownikPrzedmiot ->przedmiot ->nazwa );
            wyswietlListeStudentowZapisanychNaPrzedmiot( glowaPracownikPrzedmiot ->przedmiot, glowaStudentPrzedmiot );
        }
        glowaPracownikPrzedmiot = glowaPracownikPrzedmiot ->nast;
    }
}
