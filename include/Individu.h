#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <memory>



class Individu
{
    public:
    Individu();
    Individu(int index, std::string nom, int covid);
    bool GetCovid() const; // retourne si l'indivue � le covid ou non 
    int GetIndex() const; //retourne l'index 
    std::string GetNom() const; // retourne le nom 
    std::vector<std::pair<int, float>> GetVoisins() const; // retourne les voisins de l'individue 
    void AddVoisin(int index, float distance); // ajoute un voisin � l'individue
    
    

    private:
    int index_; // index permettant de retrouver l'individu dans la liste 
    std::string nom_; // nom de l'individue
    bool covid_; // indique si l'individue � �t� infecter par la covid
    std::vector<std::pair<int, float>> voisins_; // voisin de l'invidividu et distance avec celui-ci

};