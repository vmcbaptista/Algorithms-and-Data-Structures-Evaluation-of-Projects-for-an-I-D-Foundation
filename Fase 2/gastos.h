#include <iostream>
#include <String>

const int MAXLENTAG = 5; // isto vai dar o tamanho do vetor que recebe as palavras chave que definem o projeto, coloquei no header poque nesta fase inicial � necess�rio para testes na main e no cuto.cpp para preencher
// Se a estrutura  H_GASTOS n�o estiver definida ent�o o programa deve defini-la

#ifndef H_GASTOS
#define H_GASTOS
struct gastos
{
	// S�o despesas em euros 
	double compraEquip;
	double pagBolsas;
	double consumiveisDesp;
	double consultoresDesp;
	double deslocacoes;
	double gastosGerais;
};
#endif
