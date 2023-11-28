
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class Angajat {

private:

	const int id;
	string nume;
	int varsta;
	float salariu; //mii lei
	static int varstaPensionare;
	char* domeniu;

public:

	int operator()() {
		int a = 0;
		if (Angajat::varstaPensionare > this->varsta) {
			a = Angajat::varstaPensionare - this->varsta;
			return a;
		}
		else
		{
			return a;
		}
	}

	explicit operator string(){
		return this->nume;
	}

	explicit operator int() {
		return this->varsta;
	}

	explicit operator float() {
		return this->salariu;
	}

	
	const int getIDAngajat()  {

		return this->id;
	}

	static int getVarstaPensionare() {

		return Angajat::varstaPensionare;

	}

	static void setvarstaPensionare(int varstaNoua) {

		if (varstaNoua > 0) {

			Angajat::varstaPensionare = varstaNoua;

		}
	}

	void setNumeAngajat(string numeNou) {

		if (numeNou.length() > 2) {

			this->nume = numeNou;

		}

	}

	string getNumeAngajat() {

		return this->nume;

	}

	void setVarstaAngajat(int varstaA) {

		if (varstaA > 18) {

			this->varsta = varstaA;

		}


	}

	int getVarstaAngajat() {

		return this->varsta;

	}

	void setSalariuAngajat(float salariuN) {

		if (salariuN > 0) {

			this->salariu = salariuN;

		}

	}

	float getSalariuAngajat() {

		return this->salariu;

	}

	void setDomeniuAngajat(const char* domeniuNou) {

		if (this->domeniu != NULL && strlen(domeniuNou) >= 2) {

			if (this->domeniu != NULL) {

				delete[]this->domeniu;

			}

			this->domeniu = new char[strlen(domeniuNou) + 1];

			strcpy_s(domeniu, strlen(domeniuNou) + 1, domeniuNou);

		}




	}

	const char* getDomeniuAngajat() {

		return this->domeniu;

	}

	Angajat(const Angajat &a) :id(a.id) {

		this->nume = a.nume;

		this->varsta = a.varsta;

		this->salariu = a.salariu;

		this->domeniu = new char[strlen(a.domeniu) + 1];

		strcpy_s(this->domeniu, strlen(a.domeniu) + 1, a.domeniu);

	}


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

	Angajat(int idNou, float salariuNou,string numeNou, int varstaNoua, char* domeniuNou) :id(idNou), salariu(salariuNou),nume(numeNou), varsta(varstaNoua) {

		this->domeniu = new char[strlen(domeniuNou) + 1];

		strcpy_s(domeniu, strlen(domeniuNou) + 1, domeniuNou);
	}

	~Angajat() {


		if (this->domeniu != NULL)
			
		{

			delete[]this->domeniu;

		}
	}

	//void afisare() {

	//	cout << id << "." << "Nume angajat: "<< nume << endl;

	//	cout<< "Varsta: " << varsta << endl;
	//	
	//	cout << "Salariu: " << salariu << " mii lei" << endl;
	//	
	//	cout << "Ocupatie: " << domeniu << endl;
	//	
	//	cout << "Varsta pensionare: " << varstaPensionare << endl;
	//	
	//	cout << endl;


	//}

	Angajat operator=(const Angajat& ang) {

		if (this != &ang) {


			if (this->domeniu != NULL) {

				delete[]this->domeniu;

			}

			this->nume = ang.nume;

			this->varsta = ang.varsta;

			this->salariu = ang.salariu;

			this->domeniu = new char[strlen(ang.domeniu) + 1];

			strcpy_s(this->domeniu, strlen(ang.domeniu) + 1, ang.domeniu);


		}

		return *this;

	}

	friend ostream& operator<<(ostream& dinozaur, const Angajat& a);

	friend istream& operator>>(istream& floare, Angajat& a);

	Angajat operator+(int varsta) const {

		Angajat aux = *this;

		aux.varsta = this->varsta + varsta;

		return aux;

	}

	

};

istream& operator>>(istream& floare, Angajat& a) {

	if (a.domeniu != NULL) {

		delete[]a.domeniu;

	}

	cout << "Nume: ";
	//getline(floare, a.nume);
	floare >> a.nume;
	cout << "Varsta: ";
	floare >> a.varsta;
	cout << "Salariu: ";
	floare >> a.salariu;
	cout << "Ocupatie: ";

	char aux[100];
	floare >> aux;

	a.domeniu = new char[strlen(aux) + 1];
	strcpy_s(a.domeniu, strlen(aux) + 1, aux);

	return floare;

}

