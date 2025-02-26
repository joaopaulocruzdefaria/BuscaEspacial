#include "EstacaoEspacial.hpp"

using namespace std;

EstacaoEspacial::EstacaoEspacial() {
    linhas = 0;
    colunas = 0;
    matriz = vector<vector<Modulo *> >();
}


void EstacaoEspacial::setLinhas(int linhas) {
    this->linhas = linhas;
}

void EstacaoEspacial::setColunas(int colunas) {
    this->colunas = colunas;
}

void EstacaoEspacial::setAstronautas(list<Astronauta> astronautas) {
    this->astronautas = astronautas;
}

void EstacaoEspacial::setPosicaoAstronauta(int x, int y) {
    astronautas.front().setX(x);
    astronautas.front().setY(y);
}   

int EstacaoEspacial::getLinhas() {
    return linhas;
} 

int EstacaoEspacial::getColunas() {
    return colunas;
}

Astronauta EstacaoEspacial::procurarAstronauta(int x, int y) {
    Astronauta astro;
    for (Astronauta astro : astronautas) {
        if (astro.getX() == x && astro.getY() == y) {
            return astro;
        }
    }
    return Astronauta(); 
}

void EstacaoEspacial::imprimirMatriz() {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << matriz[i][j]->getTipo();
        }
        cout << endl;
    }
}

void EstacaoEspacial::imprimirAstronautas() {
    for (list<Astronauta>::iterator it = astronautas.begin(); it != astronautas.end(); it++) {
        cout << it->getNome() << " " << it->getAtendimentoUrgente() << " " << it->getNivelSaude() << " " << it->getX() << " " << it->getY() << endl;
    }
    
}


