#include "Clinique.h"

Clinique::Clinique(const Clinique & cop){
nom = cop.nom;
telephone=cop.telephone;
ad=cop.ad;
}

Clinique & Clinique::operator=(const Clinique &rr){
if (this == &rr) return *this;
nom = rr.nom;
telephone=rr.telephone;
ad.numb=rr.ad.numb;
ad.rue=rr.ad.rue;
ad.loc=rr.ad.loc;
ad.ville=rr.ad.ville;
ad.region=rr.ad.region;
ad.cp=rr.ad.cp;
ad.cID=rr.ad.cID;
}

Clinique::Clinique(Clinique&& other) :nom(""), telephone("")
    {
        ad.numb=""; ad.rue=""; ad.loc=""; ad.cp=""; ad.ville=""; ad.region=""; ad.cID="";
        nom = other.nom;
        telephone = other.telephone;
        ad.numb=other.ad.numb;
        ad.rue=other.ad.rue;
        ad.loc=other.ad.loc;
        ad.ville=other.ad.ville;
        ad.region=other.ad.region;
        ad.cp=other.ad.cp;
        ad.cID=other.ad.cID;

        other.nom="";
        other.telephone="";
        other.ad.numb="";
        other.ad.rue="";
        other.ad.loc="";
        other.ad.ville="";
        other.ad.region="";
        other.ad.cp="";
        other.ad.cID="";
       }

Clinique& Clinique::operator=(Clinique&& other)
    {
      if (this != &other) {
       nom = other.nom;
        telephone = other.telephone;
        ad.numb=other.ad.numb;
        ad.rue=other.ad.rue;
        ad.loc=other.ad.loc;
        ad.ville=other.ad.ville;
        ad.region=other.ad.region;
        ad.cp=other.ad.cp;
        ad.cID=other.ad.cID;

        other.nom="";
        other.telephone="";
        other.ad.numb="";
        other.ad.rue="";
        other.ad.loc="";
        other.ad.ville="";
        other.ad.region="";
        other.ad.cp="";
         other.ad.cID="";
       }
       return *this;
    }

string Clinique::getNom() const { return nom; }
string Clinique::getTel()  const { return telephone; }
Adresse Clinique::getAd()  const { return ad; }

void Clinique::setNom(string N) { this->nom = N; }
void Clinique::setTel(string t)     { this->telephone = t; }
void Clinique::setAd(Adresse a) { this->ad = a; }

ostream & operator<< (ostream & out, const Clinique & c) {
   out <<c.ad.cID<<'\t'<<c.nom <<'\t'<<c.ad.numb<<", "<<c.ad.rue<<'\t'<<c.ad.ville<<'\t'<<c.ad.region<<'\t'<<c.ad.cp<<'\t'<<c.telephone;
 //<<", "<<c.ad.loc
 return out;
}

bool Clinique::valid () {
 return (telephone!="");
}
 void Clinique::print() {
  cout <<nom<<" "<<telephone<<" "<<ad.numb<<" "<<ad.rue<<" "<<ad.ville<<endl;
}

