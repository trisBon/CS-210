// TheZoo.cpp
#include <iostream>
#include "jni.h"
#include <iomanip>
#include <string>
#include <fstream>
#include <iterator>

#include "TheZoo.h"
#include "Animal.h"
#include "Mammal.h"
#include "Oviparous.h"
#include "Bat.h"
#include "Whale.h"
#include "SeaLion.h"
#include "Goose.h"
#include "Pelican.h"
#include "Crocodile.h"

using namespace std;

void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{
     JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
     JNIEnv *env;                      // Pointer to native interface
                                                              //================== prepare loading of Java VM ============================
     JavaVMInitArgs vm_args;                        // Initialization arguments
     JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
     options[0].optionString = (char*) "-Djava.class.path=C:/repos/CPlusPlus/CS210/WildLifeZooFiles/WildLifeZooFiles/TheZoo";   // where to find java .class
     vm_args.version = JNI_VERSION_1_6;             // minimum Java version
     vm_args.nOptions = 1;                          // number of options
     vm_args.options = options;
     vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
                                                                          //=============== load and initialize Java VM and JNI interface =============
     jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
     delete options;    // we then no longer need the initialisation options.
     if (rc != JNI_OK) {
            // TO DO: error processing...
            cin.get();
            exit(EXIT_FAILURE);
     }
     //=============== Display JVM version =======================================
     cout << "JVM load succeeded: Version ";
     jint ver = env->GetVersion();
     cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

     jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
     if (cls2 == nullptr) {
            cerr << "ERROR: class not found !";
     }
     else {                                  // if class found, continue
            cout << "Class MyTest found" << endl;
            jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
            if (mid == nullptr)
                   cerr << "ERROR: method void createZooFile() not found !" << endl;
            else {
                   env->CallStaticVoidMethod(cls2, mid);                      // call method
                   cout << endl;
            }
     }


     jvm->DestroyJavaVM();
    // cin.get();           **** cin.get() commented out because it interrupted program transition from method to user menu.

}

