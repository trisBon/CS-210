# CS210 Zoo.cpp

# Sumerize the project and what problem it was solving.

The goal of this project was to create a prototype of a RFID chip application that would allow animal handlers to update information about chipped about animals in their care. Instead of simply displaying the identity of individual animals, the app would also store information on the animal's type and breeding history.

# What did you do particularly well?

For this project, I am proudest of my AddAnimal function. Though inelegantly designed, AddAnimal handles input validation and creates an pointer objects only after all entries have successfully completed error testing. There are several opportunites for the user to verify entries, and nested loops are used to guide the user through the Animal class hierarchy.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, etc?

This code could be greatly inhanced by refactoring the code in AddAnimal() and LoadDataFromFile(). Both functions laod data to a vector of pointers, but receive data from different sources, which resulted in lines of identical code in the two functions. Finding a way to refactor the code so that AddAnimal() and LoadDataFromFile() can call on a third function to build their respective datas would make this code more object oriented and improve its readability. 

GenerateData() should also be modified to include input validation. LoadDataFromFile() could have implemented some input validation, but without the ability to call GenerateData() and update the user entry this didn't seem particularly beneficial.

# Did you find writing any piece of this code challenging and how did you overcome this? What tools and/or resources are you adding to your support network?

I found the LoadDataFromFile() function to be incredibly difficult to write because of ambiguous/conflicting information on the intended function of the code. Loading the data from the file was pretty straightfoward, but figuring out how to load that data into the vector took time. I also started the project assuming that GenerateData() would run more than a single time during the application, and had to rethink my approach to implementing the functions that take user inputs. 

It took me a long time to figure out the purpose of the Animal class. The project guidelines detailed the structure of the Animal class hierarchy, but didn't give a specific direction on how the classes should be implemented in the code. Meeting functional requirements for the TheZoo.cpp functions could have been accomplished without using the Animal class, so I had to choose between abiding by the UML class diagram and creating a superflous class, or make extensive modifications to the Animal class and its derived classes so that I could make use of the class in my application. 

For both of these issues, I used the ZyBooks e-book, an announcement posted by my instructor, stackoverflow, C++ API websites, and the help of a Dev 3 software engineer friend. I overcame these issues by prioritizing functionality over 100% adherance to assignment directions and perfectly tailored code. 

# What skills from this project will be particularly transferable to other projects and/or course work? 

I have two takeaways from this project. 1) Though it kills the perfectionsit in me to do so, ignoring some assignment directions may be necessary to complete an application, and 2) sometimes meeting a deadline means writing shoddy code. I realized that I was going to have to duplicate code from AddAnimal() for LoadDataFromFile() on Sunday afternoon, and knew I wouldn't be able to finish the assignment on time AND refactor my code. I'm still not happy about it, but I think I'll be happier if I can accept that done really is better than perfect. 
