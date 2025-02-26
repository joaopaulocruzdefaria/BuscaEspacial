#include "Astronauta.hpp"
#include <sstream>

using namespace std;

Astronauta::Astronauta(std::string nome, int nivelSaude, bool atendimentoUrgente, int x, int y) : nome(nome), nivelSaude(nivelSaude), atendimentoUrgente(atendimentoUrgente), x(x), y(y) {}
Astronauta::Astronauta() : nome(""), nivelSaude(0), atendimentoUrgente(false), x(0), y(0) {}

void Astronauta::setNivelSaude(int nivelSaude) { this->nivelSaude = nivelSaude; }
void Astronauta::setAtendimentoUrgente(bool atendimentoUrgente) { this->atendimentoUrgente = atendimentoUrgente; }
void Astronauta::setX(int x) { this->x = x; }
void Astronauta::setY(int y) { this->y = y; }


string Astronauta::getNome() { return nome; }
int Astronauta::getNivelSaude() { return nivelSaude; }
bool Astronauta::getAtendimentoUrgente() { return atendimentoUrgente; }
int Astronauta::getX() { return x; }
int Astronauta::getY() { return y; }


string Astronauta::toString()
{
    ostringstream oss;
    oss << nome << " - Nível de saúde: " << nivelSaude << " - Atendimento urgente: " << (atendimentoUrgente ? "sim" : "não") << " - Posição: (" << x << "," << y << ")";
    return oss.str();
}

