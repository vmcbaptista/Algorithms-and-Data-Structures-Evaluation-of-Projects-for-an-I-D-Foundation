#include <locale.h>
#include "projeto.h"

int index = 0; //Inicio da variavel global que foi inicializada no header

int main()
{
	setlocale(LC_ALL, "Portuguese");
	projeto *proj = NULL;

	menu(proj);

	cin.sync();
	cin.get();
	return 0;
}
