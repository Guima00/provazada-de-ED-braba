// ############################################################################
// TVC 3 -- ESTRUTURA DE DADOS e LABORATORIO DE PROGRAMACAO II
// DATA: 02/07/2018
// PREENCHER ESTE CABECALHO COM SUAS INFORMACOES
// ALUNO:
// MATRICULA:
// ############################################################################
#include <iostream>
#include "ArvBinBusca.h"

using namespace std;

int main()
{
    cout << "TVC3 -- ESTRUTURA DE DADOS e LAB. DE PROG. II" << endl;
    cout << "FAVOR PREENCHER OS SEUS DADOS" << endl;
    cout << "Exemplo de ABB: " << endl;
    ArvBinBusca abb;
    // ARVORE DE TESTE
    abb.insere(40); abb.insere(15); abb.insere(10);
    abb.insere(20); abb.insere(19); abb.insere(35);
    abb.insere(75); abb.insere(50); abb.insere(45);
    abb.insere(60); abb.insere(66); abb.insere(68);
    abb.imprime();

    // SUGESTAO: TESTE COM OUTRAS ARVORES BINARIAS TAMBEM!

    // TESTE DA QUESTAO 1 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 1" << endl;
    int ni,nu;
    abb.contImpar1Filho(&ni,&nu);
    cout << ni << " " << nu << endl;
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 2 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 2" << endl;
    int su = abb.sucessor(66);
    cout << su << endl;
    cout << endl;
    // ------------------------------------------------------------------------

    // TESTE DA QUESTAO 3 -----------------------------------------------------
    cout << endl << "TESTE DA QUESTAO 3" << endl;
    abb.removeNo(40);
    abb.imprime();
    cout << endl;
    // ------------------------------------------------------------------------

    return 0;
}
