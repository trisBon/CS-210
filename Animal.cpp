// Animal.cpp

#include <iostream>
#include <iomanip>
#include <string>

#include "Animal.h"
#include "Oviparous.h"
#include "Mammal.h"

using namespace std;

void Animal::SetName(string t_name)   {
    name = t_name;
}

string Animal::GetName()  {
    return name;
}

void Animal::SetTrackNum(int t_trackNumber) {
    trackNum = t_trackNumber;
}

int Animal::GetTrackNum()   {
    return trackNum;
}

bool Animal::GetNursingStatus() {
    return false;
}

int Animal::GetNumberOfEggs()   {
    return 0;
}












