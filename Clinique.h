#ifndef CLINIQUE_H
#define CLINIQUE_H

class Clinique {
      string nom;
      string telephone;
      //string
      Adresse ad;
    public:
        Clinique(string n="", string t="", string nb="", string r="", string lo="", string c="", string v="", string reg="", string ID=""):
                 nom(n),
                 telephone(t)
                  {
                   ad.numb=nb; ad.rue=r; ad.loc=lo; ad.cp=c; ad.ville=v; ad.region=reg; ad.cID=ID;
                  }
        Clinique (const Clinique &);
        Clinique& operator=(const Clinique&);
        Clinique(Clinique &&arr);
        Clinique& operator=(Clinique &&arr);
        //bool operator== (const Clinique & rhs) const;
       // bool operator!= (const Clinique & rhs) const;
       // friend ofstream & operator<< (ofstream & out, const Clinique & c); // out << c
        string getNom() const;
        string getTel() const;
        Adresse getAd() const;

        void setNom(string);
        void setTel(string);
        void setVille(string);
        void setAd(Adresse);

        bool valid ();
        friend ostream & operator<< (ostream & out, const Clinique & c);
        void print();
};
#endif
