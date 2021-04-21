#include "automate.h"
#include "stdio.h"
Automate::Automate() { count_ = 0; };


bool Automate::GenererLangage(std::wstring nom_fichier ) {
    std::ios::sync_with_stdio(false);
    std::locale loc("en_US.UTF-8");
        std::wifstream fichier1(nom_fichier);
       
        fichier1.imbue(loc);// ouvre le fichier 
        if (fichier1.is_open()) // v�rifie que le ficher est bien ouvert 
        {
            std::ios::sync_with_stdio(false);
            std::locale loc("en_US.UTF-8");
            std::wstring mot;
            int index = 0;
            // creation du langage accept� par l'automate
            while (std::getline(fichier1 >> std::ws , mot))
            {
                
                std:: tuple<std::wstring, int, bool,int> nouveau_mot = make_tuple(mot, 0, false,0);//wstring c'est le mot, int le nombre de fois qu'il � �t� utilis�, bool si il a �t� appeler dans les 10 derniers, int compteur du num�ro de l'entr�e
 
                lexique_.push_back(nouveau_mot); // pouur le tuple dans liste 
            }
            fichier1.close();// ferme le fichier 
            return true;
        }
        else {// si le fichier n'a pas pu bien s'ouvrir 
            std::cout << " Pas de lexique disponible"<<std::endl; 
            return false;
        }


};

void Automate::AfficherStatistique() {

    std::wcout << "                        Affichage Statistique" << std::endl << std::endl; 
    std::wcout << "        Mot         " << "  Frequence d utilisation  " << "     10 derniers mots entr�es    " << std::endl;
    std::wcout << "____________________________________________________________________________________________" << std::endl;
        for (size_t i = 0; i < lexique_.size(); i++)
    {
            std::wcout << std::get<0>(lexique_[i]);
            for (size_t j = 0; j < 35-std::get<std::wstring>(lexique_[i]).size(); j++)
            {
                std::cout << " "; // formattage de l'affichage afin d'avoir d'avoir des ligne droite 
            }
            std::cout << std::get<1>(lexique_[i]);
            if (std::get<1>(lexique_[i]) < 10) {
                for (size_t j = 0; j < 25; j++)
                {
                    std::cout << " ";  // formattage de l'affichage afin d'avoir d'avoir des ligne droite 
                }
            
            
            }
            else{
            for (size_t j = 0; j < 25; j++)
            {
                std::cout << " "; // formattage de l'affichage afin d'avoir d'avoir des ligne droite 
            }
             }
            //tranforme un bool en oui ou non pour l'affichage des statistiques
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
    system("CLS");  // clear la console 
    // il s'agit de notre machine a �tat
    while(1){ // boucle while prenant fin lorsqu'on recoit une entr� valide
        bool possibilite = false;
        wchar_t input = (wchar_t)_getwche();
        if(input == L'\r') // lorsque l'utilisateur appuie sur la touche "enter" on envoie la soumission, qui sera utilis� comme un flag 
        {
            soumission = true;
        }
        else 
        {
            etat += input; //chaque lettre change l'�tat afin que l'�tat soit repr�sentatif du mot
        }
        
        system("CLS"); // clear la console 

        std::cout << "Mot possible"<<std::endl<<"__________"<<std::endl;
        //affiche l'ensemble des mots suivant l'�tat actuel
        for (size_t i = 0; i < lexique_.size(); i++)
        {
            if(std::get<std::wstring>(lexique_[i]).find(etat) == 0){ //cherche si on mot existant commencant avec les lettres repr�sentant l'�tat pr�sent 
                possibilite = true;
                std::wcout << std::get<0>(lexique_[i])<<std::endl; 
                if (etat == std::get<std::wstring>(lexique_[i]) && soumission) { //v�rifie s'il existe un mot composer uniquement des lettres repr�sentant l'�tat actuel et que l'utilisateur � appuyer sur enter
                    std::get<1>(lexique_[i])+=1; //ajoute un au compteur pour les statistiques du mots 
                    count_ += 1;  //compte le nombre de mots entr� au total
                    std::get<3>(lexique_[i]) = count_;//num�ro d'entr� du mot 
                    for (size_t j = 0; j < lexique_.size(); j++)  // met le flag a false pour la 11e mot rentr� s'il y a u plus de 10 mots 
                    {
                        if (std::get<3>(lexique_[j]) != 0 && std::get<3>(lexique_[j]) > count_ - 10 && std::get<3>(lexique_[j]) <= count_) {
                            std::get<2>(lexique_[j]) = true;
                        }
                        else {
                            std::get<2>(lexique_[j]) = false;

                        }
                    }
               
                    return;
                }
            
            }
           
        }
        if (!possibilite){// si aucun mot du lexique ne contient la combinaison de lettre formant l'�tat de l'automate 
            std::wcout << "Aucune Possibilit�" << std::endl;
            return;
        
        }
        
        std::wcout << etat;
    
    }
}