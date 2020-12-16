// mammal.h

#ifndef MAMMAL_H
#define MAMMAL_H
#include "Animal.h"

class Mammal: public Animal  {
  public:
    bool isNursing;
    void SetAnimalType();
    void SetNursingStatus(bool t_isNursing);
    bool GetNursingStatus();
    int GetNumberOfEggs();

};

#endif