// add animal to vector
void TheZoo::AddAnimal()
{      
       char userInput; // user selection variable

       // variables for creating new Animal pointers
       string animalName;
       int trackingNumber;
       char animalType;
       int numberOfEggs;
       bool isNursing = false;
       char animalSubType;
       int i;

       string typeOfAnimal; // string for print statements
       string nursingStatus; // string for print statements

       // animal class pointers
       Bat* newBat;
       Whale* newWhale;
       SeaLion* newSeaLion;
       Goose* newGoose;
       Pelican* newPelican;
       Crocodile* newCrocodile;





       cout << "Enter the animal tracking number: " << endl; // prompt user for tracking number
       cin >> trackingNumber;

       if (trackingNumber > 999999)       { // ensure tracking number does not exceed 6 digit limit
              cout << "Invalid entry. Tracking number cannot exceed six-digits." << endl; // console error message
              cin >> trackingNumber; // allow user to re-enter number
       }

       // code to allow user to verify entry
       cout << "You entered: " << trackingNumber << endl; 
       cout << "Press 'C' to continue (press 'R' to re-enter)." << endl; 
       cin >> userInput; 
       
       // allow user to re-enter tracking number
       while (userInput == 'R' || userInput == 'r') { // 
              cin >> trackingNumber;
              cout << "Is this correct? Enter 'Y' to continue (press 'R' to re-enter)." << endl;
              cin >> userInput;
       }

       // 
       cout << "Enter animal name: " << endl; // prompt user for animal name
       cin >> animalName;

       // code to let user verify
       cout << "You entered: " << animalName << endl;
       cout << "Press 'C' to continue (press 'R' to re-enter)." << endl;
       cin >> userInput;

       // allow user to re-enter animal Name
       while (userInput == 'R' || userInput == 'r') {
              cin >> animalName;
              cout << "You entered: " << animalName << endl;
              cout << "Is this correct? Press 'C' to continue (press 'R' to re-enter)." << endl;
              cin >> userInput;
       }

       // determine animal type
       cout << "Select animal type: 'O' for oviparous or 'M' for mammal." << endl;
       cin >> animalType;

       // display error message in case of invalid entry 
       while (animalType != 'm' && animalType != 'M' && animalType != 'o' && animalType !='O')      { // validate for supported animal type
              cout << "Invalid entry. Please try again." << endl;
              cin >> animalType; 
       }
       
// Mammal subtypes
       if (animalType == 'm' || animalType =='M')      { // mammals

              cout << "Select animal sub-type: 'B' for bat, 'S' for sealion, or 'W' for whale. "<< endl;
              cin >> animalSubType;

              // validate user input matches selection options
              while (animalSubType != 'S' && animalSubType != 's' && animalSubType != 'b' && animalSubType != 'B' && animalSubType != 'W' && animalSubType != 'w')      { // avalidate for supported animal subtype(M)
                     cout << "Invalid entry. Please try again." << endl;
                     cin >> animalSubType;
              }
              // determine if animal is nursing
              cout << "Is " << animalName << " nursing? Y/N?" << endl; // set nursing
              cin >> userInput;
              if (userInput == 'Y' || userInput == 'y')       {
                     isNursing = true;
                     nursingStatus = "Nursing";
              }
              if (userInput == 'N' || userInput == 'n')       {
                     nursingStatus = "Not Nursing";

              }

              // create new Sea Lion vector
              if (animalSubType == 'S' || animalSubType == 's')       {
                     typeOfAnimal = "Sea Lion ";
                     newSeaLion = new SeaLion();
                     newSeaLion->SetTrackNum(trackingNumber);
                     newSeaLion->SetName(animalName);                            
                     newSeaLion->SetNursingStatus(isNursing);
                     newSeaLion->SetAnimalType();
                     newSeaLion->SetAnimalSubType();

                     animalTracking.push_back(newSeaLion);

              }

              // create new Whale vector
              if (animalSubType == 'W' || animalSubType == 'w')   {
                     typeOfAnimal = "Whale ";

                     newWhale = new Whale();
                     newWhale->SetTrackNum(trackingNumber);
                     newWhale->SetName(animalName);                            
                     newWhale->SetNursingStatus(isNursing);
                     newWhale->SetAnimalType();                            
                     newWhale->SetAnimalSubType();

                     animalTracking.push_back(newWhale);

              }

              // create new Bat vector
              if (animalSubType == 'B' || animalSubType == 'b')       {
                     typeOfAnimal = "Bat ";

                     newBat = new Bat();
                     newBat->SetTrackNum(trackingNumber);
                     newBat->SetName(animalName);
                     newBat->SetAnimalType();
                     newBat->SetAnimalSubType();                            
                     newBat->SetNursingStatus(isNursing);                            
                     

                     animalTracking.push_back(newBat);
              }

              // print statements for final user verification
              cout << "You entered: " << endl; 
              cout << "Animal Name: " << animalName << endl;
              cout << "Tracking Number: " << trackingNumber << endl;
              cout << "Animal Type: " << typeOfAnimal << endl;
              cout << "Nursing status: " << nursingStatus << endl;
              cout << endl;
              
       }

// Oviparous subTypes 
       if (animalType == 'o' || animalType =='O')   { // oviparous

              cout << "Select animal sub-type: 'C' for crocodile, 'G' for goose, or 'P' for pelican." << endl;
              cin >> animalSubType;

              // validate user input matches provided selection
              while (animalSubType != 'G' && animalSubType != 'g' && animalSubType != 'P' && animalSubType != 'p' && animalSubType != 'C' && animalSubType != 'c')      { // validate for supported animal subtype(O)
                     cout << "Invalid entry. Please try again." << endl;
                     cin >> animalName;
              }

              // determine number of eggs
              cout << "How many eggs does " << animalName << " have?" << endl; // set number of eggs
              cin >> numberOfEggs;
              cout << endl;

              // create new Goose vector
              if (animalSubType == 'G' || animalSubType == 'g')       {
                     typeOfAnimal = "Goose ";

                     newGoose = new Goose();
                     newGoose->SetTrackNum(trackingNumber);
                     newGoose->SetName(animalName);
                     newGoose->SetAnimalType();
                     newGoose->SetAnimalSubType();
                     newGoose->SetNumberOfEggs(numberOfEggs);                           
                     

                     animalTracking.push_back(newGoose);

              }

              // create new Pelican vector
              if (animalSubType == 'P' || animalSubType == 'p')       {
                     typeOfAnimal = "Pelican ";

                     newPelican = new Pelican;
                     newPelican->SetTrackNum(trackingNumber);
                     newPelican->SetName(animalName);
                     newPelican->SetAnimalType();
                     newPelican->SetAnimalSubType();                            
                     newPelican->SetNumberOfEggs(numberOfEggs);                           
                     
                     animalTracking.push_back(newPelican);
              }

              // create new Crocodile vector
              if (animalSubType == 'C' || animalSubType == 'c')       {
                     typeOfAnimal = "Crocodile ";
                     newCrocodile = new Crocodile();
                     newCrocodile->SetTrackNum(trackingNumber);
                     newCrocodile->SetName(animalName);
                     newCrocodile->SetAnimalType();
                     newCrocodile->SetAnimalSubType();
                     newCrocodile->SetNumberOfEggs(numberOfEggs);                            
                     

                     animalTracking.push_back(newCrocodile);
              }

              // print statements for final user verification
              cout << "You entered: " << endl; 
              cout << "Animal Name: " << animalName << endl;
              cout << "Tracking Number: " << trackingNumber << endl;
              cout << "Animal Type: " << typeOfAnimal << endl;
              cout << "Number of Eggs: " << numberOfEggs << endl;
              cout << endl;
       } 
       
       // prompt user to save or exit method
       cout << "Enter 'S' to save or 'M' to abandon changes and return to menu." << endl;
       cout << endl;
       cin >> userInput;
       
       // call save function to save input to file
       if (userInput == 'S'|| userInput == 's')  {
              SaveDataToFile();
       }

       // abandon input, deallocate pointer, and return to menu
       if (userInput == 'M' || userInput == 'm') {
              newBat = nullptr;
              newSeaLion = nullptr;
              newWhale = nullptr;
              newGoose = nullptr;
              newCrocodile = nullptr;
              newPelican = nullptr;

              DisplayMenu();
       }

}

