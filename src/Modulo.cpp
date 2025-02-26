#include "Modulo.hpp"

Modulo::Modulo() : tipo(' ') {}

Modulo::Modulo(char tipo) : tipo(tipo) {}

Modulo::~Modulo() {}

char Modulo::getTipo() {
    return tipo;
}

void Modulo::setTipo(char tipo) {
    this->tipo = tipo;
}

bool Modulo::podeAcessar() {
    return true;
}