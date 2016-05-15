#include "Projeto.h"

// Função responsável por listar projetos por instituição proponente
// Esta função realiza uma procura pela lista ligada à procura dos projetos com a instiução proponente pedida ao utilizador e imprim todos os encontrados na consola.
void listaProInstProponente(projeto **p)
{
	projeto * aux = *p;
	string procuraInstProp;
	bool encontrado = false;
	int contador = 0;
	cout << "Insira o nome da instituição proponente: ";
	getline(cin, procuraInstProp);

	cout << "Projetos encontrados: " << endl;
	while (aux!=NULL)
	{
		string intitProp = aux->instituiçãoProv;
		if ( intitProp.compare(procuraInstProp) == 0)
		{
			contador++;
			cout << endl;
			cout << "Id: " << aux->id << endl;
			cout << "Nome do projeto: " << aux->titulo << endl;
			cout << "Instituiçao proponente do projeto: " << aux->instituiçãoProv << endl;
			cout << "Nome do Investigador: " << aux->nomeInvestigador << endl;
			cout << "Duracao do projeto: " << aux->duracao << endl;
			cout << "Custo total: " << aux->custoTotal << endl;
		
			if (aux->verificaAvaliacao[0] && aux->verificaAvaliacao[1] && aux->verificaAvaliacao[2])
			{
				cout << "Classificacao Final : " << aux->classFinal << endl;
				atribuiSubsidio(&aux);
				cout << "Subsidio : " << aux->subsidio << endl << endl;
			}
			else
			{
				cout << "O projeto não foi avaliado avaliado" << endl;
				for (int i = 0; i < AVALIADORES; i++)
				{
					if (aux->verificaAvaliacao[i])
					{
						cout << "O júri " << i + 1 << " já atribuiu a sua avaliação. " << endl;
					}
					else
					{
						cout << "O júri " << i + 1 << " ainda não atribuiu a sua avaliação. " << endl;
					}
				}
			}
			cout << endl;
			encontrado = true;
			if ((contador - 3 + 1) % 3 == 0){ //Faz apresentar 3 projetos de cada vez
				cout << "Prima ENTER para a passar ao próximo conjunto de projetos ->";
				while (cin.get() != '\n'); // Aguarda EMTER
				cout << endl;
			}
		}
		aux = aux->next;
		
	}
	if (!encontrado){
		cout << "Não foi encontrado nenhum projeto da instituição que procurou." << endl;
	}
}

