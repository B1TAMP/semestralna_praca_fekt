#pragma once
#include "Lod.h"
#include <iostream>
using namespace std;
class Kriznik : public Lod {
protected:
	
public:
	Kriznik() : Lod(3) {}
	
	int Get_dlzka() {
		return dlzka;
	}
	void skontroluj_potopenie() {
		if (zasah >= dlzka) {
			potopena = true; cout << endl << "Kriznik Potopeny!" << endl;
		}
	}
	friend ostream& operator << (ostream& os, const Kriznik& k) {
		os << "Kriznik:    dlzka: " << k.dlzka << ", zasahy: " << k.zasah << ", potopena: " << k.potopena;
		return os;
	}



};