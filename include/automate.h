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
    std::vector<std::tuple<std::wstring,int,bool,int>> lexique_;
    int count_;
};
