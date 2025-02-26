#ifndef MODULOCOMASTRONAUTA_HPP
#define MODULOCOMASTRONAUTA_HPP

#include "Modulo.hpp"

class ModuloComAstronauta : public Modulo
{

public:
    ModuloComAstronauta(char tipo) : Modulo(tipo) {}
    bool podeAcessar() override { return true; }
}; 

#endif