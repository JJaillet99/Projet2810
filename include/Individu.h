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
    bool GetCovid() const;
    int GetIndex() const;
    std::string GetNom() const;
    std::vector<std::pair<int, float>> GetVoisins() const;
    void AddVoisin(int index, float distance);
    
    

    private:
    int index_;
    std::string nom_;
    bool covid_;
    std::vector<std::pair<int, float>> voisins_;

};