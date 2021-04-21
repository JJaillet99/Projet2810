#include "individu.h"


    Individu::Individu(){};

    Individu::Individu(int index, std::string nom, int covid) : index_(index), nom_(nom), covid_(covid) {}
    //fonction get set pour les attribut des individues
    bool Individu::GetCovid() const
    {
        return covid_; //indique si l'indivue est déjà inffecter par la covid 
    }

    int Individu::GetIndex() const
    {
        return index_; //index permettant de retrouver l'individue dans la liste 
    }

    std::string Individu::GetNom() const
    {
        return nom_; //nom de l'individue
    }

    void Individu::AddVoisin(int index, float distance) //permet d'ajouter un voisin à l'individu
    {
        std::pair<int, float> voisDist = std::make_pair(index, distance);
        voisins_.push_back(voisDist);
    }
    

    std::vector<std::pair<int, float>> Individu::GetVoisins() const // retourne le voisin 
    {
        return voisins_;
    }