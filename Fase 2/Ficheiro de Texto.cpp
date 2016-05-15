#include <fstream>
#include <string>
#include "projeto.h"

// Fun��o que l� os dados de projetos a partir de um ficheiro de texto.
void leituraDeTexto(projeto **p){
	string str;
	string linhaBranco;
	string option;
	string filename = "dados.txt"; // Var�vel que possui o nome do ficheiro de texto onde est�a info a ser carregada
	bool falhou = false; //Var�avel que controla a exite�ncia ou n�o de erros ao longo do carregamento

	do{
		cout << "Deseja prosseguir com o carregamento de dados a partir do ficheiro \""<< filename << "\" S/N" << endl;
		getline(cin, option);
		// Se a string tiver um tamanho maior um. Ent�o apresenta-se uma mensageem de erro
		if (option.length() > 1 || (option[0] != 'N' && option[0] != 'S'))
		{
			cout << "Introduza uma op��o v�lida" << endl;
		}

	} while ((option[0] != 'N' && option[0] != 'S') || option.length()>1);

	if (option[0] == 'N')
	{
		cout << "O ficheiro " << filename << " n�o foi carregado."<<endl;
	}
	else
	{
		ifstream ficheiro(filename);
		if (ficheiro.is_open())
		{
			try{
			while (!ficheiro.eof())
			{
				
					projeto * proj = new projeto();
					proj->id = index;
					getline(ficheiro, proj->titulo);
					getline(ficheiro, proj->institui��oProv);
					getline(ficheiro, proj->nomeInvestigador);
					getline(ficheiro, str);
					proj->duracao = stoi(str);
					getline(ficheiro, proj->vectorPalavrasChave[0]);
					getline(ficheiro, proj->vectorPalavrasChave[1]);
					getline(ficheiro, proj->vectorPalavrasChave[2]);
					getline(ficheiro, proj->vectorPalavrasChave[3]);
					getline(ficheiro, proj->vectorPalavrasChave[4]);
					getline(ficheiro, str);
					proj->despesas.compraEquip = stoi(str);
					getline(ficheiro, str);
					proj->despesas.consultoresDesp = stoi(str);
					getline(ficheiro, str);
					proj->despesas.consumiveisDesp = stoi(str);
					getline(ficheiro, str);
					proj->despesas.deslocacoes = stoi(str);
					getline(ficheiro, str);
					proj->despesas.gastosGerais = stoi(str);
					getline(ficheiro, str);
					proj->despesas.pagBolsas = stoi(str);
					proj->custoTotal = calcCustoTotal(&proj);
					//Preenche o vetor das notas.
					for (int i = 0; i < 3; i++)
					{
						getline(ficheiro, str);
						//stoi() converte uma string para um valor inteiro.
						proj->notas[i].exequibilidade = stoi(str);
						getline(ficheiro, str);
						proj->notas[i].idoneidade = stoi(str);
						getline(ficheiro, str);
						proj->notas[i].originalidade = stoi(str);
						getline(ficheiro, str);
						proj->notas[i].qualidade = stoi(str);
					}
					proj->classFinal = classificacaoFinal(proj->notas);
					for (int i = 0; i < 3; i++)
					{
						proj->verificaAvaliacao[i] = true;
					}
					getline(ficheiro, linhaBranco);
					proj->next = *p;
					*p = proj;
					index++;
				}
				
			}
			catch (bad_alloc e){
				cout << "Lamentamos mas n�o foi poss�vel alocar mem�ria para o projeto!" << endl;
				falhou = true;
			}
			catch (invalid_argument e){
				cout << "Ocorreu um erro na leitura do ficheiro!" << endl;
				falhou = true;
			}
			ficheiro.close();
			if (!falhou)
			{
				cout << "O carregamento do ficheiro \"" << filename << "\" foi bem sucedido." << endl;
			}
		}
		else
		{
			cout << "� imposs�vel abrir o ficheiro de texto." << endl;
			menu(*p);
		}
	}
}

// Fun��o que permite escrever projetos em um ficheiro de texto //
void escreveFicheiroTexto(projeto **p)
{
	projeto *aux = *p;
	string nameFile;
	string option;
	cout << "Insira o nome para o ficheiro de texto" << endl;
	//cin.ignore();
	getline(cin, nameFile);

	do{
		cout << "Deseja prosseguir com a escrita do ficheiro? S/N" << endl;
		cout << "ATEN��O !!!!!" << endl;
		cout << "Caso n�o tenha ordenado os ficheiros e deseje escreve-los de forma" << endl;
		cout << "ordenada, deve escolher previamente a op��o pretendida no menu principal." << endl;
		getline(cin, option);
		// Se a string tiver um tamanho maior um. Ent�o apresenta-se uma mensageem de erro
		if (option.length() > 1 || (option[0] != 'N' && option[0] != 'S'))
		{
			cout << "Introduza uma op��o v�lida" << endl;
		}

	} while ((option[0] != 'N' && option[0] != 'S') || option.length()>1);

	if (option[0] == 'N')
	{
		cout << "A escrita foi interrompida ir� voltar ao menu inicial." << endl;
	}
	else
	{
		ofstream nomeFicheiro(nameFile.append(".txt"));
		if (nomeFicheiro.is_open())
		{
			while (aux != NULL){
				nomeFicheiro << "Id: " << aux->id << endl;
				nomeFicheiro << "Nome do Projeto: " << aux->titulo << endl;
				//Calcula o cuso total do projeto do projeto que vai ser escrito
				calcCustoTotal(&aux);
				nomeFicheiro << "Custo total do projeto: " << aux->custoTotal << endl;

				if (aux->verificaAvaliacao[0] && aux->verificaAvaliacao[1] && aux->verificaAvaliacao[2])
				{
					nomeFicheiro << "Classifica��o final do projeto: " << aux->classFinal << endl;
					atribuiSubsidio(&aux);
					nomeFicheiro << "Subs�dio atribu�do: " << aux->subsidio << endl;
				}
				else
				{

					for (int i = 0; i < AVALIADORES; i++){
						if (aux->verificaAvaliacao[i])
						{
							nomeFicheiro << "O j�ri " << i + 1 << " j� atribuiu a sua avalia��o. " << endl;
						}
						else
						{
							nomeFicheiro << "O j�ri " << i + 1 << " ainda n�o atribuiu a sua avalia��o. " << endl;
						}
					}
				}
				nomeFicheiro << endl;
				nomeFicheiro << "---------------------------------------" << endl;
				nomeFicheiro << endl;
				//Passa � escrita do proximo projeto.
				aux = aux->next;
			}
			nomeFicheiro.close();
			cout << endl;
			cout << "A escrita no ficheiro de texto" + nameFile + " foi bem sucedida." << endl;
		}
		else
		{
			cout << "� imposs�vel abrir o ficheiro de texto." << endl;
			// Se n�o for poss�vel abrir o ficheiro de texto ent�o volta ao menu
		}
	}
}