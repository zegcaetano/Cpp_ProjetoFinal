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



// DESLOCAMENTO ENCRIPTAÇÃO
const int DESLOCAMENTO3 = 3;



class Jogo
{
private:
	string	title;
	string  developer;
	string	publisher;
	string	platforms;
	string	releaseDate;
	string	mode;
	string	genre;
	float	price;
	int		copies;
	bool	online;

	

	//****************************************************
	//* Função encripta()
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
	//fim da função encripta



//****************************************************
//* Função desencripta()
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


	//Encriptar e desencriptar boleanos
	string encriptaBool(bool valor, int desl)
	{
		string boolStr = valor ? "sim" : "nao";
		return encripta(boolStr, desl);
	}

	bool desencriptaBool(string msg, int desl)
	{
		string boolStr = desencripta(msg, desl);
		return (boolStr == "sim");
	}

	//funão que valida data
	bool isValidDate(const string& date) {
		int day, month, year;
		char delimiter1, delimiter2;

		// Tenta extrair dia, mês e ano
		stringstream ss(date);
		ss >> day >> delimiter1 >> month >> delimiter2 >> year;

		// Verifica se o formato está correto
		if (ss.fail() || delimiter1 != '/' || delimiter2 != '/' || !ss.eof()) {
			return false;
		}

		// Verifica se os valores estão dentro dos limites válidos
		if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
			return false;
		}

		// Verifica o número de dias em cada mês
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			return false;
		}
		if (month == 2) { // Fevereiro
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // Ano bissexto
				if (day > 29) return false;
			}
			else {
				if (day > 28) return false;
			}
		}

		return true;
	}





