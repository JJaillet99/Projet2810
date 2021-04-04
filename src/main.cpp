#include <iostream>
#include "GrapheExposition.h"

int main()
{
    bool quitterPrincipal = false;
    
    while(quitterPrincipal == false)
    {
        bool quitter = false;
        char choixPrincipal;
        std::cout << "(a) Alerte COVID." << std::endl;
        std::cout << "(b) Jeu Instructif." << std::endl;
        std::cout << "(c) Quitter." << std::endl;
        std::cin >> choixPrincipal;
        std::cout << std::endl;
        switch(choixPrincipal)
        {
            case 'a':
            {
                GrapheExposition graphe;
                while(quitter == false)
                {
                    char choix;
                    std::cout << "(a) Creer le graphe d exposition." << std::endl;
                    std::cout << "(b) Afficher le graphe d exposition." << std::endl;
                    std::cout << "(c) Afficher notification COVID" << std::endl;
                    std::cout << "(d) Quitter." << std::endl;
                    std::cin >> choix;
                    std::cout << std::endl;
                    switch(choix)
                    {
                        case 'a':
                        {
                            graphe.creerGrapheExposition("Individus.txt", "Contacts.txt");
                            std::cout << std::endl << std::endl;
                        break;
                        }

                        case 'b':
                        {
                            if(graphe.getExist())
                            {
                                graphe.afficherGrapheExposition();
                            }
                            else
                            {
                                std::cout << "Le graphe n a pas encore été genere" << std::endl << std::endl;;
                            }
                        break;
                        }
                        case 'c':
                        {
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
                        }

                        case 'd':
                        {
                            quitter = true;
                        break;
                        }

                        default:
                        {
                            std::cout << "Entre invalide"<<std::endl;
                        break;
                        }
                    }
                }
            break;
            }
                

            case 'b':
            {
                while(quitter == false)
                {
                    char choix;
                    std::cout << "(d) Créer automate." << std::endl;
                    std::cout << "(e) Saisir mot." << std::endl;
                    std::cout << "(f) Afficher statistiques." << std::endl;
                    std::cout << "(g) Quitter" << std::endl;
                    std::cin >> choix;
                    std::cout << std::endl;

                    switch(choix)
                    {
                        case 'd':
                        {
                            std::cout << "Creation automate" << std::endl << std::endl;
                        break;
                        }

                        case 'e':
                        {

                            std::cout << "Tappe un mot" << std::endl << std::endl;;
                        break;
                        }
                        case 'f':
                        {

                        std::cout << "Statistique" << std::endl << std::endl;;
                            
                        break;
                        }

                        case 'g':
                        {
                            quitter = true;
                        break;
                        }

                        default:
                        {
                            std::cout << "Entre invalide"<<std::endl;
                        break;
                        }
                    }
                }
            break;
            }

            

            case 'c':
            {
                quitterPrincipal = true;
            break;
            }

            default:
            {
                std::cout << "Entre invalide"<<std::endl;
            break;
            }
            
        }
    }
    
    

    return 0;
}