// pelican.h

#include "Animal.h"
#include "Oviparous.h"

class Pelican: public Oviparous {
    public:
        void SetAnimalSubType();
        string GetAnimalSubType();

};