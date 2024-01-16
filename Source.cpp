#include <iostream>
#include<fstream>
#include<string>
using namespace std;

class Descriere {
public:
	virtual void caracteristici() = 0;
};

class Informatii {
public:
	virtual void afisareInformatii() = 0;
};


class Angajat :public Descriere {

private:

	const int id;
	string nume;
	int varsta;
	float salariu; //mii lei
	static int varstaPensionare;
	char* domeniu;

public:

	void caracteristici() override {
		cout << "Angajatul are varsta de " << this->getVarstaAngajat() << " ani" << endl;
	}


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

	Angajat(int varsta) :id(14)

	{

		this->nume = "Solea Ianis";

		this->varsta = varsta;

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

    virtual	~Angajat() {


		if (this->domeniu != NULL)
			
		{

			delete[]this->domeniu;

		}
	}

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

class Manager :public Angajat {
private:
	int nrMembriFamilie;
	string mancarePreferata;
	float inaltime;
public:

	void caracteristici() override {
		cout << "Managerul are inca " << this->getNrMembri() << " membri in familie " << endl;
	}

	void setNrMembri(int nr) {
		if (nr > 0) {
			this->nrMembriFamilie = nr;
		}
	}
	int getNrMembri() {
		return this->nrMembriFamilie;
	}
	void setMancare(string m) {
		if (m.length() > 2) {
			this->mancarePreferata = m;
		}
	}
	string getMancare() {
		return this->mancarePreferata;
	}
	void setInaltime(float in) {
		if (in >= 1) {
			this->inaltime = in;
		}
	}
	float getInaltime() {
		return this->inaltime;
	}



	Manager() :Angajat() {
		this->nrMembriFamilie = 3;
		this->mancarePreferata = "Peste";
		this->inaltime = 1.75;
	}
	Manager(int nrM, float sal) :Angajat(5, sal) {
		this->nrMembriFamilie = nrM;
		this->mancarePreferata = "Ciorba";
		this->inaltime = 1.63;
	}
	Manager(int nR, float inaltime, string mancare, int ID, float salariuN) :Angajat(ID, salariuN) {
		this->nrMembriFamilie = nR;
		this->inaltime = inaltime;
		this->mancarePreferata = mancare;
	}

	Manager(const Manager& om) :Angajat(om) {
		this->inaltime = om.inaltime;
		this->mancarePreferata = om.mancarePreferata;
		this->nrMembriFamilie = om.nrMembriFamilie;
	}

	Manager& operator=(const Manager& o) {
		if (this != &o) {
			Angajat::operator=(o);
			this->inaltime = o.inaltime;
			this->mancarePreferata = o.mancarePreferata;
			this->nrMembriFamilie = o.nrMembriFamilie;

		}
		return *this;
	}

	friend ostream& operator<<(ostream& afis, const Manager& o) {
		afis << "Nr membri familie: " << o.nrMembriFamilie << endl;
		afis << "Inaltime: " << o.inaltime << " m " << endl;
		afis << "Mancare preferata: " << o.mancarePreferata << endl;
		afis << (Angajat)o;
		afis << endl;

		return afis;
	}

};

class SediuCuAngajati {
private:
	int nrAng;
	Descriere** angajati;
public:

	int getNrA() {
		return this->nrAng;
	}

	SediuCuAngajati() {
		this->nrAng = 10;
		this->angajati = new Descriere * [10];
		for (int i = 0; i < 9; i++) {
			this->angajati[i] = new Angajat();
		}
		this->angajati[this->nrAng - 1] = new Manager();

	}

	Descriere*& operator[](int index) {
		if (index >= 0 && index < this->nrAng) {
			return this->angajati[index];
		}
	}

	~SediuCuAngajati() {
		if (this->angajati != NULL) {
			delete[]this->angajati;
		}
	}
};

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



class Sediu: public Informatii{

private:

	int nrCamere;

	float suprafata;

	char* locatie;

	string numarTelefon;

	static int nrTotalSedii;

	const int id;

public:

	void afisareInformatii() override {
		cout << "Sediul are " << this->getNrCamereSediu() << " nr camere si o suprafata de " << this->suprafata << " mp\n";
	}

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

	virtual ~Sediu() {

		if (this->locatie != NULL)
		
		{

			delete[]this->locatie;
		}

	}


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


class Cladire :public Sediu {
private:
	int nrEtaje;
	int anConstructie;
	bool areLift;
	int capacitateParcare;

public:

	void afisareInformatii() override {
		cout << "Parcarea are o capacitate de " << this->getCapacitate() << " locuri" << endl;
	}


	int getCapacitate() {
		return this->capacitateParcare;
	}

	void setCapacitate(int nr) {
		if (nr >= 0) {
			this->capacitateParcare = nr;
		}
	}

	void setAnConstructie(int an) {
		if (an > 1950) {
			this->anConstructie = an;
		}
	}

	int getAn() {
		return this->anConstructie;
	}

	int getNrEraje() {
		return this->nrEtaje;
	}
	void setNrEtaje(int nr) {
		if (nr > 0) {
			this->nrEtaje = nr;
		}
	}

	
	Cladire() :Sediu() {
		this->nrEtaje = 5;
		this->anConstructie = 1977;
		this->areLift = false;
		this->capacitateParcare = 50;
	}

	Cladire(int nrEtaje, int capacitateParcare, int id) :Sediu(id, "0782490062") {
		this->nrEtaje = nrEtaje;
		this->anConstructie = 1962;
		this->areLift = true;
		this->capacitateParcare = capacitateParcare;
	}

	Cladire(int nr, int anC, bool lift, int parcare, int idNou, int nrCamereNoi, float suprafataNoua, string numarNou, char* locatieNoua) :Sediu(idNou, nrCamereNoi, suprafataNoua, numarNou, locatieNoua) {
	
		this->nrEtaje = nr;
		this->anConstructie = anC;
		this->areLift = lift;
		this->capacitateParcare = parcare;
		
	}

	friend ostream& operator<<(ostream& afi, const Cladire& c) {

		afi << "Nr etaje cladire: " << c.nrEtaje << endl;
		afi << "An constructie cladire: " << c.anConstructie << endl;
		afi << (c.areLift ? "Are lift" : "Nu are lift") << endl;
		afi << "Capacitate parcare: " << c.capacitateParcare << " locuri" << endl;
		afi << (Sediu)c;
		return afi;
	}

	Cladire(const Cladire& c) :Sediu(c) {
		this->anConstructie = c.anConstructie;
		this->areLift = c.areLift;
		this->capacitateParcare = c.capacitateParcare;
		this->nrEtaje = c.nrEtaje;
	}

	Cladire& operator=(const Cladire& c) {
		if (this != &c) {
			Sediu::operator=(c);
			this->anConstructie = c.anConstructie;
			this->areLift = c.areLift;
			this->capacitateParcare = c.capacitateParcare;
			this->nrEtaje = c.nrEtaje;

		}
		return *this;
	}

};

class ComplexCuSedii {
private:
	int nrSedii;
	Informatii** sediu;
public:

	int getNS() {
		return this->nrSedii;
	}

	ComplexCuSedii() {
		this->nrSedii = 10;
		this->sediu = new Informatii * [10];
		for (int i = 0; i < this->nrSedii; i++) {
			this->sediu[i] = new Sediu();
		}
	}

	Informatii*& operator[](int index) {
		if (index >= 0 && index < this->nrSedii) {
			return this->sediu[index];
		}
	}

	~ComplexCuSedii() {
		if (this->sediu != NULL) {
			delete[]this->sediu;
		}
	}

};


class Companie {

private:

	int anInfiintare;

	char* nume;

	string domeniuActivitate;

	int numarAngajati;

	int* varsteAngajati;

	const int id;

	static string tara;

public:

	explicit operator int() {
		return this->anInfiintare;
	}
	explicit operator char*() {
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

	void setNumeCompanie(char* nume) {

		if (strlen(nume) > 2) {

			if (this->nume != NULL) {
				delete[]this->nume;
			}


			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);

		}
	}
	

	char* getNumeCompanie() {

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

		this->nume = new char[strlen("Business Pure SRL") + 1];
		strcpy_s(this->nume, strlen("Business Pure SRL") + 1, "Business Pure SRL");

		this->domeniuActivitate = "Contabilitate";

		this->numarAngajati = 0;

		this->varsteAngajati = NULL;


	}

	Companie(int idNou, char* numeNou) :id(idNou) {
		this->nume = new char[strlen(numeNou) + 1];
		strcpy_s(this->nume, strlen(numeNou) + 1, numeNou);

		this->anInfiintare = 2019;

		this->domeniuActivitate = "Tranzactii Imobiliare";

		this->numarAngajati = 0;

		this->varsteAngajati = NULL;
	}

	Companie(int idNou,int anInfiintareNou, char* numeNou, string domeniuNou,int numarAngajati, int* varsteAngajati):id(idNou),anInfiintare(anInfiintareNou),domeniuActivitate(domeniuNou),numarAngajati(numarAngajati){
		this->nume = new char[strlen(numeNou) + 1];
		strcpy_s(this->nume, strlen(numeNou) + 1, numeNou);

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

		if (this->nume != NULL) {
		
			delete[]this->nume;
		
		}


	}


	Companie(const Companie& c) :id(c.id) {

		this->anInfiintare = c.anInfiintare;

		this->nume = new char[strlen(c.nume) + 1];
		strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);

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

			if (this->nume != NULL) {

				delete[]this->nume;
			
			}

			this->anInfiintare = c.anInfiintare;

			this->nume = new char[strlen(c.nume) + 1];
			strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);

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
	if (c.nume != NULL) {
	
		delete[]c.nume;
	
	}
	
	string aux1;

	cout << "Nume companie: ";
	
	cin.ignore();
	
	getline(citire, aux1);

	c.nume = new char[aux1.length() + 1];
	strcpy_s(c.nume, aux1.length() + 1, aux1.c_str());

	cout << "An infiintare: ";
	citire >> c.anInfiintare;
	cin.ignore();
	cout << "Domeniu activitate: ";

	getline(cin, c.domeniuActivitate);
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


void afisareMeniu() {
	cout << endl;
	cout << "MENIU:\n";
	cout << "1. Afisare obiect" << endl;
	cout << "2. Seteaza tara" << endl;
	cout << "3. Detalii angajati" << endl;
	cout << "4. Actualizare informatii obiect" << endl;
	cout << "5. Iesire" << endl;
	cout << "Introduceti optiunea dorita: ";
}

void main() {
	

	// MENIU SI ACTIUNI PENTRU CLASA COMPANIE

	int optiune;
	string tz;

	int* varsteOptiune = new int[3];
	varsteOptiune[0] = 20;
	varsteOptiune[1] = 30;
	varsteOptiune[2] = 40;

	char* numeOptiune1 = new char[strlen("RADION SRL") + 1];
	strcpy_s(numeOptiune1, strlen("RADION SRL") + 1, "RADION SRL");
	 
	Companie optiune1(19, 2015, numeOptiune1, "Scoala Soferi", 3, varsteOptiune);


	do {

		afisareMeniu();
		cin >> optiune;
		cout << endl;

		switch (optiune) {
		case 1:
			cout << optiune1;
			break;
		case 2:
			cout << optiune1;
			cout << "Alege tara noua: ";
			cin >> tz;
			optiune1.setTara(tz);
			cout << endl;
			cout << optiune1;

			break;
		case 3:
			cout << endl;
			cout << "Numarul de angajati este: " << optiune1.getNrAng() << endl;
			cout << "Varstele acestora: ";
			if (optiune1.getNrAng() > 0) {
				for (int i = 0; i < optiune1.getNrAng(); i++) {
					cout << optiune1.getVarsteAng()[i] << " , ";
				}
				cout << endl;
			}
			else
			{
				cout << " - \n";
			}

			break;
		case 4:
			cout << optiune1;
			cin >> optiune1;
			cout << endl << endl;
			cout << optiune1;
			cout << endl;
			break;
		default:
			cout << "\nOptiune invalida. Te rog sa alegi din nou." << endl;

		}

	} while (optiune != 5);
	

	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PROIECT FAZELE 1-2-3~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
	
	cout << "COMPANII\n\n";

	Companie companie1;
	cout << "companie1:\n" << companie1;

	char* luni = new char[strlen("La Canapele") + 1];
	strcpy_s(luni, strlen("La Canapele") + 1, "La Canapele");

	Companie companie2(3, luni);
	cout << "companie2:\n";
	cout << companie2;

	int* varste = new int[3];
	varste[0] = 25;
	varste[1] = 37;
	varste[2] = 48;
	
	char* marti = new char[strlen("Trei Barcute SRL") + 1];
	strcpy_s(marti, strlen("Trei Barcute SRL") + 1, "Trei Barcute SRL");

	Companie companie3(4, 2017, marti, "Inchirieri Cabane", 3, varste);
	cout << "companie3:\n";
	cout << companie3;

	cout << "SET TARA: \n";
	companie1.setTara("Franta");
	cout << companie1;

	cout << "CONSTRUCTOR DE COPIERE\n";
	cout << "companie4(companie1):\n";
	Companie companie4(companie1);
	cout << companie4;

	cout << "companie5(companie2):\n";
	Companie companie5(companie2);
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

	char* setNN = new char[strlen("Zara") + 1];
	strcpy_s(setNN, strlen("Zara") + 1, "Zara");

	companie5.setNumeCompanie(setNN);
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
	cout << companie6;

	cout << "OPERATOR +\n";
	cout << "companie7 = companie5 + companie3\n";


	Companie companie7;
	companie7 = companie5 + companie3;

	cout << companie7;


	//Companie companie9;
	//cin >> companie9;
	//cout << endl;
	//cout << companie9;

	cout << "--------------------------------------------\n\n";

	cout << "SEDII\n\n";

	cout << "sediu 1";
	cout << endl;
	Sediu sediu1;
	cout << sediu1;

	Sediu sediu2(10, "0742948226");
	cout << "sediu2";
	cout << endl;
	cout << sediu2;


	char* locatie;
	locatie = new char[strlen("Timisoara") + 1];
	strcpy_s(locatie, strlen("Timisoara") + 1, "Timisoara");

	Sediu sediu3(13, 3, 81, "0717945560", locatie);
	cout << "sediu3";
	cout << endl;
	cout << sediu3;

	cout << "SET SEDII: \n";
	sediu2.setNrTotalSedii(9);
	cout << sediu2;


	cout << "CONSTRUCTOR DE COPIERE:\n";
	cout << "sediu4(sediu1)";
	cout << endl;
	Sediu sediu4(sediu1);
	cout << sediu4;

	Sediu sediu5(sediu3);
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
	cout << sediu7;

	//cout << "SEDIU 8:\n ";
	/*Sediu sediu8;
	cin >> sediu8;
	cout << endl << sediu8;*/


	cout << "\n\nsediu9 operator +\n\n" << endl;

	Sediu sediu9;
	cout << "sediu9 = sediu7 + 10\n" << endl;
	sediu9 = sediu7 + 10;
	cout << sediu9;

	cout << "-----------------------------------\n\n";

	cout << "ANGAJATI\n\n";

	Angajat angajat1;
	cout << "angajat1\n";
	cout << angajat1;

	cout << "angajat2\n";
	Angajat angajat2(16, 6.5);
	cout << angajat2;


	char* domeniu = new char[strlen("IT") + 1];

	strcpy_s(domeniu, strlen("IT") + 1, "IT");

	cout << "angajat3\n";
	Angajat angajat3(19, 13, "Stefan Gabriel", 23, domeniu);
	cout << angajat3;

	angajat3.setvarstaPensionare(70);
	cout << angajat3;


	cout << "CONSTRUCTOR DE COPIERE:\n";
	cout << "angajat4(angajat3)\n";
	Angajat angajat4(angajat3);
	cout << angajat4;

	cout << "angajat5(angajat2)\n";
	Angajat angajat5(angajat2);
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
	cout << angajat6;

	//Angajat angajat7;
	//cin >> angajat7;
	//cout << endl << angajat7;

	cout << "angajat8 = angajat8 + 7\n";
	Angajat angajat8;
	cout << angajat8;
	angajat8 = angajat8 + 7;
	cout << angajat8;

	/*Angajat angajat13;
	cout << angajat13;
	cin >> angajat13;
	cout << angajat13;*/

	cout << "angajat operator +\n\n";

	Angajat angajat14;
	angajat14 = angajat8 + 13;
	cout << angajat14;

	cout << "-----------------------------------\n\n";
	cout << "operatori\n\n";
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
	cba = (char*)companie7;
	cout << abc << endl << cba << endl;


	cout << "-----------------------------------\n\n";

	//vectori si matrici

	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PROIECT FAZA 4~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	cout << "\nVECTOR\n";

	Angajat* vectorAngajat = new Angajat[3];
	/*for (int i = 0; i < 3; i++) {
		cin >> vectorAngajat[i];
		cout << endl;
	}*/
	for (int i = 0; i < 3; i++) {
		cout << vectorAngajat[i] << endl << endl;
	}
	cout << endl;


	Sediu* vectorSediu = new Sediu[2];
	/*for (int i = 0; i < 2; i++) {
		cin >> vectorSediu[i];
		cout << endl;
	}*/
	cout << endl;
	for (int i = 0; i < 2; i++) {
		cout << vectorSediu[i] << endl << endl;
	}

	Companie* vectorCompanie = new Companie[2];
	/*for (int i = 0; i < 2; i++) {
		cin >> vectorCompanie[i];
		cout << endl;
	}*/
	cout << endl;
	for (int i = 0; i < 2; i++) {
		cout << vectorCompanie[i];
		cout << endl << endl;
	}

	delete[]vectorAngajat;
	delete[]vectorCompanie;
	delete[]vectorSediu;

	cout << "\nMATRICE\n";

	Companie** matrice = new Companie * [2];
	for (int i = 0; i < 2; i++) {
		matrice[i] = new Companie[2];
	}

	/*for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin>> matrice[i][j];
			cout << endl;
		}
	}*/

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << matrice[i][j];
		}
	}
		
	for (int i = 0; i < 2; i++) {
		delete[]matrice[i];
	}
		delete[]matrice;
	

	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PROIECT FAZA 5~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	//relatia de has-a

	Angajat angajatRelatie1;
	//cin >> angajatRelatie1;
	cout << endl;
	Angajat angajatRelatie2;
	//cin >> angajatRelatie2;
	cout << endl;

	Angajat* vector = new Angajat[2]{ angajatRelatie1 ,angajatRelatie2 };

	Proiect primulProiect("Project X", 12, 43000, 2, vector);
	cout << primulProiect;

	//cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PROIECT FAZA 6~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	//cout << "fisiere\n";


	//Companie companieFisierText;
	//cin >> companieFisierText;
	//ofstream g("Companie.txt", ios::app);
	//g << companieFisierText;
	//g.close();

	//Sediu sediuFisierText;
	//cin >> sediuFisierText;
	//ofstream f("Sediu.txt", ios::app);
	//f << sediuFisierText;
	//f.close();

	//Angajat ang1;
	//fstream ang13("Angajat.bin", ios::out | ios::binary);
	//ang13.write((char*)&ang1, sizeof(Angajat));
	//ang13.close();

	//fstream z("Angajat.bin", ios::in | ios::binary);
	//z.read((char*)&ang1, sizeof(Angajat));
	//z.close();


	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PROIECT FAZA 7~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";


	char* locatieCladireS = new char[strlen("Busteni") + 1];
	strcpy_s(locatieCladireS, strlen("Busteni") + 1, "Busteni");
	Cladire c1;
	Cladire c2(6, 100, 17);
	Cladire c3(15, 1980, 1, 450, 13, 7, 231.2, "999-343-234", locatieCladireS);
	cout << c1;
	cout << c2;
	cout << c3;

	Cladire cCopie(c3);
	cout << cCopie;
	cout << endl;
	Cladire cEgal;
	cEgal = cCopie;
	cout << cEgal;
	cout << endl;

	Sediu* pSed = &c3;
	cout << *pSed;

	cout << "------------------------------------------------" << endl << endl;

	Manager om1;
	Manager om2(3, 5.6);
	Manager om3(4, 1.87, "Piept de pui", 13, 10);
	cout << om1;
	cout << om2;
	cout << om3;
	cout << om1;

	Manager omCopiat(om3);
	cout << omCopiat;
	Manager omEgal;
	omEgal = omCopiat;
	cout << omEgal;

	om1.setInaltime(1.92);
	cout << om1.getInaltime() << endl;
	om1.setNrMembri(6);
	cout << om1.getNrMembri();
	cout << endl;
	om1.setMancare("Carne de vita");
	cout << om1.getMancare();
	cout << endl << endl;



	cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~PROIECT FAZA 8~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

	char* dinamic = new char[strlen("Brasov") + 1];
	strcpy_s(dinamic, strlen("Brasov") + 1, "Brasov");

	char* dinamic1 = new char[strlen("Targu Mures") + 1];
	strcpy_s(dinamic1, strlen("Targu Mures") + 1, "Targu Mures");

	char* dinamic2 = new char[strlen("Sibiu") + 1];
	strcpy_s(dinamic2, strlen("Sibiu") + 1, "Sibiu");



	Informatii* inf = NULL;
	inf = new Cladire();

	ComplexCuSedii c;
	c[0] = inf;
	c[1] = new Sediu();
	c[2] = new Sediu(1, 9, 181, "332-344-673", dinamic);
	c[3] = new Sediu(14, "930-242-111");
	c[4] = new Sediu(1, 7, 143.4, "332-344-673", dinamic1);
	c[5] = new Sediu(1, 10, 201.11, "332-344-673", dinamic2);
	c[6] = new Cladire();
	c[7] = new Cladire(11, 432, 13);
	c[8] = new Cladire(20, 1032, 15);
	c[9] = new Cladire(15, 850, 16);

	for (int i = 0; i < c.getNS(); i++) {
		c[i]->afisareInformatii();
	}



	cout << endl << endl;


	Descriere* d = NULL;
	d = new Angajat();

	SediuCuAngajati sediu;
	sediu[0] = d;
	sediu[1] = new Angajat(21);
	sediu[2] = new Angajat(53);
	sediu[3] = new Angajat(27);
	sediu[4] = new Angajat(23);
	sediu[5] = new Manager();
	sediu[6] = new Manager(7, 4);
	sediu[7] = new Manager(1, 3.2);
	sediu[8] = new Manager(3, 5.3);
	sediu[9] = new Manager(2, 4.5);

	for (int i = 0; i < sediu.getNrA(); i++) {
		sediu[i]->caracteristici();
	}

	delete inf;
	delete d;


}


