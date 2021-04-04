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
        for(std::pair<Individu, float> voisDist : individu.getVoisins())
        {
            std::cout << "(" << individu.getNom() << " ";
            std::cout << voisDist.first.getNom() << " ";
            std::cout << "(" << voisDist.second << "))" << std::endl;
        }
    }
    std::cout << std::endl;
}

bool GrapheExposition::identifierExposition(std::string x, std::string y){
    int index_x = getIndexParNom(x);
    int index_y = getIndexParNom(y);
    if (population_[index_y].getCovid()!=true) {
        return false;
    }
    for (size_t i = 0; i < population_[index_x].getVoisins().size(); i++)
    {
        if (population_[index_x].getVoisins()[i].second < 2){
            if (population_[index_x].getVoisins()[i].first.getNom()==y) {
                return true;

            }
            else {
                if (identifierExposition(population_[index_x].getVoisins()[i].first.getNom(), y)) {
                    return true;
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
                std::cout << individu << ",Vous avez la covid-19" << std::endl << std::endl;
                return;
            }

        }
        else {
            if (identifierExposition(individu, population_[i].getNom())) {
                std::cout <<individu << ",Vous avez ete expose au cours des 14 derniers jours" << std::endl << std::endl;
                return;
            }
        }

    }
    std::cout << "Aucune exposition detecte" << std::endl << std::endl; // � remettre, juste enlever pour le testing

}
void GrapheExposition::testing() // donne la liste de tous les gens expos� 
{
    for (size_t i = 0; i < population_.size(); i++)
    {
        //std::cout << population_[i].getNom() << std::endl << std::endl;
        notifierExposition(population_[i].getNom());
    }
}