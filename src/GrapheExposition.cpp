#include "grapheExposition.h"

GrapheExposition::GrapheExposition(){}

bool GrapheExposition::GetExist() const
{
    return graphe_existe_;
}

void GrapheExposition::CreerGrapheExposition(std::string individu, std::string contact)
{
if(!graphe_existe_)
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
            if (statut == 0) {
              Individu nouveau(index, nom, false);
              population_.push_back(nouveau);
            }
            else {
              Individu nouveau(index, nom, true);
              population_.push_back(nouveau);
            }
            index++;
        }
        fichier1.close();
    }


    std::ifstream fichier2 (contact);
    if (fichier2.is_open())
    {
        std::string nom_individu;
        std::string nom_voisin;
        std::string distance_string;
        Individu individu;
        Individu voisin;
        while(std::getline(fichier2, nom_individu, ' '))
        {
            std::getline(fichier2, distance_string, ' ');
            std::getline(fichier2,nom_voisin);
            if(nom_voisin.back() == '\r')
            {
                nom_voisin.pop_back();
            }
            while(nom_voisin.back() == ' ')
            {
                nom_voisin.pop_back();
            }
            
            float distance = std::stof(distance_string);
            int indexIndividu = GetIndexParNom(nom_individu);
            int indexVoisin = GetIndexParNom(nom_voisin);
            population_[indexIndividu].AddVoisin(indexVoisin, distance);
            population_[indexVoisin].AddVoisin(indexIndividu, distance);
        }

        fichier2.close();
    }
    graphe_existe_ = true;
    std::cout << "Le graphe a ete genere";
}
else
{
    std::cout << "Le graphe est deja genere";
}

}

size_t GrapheExposition::GetIndexParNom(std::string nom)
{
    for(size_t i = 0; i < population_.size(); i++)
    {
        if (population_[i].GetNom() == nom)
        {
            return i;
        }
    }
    return -1;
}

void GrapheExposition::AfficherGrapheExposition()
{
    for(Individu individu : population_)
    {
        for(std::pair<int , float> voisDist : individu.GetVoisins())
        {
            std::cout << "(" << individu.GetNom() << " ";
            std::cout << population_[voisDist.first].GetNom() << " ";
            std::cout << "(" << voisDist.second << "))" << std::endl;
        }
    }
    std::cout << std::endl;
}

bool GrapheExposition::IdentifierExposition(std::string x, std::string y)
{
    std::set<std::pair<float, int>> ensemble;
    std::map<int, float> distance;
    int indexX;
    for (int i = 0; i<population_.size(); i++)
    {
        distance[population_[i].GetIndex()] = 10000;
        if(population_[i].GetNom() == x)
        {
            distance[population_[i].GetIndex()] = 0;
            indexX = i;
        }
    }
    ensemble.insert(std::make_pair(0, indexX));
    
    
    while(!ensemble.empty())
    {
        int individu = ensemble.begin()->second;
        if(population_[individu].GetNom() == y)
        {
            if(population_[individu].GetCovid() == true && distance[individu] < 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        ensemble.erase(ensemble.begin());
        

        for(std::pair<int, float> voisin : population_[individu].GetVoisins())
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

void GrapheExposition::NotifierExposition(std::string individu) {

    int index=GetIndexParNom(individu);
    if (index == -1) {
        std::cout << "Aucunes donnes sur cette personne" << std::endl << std::endl;
        return;
    }
    for (size_t i = 0; i < population_.size(); i++)
    {  

        if (i==index){
            if (population_[i].GetCovid()) {
                std::cout << individu << ", vous avez la covid-19" << std::endl << std::endl;
                return;
            }

        }
        else {
            if (IdentifierExposition(individu, population_[i].GetNom())) {
                std::cout << individu << ", vous avez ete expose au cours des 14 derniers jours" << std::endl << std::endl;
                return;
            }
        }

    }
    std::cout << "Aucune exposition detecte" << std::endl << std::endl; // � remettre, juste enlever pour le testing

}
