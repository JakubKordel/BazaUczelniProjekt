#ifndef usuwanie.h
#define usuwanie.h

#include "funkcje.h"
#include "przeszukiwanie.h"

Osoba* usuwaniePierwszejOsoby( Osoba* glowa );
Osoba* usuwanieOsoby( Osoba* glowa, char imie[ MAX ], char nazwisko[ MAX ] );
Przedmiot* usuwaniePierwszegoPrzedmiotu( Przedmiot* glowa );
Przedmiot* usuwaniePrzedmiotu( Przedmiot* glowa, char nazwa[ MAX ] );

#endif
