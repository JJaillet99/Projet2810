#include <iostream>
#include "GrapheExposition.h"
#include "lexique.h"

#include <locale>

int main()
{
    setlocale(LC_ALL, "fra");
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
                                
                         
                                std::wcout << "Le graphe n a pas encore ete genere" << std::endl << std::endl;;
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
            {   bool lexique_creer = false;
                std::wstring fichier;
                Lexique banque_mot = Lexique();
                while(quitter == false)
                {
                    char choix;
                    std::wcout << "(d) Creer automate." << std::endl;
                    std::cout << "(e) Saisir mot." << std::endl;
                    std::cout << "(f) Afficher statistiques." << std::endl;
                    std::cout << "(g) Quitter" << std::endl;
                    std::cin >> choix;
                    std::cout << std::endl;

                    switch(choix)
                    {
                        case 'd':
                        {
                            std::cout << "Entre nom du fichier du lexique"<<std::endl;
                            std::wcin >> fichier;
                            if(banque_mot.genererLangage(fichier)==true ){
                            lexique_creer = true;
                            }

                        break;
                        }

                        case 'e':
                        {

                            std::cout << "Tappe un mot" << std::endl << std::endl;;
                            banque_mot.SaisiTexte();
                        break;
                        }
                        case 'f':
                        {

                            if (lexique_creer) {
                                banque_mot.AfficherStatistique();
                            
                            }
                            else {
                                std::cout << "Pas de lexique" << std::endl;
                            
                            
                            
                            }
                            
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