ostream& operator<<(ostream& dinozaur, const Angajat& a) {


	dinozaur << a.id << "." << "Nume angajat: " << a.nume << endl;

	dinozaur << "Varsta: " << a.varsta << endl;

	dinozaur << "Salariu: " << a.salariu << " mii lei" << endl;

	dinozaur << "Ocupatie: " << a.domeniu << endl;

	dinozaur << "Varsta pensionare: " << a.varstaPensionare << endl;

	dinozaur << endl;


	return dinozaur;



}

int Angajat::varstaPensionare = 65;


class Proiect {
private:

	string numeProiect;
	int durata;
	float buget; 
	int nrMembri;
	Angajat* membriProiect;

public:

	Angajat* getMembru() {
		return this->membriProiect;
	}
	int getNrMembri() {
		return this->nrMembri;
	}
	void setMembri(int nr, Angajat* m) {
		if (this->membriProiect != NULL) {
			delete[]this->membriProiect;
		}
		if (nr >= 0) {
			this->nrMembri = nr;
		}
		if (nr > 0) {
			this->membriProiect = new Angajat[nr];
			for (int i = 0; i < nr; i++) {
				this->membriProiect[i] = m[i];
			}
		}
		else
			this->membriProiect = NULL;
	}
	float getBuget() {
		return this->buget;
	}
	void setBuget(float b) {
		if (b > 0) {
			this->buget = b;
		}
	}
	int getDurata() {
		return this->durata;
	}
	void setDurata(int i) {
		if (i > 0) {
			this->durata = i;
		}
	}
	string getNumeProiect() {
		return this->numeProiect;
	}
	void setNumeProiect(string n) {
		if (n.length() > 3) {
			this->numeProiect = n;
		}
	}

	Proiect() {
		this->numeProiect = "Platforma de Management de Proiecte";
		this->durata = 6;
		this->buget = 150000;
		this->nrMembri = 2;
		this->membriProiect = new Angajat[2];
	}

	Proiect(int durata, float bug) :durata(durata), buget(bug) {
		this->numeProiect = "Platforma de E-learning";
		this->nrMembri = 0;
		this->membriProiect = NULL;
	}

	Proiect(string nume, int d, float b, int nrM, Angajat* mem) {
		this->numeProiect = nume;
		this->durata = d;
		this->buget = b;
		this->nrMembri = nrM;
		if (nrM > 0) {
			this->membriProiect = new Angajat[nrM];
			for (int i = 0; i < nrM; i++) {
				this->membriProiect[i] = mem[i];
			}
		}
		else
		
		{
			this->membriProiect = NULL;
		}
	}

	Angajat& operator[](int index) {
		if (this->membriProiect!=NULL && index >= 0 && index < this->nrMembri) {
			return this->membriProiect[index];
		}
	}
	

	Proiect(const Proiect& p) {
		this->numeProiect = p.numeProiect;
		this->durata = p.durata;
		this->buget = p.buget;
		this->nrMembri = p.nrMembri;
		if (this->nrMembri > 0) {
			this->membriProiect = new Angajat[this->nrMembri];
			for (int i = 0; i < this->nrMembri; i++) {
				this->membriProiect[i] = p.membriProiect[i];
			}
		}
		else
			this->membriProiect = NULL;
	}

	Proiect& operator=(const Proiect& p) {
		if (this != &p) {
			if (this->membriProiect != NULL) {
				delete[]this->membriProiect;
			}
			this->numeProiect = p.numeProiect;
			this->durata = p.durata;
			this->buget = p.buget;
			this->nrMembri = p.nrMembri;
			if (this->nrMembri > 0) {
				this->membriProiect = new Angajat[this->nrMembri];
				for (int i = 0; i < this->nrMembri; i++) {
					this->membriProiect[i] = p.membriProiect[i];
				}
			}
			else
				this->membriProiect = NULL;
		}
		return *this;
	}
	
	~Proiect() {
		if (this->membriProiect != NULL) {
			delete[]this->membriProiect;
		}
	}

	friend ostream& operator<<(ostream& afi, const Proiect& p);
	
};