public:
	// Funções devem ser públicas 
	// Dados estáticos
	static int numJogos;

	
	void addCopies(int quantidade) {
        if (quantidade > 0) { // Garantir que a quantidade a adicionar é positiva
            copies += quantidade;
            cout << quantidade << " copies added. Total now: " << copies << " copies." << endl;
        } else {
            cout << "Invalid quantity. Must be positive." << endl;
        }
    }
	

	// 2. Funções
	// 2.0 Funções de inicialização
	void inicializaJogo()
	{
		title = "";
		developer = "";
		publisher = "";
		platforms = "";
		releaseDate = "";
		mode = "";
		genre = "";
		price = 0;
		copies = 0;
		online = false;
	}

	// 2.1  Funções construtoras
	//      Servem para inicializar os dados de cada objeto.

	// 2.1.1 Construtor sem argumentos
	Jogo()
	{
		title = "";
		developer = "";
		publisher = "";
		platforms = "";
		releaseDate = "";
		mode = "";
		genre = "";
		price = 0;
		copies = 0;
		online = false;
	}


	// 2.1.2 Construtor com um argumento
	Jogo(string tit)
	{
		title.assign(tit);
		developer = "";
		publisher = "";
		platforms = "";
		releaseDate = "";
		mode = "";
		genre = "";
		price = 0;
		copies = 0;
		online = false;
	}


	// 2.1.3 Construtor com dois argumentos
	Jogo(string tit, string pub)
	{
		title.assign(tit);
		developer = "";
		publisher.assign(pub);
		platforms = "";
		releaseDate = "";
		mode = "";
		genre = "";
		price = 0;
		copies = 0;
		online = false;
	}


	// 2.1.4 Construtor com três argumentos
	Jogo(string tit, string dev, string pub)
	{
		title.assign(tit);
		developer.assign(dev);
		publisher.assign(pub);
		platforms = "";
		releaseDate = "";
		mode = "";
		genre = "";
		price = 0;
		copies = 0;
		online = false;
	}


	// 2.1.5 Construtor com quatro argumentos
	Jogo(string tit, string dev, string pub, string plat)
	{
		title.assign(tit);
		developer.assign(dev);
		publisher.assign(pub);
		platforms.assign(plat);
		releaseDate = "";
		mode = "";
		genre = "";
		price = 0;
		copies = 0;
		online = false;
	}


	// 2.1.6 Construtor com oito argumentos
	Jogo(string tit, string dev, string pub, string plat, string date,
		string mod, string gen, float pri)
	{
		title.assign(tit);
		developer.assign(dev);
		publisher.assign(pub);
		platforms.assign(plat);
		releaseDate.assign(date);
		mode.assign(mod);
		genre.assign(gen);
		price = pri;
		copies = 0;
		online = false;
	}

	// 2.1.7 Construtor com dez argumentos
	Jogo(string tit, string dev, string pub, string plat, string date,
		string mod, string gen, float pri, int cop, bool onl)
	{
		title.assign(tit);
		developer.assign(dev);
		publisher.assign(pub);
		platforms.assign(plat);
		releaseDate.assign(date);
		mode.assign(mod);
		genre.assign(gen);
		price = pri;
		copies = cop;
		online = onl;
	}

	
	

	// 2.2 Destrutor
	//     Código que é executado antes de um objeto
	//     sair de memória.
	~Jogo() {
	}

	// 2.3 Setters
	//     Permitem a atribuição de valores a cada 
	//     dado de um objeto.
	void setTitle(string t)			{ title = t; }
	void setDeveloper(string d)		{ developer = d; }
	void setPublisher(string p)		{ publisher = p; }
	void setPlatforms(string pl)	{ platforms = pl; }
	void setReleaseDate(string rd)	{ releaseDate = rd; }
	void setMode(string m)			{ mode = m; }
	void setGenre(string g)			{ genre = g; }
	void setPrice(float pr)			{ price = pr; }
	void setCopies(int c)			{ copies = c; }
	void setOnline(bool o)			{ online = o; }

	// 2.4 Getters
	//     Permitem a obtenção do valor de  cada 
	//     dado de um objeto.
	string getTitle()		{ return title; }
	string getDeveloper()	{ return developer; }
	string getPublisher()	{ return publisher; }
	string getPlatforms()	{ return platforms; }
	string getReleaseDate() { return releaseDate; }
	string getMode()		{ return mode; }
	string getGenre()		{ return genre; }
	float  getPrice()		{ return price; }
	int    getCopies()		{ return copies; }
	bool   getOnline()		{ return online; }

	// 2.5 Funções de Leitura




	void readTitle()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Please insert the game's title: " << endl;
		cin.getline(letras, sizeof(letras), '\n');
		cout << endl;
		setTitle(string(letras));
	}



	void readDeveloper()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Please insert the game's developer(s): " << endl;
		cin.getline(letras, sizeof(letras), '\n');
		cout << endl;
		setDeveloper(string(letras));
	}



	void readPublisher()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Please insert the game's publisher: " << endl;
		cin.getline(letras, sizeof(letras), '\n');
		cout << endl;
		setPublisher(string(letras));
	}


	void readPlatform()
	{
		vector<string> plataformasDisponiveis = { "Playstation 5", "Xbox X/S", "PC(Windows)", "PC(macOS)", "Nintendo Switch", "Playstation 4", "Xbox One", "Steam Deck", "VR" };
		vector<string> plataformasEscolhidas;
		string escolha;
		char continuar;

		cout << "Choose the platforms on which the game is available: " << endl;
		// Exibir as plataformas disponíveis
		for (size_t i = 0; i < plataformasDisponiveis.size(); ++i) {
			cout << i + 1 << ". " << plataformasDisponiveis[i] << endl;
		}

		do {
			cout << "Type the number of the platform you wish to add (or 0 to quit): " << endl;;
			cin >> escolha;

			// Verifica se a escolha é um número e se está dentro do intervalo
			int opcao = stoi(escolha);
			if (opcao >= 1 && opcao <= plataformasDisponiveis.size()) {
				string plataformaEscolhida = plataformasDisponiveis[opcao - 1];

				// Verificar se a plataforma já foi escolhida
				if (find(plataformasEscolhidas.begin(), plataformasEscolhidas.end(), plataformaEscolhida) == plataformasEscolhidas.end()) {
					plataformasEscolhidas.push_back(plataformaEscolhida);
					cout << plataformaEscolhida << " Platform added successfully!" << endl;
					cout << endl;
				}
				else {
					cout << plataformaEscolhida << " Platform has already been added." << endl;
					cout << endl;
				}
			}
			else if (opcao == 0) {
				break; // Sair do loop
			}
			else {
				cout << "Wrong option. Try again." << endl;
				cout << endl;
			}

			// Pergunta ao usuário se deseja adicionar mais
			cout << "Do you wish to add more platforms? (y/n): " << endl;;
			cin >> continuar;
			cin.ignore(); // Limpar o buffer do cin
		} while (continuar == 'y' || continuar == 'Y');

		// Concatenar as plataformas escolhidas para armazenar
		string plataformasFinal;
		for (const auto& plat : plataformasEscolhidas) {
			if (!plataformasFinal.empty()) {
				plataformasFinal += ", ";
			}
			plataformasFinal += plat;
		}

		setPlatforms(plataformasFinal); // Salvar as plataformas escolhidas
	}




	void readReleaseDate() {
		string date;

		do {
			cout << "Please insert the release date of the game in the following format: dd/mm/yyyy" << endl;
			cin >> date;

			if (isValidDate(date)) {
				setReleaseDate(date);
				cout << "Release date registered: " << getReleaseDate() << endl;
				cout << endl;
				break; // Sai do loop se a data for válida
			}
			else {
				cout << "Invalid date or date format. Try again." << endl;
			}

		} while (true);
	}




	void readMode()
	{
		vector<string> modosDisponiveis = { "Single player", "Multiplayer", "Co-op", "Competitive", "Sandbox", "Turn-Based", "Time Trials" };
		vector<string> modosEscolhidos;
		string escolha;
		char continuar;

		cout << "Please choose from the available game modes: \n";
		// Exibir os modos disponíveis
		for (size_t i = 0; i < modosDisponiveis.size(); ++i) {
			cout << i + 1 << ". " << modosDisponiveis[i] << endl;
		}

		do {
			cout << "Type the number of the game mode you wish to add (or 0 to quit): " << endl;
			cin >> escolha;
			cout << endl;

			// Verifica se a escolha é um número e se está dentro do intervalo
			int opcao = stoi(escolha);
			if (opcao >= 1 && opcao <= modosDisponiveis.size()) {
				string modoEscolhido = modosDisponiveis[opcao - 1];

				// Verificar se o modo já foi escolhido
				if (find(modosEscolhidos.begin(), modosEscolhidos.end(), modoEscolhido) == modosEscolhidos.end()) {
					modosEscolhidos.push_back(modoEscolhido);
					cout << modoEscolhido << " game mode added successfully!" << endl;
				}
				else {
					cout << modoEscolhido << " game mode has already been added." << endl;
					
				}
			}
			else if (opcao == 0) {
				break; // Sair do loop
			}
			else {
				cout << "Wrong option. Try again." << endl;
				cout << endl;
			}

			// Pergunta ao usuário se deseja adicionar mais
			cout << "Do you wish to add more game modes? (y/n): " << endl;
			cin >> continuar;
			cin.ignore(); // Limpar o buffer do cin
		} while (continuar == 'y' || continuar == 'Y');

		// Concatenar os modos escolhidas para armazenar
		string modosFinal;
		for (const auto& plat : modosEscolhidos) {
			if (!modosFinal.empty()) {
				modosFinal += ", ";
			}
			modosFinal += plat;
		}

		setMode(modosFinal); // Salvar os modos escolhidas
	}




	void readGenre()
	{
		vector<string> generosDisponiveis = { "Action", "Adventure", "Role-Playing (RPG)", "Simulation", "Strategy", "Sports", "Puzzle", "Shooter", "Racing" };
		vector<string> generosEscolhidos;
		string escolha;
		char continuar;

		cout << "Please choose from the available game genres: \n";
		// Exibir os géneros disponíveis
		for (size_t i = 0; i < generosDisponiveis.size(); ++i) {
			cout << i + 1 << ". " << generosDisponiveis[i] << endl;
		}

		do {
			cout << "Type the number of the game genre you wish to add (or 0 to quit): " << endl;
			cin >> escolha;


			// Verifica se a escolha é um número e se está dentro do intervalo
			int opcao = stoi(escolha);
			if (opcao >= 1 && opcao <= generosDisponiveis.size()) {
				string generoEscolhido = generosDisponiveis[opcao - 1];

				// Verificar se o género já foi escolhido
				if (find(generosEscolhidos.begin(), generosEscolhidos.end(), generoEscolhido) == generosEscolhidos.end()) {
					generosEscolhidos.push_back(generoEscolhido);
					cout << generoEscolhido << " game genre added successfully!" << endl;
					cin.get();
					cout << endl;
				}
				else {
					cout << generoEscolhido << " game genre has already been added." << endl;
					cin.get();
					cout << endl;
				}
			}
			else if (opcao == 0) {
				break; // Sair do loop
			}
			else {
				cout << "Wrong option. Try again." << endl;
				cout << endl;
			}

			// Pergunta ao usuário se deseja adicionar mais
			cout << "Do you wish to add more game genres? (y/n): " << endl;
			cin >> continuar;
			cin.ignore();
			cout << endl;// Limpar o buffer do cin
		} while (continuar == 'y' || continuar == 'Y');

		// Concatenar os géneros escolhidas para armazenar
		string generosFinal;
		for (const auto& plat : generosEscolhidos) {
			if (!generosFinal.empty()) {
				generosFinal += ", ";
			}
			generosFinal += plat;
		}

		setGenre(generosFinal); // Salvar os modos escolhidas
	}





	void readPrice()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		// Regex para validar o formato do preço
		regex pricePattern(R"(\d{1,3},\d{2})");

		string input;
		bool valid = false;

		while (!valid) {
			cout << "Please insert the price of the game in the following format: XX,XX " << endl; // Deve colocar ","
			cin.getline(letras, sizeof(letras), '\n');
			cout << endl;
			input = string(letras);

			if (regex_match(input, pricePattern)) {
				valid = true;
				setPrice(static_cast<float>(atof(input.c_str())));
			}
			else {
				cout << "Invalid format. Please insert the price in the following format: XX,XX." << endl;
				cout << endl;
			}
		}
	}




	void readCopies()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		cout << "Please enter the number of available game copies: " << endl;;
		cin.getline(letras, sizeof(letras), '\n');
		cout << endl;
		setCopies(atoi(letras));
	}



	void readOnline() {
		int choice;
		bool valid = false;

		while (!valid) {
			cout << "Does the game have an online mode? (1.Yes/2.No): " << endl;
			cin >> choice;
			cout << endl;

			if (choice == 1) {
				setOnline(true);
				valid = true;
			}
			else if (choice == 2) {
				setOnline(false);
				valid = true;
			}
			else {
				cout << "Invalid option. Please choose 1 for Yes or 2 for No." << endl;
			}
		}
	}

	void readAllJogo()
	{
		readTitle();		readDeveloper();
		readPublisher();	readPlatform();
		readReleaseDate();	readMode();
		readGenre();		readPrice();
		readCopies();		readOnline();
	}

	//Funções de escrita
	void showTitle()
	{
		cout << "Title: " << getTitle() << "." << endl;
	}

	void showDeveloper()
	{
		cout << "Developer(s): " << getDeveloper() << "." << endl;
	}

	void showPublisher()
	{
		cout << "Publisher: " << getPublisher() << "." << endl;
	}

	void showPlatform()
	{
		cout << "Platform(s): " << getPlatforms() << "." << endl;
	}

	void showReleaseDate()
	{
		cout << "Release date: " << getReleaseDate() << "." << endl;
	}

	void showMode()
	{
		cout << "Mode(s): " << getMode() << "." << endl;
	}

	void showGenre()
	{
		cout << "Genre(s): " << getGenre() << "." << endl;
	}

	void showPrice()
	{
		//cout << fixed << setprecision(2); -> acho que não preciso porcausa da expressão regular, mas vamos ver...
		cout << "Price: " << getPrice() << " euros." << endl;
	}

	void showCopies()
	{
		cout << "Nr of copies: " << getCopies() << "." << endl;
	}

	void showOnline()
	{
		cout << "Online: " << (getOnline() ? "Yes" : "No") << "." << endl;
	}

	void mostraTitulo()
	{
		cout << getTitle() << endl;
	}

	void showAllJogo()
	{
		showTitle();		showDeveloper();
		showPublisher();	showReleaseDate();
		showPlatform();		showMode();
		showGenre();		showOnline();
		showCopies();		showPrice();
		cout << endl;		cout << endl;
	}




	//*************************************************************************************
	//* Redefinição do operador ">>" na classe Jogo
	//**************************************************************************************
	friend istream& operator>> (istream& is, Jogo& jog)
	{
		char letra = '\0';


		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
				texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			jog.setTitle(jog.desencripta(string(texto), DESLOCAMENTO3));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			jog.setDeveloper(jog.desencripta(string(texto), DESLOCAMENTO3));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			jog.setPublisher(jog.desencripta(string(texto), DESLOCAMENTO3));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			jog.setReleaseDate(jog.desencripta(string(texto), DESLOCAMENTO3));
		}


		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			jog.setPlatforms(jog.desencripta(string(texto), DESLOCAMENTO3));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			jog.setMode(jog.desencripta(string(texto), DESLOCAMENTO3));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			jog.setGenre(jog.desencripta(string(texto), DESLOCAMENTO3));
		}


		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
				texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			strcpy_s(texto, jog.desencriptaII(texto, DESLOCAMENTO3));
			jog.setCopies(atoi(texto));
		}



		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			strcpy_s(texto, jog.desencriptaII(texto, DESLOCAMENTO3));
			jog.setPrice(static_cast<float>(atof(texto)));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			string msg = string(texto);
			bool online = jog.desencriptaBool(msg, DESLOCAMENTO3);
			jog.setOnline(online);

		}
		is.ignore();
		return is;
	}//fim da redefinição do operador ">>"

//*************************************************************************************
//* Redefinição do operador "<<" na classe Jogo
//**************************************************************************************

	friend ostream& operator<< (ostream& os, Jogo& jog)
	{

		os << jog.encripta(jog.getTitle(), DESLOCAMENTO3) << endl;
		os << jog.encripta(jog.getDeveloper(), DESLOCAMENTO3) << endl;
		os << jog.encripta(jog.getPublisher(), DESLOCAMENTO3) << endl;
		os << jog.encripta(jog.getReleaseDate(), DESLOCAMENTO3) << endl;
		os << jog.encripta(jog.getPlatforms(), DESLOCAMENTO3) << endl;
		os << jog.encripta(jog.getMode(), DESLOCAMENTO3) << endl;
		os << jog.encripta(jog.getGenre(), DESLOCAMENTO3) << endl;
		os << jog.encripta(to_string(jog.getCopies()), DESLOCAMENTO3) << endl;
		os << jog.encripta(to_string(jog.getPrice()), DESLOCAMENTO3) << endl;
		os << jog.encriptaBool(jog.getOnline(), DESLOCAMENTO3) << endl;
		os << endl;
		return os;
	}//fim da redefinição do operador "<<"
};//fim da classe Jogo














