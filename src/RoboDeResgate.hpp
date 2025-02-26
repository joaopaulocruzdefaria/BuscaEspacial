#ifndef ROBODERESGATE_HPP
#define ROBODERESGATE_HPP

#include "EstacaoEspacial.hpp"
#include "Astronauta.hpp"
#include <queue>
#include <iostream>
#include <list>

using namespace std;

class RoboDeResgate
{
    private:
    int posicaoInicialX;
    int posicaoInicialY;
    EstacaoEspacial estacao;
    list<Astronauta> resgatados;
    list<Astronauta> naoResgatados;
    int passos;
    struct Pos
    {
        int x;
        int y;
    };
        

    public: 
    RoboDeResgate();
    void setResgatados(list<Astronauta> resgatados);
    void setNaoResgatados(list<Astronauta> naoResgatados);
    void setEstacao(EstacaoEspacial estacao);
    void setPosicaoInicialX(int posicaoInicialX);
    void setPosicaoInicialY(int posicaoInicialY);

    int getposicaoInicialX();
    int getposicaoInicialY();
    int getPassos();
    list<Astronauta> getResgatados();
    list<Astronauta> getNaoResgatados();

    void imprimirCaminho(vector<Pos> &caminho);
    int iniciarResgate();
    void resgatarAstronauta(Pos atual);
    void buscarAstronautasNaoResgatados();
    bool dentroDosLimites(int x, int y);
    bool proximoAoFogo(int x, int y);
    bool podeAcessar(int x, int y);
    



};

#endif
