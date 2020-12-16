// Mammal.cpp

#include "Mammal.h"

void Mammal::SetNursingStatus(bool t_isNursing)  {
    isNursing = t_isNursing;
}

bool Mammal::GetNursingStatus() {
    return isNursing;
}

void Mammal::SetAnimalType()    {
    animalType = "Mammal";
}

int Mammal::GetNumberOfEggs()   {
    return 0;
}