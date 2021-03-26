#include "GrapheExposition.h"

GrapheExposition::GrapheExposition(){}

bool GrapheExposition::getExist() const
{
    return grapheExiste_;
}

void GrapheExposition::creerGrapheExposition(std::string individu, std::string contact)
{
if(!grapheExiste_)
{
    std::ifstream fichier1 (individu);
    
    if (fichier1.is_open())
    {
        std::string nom;
        std::string covid;
        while(std::getline(fichier1, nom, ','))
        { 
            std::getline(fichier1,covid);
            int statut = std::stoi(covid);
            Individu nouveau(nom, statut);
            population_.push_back(nouveau);
        }
        fichier1.close();
    }


    std::ifstream fichier2 (contact);
    if (fichier2.is_open())
    {
        std::string nomIndividuPrecedent = " ";
        std::string nomIndividu;
        std::string nomVoisin;
        std::string distanceString;
        Individu individu;
        Individu voisin;
        while(std::getline(fichier2, nomIndividu, ' '))
        {
            std::getline(fichier2, distanceString, ' ');
            std::getline(fichier2,nomVoisin);
            if(nomVoisin.back() == '\r')
            {
                nomVoisin.pop_back();
            }
            if(nomVoisin.back() == ' ')
            {
                nomVoisin.pop_back();
            }
            
            float distance = std::stof(distanceString);

            population_[getIndexParNom(nomIndividu)].addVoisin(population_[getIndexParNom(nomVoisin)],distance);

            nomIndividuPrecedent = nomIndividu;
            
        }

        fichier2.close();
    }
    grapheExiste_ = true;
    std::cout << "Le graphe a été généré";
}
else
{
    std::cout << "Le graphe est déjà généré";
}

}

size_t GrapheExposition::getIndexParNom(std::string nom)
{
    for(size_t i = 0; i < population_.size(); i++)
    {
        if (population_[i].getNom() == nom)
        {
            return i;
        }
    }
    return 0;
}

void GrapheExposition::afficherGrapheExposition()
{
    for(Individu individu : population_)
    {
        for(std::pair<Individu, float> voisDist : individu.getVoisins())
        {
            std::cout << "(" << individu.getNom() << " ";
            std::cout << voisDist.first.getNom() << " ";
            std::cout << "(" << voisDist.second << "))" << std::endl;
        }
    }
    std::cout << std::endl;
}