// Função responsável por listar projetos por id
// Percorre a lista ligada à procura do projeto com o id inserido pelo utilizador e imprime-o na consola caso exista
void ListarPorId(projeto **p)
{
	bool falhou = false;
	bool foundProj = false;
	int opp;
	string valInput;
	projeto *proj = *p;

	do{
		try{
			cout << "Introduza o id do projeto que deseja visualizar" << endl;
			getline(cin, valInput);
			opp = stoi(valInput);
			falhou = false;
		}
		catch (invalid_argument e){
			cout << "O id introduzido não é valido!";
			falhou = true;
		}
	} while (falhou);


	while (proj != NULL)
	{

		if (opp == proj->id)
		{
			cout << "O projeto encontrado: " << endl << endl;
			cout << "Id: " << proj->id << endl;
			cout << "Instituição Proveniente: " << proj->instituiçãoProv << endl;
			cout << "Título: " << proj->titulo << endl;
			cout << "Nome do Investigador: " << proj->nomeInvestigador << endl;
			cout << "Duracão : " << proj->duracao << endl;

			cout << "Palavras Chave: :" << endl;
			cout << proj->vectorPalavrasChave[0] << endl;
			cout << proj->vectorPalavrasChave[1] << endl;
			cout << proj->vectorPalavrasChave[2] << endl;
			cout << proj->vectorPalavrasChave[3] << endl;
			cout << proj->vectorPalavrasChave[4] << endl;

			cout << "Despesas Compra Equipamento : " << proj->despesas.compraEquip << endl;
			cout << "Despesas Consultores : " << proj->despesas.consultoresDesp << endl;
			cout << "Despesas Consumiveis: " << proj->despesas.consumiveisDesp << endl;
			cout << "Despesas Deslocacoes: " << proj->despesas.deslocacoes << endl;
			cout << "Despesas Gastos Gerais: " << proj->despesas.gastosGerais << endl;
			cout << "Despesa Pagar Bolsas: " << proj->despesas.pagBolsas << endl;
			// Calcula os vários subsidios dos projetos, custo e atribuições nas funcções invocadas abaixo.
			calcCustoTotal(&proj);
			cout << "Custo Total: " << proj->custoTotal << endl;


			if (proj->verificaAvaliacao[0] && proj->verificaAvaliacao[1] && proj->verificaAvaliacao[2])
			{
				cout << "Classificacao Final : " << proj->classFinal << endl;
				atribuiSubsidio(&proj);
				cout << "Subsidio : " << proj->subsidio << endl << endl;
			}
			else
			{
				cout << "O projeto não foi avaliado avaliado" << endl;
				for (int i = 0; i < AVALIADORES; i++){
					if (proj->verificaAvaliacao[i])
					{
						cout << "O júri " << i + 1 << " já atribuiu a sua avaliação. " << endl;
					}
					else
					{
						cout << "O júri " << i + 1 << " ainda não atribuiu a sua avaliação. " << endl;
					}
				}
			}
			foundProj = true;
			break;
		}
		proj = proj->next;
	}

	if (foundProj == false)
	{
		cout << "O projeto não foi encontrado." << endl;
	}
}

// Função que percorre toda a lista ligada e imprime na consola todos os projetos inseridos
void mostraProjetos(projeto **p)
{
	int contador = 0;

	if (*p == NULL){
		cout << "ERRO!" << endl;
		cout << "Não é possível listar projetos uma vez que ainda não introduziu nenhum projeto!" << endl;
	}
	else{
		projeto * aux = *p;
		while (aux != NULL){
			contador++;
			cout << "Id: " << aux->id << endl;
			cout << "Nome do projeto: " << aux->titulo << endl;
			cout << "Instituiçao proponente do projeto: " << aux->instituiçãoProv << endl;
			cout << "Nome do Investigador: " << aux->nomeInvestigador << endl;
			cout << "Duracao do projeto: " << aux->duracao << endl;

			cout << "Palavras-chave: ";
			for (int i = 0; i < MAXLENTAG; i++)
			{
				cout << aux->vectorPalavrasChave[i] << "  ";
			}
			cout << endl;
			cout << "Compra de equipamento: " << aux->despesas.compraEquip << endl;
			cout << "Pagamento de bolsas: " << aux->despesas.pagBolsas << endl;
			cout << "Despesas com consumiveis: " << aux->despesas.consumiveisDesp << endl;
			cout << "Despesas com consutores: " << aux->despesas.consultoresDesp << endl;
			cout << "Despesas com deslocacoes: " << aux->despesas.deslocacoes << endl;
			cout << "Gastos gerais: " << aux->despesas.gastosGerais << endl;

			cout << "Custo total: " << aux->custoTotal << endl;

			if (aux->verificaAvaliacao[0] && aux->verificaAvaliacao[1] && aux->verificaAvaliacao[2])
			{
				cout << "Classificaçao final do projeto: " << aux->classFinal << endl;
				cout << "Subsidio: " << atribuiSubsidio(&aux) << endl;
			}
			else
			{
				cout << "O projeto não foi avaliado." << endl;
				for (int i = 0; i < AVALIADORES; i++){
					if (aux->verificaAvaliacao[i])
					{
						cout << "O júri " << i + 1 << " já atribuiu a sua avaliação. " << endl;
					}
					else
					{
						cout << "O júri " << i + 1 << " ainda não atribuiu a sua avaliação. " << endl;
					}
				}
			}
			cout << "---------------------------------------" << endl;
			aux = aux->next;
			if ((contador - 3 + 1) % 3 == 0){ //Faz apresentar 3 projetos de cada vez
				cout << "Prima ENTER para a passar ao próximo conjunto de projetos ->";
				while (cin.get() != '\n'); // Aguarda EMTER
				cout << endl;
			}
		}
	}
}

