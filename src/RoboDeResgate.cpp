#include "RoboDeResgate.hpp"
#include "EstacaoEspacial.hpp"
#include "ModuloObstaculo.hpp"
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

RoboDeResgate::RoboDeResgate()
{
    this->posicaoInicialX = 0;
    this->posicaoInicialY = 0;
    this->estacao = EstacaoEspacial();
    this->passos = 0;
}



void RoboDeResgate::setEstacao(EstacaoEspacial estacao)
{
    this->estacao = estacao;
}

void RoboDeResgate::setPosicaoInicialX(int posicaoInicialX)
{
    this->posicaoInicialX = posicaoInicialX;
}

void RoboDeResgate::setPosicaoInicialY(int posicaoInicialY)
{
    this->posicaoInicialY = posicaoInicialY;
}

void RoboDeResgate::setResgatados(list<Astronauta> resgatados)
{
    this->resgatados = resgatados;
}

void RoboDeResgate::setNaoResgatados(list<Astronauta> naoResgatados)
{
    this->naoResgatados = naoResgatados;
}



int RoboDeResgate::getposicaoInicialX()
{
    return posicaoInicialX;
}

int RoboDeResgate::getposicaoInicialY()
{
    return posicaoInicialY;
}

list<Astronauta> RoboDeResgate::getResgatados()
{
    return resgatados;
}

list<Astronauta> RoboDeResgate::getNaoResgatados()
{
    return naoResgatados;
}

int RoboDeResgate::getPassos()
{
    return passos;
}



void RoboDeResgate::buscarAstronautasNaoResgatados()
{
    for (auto astronauta : estacao.getTodosAstronautas())
    {
        bool resgatado = false;
        for (auto astronautaResgatado : resgatados)
        {
            if (astronauta.getNome() == astronautaResgatado.getNome())
            {
                resgatado = true;
                break;
            }
        }
        if (!resgatado)
        {
            naoResgatados.push_back(astronauta);
        }
    }
    cout << endl
         << "Nao resgatados: " << endl;
    for (auto astronauta : naoResgatados)
    {
        cout << astronauta.toString() << endl;
    }
}

bool RoboDeResgate::proximoAoFogo(int x, int y)
{
    int directions[][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (int i = 0; i < 8; ++i)
    {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (newX >= 0 && newX < estacao.getLinhas() && newY >= 0 && newY < estacao.getColunas())
        {
            Modulo *adjacente = estacao.getMatriz()[newX][newY];
            if (adjacente != nullptr && adjacente->getTipo() == 'F')
            {
                return true;
            }
        }
    }
    return false;
}

void RoboDeResgate::resgatarAstronauta(Pos atual)
{
    for (auto astronauta : estacao.getTodosAstronautas())
    {
        if (astronauta.getX() == atual.x && astronauta.getY() == atual.y)
        {
            cout << endl
                 << astronauta.toString() << endl;
            resgatados.push_back(astronauta);
            break;
        }
    }
}

void RoboDeResgate::imprimirCaminho(vector<Pos> &caminho)
{
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            bool ehCaminho = false;
            unsigned int idx = 0;
            for (const auto &p : caminho)
            {
                if (p.x == i && p.y == j)
                {
                    ehCaminho = true;
                    break;
                }
                idx++;
            }

            if (ehCaminho && idx != 0 && idx != caminho.size() - 1)
            {
                cout << "* ";
            }
            else
            {
                if (estacao.getMatriz()[i][j]->getTipo() == 'E')
                {
                    cout << "A ";
                }
                else
                {
                    cout << estacao.getMatriz()[i][j]->getTipo() << " ";
                }
            }
        }
        cout << endl;
    }
    this->passos += caminho.size() - 1;
    cout << "Passos: " << caminho.size() - 1 << endl;
    cout << "Total de Passos: " << passos << endl;
}

bool RoboDeResgate::dentroDosLimites(int x, int y)
{
    int linhas = estacao.getLinhas();
    int colunas = estacao.getColunas();
    return x >= 0 && x < linhas && y >= 0 && y < colunas;
}

bool RoboDeResgate::podeAcessar(int x, int y)
{
    if (estacao.getMatriz()[x][y]->getTipo() == '#' || estacao.getMatriz()[x][y]->getTipo() == '~' || estacao.getMatriz()[x][y]->getTipo() == 'F')
    {
        return false;
    }
    return true;
}

int RoboDeResgate::iniciarResgate()
{
    int linhas = estacao.getLinhas();
    int colunas = estacao.getColunas();

    int PosIniX = this->posicaoInicialX;
    int PosIniY = this->posicaoInicialY;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    bool testeResgate = true;

    while (true)
    {
        vector<vector<bool> > visitado(linhas, vector<bool>(colunas, false));
        vector<vector<Pos> > pai(linhas, vector<Pos>(colunas, {-1, -1}));

        Pos destino = {-1, -1};
        Pos ultimoEncontrado;
        vector<Pos> caminho = {};
        queue<Pos> fila = {};

        fila.push({PosIniX, PosIniY});
        visitado[PosIniX][PosIniY] = true;

        while (!fila.empty())
        {
            Pos atual = fila.front();
            fila.pop();

            if (proximoAoFogo(atual.x, atual.y))
            {
                cout << "O robo encontrou fogo no caminho" << endl;
                buscarAstronautasNaoResgatados(); // attention
                return 0;
            }

            if (testeResgate && estacao.getMatriz()[atual.x][atual.y]->getTipo() == 'A' && !(ultimoEncontrado.x == atual.x && ultimoEncontrado.y == atual.y))
            {
                resgatarAstronauta(atual);
                cout << "Astronauta resgatado!" << endl;
                estacao.getMatriz()[atual.x][atual.y]->setTipo('E');
                ultimoEncontrado = atual;
                destino = atual;
                break;
            }

            if (!testeResgate && atual.x == PosIniX && atual.y == PosIniY)
            {
                buscarAstronautasNaoResgatados();
                return 0;
            }

            for (int k = 0; k < 4; k++)
            {
                int nova_linha = atual.x + dx[k];
                int nova_coluna = atual.y + dy[k];

                if (dentroDosLimites(nova_linha, nova_coluna) && !visitado[nova_linha][nova_coluna] && podeAcessar(nova_linha, nova_coluna) && !proximoAoFogo(nova_linha, nova_coluna))
                {
                    visitado[nova_linha][nova_coluna] = true;
                    pai[nova_linha][nova_coluna] = atual;
                    fila.push({nova_linha, nova_coluna});
                }
            }
        }

        if (destino.x == -1 && destino.y == -1)
        {
            cout << "Nenhum astronauta encontrado, retornando à base." << endl;
            if (testeResgate)
            {
                testeResgate = false;
                destino = {posicaoInicialX, posicaoInicialY};
            }
        }

        for (Pos p = destino; p.x != -1 && p.y != -1; p = pai[p.x][p.y])
        {
            caminho.push_back(p);
            // cout << "cu2" << endl;
        }
        reverse(caminho.begin(), caminho.end());
        imprimirCaminho(caminho);

        PosIniX = caminho.back().x;
        PosIniY = caminho.back().y;
    }
}