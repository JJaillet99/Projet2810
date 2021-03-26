#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Individu.h"


class GrapheExposition
{
    public:

    GrapheExposition();

    void creerGrapheExposition(std::string individu, std::string contact);
    void afficherGrapheExposition();
    bool getExist() const;

    private:
    size_t getIndexParNom(std::string nom);
    std::vector<Individu> population_;
    bool grapheExiste_ = false;

    
};