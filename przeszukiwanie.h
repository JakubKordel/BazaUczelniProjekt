#pragma once

#include <stdio.h>
#include "struktury.h"

Osoba* wyszukajOsobe( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] );
Osoba* poprzednikOsoby( Osoba* glowa, char im[ MAX ], char nazw[ MAX ] );
Przedmiot* wyszukajPrzedmiot( Przedmiot* glowa, char nazw[ MAX ] );
Przedmiot* poprzednikPrzedmiotu( Przedmiot* glowa, char nazw[ MAX ] );


