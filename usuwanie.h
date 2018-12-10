#pragma once

#include "funkcje.h"
#include "przeszukiwanie.h"

void usuwaniePierwszegoStudenta( Glowy* glowy );
void usuwanieStudenta( Glowy* glowy, Osoba* usuwany );
void usuwaniePierwszegoPracownika( Glowy* glowy );
void usuwaniePracownika( Glowy* glowy, Osoba* usuwany );
void usuwaniePierwszegoPrzedmiotu( Glowy* glowy );
void usuwaniePrzedmiotu( Glowy* glowy, Przedmiot* usuwany );
OsobaPrzedmiot* usuwaniePierwszejOsobaPrzedmiot( OsobaPrzedmiot* glowa );
OsobaPrzedmiot* usuwanieOsobaPrzedmiot( OsobaPrzedmiot* glowa, OsobaPrzedmiot* usuwany );


