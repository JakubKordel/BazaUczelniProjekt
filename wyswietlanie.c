#include "wyswietlanie.h"

void wyswietlListeStudentow( Glowy* glowy )
{
    glowy ->student = posortujWedlugNazwiska( glowy ->student );
    Osoba* x;
    char wybor;
    while ( wybor != 'e' )
    {
        wyczyscEkran();
        rysujPrzerwe();
        printf("LISTA STUDENTOW \n");
        rysujPrzerwe();
        printf(" Numer indeksu\t\tImie i Nazwisko\n");
        x = glowy ->student;
        while( x )
        {
            printf( "  %6d\t\t%s %s\n", x ->id, x ->imie, x ->nazwisko );
            x = x ->nast;
        }
        rysujPrzerwe();
        printf("\nD - dodaj studenta\n");
        printf("\nU - usun studenta\n");
        printf("\nW - Wypis o studencie\n");
        printf("\nN - posortuj wedlug nazwiska\n");
        printf("I - posortuj wedlug imienia\n");
        printf("i - posortuj wedlug numeru indeksu\n");
        printf("e - aby wrocic\n");
        scanf("%c", &wybor);
        wyczyscBuf();
        switch ( wybor )
        {
        case 'N':
            glowy ->student = posortujWedlugNazwiska( glowy ->student );
            break;
        case 'I':
            glowy ->student = posortujWedlugImienia( glowy ->student );
            break;
        case 'i':
            break;
        case 'D':
            glowy ->student = wczytajOsobe( glowy ->student );
            break;
        case 'U':
            wczytajUsuwanegoStudenta( glowy );
            break;
        case 'W':
            wczytajStudentaDoWypisania( glowy );
            break;
        case 'e':
            break;
        default:
            printf("Nieprawidlowy znak\n");
            usleep(1000);
            break;
        }
    }
}

void wyswietlListePracownikow( Glowy* glowy )
{
    glowy ->pracownik = posortujWedlugNazwiska( glowy ->pracownik );
    Osoba* x;
    char wybor;
    while ( wybor != 'e' )
    {
        wyczyscEkran();
        rysujPrzerwe();
        printf("LISTA PRACOWNIKOW \n");
        rysujPrzerwe();
        printf("Imie i Nazwisko\n");
        x = glowy ->pracownik;
        while( x )
        {
            printf( "%s %s\n", x ->imie, x ->nazwisko );
            x = x ->nast;
        }
        rysujPrzerwe();
        printf("\nD - dodaj pracownika\n");
        printf("\nU - usun pracownika\n");
        printf("\nW - Wypis o pracowniku\n");
        printf("\nN - posortuj wedlug nazwiska\n");
        printf("I - posortuj wedlug imienia\n");
        printf("e - aby wrocic\n");
        scanf("%c", &wybor);
        wyczyscBuf();
        switch ( wybor )
        {
        case 'D':
            glowy ->pracownik = wczytajOsobe( glowy ->pracownik );
            break;
        case 'U':
            wczytajUsuwanegoPracownika( glowy );
            break;
        case 'N':
            glowy ->pracownik = posortujWedlugNazwiska( glowy ->pracownik );
            break;
        case 'I':
            glowy ->pracownik = posortujWedlugImienia( glowy ->pracownik);
            break;
        case 'W':
            wczytajPracownikaDoWypisania( glowy );
            break;
        case 'e':
            break;
        default:
            printf("Nieprawidlowy znak\n");
            usleep(1000);
            break;
        }
    }
}

void wyswietlListePrzedmiotow( Glowy* glowy )
{
    Przedmiot* x;
    char wybor;
    while ( wybor != 'e' )
    {
        glowy ->przedmiot = posortujWedlugNazwy( glowy ->przedmiot );
        wyczyscEkran();
        rysujPrzerwe();
        printf("LISTA PRZEDMIOTOW \n");
        rysujPrzerwe();
        printf("NAZWA\n");
        x = glowy ->przedmiot;
        while( x )
        {
            printf( "%s\n", x ->nazwa );
            x = x ->nast;
        }
        rysujPrzerwe();
        printf("\nD - dodaj przedmiot\n");
        printf("\nU - usun przedmiot\n");
        printf("\nW - Wypis o przedmiocie\n");
        printf("\ne - aby wrocic\n");
        scanf("%c", &wybor);
        wyczyscBuf();
        switch ( wybor )
        {
        case 'D':
            glowy ->przedmiot = wczytajPrzedmiot( glowy ->przedmiot );
            break;
        case 'U':
            wczytajUsuwanyPrzedmiot( glowy );
            break;
        case 'W':
            wczytajPrzedmiotDoWypisania( glowy );
            break;
        case 'e':
            break;
        default:
            printf("Nieprawidlowy znak\n");
            usleep(1000);
            break;
        }
    }
}


