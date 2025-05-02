#pragma once
#include <iostream>
#include <string>
#include "Hraci_Pole.h"
#include "Lod.h"
#include "element_pole.h"

using namespace std;


class Hrac
{
private:			

	string meno; 
	bool ukoncit; // neimplementoval som
	int skore;
	Hraci_Pole pole;
	

public:

	Hrac(string meno) : meno(meno), skore(0), ukoncit(false) {}
	// inicializuje lodky int => off_set 
	void pridaj_lod(int);	
	// vrati true ak zasah	
	bool vykonaj_tah(Hrac& hrac, int i, char A);
	//getter skore
	int get_skore() const; 

	void vypis_skore() const;

	void vypis_hracove_pole() const;
	// DEBUG
	void vypis_hracove_pole_lodi();
	// getter meno
	string get_meno() const;
};



