#ifndef ASTRONAUTA_HPP
#define ASTRONAUTA_HPP

#include <string>

using namespace std;

class Astronauta {
public:
    Astronauta(string nome, int nivelSaude, bool atendimentoUrgente, int x, int y);
    Astronauta();

    void setNivelSaude(int nivelSaude);
    void setAtendimentoUrgente(bool atendimentoUrgente);
    void setX(int x);
    void setY(int y);
    
    string getNome();
    int getNivelSaude();
    bool getAtendimentoUrgente();
    int getX();
    int getY();

    string toString();

private:
    string nome;
    int nivelSaude;
    bool atendimentoUrgente;
    int x;
    int y;
};

#endif  // ASTRONAUTA_HPP
