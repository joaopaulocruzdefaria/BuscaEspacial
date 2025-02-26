#ifndef MODULO_HPP
#define MODULO_HPP

#include <iostream>

class Modulo
{
protected:
    char tipo;
    
public:

    Modulo();
    Modulo(char tipo);
    virtual ~Modulo();
    char getTipo();
    void setTipo(char tipo);
    virtual bool podeAcessar();
};

#endif
