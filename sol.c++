#include <iostream>

using namespace std;

class etudiant{
 int matricule;
static int i;
string nom ;
int nbr_nt;
float *tab_nt;
public:

    etudiant(){
    matricule = i++ ;
    nom = "";
    tab_nt = nullptr;
    }

    etudiant(int m , string n , int nbr){
    matricule = m;
    nom = n;
    nbr_nt = nbr;
    }

    ~etudiant(){
    delete []tab_nt;
    matricule = i-- ;
    }

    etudiant(const etudiant& e){
    matricule = i++;
    nom = e.nom;
    nbr_nt = e.nbr_nt;
    tab_nt = new float [nbr_nt];
    for(int j=0 ; j<nbr_nt ; j++){
        tab_nt[j] = e.tab_nt[j];
    }
    }

    string getnom(){
    return nom;
    }
    void setnom(string n){
    nom = n;
    }

    int getmat(){
    return matricule;
    }

    void setmat(int m){
    matricule = m;
    }

    int getnbr_nt(){
    return matricule;
    }

    int get_nbr_nt(){
    return nbr_nt;
    }

    void set_nbr_nt(int nbr_nt){
        this ->nbr_nt = nbr_nt;
        delete []tab_nt;
        tab_nt = new float [nbr_nt];
    }

    float* get_tab_nt(){
    return tab_nt;
    }

    void set_tab_nt(float* t){
    for(int i=0 ; i<nbr_nt ; i++)
        tab_nt[i] = t[i];
    }

void saisir(){
cout<<"saisir les notes"<<endl;
for(int j=0 ; j<nbr_nt ; j++){
    cout<<"saisir la notes "<<j<<endl;
    cin>>tab_nt[j];
}
}

void affichage(){
cout<<"matricule: "<<matricule<<endl;
cout<<"nom: "<<nom<<endl;
cout<<"Nombre de notes: "<<nbr_nt<<endl;
cout<<"Notes: "<<endl;
for(int j=0 ; j<nbr_nt ; j++)
    cout<<tab_nt[j]<<endl;

}

float moy(){
int s=0;
for(int i=0 ; i<nbr_nt ; i++){
    s += tab_nt[i];
}
return s/float(nbr_nt);
}

bool admis(float r){
if(r>=10)
    return true;
else
    return false;
}

bool comparer(float e1,float e2){
if(e1==e2)
    return true;
else
    return false;
}

};

int etudiant::i=0;

int main()
{
cout<<"Creation d'un objet etudiant e1 avec 3 notes"<<endl;
etudiant e1;
e1.setnom("Yassine");
e1.set_nbr_nt(3);
e1.saisir();
//float* tab = e1.get_tab_nt();
//e1.set_tab_nt(tab);

cout<<"Affichage de l'etudiant e1"<<endl;
e1.affichage();
cout<<"Copie de l'etudiant e1 dans e2"<<endl;
etudiant e2 = e1;
cout<<"Affichage de l'etudiant e2"<<endl;
e2.affichage();
etudiant e3;
e3.setnom("Younes");
e3.set_nbr_nt(2);

cout<<"Creation d'un objet etudiant e1 avec 3 notes"<<endl;
e3.saisir();
int m = e3.getmat();
string n = e3.getnom();
int nbr_nt = e3.getnbr_nt();
cout<<"matricule de e3: "<<m<<endl;
cout<<"nom de e3: "<<n<<endl;
cout<<"nbr note de e3: "<<nbr_nt<<endl;
float moy1 = e2.moy();
float moy2 = e3.moy();
cout<<"la moy de e3: "<<moy2<<endl;
bool admis  = e3.admis(moy2);
if(admis)
    cout<<"admis"<<endl;
else
    cout<<"non admis"<<endl;


bool res = e3.comparer(moy1,moy2);
if(res)
    cout<<"meme moy"<<endl;
else
    cout<<"moy differente"<<endl;

return 0;
}
