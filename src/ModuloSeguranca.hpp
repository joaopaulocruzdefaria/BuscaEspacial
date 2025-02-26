#ifndef MODULOSEGURANCA_HPP
#define MODULOSEGURANCA_HPP

#include "Modulo.hpp"

class ModuloSeguranca : public Modulo
{
    
public:
    ModuloSeguranca(char tipo) : Modulo(tipo) {}
    virtual ~ModuloSeguranca() {}
    bool podeAcessar() override { return true; }
};

#endif