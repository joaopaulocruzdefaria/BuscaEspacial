#ifndef LEITORDEARQUIVO_HPP
#define LEITORDEARQUIVO_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include "Modulo.hpp"
#include "Astronauta.hpp"
#include "EstacaoEspacial.hpp"
#include "RoboDeResgate.hpp"
#include "ModuloComAstronauta.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloNormal.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloVazio.hpp"
#include "ModuloSeguranca.hpp"

using namespace std;

class LeitorDeArquivo {
public:
    void lerArquivo(string &nomeArquivo, EstacaoEspacial &estacao, RoboDeResgate &robo);
    void escreverArquivo( string &nomeArquivo, RoboDeResgate &robo);
};

#endif