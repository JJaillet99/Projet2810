#include <iostream>
#include "GrapheExposition.h"

int main()
{
    bool quitter = false;
    GrapheExposition graphe;


    while(quitter == false)
    {
        char choix;
        std::cout << "(a) Creer le graphe d exposition." << std::endl;
        std::cout << "(b) Afficher le graphe d exposition." << std::endl;
        std::cout << "(c) Afficher notification COVID" << std::endl;
        std::cout << "(d) Quitter." << std::endl;
        std::cout << "(e) testing." << std::endl;
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
                    std::cout << "Le graphe n a pas encore été genere" << std::endl << std::endl;;
                }
                
                
                break;

            case 'c':
              
                if (graphe.getExist())
                {
                    std::string personne;
                    std::cout << "Entrer le nom de la personne que vous souhaiter verifier son exposition a la covid" << std::endl << std::endl;
                    std::cin >> personne;
                    graphe.notifierExposition(personne);
                }
                else
                {
                    std::cout << "Le graphe n as pas encore ete genere" << std::endl << std::endl;;
                }

                break;
            case 'e':
                graphe.testing();
                break;
            case 'd':
                quitter = true;
                break;
          
            default:
                std::cout << "Entre invalide"<<std::endl;
                break;

        }
    }
    

    return 0;
}