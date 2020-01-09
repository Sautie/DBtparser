#ifndef PROF_H
#define PROF_H


class prof {
      string titre;
      string nom;
      string pren;
      bool client;
      string courriel;
      unordered_set<string> lan;
      unordered_set<string> DomPra;
      unordered_set<string> Activites;
    public:
         string pPid;
         prof( string t="", string n="", string pn="", bool c=false, string co=""): titre(t), nom(n), pren(pn), client(c),courriel(co)
        {

         }
        prof(unordered_set<string>& lan, unordered_set<string>& DP, unordered_set<string>& A, string t="", string n="", string pn="", bool c=false, string co=""): lan(lan),DomPra(DP), Activites(A),titre(t), nom(n), pren(pn), client(c),courriel(co)
        {
         }

        prof (const prof &);
        prof& operator=(const prof&);
        bool operator== (const prof & rh) const;
        bool operator!= (const prof & rh) const;
        void AddLang(string lang)
		{
          lan.insert(lang);
		}
		void AddDP(string dp)
		{
          DomPra.insert(dp);
		}
		void AddAct(string act)
		{
          Activites.insert(act);
		}
        string getTitre() const;
        string getNom();
        string getpren();
        bool getClient()const;
        string getCourriel()const;
        unordered_set<string> getlang();
        unordered_set<string> getDP();
        unordered_set<string> getAct();

        void setlang(unordered_set<string>&);
        void setDP(unordered_set<string>&);
        void setAct(unordered_set<string>&);
        void setTitre(string);
        void setNom(string);
        void setpren(string);
        void setClient(bool);
        void setCourriel(string);
        friend ofstream & operator<< (ofstream & out, const prof & c);
        bool valid ();
        void print();

};

struct Adresse {
         string cID;
         string numb;
         string rue;
         string loc;
         string cp;
         string ville;
         string region;
         Adresse(string nb="", string r="", string lo="", string c="", string v="", string reg="", string ID=""):numb(nb), rue(r), loc(lo), cp(c),ville(v), region(reg), cID(ID) {}
         Adresse (const Adresse &vo){
              numb = vo.numb; rue=vo.rue; loc=vo.loc; cp=vo.cp; ville=vo.ville; region=vo.region; cID=vo.cID;
            }
         Adresse& operator=(const Adresse&rr){
           if (this == &rr) return *this;
             numb = rr.numb; rue=rr.rue; loc=rr.loc; cp=rr.cp; ville=rr.ville; region=rr.region; cID=rr.cID;
                }
           };
#endif // TPARSER_H
