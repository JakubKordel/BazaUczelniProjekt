#pragma once


#include <stdio.h>
#include "podst.h"
#include "struktury.h"

void wyswietlListeOsob( Osoba* glowaOsoba );
void wyswietlListePrzedmiotow( Przedmiot* glowaPrzedmiot );
void wypisStudent( Osoba* student, OsobaPrzedmiot* glowa );
void wyswietlListeStudentowZapisanychNaPrzedmiot( Przedmiot* przedmiot, OsobaPrzedmiot* glowa );
void wypisPrzedmiot( Przedmiot* przedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot, OsobaPrzedmiot* glowaPracowikPrzedmiot );
void wypisPracownik( Osoba* pracownik, OsobaPrzedmiot* glowaPracownikPrzedmiot, OsobaPrzedmiot* glowaStudentPrzedmiot );






