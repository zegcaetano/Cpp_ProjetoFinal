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
using namespace std;

// DESLOCAMENTO ENCRIPTA��O
const int DESLOCAMENTO1 = 3;



class Fornecedores
{
private:
	string	nomeFornecedor;
	string	contacto;
	string	morada;
	string	NIF;
	string	termosPagamento;
	int		rating;


	bool validarTelefone(const std::string& telefone) {
		// Express�o regular para validar n�meros de telefone portugueses (fixos e m�veis)
		std::regex padraoTelefone(R"(^((2\d{8})|(9[1236]\d{7}))$)");
		return std::regex_match(telefone, padraoTelefone);
	}

	bool validarNIF(const string& nif) {
		// Express�o regular para validar o NIF (9 d�gitos)
		regex padraoNIF(R"(^\d{9}$)");
		return regex_match(nif, padraoNIF);
	}

	//****************************************************
	//* Fun��o encripta()
	//****************************************************
	string  encripta(string mensagemO, int desl)
	{
		const int MAXCHARS = 100;
		char mensagem[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			mensagem[cLetra] = '\0';

		strcpy_s(mensagem, mensagemO.c_str());

		//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
		//    mensagem[cLetra]=toupper(mensagem[cLetra]);

		for (int cLetra = 0; cLetra < mensagemO.length(); cLetra++)
		{
			int valor = (int)mensagem[cLetra] + desl;
			if (((valor) > 90 && isupper(mensagem[cLetra]))
				|| ((valor) > 122 && islower(mensagem[cLetra]))
				)
				valor = valor - 26;
			if (mensagem[cLetra] == '.')
				mensagem[cLetra] = '.';
			else if (!isalpha(mensagem[cLetra]))
				mensagem[cLetra] = mensagem[cLetra];
			else
				mensagem[cLetra] = valor;
		}
		//cout<<mensagem;	
		return mensagem;
	}
//fim da fun��o encripta



//****************************************************
//* Fun��o desencripta()
//****************************************************
	string  desencripta(string mensagemE, int desl)
	{
		const int MAXCHARS = 100;
		char mensagem[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			mensagem[cLetra] = '\0';

		strcpy_s(mensagem, mensagemE.c_str());

		//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
		//    mensagem[cLetra]=toupper(mensagem[cLetra]);

		for (int cLetra = 0; cLetra < mensagemE.length(); cLetra++)
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
	}//fim da fun��o desencripta()

//****************************************************
//* Fun��o desencripta()
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
	}//fim da fun��o desencriptaII()

//****************************************************
//* Fun��o desencripta()
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
	}//fim da fun��o desencriptaIII()



public:
	// Fun��es devem ser p�blicas 
	// Dados est�ticos
	static int numFornecedores;

	// 2. Fun��es
	// 2.0 Fun��es de inicializa��o
	void inicializaFornecedor()
	{
		nomeFornecedor = "";
		contacto = "";
		morada = "";
		NIF = "";
		termosPagamento = "";
		rating = 0;
	}

	// 2.1  Fun��es construtoras
	//      Servem para inicializar os dados de cada objeto.

	// 2.1.1 Construtor sem argumentos


	Fornecedores()
	{
		nomeFornecedor = "";
		contacto = "";
		morada = "";
		NIF = "";
		termosPagamento = "";
		rating = 0;
	}

	Fornecedores(string nf)
	{
		nomeFornecedor.assign(nf);
		contacto = "";
		morada = "";
		NIF = "";
		termosPagamento = "";
		rating = 0;
	}

	Fornecedores(int ra)
	{
		nomeFornecedor = "";
		contacto = "";
		morada = "";
		NIF = "";
		termosPagamento = "";
		rating = ra;
	}

	Fornecedores(string con, string mor)
	{
		nomeFornecedor = "";
		contacto.assign(con);
		morada.assign(mor);
		NIF = "";
		termosPagamento = "";
		rating = 0;
	}

	Fornecedores(string nf, string con, string mor, string nif, string tp, int r)
	{
		nomeFornecedor.assign(nf);
		contacto.assign(con);
		morada.assign(mor);
		NIF.assign(nif);
		termosPagamento.assign(tp);
		rating = r;
	}

