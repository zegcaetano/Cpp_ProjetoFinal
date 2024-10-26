#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <clocale>
// Biblioteca de C++
#include <string>     // Classe "string"
#include <iostream>   // Objetos: "cin" e "cout"
#include <iomanip>    // "setprecision()".
#include <vector>
#include <fstream>
              // Inclusão do ficheiro de classe
#include "Jogo.cpp"
#include "Fornecedores.cpp"
#include "Encomendas.cpp"
#include "DataHora.cpp"
using namespace std;



void escolhaInvalida();
void despedida();
void pausa();
void mostraMenu();
void mostraMainMenu();
void mostraMenuJogo();
void mostraMenuFornecedor();
void mostraMenuEncomenda();
int  obtemEscolhaJogo(int);
int  obtemEscolhaFornecedor(int);
int  obtemEscolhaEncomenda(int);
bool processaEscolhaJogo(vector<Jogo>*, int, bool);
bool processaEscolhaFornecedor(vector<Fornecedores>*, int, bool);
bool processaEscolhaEncomenda(vector<Encomendas>*, vector<Fornecedores>*, vector<Jogo>*, int, bool);
bool sairDoProgramaJogo(bool);
bool sairDoProgramaFornecedores(bool);
bool sairDoProgramaEncomendas(bool);
void guardaFicheiroJogo(vector<Jogo> jogos);
void lerFicheiroJogo(vector<Jogo>* jogos);
void guardaFicheiroFornecedores(vector<Fornecedores> fornecedores);
void lerFicheiroFornecedores(vector<Fornecedores>* fornecedores);
void guardaFicheiroEncomendas(vector<Encomendas> encomendas);
void lerFicheiroEncomendas(vector<Encomendas>* encomendas);
void listarJogos(vector<Jogo>);
void listarFornecedores(vector<Fornecedores>);
void listarEncomendas(vector<Encomendas>);
void inserirJogo(vector<Jogo>*);
void inserirFornecedor(vector<Fornecedores>*);
void inserirEncomenda(vector<Encomendas>*, vector<Fornecedores>*, vector<Jogo>*);
void apagarJogo(vector<Jogo>*);
void apagarFornecedor(vector<Fornecedores>*);
void pesquisarJogo(vector<Jogo>);
void pesquisarFornecedor(vector<Fornecedores>);
void editarJogo(vector<Jogo>*);
void editarFornecedor(vector<Fornecedores>*);
void venderJogo(vector<Jogo>*);
void reporJogo(vector<Jogo>*);
void pagarFatura(vector<Encomendas>*, vector<Jogo>*);



// Declaração e inicialização dos dados estaticos
int Jogo::numJogos = 0;
int Fornecedores::numFornecedores = 0;
int Encomendas::numEncomendas = 0;
int Encomendas::nextID = 1;

// Dados globais
const int MAXOPCOES = 8;

//*******************
// Declaração de um vetor dinâmico
vector<Jogo> jogos;
vector<Fornecedores> fornecedores;
vector<Encomendas> encomendas;



int main()
{
	setlocale(LC_ALL, "Portuguese");
	int escolha = 0;
	bool queroSair = false;
	bool sairMain = false;

	lerFicheiroJogo(&jogos);
	lerFicheiroFornecedores(&fornecedores);
	lerFicheiroEncomendas(&encomendas);
	
	
	do {
		mostraMenu(); mostraMainMenu();
		int escolha = 0;
		cout << "Choose your option (1-4)" << endl;
		cin >> escolha; cin.ignore();
		switch (escolha)
			{
			case 1:
				{
					do
					{
						queroSair = false;
						mostraMenu(); mostraMenuJogo();
						escolha = obtemEscolhaJogo(escolha);
						queroSair = processaEscolhaJogo(&jogos, escolha, queroSair);
					} while (!queroSair);
					break;
				}

			case 2:
				{
					do
					{
						queroSair = false;
						mostraMenu(); mostraMenuFornecedor();
						escolha = obtemEscolhaFornecedor(escolha);
						queroSair = processaEscolhaFornecedor(&fornecedores, escolha, queroSair);
					} while (!queroSair);
					break;
				}
			case 3:
				{
					do
					{
						queroSair = false;
						mostraMenu(); mostraMenuEncomenda();
						escolha = obtemEscolhaEncomenda(escolha);
						queroSair = processaEscolhaEncomenda(&encomendas, &fornecedores, &jogos, escolha, queroSair);
					} while (!queroSair);
					break;
				}
			case 4:
				{
				sairMain = sairDoProgramaJogo(sairMain);
				break;
				}
			default:
				{
				cout << "Wrong option. Must be between 1-4" << endl;
				}
		}

	} while (!sairMain);
	despedida();
	return 0;
}// fim do main

void mostraMainMenu()
{
	system("color B");
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                             1. Games.                                       *" << endl;
	cout << "*                             2. Suppliers.                                   *" << endl;
	cout << "*                             3. Orders.                                      *" << endl;
	cout << "*                             4. Quit.                                        *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*******************************************************************************" << endl;
	cout << endl;
}


void mostraMenu()
{
	system("cls");   // Limpa o ecrã 
	system("color B");
	cout << "*******************************************************************************" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*      ___ _       _ _        _      ___                                      *" << endl;
	cout << "*     /   (_) __ _(_) |_ __ _| |    /   \\_   _ _ __   __ _  ___  ___  _ __    *" << endl;
	cout << "*    / /\\ / |/ _` | | __/ _` | |   / /\\ / | | | '_ \\ / _` |/ _ \\/ _ \\| '_ \\   *" << endl;
	cout << "*   / /_//| | (_| | | || (_| | |  / /_//| |_| | | | | (_| |  __/ (_) | | | |  *" << endl;
	cout << "*  /___,' |_|\\__, |_|\\__\\__,_|_| /___,'  \\__,_|_| |_|\\__, |\\___|\\___/|_| |_|  *" << endl;
	cout << "*            |___/                                   |___/                    *" << endl;
}


