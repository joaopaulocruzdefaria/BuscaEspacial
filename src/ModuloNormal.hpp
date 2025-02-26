#ifndef MODULONORMAL_HPP
#define MODULONORMAL_HPP

#include "Modulo.hpp"

class ModuloNormal : public Modulo
{
    
public:
    ModuloNormal(char tipo) : Modulo(tipo) {}
    virtual ~ModuloNormal() {}
    bool podeAcessar() override { return true; }

};

#endif