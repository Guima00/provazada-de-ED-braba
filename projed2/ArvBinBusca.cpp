#include "ArvBinBusca.h"
#include <cmath>

// ----------------------------------------------------------------------------
//Q1
void ArvBinBusca::contImpar1Filho(int *nimpar, int *n1filho)
{
     *nimpar=0;
     *n1filho=0;
     auxcontimparfilho(nimpar,n1filho,raiz);
}
void ArvBinBusca::auxcontimparfilho(int *nimpar,int *n1filho, NoArv *p)
{
     if(p!=NULL)
     {
        if(p->getInfo()%2!=0)
        {
            *nimpar=(*nimpar)+1;
        }
        if((p->getEsq()==NULL && p->getDir()!=NULL)||(p->getEsq()!=NULL && p->getDir()==NULL))
        {
            *n1filho=(*n1filho)+1;
        }
        auxcontimparfilho(nimpar,n1filho,p->getEsq());
        auxcontimparfilho(nimpar,n1filho,p->getDir());
     }
}

//-Q1
// ----------------------------------------------------------------------------

// ----------------------------------------------------------------------------
//Q2

NoArv* ArvBinBusca::auxBusca(NoArv *p, int x)
{
    p=raiz;
    if(p==NULL)
    {
        return NULL;
    }
    else
    while(p->getInfo()!=x)
    {
         if(p->getInfo()<x)
         {
            p=p->getDir();
         }
         else
            p=p->getEsq();
    }
    return p;
}
int ArvBinBusca::sucessor(int x)
{
    NoArv*p;
    p=auxBusca(p,x);
    if(p==NULL || p->getDir()==NULL)
    {
        return -1;
    }
    else
        return p->getDir()->getInfo();
}
//-Q2

// ----------------------------------------------------------------------------
//Q3
NoArv* ArvBinBusca::auxRemove(NoArv* p, int ch)
{
    if(p == NULL)
        return NULL;
    else if(ch < p->getInfo())
        p->setEsq(auxRemove(p->getEsq(), ch));
    else if(ch > p->getInfo())
        p->setDir(auxRemove(p->getDir(), ch));
    else //ch == p->getInfo(), achou nó a ser removido
    {
        if(p->getEsq() == NULL && p->getDir() == NULL)
            p = removeFolha(p);
        else if((p->getEsq() == NULL) || (p->getDir() == NULL))
            p = removeNo1Filho(p);
        else
        {
            //Implemente aqui sua solucao

        }
    }
    return p;
}
//-Q3

// ----------------------------------------------------------------------------
NoArv * ArvBinBusca::removeFolha(NoArv *p)
{
    delete p;
    return NULL;
}

NoArv * ArvBinBusca::removeNo1Filho(NoArv *p)
{
    NoArv *aux;
    if(p->getEsq() == NULL)
        aux = p->getDir(); //filho único é da direita
    else
        aux = p->getEsq(); //filho único é da esquerda
    delete p;
    return aux;
}

// ----------------------------------------------------------------------------
// Restante da classe ArvBinBusca
// ----------------------------------------------------------------------------

void ArvBinBusca::removeNo(int ch)
{
    raiz = auxRemove(raiz,ch);
}

ArvBinBusca::ArvBinBusca()
{
    raiz = NULL;
}

ArvBinBusca::~ArvBinBusca()
{
    // destrutor vazio (só para avaliação)
}

bool ArvBinBusca::vazia()
{
    return raiz == NULL;
}

void ArvBinBusca::insere(int x)
{
    NoArv *p = auxInsere(raiz, x);
    if(raiz == NULL)
        raiz = p;
}

NoArv* ArvBinBusca::auxInsere(NoArv *p, int x)
{
    if(p == NULL)
    {
        p = new NoArv();
        p->setInfo(x);
        p->setEsq(NULL);
        p->setDir(NULL);
    }
    else if(x < p->getInfo())
        p->setEsq(auxInsere(p->getEsq(), x));
    else
        p->setDir(auxInsere(p->getDir(), x));
    return p;
}

void ArvBinBusca::imprime()
{
    auxImprime(raiz, 0);
}

void ArvBinBusca::auxImprime(NoArv *p, int nivel)
{
    if(p != NULL)
    {
        cout << "(" << nivel << ")";
        for(int i = 1; i <= nivel; i++)
            cout << "--";
        cout << p->getInfo() << endl;
        auxImprime(p->getEsq(), nivel+1);
        auxImprime(p->getDir(), nivel+1);
    }
}
