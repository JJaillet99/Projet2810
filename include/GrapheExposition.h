#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <utility>
#include "individu.h"


class GrapheExposition
{


    public:
         GrapheExposition();
    void CreerGrapheExposition(std::string individu, std::string contact); // créer le graph à partir d'un fichier txt 
    void AfficherGrapheExposition(); // affiche l'ensemble du graph en affiche l'individue, son voisin et leur distance 
    bool IdentifierExposition(std::string x, std::string y); // détermine si l'individue x à été exposé par l'individu y
    void NotifierExposition(std::string individu); // indique si l'individue à été exposer 
    bool GetExist() const; //retourne si le graph existe
    private:
    size_t GetIndexParNom(std::string nom);
    std::vector<Individu> population_; // liste des individue 
    bool graphe_existe_ = false; // indique si le graph à été creer 

    
};