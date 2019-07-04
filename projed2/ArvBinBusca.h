#ifndef ARVBINBUSCA_H
#define ARVBINBUSCA_H
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "NoArv.h"

using namespace std;

class ArvBinBusca
{
public:
    ArvBinBusca();
    ~ArvBinBusca();
    void imprime();
    void insere(int x);
    bool vazia();
    int altura();

    // Questao 1  -------------------------------------------------------------
    void contImpar1Filho(int *nimpar, int *n1filho);

    // Questao 2  -------------------------------------------------------------
    int sucessor(int x);

    // Questao 3  -------------------------------------------------------------
    void removeNo(int ch);
    NoArv* auxRemove(NoArv* p, int ch);

private:
    NoArv *raiz;

    // funcoes auxiliares
    NoArv *auxInsere(NoArv *p, int x);
    void auxImprime(NoArv *p, int nivel);
    NoArv * removeFolha(NoArv *p);
    NoArv * removeNo1Filho(NoArv *p);
    int auxAltura(NoArv *p);
    NoArv * auxBusca(NoArv *p, int x);
    void auxcontimparfilho(int *nimpar, int *n1filho, NoArv*p);
};

#endif //ARVBINBUSCA_H
