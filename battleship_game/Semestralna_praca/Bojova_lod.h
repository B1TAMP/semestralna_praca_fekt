#pragma once
#include "Lod.h"
#include <iostream>

using namespace std;

class Bojova_lod : public Lod {
protected:
	
public:
	
	Bojova_lod() : Lod(4) {}
	int Get_dlzka() {
		return dlzka;
	}
	void skontroluj_potopenie() override {
		if (zasah >= dlzka) { potopena = true; cout << endl << "Bojova Lod Potopena!" << endl;
		}
	}
	friend ostream& operator << (ostream& os, const Bojova_lod& b) {
		os << "Bojova lod:    dlzka: " << b.dlzka << ", zasahy: " << b.zasah << ", potopena: " << b.potopena;
		return os;
	}




};

