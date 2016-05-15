#include <iomanip>
#include "projeto.h"
//Fun��o que trata de mostrar o menu e, permitir que utilizador escolha o que pretende fazer
void menu(projeto *p){
	string opcao;
	int option;
	int novoVal;
	bool sair = false;
	do
	{
			
		system("Color 1F");
		cout << setw(68) << setfill('/') << "/" << setfill(' ') << endl;
		cout << "//  Escolha uma opcao:                                    " << setw(10) << "//" << endl;
		cout << "//  1 - Inserir dados dos projetos                        " << setw(10) << "//" << endl;
		cout << "//  2 - Listagem de projetos                              " << setw(10) << "//" << endl;
		cout << "//  3 - Inserir notas dos avaliadores                     " << setw(10) << "//" << endl;
		cout << "//  4 - Escrever no ficheiro de texto                     " << setw(10) << "//" << endl;
		cout << "//  5 - Procurar projeto por ID                           " << setw(10) << "//" << endl;
		cout << "//  6 - Procurar projeto por institui��o                  " << setw(10) << "//" << endl;
		cout << "//  7 - Carregar projetos a partir de um ficheiro de texto" << setw(10) << "//" << endl;
		cout << "//  8 - Ordena por Classifica��o Final                    " << setw(10) << "//" << endl;
		cout << "//  9 - Ordena por ordem alfab�tica                       " << setw(10) << "//" << endl;
		cout << "//  10 - Remo��o por id                                   " << setw(10) << "//" << endl;
		cout << "//  0 - Sair                                              " << setw(10) << "//" << endl;
		cout << setw(68) << setfill('/') << "/" << endl << setfill(' ');
		try
		{
			getline(cin, opcao);
			novoVal = stoi(opcao);
			if (to_string(novoVal).length() == opcao.length())
			{
				option = novoVal;


			cout << endl;

			switch (option)
			{
			case 1:
				inserir(&p);
				break;
			case 2:
				mostraProjetos(&p);
				break;
			case 3:
				atribuiClassificacoes(&p);
				break;
			case 4:
				escreveFicheiroTexto(&p);
				break;
			case 5:
				ListarPorId(&p);
				break;
			case 6:
				listaProInstProponente(&p);
				break;
			case 7:
				leituraDeTexto(&p);
				break;
			case 8:
				insertionSort(&p);
				break;
			case 9:
				insertionAlfabetico(&p);
				break;
			case 10:
				removerProjeto(&p);
				break;
			case 0:
				cout << "Escolheu a op��o sair. Adeus!" << endl;
				cout << "Por favor prima ENTER para sair da aplica��o.";
				libertaMemoria(&p);
				sair = true;
				break;
			default:
				cout << "Escolha uma op��o valida." << endl << endl;
			}
		}
			else{
				cout << "Introduza um n�mero!" << endl;
			}
		}
		catch (invalid_argument exp1)
		{
			cout << "O valor introduzido foi inv�lido. " << endl;
		}
		catch (out_of_range exp1)
		{
			cout << "O valor introduzido � muito grande ." << endl;
		}
	} while (!sair);
}