ostream& operator<<(ostream& afi, const Proiect& p) {
	
	afi << "Nume proiect :" << p.numeProiect << endl;
	afi << "Durata: " << p.durata << " luni" << endl;
	afi << "Buget: " << p.buget << " mii lei" << endl;
	afi << "Nr membri: " << p.nrMembri << endl;
	afi << "Acestia sunt: \n";
	if (p.nrMembri > 0) {
		afi << endl;
		for (int i = 0; i < p.nrMembri; i++) {
			afi << p.membriProiect[i];
		}
		afi << endl;
	}
	else
	{
		afi << " - ";
		afi << endl;
	}
	afi << endl;
	return afi;
}

class Sediu {

private:

	int nrCamere;

	float suprafata;

	char* locatie;

	string numarTelefon;

	static int nrTotalSedii;

	const int id;

public:

	explicit operator int() {
		return this->nrCamere;
	}

	explicit operator float() {
		return this->suprafata;
	}


	const int getIDSediu() {

		return this->id;
	}

	static void setNrTotalSedii(int nrNou) {

		if (nrNou > 0) {

			Sediu::nrTotalSedii = nrNou;

		}
	}

	static int getNrTotalSedii() {

		return Sediu::nrTotalSedii;

	}

	void setNrCamereSediu(int numarCamere) {

		if (numarCamere > 0) {

			this->nrCamere = numarCamere;

		}

	}

	int getNrCamereSediu() {

		return this->nrCamere;

	}

	void setSuprafataSediu(float supra) {

		if (supra > 0) {

			this->suprafata = supra;

		}

	}

	float getSuprafataSediu() {

		return this->suprafata;

	}

	void setNrTelefon(string telefon) {

		if (telefon.length() > 2) {

			this->numarTelefon = telefon;

		}

	}

	string getNrTelefon() {

		return this->numarTelefon;

	}

	void setLocatieSediu(const char* loc) {

		if (this->locatie != NULL && strlen(loc) > 2) {

			if (this->locatie != NULL) {

				delete[]this->locatie;

			}

			this->locatie = new char[strlen(loc) + 1];

			strcpy_s(locatie, strlen(loc) + 1, loc);

		}

	}

	const char* getLocatieSediu() {

		return this->locatie;

	}

	Sediu(const Sediu& s) :id(s.id) {

		this->nrCamere = s.nrCamere;

		this->suprafata = s.suprafata;

		this->numarTelefon = s.numarTelefon;

		this->locatie = new char[strlen(s.locatie) + 1];

		strcpy_s(this->locatie, strlen(s.locatie) + 1, s.locatie);

	}


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
	), suprafata(suprafataNoua), numarTelefon(numarNou) {

		this->locatie = new char[strlen(locatieNoua) + 1];

		strcpy_s(locatie, strlen(locatieNoua) + 1, locatieNoua);

	}

	~Sediu() {

		if (this->locatie != NULL)
		
		{

			delete[]this->locatie;
		}

	}

	/*void afisare() {

		cout << id << "." << "Locatie sediu: " << locatie;
		
		cout << endl << "Numar camere: " << nrCamere << endl;
		
		cout << "Suprafata: " << suprafata << " metri patrati" << endl;

		cout << "Numar telefon: " << numarTelefon << endl;

		cout << "Numar total sedii: " << nrTotalSedii << endl << endl;


	}*/


	Sediu operator=(const Sediu& s)
	{

		if (this != &s) {

			if (this->locatie != NULL) {

				delete[]this->locatie;

			}

			this->nrCamere = s.nrCamere;

			this->suprafata = s.suprafata;

			this->numarTelefon = s.numarTelefon;

			this->locatie = new char[strlen(s.locatie) + 1];

			strcpy_s(this->locatie, strlen(s.locatie) + 1, s.locatie);

		}

		return *this;

	}
	
	Sediu operator+( int nrCam) const {
		
		Sediu aux = *this;

		float supM = 0;
		supM = this->suprafata / (float)this->nrCamere;

		aux.nrCamere = this->nrCamere + nrCam;

		aux.suprafata = this->suprafata + supM * nrCam;

		return aux;

	}

	float operator()(){
		float medie = 0;
		medie = this->suprafata / (float)this->nrCamere;
		return medie;

	}



	friend ostream& operator<<(ostream& afis, const Sediu& s);

	friend istream& operator>>(istream& apa, Sediu& se);

	friend ofstream& operator<<(ofstream& afisare, const Sediu& s);
};

