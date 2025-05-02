#pragma once
#include <iostream>
#include <string>
#include "element_pole.h"
#include "Lod.h"
#include "Fregata.h"
#include "Bojova_lod.h"
#include "Torpedoborec.h"
#include "Kriznik.h"
#include <ctime>
#include <vector>

using namespace std;



class Hraci_Pole {
private:
	
			//element_pole pole[10][10];           
			//element_pole pole_lodi[10][10];      


	element_pole** pole;   
	element_pole** pole_lodi; 
	int size = 10; 

	Fregata fregata;
	Torpedoborec torpedoborec;
	Bojova_lod bojova_lod;	
	Kriznik kriznik;
	
	
public:
	

	Hraci_Pole(int size = 10): size(size)  {

		pole = new element_pole * [size];
		pole_lodi = new element_pole * [size];

		for (int i = 0; i < size; i++) {

			pole[i] = new element_pole[size];
			pole_lodi[i] = new element_pole[size];
		}
	}
	
    friend ostream& operator<<(ostream& os, const Hraci_Pole& hraci_pole) {  

				os << endl << "                                      Protihracove lode: " << endl;
				os << "                                      ___________________" << endl;
				os << "                                      " << hraci_pole.fregata << endl;
				os << "                                      " << hraci_pole.torpedoborec << endl;
				os << "                                      " << hraci_pole.kriznik << endl;
				os << "                                      " << hraci_pole.bojova_lod << endl;
				os << "                                      ___________________" << endl;
		os << "     Protihracovo pole:   " << endl;
       os << " ________________________________" << endl;  
       os << "|   A  B  C  D  E  F  G  H  I  J |" << endl;  
       os << " _______________________________" << endl;  
       for (int i = 0; i < hraci_pole.size; i++) {  
           os << "|" << i << "|";  
           for (int j = 0; j < hraci_pole.size; j++) {
               os << " " << hraci_pole.pole[i][j] << " ";  
           }  
           os << "|";  
           os << " " << endl;  
       }  
       os << " _________________________________" << endl;  
       return os;  
    }

											
	void Vypis_Hraci_Pole_Lodi() const;
	void Umiestni_Lod(int);				
	bool zasiahni_lod(int ,char);
											
	
	~Hraci_Pole() {
		for (int i = 0; i < size; i++) {
			delete[] pole[i];
			delete[] pole_lodi[i];
		}
		delete[] pole;
		delete[] pole_lodi;
	}
};




