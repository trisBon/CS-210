// oviparous.cpp

#include "Oviparous.h"

void Oviparous::SetNumberOfEggs(int t_eggs) {
    numberOfEggs = t_eggs;
}

int Oviparous::GetNumberOfEggs()    {
    return numberOfEggs;
}

void Oviparous::SetAnimalType() {
    animalType = "Oviparous";
}

bool Oviparous::GetNursingStatus() {
    return false;
}
