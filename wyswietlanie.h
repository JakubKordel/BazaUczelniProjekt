#pragma once

#include <stdio.h>
#include "podst.h"
#include "struktury.h"
#include "sortowanie.h"
#include "unistd.h"
#include "uzytkownik.h"
#include "zapis.h"
#include "poprawnosc.h"
#include <time.h>

void wyswietlListeStudentow( Glowy* glowy );
void wyswietlListePracownikow( Glowy* glowy );
void wyswietlListePrzedmiotow( Glowy* glowy );
void wypisStudent( Osoba* student, Glowy* glowy );
void wyswietlListeStudentowZapisanychNaPrzedmiot( Przedmiot* przedmiot, OsobaPrzedmiot* glowa );
void wypisPrzedmiot( Przedmiot* przedmiot, Glowy* glowy );
void wypisPracownik( Glowy* glowy, Osoba* pracownik );
void menuWczytywania ( Glowy* glowy );
void menuZapisywania( Glowy* glowy );





