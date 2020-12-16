// oviparous.h
#ifndef OVIPAROUS_H
#define OVIPAROUS_H

#include "Animal.h"

class Oviparous: public Animal   {
    public:
        int numberOfEggs;
        void SetAnimalType();
        void SetNumberOfEggs(int t_eggs);
        int GetNumberOfEggs();
        bool GetNursingStatus();
};

#endif