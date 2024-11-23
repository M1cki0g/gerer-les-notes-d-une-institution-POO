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
    cout<<" "<<tab_nt[j]<<endl;

}

float moy(){
int s=0;
for(int i=0 ; i<nbr_nt ; i++){
    s += tab_nt[i];
}
return s/nbr_nt;
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
e1.setmat(1);
e1.setnom("Yassine");
e1.set_nbr_nt(3);
int n = e1.get_nbr_nt();
float* t = new float[n] ;

for(int i=0 ; i<n ; i++){
    cout<<"note "<<i<<endl;
    cin>>t[i];
}
    e1.set_tab_nt(t);

cout<<"Affichage de l'etudiant e1"<<endl;
e1.affichage();
cout<<"Copie de l'etudiant e1 dans e2"<<endl;
etudiant e2 = e1;
cout<<"Affichage de l'etudiant e2"<<endl;
e2.affichage();

return 0;
}
