#pragma once
#include "Lod.h"
#include <iostream>
using namespace std;
class Torpedoborec : public Lod {
protected:
	
public:
	Torpedoborec() : Lod(2) {}
	int Get_dlzka() {
		return dlzka;
	}
	void skontroluj_potopenie() {
		if (zasah >= dlzka) { potopena = true; cout << endl << "Torpedoborec Potopeny!" << endl;
		}
	}
	friend ostream& operator << (ostream& os, const Torpedoborec& t) {
		os << "Torpedoborec:    dlzka: " << t.dlzka << ", zasahy: " << t.zasah << ", potopena: " << t.potopena;
		return os;
	}

};

