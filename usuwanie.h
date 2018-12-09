#pragma once

#include "funkcje.h"
#include "przeszukiwanie.h"

Osoba* usuwaniePierwszejOsoby( Osoba* glowa );
Osoba* usuwanieOsoby( Osoba* glowa, char imie[ MAX ], char nazwisko[ MAX ] );
Przedmiot* usuwaniePierwszegoPrzedmiotu( Przedmiot* glowa );
Przedmiot* usuwaniePrzedmiotu( Przedmiot* glowa, char nazwa[ MAX ] );
OsobaPrzedmiot* usuwaniePierwszejOsobaPrzedmiot( OsobaPrzedmiot* glowa );
OsobaPrzedmiot* usuwanieOsobaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* os, Przedmiot* przedm );


