#include <iostream>
#include "GrapheExposition.h"

int main()
{
    bool quitter = false;
    GrapheExposition graphe;
    


    while(quitter == false)
    {
        char choix;
        std::cout << "(a) Créer le graphe d'exposition." << std::endl;
        std::cout << "(b) Afficher le graphe d'exposition." << std::endl;
        std::cout << "(c) Aﬀicher notification COVID" << std::endl;
        std::cout << "(d) Quitter." << std::endl;
        std::cin >> choix;
        std::cout << std::endl;
        switch(choix)
        {
            case 'a':
                graphe.creerGrapheExposition("Individus.txt", "Contacts.txt");
                std::cout << std::endl << std::endl;
                break;

            case 'b':
                if(graphe.getExist())
                {
                    graphe.afficherGrapheExposition();
                }
                else
                {
                    std::cout << "Le graphe n'as pas encore été généré" << std::endl << std::endl;;
                }
                
                
                break;

            case 'c':
                std::cout << "Affichage notification." << std::endl << std::endl;
                break;

            case 'd':
                quitter = true;
                break;

            default:
                std::cout << std::endl;

        }
    }
    

    return 0;
}