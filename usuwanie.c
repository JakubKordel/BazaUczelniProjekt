#include "usuwanie.h"
#include <stdlib.h>

void usuwaniePierwszegoStudenta( Glowy* glowy )
{
    Osoba* glowaStudent = glowy ->student;
    OsobaPrzedmiot* glowaStudentPrzedmiot = glowy ->studentPrzedmiot;
    if ( glowaStudent )
    {
        while ( glowaStudentPrzedmiot )
        {
            if ( glowaStudentPrzedmiot ->osoba == glowaStudent )
                glowy ->studentPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->studentPrzedmiot, glowaStudentPrzedmiot );
            glowaStudentPrzedmiot = glowaStudentPrzedmiot ->nast;
        }
        glowy ->student = glowaStudent ->nast;
        free( glowaStudent );
    }
}

void usuwanieStudenta( Glowy* glowy, Osoba* usuwany )
{
    OsobaPrzedmiot* glowaStudentPrzedmiot = glowy ->studentPrzedmiot;
    if ( glowy ->student == usuwany )
        usuwaniePierwszegoStudenta( glowy );
    else
    {
        poprzednikOsoby( glowy ->student, usuwany ) ->nast = usuwany ->nast;
        while ( glowaStudentPrzedmiot )
        {
            if ( glowaStudentPrzedmiot ->osoba == usuwany )
                glowy ->studentPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->studentPrzedmiot, glowaStudentPrzedmiot );
            glowaStudentPrzedmiot = glowaStudentPrzedmiot ->nast;
        }
        free( usuwany );
    }
}

void usuwaniePierwszegoPracownika( Glowy* glowy )
{
    Osoba* glowaPracownik = glowy ->pracownik;
    OsobaPrzedmiot* glowaPracownikPrzedmiot = glowy ->pracownikPrzedmiot;
    if ( glowaPracownik )
    {
        while ( glowaPracownikPrzedmiot )
        {
            if ( glowaPracownikPrzedmiot ->osoba == glowaPracownik )
                glowy ->pracownikPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->pracownikPrzedmiot, glowaPracownikPrzedmiot );
            glowaPracownikPrzedmiot = glowaPracownikPrzedmiot ->nast;
        }
        glowy ->pracownik = glowaPracownik ->nast;
        free( glowaPracownik );
    }
}

void usuwaniePracownika( Glowy* glowy, Osoba* usuwany )
{
    OsobaPrzedmiot* glowaPracownikPrzedmiot = glowy ->pracownikPrzedmiot;
    if ( glowy ->pracownik == usuwany )
        usuwaniePierwszegoPracownika( glowy );
    else
    {
        poprzednikOsoby( glowy ->pracownik, usuwany ) ->nast = usuwany ->nast;
        while ( glowaPracownikPrzedmiot )
        {
            if ( glowaPracownikPrzedmiot ->osoba == usuwany )
                glowy ->pracownikPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->pracownikPrzedmiot, glowaPracownikPrzedmiot );
            glowaPracownikPrzedmiot = glowaPracownikPrzedmiot ->nast;
        }
        free( usuwany );
    }
}

void usuwaniePierwszegoPrzedmiotu( Glowy* glowy )
{
    Przedmiot* glowaPrzedmiot = glowy ->przedmiot;
    OsobaPrzedmiot* glowaStudentPrzedmiot = glowy ->studentPrzedmiot;
    OsobaPrzedmiot* glowaPracownikPrzedmiot = glowy ->pracownikPrzedmiot;
    if ( glowaPrzedmiot )
    {
        while ( glowaStudentPrzedmiot )
        {
            if ( glowaStudentPrzedmiot ->przedmiot == glowaPrzedmiot )
                glowy ->studentPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->studentPrzedmiot, glowaStudentPrzedmiot );
            glowaStudentPrzedmiot = glowaStudentPrzedmiot ->nast;
        }
        while ( glowaPracownikPrzedmiot )
        {
            if ( glowaPracownikPrzedmiot ->przedmiot == glowaPrzedmiot )
            {
                glowy ->pracownikPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->pracownikPrzedmiot, glowaPracownikPrzedmiot );
                break;
            }
            glowaPracownikPrzedmiot = glowaPracownikPrzedmiot ->nast;
        }
        glowy ->przedmiot = glowaPrzedmiot ->nast;
        free( glowaPrzedmiot );
    }
}

void usuwaniePrzedmiotu( Glowy* glowy, Przedmiot* usuwany )
{
    OsobaPrzedmiot* glowaStudentPrzedmiot = glowy ->studentPrzedmiot;
    OsobaPrzedmiot* glowaPracownikPrzedmiot = glowy ->pracownikPrzedmiot;
    if ( glowy ->przedmiot == usuwany )
        usuwaniePierwszegoPrzedmiotu( glowy );
    else
    {
        poprzednikPrzedmiotu( glowy ->przedmiot, usuwany ) ->nast = usuwany ->nast;
        while ( glowaStudentPrzedmiot )
        {
            if ( glowaStudentPrzedmiot ->przedmiot == usuwany )
                glowy ->studentPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->studentPrzedmiot, glowaStudentPrzedmiot );
            glowaStudentPrzedmiot = glowaStudentPrzedmiot ->nast;
        }
        while ( glowaPracownikPrzedmiot )
        {
            if ( glowaPracownikPrzedmiot ->przedmiot == usuwany )
            {
                glowy ->pracownikPrzedmiot = usuwanieOsobaPrzedmiot( glowy ->pracownikPrzedmiot, glowaPracownikPrzedmiot );
                break;
            }
            glowaPracownikPrzedmiot = glowaPracownikPrzedmiot ->nast;
        }
        free( usuwany );
    }
}

OsobaPrzedmiot* usuwaniePierwszejOsobaPrzedmiot( OsobaPrzedmiot* glowa )
{
    if ( glowa )
    {
        OsobaPrzedmiot* pierwszy = glowa;
        glowa = glowa -> nast;
        free( pierwszy );
    }
    return glowa;
}

OsobaPrzedmiot* usuwanieOsobaPrzedmiot( OsobaPrzedmiot* glowa, OsobaPrzedmiot* usuwany )
{
    if ( glowa == usuwany )
        glowa = usuwaniePierwszejOsobaPrzedmiot( glowa );
    else
    {
        if ( usuwany )
        {
            poprzednikOsobaPrzedmiot( glowa, usuwany ) ->nast = usuwany ->nast;
            free( usuwany );
        }
    }
    return glowa;
}
