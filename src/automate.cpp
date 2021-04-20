#include "automate.h"
#include "stdio.h"
Automate::Automate() { count_ = 0; };


bool Automate::GenererLangage(std::wstring nom_fichier ) {
    std::ios::sync_with_stdio(false);
    std::locale loc("en_US.UTF-8");
        std::wifstream fichier1(nom_fichier);
       
        fichier1.imbue(loc);
        if (fichier1.is_open())
        {
            std::ios::sync_with_stdio(false);
            std::locale loc("en_US.UTF-8");
            std::wstring mot;
            int index = 0;
            // creation du langage accepté par l'automate
            while (std::getline(fichier1 >> std::ws , mot))
            {
                
                std:: tuple<std::wstring, int, bool,int> nouveau_mot = make_tuple(mot, 0, false,0);
 
                lexique_.push_back(nouveau_mot);
            }
            fichier1.close();
            return true;
        }
        else {
            std::cout << " Pas de lexique disponible"<<std::endl;
            return false;
        }


};

void Automate::AfficherStatistique() {

    std::wcout << "                        Affichage Statistique" << std::endl << std::endl;
    std::wcout << "        Mot         " << "  Frequence d utilisation  " << "     10 derniers mots entrées    " << std::endl;
    std::wcout << "____________________________________________________________________________________________" << std::endl;
        for (size_t i = 0; i < lexique_.size(); i++)
    {
            std::wcout << std::get<0>(lexique_[i]);
            for (size_t j = 0; j < 35-std::get<std::wstring>(lexique_[i]).size(); j++)
            {
                std::cout << " ";
            }
            std::cout << std::get<1>(lexique_[i]);
            if (std::get<1>(lexique_[i]) < 10) {
                for (size_t j = 0; j < 25; j++)
                {
                    std::cout << " ";
                }
            
            
            }
            else{
            for (size_t j = 0; j < 25; j++)
            {
                std::cout << " ";
            }
             }
            if (std::get<2>(lexique_[i])) {

                std::cout << "Oui" << std::endl;

            }
            else {
                std::cout << "Non" << std::endl;
            
            }
            


    }

};

void Automate::SaisiTexte() {

    std:: vector<wchar_t> key_pressed;
    std:: wstring etat;
    std:: wstring enter;
    bool soumission = false;
    bool new_character=false;
    system("CLS");
    while(1){
        bool possibilite = false;
        wchar_t input = (wchar_t)_getwche();
        if(input == L'\r')
        {
            soumission = true;
        }
        else 
        {
            etat += input;
        }
        
        system("CLS");

        std::cout << "Mot possible"<<std::endl<<"__________"<<std::endl;
        for (size_t i = 0; i < lexique_.size(); i++)
        {
            if(std::get<std::wstring>(lexique_[i]).find(etat) == 0){
                possibilite = true;
                std::wcout << std::get<0>(lexique_[i])<<std::endl;
                if (etat == std::get<std::wstring>(lexique_[i]) && soumission) {
                    std::get<1>(lexique_[i])+=1; 
                    count_ += 1;
                    std::get<3>(lexique_[i]) = count_;
                    for (size_t j = 0; j < lexique_.size(); j++)
                    {
                        if (std::get<3>(lexique_[i]) != 0 && std::get<3>(lexique_[i]) > count_ - 10 && std::get<3>(lexique_[i]) <= count_) {
                            std::get<2>(lexique_[i]) = true;
                        }
                        else {
                            std::get<2>(lexique_[i]) = false;

                        }
                    }
               
                    return;
                }
            
            }
           
        }
        if (!possibilite){
            std::wcout << "Aucune Possibilité" << std::endl;
            return;
        
        }
        
        std::wcout << etat;
    
    }
}