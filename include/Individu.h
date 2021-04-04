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
    Individu(std::string nom, int covid);
    int getCovid() const;
    std::string getNom() const;
    std::vector<std::pair<std::shared_ptr<Individu>, float>> getVoisins() const;
    void addVoisin(std::shared_ptr<Individu> voisin, float distance);
    
    

    private:
    std::string nom_;
    int covid_;
    std::vector<std::pair<std::shared_ptr<Individu>, float>> voisins_;

};