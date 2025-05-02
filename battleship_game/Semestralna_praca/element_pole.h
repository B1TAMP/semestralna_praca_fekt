#pragma once
#include <iostream>
#include <iostream>
#include <string>

using namespace std;

class element_pole{
private:
	// stav elementu pola   L = lod, X = zasah, ' ' = prazdne
	// F - fregata, T - torpedoborec, K - kriznik, B - bojova_lod
	char stav; 

public:

	element_pole() : stav(' ') {} 
	//setter
	void Novy_Stav(char);	
	//gettter
	char Get_Stav() const;   


	operator char() const {  
		if ( stav == 'L' ) {
			return ' '; 
		}
		return stav; 
	}

	friend ostream& operator << (ostream&, const element_pole&);
	
};