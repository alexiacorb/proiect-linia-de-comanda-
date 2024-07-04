#include <iostream>
#include "Data.h"

using namespace std;
Data::Data():zi(0),luna(0),an(0){}

Data::~Data(){}

Data::Data(int zi,int luna,int an){
    this->zi=zi;
    this->luna=luna;
    this->an=an;
}

int Data::getZi() const {
    return zi;
}

int Data::getLuna() const{
    return luna;
}

int Data::getAn() const{
    return an;
}
ostream& operator<<(ostream& os, const Data& data) {
    os << data.zi << "/" << data.luna << "/" << data.an;
    return os;
}
