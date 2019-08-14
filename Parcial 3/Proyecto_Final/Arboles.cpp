#include "Arboles.h"

//Constructor
template<class T>
Arboles<T>::Arboles(){}

//Destructor
template<class T>
Arboles<T>::~Arboles(){}




//IMPORTANTE
#include "Persona.h"
template class Arboles<Persona>;
template class Arboles<int>;