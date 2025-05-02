#pragma once
#include "Lod.h"
#include <iostream>
using namespace std;

class Fregata : public Lod {
	
public:

	Fregata() : Lod(2) {}
	
	int Get_dlzka() const {
		return dlzka;
	}
	void skontroluj_potopenie() override {
		if (zasah >= dlzka) { potopena = true; cout << endl << "Fregata Potopena!"<< endl; }
	}

	friend ostream& operator << (ostream& os, const Fregata& f) {
		os << "Fregata:    dlzka: " << f.dlzka << ", zasahy: " << f.zasah << ", potopena: " << f.potopena;
		return os;
	}
};

