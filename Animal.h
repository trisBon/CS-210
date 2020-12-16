
#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Animal    {
    public:
        string name;
        int trackNum;
        void SetName(string t_name);
        void SetTrackNum(int t_trackNum);
        string animalSubType;
        string animalType;
        string GetName();
        int GetTrackNum();

        virtual bool GetNursingStatus();  // used virtual methods to access derived class methods for pointer assignment
        virtual int GetNumberOfEggs();
        bool isNursing; 
};

#endif
