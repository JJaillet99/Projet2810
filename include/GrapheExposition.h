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
    void CreerGrapheExposition(std::string individu, std::string contact);
    void AfficherGrapheExposition();
    bool IdentifierExposition(std::string x, std::string y);
    void NotifierExposition(std::string individu);
    bool GetExist() const;
    private:
    size_t GetIndexParNom(std::string nom);
    std::vector<Individu> population_;
    bool graphe_existe_ = false;

    
};