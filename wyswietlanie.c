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
        printf("\nW - Wypis i zarzadzanie studentem\n");
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
            glowy ->student = posortujWedlugIndeksu( glowy ->student );
            break;
        case 'D':
            glowy ->student = wczytajOsobe( glowy ->student );
            break;
        case 'U':
            wczytajUsuwanaOsobe( glowy, 1 );
            break;
        case 'W':
            wczytajOsobeDoWypisania( glowy, 1 );
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
        printf("\nW - Wypis i zarzadzanie pracownikiem\n");
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
            wczytajUsuwanaOsobe( glowy, 2 );
            break;
        case 'N':
            glowy ->pracownik = posortujWedlugNazwiska( glowy ->pracownik );
            break;
        case 'I':
            glowy ->pracownik = posortujWedlugImienia( glowy ->pracownik);
            break;
        case 'W':
            wczytajOsobeDoWypisania( glowy, 2 );
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
        printf( "LISTA PRZEDMIOTOW \n" );
        rysujPrzerwe();
        printf("NAZWA\n");
        x = glowy ->przedmiot;
        while( x )
        {
            printf( "%s\n", x ->nazwa );
            x = x ->nast;
        }
        rysujPrzerwe();
        printf( " " );
        printf( "\nD - dodaj przedmiot\n" );
        printf( "\nU - usun przedmiot\n" );
        printf( "\nW - Wypis i zarzadzanie przedmiotem\n" );
        printf( "\ne - aby wrocic\n");
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
            podepnijOsobeNaPrzedmiot( glowy, student, NULL, 1 );
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
        printf("\nu - Wykresl ucznia z przedmiotu\n");
        printf("\nr - Usun prowadzacego przedmiotu\n");
        printf("\nU - usun przedmiot\n");
        printf("e - aby wrocic\n");
        scanf("%c", &wybor);
        wyczyscBuf();
        switch ( wybor )
        {
        case 'P':
            podepnijOsobeNaPrzedmiot( glowy, NULL, przedmiot, 1 );
            break;
        case 'U':
            usuwaniePrzedmiotu( glowy, przedmiot );
            break;
        case 'D':
            podepnijOsobeNaPrzedmiot( glowy, NULL, przedmiot, 2 );
            break;
        case 'u':
            usunZprzedmiotuStudenta( glowy, przedmiot );
            break;
        case 'r':
            usunZprzedmiotuProwadzacego( glowy, przedmiot );
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
            podepnijOsobeNaPrzedmiot( glowy, pracownik, NULL, 2 );
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

void menuWczytywania ( Glowy* glowy )
{
    wyczyscEkran();
    printf( "Pliki z bazami:\n");
    zwolnijNazwaPliku( glowy ->nazwaPliku );
    glowy ->nazwaPliku = NULL;
    wczytajNazwyPlikow( glowy );
    glowy ->nazwaPliku = posortujWedlugCzasu( glowy ->nazwaPliku );
    NazwaPliku* pliki = glowy ->nazwaPliku;
    int numer;
    int i = 1;
    time_t czasZapisu;
    while ( pliki )
    {
        printf( "%d. %s\t", i, pliki ->nazwa );
        if ( pliki ->czas != 0 )
        {
            czasZapisu = ( time_t )pliki ->czas;
            printf( ctime( &czasZapisu ) );
        }
        else
            printf( "\n");
        pliki = pliki ->nast;
        ++i;
    }
    printf( "\nPodaj numer pliku z baza, ktora chcesz wczytac\n" );
    printf( "Inny klawisz aby wrocic\n" );
    if ( scanf( "%d", &numer ) )
    {
        wyczyscBuf();
        i = 1;
        pliki = glowy ->nazwaPliku;
        while ( pliki && i < numer+1 )
        {
            if ( numer == i )
            {
                if ( czyPlikPoprawny( pliki ->nazwa ) )
                    wczytajBaze( glowy, pliki ->nazwa );
                else
                {
                    printf("Plik uszkodzony!");
                    getchar();
                }
            }
            pliki = pliki ->nast;
            ++i;
        }
    }
    wyczyscBuf();
}

void menuZapisywania( Glowy* glowy )
{
    wyczyscEkran();
    zwolnijNazwaPliku( glowy ->nazwaPliku );
    glowy ->nazwaPliku = NULL;
    wczytajNazwyPlikow( glowy );
    glowy ->nazwaPliku = posortujWedlugCzasu( glowy ->nazwaPliku );
    NazwaPliku* pliki = glowy ->nazwaPliku;
    char nazwa[ MAX ];
    time_t czasZapisu;
    while ( pliki )
    {
        printf( "%s\t", pliki ->nazwa );
        if ( pliki ->czas != 0 )
        {
            czasZapisu = ( time_t )pliki ->czas;
            printf( ctime( &czasZapisu ) );
        }
        else
            printf( "\n");
        pliki = pliki ->nast;
    }
    printf( "\nPodaj nazwe zapisu(bez rozszerzenia), mozesz wybrac jeden z powyzszych lub nowy:\n\n" );
    scanf( "%s", nazwa );
    wyczyscBuf();
    if ( strlen( nazwa ) < MAX - 5 )
    {
        strcat( nazwa, ".ucb");
        zapiszBaze( glowy, nazwa );
    }
}

