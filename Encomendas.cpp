#pragma once
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cstring>
#include <string>     // Classe "string"
#include <iostream>   // Objetos: "cin" e "cout"
#include <iomanip>    // "setprecision()".
#include <vector>
#include <sstream>
#include <regex>
#include <fstream>
#include "Fornecedores.cpp"
#include "Jogo.cpp"
#include "DataHora.cpp"
using namespace std;

// DESLOCAMENTO ENCRIPTAÇÃO
const int DESLOCAMENTO2 = 3;


class Encomendas
{
	int			idEncomenda = 0;
	string		idFornecedor = "";
	string		dataEncomenda = "";
	string		estadoEncomenda = "";
	vector<pair<string, int>> produtos;
	/*float		valorTotal = 0;*/




	// DESLOCAMENTO ENCRIPTAÇÃO
	const int DESLOCAMENTO = 3;


	//****************************************************
	//* Função encripta()
	//****************************************************
	string encripta(string mensagemO, int desl)
	{
		for (char& c : mensagemO) {
			if (isalpha(c)) {
				char limite = isupper(c) ? 'Z' : 'z'; // Define o limite
				c += desl; // Aplica o deslocamento
				if (c > limite) c -= 26; // Se ultrapassa o limite, volta ao início
			}
		}
		return mensagemO; // Retorna a string criptografada
	}


//****************************************************
//* Função desencripta()
//****************************************************
	string desencripta(string mensagemE, int desl)
	{
		for (char& c : mensagemE) {
			if (isalpha(c)) {
				char limite = isupper(c) ? 'A' : 'a'; // Define o limite
				c -= desl; // Aplica o deslocamento
				if (c < limite) c += 26; // Se ultrapassa o limite, vai ao final
			}
		}
		return mensagemE; // Retorna a string desencriptada
	}//fim da função desencripta()

//****************************************************
//* Função desencripta()
//****************************************************
	char* desencriptaII(char mensagemE[], int desl)
	{
		const int MAXCHARS = 100;
		char mensagem[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			mensagem[cLetra] = '\0';

		strcpy_s(mensagem, mensagemE);

		//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
		//    mensagem[cLetra]=toupper(mensagem[cLetra]);

		for (int cLetra = 0; cLetra < strlen(mensagemE); cLetra++)
		{
			int valor = (int)mensagem[cLetra] - desl;
			if (((valor) < 65 && isupper(mensagem[cLetra]))
				|| ((valor) < 97 && islower(mensagem[cLetra]))
				)

				valor = valor + 26;
			if (mensagem[cLetra] == '.')
				mensagem[cLetra] = '.';
			else if (!isalpha(mensagem[cLetra]))
				mensagem[cLetra] = mensagemE[cLetra];
			else
				mensagem[cLetra] = valor;
		}
		//cout<<mensagem;	
		return mensagem;
	}//fim da função desencriptaII()

//****************************************************
//* Função desencripta()
//****************************************************
	void  desencriptaIII(char mensagemE[], int desl, char mensagemO[])
	{
		const int MAXCHARS = 100;
		char mensagem[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			mensagem[cLetra] = '\0';

		strcpy_s(mensagem, mensagemE);

		//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
		//    mensagem[cLetra]=toupper(mensagem[cLetra]);

		for (int cLetra = 0; cLetra < strlen(mensagemE); cLetra++)
		{
			int valor = (int)mensagem[cLetra] - desl;
			if (((valor) < 65 && isupper(mensagem[cLetra]))
				|| ((valor) < 97 && islower(mensagem[cLetra]))
				)

				valor = valor + 26;
			if (mensagem[cLetra] == '.')
				mensagem[cLetra] = '.';
			else if (!isalpha(mensagem[cLetra]))
				mensagem[cLetra] = mensagemE[cLetra];
			else
				mensagem[cLetra] = valor;
		}
		//cout<<mensagem;	
		strcpy_s(mensagemO, sizeof(mensagemO), mensagem);
		//strcpy_s(destino, sizeof(destino), origem);
	}//fim da função desencriptaIII()




public:
	static int	nextID;
	static int numEncomendas;

	// 2. Funções
		// 2.0 Funções de inicialização

	//void resetValorTotal() {
	//	valorTotal = 0; 
	//}



	void inicializaEncomenda() {
		idEncomenda = 0;
		idFornecedor = "";
		dataEncomenda = "";
		estadoEncomenda = "";
		//valorTotal = 0.0f;
		produtos.clear(); // Limpa o vetor de produtos
	}

	Encomendas()
	{
		idEncomenda = nextID++;
		idFornecedor = "";
		DataEHoras dataAtual;
		dataEncomenda = dataAtual.currentDate();
		estadoEncomenda = "Pending";
		//valorTotal = 0.0f;
	}

	Encomendas(int ide)
	{
		idEncomenda = ide;
		idFornecedor = "";
		dataEncomenda = "";
		estadoEncomenda = "";
		//valorTotal = 0.0f;
	}

	Encomendas(string idf)
	{
		idEncomenda = 0;
		idFornecedor.assign(idf);
		dataEncomenda = "";
		estadoEncomenda = "";
		//valorTotal = 0.0f;
	}

	Encomendas(int ide, string idf)
	{
		idEncomenda = ide;
		idFornecedor.assign(idf);
		dataEncomenda = "";
		estadoEncomenda = "";
		//valorTotal = 0.0f;
	}

	Encomendas(string idf, string de)
	{
		idFornecedor.assign(idf);
		dataEncomenda.assign(de);
		estadoEncomenda = "Pending";
		idEncomenda = nextID++;
		//valorTotal = 0.0f;
	}

	// Construtor de cópia
	Encomendas(const Encomendas& other)
	{
		idEncomenda = other.idEncomenda;
		idFornecedor = other.idFornecedor;
		dataEncomenda = other.dataEncomenda;
		estadoEncomenda = other.estadoEncomenda;
		produtos = other.produtos;
		//valorTotal = other.valorTotal;
	}

	// Operador de atribuição
	Encomendas& operator=(const Encomendas& other)
	{
		if (this != &other) {
			idEncomenda = other.idEncomenda;
			idFornecedor = other.idFornecedor;
			dataEncomenda = other.dataEncomenda;
			estadoEncomenda = other.estadoEncomenda;
			produtos = other.produtos;
			//valorTotal = other.valorTotal;
		}
		return *this;
	}

	// 2.2 Destrutor
	//     Código que é executado antes de um objeto
	//     sair de memória.
	~Encomendas() {}


	// 2.3 Setters
	//    Permitem a atribuição de valores a cada 
	//    dado de um objeto.

	void setIDEncomenda(int ide) { idEncomenda = ide; }
	void setIDFornecedor(string idf) { idFornecedor = idf; }
	void setDataEncomenda(string de) { dataEncomenda = de; }
	void setEstadoEncomenda(string ee) { estadoEncomenda = ee; }
	//void setValorTotal(float vt) { valorTotal = vt; }
	void setProdutos(string nome, int quantidade) {
		produtos.push_back(make_pair(nome, quantidade));
	/*	valorTotal += (quantidade * preco);*/
	}

	//2.4 Getters
	//    Permitem a obtenção do valor de  cada 
	//    dado de um objeto.

	int getIDEncomenda() { return idEncomenda; }
	string getIDFornecedor() { return idFornecedor; }
	string getDataEncomenda() { return dataEncomenda; }
	string getEstadoEncomenda() { return estadoEncomenda; }
	//float getValorTotal() { return valorTotal; }
	vector<pair<string, int>> getProdutos() { return produtos; }






	//funções de leitura
	void readFornecedor(vector<Fornecedores> fornecedores) {
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		bool valido = false;
		int nFornecedores = static_cast<int>(fornecedores.size());

		while (!valido)
		{
			for (int i = 0; i < nFornecedores; i++)
			{
				cout << i + 1 << ". ";
				fornecedores[i].mostraNome();
			}
			cout << "Insert the name of the supplier: " << endl;
			cin.getline(letras, sizeof(letras), '\n');

			// Verifica se o fornecedor existe
			for (auto& f : fornecedores)
			{
				if (f.getNomeFornecedor() == letras)
				{
					setIDFornecedor(f.getNomeFornecedor());
					valido = true;
					break;
				}
			}
			if (!valido) {
				cout << "Supplier not found. Please try again." << endl;
			}
		}

	}


	void readProduto(vector<Jogo> jogos) {
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		bool valido = false;
		int nJogos = static_cast<int>(jogos.size());

		while (!valido)
		{
			for (int i = 0; i < nJogos; i++)
			{
				cout << i + 1 << ". ";
				jogos[i].mostraTitulo();
			}
			cout << "Insert the name of the game you wish to add to your order: " << endl;
			cin.getline(letras, sizeof(letras), '\n');

			// Verifica se o fornecedor existe
			for (auto& j : jogos)
			{
				if (j.getTitle() == letras)
				{
					int quantidade = 0;
					cout << "Insert the number of copies you wish to add to your order: " << endl;
					cin >> quantidade;

					setProdutos(letras, quantidade);
					valido = true;
					break;

				}
			}
			if (!valido) {
				cout << "Game not found. Please try again." << endl;
			}
		}

	}

	void readAllEncomenda(vector<Fornecedores>& fornecedores, vector<Jogo>& jogos)
	{
		readFornecedor(fornecedores); readProduto(jogos);
	}

	// Métodos de exibição para cada atributo


	void showIDEncomenda() {
		cout << "Order ID: " << getIDEncomenda() << "." << endl;
	}

	void showIDFornecedor() {
		cout << "Supplier: " << getIDFornecedor() << "." << endl;
	}

	void showDataEncomenda() {
		cout << "Order date: " << getDataEncomenda() << endl;
	}

	void showEstadoEncomenda() {
		cout << "Status: " << getEstadoEncomenda() << "." << endl;
	}

	//void showValorTotal() {
	//	cout << "Total: " << fixed << setprecision(2) << getValorTotal() << "euros." << endl;
	//}

	void showProdutos() {
		cout << "Order's products:" << endl;
		for (auto& produto : getProdutos()) {
			cout << "Game: " << produto.first << ", Copies: " << produto.second << "." << endl;
		}
	}

	// Método para mostrar todos os dados da encomenda
	void showAllEncomendas() {
		showIDEncomenda();
		showIDFornecedor();
		showDataEncomenda();
		showEstadoEncomenda();
		//showValorTotal();
		showProdutos();
		cout << endl;	
		cout << endl;
	}



	//*************************************************************************************
	//* Redefinição do operador ">>" na classe Encomendas
	//**************************************************************************************
	friend istream& operator>>(istream& is, Encomendas& enc) {
		string linha;

		//enc.resetValorTotal();
		enc.produtos.clear();

		// Leitura do ID da Encomenda
		if (getline(is, linha) && !linha.empty()) {
			enc.setIDEncomenda(atoi(linha.c_str()));
		}

		// Leitura do ID do Fornecedor
		if (getline(is, linha) && !linha.empty()) {
			enc.setIDFornecedor(enc.desencripta(linha, DESLOCAMENTO2));
		}

		// Leitura da Data da Encomenda
		if (getline(is, linha) && !linha.empty()) {
			enc.setDataEncomenda(enc.desencripta(linha, DESLOCAMENTO2));
		}

		// Leitura do Estado da Encomenda
		if (getline(is, linha) && !linha.empty()) {
			enc.setEstadoEncomenda(enc.desencripta(linha, DESLOCAMENTO2));
		}

		// Leitura do Produto
		if (getline(is, linha) && !linha.empty()) {
			string nomeProduto = enc.desencripta(linha, DESLOCAMENTO2);


			// Leitura da quantidade
			if (getline(is, linha) && !linha.empty()) {
				int quantidade = stoi(linha);

				// Leitura do preço
				/*if (getline(is, linha) && !linha.empty()) {
					float preco = stof(linha);*/
				enc.setProdutos(nomeProduto, quantidade);
				/*				enc.recalcularValorTotal();*/



			}

		}
		return is;
	}
		
		
	
		
		

		
	//fim da redefinição do operador ">>"

	//*************************************************************************************
	//* Redefinição do operador "<<" na classe Encomendas
	//**************************************************************************************

	friend ostream& operator<< (ostream& os, Encomendas& enc)
	{
		// Bloco 1: ID da Encomenda, ID do Fornecedor, Data e Estado
		os << enc.encripta(to_string(enc.getIDEncomenda()), DESLOCAMENTO2) << '\n'; // ID da Encomenda (criptografado)
		os << enc.encripta(enc.getIDFornecedor(), DESLOCAMENTO2) << '\n'; // ID do Fornecedor (criptografado)
		os << enc.encripta(enc.getDataEncomenda(), DESLOCAMENTO2) << '\n'; // Data da Encomenda (criptografada)
		os << enc.encripta(enc.getEstadoEncomenda(), DESLOCAMENTO2) << '\n'; // Estado da Encomenda (criptografado)

		
		for (auto& produto : enc.getProdutos()) {
			os << enc.encripta(produto.first, DESLOCAMENTO2) << '\n'; // Nome do Produto (criptografado)
			os << produto.second << '\n'; // Quantidade
		}

		// Adicionar valor total ao final do bloco 2
		//os << enc.getValorTotal() << '\n'; // Total da Encomenda


		return os;
	}

};