ofstream& operator<<(ofstream& afisare, const Sediu& s) {

	afisare << s.id << "." << "Locatie sediu: " << s.locatie;
	afisare << endl << "Numar camere: " << s.nrCamere << endl;
	afisare << "Suprafata: " << s.suprafata << " metri patrati" << endl;
	afisare << "Numar telefon: " << s.numarTelefon << endl;
	afisare << "Numar total sedii: " << s.nrTotalSedii << endl << endl;
	return afisare;
}

istream& operator>>(istream& apa, Sediu& se) {

	if (se.locatie != NULL) {

		delete[]se.locatie;

	}

	char aux[100];

	cout << "Locatie sediu: ";
	apa >> aux;

	se.locatie = new char[strlen(aux) + 1];
	strcpy_s(se.locatie, strlen(aux) + 1, aux);


	cout << "Numar camere: ";
	apa >> se.nrCamere;
	cout << "Suprafata(mp): ";
	apa >> se.suprafata;
	cout << "Numar telefon: ";
	apa >> se.numarTelefon;

	return apa;

}

ostream& operator<<(ostream& afis, const Sediu& s) {

	afis << s.id << "." << "Locatie sediu: " << s.locatie;

	afis << endl << "Numar camere: " << s.nrCamere << endl;

	afis << "Suprafata: " << s.suprafata << " metri patrati" << endl;

	afis << "Numar telefon: " << s.numarTelefon << endl;

	afis << "Numar total sedii: " << s.nrTotalSedii << endl << endl;

	return afis;

}

int Sediu::nrTotalSedii = 3;


class Companie {

private:

	int anInfiintare;

	string nume;

	string domeniuActivitate;

	int numarAngajati;

	int* varsteAngajati;

	const int id;

	static string tara;

public:

	explicit operator int() {
		return this->anInfiintare;
	}
	explicit operator string() {
		return this->nume;
	}

	int& operator[](int index) {
		if (index >= 0 && index < this->numarAngajati) {
			return this->varsteAngajati[index];
		}
	}

	float operator()() {
		float medie = 0;
		if (this->numarAngajati > 0) {
			for (int i = 0; i < this->numarAngajati; i++) {
				medie += this->varsteAngajati[i];
			}
			medie = medie / (float)this->numarAngajati;
			return medie;
		}
		else
		{
			return medie;
		}
	}

	static string getTara() {

		return Companie::tara;

	}

	static void setTara(string taraNoua) {

		if (taraNoua.length() > 3) {

			Companie::tara = taraNoua;

		}

	}

	const int getIDCompanie()  {

		return this->id;

	}

	void setAnInfiintare(int an) {

		if (an > 1500) {

			this->anInfiintare = an;

		}

	}

	int getAnInfiintare() {

		return this->anInfiintare;
	}

	void setNumeCompanie(string nume) {

		if (nume.length() > 2) {

			this->nume = nume;

		}

	}

	string getNumeCompanie() {

		return this->nume;

	}

	void setDomeniuActivitateCompanie(string domeniu) {

		if (domeniu.length() >= 2) {

			this->domeniuActivitate = domeniu;

		}

	}

	string getDomeniuActivitateCompanie() {

		return this->domeniuActivitate;

	}

	void setAngajatiSiVarste(int ang, int* varste) {

		if (ang > 0) {

			this->numarAngajati = ang;

			if (this->varsteAngajati != NULL) {

				delete[]this->varsteAngajati;

			}

			this->varsteAngajati = new int[ang];

			for (int i = 0; i < ang; i++) {

				this->varsteAngajati[i] = varste[i];

			}

		}

		else

			this->varsteAngajati = NULL;

	}

	int getNrAng() {

		return this->numarAngajati;

	}

	int* getVarsteAng() {

		return this->varsteAngajati;

	}

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

	/*void afisare() {

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
		
		

	}*/

	Companie(const Companie& c) :id(c.id) {

		this->anInfiintare = c.anInfiintare;

		this->nume = c.nume;

		this->domeniuActivitate = c.domeniuActivitate;

		this->numarAngajati = c.numarAngajati;

		if (numarAngajati != 0) {

			this->varsteAngajati = new int[numarAngajati];

			for (int i = 0; i < numarAngajati; i++) {

				this->varsteAngajati[i] = c.varsteAngajati[i];

			}

		}

		else

			this->varsteAngajati = NULL;

	}