// Função que ordena os projetos por ordem alfabética. Baseado no Insertion Sort
void insertionAlfabetico(projeto ** zz) {
	// Cria um apontador para a lista
	projeto * pList = *zz;

	if (pList == NULL || pList->next == NULL)
	{
		cout << "Não existem projetos." << endl;
	}
	else
	{
		// Criação do apontador que será a cabeça da nova lista ordenada.
		projeto * cabeca = NULL;

		//Equanto a apontador da lista orginal n estiver a null executa
		while (pList != NULL)
		{
			// Cria um apontador para o primeiro elementa da lista original
			projeto * current = pList;
			// passa ao proximo elemento da lista
			pList = pList->next;
			// Se o elemnto que estou a analisar é maior que o elemento que está na cabeça da lista orginal
			//ou a cabeça dor iguala NULL então coloca na cabela da lista o 
			if (cabeca == NULL || (current->titulo).compare(cabeca->titulo)<0) {
				// Coloca na cabeça de lista ordenada o elemento current
				current->next = cabeca;
				cabeca = current;
			}
			else {
				// Caso a cabeça n seja NULL significa que existem elementos pelo que é necessário proceder de outra forma
				projeto * p = cabeca;
				while (p != NULL)
				{
					if (p->next == NULL || // last element of the sorted list
						(current->titulo).compare(p->next->titulo) <0) // middle of the list
					{
						// insert into middle of the sorted list or as the last element
						current->next = p->next;
						p->next = current;
						break; // done
					}
					p = p->next;
				}
			}
		}
		*zz = cabeca;
		cout << "A lista foi ordenada por ordem  decrescente de Classificação Final." << endl;
	}
}

// Função que ordena os projetos por ordem de classificação. Baseado no Insertion Sort
void insertionSort(projeto ** zz) {
	// Cria um apontador para a lista
	projeto * pList = *zz;

	if (pList == NULL || pList->next == NULL)				// Se a lista tiver menos de 2 elementos não há neceessidade de ordenar.
	{
		cout << "Não existem projetos, ou existe só um projeto." << endl;
	}
	else
	{
		// Criação do apontador que será a cabeça da nova lista ordenada.
		projeto * cabeca = NULL;


		while (pList != NULL) // Verifica se o apontador da lista original está a NULL se estiver já se chegou ao fim. 
		{
			// Cria um apontador para o projeto que vai ser ordenado.
			projeto * atual = pList;
			// passa ao elemnto seguinte da lista atual.
			pList = pList->next;

			// Se a cabeça estiver a NULL então o primeiro elemento da lista será o primeiro da lista original
			// Se não então ocorre a necessidade de se verificar se a classificação do projeto a analiar 
			//é maior ou menor do que o que se encontra na cabeça da lista ordenada.
			if (cabeca == NULL || atual->classFinal > cabeca->classFinal) {
				//coloca o projeto na lista ordenada.
				atual->next = cabeca;
				cabeca = atual;
			}
			else
			{
				// Caso a cabeça da lista não seja null e 
				// a classificação do projeto que esta analisado é maior do que a classificação do projeto que se encontra na cabeça
				// da lista ordenada.
				projeto * p = cabeca;
				// Percorre a lista ordenada até encontrar um prjeto cuja classificçãi seja superior a do projeto qe esta a ser avaliado.
				while (p != NULL)
				{
					if (p->next == NULL || atual->classFinal > p->next->classFinal)
					{
						// Efetua a troca e para 
						atual->next = p->next;
						p->next = atual;
						break;
					}
					// Analida o próximo projeto da lista ordenada.
					p = p->next;
				}
			}//-- Fim if
		}//--Fim do  while
		*zz = cabeca;
		cout << "A lista foi ordenada por ordem Alfabética." << endl;
	}
}