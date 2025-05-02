
#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>
#include "element_pole.h"
#include "Hraci_Pole.h"
#include "Lod.h"
#include "Hrac.h"
#include "HerneFunkcie.h"
#include <limits>
using namespace std;

      //DEBUGING

//#define DEBUG_LODE // zobraz lode
//#define DEBUG_SURADNICE // nacitaj suradnice


bool DEBUG_MODE = false;
ifstream file;
//#define NUMBER_OF_GENERATED_COORDINATES 5 // pocet generovanych suradnic

			
												
							
class Hra {
private:

	Hrac Hrac_1;
	Hrac Hrac_2;
	int max_skore = 11;
	bool koniec ;

public:
	Hra(string meno1, string meno2) : Hrac_1(meno1) ,Hrac_2(meno2), koniec(false) {}

	void innicializuj() {
		
		// vypis menu
		inicializuj_hru();

		Hrac_1.pridaj_lod(257641);
		Hrac_2.pridaj_lod(78965);


						// DEBUG_LODE pre polohu konkretnych lodi
				#ifdef DEBUG_LODE
						Hrac_1.vypis_hracove_pole_lodi();
						Hrac_2.vypis_hracove_pole_lodi();
				#endif
		//  DEBUG nacitanie suradnic z suboru
		if (DEBUG_MODE) {

			file.open("suradnice.txt");
			if (!file) { cout << "Subor sa nepodarilo otvorit!" << endl;return; }

		}

	
	
	
	}
	void spusti() {

		while (!koniec) {
			int x;
			char y;

			vypis_tah_hrac1(Hrac_1);

			// DEBUG
			if (DEBUG_MODE) {
				if (!(file >> x >> y)) { 
					cout << "Koniec suboru!" << endl;
					file.close();
					koniec = true;
					continue; 
				}	
			}

			// DEBUG
			if(DEBUG_MODE){
				
				try {
					if (Hrac_1.vykonaj_tah(Hrac_2, x, y)) { cout << "Zasah!\n"; }
					else { cout << "Vedla!\n"; }
				}
				catch (exception& e) { cout << "Nastala chyba: " << e.what() << endl; }
			
			}
			else {


				bool valid_vstup = false;
				while (!valid_vstup) {
					valid_vstup = over_suradnice(x, y);
					if (valid_vstup) {
						try {
							
							if (Hrac_1.vykonaj_tah(Hrac_2, x, y)) { cout << "Zasah!\n"; }
							else { cout << "Vedla!\n"; }
						}
						catch (exception& e) { cout << "Nastala chyba: " << e.what() << endl; }

					}
				}
			}
			// DEBUG
			if (DEBUG_MODE) {
				if (!(file >> x >> y)) {
					cout << "Koniec suboru!" << endl;
					file.close();
					koniec = true;
					continue;
				}

			}
	
			vypis_vysledok_tahu_hrac1(Hrac_1, Hrac_2);
			ukonci_hru(Hrac_1, Hrac_2, max_skore, this->koniec);
			if (koniec) { break; }
			vypis_tah_hrac2(Hrac_2);

			// DEBUG
			if (DEBUG_MODE) {
				
				try {
					if (Hrac_2.vykonaj_tah(Hrac_1, x, y)) { cout << "Zasah!\n"; }
					else { cout << "Vedla!\n"; }
				}
				catch (exception& e) { cout << "Nastala chyba: " << e.what() << endl; }
			
			}
			else {
				try {
					bool vstup_valid = false;
					while (!vstup_valid) {
						vstup_valid = over_suradnice(x, y);
						if (vstup_valid) {
							if (Hrac_2.vykonaj_tah(Hrac_1, x, y)) { cout << "Zasah!\n"; }
							else { cout << "Vedla!\n"; }

						}

					}

				}
				catch (exception& e) {
					cout << "Nastala chyba: " << e.what() << endl;
					continue;
				}
			}

			
			vypis_vysledok_tahu_hrac2(Hrac_1, Hrac_2);
			ukonci_hru(Hrac_1, Hrac_2, max_skore,this->koniec);
			
			

		}
		

	}
	
	bool over_suradnice(int& x, char& y) {
		cout << "Zadaj suradnice utoku! (cislo 0-9 a pismeno A-J): ";

		if (!(cin >> x)) {
			cout << "Neplatny vstup pre cislo! Zadaj cele cislo od 0 do 9." << endl;
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			return false;
		}

		
		if (x < 0 || x >= 10) {
			cout << "Neplatny rozsah! Cislo musi byt od 1 do 10." << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
				return false;
		}

		
		if (!(cin >> y)) {
			cout << "Neplatny vstup pre pismeno!" << endl;
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			return false;
		}

	
		y = toupper(y);
		if (y < 'A' || y > 'J') {
			cout << "Neplatne pismeno! Zadajte pismeno od A do J." << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return false;
		}

	
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return true;
	}

	friend void inicializuj_hru();
	friend void ukonci_hru(Hrac& Hrac_1, Hrac& Hrac_2, int max_skore, bool& koniec);
	friend void vypis_tah_hrac1(Hrac& Hrac_1);
	friend void vypis_tah_hrac2(Hrac& Hrac_2);
	friend void vypis_vysledok_tahu_hrac1(Hrac& Hrac_1, Hrac& Hrac_2);
	friend void vypis_vysledok_tahu_hrac2(Hrac& Hrac_1, Hrac& Hrac_2);


};		




int main() {


	#ifdef DEBUG_SURADNICE
		DEBUG_MODE = true;
		vygeneruj_suradnice("suradnice.txt");
	#endif


	Hra hra("Ferda", "Honza");
	hra.innicializuj();
	hra.spusti();
	
	
	return 0;
}









	


	
	
