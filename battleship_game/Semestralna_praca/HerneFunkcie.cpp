
#include "HerneFunkcie.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Hrac.h"
#include <cstdlib>

using namespace std;

//vypis uvodneho menu hry
void inicializuj_hru() { 

	cout << endl;
	cout << "|  Vytajte v hre na Lode  | " << endl;
	cout << "|_________________________|" << endl;
	cout << endl << "Lode su umiestnene nahodne" << endl;
	cout << "kazdy hrac v svojom kole zadava suradnice utoku v tvare (cislo pismeno)" << endl;
	cout << "napr.    5 A" << endl;
	cout << "Ak sa lod zasiahne, na hracom poli sa zobrazi X" << endl;
	cout << "Ak sa lod netrafi, na hracom poli sa zobrazi O" << endl;
	cout << "Hrac, ktory ako prvy potopi vsetky lode vyhrava" << endl;
	cout << "_________________________" << endl;
	cout << endl;
	cout << endl;

}

void ukonci_hru(Hrac& Hrac_1, Hrac& Hrac_2, int max_skore, bool& koniec) {

	if (Hrac_1.get_skore() >= max_skore && Hrac_2.get_skore() < max_skore) {
		vypis_konec_hry();
		cout << Hrac_1.get_meno() << "     vyhral!   " << endl;;
		koniec = true;
	}
	else if (Hrac_2.get_skore() >= max_skore && Hrac_1.get_skore() < max_skore) {
		vypis_konec_hry();
		cout << Hrac_2.get_meno() << "     vyhral!   " << endl;
		koniec = true;
	}

	else if (Hrac_1.get_skore() >= max_skore && Hrac_2.get_skore() >= max_skore) {
		vypis_konec_hry();
		cout << "    Remiza!   " << endl;
		koniec = true;
	}



}
//vypise koniec hry
void vypis_konec_hry() {

	cout << endl;
	cout << endl;
	cout << "_______KONIEC_HRY________" << endl;
	cout << "_________________________" << endl;


}
//vygeneruje nahodne suradnice do suboru
void vygeneruj_suradnice(const string& nazov_suboru) {

	ofstream file;
	file.open(nazov_suboru);
	for (int i = 0; i < NUMBER_OF_GENERATED_COORDINATES; i++) {
		file << rand() % 10 << ' '
			<< static_cast<char>('A' + rand() % 10) << endl;
	}
	file.close();
}
void vypis_tah_hrac1(Hrac& Hrac_1) {
	cout << "__________________________________" << endl;
	cout << "          " << Hrac_1.get_meno() << " - TVOJ TAH!" << endl;
	cout << endl;
	cout << Hrac_1.get_meno() << ": ";
};
void vypis_tah_hrac2(Hrac& Hrac_2) {
	cout << "__________________________________" << endl;
	
	cout <<"          " << Hrac_2.get_meno() << " - TVOJ TAH!" << endl;
	cout << endl;
	cout << Hrac_2.get_meno() << ": ";

};
void vypis_vysledok_tahu_hrac1(Hrac& Hrac_1, Hrac& Hrac_2) {  Hrac_2.vypis_hracove_pole(), Hrac_1.vypis_skore();  }
void vypis_vysledok_tahu_hrac2(Hrac& Hrac_1, Hrac& Hrac_2) { Hrac_1.vypis_hracove_pole(), Hrac_2.vypis_skore(); };