// remove animal from vector
void TheZoo::RemoveAnimal()
{
       int i;
       int userInput;

       cout << "Enter tracking code: " << endl;
       cin >> userInput;
       

       if( userInput <= 999999)    { // ensure userInput matches tracknumber length requirement
              for (i = 0; i < animalTracking.size(); i++)  {
                     if (animalTracking.at(i)->GetTrackNum() == userInput)     {

                            char confirm; // variable to hold user response
                            cout << "Delete tracking number " << userInput << "? Y/N" << endl; // confirm or cancel delete

                            cin >> confirm;

                            // if delete confirmed, deallocate pointer
                            if (confirm == 'Y' || confirm == 'y')     {
                                   animalTracking.at(i) = nullptr;
                                   animalTracking.erase(animalTracking.begin() + i);
                                   cout << "Animal successfully deleted." << endl;
                                   SaveDataToFile();
                            }

                            // if delete aborted, return to menu
                            if (confirm == 'n' || confirm == 'N')     {
                                   cout << "Deletion canceled. Retruning to main menu." << endl;
                                   DisplayMenu();
                            }
                     }
              }
       }
       else {
              cout << "Invalid entry. Please retry." << endl; // statement print if tracknumber length incorrect
              cin >> userInput;
       }

}

// load data from zoodata.txt
void TheZoo::LoadDataFromFile()
{
       string userInput; // user variable

       // variables to hold data stored in zoodata.txt file
       string animalName;
       int trackingNumber;
       string animalType;
       int numberOfEggs;
       bool isNursing = false;
       string animalSubType;
       int i;

       // animal class pointers
       Bat* newBat;
       Whale* newWhale;
       SeaLion* newSeaLion;
       Goose* newGoose;
       Pelican* newPelican;
       Crocodile* newCrocodile;

       ifstream readFile ("zoodata.txt"); // read zoodata file

       // assign zoodata to variables
       readFile >> trackingNumber;
       readFile >> animalName;
       readFile >> animalType;
       readFile >> animalSubType;
       readFile >> numberOfEggs;
       readFile >> isNursing;

       // If statements for initializing object, and setting pointer to object based on zoodata file contents

       // create new SeaLion
       if (animalSubType == "SeaLion" || animalSubType == "sealion")       {

              newSeaLion = new SeaLion();
              newSeaLion->SetTrackNum(trackingNumber);
              newSeaLion->SetName(animalName);                            
              newSeaLion->SetNursingStatus(isNursing);
              newSeaLion->SetAnimalType();
              newSeaLion->SetAnimalSubType();

              animalTracking.push_back(newSeaLion);

       }

       // create new Whale vector
       if (animalSubType == "Whale" || animalSubType == "whale")   {

              newWhale = new Whale();
              newWhale->SetTrackNum(trackingNumber);
              newWhale->SetName(animalName);                            
              newWhale->SetNursingStatus(isNursing);
              newWhale->SetAnimalType();                            
              newWhale->SetAnimalSubType();

              animalTracking.push_back(newWhale);

       }

       // create new Bat vector
       if (animalSubType == "Bat" || animalSubType == "bat")       {

              newBat = new Bat();
              newBat->SetTrackNum(trackingNumber);
              newBat->SetName(animalName);
              newBat->SetAnimalType();
              newBat->SetAnimalSubType();                            
              newBat->SetNursingStatus(isNursing);                            
              

              animalTracking.push_back(newBat);
       }

       if (animalSubType == "Goose" || animalSubType == "goose")       {

              newGoose = new Goose();
              newGoose->SetTrackNum(trackingNumber);
              newGoose->SetName(animalName);
              newGoose->SetAnimalType();
              newGoose->SetAnimalSubType();
              newGoose->SetNumberOfEggs(numberOfEggs);                           
              

              animalTracking.push_back(newGoose);

       }

       // create new Pelican vector
       if (animalSubType == "Pelican" || animalSubType == "pelican")       {

              newPelican = new Pelican;
              newPelican->SetTrackNum(trackingNumber);
              newPelican->SetName(animalName);
              newPelican->SetAnimalType();
              newPelican->SetAnimalSubType();                            
              newPelican->SetNumberOfEggs(numberOfEggs);                           
              
              animalTracking.push_back(newPelican);
       }

       // create new Crocodile vector
       if (animalSubType == "Crocodile" || animalSubType == "crocodile")       {

              newCrocodile = new Crocodile();
              newCrocodile->SetTrackNum(trackingNumber);
              newCrocodile->SetName(animalName);
              newCrocodile->SetAnimalType();
              newCrocodile->SetAnimalSubType();
              newCrocodile->SetNumberOfEggs(numberOfEggs);                            
              

              animalTracking.push_back(newCrocodile);
       }


       cout << endl;
       cout << "Load data successful." << endl; // confirm successful load to vector
       cout << "Press 'M' to return to menu" << endl;
       cin >> userInput;
       if (userInput == "m" || userInput == "M") {
              DisplayMenu();
       }
    
}

