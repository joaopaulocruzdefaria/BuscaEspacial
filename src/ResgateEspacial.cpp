#include <iostream>
#include "ResgateEspacial.hpp"
#include "EstacaoEspacial.hpp"
#include "LeitorDeArquivo.hpp"
#include "RoboDeResgate.hpp"
#include "Astronauta.hpp"

using namespace std;

int main()
{
    for (int i = 1; i <= 10; i++)
    {
        cout << "Caminho "<< i << ": " << endl;
        string nomeArquivo = "./entradas/entrada" + to_string(i) + ".txt";
        string nomeArquivoS = "./saidas/saida" + to_string(i) + ".txt";
        EstacaoEspacial estacao;
        LeitorDeArquivo arquivo;
        RoboDeResgate roboDeResgate;
        arquivo.lerArquivo(nomeArquivo, estacao, roboDeResgate);
        roboDeResgate.iniciarResgate();
        arquivo.escreverArquivo(nomeArquivoS, roboDeResgate);
    }
    return 0;
}