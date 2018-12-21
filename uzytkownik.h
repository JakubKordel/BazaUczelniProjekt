#pragma once

#include <stdio.h>
#include <string.h>
#include "struktury.h"
#include "usuwanie.h"
#include "wyswietlanie.h"

Osoba* wczytajOsobe( Osoba* glowaOsoba );
Przedmiot* wczytajPrzedmiot( Przedmiot* glowaPrzedmiot );
void wczytajUsuwanaOsobe( Glowy* glowy, int typOsoby );
void wczytajUsuwanyPrzedmiot( Glowy* glowy );
void podepnijOsobeNaPrzedmiot( Glowy *glowy, Osoba* osoba, Przedmiot* przedm, int typOsoby );
void wczytajOsobeDoWypisania( Glowy* glowy, int typOsoby );
void wczytajPrzedmiotDoWypisania( Glowy* glowy );
void usunZprzedmiotuStudenta( Glowy* glowy, Przedmiot* przedmiot );
void usunZprzedmiotuProwadzacego( Glowy* glowy, Przedmiot* przedm );

