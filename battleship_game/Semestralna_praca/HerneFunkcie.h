#pragma once
#include <iostream>
#include <string>
#include "Hrac.h"
using namespace std;


#ifndef HERNEFUNKCIE_H
#define HERNEFUNKCIE_H

#ifndef NUMBER_OF_GENERATED_COORDINATES
#define NUMBER_OF_GENERATED_COORDINATES 1000
#endif

void vygeneruj_suradnice(const string& nazov_suboru);

#endif

void inicializuj_hru();
void ukonci_hru(Hrac& Hrac_1, Hrac& Hrac_2, int max_skore, bool& koniec);
void vypis_konec_hry();
void vygeneruj_suradnice(const string& nazov_suboru);
void vypis_tah_hrac1(Hrac& Hrac_1);
void vypis_tah_hrac2(Hrac& Hrac_2);
void vypis_vysledok_tahu_hrac1(Hrac& Hrac_1, Hrac& Hrac_2);
void vypis_vysledok_tahu_hrac2(Hrac& Hrac_1, Hrac& Hrac_2); 