	// 2.2 Destrutor
	//     C�digo que � executado antes de um objeto
	//     sair de mem�ria.
	~Fornecedores() {
	}

	// 2.3 Setters
	//     Permitem a atribui��o de valores a cada 
	//     dado de um objeto.
	void setNomeFornecedor(string nf) { nomeFornecedor = nf; }
	void setContacto(string con) { contacto = con; }
	void setMorada(string mor) { morada = mor; }
	void setNIF(string nif) { NIF = nif; }
	void setTermosPagamento(string tp) { termosPagamento = tp; }
	void setRating(int r) { rating = r; }



	// 2.4 Getters
	//     Permitem a obten��o do valor de  cada 
	//     dado de um objeto.
	string getNomeFornecedor() { return nomeFornecedor; }
	string getContacto() { return contacto; }
	string getMorada() { return morada; }
	string getNIF() { return NIF; }
	string getTermosPagamento() { return termosPagamento; }
	int getRating() { return rating; }




	// 2.5 Fun��es de Leitura

	void readNomeFornecedor()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Please enter the name of the supplier company: " << endl;
		cin.getline(letras, sizeof(letras), '\n');
		cout << endl;
		setNomeFornecedor(string(letras));
	}

	void readContacto()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		bool isValid = false;
		do {
			cout << "Please enter the phone number of the supplier company: " << endl;;
			cin.getline(letras, sizeof(letras), '\n');
			isValid = validarTelefone(string(letras));
			if (isValid)
			{
				cout << "Valid phone number" << endl;
				setContacto(string(letras));
			}
			else
			{
				cout << "Invalid phone number!" << endl;
			}
			cout << endl;

		} while (!isValid);
	}

	void readMorada()
	{
		const int MAXCHARS = 80;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Please enter the adress of the supplier company: " << endl;
		cin.getline(letras, sizeof(letras), '\n');
		cout << endl;
		setMorada(string(letras));
	}

	void readNIF()
	{
		const int MAXCHARS = 20;
		char letras[MAXCHARS];
		bool isValid = false;
		do {
			cout << "Please enter the NIF of the supplier company: " << endl;
			cin.getline(letras, sizeof(letras), '\n');

			// Verifique a validade do NIF e armazene o resultado
			isValid = validarNIF(string(letras));
			if (isValid) {
				cout << "Valid NIF." << endl;
				setNIF(string(letras));
				 // Saia do loop se o NIF for v�lido
			}
			else {
				cout << "Invalid NIF. NIF must be exactly 9 digits." << endl;
			}
			cout << endl;

		} while (!isValid);
	}


	void readTermosPagamento()
	{
		vector<string> termosPagamentoDisponiveis = { "Cash on Delivery - COD", "Net 30", "Advance Payment", "Installment Payments" };
		string escolha;
		int opcao = 0;
		bool escolhaValida = false;


		cout << "Select the payment terms for this supplier: " << endl;
		// Exibir as plataformas dispon�veis
		for (size_t i = 0; i < termosPagamentoDisponiveis.size(); ++i) {
			cout << i + 1 << ". " << termosPagamentoDisponiveis[i] << endl;
		}

		while (!escolhaValida)
		{
			cout << "Type the number of the payment term you wish to add: " << endl;;
			cin >> escolha;
			cin.ignore();

			// Verifica se a escolha � um n�mero e se est� dentro do intervalo
			/*try {*/
				opcao = stoi(escolha);
				if (opcao >= 1 && opcao <= termosPagamentoDisponiveis.size()) {
					string termoEscolhido = termosPagamentoDisponiveis[opcao - 1];
					setTermosPagamento(termoEscolhido);
					cout << "Payment term set successfully: " << termoEscolhido << endl;
					escolhaValida = true;
				}
				else {
					cout << "Wrong option. Try again." << endl;
				}
			/*}*/
			/*catch (const invalid_argument& ia)
			{
				cout << "Invalid input. Please enter a number." << endl;
			}*/
		}
	}

	void readRating()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		int rating = 0;
	do {
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
			cout << "Please enter the rating of the supplier: " << endl;;
			cin.getline(letras, sizeof(letras), '\n');
			rating = atoi(letras);
			if (rating < 1 || rating > 5)
			{
				cout << "The rating must be between 1 and 5..." << endl;
			}
			else
			{
				cout << endl;
				setRating(rating);
				cout << "Rating inserted successfully!" << endl;
			}
		} while (rating < 1 || rating > 5);
	}


		void readAllFornecedores()
		{
			readNomeFornecedor();	readContacto();
			readMorada();			readNIF();
			readTermosPagamento();	readRating();
			cout << endl;			cout << endl;
		}