////*********************************************
////* Função "obtemEscolhaMain()"
////* Entrada(s): int escolha 
////* Saida(s): int
////*********************************************
//void obtemEscolhaMain()
//{
//	int escolha = 0;
//	cout << "Choose your option (1-4)" << endl;
//	cin >> escolha; cin.ignore();
//} // Fim do "obtemEscolha()".
//*********************************************
//*			FUNÇÕES DA CLASSE JOGO
//*********************************************

void mostraMenuJogo()
{
	system("color B");
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                             1. Insert game.                                 *" << endl;
	cout << "*                             2. Delete game.                                 *" << endl;
	cout << "*                             3. Search game.                                 *" << endl;
	cout << "*                             4. Edit game.                                   *" << endl;
	cout << "*                             5. Show game list.                              *" << endl;
	cout << "*                             6. Sell game.                                   *" << endl;
	cout << "*                             7. Restock game.                                *" << endl;
	cout << "*                             8. Main menu.                                   *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*******************************************************************************" << endl;
	cout << endl;
}   // Fim da função "mostraMenu()".





//*********************************************
//* Função "obtemEscolhaJogo()"
//* Entrada(s): int escolha 
//* Saida(s): int
//*********************************************
int obtemEscolhaJogo(int escolha)
{
	cout << "Choose your option (1-8)" << endl;
	cin >> escolha; cin.ignore();
	return escolha;
} // Fim do "obtemEscolha()".



//**********************************************
//*  Função processaEscolhaJogo()"
//*    Entradas: vector<Livro>& livros, int numLivros,
//*              char escolha, bool queroSair.
//*    Saida(s): bool queroSair.
//**********************************************
bool processaEscolhaJogo(vector<Jogo>* jogos, int escolha, bool queroSair)
{
	switch (escolha)
	{
	case 1:
	{
		inserirJogo(jogos);
		guardaFicheiroJogo(*jogos);
		break;
	}
	case 2:
	{
		apagarJogo(jogos);
		guardaFicheiroJogo(*jogos);
		break;
	}
	case 3:
	{
		pesquisarJogo(*jogos);
		break;
	}
	case 4:
	{
		editarJogo(jogos);
		guardaFicheiroJogo(*jogos);
		break;
	}
	case 5:
	{
		listarJogos(*jogos);
		break;
	}
	case 6:
	{
		venderJogo(jogos);
		guardaFicheiroJogo(*jogos);
		break;
	}
	case 7:
	{
		reporJogo(jogos);
		guardaFicheiroJogo(*jogos);
		break;
	}
	case 8:
	{
		queroSair = sairDoProgramaJogo(queroSair);
		break;
	}
	default:
		escolhaInvalida();
	} // Fim do "switch"

	return queroSair;
} // Fim da Função "processaEscolha()".



//**********************************************
//*  Função inserirJogo()"
//*    Entradas: vector<Jogo>& jogos, int numJogos.
//*    Saida(s): não tem.
//**********************************************
void inserirJogo(vector<Jogo>* jogos)
{
	Jogo* jogo = new Jogo;
	jogo->readAllJogo();

	int nJogos = static_cast<int>(jogos->size());
	cout << "Number of games: " << nJogos << "." << endl;

	jogos->push_back(*jogo);
	Jogo::numJogos++;
	//livros.insert(livros.begin()+nLivros, livro);
	jogos->at(nJogos).showAllJogo();
	nJogos = static_cast<int>(jogos->size());
	cout << "Number of games: " << nJogos << "." << endl;
	cout << "Game inserted successfully!" << endl;
	pausa();
} // Fim da função "Inserirlivro()".



//**********************************************
//*  Função apagarJogo()"
//*    Entradas: vector<Jogo>& jogos, int numJogos.
//*    Saida(s): não tem.
//**********************************************
void apagarJogo(vector<Jogo>* jogos)
{
	int indexApagar = 0;
	int nJogos = static_cast<int>(jogos->size());


	if (nJogos <= 0)
	{
		cout << "Currently there are no games in stock." << endl;
		pausa();
	}
	else
	{
		cout << "Available games: " << endl;
		for (int i = 0; i < nJogos; i++)
		{
			cout << (i + 1) << ".";
			jogos->at(i).mostraTitulo();
		}
		do {
			cout << "Insert the number of the game you wish to delete (1 - " << nJogos << "). " << endl;
			cin >> indexApagar;
			cin.ignore();
			if (indexApagar < 1 || indexApagar > nJogos)
			{
				cout << "Games available: 1 - " << nJogos << "). " << endl;
				cout << "Press any key to continue..." << endl;
				cin.get();
			}
		} while (indexApagar < 1 || indexApagar > nJogos);

		jogos->erase(jogos->begin() + (indexApagar - 1));
		Jogo::numJogos--;
		cout << "Game deleted successfully!" << endl;
		pausa();
	}
}//fim da função apagarJogo


//**********************************************
//*    Função pesquisarJogo()"
//*    Entradas: vector<Jogo>& jogos, int numJogos.
//*    Saida(s): não tem.
//**********************************************
void pesquisarJogo(vector<Jogo> jogos)
{

	int indexProcurar = 0;
	int nJogos = static_cast<int>(jogos.size());


	if (nJogos <= 0)
	{
		cout << "Currently there are no games in stock." << endl;
		pausa();
	}
	else
	{
		cout << "Available games: " << endl;
		for (int i = 0; i < nJogos; i++)
		{
			cout << (i + 1) << ".";
			jogos[i].mostraTitulo();
		}
		do {
			cout << "Insert the number of the game you wish to search (1 - " << nJogos << "). " << endl;
			cin >> indexProcurar;
			cin.ignore();
			if (indexProcurar < 1 || indexProcurar > nJogos)
			{
				cout << "Games available: 1 - " << nJogos << "). " << endl;
				cout << "Press any key to continue..." << endl;
				cin.get();
			}
		} while (indexProcurar < 1 || indexProcurar > nJogos);

		jogos[indexProcurar - 1].showAllJogo();
		pausa();
	}
}

