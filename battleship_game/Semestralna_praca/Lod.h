#pragma once
#include <iostream>
#include <string>
#include "element_pole.h"


using namespace std;

class Lod{
protected:

	int dlzka;
	bool potopena;
	int zasah;

public:
	Lod(int dlzka) : dlzka(dlzka), zasah(0), potopena(false) {}
	
	 virtual ~Lod() {}
	 //kontrola potopenia
	 virtual void skontroluj_potopenie() {
		 if (zasah >= dlzka) { potopena = true; }
	 };
	 // inkrementuje zasah
	 void zasiahni() {
		 if (zasah < dlzka) { zasah++; }
	 };
	


};

