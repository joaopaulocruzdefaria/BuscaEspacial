#ifndef ESTACAO_ESPACIAL_HPP
#define ESTACAO_ESPACIAL_HPP

#include <vector>
#include <list>
#include <iostream>
#include "Modulo.hpp"
#include "Astronauta.hpp"

using namespace std;

class EstacaoEspacial
{
private:
    int linhas;
    int colunas;
    vector<vector<Modulo *> > matriz;
    list<Astronauta> astronautas;

public:
    EstacaoEspacial();
    vector<vector<Modulo *> > &getMatriz() { return matriz; }
    list<Astronauta> &getTodosAstronautas() { return astronautas; }
    int getLinhas();
    int getColunas();

    void setLinhas(int linhas);
    void setColunas(int colunas);
    void setAstronautas(list<Astronauta> astronautas);
    void setPosicaoAstronauta(int x, int y);


    Astronauta procurarAstronauta(int x, int y);
    void imprimirMatriz();
    void imprimirAstronautas();
};

#endif