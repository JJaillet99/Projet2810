#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <fstream>
#include <tuple>
#include <conio.h>
class Automate
{
public:
    Automate();
    bool GenererLangage(std::wstring nom_fichier);
    void AfficherStatistique();
    void SaisiTexte();

private:
    std::vector<std::tuple<std::wstring,int,bool,int>> lexique_; //wstring est le mot, int le nombre d'entré de celui-ci, bool si il est présent dans les 10 derniers, et int sont numéro d'entré pour calculé si il est dans les 10 derniers
    int count_; // compte le nombre d'entrée 
};
