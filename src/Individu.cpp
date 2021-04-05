#include "Individu.h"


    Individu::Individu(){};

    Individu::Individu(int index, std::string nom, int covid) : index_(index), nom_(nom), covid_(covid) {}

    int Individu::getCovid() const
    {
        return covid_;
    }

    int Individu::getIndex() const
    {
        return index_;
    }

    std::string Individu::getNom() const
    {
        return nom_;
    }

    void Individu::addVoisin(int index, float distance)
    {
        std::pair<int, float> voisDist = std::make_pair(index, distance);
        voisins_.push_back(voisDist);
    }
    

    std::vector<std::pair<int, float>> Individu::getVoisins() const
    {
        return voisins_;
    }