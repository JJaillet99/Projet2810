#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <vector>



class Individu
{
    public:
    Individu();
    Individu(std::string nom, int covid);
    int getCovid() const;
    std::string getNom() const;
    std::vector<std::pair<Individu, float>> getVoisins() const;
    void addVoisin(Individu voisin, float distance);
    
    

    private:
    std::string nom_;
    int covid_;
    std::vector<std::pair<Individu, float>> voisins_;

};