#include "Individu.h"


    Individu::Individu(){};

    Individu::Individu(std::string nom, int covid) : nom_(nom), covid_(covid) {}

    int Individu::getCovid() const
    {
        return covid_;
    }

    std::string Individu::getNom() const
    {
        return nom_;
    }

    void Individu::addVoisin(Individu voisin, float distance)
    {
        std::pair<Individu, float> voisDist = std::make_pair(voisin, distance);
        voisins_.push_back(voisDist);
    }
    

    std::vector<std::pair<Individu, float>> Individu::getVoisins() const
    {
        return voisins_;
    }