#pragma once

#include <stdio.h>
#include "struktury.h"

Osoba* wyszukajOsobe( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] );
Osoba* wyszukajOsobeWedlugId( Osoba* glowa, int parametrId );
Osoba* poprzednikOsoby( Osoba* glowa, Osoba* osoba  );
unsigned int policzOsoby( Osoba* glowa );
Przedmiot* wyszukajPrzedmiot( Przedmiot* glowa, char nazw[ MAX ] );
Przedmiot* poprzednikPrzedmiotu( Przedmiot* glowa, Przedmiot* przedmiot );
unsigned int policzPrzedmioty ( Przedmiot* glowa );
OsobaPrzedmiot* wyszukajOsobaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* os, Przedmiot* przedm );
OsobaPrzedmiot* poprzednikOsobaPrzedmiot( OsobaPrzedmiot* glowa, OsobaPrzedmiot* osobaPrzedmiot );
int znajdzMaxId( Osoba* glowa );


