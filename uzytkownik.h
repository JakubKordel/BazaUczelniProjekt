#pragma once

#include <stdio.h>
#include <string.h>
#include "struktury.h"
#include "usuwanie.h"
#include "wyswietlanie.h"

Osoba* wczytajOsobe( Osoba* glowaOsoba );
Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot );
void wczytajUsuwanegoStudenta( Glowy* glowy );
void wczytajUsuwanegoPracownika( Glowy* glowy );
void wczytajUsuwanyPrzedmiot( Glowy* glowy );
OsobaPrzedmiot* podepnijStudentaNaPrzedmiot( OsobaPrzedmiot* glowa, Osoba* student, Przedmiot* przedm );
void dajStudentowiPrzedmiot( Glowy* glowy, Osoba* student );
void dajPrzedmiotowiStudenta( Glowy* glowy, Przedmiot *przedmiot );
void dajPrzedmiotowiProwadzacego( Glowy* glowy, Przedmiot *przedmiot );
void dajPracownikowiPrzedmiot( Glowy* glowy, Osoba* pracownik );
void wczytajStudentaDoWypisania( Glowy* glowy );
void wczytajPracownikaDoWypisania( Glowy* glowy );
void wczytajPrzedmiotDoWypisania( Glowy* glowy );

