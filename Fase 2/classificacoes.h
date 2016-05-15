#include <iostream>
#include <String>

// Se a estrutura  H_CLASS não estiver definida então o programa deve defini-la
#ifndef H_CLASS
#define H_CLASS

const int AVALIADORES = 3; // Numero de avaliadores.

struct classificacoes
{
	int originalidade;
	int qualidade;
	int idoneidade;
	int exequibilidade;
};

#endif