	Companie operator=(const Companie& c) {

		if (this != &c) {

			if (this->varsteAngajati != NULL) {

				delete[]this->varsteAngajati;

			}

			this->anInfiintare = c.anInfiintare;

			this->nume = c.nume;

			this->domeniuActivitate = c.domeniuActivitate;

			this->numarAngajati = c.numarAngajati;

			if (this->numarAngajati != 0) {

				this->varsteAngajati = new int[numarAngajati];

				for (int i = 0; i < numarAngajati; i++) {

					this->varsteAngajati[i] = c.varsteAngajati[i];

				}

			}
			else

				this->varsteAngajati = NULL;

		}

		return *this;

	}

	Companie operator+(const Companie& c) {

		Companie aux = *this;

		aux.numarAngajati = this->numarAngajati + c.numarAngajati;

		if (aux.varsteAngajati != NULL) {

			delete[]aux.varsteAngajati;

		}

		if (aux.numarAngajati > 0) {

			aux.varsteAngajati = new int[aux.numarAngajati];

			for (int i = 0; i < this->numarAngajati; i++) {

				aux.varsteAngajati[i] = varsteAngajati[i];

			}

			for (int j = this->numarAngajati; j < aux.numarAngajati; j++) {

				aux.varsteAngajati[j] = c.varsteAngajati[j - numarAngajati];

			}


		}
		else

		{
			aux.varsteAngajati = NULL;
		}

		return aux;
	}

	friend ostream& operator<<(ostream& telefon, const Companie& companie);

	friend istream& operator>>(istream& citire, Companie& c);

	friend ofstream& operator<<(ofstream& mouse, const Companie& companie) {

		mouse << companie.id << "." << "Nume companie: " << companie.nume << endl;
		mouse << "An infiintare: " << companie.anInfiintare << endl;
		mouse << "Domeniu activitate: " << companie.domeniuActivitate << endl;
		mouse << "Numar angajati: " << companie.numarAngajati << endl;
		mouse << "Varste angajati(ani): ";
		if (companie.varsteAngajati != NULL)

		{

			for (int i = 0; i < companie.numarAngajati; i++)

			{

				mouse << companie.varsteAngajati[i] << ' ';

			}


		}

		else

		{
			mouse << " - ";
		}
		mouse << endl;
		mouse << "Tara activitate: " << companie.tara << endl << endl;

		return mouse;


	}

};

istream& operator>>(istream& citire, Companie& c) {

	if (c.varsteAngajati != NULL) {

		delete[]c.varsteAngajati;

	}

	cout << "Nume companie: ";
	//getline(citire, c.nume);
	citire >> c.nume;
	cout << "An infiintare: ";
	citire >> c.anInfiintare;
	cout << "Domeniu activitate: ";
	citire >> c.domeniuActivitate;
	cout << "Numar angajati: ";
	citire >> c.numarAngajati;
	
	if (c.numarAngajati > 0) {

		c.varsteAngajati = new int[c.numarAngajati];

		for (int i = 0; i < c.numarAngajati; i++) {

			cout << "Varsta angajatului " << i + 1 << ":";
			citire >> c.varsteAngajati[i];
		}

	}
	else
	{
		cout << "Varste angajati: - ";
		c.varsteAngajati = NULL;

	}

	return citire;
}

ostream& operator<<(ostream& telefon, const Companie& companie) {

	telefon << companie.id << "." << "Nume companie: " << companie.nume << endl;
	telefon<<"An infiintare: " << companie.anInfiintare << endl;
	telefon << "Domeniu activitate: " << companie.domeniuActivitate << endl;
	telefon << "Numar angajati: " << companie.numarAngajati << endl;
	telefon << "Varste angajati(ani): ";
	if (companie.varsteAngajati != NULL)

	{

		for (int i = 0; i < companie.numarAngajati; i++)

		{

			telefon << companie.varsteAngajati[i] << ' ';

		}


	}

	else

	{

		telefon << " - ";

	}

	telefon << endl;


	telefon << "Tara activitate: " << companie.tara << endl << endl;

	return telefon;


}

string Companie::tara = "Romania";


