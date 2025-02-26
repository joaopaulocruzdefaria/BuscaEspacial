#ifndef MODULOVAZIO_HPP
#define MODULOVAZIO_HPP

#include "Modulo.hpp"

class ModuloVazio : public Modulo
{
    
public:
    ModuloVazio(char tipo) : Modulo(tipo) {}
    virtual ~ModuloVazio() {}
    bool podeAcessar() override { return true; }
};

#endif