// display vector contents
void TheZoo::DisplayData()
{      
       int i;
       
       // heading for Data display
       cout << setfill(' ') << setw(6)<< left << "Track #" << '\t';
       cout << setw(15) <<"Name" << setw(15) << "Type" << setw(15) << "Sub-type" << setw(15) << "Eggs" << setw(15) << "Nurse" << endl;

       // print animalTracking vector contents with formatting
       for (i = 0; i < animalTracking.size(); i++)      {    

              cout << setfill('0') << setw(6) << animalTracking.at(i)->GetTrackNum() << '\t';
              cout << setfill(' ') << setw(15) <<animalTracking.at(i)->GetName();
              cout << setfill(' ') << setw(15) <<animalTracking.at(i)->animalType;
              cout << setfill(' ') << setw(15) <<animalTracking.at(i)->animalSubType;
              cout << setfill(' ') << setw(15) <<animalTracking.at(i)->GetNumberOfEggs();
              cout << setfill(' ') << setw(15) <<animalTracking.at(i)->GetNursingStatus();
              cout << endl; 
       }
      
      // format cushion and redirect user to menu
      cout << endl;
      cout << "Returning to main menu." << endl;
      cout << endl;
      cout << endl;
      DisplayMenu();

}

// opens zoodata.txt file and saves vector details to file.
void TheZoo::SaveDataToFile()
{
       int i;
       
       std::ofstream output_file("./zoodata.txt"); // open zoodata.txt

       if (output_file.is_open())  {
              // format for display header
              output_file << setfill(' ') << setw(6)<< left << "Track #" << '\t';
              output_file << setw(15) <<"Name" << setw(15) << "Type" << setw(15) << "Sub-type" << setw(15) << "Eggs" << setw(15) << "Nurse" << endl;

              // save contents of animalTracking vector to file
              for (i = 0; i < animalTracking.size(); i++)      {

                     output_file << setfill('0') << setw(6) << animalTracking.at(i)->GetTrackNum() << '\t';
                     output_file << setfill(' ') << setw(15) <<animalTracking.at(i)->GetName();
                     output_file << setfill(' ') << setw(15) <<animalTracking.at(i)->animalType;
                     output_file << setfill(' ') << setw(15) <<animalTracking.at(i)->animalSubType;
                     output_file << setfill(' ') << setw(15) <<animalTracking.at(i)->GetNumberOfEggs();
                     output_file << setfill(' ') << setw(15) <<animalTracking.at(i)->GetNursingStatus();
                     output_file << endl;
                     
              }
              
              cout << "Save successfully completed." << endl; // confirmation of successful save
       }
       else cout << "Error: unable to open file." << endl; // print message if file load fails

       DisplayMenu();
}

