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
    std::vector<std::tuple<std::wstring,int,bool,int>> lexique_; //wstring est le mot, int le nombre d'entr� de celui-ci, bool si il est pr�sent dans les 10 derniers, et int sont num�ro d'entr� pour calcul� si il est dans les 10 derniers
    int count_; // compte le nombre d'entr�e 
};
