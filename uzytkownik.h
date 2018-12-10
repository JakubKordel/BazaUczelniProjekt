#pragma once

#include <stdio.h>
#include <string.h>
#include "struktury.h"
#include "usuwanie.h"
#include "wyswietlanie.h"

Osoba* wczytajOsobe( Osoba* glowaOsoba );
Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot );
Osoba* wczytajUsuwanaOsobe( Osoba* glowa );
Przedmiot* wczytajUsuwanyPrzedmiot( Przedmiot* glowa );
OsobaPrzedmiot* podepnijStudentaNaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* student, Przedmiot* przedm );
OsobaPrzedmiot* dajPracownikowiPrzedmiot( OsobaPrzedmiot* glowa, Osoba* pracownik, Przedmiot* przedm );
void wczytajStudentaDoWypisania( Osoba* glowaStudent, OsobaPrzedmiot* glowaOsobaPrzedmiot );
void wczytajPracownikaDoWypisania( Osoba* glowaPracownik, OsobaPrzedmiot* glowaPracownikPrzedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot );
void wczytajPrzedmiotDoWypisania( Przedmiot* glowaPrzedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot, OsobaPrzedmiot* glowaPracownikPrzedmiot );