// display user menu
void TheZoo::DisplayMenu()
{
       int menuSelection; // variable to hold user selection

       // display menu options
       cout << "MENU" << endl;
       cout << "(1) Load Animal Data" << endl;
       cout << "(2) Generate Data" << endl;
       cout << "(3) Display Animal Data" << endl;
       cout << "(4) Add Record" << endl;
       cout << "(5) Delete Record" << endl;
       cout << "(6) Save Animal Data" << endl;
       cout << "(0) Exit Menu" << endl;
       
       // read user selection
       cin >> menuSelection;

       // handle user selections
       while (menuSelection != 0)  {

              if (menuSelection == 1)      { // call LoadDataFromFile()
                     LoadDataFromFile();     
              }
              else if (menuSelection == 2)      {       // call GenerateData(), which calls the java app
                     GenerateData(); 
              }
              else if (menuSelection == 3)      {       // call DisplayData()
                     DisplayData();
              }
              else if (menuSelection == 4)      {       // call AddAnimal()
                     AddAnimal();
              }
              else if (menuSelection == 5)      {       // call RemoveAnimal()
                     RemoveAnimal();
              }
              else if (menuSelection == 6)      {       // call SaveDataToFile()
                     SaveDataToFile();    
              }
              else
              {
                     cout << "Invalid entry. Please try again.";
                     cin.ignore();
                     cout << endl;
                  //   cin >> menuSelection;      
              }

              // reprint menu desplay
              cout << "MENU" << endl;
              cout << "(1) Load Animal Data" << endl;
              cout << "(2) Generate Data" << endl;
              cout << "(3) Display Animal Data" << endl;
              cout << "(4) Add Record" << endl;
              cout << "(5) Delete Record" << endl;
              cout << "(6) Save Animal Data" << endl;
              cout << "(0) Exit Menu" << endl;

              cin >> menuSelection;
              
       }
       
       
       
       
}

int main()
{
       TheZoo newZoo; // create new TheZoo object
       newZoo.DisplayMenu(); 

	return 1;
}