//**********************************************
//*  Função editarJogo()"
//*    Entradas: vector<Jogo>& jogos, int numJogos.
//*    Saida(s): não tem.
//**********************************************
void editarJogo(vector<Jogo>* jogos)
{
	int indexEditar = 0;
	int nJogos = static_cast<int>(jogos->size());
	int opcao = 0;
	bool sair = false;
	char yes = '\0';

	if (nJogos <= 0)
	{
		cout << "Currently there are no games in stock." << endl;
		pausa();
	}
	else
	{
		cout << "Available games: " << endl;
		for (int i = 0; i < nJogos; i++)
		{
			cout << (i + 1) << ".";
			jogos->at(i).mostraTitulo();
		}
		do {
			cout << "Insert the number of the game you wish to edit (1 - " << nJogos << "). " << endl;
			cin >> indexEditar;
			cin.ignore();
			if (indexEditar < 1 || indexEditar > nJogos)
			{
				cout << "Games available: 1 - " << nJogos << "). " << endl;
				cout << "Press any key to continue..." << endl;
				cin.get();
			}
		} while (indexEditar < 1 || indexEditar > nJogos);

		do {
			(*jogos)[indexEditar - 1].showAllJogo();
			cout << "Insert the number of the field you wish to edit:" << endl;
			cout << "1.All            2.Price      3.Copies   4.Title    5.Developer(s)   6.Publisher" << endl;
			cout << "7.Release Date   8.Platform   9.Mode     10.Genre   11.Online        " << endl;
			cin >> opcao;
			cin.ignore();
			switch (opcao)
			{
			case 1:
			{
				(*jogos)[indexEditar - 1].readAllJogo();
				sair = true;
				break;
			}
			case 2:
			{
				(*jogos)[indexEditar - 1].readPrice();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 3:
			{
				(*jogos)[indexEditar - 1].readCopies();
				cout << endl;
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 4:
			{
				(*jogos)[indexEditar - 1].readTitle();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 5:
			{
				(*jogos)[indexEditar - 1].readDeveloper();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 6:
			{
				(*jogos)[indexEditar - 1].readPublisher();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 7:
			{
				(*jogos)[indexEditar - 1].readReleaseDate();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 8:
			{
				(*jogos)[indexEditar - 1].readPlatform();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 9:
			{
				(*jogos)[indexEditar - 1].readMode();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 10:
			{
				(*jogos)[indexEditar - 1].readGenre();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 11:
			{
				(*jogos)[indexEditar - 1].readOnline();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}

			}
		} while (!sair);
		cout << "Field(s) edited successfully!" << endl;
		cin.ignore();
		pausa();
	}
}




//**********************************************
//*    Função listarJogos()"
//*    Entradas: vector<Jogo>& jogos, int numJogos.
//*    Saida(s): não tem.
//**********************************************
void listarJogos(vector<Jogo> jogos)
{

	int indexListar = 0;
	int nJogos = static_cast<int>(jogos.size());


	if (nJogos <= 0)
	{
		cout << "Currently there are no games in stock." << endl;
		pausa();
	}
	else
	{
		cout << "Insert type of list" << endl;
		cout << "1. Quick view" << endl;
		cout << "2. Detailed view" << endl;
		cout << "0. Quit" << endl;
		cin >> indexListar;
		do {
			switch (indexListar)
			{
			case 1:
			{
				for (int i = 0; i < nJogos; i++)
				{
					cout << i + 1 << ". ";
					jogos[i].mostraTitulo();
				}
				pausa();
				cin.ignore();
				break;
			}
			case 2:
			{
				for (int i = 0; i < nJogos; i++)
				{
					cout << i + 1 << ". ";
					jogos[i].showAllJogo();
				}
				pausa();
				cin.ignore();
				break;
			}
			case 0:
			{
				pausa();
				break;
			}
			default:
			{
				cout << "Wrong option! Please choose between 0-2..." << endl;
				pausa();
			}
			}
		} while (indexListar < 0 && indexListar > 2);
	}
}//fim do listarJogos




//**********************************************
//*  Função venderJogo()"
//*    Entradas: vector<Jogo>& jogos, int numJogos.
//*    Saida(s): não tem.
//**********************************************
void venderJogo(vector<Jogo>* jogos)
{
	int indexVenda = 0;
	int nJogos = static_cast<int>(jogos->size());
	int uVendidas = 0;
	int nUnidades = 0;
	char apaga = '\0';


	if (nJogos <= 0)
	{
		cout << "Currently there are no games in stock." << endl;
		pausa();
	}
	else
	{
		cout << "Available games: " << endl;
		for (int i = 0; i < nJogos; i++)
		{
			cout << (i + 1) << ".";
			jogos->at(i).mostraTitulo();
		}
		do {
			cout << "Insert the number of the game you wish to sell (1 - " << nJogos << "). " << endl;
			cin >> indexVenda;
			cin.ignore();
			if (indexVenda < 1 || indexVenda > nJogos)
			{
				cout << "Games available: 1 - " << nJogos << "). " << endl;
				cout << "Press any key to continue..." << endl;
				cin.get();
			}
		} while (indexVenda < 1 || indexVenda > nJogos);



		(*jogos)[indexVenda - 1].showAllJogo();
		nUnidades = (*jogos)[indexVenda - 1].getCopies();
		cout << "Insert the number of copies sold." << endl;
		cin >> uVendidas; cin.ignore();

		if (uVendidas <= 0) {
			cout << "You must sell at least one copy." << endl;
			pausa();
			return; // Early exit if invalid input
		}

		// Check stock and update
		if (uVendidas > nUnidades) {
			cout << "Not enough copies in stock. Available copies: " << nUnidades << endl;
			pausa();
			return; // Exit if trying to sell more than available
		}

		nUnidades -= uVendidas;
		(*jogos)[indexVenda - 1].setCopies(nUnidades);
		if ((*jogos)[indexVenda - 1].getCopies() == 0)
		{
			cout << "No copies are available. Press D to delete the game from file or any other key to keep it...." << endl;
			cin >> apaga;
			if (apaga == 'd' || apaga == 'D')
			{
				jogos->erase(jogos->begin() + (indexVenda - 1));
				Jogo::numJogos--;
				cout << "Game deleted successfully!" << endl;
				pausa();
			}

			else
			{
				(*jogos)[indexVenda - 1].showAllJogo();
				cout << "The sale was successful! Thank you for your transaction." << endl;
				pausa();
			}
		}
	}
}







//**********************************************
//*  Função reporJogo()"
//*    Entradas: vector<Jogo>& jogos, int numJogos.
//*    Saida(s): não tem.
//**********************************************
void reporJogo(vector<Jogo>* jogos)
{
	int indexRepos = 0;
	int nJogos = static_cast<int>(jogos->size());
	int uRepostas = 0;
	int nUnidades = 0;


	if (nJogos <= 0)
	{
		cout << "Currently there are no games in stock." << endl;
		pausa();
	}
	else
	{
		cout << "Available games: " << endl;
		for (int i = 0; i < nJogos; i++)
		{
			cout << (i + 1) << ".";
			jogos->at(i).mostraTitulo();
		}
		do {
			cout << "Insert the number of the game you wish to restock (1 - " << nJogos << "). " << endl;
			cin >> indexRepos;
			cin.ignore();
			if (indexRepos < 1 || indexRepos > nJogos)
			{
				cout << "Games available: 1 - " << nJogos << "). " << endl;
				cout << "Press any key to continue..." << endl;
				cin.get();
			}
		} while (indexRepos < 1 || indexRepos > nJogos);



		(*jogos)[indexRepos - 1].showAllJogo();
		nUnidades = (*jogos)[indexRepos - 1].getCopies();
		cout << "Please insert the number of copies restocked." << endl;
		cin >> uRepostas; cin.ignore();
		nUnidades += uRepostas;
		(*jogos)[indexRepos - 1].setCopies(nUnidades);
		(*jogos)[indexRepos - 1].showAllJogo();
		cout << "Restock successful! Thank you for replenishing our inventory." << endl;
		pausa();
	}
}



//*************************************************
//*  Função "sairDoProgramaJogo()"
//*   Entrada(s): queroSair (bool) 
//*   Saida(s): queroSair (bool)
//*************************************************
bool sairDoProgramaJogo(bool queroSair)
{
	char resposta = '\0';
	fflush(stdin);
	cout << "Are you sure? (Y/N)? ";
	cin >> resposta; cin.ignore();
	if (resposta == 'y' || resposta == 'Y')
		queroSair = true;
	return queroSair;
} // Fim da função "sairDoPrograma()".




//****************************************************************
//* GravarFicheiro Jogo
//****************************************************************
void guardaFicheiroJogo(vector<Jogo> jogos)
{
	string caminho = "";
	string nomeFicheiro = "lojaJogos.txt";
	string nomeCompleto = caminho + nomeFicheiro;
	cout << "File name: " << nomeCompleto.c_str() << "." << endl;

	// 4. Criar o objeto e abrir o ficheiro
	//ofstream ficheiro4(nomeCompleto.c_str());
	ofstream  ficheiro;
	ficheiro.open(nomeCompleto, ios::out);// | ios_base::binary
	// Modos de abertura: "ios::out" -> escrita

	if (!ficheiro)
	{
		cout << "File not open..." << endl;
		cout << "Press any key to continue ... ";
		cin.get();
	}
	else
	{
		int nJogos = static_cast<int>(jogos.size());
		cout << "Available games: " << nJogos << endl;
		if (nJogos <= 0)
		{
			cout << "Currently there are no games in stock." << endl;
			cout << "Press any key to continue ... ";
			cin.get();
		}
		else
		{
			cout << "Saving games..." << endl;
			for (int i = 0; i < nJogos; i++)
				ficheiro << jogos[i];
			ficheiro.close();
			cout << "Data saved successfully!" << endl;
			cout << "Press any key to continue ... ";
			cin.get();
		}
	}
}//fim da função guardaFicheiro


//****************************************************************
//* LerFicheiro Jogo
//****************************************************************
void lerFicheiroJogo(vector<Jogo>* jogos)
{
	string caminho = "";
	string nomeFicheiro = "lojaJogos.txt";
	string nomeCompleto = caminho + nomeFicheiro;
	cout << "File name: " << nomeCompleto.c_str() << "." << endl;

	jogos->erase(jogos->begin(), jogos->end());

	cout << "Reading file..." << endl;
	// 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
	ifstream ficheiroL;
	ficheiroL.open(nomeCompleto, ios::in);

	if (ficheiroL.is_open())
	{
		Jogo jogo;
		//leitura dos objectos
		int cJogos = 0;
		while (ficheiroL >> jogo && !ficheiroL.eof())
		{
			jogos->push_back(jogo);
			cJogos++;
			cout << "Game " << cJogos << ": " << endl;
		}
		ficheiroL.close();
		cout << endl;
	}
}

//FIM DAS FUNÇÕES DA CLASSE JOGO

//*********************************************
//*			FUNÇÕES DA CLASSE FORNECEDOR
//*********************************************


void mostraMenuFornecedor()
{
	system("color B");
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                             1. Insert supplier.                             *" << endl;
	cout << "*                             2. Delete supplier.                             *" << endl;
	cout << "*                             3. Search supplier.                             *" << endl;
	cout << "*                             4. Edit supplier.                               *" << endl;
	cout << "*                             5. Show supplier list.                          *" << endl;
	cout << "*                             6. Main menu.                                   *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*******************************************************************************" << endl;
	cout << endl;
}

//*********************************************
//* Função "obtemEscolhaFornecedor()"
//* Entrada(s): int escolha 
//* Saida(s): int
//*********************************************
int obtemEscolhaFornecedor(int escolha)
{
	cout << "Choose your option (1-6)" << endl;
	cin >> escolha; cin.ignore();
	return escolha;
} // Fim do "obtemEscolha()".



//**********************************************
//*  Função processaEscolhaFornecedor()"
//*    Entradas: vector<Livro>& livros, int numLivros,
//*              char escolha, bool queroSair.
//*    Saida(s): bool queroSair.
//**********************************************
bool processaEscolhaFornecedor(vector<Fornecedores>* fornecedores, int escolha, bool queroSair)
{
	switch (escolha)
	{
	case 1:
	{
		inserirFornecedor(fornecedores);
		guardaFicheiroFornecedores(*fornecedores);
		break;
	}
	case 2:
	{
		apagarFornecedor(fornecedores);
		guardaFicheiroFornecedores(*fornecedores);
		break;
	}
	case 3:
	{
		pesquisarFornecedor(*fornecedores);
		break;
	}
	case 4:
	{
		editarFornecedor(fornecedores);
		guardaFicheiroFornecedores(*fornecedores);
		break;
	}
	case 5:
	{
		listarFornecedores(*fornecedores);
		break;
	}
	case 6:
	{
		queroSair = sairDoProgramaFornecedores(queroSair);
		break;
	}
	default:
		escolhaInvalida();
	} // Fim do "switch"

	return queroSair;
} // Fim da Função "processaEscolhaFornecedor()".


//**********************************************
//*  Função inserirFornecedor()"
//*    Entradas: vector<Fornecedor>& fornecedores, int numFornecedores.
//*    Saida(s): não tem.
//**********************************************
void inserirFornecedor(vector<Fornecedores>* fornecedores)
{
	Fornecedores* fornecedor = new Fornecedores;
	fornecedor->readAllFornecedores();

	int nFornecedores = static_cast<int>(fornecedores->size());
	cout << "Number of suppliers: " << nFornecedores << "." << endl;

	fornecedores->push_back(*fornecedor);
	Fornecedores::numFornecedores++;
	//livros.insert(livros.begin()+nLivros, livro);
	fornecedores->at(nFornecedores).showAllFornecedores();
	nFornecedores = static_cast<int>(fornecedores->size());
	cout << "Number of suppliers: " << nFornecedores << "." << endl;
	cout << "Supplier inserted successfully!" << endl;
	pausa();
} // Fim da função "InserirFornecedor()".

//**********************************************
//*  Função apagarFornecedor()"
//*    Entradas: vector<Fornecedor>& fornecedores, int numFornecedores.
//*    Saida(s): não tem.
//**********************************************
void apagarFornecedor(vector<Fornecedores>* fornecedores)
{
	int indexApagar = 0;
	int nFornecedores = static_cast<int>(fornecedores->size());


	if (nFornecedores <= 0)
	{
		cout << "Currently there are no registered suppliers." << endl;
		pausa();
	}
	else
	{
		cout << "Available suppliers: " << endl;
		for (int i = 0; i < nFornecedores; i++)
		{
			cout << (i + 1) << ".";
			fornecedores->at(i).mostraNome();
		}
		do {
			cout << "Insert the number of the supplier you wish to delete (1 - " << nFornecedores << "). " << endl;
			cin >> indexApagar;
			cin.ignore();
			if (indexApagar < 1 || indexApagar > nFornecedores)
			{
				cout << "Suppliers available: 1 - " << nFornecedores << "). " << endl;
				cout << "Press any key to continue..." << endl;
				cin.get();
			}
		} while (indexApagar < 1 || indexApagar > nFornecedores);

		fornecedores->erase(fornecedores->begin() + (indexApagar - 1));
		Fornecedores::numFornecedores--;
		cout << "Supplier deleted successfully!" << endl;
		pausa();
	}
}//fim da função apagarFornecedor

//**********************************************
//*    Função pesquisarFornecedor()"
//*    Entradas: vector<Fornecedor> fornecedores
//*    Saida(s): não tem.
//**********************************************
void pesquisarFornecedor(vector<Fornecedores> fornecedores)
{

	int indexProcurar = 0;
	int nFornecedores = static_cast<int>(fornecedores.size());


	if (nFornecedores <= 0)
	{
		cout << "Currently there are no registered suppliers." << endl;
		pausa();
	}
	else
	{
		cout << "Available suppliers: " << endl;
		for (int i = 0; i < nFornecedores; i++)
		{
			cout << (i + 1) << ".";
			fornecedores[i].mostraNome();
		}
		do {
			cout << "Insert the number of the supplier you wish to search (1 - " << nFornecedores << "). " << endl;
			cin >> indexProcurar;
			cin.ignore();
			if (indexProcurar < 1 || indexProcurar > nFornecedores)
			{
				cout << "Suppliers available: 1 - " << nFornecedores << "). " << endl;
				cout << "Press any key to continue..." << endl;
				cin.get();
			}
		} while (indexProcurar < 1 || indexProcurar > nFornecedores);

		fornecedores[indexProcurar - 1].showAllFornecedores();
		pausa();
	}
}


//**********************************************
//*  Função editarFornecedor()"
//*    Entradas: vector<Fornecedor> fornecedores
//*    Saida(s): não tem.
//**********************************************
void editarFornecedor(vector<Fornecedores>* fornecedores)
{
	int indexEditar = 0;
	int nFornecedores = static_cast<int>(fornecedores->size());
	int opcao = 0;
	bool sair = false;
	char yes = '\0';

	if (nFornecedores <= 0)
	{
		cout << "Currently there are no registered suppliers." << endl;
		pausa();
	}
	else
	{
		cout << "Available suppliers: " << endl;
		for (int i = 0; i < nFornecedores; i++)
		{
			cout << (i + 1) << ".";
			fornecedores->at(i).mostraNome();
		}
		do {
			cout << "Insert the number of the supplier you wish to edit (1 - " << nFornecedores << "). " << endl;
			cin >> indexEditar;
			cin.ignore();
			if (indexEditar < 1 || indexEditar > nFornecedores)
			{
				cout << "Suppliers available: 1 - " << nFornecedores << "). " << endl;
				cout << "Press any key to continue..." << endl;
				cin.get();
			}
		} while (indexEditar < 1 || indexEditar > nFornecedores);

		do {
			(*fornecedores)[indexEditar - 1].showAllFornecedores();
			cout << "Insert the number of the field you wish to edit:" << endl;
			cout << "1.All		2.Name				3.Contact		4.Address   " << endl;
			cout << "5.NIF		6.Payment Terms     7.Rating					" << endl;
			cin >> opcao;
			cin.ignore();
			switch (opcao)
			{
			case 1:
			{
				(*fornecedores)[indexEditar - 1].readAllFornecedores();
				sair = true;
				break;
			}
			case 2:
			{
				(*fornecedores)[indexEditar - 1].readNomeFornecedor();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 3:
			{
				(*fornecedores)[indexEditar - 1].readContacto();
				cout << endl;
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 4:
			{
				(*fornecedores)[indexEditar - 1].readMorada();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 5:
			{
				(*fornecedores)[indexEditar - 1].readNIF();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 6:
			{
				(*fornecedores)[indexEditar - 1].readTermosPagamento();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}
			case 7:
			{
				(*fornecedores)[indexEditar - 1].readRating();
				cout << "Press Y to continue editing, any other key to exit..." << endl;
				cin >> yes;
				if (yes != 'y' && yes != 'Y')
				{
					sair = true;
				}
				break;
			}


			}
		} while (!sair);
		cout << "Field(s) edited successfully!" << endl;
		cin.ignore();
		pausa();
	}
}


//**********************************************
//*    Função listarFornecedores()"
//*    Entradas: vector<Fornecedores> fornecedores
//*    Saida(s): não tem.
//**********************************************
void listarFornecedores(vector<Fornecedores> fornecedores)
{

	int indexListar = 0;
	int nFornecedores = static_cast<int>(fornecedores.size());


	if (nFornecedores <= 0)
	{
		cout << "Currently there are no registered suppliers." << endl;
		pausa();
	}
	else
	{
		cout << "Insert type of list" << endl;
		cout << "1. Quick view" << endl;
		cout << "2. Detailed view" << endl;
		cout << "0. Quit" << endl;
		cin >> indexListar;
		do {
			switch (indexListar)
			{
			case 1:
			{
				for (int i = 0; i < nFornecedores; i++)
				{
					cout << i + 1 << ". ";
					fornecedores[i].mostraNome();
				}
				pausa();
				cin.ignore();
				break;
			}
			case 2:
			{
				for (int i = 0; i < nFornecedores; i++)
				{
					cout << i + 1 << ". ";
					fornecedores[i].showAllFornecedores();
				}
				pausa();
				cin.ignore();
				break;
			}
			case 0:
			{
				pausa();
				break;
			}
			default:
			{
				cout << "Wrong option! Please choose between 0-2..." << endl;
				pausa();
			}
			}
		} while (indexListar < 0 && indexListar > 2);
	}
}//fim do listarFornecedores

//*************************************************
//*  Função "sairDoProgramaFornecedores()"
//*   Entrada(s): queroSair (bool) 
//*   Saida(s): queroSair (bool)
//*************************************************
bool sairDoProgramaFornecedores(bool queroSair)
{
	char resposta = '\0';
	fflush(stdin);
	cout << "Are you sure? (Y/N)? ";
	cin >> resposta; cin.ignore();
	if (resposta == 'y' || resposta == 'Y')
		queroSair = true;
	return queroSair;
} // Fim da função "sairDoProgramaFornecedores()".


//****************************************************************
//* GravarFicheiro Fornecedores
//****************************************************************
void guardaFicheiroFornecedores(vector<Fornecedores> fornecedores)
{
	string caminho = "";
	string nomeFicheiro = "Fornecedores.txt";
	string nomeCompleto = caminho + nomeFicheiro;
	cout << "File name: " << nomeCompleto.c_str() << "." << endl;

	// 4. Criar o objeto e abrir o ficheiro
	//ofstream ficheiro4(nomeCompleto.c_str());
	ofstream  ficheiroF;
	ficheiroF.open(nomeCompleto, ios::out);// | ios_base::binary
	// Modos de abertura: "ios::out" -> escrita

	if (!ficheiroF)
	{
		cout << "File not open..." << endl;
		cout << "Press any key to continue ... ";
		cin.get();
	}
	else
	{
		int nFornecedores = static_cast<int>(fornecedores.size());
		cout << "Available suppliers: " << nFornecedores << endl;
		if (nFornecedores <= 0)
		{
			cout << "Currently there are no registered suppliers." << endl;
			cout << "Press any key to continue ... " << endl;
			cin.get();
		}
		else
		{
			cout << "Saving suppliers..." << endl;
			for (int i = 0; i < nFornecedores; i++)
				ficheiroF << fornecedores[i];
			ficheiroF.close();
			cout << "Data saved successfully!" << endl;
			cout << "Press any key to continue ... ";
			cin.get();
		}
	}
}//fim da função guardaFicheiro


//****************************************************************
//* LerFicheiro Fornecedores
//****************************************************************
void lerFicheiroFornecedores(vector<Fornecedores>* fornecedores)
{
	string caminho = "";
	string nomeFicheiro = "Fornecedores.txt";
	string nomeCompleto = caminho + nomeFicheiro;
	cout << "File name: " << nomeCompleto.c_str() << "." << endl;

	fornecedores->erase(fornecedores->begin(), fornecedores->end());

	cout << "Reading file..." << endl;
	// 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
	ifstream ficheiroLF;
	ficheiroLF.open(nomeCompleto, ios::in);

	if (ficheiroLF.is_open())
	{
		Fornecedores fornecedor;
		//leitura dos objectos
		int cFornecedores = 0;
		while (ficheiroLF >> fornecedor && !ficheiroLF.eof())
		{
			fornecedores->push_back(fornecedor);
			cFornecedores++;
			cout << "Supplier " << cFornecedores << ": " << endl;
		}
		ficheiroLF.close();
		cout << endl;
	}
}//fim das funções dos fornecedores





//*********************************************
//*				FUNÇÕES ENCOMENDAS
//*********************************************

void mostraMenuEncomenda()
{
	system("color B");
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*                             1. Add order.                                   *" << endl;
	cout << "*                             2. Show order list.                             *" << endl;
	cout << "*                             3. Pay invoice.                                 *" << endl;
	cout << "*                             4. Main menu.                                   *" << endl;
	cout << "*                                                                             *" << endl;
	cout << "*******************************************************************************" << endl;
	cout << endl;
}

//*********************************************
//* Função "obtemEscolhaEncomenda()"
//* Entrada(s): int escolha 
//* Saida(s): int
//*********************************************
int obtemEscolhaEncomenda(int escolha)
{
	cout << "Choose your option (1-4)" << endl;
	cin >> escolha; cin.ignore();
	return escolha;
} // Fim do "obtemEscolha()".



//**********************************************
//*  Função processaEscolhaEncomenda()"
//*    Entradas: vector<Livro>& livros, int numLivros,
//*              char escolha, bool queroSair.
//*    Saida(s): bool queroSair.
//**********************************************
bool processaEscolhaEncomenda(vector<Encomendas>* encomendas, vector<Fornecedores>* fornecedores, vector<Jogo>* jogos, int escolha, bool queroSair)
{
	switch (escolha)
	{
	case 1:
	{
		inserirEncomenda(encomendas, fornecedores, jogos);
		guardaFicheiroEncomendas(*encomendas);
		break;
	}
	case 2:
	{
		listarEncomendas(*encomendas);
		break;
	}
	case 3:
	{
		pagarFatura(encomendas, jogos);
		guardaFicheiroEncomendas(*encomendas);
		break;
	}
	case 4:
	{
		queroSair = sairDoProgramaEncomendas(queroSair);
		break;
	}
	default:
		escolhaInvalida();
	} // Fim do "switch"

	return queroSair;
} // Fim da Função "processaEscolhaFornecedor()".


//**********************************************
//*  Função inserirEncomenda()"
//*    Entradas: vector<Fornecedor>& fornecedores, int numFornecedores.
//*    Saida(s): não tem.
//**********************************************

void inserirEncomenda(vector<Encomendas>* encomendas, vector<Fornecedores>* fornecedores, vector<Jogo>* jogos)
{
	// Cria um novo objeto de encomenda
	Encomendas* encomenda = new Encomendas;

	// Lê os dados da nova encomenda
	encomenda->readAllEncomenda(*fornecedores, *jogos);

	// Mostra o número atual de encomendas
	int nEncomendas = static_cast<int>(encomendas->size());
	cout << "Number of orders: " << nEncomendas << "." << endl;

	// Adiciona a nova encomenda ao vetor
	encomendas->push_back(*encomenda);
	Encomendas::numEncomendas++;

	// Exibe os detalhes da nova encomenda
	encomendas->at(nEncomendas).showAllEncomendas();

	// Atualiza e mostra o novo número de encomendas
	nEncomendas = static_cast<int>(encomendas->size());
	cout << "Number of orders: " << nEncomendas << "." << endl;
	cout << "Order inserted successfully!" << endl;


	pausa();
}




//**********************************************
//*    Função listarEncomendas()"
//*    Entradas: vector<Encomendas> encomendas
//*    Saida(s): não tem.
//**********************************************
void listarEncomendas(vector<Encomendas> encomendas)
{
	int nEncomendas = static_cast<int>(encomendas.size());

	if (nEncomendas <= 0)
	{
		cout << "Currently there are no registered orders." << endl;
		pausa();
	}
	else
	{
		for (int i = 0; i < nEncomendas; i++)
		{
			cout << i + 1 << ". ";
			encomendas[i].showAllEncomendas();
		}
		pausa();
	}
}//fim do listarEncomendas


//**********************************************
//*    Função pagarFatura()"
//*    Entradas: vector<Encomendas> &encomendas, vector<Jogo> &jogos
//*    Saida(s): não tem.
//**********************************************
void pagarFatura(vector<Encomendas>* encomendas, vector<Jogo>* jogos)
{
	int nEncomendas = static_cast<int>(encomendas->size());
	bool foundPending = false;

	if (nEncomendas <= 0)
	{
		cout << "Currently there are no registered orders." << endl;
		pausa();
		return;
	}

	cout << "List of pending orders:" << endl;
	for (int i = 0; i < nEncomendas; i++)
	{
		if ((*encomendas)[i].getEstadoEncomenda() == "Pending")
		{
			foundPending = true;
			//cout << "ID: " << encomendas[i].getIDEncomenda() << " - ";
			(*encomendas)[i].showAllEncomendas();  // Show all details of the order
		}
	}

	if (!foundPending)
	{
		cout << "No pending orders found." << endl;
		pausa();
		return;
	}

	int idEncomenda;
	cout << "Enter the ID of the order you want to pay: ";
	cin >> idEncomenda;

	bool orderFound = false;
	for (int i = 0; i < nEncomendas; i++)
	{
		if ((*encomendas)[i].getIDEncomenda() == idEncomenda && (*encomendas)[i].getEstadoEncomenda() == "Pending")
		{
			orderFound = true;
			(*encomendas)[i].setEstadoEncomenda("Complete");

			vector<pair<string, int>> produtos = (*encomendas)[i].getProdutos();

			for (const auto& produto : produtos)
			{
				string produtoId = produto.first;
				int quantidade = produto.second;

				for (size_t k = 0; k < jogos->size(); k++)
				{
					if ((*jogos)[k].getTitle() == produtoId) 
					{
						(*jogos)[k].addCopies(quantidade); 
						break;
					}
				}
			}

			cout << "Order with ID " << idEncomenda << " has been paid and marked as Complete." << endl;
			break;
		}
	}

	if (!orderFound)
	{
		cout << "Order with ID " << idEncomenda << " was not found or is not pending." << endl;
	}

	pausa();
}


//*************************************************
//*  Função "sairDoProgramaEncomendas()"
//*   Entrada(s): queroSair (bool) 
//*   Saida(s): queroSair (bool)
//*************************************************
bool sairDoProgramaEncomendas(bool queroSair)
{
	char resposta = '\0';
	fflush(stdin);
	cout << "Are you sure? (Y/N)? ";
	cin >> resposta; cin.ignore();
	if (resposta == 'y' || resposta == 'Y')
		queroSair = true;
	return queroSair;
} // Fim da função "sairDoProgramaFornecedores()".




//****************************************************************
//* GravarFicheiro Encomendas
//****************************************************************
void guardaFicheiroEncomendas(vector<Encomendas> encomendas)
{
	string caminho = "";
	string nomeFicheiro = "Encomendas.txt";
	string nomeCompleto = caminho + nomeFicheiro;
	cout << "File name: " << nomeCompleto.c_str() << "." << endl;

	// Criar o objeto e abrir o ficheiro
	ofstream ficheiroE;
	ficheiroE.open(nomeCompleto, ios::out); // Modos de abertura: "ios::out" -> escrita

	if (!ficheiroE)
	{
		cout << "File not open..." << endl;
		cout << "Press any key to continue ... ";
		cin.get();
	}
	else
	{
		int nEncomendas = static_cast<int>(encomendas.size());
		cout << "Available orders: " << nEncomendas << endl;
		if (nEncomendas <= 0)
		{
			cout << "Currently there are no registered orders." << endl;
			cout << "Press any key to continue ... " << endl;
			cin.get();
		}
		else
		{
			cout << "Saving orders..." << endl;
			for (int i = 0; i < nEncomendas; i++)
				ficheiroE << encomendas[i];
			ficheiroE.close();
			cout << "Data saved successfully!" << endl;
			cout << "Press any key to continue ... ";
			cin.get();
		}
	}
}//fim da função guardaFicheiroEncomendas

//****************************************************************
//* LerFicheiro Encomendas
//****************************************************************
void lerFicheiroEncomendas(vector<Encomendas>* encomendas)
{
	string caminho = "";
	string nomeFicheiro = "Encomendas.txt";
	string nomeCompleto = caminho + nomeFicheiro;
	cout << "File name: " << nomeCompleto.c_str() << "." << endl;

	encomendas->erase(encomendas->begin(), encomendas->end());

	cout << "Reading file..." << endl;
	// Criar o objeto e abrir o ficheiro
	ifstream ficheiroLE;
	ficheiroLE.open(nomeCompleto, ios::in);

	if (ficheiroLE.is_open())
	{
		Encomendas encomenda;
		// Leitura dos objetos
		int cEncomendas = 0;
		while (ficheiroLE >> encomenda && !ficheiroLE.eof())
		{
			encomendas->push_back(encomenda);
			cEncomendas++;
			cout << "Order " << cEncomendas << ": " << endl;
		}
		ficheiroLE.close();
		cout << endl;
	}
}//fim da função lerFicheiroEncomendas




//*********************************************
//*				FUNÇÕES COMUNS
//*********************************************

//**********************************************
//*  Função "pausa()"
//*    Entradas: não tem.
//*    Saida(s): não tem.
//**********************************************
void pausa()
{
	cout << "Press any key to continue ... ";
	cin.get();
} // Fim da função "pausa()".


//**************************************************
//* Função "escolhaInvalida()"
//*  Entrada(s): não tem.
//*  Saida(s): não tem.
//**************************************************
//**************************************************
//* Função escolhaInvalida()
//***************************************************
void escolhaInvalida()
{
	cout << "Wrong option! Choice must be between 1-8..." << endl;
	pausa();
} // Fim da função "escolhaInvalida()".


//***************************************************
//*  Função "despedida()"
//*   Entrada(s): não tem.
//*   Saida(s): não tem.
//***************************************************
void despedida()
{
	cout << "Thank you for using our app, see you soon...";
	cout << "Press any key to continue... ";
	cin.get();
} // Fim da função "despedida()".
