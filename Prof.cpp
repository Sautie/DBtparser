#include "Prof.h"

string prof::getTitre() const { return titre; }
string prof::getNom()  { return nom; }
string prof::getpren() { return pren; }
bool prof::getClient()const { return client; }
string prof::getCourriel()const { return courriel; }
unordered_set<string>  prof::getlang() { return lan; }
unordered_set<string>  prof::getDP() { return DomPra; }
unordered_set<string>  prof::getAct() { return Activites; }
void prof::setTitre(string t) { this->titre = t; }
void prof::setNom(string n)     { this->nom = n; }
void prof::setpren(string pn) { this->pren = pn; }
void prof::setClient(bool c)    { this->client = c; }
void prof::setCourriel(string co) { this->courriel = co; }

void prof::setlang(unordered_set<string>&k) { this->lan = k; }
void prof::setDP(unordered_set<string>&j) { this->DomPra = j; }
void prof::setAct(unordered_set<string>&d) { this->Activites = d; }

prof::prof (const prof & cop){
titre = cop.titre;
nom=cop.nom;
pren=cop.pren;
client=cop.client;
courriel =cop.courriel;

lan=cop.lan;
DomPra=cop.DomPra;
Activites=cop.Activites;
}

prof & prof::operator=(const prof &rr){
if (this == &rr) return *this;
titre = rr.titre;
nom=rr.nom;
pren=rr.pren;
client=rr.client;
courriel =rr.courriel;
}

bool prof::operator== (const prof & rh) const {
   return (titre == rh.titre && nom == rh.nom &&pren==rh.pren&&courriel==rh.courriel);
}

bool prof::operator!= (const prof & rh) const {
   return !(*this == rh);
}

/* string prof::getpPid(multimap<string, string>& mDr,   ) {

}*/

ofstream & operator<< (ofstream & out, const prof & c) {

   out <<c.titre <<'\t'<<c.pren <<'\t'<<c.nom<<'\t'<<c.courriel<<'\t';
   out <<"Domaine de pratique"<<'\t';
    for (string val : c.DomPra)
        out <<val<<"; ";
   out<<'\t';
   out <<"Activites"<<'\t';
   for (string val : c.Activites)
        out <<val<<"; ";
   out<<'\t';
   out <<"lan"<<'\t';
   for (string val : c.lan)
        out <<val<<"; ";
   out<<'\t';
 return out;
}

bool prof::valid () {

 return ((titre!="")&&(pren!="")&&(nom!="")&&(courriel!=""));
}

 void prof::print() {
  cout <<titre <<" "<<nom <<", "<<pren<<" "<<client<<" "<<courriel<<'\t';
    unordered_set<string> :: iterator itr;
    for (itr = lan.begin(); itr != lan.end(); itr++)
        cout <<(*itr)<<", ";
        cout <<'\t';
    for (itr = DomPra.begin(); itr != DomPra.end(); itr++)
        cout <<(*itr)<<", ";
        cout <<'\t';
    for (itr = Activites.begin(); itr != Activites.end(); itr++)
        cout <<(*itr)<<", ";
        cout <<'\t';
    cout<<endl;}

