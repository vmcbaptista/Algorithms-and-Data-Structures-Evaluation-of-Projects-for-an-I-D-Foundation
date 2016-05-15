#include <iostream>
#include <string>
#include "gastos.h"
#include "classificacoes.h"

using namespace std;

#ifndef H_PROJETO
#define H_PROJETO

extern int index;  //Variável global que pode ser usada em outros cpp's (definida na main).

struct projeto
{
	int id;
	string titulo;
	string instituiçãoProv;
	string nomeInvestigador;
	int duracao;
	string vectorPalavrasChave[MAXLENTAG];
	gastos despesas;
	double custoTotal;
	classificacoes notas[AVALIADORES];
	int classFinal;
	double subsidio;
	projeto *next;
	bool verificaAvaliacao[AVALIADORES];
};

void novoProjeto(projeto* proj);
void inserir(projeto **proj);
void mostraProjetos(projeto **proj);
void menu(projeto *p);
double atribuiSubsidio(projeto **p);
int classificacaoFinal(classificacoes *vetor);
double calcCustoTotal(projeto **p);
void atribuiClassificacoes(projeto **p);
void escreveFicheiroTexto(projeto **p);
void ListarPorId(projeto **p);
void listaProInstProponente(projeto **p);
void leituraDeTexto(projeto **p);
void insertionSort(projeto ** zz);
void insertionAlfabetico(projeto ** zz);
void removerProjeto(projeto **p);
void libertaMemoria(projeto **p);
#endif