void main() {


	cout << "COMPANII\n\n";

	Companie companie1;
	//companie1.afisare();
	cout << "companie1:\n" << companie1;

	Companie companie2(3, "La Canapele");
	//companie2.afisare();
	cout << "companie2:\n";
	cout << companie2;

	int* varste = new int[3];
	varste[0] = 25;
	varste[1] = 37;
	varste[2] = 48;

	Companie companie3(4, 2017, "Trei Barcute SRL", "Inchirieri Cabane", 3, varste);
	//companie3.afisare();
	cout << "companie3:\n";
	cout << companie3;

	cout << "SET TARA: \n";
	companie1.setTara("Franta");
	//companie1.afisare();
	cout << companie1;

	cout << "CONSTRUCTOR DE COPIERE\n";
	cout << "companie4(companie1):\n";
	Companie companie4(companie1);
	//companie4.afisare();
	cout << companie4;

	cout << "companie5(companie2):\n";
	Companie companie5(companie2);
	//companie5.afisare();
	cout << companie5;

	cout << "GET - ERI SI SET - ERI\n";

	cout << "COMPANIE 5=>GET-ERI\n";
	cout << "ID: " << companie5.getIDCompanie() << endl;
	cout << "NUME COMPANIE: " << companie5.getNumeCompanie() << endl;
	cout << "AN INFIINTARE: " << companie5.getAnInfiintare() << endl;
	cout << "DOMENIU ACTIVITATE: " << companie5.getDomeniuActivitateCompanie() << endl;
	cout << "NUMAR ANGAJATI: " << companie5.getNrAng() << endl;
	cout << "VARSTE ANGAJATI(ANI): ";

	int* varsteAngajati = companie5.getVarsteAng();
	if (varsteAngajati != NULL) {
		for (int i = 0; i < companie5.getNrAng(); i++) {
			cout << varsteAngajati[i] << ' ';
		}
	}
	else {
		cout << " - ";
	}
	cout << endl;

	cout << "TARA ACTIVITATE: " << companie5.getTara() << endl << endl;

	companie5.setNumeCompanie("Zara");
	companie5.setDomeniuActivitateCompanie("Vanzari haine");
	companie5.setAnInfiintare(2002);
	companie5.setTara("Franta");
	int* setVarsteAngCompanie = new int[4] {29, 39, 49, 59};
	companie5.setAngajatiSiVarste(4, setVarsteAngCompanie);

	cout << "COMPANIE 5\n";
	cout << "ID: " << companie5.getIDCompanie() << endl;
	cout << "NUME COMPANIE: " << companie5.getNumeCompanie() << endl;
	cout << "AN INFIINTARE: " << companie5.getAnInfiintare() << endl;
	cout << "DOMENIU ACTIVITATE: " << companie5.getDomeniuActivitateCompanie() << endl;
	cout << "NUMAR ANGAJATI: " << companie5.getNrAng() << endl;
	cout << "VARSTE ANGAJATI(ANI): ";

	int* varsteAng = companie5.getVarsteAng();
	if (varsteAng != NULL) {
		for (int i = 0; i < companie5.getNrAng(); i++) {
			cout << varsteAng[i] << ' ';
		}
	}
	else {
		cout << " - ";
	}
	cout << endl;

	cout << "TARA ACTIVITATE: " << companie5.getTara() << endl << endl;

	delete[]setVarsteAngCompanie;


	cout << "OPERTOR =\n";
	cout << "companie6 = companie3\n";

	Companie companie6;
	companie6 = companie3;
	//companie6.afisare();
	cout << companie6;

	cout << "OPERATOR +\n";
	cout << "companie7 = companie5 + companie3\n";


	Companie companie7;
	companie7 = companie5 + companie3;
	//companie7.afisare();

	cout << companie7;


	Companie companie9;
	cin >> companie9;
	cout << endl;
	cout << companie9;

	cout << "-----------------------------------\n\n";

	cout << "SEDII\n\n";

	cout << "sediu 1";
	cout << endl;
	Sediu sediu1;
	//sediu1.afisare();
	cout << sediu1;

	Sediu sediu2(10, "0742948226");
	cout << "sediu2";
	cout << endl;
	//sediu2.afisare();
	cout << sediu2;


	char* locatie;
	locatie = new char[strlen("Timisoara") + 1];
	strcpy_s(locatie, strlen("Timisoara") + 1, "Timisoara");

	Sediu sediu3(13, 3, 81, "0717945560", locatie);
	cout << "sediu3";
	cout << endl;
	//sediu3.afisare();
	cout << sediu3;

	cout << "SET SEDII: \n";
	sediu2.setNrTotalSedii(9);
	//sediu2.afisare();
	cout << sediu2;


	cout << "CONSTRUCTOR DE COPIERE:\n";
	cout << "sediu4(sediu1)";
	cout << endl;
	Sediu sediu4(sediu1);
	//sediu4.afisare();
	cout << sediu4;

	Sediu sediu5(sediu3);
	//sediu5.afisare();
	cout << "sediu5(sediu3)";
	cout << endl;
	cout << sediu5;

	cout << "GET-eri \n\n";

	cout << "SEDIU 5 \n";
	cout << "ID: " << sediu5.getIDSediu() << endl;
	cout << "LOCATIE SEDIU: " << sediu5.getLocatieSediu() << endl;
	cout << "NUMAR CAMERE: " << sediu5.getNrCamereSediu() << endl;
	cout << "SUPRAFATA: " << sediu5.getSuprafataSediu() << " metri patrati" << endl;
	cout << "NUMAR TELEFON: " << sediu5.getNrTelefon() << endl;
	cout << "NUMAR TOTAL SEDII: " << sediu5.getNrTotalSedii() << endl;

	char* seteazaLocatia = new char[strlen("Sibiu") + 1];
	strcpy_s(seteazaLocatia, strlen("Sibiu") + 1, "Sibiu");

	sediu5.setLocatieSediu(seteazaLocatia);
	sediu5.setNrCamereSediu(4);
	sediu5.setSuprafataSediu(101.5);
	sediu5.setNrTelefon("555-313");
	sediu5.setNrTotalSedii(5);

	cout << "\nSEDIU 5 | SET-eri\n";

	cout << "ID: " << sediu5.getIDSediu() << endl;
	cout << "LOCATIE SEDIU: " << sediu5.getLocatieSediu() << endl;
	cout << "NUMAR CAMERE: " << sediu5.getNrCamereSediu() << endl;
	cout << "SUPRAFATA: " << sediu5.getSuprafataSediu() << " metri patrati" << endl;
	cout << "NUMAR TELEFON: " << sediu5.getNrTelefon() << endl;
	cout << "NUMAR TOTAL SEDII: " << sediu5.getNrTotalSedii() << endl;

	delete[]seteazaLocatia;

	cout << "OPERTOR =\n";
	cout << "sediu7=sediu3\n";
	cout << endl;
	Sediu sediu7;
	sediu7 = sediu3;
	//sediu7.afisare();
	cout << sediu7;

	cout << "SEDIU 8:\n ";
	Sediu sediu8;
	cin >> sediu8;
	cout << endl << sediu8;
	cout << "sediu9" << endl;
	Sediu sediu9;
	cout << "sediu9 = sediu7 + 10\n" << endl;
	sediu9 = sediu7 + 10;
	cout << sediu9;

	cout << "-----------------------------------\n\n";

	cout << "ANGAJATI\n\n";

	Angajat angajat1;
	cout << "angajat1\n";
	//angajat1.afisare();
	cout << angajat1;

	cout << "angajat2\n";
	Angajat angajat2(16, 6.5);
	//angajat2.afisare();
	cout << angajat2;


	char* domeniu = new char[strlen("IT") + 1];

	strcpy_s(domeniu, strlen("IT") + 1, "IT");

	cout << "angajat3\n";
	Angajat angajat3(19, 13, "Stefan Gabriel", 23, domeniu);
	//angajat3.afisare();
	cout << angajat3;

	angajat3.setvarstaPensionare(70);
	//angajat3.afisare();
	cout << angajat3;


	cout << "CONSTRUCTOR DE COPIERE:\n";
	cout << "angajat4(angajat3)\n";
	Angajat angajat4(angajat3);
	//angajat4.afisare();
	cout << angajat4;

	cout << "angajat5(angajat2)\n";
	Angajat angajat5(angajat2);
	//angajat5.afisare();
	cout << angajat5;

	cout << "GET-ERI SI SET-ERI\n\n";

	cout << "ANGAJAT 5" << endl;
	cout << "ID: " << angajat5.getIDAngajat() << endl;
	cout << "NUME: " << angajat5.getNumeAngajat() << endl;
	cout << "VARSTA: " << angajat5.getVarstaAngajat() << endl;
	cout << "SALARIU: " << angajat5.getSalariuAngajat() << " mii lei" << endl;
	cout << "OCUPATIE: " << angajat5.getDomeniuAngajat() << endl;
	cout << "VARSTA PENSIONARE: " << angajat5.getVarstaPensionare() << endl;
	cout << endl;

	char* seteazaDomeniu = new char[strlen("Brutar") + 1];
	strcpy_s(seteazaDomeniu, strlen("Brutar") + 1, "Brutar");

	angajat5.setNumeAngajat("Vasile Vladut");
	angajat5.setVarstaAngajat(25);
	angajat5.setSalariuAngajat(9);
	angajat5.setDomeniuAngajat(seteazaDomeniu);
	angajat5.setvarstaPensionare(50);

	cout << "ANGAJAT 5" << endl;
	cout << "ID: " << angajat5.getIDAngajat() << endl;
	cout << "NUME: " << angajat5.getNumeAngajat() << endl;
	cout << "VARSTA: " << angajat5.getVarstaAngajat() << endl;
	cout << "SALARIU: " << angajat5.getSalariuAngajat() << " mii lei" << endl;
	cout << "OCUPATIE: " << angajat5.getDomeniuAngajat() << endl;
	cout << "VARSTA PENSIONARE: " << angajat5.getVarstaPensionare() << endl;
	cout << endl;

	delete[]seteazaDomeniu;

	cout << "OPERTOR =\n";
	cout << "angajat6 = angajat2\n";
	Angajat angajat6;
	angajat6 = angajat2;
	//angajat6.afisare();
	cout << angajat6;

	Angajat angajat7;
	cin >> angajat7;
	cout << endl << angajat7;

	cout << "angajat8 = angajat8 + 7\n";
	Angajat angajat8;
	cout << angajat8;
	angajat8 = angajat8 + 7;
	cout << angajat8;

	Angajat angajat13;
	cout << angajat13;
	cin >> angajat13;
	cout << angajat13;

	Angajat angajat14;
	angajat14 = angajat13 + 13;
	cout << angajat14;

	cout << "-----------------------------------\n\n";

	string n;
	n = (string)angajat1;

	int v;
	v = (int)angajat1;

	float s;
	s = (float)angajat1;

	cout << n << endl << v << endl << s << endl;

	cout << angajat8.operator()() << endl;

	cout << "-----------------------------------\n\n";

	cout << "Suprafata medie/camera a sediului cu id-ul " << sediu5.getIDSediu() << " este " << sediu5.operator()() << " mp" << endl;

	int b;
	b = (int)sediu5;
	float b1;
	b1 = (float)sediu5;
	cout << b << endl << b1 << endl;

	cout << "-----------------------------------\n\n";
	cout << companie7;
	companie7[1] = 13;
	cout << companie7;
	cout << companie7.operator()() << endl;

	int abc;
	abc = (int)companie7;
	string cba;
	cba = (string)companie7;
	cout << abc << endl << cba << endl;


	cout << "-----------------------------------\n\n";

	//vectori si matrici

	Angajat* vectorAngajat = new Angajat[3];
	for (int i = 0; i < 3; i++) {
		cin >> vectorAngajat[i];
		cout << endl;
	}
	for (int i = 0; i < 3; i++) {
		cout << vectorAngajat[i] << endl << endl;
	}
	cout << endl;
	Sediu* vectorSediu = new Sediu[2];
	for (int i = 0; i < 2; i++) {
		cin >> vectorSediu[i];
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 2; i++) {
		cout << vectorSediu[i] << endl << endl;
	}

	Companie* vectorCompanie = new Companie[2];
	for (int i = 0; i < 2; i++) {
		cin >> vectorCompanie[i];
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 2; i++) {
		cout << vectorCompanie[i];
		cout << endl << endl;
	}

	delete[]vectorAngajat;
	delete[]vectorCompanie;
	delete[]vectorSediu;

	Companie** matrice = new Companie * [2];
	for (int i = 0; i < 2; i++) {
		matrice[i] = new Companie[2];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin>> matrice[i][j];
			cout << endl;
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << matrice[i][j];
		}

		for (int i = 0; i < 2; i++) {
			delete[]matrice[i];
		}
		delete[]matrice;
	}

	cout << "-----------------------------------\n\n";

	//relatia de has-a

	Angajat angajatRelatie1;
	cin >> angajatRelatie1;
	cout << endl;
	Angajat angajatRelatie2;
	cin >> angajatRelatie2;
	cout << endl;

	Angajat* vector = new Angajat[2]{ angajatRelatie1 ,angajatRelatie2 };

	Proiect primulProiect("Project X", 12, 43000, 2, vector);
	cout << primulProiect;

	cout << "-----------------------------------\n\n";


	Companie companieFisierText;
	cin >> companieFisierText;
	ofstream g("Companie.txt", ios::app);
	g << companieFisierText;
	g.close();

	Sediu sediuFisierText;
	cin >> sediuFisierText;
	ofstream f("Sediu.txt", ios::app);
	f << sediuFisierText;
	f.close();



}




