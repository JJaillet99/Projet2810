#include "lexique.h"
Lexique::Lexique() { count_ = 0; };


bool Lexique::AddWord(std::string nom_fichier ) {
  
        std::ifstream fichier1(nom_fichier);

        if (fichier1.is_open())
        {
            std::string mot;
            int index = 0;
            while (std::getline(fichier1, mot, ','))
            {
                std:: tuple<std::string, int, bool,int> nouveau_mot = make_tuple(mot, 0, false,0);
 
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

void Lexique::AfficherStatistique() {

    std::cout << "                        Affichage Statistique" << std::endl << std::endl;
    std::cout << "        Mot         " << "  Frequence d utilisation  " << "     10 derniers mots entrées    " << std::endl;
    std::cout << "____________________________________________________________________________________________" << std::endl;
        for (size_t i = 0; i < lexique_.size(); i++)
    {
            std::cout << std::get<0>(lexique_[i]);
            for (size_t j = 0; j < 35-std::get<std::string>(lexique_[i]).size(); j++)
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

void Lexique::SaisiTexte() {
    std:: vector<char> key_pressed;
    std::string entre;
    bool new_character=false;
    system("CLS");
    while(1){

        entre+=(char)_getche();
        system("CLS");
        std::cout << "Mot possible"<<std::endl<<"__________"<<std::endl;
        for (size_t i = 0; i < lexique_.size(); i++)
        {
            if(std::get<std::string>(lexique_[i]).find(entre)!= std::string::npos){
                std::cout << std::get<0>(lexique_[i])<<std::endl;
                if (entre == std::get<std::string>(lexique_[i])) {
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
        std::cout << entre;
    
    }
}