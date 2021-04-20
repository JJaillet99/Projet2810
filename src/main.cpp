#include <iostream>
#include "grapheExposition.h"
#include "automate.h"
#include <locale>
#include <Windows.h>
int main()
{
    setlocale(LC_ALL, "fra");
    bool quitterPrincipal = false;

    
    while(quitterPrincipal == false)
    {
        bool quitter = false;
        char choixPrincipal;
        system("CLS");
        std::cout << "(a) Alerte COVID." << std::endl;
        std::cout << "(b) Jeu Instructif." << std::endl;
        std::cout << "(c) Quitter." << std::endl;
        std::cin >> choixPrincipal;
        system("CLS");
        std::cout << std::endl;
        switch(choixPrincipal)
        {

           
            case 'a':
            {
                GrapheExposition graphe= GrapheExposition ();
                while(quitter == false)
                {
                  
                    char choix;
                    std::cout << "(a) Creer le graphe d exposition." << std::endl;
                    std::cout << "(b) Afficher le graphe d exposition." << std::endl;
                    std::cout << "(c) Afficher notification COVID" << std::endl;
                    std::cout << "(d) Quitter." << std::endl;
                    std::cin >> choix;
                    system("CLS");
                    std::cout << std::endl;
                    switch(choix)
                    {
                        case 'a':
                        {   
                            graphe.CreerGrapheExposition("Individus.txt", "Contacts.txt");
                            std::cout << std::endl << std::endl;
                        break;
                        }

                        case 'b':
                        {
                            if(graphe.GetExist())
                            {
                                graphe.AfficherGrapheExposition();
                            }
                            else
                            {
                                
                         
                                std::wcout << "Le graphe n a pas encore ete genere" << std::endl << std::endl;;
                            }
                        break;
                        }
                        case 'c':
                        {
                            if (graphe.GetExist())
                            {
                                std::string personne;
                                std::cout << "Entrer le nom de la personne que vous souhaiter verifier son exposition a la covid" << std::endl << std::endl;
                                std::cin >> personne;
                                graphe.NotifierExposition(personne);
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
                Automate banque_mot = Automate();
                while(quitter == false)
                {
                   
                    char choix;
                    std::wcout << "(d) Creer automate." << std::endl;
                    std::cout << "(e) Saisir mot." << std::endl;
                    std::cout << "(f) Afficher statistiques." << std::endl;
                    std::cout << "(g) Quitter" << std::endl;
                    std::cin >> choix;
                    system("CLS");
                    std::cout << std::endl;

                    switch(choix)
                    {
                        case 'd':
                        {
                            std::cout << "Entre nom du fichier du lexique"<<std::endl;
                            std::wcin >> fichier;
                            if(banque_mot.GenererLangage(fichier)==true ){
                            lexique_creer = true;
                            }

                        break;
                        }

                        case 'e':
                        {
                            if (lexique_creer) {
                                std::cout << "Tappe un mot" << std::endl << std::endl;
                                Sleep(1000);
                                banque_mot.SaisiTexte();

                            }
                            else {
                                std::cout << "Pas de lexique" << std::endl;



                            }
                           
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