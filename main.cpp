
#include<iostream>
#include <fstream>
#include <algorithm>
#include<string>
#include <map>
#include <unordered_set>
#include "Prof.h"
#include "Clinique.h"

using namespace std;

int main()
{
    prof ProReg;
  Clinique ClinReg;
  Adresse Adre;
   map<string,string> mDr;
  string ID, region="Lau";
  vector <prof> bdpro;
  vector <Clinique> bdclin;
  unordered_set<string> memolan, lan, memodp, dpra, memoac, act;

  int doc=0, s=0, nume=0,L=1,p=0,ac=0, cont=0, dp=0, cl=0,z=0,zdr=0, Lc=0;
  ifstream inf;
  string file("tLaurentide2.txt"), line;
  inf.open(file.c_str());
  if(inf.is_open()){
        while(getline(inf,line)){

           if (line.length()==0) z++;
           else if (line.length()>0) {
              //cout<<line<<" "<<z<<" "<<zdr<<" "<<cl<<" "<<endl;
               //cout<<line<<" "<<z<<" "<<zdr<<" "<<cl<<" "<<endl;
              if  (line.find("Voir le profil")!=std::string::npos)                     //(((line.find("Dr")==0)||(zdr==1))&&(line.find(" m.v. Voir le profil ")!=std::string::npos))
            {

                ProReg.getlang().clear();
                ProReg.getAct().clear();
                ProReg.getDP().clear();
                zdr=0;

                string nombre, ID;

                int pos, posf, posi;
                posf=line.find("Dr"); //nom, pren
                posi=line.find(' ', posf);
                ProReg.setTitre(line.substr(posf,posi-posf));
                pos=line.find(',', posi);
                posf=line.rfind(' ', pos);

                ProReg.setNom(line.substr(posf+1,pos-posf));
                ProReg.setpren(line.substr(posi+1,posf-posi));
                nombre=(line.substr(posi+1,posf-posi)) + (line.substr(posf+1,pos-posf));
                ID= to_string(doc)+"Dr"+region;
                // cout<<cont<<" "<<nombre<<endl;
                if (doc==0) {
                    mDr[nombre] =  ID;
                   //mDr.insert(make_pair(nombre,ID));

                      }
                else  {
                    auto it = mDr.find(nombre);

                     if (it == mDr.end()) {
                         mDr[nombre] =  ID;
                      //  cout<<cont<<" "<<mDr[nombre] <<endl;
                           }
                      }
                doc++;

                   }
           /* else if ((line.find("Specialiste")!=std::string::npos)||(s==1))
                 {

                         s=1;

                        z=0;
                      //continue;
                         }*/
             //Domaine de pratique
             else if ((line.find("Domaine de pratique")!=std::string::npos)||(dp>0))
                  {
                     // cout<<cont<<" "<<line<<endl;
                    if ((line.find("Domaine de pratique")==std::string::npos)&&(line.find("Activites")==std::string::npos)&& (line.find("1 2 3 4 5 6 7 8 9")==std::string::npos))
                              { // ProReg.AddDP(line);
                                 memodp.insert(line);

                                  }

                      if (line.find("Activites")!=std::string::npos) { p=1;dp=0; ProReg.setDP(memodp); memodp.clear(); }
                       else  dp++;
                        }
             //Activites
             else if ((line.find("Activites")!=std::string::npos)||(ac>0)||(p==1))
                   {
                       //cout<<line<<" "<<ac<<" "<<L<<" "<<cl<<" "<<endl;
                      if ((line.find("Activites")==std::string::npos)&&(line.find("lan")==std::string::npos)&& (line.find("1 2 3 4 5 6 7 8 9")==std::string::npos))
                         {  //ProReg.AddAct(line);
                            memoac.insert(line); }
                       //Activites
                      if (line.find("lan")!=std::string::npos) {ac=0; L=0;p=0; ProReg.setAct(memoac); memoac.clear(); }
                       else  ac++;
                        }
                //lan
              else if ((z!=2)&&((L==0)||(line.find("Francais")!=std::string::npos)||(line.find("Anglais")!=std::string::npos)||(line.find("allemand")!=std::string::npos)||(line.find("espagnol")!=std::string::npos)||(line.find("arabe")==0)||(line.find("chinois")==0)||(line.find("vietnamienne")==0)||(line.find("roumain")==0)))
              {

                      if (line.find("lan")==std::string::npos)
                         {  //ProReg.AddLang(line);
                            memolan.insert(line); }

                        }
              //clinique
                else if ((z==2)||(cl>0)){
                     if ((not(isdigit(line[line.size()-2])))||(line[0]=='(')){

                       if (L==0) {ProReg.setlang(memolan); memolan.clear(); L=1; }
                    if (cl==0){
                        cout<<line<<endl<<endl;
                      int po, po1;
                        po1=line.find_first_of("0123456789");
                        po=line.find_first_not_of("0123456789", po1);
                         cout<<line.substr(po1, po-po1)<<" este"<<endl;
                        Adre.cID=line.substr(po1, po-po1)+"Cl"+region;
                        ClinReg.setNom(line.substr(0, line.length()));// nom
                       }
                     else if (cl==1) {
                        // numb rue loc
                        int posfs, poss;
                        posfs=line.find(',');
                        Adre.numb=line.substr(0, posfs);
                        poss=line.find(',',posfs+1);
                        if (poss!=std::string::npos) Adre.rue=line.substr(posfs+1, poss-posfs);
                        else Adre.rue=line.substr(posfs+1, line.length()-posfs);
                        //if posfs=line.find(',', poss+1);
                        //if Adre.rue=line.substr(posfs+1, poss-posfs);
                        //Adre.loc=line.substr(poss+1, posfs-poss);
                          }
                     else if (cl==2){
                         Adre.ville=line;}
                     else if (cl==3) {
                          if (line[0]!='(')  Adre.cp=line;
                          else  ClinReg.setTel(line);
                           }//cp
                     else if ((cl==4)&&(line[0]=='(')) {
                        ClinReg.setTel(line);

                        }

                    if (line.find("Itineraire")!=std::string::npos) {
                              ClinReg.setAd(Adre);
                              bdpro.push_back(ProReg);
                               bdclin.push_back(ClinReg);
                              zdr=1;cl=0; nume=0;
                              }
                     else   cl++; }
                 }
               else  if ((zdr==1)) {
            if  ((line.find("Voir le profil")==std::string::npos)&&((not(isdigit(line[line.size()-2])))||(line[0]=='(')))
                  {
                      if (cl==0) {
                        int po, po1;
                            cout<<line<<endl<<endl;
                        po1=line.find_first_of("0123456789");
                        po=line.find_first_not_of("0123456789", po1);
                           cout<<line.substr(po1, po-po1)<<" este"<<endl;
                        Adre.cID=line.substr(po1, po-po1)+"Cl"+region;
                        ClinReg.setNom(line.substr(0, line.length()));
                       }// nom
                     else if (cl==1) {
                        // numb rue loc
                        int posfs, poss;
                        posfs=line.find(',');
                        Adre.numb=line.substr(0, posfs);
                        poss=line.find(',',posfs+1);

                         if (poss!=std::string::npos) Adre.rue=line.substr(posfs+1, poss-posfs);
                        else Adre.rue=line.substr(posfs+1, line.length()-posfs);
                       // posfs=line.find(',',poss+1);
                       // Adre.loc=line.substr(poss+1, posfs-poss);
                          }
                     else if (cl==2){
                         Adre.ville=line;}
                     else if (cl==3) {
                           if (line[0]!='(')  Adre.cp=line;
                          else  ClinReg.setTel(line);
                           }//cp
                     else if ((cl==4)&&(line[0]=='(')) {
                        ClinReg.setTel(line);


                       // cout<<cl<<" "<<line<<endl;
                        }
                        //telephone
                    if (line.find("Itineraire")!=std::string::npos) {
                         ClinReg.setAd(Adre);
                        bdpro.push_back(ProReg);
                        bdclin.push_back(ClinReg);
                    cl=0;
                    }
                     else  cl++;
                                   }  }
                z=0; cont++;
                       }
             }
  }
ofstream fout, pout;
string nombre2;
file="tableOut.txt";
//pout.open(file.c_str());

 //for (map<string, string>::iterator it=mDr.begin(); it!=mDr.end(); ++it)
 //  cout<<(*it).second <<endl;

//cout<<bdpro[0].getpren();
  fout.open(file.c_str());
  map<string, string>::iterator it;
  if(fout.is_open()){
   it=mDr.begin();
   string nomb;
   for (int y=0; y<bdpro.size(); y++){
                     nomb=bdpro[y].getpren()+bdpro[y].getNom();
                     auto it = mDr.find(nomb);
                     if (it != mDr.end()) {
                      fout<<it->second<<'\t';
                      fout<<bdpro[y]<<'\t'<<bdclin[y]<<endl;
                       }
                      //cout<<it->second<<endl;
                     // ++it;
                    }
          }

    return 0;
     }