void wypisStudent( Osoba* student, Glowy* glowy )
{
    char wybor;
    while ( wybor != 'e' && wybor != 'U' )
    {
        wyczyscEkran();
        printf( "IMIE:          %s\n", student ->imie );
        printf( "NAZWISKO:      %s\n", student ->nazwisko );
        printf( "NUMER INDEKSU: %d\n", student ->id );
        printf( "PRZEDMIOTY UCZNIA:\n" );
        OsobaPrzedmiot* x = glowy ->studentPrzedmiot;
        while ( x )
        {
            if ( x ->osoba == student )
                printf( "%s \n", x ->przedmiot ->nazwa );
            x = x ->nast;
        }
        rysujPrzerwe();
        printf("\nP - podepnij studenta na przedmiot\n");
        printf("\nU - usun studenta\n");
        printf("e - aby wrocic\n");
        scanf("%c", &wybor);
        wyczyscBuf();
        switch ( wybor )
        {
        case 'P':
            dajStudentowiPrzedmiot( glowy, student );
            break;
        case 'U':
            usuwanieStudenta( glowy, student );
            break;
        case 'e':
            break;
        default:
            printf("Nieprawidlowy znak\n");
            usleep(1000);
            break;
        }
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

void wypisPrzedmiot( Przedmiot* przedmiot, Glowy* glowy )
{
    char wybor;
    while ( wybor != 'e' && wybor != 'U' )
    {
        printf("NAZWA PRZEDMIOTU: %s\n", przedmiot ->nazwa );
        printf( "PROWADZACY: " );
        OsobaPrzedmiot* x = glowy ->pracownikPrzedmiot;
        while ( x )
        {
            if ( x ->przedmiot == przedmiot )
            {
                printf( "%s %s ", x ->osoba ->imie, x ->osoba ->nazwisko );
                break;
            }
            x = x->nast;
        }
        printf("\nLISTA STUDENTOW ZAPISAYCH NA PRZEDMIOT\n");
        wyswietlListeStudentowZapisanychNaPrzedmiot( przedmiot, glowy ->studentPrzedmiot );
        rysujPrzerwe();
        printf("\nP - podepnij na przedmiot studenta\n");
        printf("\nD - Daj prowadzacego\n");
        printf("\nU - usun przedmiot\n");
        printf("e - aby wrocic\n");
        scanf("%c", &wybor);
        wyczyscBuf();
        switch ( wybor )
        {
        case 'P':
            dajPrzedmiotowiStudenta( glowy, przedmiot );
            break;
        case 'U':
            usuwaniePrzedmiotu( glowy, przedmiot );
            break;
        case 'D':
            dajPrzedmiotowiProwadzacego( glowy, przedmiot );
            break;
        case 'e':
            break;
        default:
            printf("Nieprawidlowy znak\n");
            usleep(1000);
            break;
        }
        wyczyscEkran();
    }
}

void wypisPracownik( Glowy* glowy, Osoba* pracownik )
{
    char wybor;
    while ( wybor != 'e' && wybor != 'U' )
    {
        printf( "IMIE:          %s\n", pracownik ->imie );
        printf( "NAZWISKO:      %s\n", pracownik ->nazwisko );
        printf( "PRZEDMIOTY PROWADZONE PRZEZ PRACOWNIKA:\n" );
        OsobaPrzedmiot* x = glowy ->pracownikPrzedmiot;
        while ( x )
        {
            if ( x ->osoba == pracownik )
            {
                printf("NAZWA PRZEDMIOTU: %s\n", x ->przedmiot ->nazwa );
                wyswietlListeStudentowZapisanychNaPrzedmiot( x ->przedmiot, glowy ->studentPrzedmiot );
            }
            x = x ->nast;
        }
        rysujPrzerwe();
        printf("\nD - daj pracownikowi przedmiot\n");
        printf("\nU - usun pracownika\n");
        printf("e - aby wrocic\n");
        scanf("%c", &wybor);
        wyczyscBuf();
        switch ( wybor )
        {
        case 'D':
            dajPracownikowiPrzedmiot( glowy, pracownik );
            break;
        case 'U':
            usuwaniePracownika( glowy, pracownik );
            break;
        case 'e':
            break;
        default:
            printf("Nieprawidlowy znak\n");
            usleep(1000);
            break;
        }
        wyczyscEkran();
    }

}
