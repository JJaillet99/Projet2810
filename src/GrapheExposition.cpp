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
        int index = 0;
        while(std::getline(fichier1, nom, ','))
        { 
            
            std::getline(fichier1,covid);
            int statut = std::stoi(covid);
            Individu nouveau(index, nom, statut);
            population_.push_back(nouveau);
            index++;
        }
        fichier1.close();
    }


    std::ifstream fichier2 (contact);
    if (fichier2.is_open())
    {
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
            while(nomVoisin.back() == ' ')
            {
                nomVoisin.pop_back();
            }
            
            float distance = std::stof(distanceString);
            int indexIndividu = getIndexParNom(nomIndividu);
            int indexVoisin = getIndexParNom(nomVoisin);
            population_[indexIndividu].addVoisin(indexVoisin, distance);
            population_[indexVoisin].addVoisin(indexIndividu, distance);
        }

        fichier2.close();
    }
    grapheExiste_ = true;
    std::cout << "Le graphe a ete genere";
}
else
{
    std::cout << "Le graphe est deja genere";
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
    return -1;
}

void GrapheExposition::afficherGrapheExposition()
{
    for(Individu individu : population_)
    {
        for(std::pair<int , float> voisDist : individu.getVoisins())
        {
            std::cout << "(" << individu.getNom() << " ";
            std::cout << population_[voisDist.first].getNom() << " ";
            std::cout << "(" << voisDist.second << "))" << std::endl;
        }
    }
    std::cout << std::endl;
}

bool GrapheExposition::identifierExposition(std::string x, std::string y)
{
    std::set<std::pair<float, int>> ensemble;
    std::map<int, float> distance;
    int indexX;
    for (int i = 0; i<population_.size(); i++)
    {
        distance[population_[i].getIndex()] = 10000;
        if(population_[i].getNom() == x)
        {
            distance[population_[i].getIndex()] = 0;
            indexX = i;
        }
    }
    ensemble.insert(std::make_pair(0, indexX));
    
    
    while(!ensemble.empty())
    {
        int individu = ensemble.begin()->second;
        if(population_[individu].getNom() == y)
        {
            if(population_[individu].getCovid() == 1 && distance[individu] < 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        ensemble.erase(ensemble.begin());
        

        for(std::pair<int, float> voisin : population_[individu].getVoisins())
        {
            if(voisin.second < 2)
            {
                if(distance[voisin.first] > distance[individu] + voisin.second)
                {
                    if(distance[voisin.first] != 10000)
                    {
                        ensemble.erase(ensemble.find(std::make_pair(distance[voisin.first], voisin.first)));
                    }
                    distance[voisin.first] = distance[individu] + voisin.second;
                    ensemble.insert(std::make_pair(distance[voisin.first], voisin.first));
                    
                }
            }
        }
    }
    return false;
}

void GrapheExposition::notifierExposition(std::string individu) {

    int index=getIndexParNom(individu);
    if (index == -1) {
        std::cout << "Aucunes donnes sur cette personne" << std::endl << std::endl;
        return;
    }
    for (size_t i = 0; i < population_.size(); i++)
    {  

        if (i==index){
            if (population_[i].getCovid()) {
                std::cout << individu << ", vous avez la covid-19" << std::endl << std::endl;
                return;
            }

        }
        else {
            if (identifierExposition(individu, population_[i].getNom())) {
                std::cout << individu << ", vous avez ete expose au cours des 14 derniers jours" << std::endl << std::endl;
                return;
            }
        }

    }
    std::cout << "Aucune exposition detecte" << std::endl << std::endl; // � remettre, juste enlever pour le testing

}
