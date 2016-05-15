#include "projeto.h"

// Função que associa a cada letra de avaliação o respetivo valor inteiro
int associaClassificacao(char escolha){
	if (escolha == 'N' || escolha == 'n')
	{
		return 1;
	}
	else if (escolha == 'M' || escolha == 'm')
	{
		return 2;
	}
	else if (escolha == 'S' || escolha == 's')
	{
		return 3;
	}
	else if (escolha == 'B' || escolha == 'b')
	{
		return 4;
	}
	else if (escolha == 'E' || escolha == 'e')
	{
		return 5;
	}
}

// Esta função pede e atribui as classificações aos projetos
void atribuiClassificacoes(projeto **p)
{
	string numAvaliadorS;
	string valInput;
	int id;  //Armazena o id que o utilizador escolher;
	int numAvaliador; // Indica qual o avaliador que está a avaliar o projeton no momento
	string escolha; // Armazena a letra correspondente à avaliação
	projeto *aux = *p;
	bool encontrouProjeto = false;
	bool exp = false;
	bool excep2 = false;

	do{
		try{
			cout << "Introduza o id do projeto que deseja classificar: " << endl;
			getline(cin, valInput);
			// Converte a string introduzida caso sejam números para inteiros, caso seja uma string lança exceção
			int newVal = stoi(valInput);

			if (to_string(newVal).length() == valInput.length())
			{
				id = newVal;
				exp = false;
			}
			//Significa que introduziu uma string com carateres tipo numero antes das letras.
			else
			{
				cout << "Introduziu um argumento inválido." << endl;
				exp = true;
			}
		}
		
		catch (invalid_argument exp1)
		{
			cout << "Introduziu um argumento inválido." << endl;
			exp = true;
		}
		catch (out_of_range excep)
		{
			cout << "Introduziu um número muito grande!" << endl;
			exp = true;
		}
	} while (exp);

	if (id > index - 1 || id < 0)
	{
		cout << "Não existe nenhum projeto com esse id." << endl;
	}
	else
	{
		do{
			try{
				do
				{
					cout << "Introduza o seu número de avaliador:" << endl;
					getline(cin, numAvaliadorS);
					numAvaliador = stoi(numAvaliadorS);
					excep2 = false;
					if (numAvaliador < 1 || numAvaliador > 3)
					{
						cout << "O número introduzido não é valido!" << endl;
					}
				} while (numAvaliador < 1 || numAvaliador > 3);
			}
			catch (invalid_argument exp2)
			{
				cout << "Introduziu um valor inválido." << endl;
				excep2 = true;
			}
			catch (out_of_range excep)
			{
				cout << "Introduziu um número muito grande!" << endl;
				excep2 = true;
			}
		} while (excep2);


		while (aux != NULL){
			// Verifica se o id de projeto existe.
			if (aux->id == id)
			{
				if (aux->verificaAvaliacao[numAvaliador - 1])
				{
					cout << "Não pode avaliar este projeto uma vez que já procedeu à sua avaliação!" << endl;
				}
				else
				{
					do{
						cout << "Introduza a nota respetiva ao parametro Originalidade: " << endl;
						getline(cin, escolha);
						if (escolha.length() > 1 || (escolha[0] != 'N' && escolha[0] != 'n' && escolha[0] != 'M' && escolha[0] != 'm' && escolha[0] != 'S' && escolha[0] != 's' && escolha[0] != 'B' && escolha[0] != 'b' && escolha[0] != 'E' && escolha[0] != 'e'))
						{
							cout << "A nota deverá ser introduzida utilizado as letras N, M, S, B ou E." << endl;
							cout << "ou alternativamente através de n, m, s, b ou e." << endl << endl;
						}
					} while (escolha.length() > 1 || (escolha[0] != 'N' && escolha[0] != 'n' && escolha[0] != 'M' && escolha[0] != 'm' && escolha[0] != 'S' && escolha[0] != 's' && escolha[0] != 'B' && escolha[0] != 'b' && escolha[0] != 'E' && escolha[0] != 'e'));

					aux->notas[numAvaliador - 1].originalidade = associaClassificacao(escolha[0]);


					do{
						cout << "Introduza a nota respetiva ao parametro Qualidade da proposta: " << endl;
						getline(cin, escolha);
						if (escolha.length() > 1 || (escolha[0] != 'N' && escolha[0] != 'n' && escolha[0] != 'M' && escolha[0] != 'm' && escolha[0] != 'S' && escolha[0] != 's' && escolha[0] != 'B' && escolha[0] != 'b' && escolha[0] != 'E' && escolha[0] != 'e'))
						{
							cout << "A nota deverá ser introduzida utilizado as letras N, M, S, B ou E." << endl;
							cout << "ou alternativamente através de n, m, s, b ou e." << endl << endl;
						}
					} while (escolha.length() > 1 || (escolha[0] != 'N' && escolha[0] != 'n' && escolha[0] != 'M' && escolha[0] != 'm' && escolha[0] != 'S' && escolha[0] != 's' && escolha[0] != 'B' && escolha[0] != 'b' && escolha[0] != 'E' && escolha[0] != 'e'));
					aux->notas[numAvaliador - 1].qualidade = associaClassificacao(escolha[0]);


					do{
						cout << "Introduza a nota respetiva ao parametro Idoneidade da equipa: " << endl;
						getline(cin, escolha);
						if (escolha.length() > 1 || (escolha[0] != 'N' && escolha[0] != 'n' && escolha[0] != 'M' && escolha[0] != 'm' && escolha[0] != 'S' && escolha[0] != 's' && escolha[0] != 'B' && escolha[0] != 'b' && escolha[0] != 'E' && escolha[0] != 'e'))
						{
							cout << "A nota deverá ser introduzida utilizado as letras N, M, S, B ou E." << endl;
							cout << "ou alternativamente através de n, m, s, b ou e." << endl << endl;
						}
					} while ((escolha.length() > 1) || (escolha[0] != 'N' && escolha[0] != 'n' && escolha[0] != 'M' && escolha[0] != 'm' && escolha[0] != 'S' && escolha[0] != 's' && escolha[0] != 'B' && escolha[0] != 'b' && escolha[0] != 'E' && escolha[0] != 'e'));
					aux->notas[numAvaliador - 1].idoneidade = associaClassificacao(escolha[0]);


					do{
						cout << "Introduza a nota respetiva ao parametro Exequibilidade: " << endl;
						getline(cin, escolha);
						if (escolha.length() > 1 || (escolha[0] != 'N' && escolha[0] != 'n' && escolha[0] != 'M' && escolha[0] != 'm' && escolha[0] != 'S' && escolha[0] != 's' && escolha[0] != 'B' && escolha[0] != 'b' && escolha[0] != 'E' && escolha[0] != 'e'))
						{
							cout << "A nota deverá ser introduzida utilizado as letras N, M, S, B ou E." << endl;
							cout << "ou alternativamente através de n, m, s, b ou e." << endl << endl;
						}
					} while (escolha.length() > 1 || (escolha[0] != 'N' && escolha[0] != 'n' && escolha[0] != 'M' && escolha[0] != 'm' && escolha[0] != 'S' && escolha[0] != 's' && escolha[0] != 'B' && escolha[0] != 'b' && escolha[0] != 'E' && escolha[0] != 'e'));
					aux->notas[numAvaliador - 1].exequibilidade = associaClassificacao(escolha[0]);

					cout << endl; //Linha a separar.
					cout << "O jurado número " + numAvaliadorS;// +" terminou a avaliação do projeto que tem o id: " + aux->id;
					cout << " terminou a avaliação do projeto cujo nome é:  " << aux->titulo << endl;
					//cout << " e que tem como nome: " + aux->titulo + "." << endl;
					aux->verificaAvaliacao[numAvaliador - 1] = true;
					// Atualiza a classificação final com a nova avaliação
					aux->classFinal = classificacaoFinal(aux->notas);
				}
				break;
			}
			aux = aux->next;
		}
	}
}

