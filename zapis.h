#pragma once

#include "funkcje.h"
#include "struktury.h"
#include "przeszukiwanie.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "dirent.h"
#include "podst.h"
#include <time.h>

void zapiszBaze( Glowy* glowy, char* nazwaPliku );
void wczytajBaze( Glowy* glowy, char* nazwaPliku );
void wczytajNazwyPlikow( Glowy* glowy );

