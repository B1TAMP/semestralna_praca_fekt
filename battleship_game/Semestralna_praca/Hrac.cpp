#include "Hrac.h"
#include <iostream>
#include <string>
#include "Hraci_Pole.h"
#include "Lod.h"
#include "element_pole.h"

using namespace std;




	void Hrac :: pridaj_lod(int off_set) {
		pole.Umiestni_Lod( off_set);
	}
	
	bool Hrac:: vykonaj_tah(Hrac& hrac, int i, char A) {
		bool konaj = hrac.pole.zasiahni_lod(i, A);
		if (konaj) { skore++; } 
		return konaj;
	}
	int Hrac::get_skore() const { return skore; } 

	void Hrac::vypis_skore() const{ cout << meno << " tvoje skore: " << skore << endl; }

	void Hrac::vypis_hracove_pole() const{ cout << pole; } 

	void Hrac::vypis_hracove_pole_lodi() { pole.Vypis_Hraci_Pole_Lodi(); } 

	string Hrac::get_meno() const { return meno; } 
