// TheZoo.h
#ifndef THEZOO_H
#define THEZOO_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "jni.h"
#include "Animal.h"

using namespace std;

class TheZoo    {
    public:
        void DisplayData();
        void DisplayMenu();
        void LoadDataFromFile();
        vector<Animal*> animalTracking;
        
    private:
        void AddAnimal();
        void RemoveAnimal();
        void SaveDataToFile();
};

#endif