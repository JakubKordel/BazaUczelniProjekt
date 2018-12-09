#pragma once

#include <stdio.h>
#include "struktury.h"

Osoba* wyszukajOsobe( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] );
Osoba* poprzednikOsoby( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] );
unsigned int policzOsoby( Osoba* glowa );
Przedmiot* wyszukajPrzedmiot( Przedmiot* glowa, char nazw[ MAX ] );
Przedmiot* poprzednikPrzedmiotu( Przedmiot* glowa, char nazw[ MAX ] );
unsigned int policzPrzedmioty ( Przedmiot* glowa );
OsobaPrzedmiot* wyszukajOsobaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* os, Przedmiot* przedm );
OsobaPrzedmiot* poprzednikOsobaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* os, Przedmiot* przedm );
int znajdzMaxId( Osoba* glowa );