//Atribui subsidio mediante a classificação dos juris.
double atribuiSubsidio(projeto **p){
	double res = 0.0;
	int classificacao = (*p)->classFinal;
	double finSol = (*p)->custoTotal;
	switch (classificacao)
	{
	case 3:
		res = 0.3 * finSol;
		break;
	case 4:
		res = 0.75 * finSol;
		break;
	case 5:
		res = 1.00 * finSol;
		break;
	default:
		res = 0.0 * finSol;
		break;
	}
	(*p)->subsidio = res;
	return res;
}

//cálcula o custo total da aplicação do projeto
double calcCustoTotal(projeto **p)
{
	(*p)->custoTotal = (*p)->despesas.compraEquip + (*p)->despesas.pagBolsas + (*p)->despesas.consumiveisDesp + (*p)->despesas.consultoresDesp + (*p)->despesas.deslocacoes + (*p)->despesas.gastosGerais;
	return (*p)->custoTotal;
}

// Função que permite ao utilizador inserir projetos através da consola
void inserir(projeto **p)
{

	try{

		projeto *proj = new projeto();
		string input;
		bool falhou = false;
		string option;
		int novoVal;
		do{
			cout << "Deseja prosseguir com a inserção de um novo Projeto  S/N" << endl;
			getline(cin, option);
			// Se a string tiver um tamanho maior um. Então apresenta-se uma mensageem de erro
			if (option.length() > 1 || (option[0] != 'N' && option[0] != 'S'))
			{
				cout << "Introduza uma opção válida." << endl << endl;
			}

		} while ((option[0] != 'N' && option[0] != 'S') || option.length() > 1);

		if (option[0] == 'S')
		{
			proj->id = index;

			cout << "Introduza o título do projeto: ";
			getline(cin, proj->titulo);

			cout << "Introduza o nome da instituição: ";
			getline(cin, proj->instituiçãoProv);

			cout << "Introduza o nome do investigador: ";
			getline(cin, proj->nomeInvestigador);



			do{
				cout << "Introduza a duracao do projeto em número de meses:";
				try{
					getline(cin, input);
					novoVal = stoi(input);
					//toString transforma o numero numa string.
					if (to_string(novoVal).length() == input.length())
					{
						proj->duracao = novoVal;
						falhou = false;
					}
					//Significa que introduziu uma string com carateres tipo numero antes das letras.
					else
					{
						falhou = true;
					}
				}
				catch (invalid_argument e){
					falhou = true;
				}
				catch (out_of_range exp1)
				{
					cout << "O valor introduzido é muito grande ." << endl;
					falhou = true;
				}
			} while (falhou);

			cout << "Introduza até 5 palavras chave que descrevem o seu projeto: " << endl;
			string op;
			int i = 0;
			do{
				cout << "\nDeseja inserir palavra  S/N  ";
				getline(cin, op);

				if (op.length() > 1 || (op[0] != 'N' && op[0] != 'S'))
				{
					cout << "\nIntroduza uma opção válida." << endl;
				}
				else{
					if (op[0] == 'S'){
						cout << "Palavra-chave " << i + 1 << ": ";
						getline(cin, proj->vectorPalavrasChave[i]);
						i++;
					}
					else if (op[0] == 'N'){
						break;
					}
					else{
						cout << "Introduza uma opção válida." << endl << endl;
					}
				}

			} while (((option[0] != 'N' && option[0] != 'S') || op.length() > 1) || i < 5);



			// DESPESAS COM EQUIP
			do{
				cout << "Compra de equipamentos: ";
				try{
					getline(cin, input);
					novoVal = stoi(input);

					if (to_string(novoVal).length() == input.length())
					{
						proj->despesas.compraEquip = novoVal;
						falhou = false;
					}
					//Significa que introduziu uma string com carateres tipo numero antes das letras.
					else
					{
						cout << "Introduza um número!" << endl;
						falhou = true;
					}
				}
				catch (invalid_argument e){
					cout << "Introduza um número!" << endl;
					falhou = true;
				}
				catch (out_of_range exp1)
				{
					cout << "O valor introduzido é muito grande ." << endl;
					falhou = true;
				}
			} while (falhou);

			// Despesas PAG BOLSA
			do{
				cout << "Pagamento de bolsas: " << endl;
				try{
					getline(cin, input);
					novoVal = stoi(input);

					if (to_string(novoVal).length() == input.length())
					{
						proj->despesas.pagBolsas = novoVal;
						falhou = false;
					}
					//Significa que introduziu uma string com carateres tipo numero antes das letras.
					else
					{
						cout << "Introduza um número!" << endl;
						falhou = true;
					}
				}
				catch (invalid_argument e){
					cout << "Introduza um número!" << endl;
					falhou = true;
				}
				catch (out_of_range exp1)
				{
					cout << "O valor introduzido é muito grande ." << endl;
					falhou = true;
				}
			} while (falhou);

			// Despesas consumiveis
			do{
				cout << "Despesas de consumiveis: ";
				try{
					getline(cin, input);
					novoVal = stoi(input);

					if (to_string(novoVal).length() == input.length())
					{
						proj->despesas.consumiveisDesp = novoVal;
						falhou = false;
					}
					//Significa que introduziu uma string com carateres tipo numero antes das letras.
					else
					{
						cout << "Introduza um número!" << endl;
						falhou = true;
					}
				}
				catch (invalid_argument e){
					cout << "Introduza um número!" << endl;
					falhou = true;
				}
				catch (out_of_range exp1)
				{
					cout << "O valor introduzido é muito grande ." << endl;
					falhou = true;
				}
			} while (falhou);

			//Despesas consultores

			do{
				cout << "Despesas de consultores: ";
				try{
					getline(cin, input);
					novoVal = stoi(input);

					if (to_string(novoVal).length() == input.length())
					{
						proj->despesas.consultoresDesp = novoVal;
						falhou = false;
					}
					//Significa que introduziu uma string com carateres tipo numero antes das letras.
					else
					{
						cout << "Introduza um número!" << endl;
						falhou = true;
					}
				}
				catch (invalid_argument e){
					cout << "Introduza um número!" << endl;
					falhou = true;
				}
				catch (out_of_range exp1)
				{
					cout << "O valor introduzido é muito grande ." << endl;
					falhou = true;
				}
			} while (falhou);

			// Desp Desloc

			do{
				cout << "Despesas com deslocacoes: ";
				try{
					getline(cin, input);
					novoVal = stoi(input);

					if (to_string(novoVal).length() == input.length())
					{
						proj->despesas.deslocacoes = novoVal;
						falhou = false;
					}
					//Significa que introduziu uma string com carateres tipo numero antes das letras.
					else
					{
						cout << "Introduza um número!" << endl;
						falhou = true;
					}
				}
				catch (invalid_argument e){
					cout << "Introduza um número!" << endl;
					falhou = true;
				}
				catch (out_of_range exp1)
				{
					cout << "O valor introduzido é muito grande ." << endl;
					falhou = true;
				}
			} while (falhou);

			//Gastos gerais
			cout << "Insira os gastos gerais: ";
			do{
				try{
					getline(cin, input);
					novoVal = stoi(input);

					if (to_string(novoVal).length() == input.length())
					{
						proj->despesas.gastosGerais = novoVal;
						falhou = false;
					}
					//Significa que introduziu uma string com carateres tipo numero antes das letras.
					else
					{
						cout << "Introduza um número!" << endl;
						falhou = true;
					}
				}
				catch (invalid_argument e){
					cout << "Introduza um número!" << endl;
					falhou = true;
				}
				catch (out_of_range exp1)
				{
					cout << "O valor introduzido é muito grande ." << endl;
					falhou = true;
				}
			} while (falhou);


			// Coloca no projeto o custo total deste
			proj->custoTotal = calcCustoTotal(&proj);

			// Coloca o vetor de booleanos a falso pois o projeto ainda não foi avaliado
			for (int i = 0; i < 3; i++)
			{
				proj->verificaAvaliacao[i] = false;
			}

			//Devido as ordenações para não ocorrerem erros.
			proj->classFinal = -1;

			proj->next = *p;
			*p = proj;

			index++;
		}
	}
	catch (bad_alloc e){
		cout << "Lamentamos mas não foi possível alocar memória para o projeto." << endl;
	}
}

