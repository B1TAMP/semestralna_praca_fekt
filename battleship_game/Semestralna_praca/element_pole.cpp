
#include "element_pole.h"
#include <iostream>
#include <string>
#include "Hraci_Pole.h"

using namespace std;

void element_pole::Novy_Stav(char novy_stav) {
    stav = novy_stav;
} 

char element_pole::Get_Stav() const {   
    return stav;
}

ostream& operator << (ostream& os, const element_pole& elem) {
    os << static_cast<char>(elem);    
    return os;
   
}