//fun��es de escrita da classe "Fornecedores"
		void showNomeFornecedor()
		{
			cout << "Name: " << getNomeFornecedor() << "." << endl;
		}

		void showContacto()
		{
			cout << "Contact: " << getContacto() << endl;
		}

		void showMorada()
		{
			cout << "Adress: " << getMorada() << "." << endl;
		}

		void showNIF()
		{
			cout << "NIF: " << getNIF() << endl;
		}

		void showTermosPagamento()
		{
			cout << "Payment terms: " << getTermosPagamento() << "." << endl;
		}

		void showRating()
		{
			cout << "Rating: " << getRating() << endl;
		}

		void showAllFornecedores()
		{
			showNomeFornecedor();	showContacto();
			showMorada();			showNIF();
			showTermosPagamento();	showRating();
			cout << endl;			cout << endl;
		}

		void mostraNome()
		{
			cout << getNomeFornecedor() << endl;
		}


//*************************************************************************************
//* Redefini��o do operador ">>" na classe Jogo
//**************************************************************************************
		friend istream& operator>> (istream& is, Fornecedores& forne)
		{
			char letra = '\0';


			{
				const int MAXNOME = 40; char texto[MAXNOME];
				for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
					texto[cLetra] = '\0';
				is.getline(texto, MAXNOME, '\n');
				forne.setNomeFornecedor(forne.desencripta(string(texto), DESLOCAMENTO1));
			}

			{
				const int MAXNOME = 40; char texto[MAXNOME];
				for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
				is.getline(texto, MAXNOME, '\n');
				forne.setContacto(forne.desencripta(string(texto), DESLOCAMENTO1));
			}

			{
				const int MAXNOME = 40; char texto[MAXNOME];
				for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
				is.getline(texto, MAXNOME, '\n');
				forne.setMorada(forne.desencripta(string(texto), DESLOCAMENTO1));
			}

			{
				const int MAXNOME = 40; char texto[MAXNOME];
				for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
				is.getline(texto, MAXNOME, '\n');
				forne.setNIF(forne.desencripta(string(texto), DESLOCAMENTO1));
			}


			{
				const int MAXNOME = 40; char texto[MAXNOME];
				for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
				is.getline(texto, MAXNOME, '\n');
				forne.setTermosPagamento(forne.desencripta(string(texto), DESLOCAMENTO1));
			}



			{
				const int MAXNOME = 40; char texto[MAXNOME];
				for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
					texto[cLetra] = '\0';
				is.getline(texto, MAXNOME, '\n');
				strcpy_s(texto, forne.desencriptaII(texto, DESLOCAMENTO1));
				forne.setRating(atoi(texto));
			}


			is.ignore();
			return is;
		}//fim da redefini��o do operador ">>"


//*************************************************************************************
//* Redefini��o do operador "<<" na classe Jogo
//**************************************************************************************

		friend ostream& operator<< (ostream& os, Fornecedores& forne)
		{

			os << forne.encripta(forne.getNomeFornecedor(), DESLOCAMENTO1) << endl;
			os << forne.encripta(forne.getContacto(), DESLOCAMENTO1) << endl;
			os << forne.encripta(forne.getMorada(), DESLOCAMENTO1) << endl;
			os << forne.encripta(forne.getNIF(), DESLOCAMENTO1) << endl;
			os << forne.encripta(forne.getTermosPagamento(), DESLOCAMENTO1) << endl;
			os << forne.encripta(to_string(forne.getRating()), DESLOCAMENTO1) << endl;
			os << endl;
			return os;
		}//fim da redefini��o do operador "<<"
};//fim da classe fornecedores