// Função que remove projetos da lista ligada.
void removerProjeto(projeto **p)
{
	string valInput;
	int id;

	if (*p != NULL){
		string option;
		bool checkExist = false;					// Variavél para verificar se o projeto foi ou não encontrado.
		projeto *anterior = *p;
		projeto *avançado = anterior->next;
		bool continues = false;
		do{
			try{
				cout << "Introduza o id do projeto que deseja remover: " << endl;
				getline(cin, valInput);
				// Converte a string introduzida caso sejam números para inteiros, caso seja uma string lança exceção
				id = stoi(valInput);
				if (to_string(id).length() == valInput.length())
				{
					continues = false;
				}
				else
				{
					cout << "Introduza um número: " << endl;
					continues = true;
				}
			}
			catch (out_of_range exp1)
			{
				cout << "Introduza um número: " << endl;
				continues = true;
			}
			catch (invalid_argument exp1)
			{
				cout << "Introduza um número: " << endl;
				continues = true;
			}
		} while (continues);


		while (avançado != NULL)
		{
			if (avançado->id == id)
			{
				cout << "O projeto " + avançado->titulo + " foi encontrado. " << endl;
				do{

					cout << "Deseja continuar com a sua remoção? S/N" << endl;
					getline(cin, option);
					if (option.length() > 1 || (option[0] != 'N' && option[0] != 'S'))
					{
						cout << "Introduza uma opção válida" << endl;
					}

				} while ((option[0] != 'N' && option[0] != 'S') || option.length() > 1);

				if (option[0] == 'S')
				{
					checkExist = true;
					anterior->next = avançado->next;
					delete avançado;
					cout << "O projeto foi removido." << endl;
					break;
				}
				else
				{
					cout << "A remoção do projeto " + avançado->titulo + " foi cancelada." << endl;
					checkExist = true;
				}
			}
			avançado = avançado->next;
			anterior = anterior->next;
		}
		if (checkExist == false)
		{
			cout << "Não foram encontrados projetos." << endl;
		}
	}
	else
	{
		cout << "Não existem projetos." << endl;
	}

}

// Calcula a classificação final de cada projeto
int classificacaoFinal(classificacoes *vetor)
{
	int soma = 0;
	int media[AVALIADORES]; // Cria um vetor que armazena a média de classificações de cada avaliador
	int mediaFinal = 0;
	int somaMedia = 0;
	// Calcula a média da classificacao atribuida por cada avaliador
	for (int i = 0; i < AVALIADORES; i++)
	{
		soma = vetor[i].exequibilidade + vetor[i].idoneidade + vetor[i].originalidade + vetor[i].qualidade;
		media[i] = soma / 4;
	}


	// Soma as médias dos 3 classificadores
	for (int i = 0; i < AVALIADORES; i++)
	{
		somaMedia = somaMedia + media[i];

	}
	mediaFinal = somaMedia / AVALIADORES;
	return mediaFinal;
}

//Destroi todos os nodos que se encontram presentes na memoria quando se fecha o programa
void libertaMemoria(projeto **p)
{
	if (*p == NULL)
	{
	}
	else
	{
		projeto * aux = *p;
		projeto * next = aux->next;
		while (next != NULL)
		{
			delete aux;
			aux = next;
			next = next->next;
		}
		*p = NULL;
	}
}