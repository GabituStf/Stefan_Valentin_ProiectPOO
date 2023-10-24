#include <iostream>

using namespace std;


class Angajat {

public:

	const int id;

	string nume;

	int varsta;

	float salariu; //mii lei

	static int varstaPensionare;

	char* domeniu;


	Angajat() :id(14)

	{

		this->nume = "Solea Ianis";

		this->varsta = 34;

		this->salariu = 3.2;

		this->domeniu = new char[strlen("Vanzator") + 1];

		strcpy_s(domeniu, strlen("Vanzator") + 1, "Vanzator");


	}



	Angajat(int idNou, float salariuNou) :id(idNou), salariu(salariuNou)
	
	{

		this->nume = "Serban Ovidiu";

		this->varsta = 21;

		this->domeniu = new char[strlen("Contabilitate") + 1];

		strcpy_s(domeniu, strlen("Contabilitate") + 1, "Contabilitate");


	}


	Angajat(int idNou, float salariuNou,string numeNou, int varstaNoua, char* domeniuNou) :id(idNou), salariu(salariuNou),nume(numeNou), varsta(varstaNoua), domeniu(domeniuNou) {

	}


	~Angajat() {


		if (this->domeniu != NULL)
			
		{

			delete[]this->domeniu;

		}
	}

	void afisare() {

		cout << id << "." << "Nume angajat: "<< nume << endl;

		cout<< "Varsta: " << varsta << endl;
		
		cout << "Salariu: " << salariu << " mii lei" << endl;
		
		cout << "Ocupatie: " << domeniu << endl;
		
		cout << "Varsta pensionare: " << varstaPensionare << endl;
		
		cout << endl;


	}

	static void setvarstaPensionare(int varstaNoua) {

		varstaPensionare = varstaNoua;

	}

};

int Angajat::varstaPensionare = 65;



class Sediu {


public:

	int nrCamere;

	float suprafata;

	char* locatie;

	string numarTelefon;

	static int nrTotalSedii;

	const int id;

	Sediu() :id(7) {

		this->nrCamere = 4;

		this->suprafata = 107;

		this->numarTelefon = "0734432360";

		this->locatie = new char[strlen("Bucuresti") + 1];

		strcpy_s(locatie, strlen("Bucuresti") + 1, "Bucuresti");


	}


	Sediu(int idNou, string numarNou) :id(idNou), numarTelefon(numarNou) {

		this->nrCamere = 2;

		this->suprafata = 57;

		this->locatie = new char[strlen("Targoviste") + 1];

		strcpy_s(locatie, strlen("Targoviste") + 1, "Targoviste");

	}

	Sediu(int idNou, int nrCamereNoi, float suprafataNoua, string numarNou, char* locatieNoua) :id(idNou), nrCamere(nrCamereNoi
	), suprafata(suprafataNoua), numarTelefon(numarNou), locatie(locatieNoua) {

	}

	~Sediu() {

		if (this->locatie != NULL)
		
		{

			delete[]this->locatie;
		}

	}

	void afisare() {

		cout << id << "." << "Locatie sediu: " << locatie;
		
		cout << endl << "Numar camere: " << nrCamere << endl;
		
		cout << "Suprafata: " << suprafata << " metri patrati" << endl;

		cout << "Numar telefon: " << numarTelefon << endl;

		cout << "Numar total sedii: " << nrTotalSedii << endl << endl;


	}

	static void setnrTotalSedii(int nrNou) {

		nrTotalSedii = nrNou;

	}


};


int Sediu::nrTotalSedii = 3;



class Companie {

public:

	int anInfiintare;

	string nume;

	string domeniuActivitate;

	int numarAngajati;

	int* varsteAngajati;

	const int id;

	static string tara;

	Companie():id(1) {

		this->anInfiintare = 2022;

		this->nume = "Bussiness Pure SRL";

		this->domeniuActivitate = "Contabilitate";

		this->numarAngajati = 0;

		this->varsteAngajati = NULL;


	}


	Companie(int idNou, string numeNou) :id(idNou), nume(numeNou) {

		this->anInfiintare = 2019;

		this->domeniuActivitate = "Tranzactii Imobiliare";

		this->numarAngajati = 0;

		this->varsteAngajati = NULL;
	}

	Companie(int idNou,int anInfiintareNou, string numeNou, string domeniuNou,int numarAngajati, int* varsteAngajati):id(idNou),anInfiintare(anInfiintareNou),nume(numeNou),domeniuActivitate(domeniuNou),numarAngajati(numarAngajati){

		if (numarAngajati != 0) {

			this->varsteAngajati = new int[numarAngajati];

			for (int i = 0; i < numarAngajati; i++)

			{
				this->varsteAngajati[i] = varsteAngajati[i];

			}


		}

		else

			this->varsteAngajati = NULL;


	}

	~Companie() {

		if (this->varsteAngajati != NULL) {

			delete[]this->varsteAngajati;

		}


	}

	void afisare() {

		cout << id << "." << "Nume companie: " << nume << endl;

		cout << "An infiintare: " << anInfiintare << endl;

		cout << "Domeniu activitate: " << domeniuActivitate << endl;

		cout << "Numar angajati: " << numarAngajati << endl;

		cout << "Varste angajati(ani): ";

		if (varsteAngajati != NULL)

		{

			for (int i = 0; i < numarAngajati; i++)

			{

				cout << varsteAngajati[i] << ' ';

			}


		}

		else
		
		{

			    cout << " - ";
		    
		}

		cout << endl;


		cout << "Tara activitate: " << tara << endl << endl;
		
		

	}

	static void settara(string taraNoua) {

		tara = taraNoua;

	}




};

string Companie::tara = "Romania";


void main() {


	Companie companie1;
	companie1.afisare();


	Companie companie2(3, "La Canapele");
	companie2.afisare();

	int* varste = new int[3];
	varste[0] = 25;
	varste[1] = 37;
	varste[2] = 48;

	Companie companie3(4, 2017, "Trei Barcute SRL", "Inchirieri Cabane", 3, varste);
	companie3.afisare();

	companie1.settara("Franta");
	companie1.afisare();


	cout << "-----------------------------------\n\n";



	Sediu sediu1;
	sediu1.afisare();

	Sediu sediu2(10, "0742948226");
	sediu2.afisare();

	char* locatie;
	locatie = new char[strlen("Timisoara") + 1];
	strcpy_s(locatie, strlen("Timisoara") + 1, "Timisoara");

	Sediu sediu3(13, 3, 81, "0717945560", locatie);
	sediu3.afisare();

	sediu2.setnrTotalSedii(9);
	sediu2.afisare();


	cout << "-----------------------------------\n\n";


	Angajat angajat1;
	angajat1.afisare();

	Angajat angajat2(16, 6.5);
	angajat2.afisare();

	char* domeniu = new char[strlen("IT") + 1];

	strcpy_s(domeniu, strlen("IT") + 1, "IT");

	Angajat angajat3(19, 13, "Stefan Gabriel", 23, domeniu);
	angajat3.afisare();

	angajat3.setvarstaPensionare(70);
	angajat3.afisare();

	

	cout << "-----------------------------------\n\n";





}