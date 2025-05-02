#include "Hraci_Pole.h"
#include <iostream>
#include <stdexcept>
#include "Lod.h"
#include "Fregata.h"
#include <ctime>
#include <vector>

using namespace std;




// metoda pre umiestnenie lodi na hracom poli
void Hraci_Pole::Umiestni_Lod(int off_set) {

	
    vector<int> lodky; 
	vector<char> znaky;


    lodky.push_back(fregata.Get_dlzka());
    lodky.push_back(torpedoborec.Get_dlzka());
    lodky.push_back(kriznik.Get_dlzka());
    lodky.push_back(bojova_lod.Get_dlzka());
	
	znaky.push_back('F');
	znaky.push_back('T');
	znaky.push_back('K');
	znaky.push_back('B');


    srand(time(0) + off_set);

    bool vertikalne;
    int vpravo, vlavo, hore, dole, suradnica_x, suradnica_y;
    bool umiestnena;

    for (int it = 0; it < lodky.size(); it++) {
        umiestnena = false;

        while (!umiestnena) {

            bool konflikt = false;
            suradnica_x = rand() % 10;
            suradnica_y = rand() % 10;
            vertikalne = rand() % 2;

            
            vpravo = suradnica_x + lodky[it] - 1;
            vlavo = suradnica_x - (lodky[it] - 1);
            hore = suradnica_y + lodky[it] - 1;
            dole = suradnica_y - (lodky[it] - 1);

            if (vertikalne) {
                if (vpravo <= 9) {
                  
                    for (int i = suradnica_x; i <= vpravo; i++) {
                        if (pole[i][suradnica_y].Get_Stav() == 'L') {
                            konflikt = true;
                            break;
                        }
                    }

                    if (!konflikt) {
                        for (int i = suradnica_x; i <= vpravo; i++) {
                            pole[i][suradnica_y].Novy_Stav('L');
                            pole_lodi[i][suradnica_y].Novy_Stav(znaky[it]);

                        }
                        umiestnena = true;
                    }
                }
                else {
      
                    for (int i = suradnica_x; i >= vlavo; i--) {
                        if (pole[i][suradnica_y].Get_Stav() == 'L') {
                            konflikt = true;
                            break;
                        }
                    }

                    if (!konflikt) {
                        for (int i = suradnica_x; i >= vlavo; i--) {
                            pole[i][suradnica_y].Novy_Stav('L');
							pole_lodi[i][suradnica_y].Novy_Stav(znaky[it]);
                        }
                        umiestnena = true;
                    }
                }
            }
            else {
                if (hore <= 9) {
              
                    for (int i = suradnica_y; i <= hore; i++) {
                        if (pole[suradnica_x][i].Get_Stav() == 'L') {
                            konflikt = true;
                            break;
                        }
                    }

                    if (!konflikt) {
                        for (int i = suradnica_y; i <= hore; i++) {
                            pole[suradnica_x][i].Novy_Stav('L');
                            pole_lodi[suradnica_x][i].Novy_Stav(znaky[it]);
                        }
                        umiestnena = true;
                    }
                }
                else  {
                  
                    for (int i = suradnica_y; i >= dole; i--) {
                        if (pole[suradnica_x][i].Get_Stav() == 'L') {
                            konflikt = true;
                            break;
                        }
                    }

                    if (!konflikt) {
                        for (int i = suradnica_y; i >= dole; i--) {
                            pole[suradnica_x][i].Novy_Stav('L');
                            pole_lodi[suradnica_x][i].Novy_Stav(znaky[it]);

                        }
                        umiestnena = true;
                    }
                }
            }
        }
    }
}
// metoda na ovladanie pola a jeho elementov
bool Hraci_Pole::zasiahni_lod(int i, char A) {

    int x = i;
    int y = A - 'A';

    if (x < 0 || x >= 10 || y < 0 || y >= 10) {            
        throw out_of_range("Suradnice su neplatne!");
    }

    if (pole_lodi[x][y].Get_Stav() == 'F') { fregata.zasiahni();fregata.skontroluj_potopenie(); }
	else if (pole_lodi[x][y].Get_Stav() == 'T') { torpedoborec.zasiahni();torpedoborec.skontroluj_potopenie(); }
	else if (pole_lodi[x][y].Get_Stav() == 'K') { kriznik.zasiahni();kriznik.skontroluj_potopenie(); }
	else if (pole_lodi[x][y].Get_Stav() == 'B') { bojova_lod.zasiahni();bojova_lod.skontroluj_potopenie(); }

    if (pole[x][y].Get_Stav() == 'L') {
        pole[x][y].Novy_Stav('X');
		pole_lodi[x][y].Novy_Stav('X');
        return true;
    }
    else if (pole[x][y].Get_Stav() == 'X') {
        return false;
    }
    else {
        pole[x][y].Novy_Stav('o');
        
        return false;
		
    }
   

    
}

//DEBUG polohy lodi
void Hraci_Pole::Vypis_Hraci_Pole_Lodi() const{ 

    cout << " ________________________________" << endl;
    cout << "|   A  B  C  D  E  F  G  H  I  J |" << endl;
    cout << " _______________________________" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "|" << i << "|";
        for (int j = 0; j < 10; j++) {
            cout << " " << pole_lodi[i][j] << " ";
        }
        cout << "|";
        cout << " " << endl;
    }
    cout << " _________________________________" << endl;
}