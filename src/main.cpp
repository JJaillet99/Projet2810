#include <iostream>
#include "grapheExposition.h"
#include "automate.h"
#include <locale>
#include <Windows.h>
int main()
{
    setlocale(LC_ALL, "fra");
    bool quitterPrincipal = false;

    
    while(quitterPrincipal == false)//boucle d'affichage du menu principale  
    {
        bool quitter = false;
        char choixPrincipal;
        system("CLS");
        //affichage des différentes options
        std::cout << "(a) Alerte COVID." << std::endl;
        std::cout << "(b) Jeu Instructif." << std::endl;
        std::cout << "(c) Quitter." << std::endl;
        std::cin >> choixPrincipal;
        system("CLS");
        std::cout << std::endl;
        // switch permenttant de choisir l'option
        switch(choixPrincipal)
        {
            case 'a':  // option d'application covid
            {
                GrapheExposition graphe= GrapheExposition ();
                while(quitter == false) // boucle d'affichage du menu de l'application covid
                {
                  
                    char choix;
                    //affichage des différentes options
                    std::cout << "(a) Creer le graphe d exposition." << std::endl;
                    std::cout << "(b) Afficher le graphe d exposition." << std::endl;
                    std::cout << "(c) Afficher notification COVID" << std::endl;
                    std::cout << "(d) Quitter." << std::endl;
                    std::cin >> choix;
                    system("CLS");
                    std::cout << std::endl;
                    // switch permenttant de choisir l'option dans l'application covid
                    switch(choix)
                    {
                        case 'a':
                        {   
                            graphe.CreerGrapheExposition("Individus.txt", "Contacts.txt"); // appel de la fonction générant le graoh
                            std::cout << std::endl << std::endl;
                        break;
                        }

                        case 'b':
                        {
                            if(graphe.GetExist()) // appel la fonction uniquement si le graph à été généré, autremenent affiche un message d'erreur
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
                            if (graphe.GetExist()) // appel la fonction uniquement si le graph à été généré, autremenent affiche un message d'erreur
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

                        case 'd': // option permettant de retourner au menu principal 
                        {
                            quitter = true; 
                        break;
                        }

                        default:
                        {
                            std::cout << "Entre invalide"<<std::endl; //message d'erreur si un autre caratère que a, b,c,d est entrée
                        break;
                        }
                    }
                }
            break;
            }
                

            case 'b': // option amenant à l'application du lexique 
            {   bool lexique_creer = false;
                std::wstring fichier;
                Automate banque_mot = Automate();
                while(quitter == false) // boucle d'affichage du menu de l'application lexique
                {
                   
                    char choix;
                    std::wcout << "(d) Creer automate." << std::endl;
                    std::cout << "(e) Saisir mot." << std::endl;
                    std::cout << "(f) Afficher statistiques." << std::endl;
                    std::cout << "(g) Quitter" << std::endl;
                    std::cin >> choix;
                    system("CLS");
                    std::cout << std::endl;
                    // switch permenttant de choisir l'option dans l'application covid
                    switch(choix)
                    {
                        case 'd': // entré du nom du fichier contenant le lexique 
                        {
                            std::cout << "Entre nom du fichier du lexique"<<std::endl;
                            std::wcin >> fichier;
                            if(banque_mot.GenererLangage(fichier)==true ){
                            lexique_creer = true;
                            }

                        break;
                        }

                        case 'e': // option permettant de taper un mot 
                        {
                            if (lexique_creer) { // si le graph à été généré appel la fonction, sinon affiche un message d'erreur
                                std::cout << "Tappe un mot" << std::endl << std::endl;
                                Sleep(1000);
                                banque_mot.SaisiTexte();

                            }
                            else {
                                std::cout << "Pas de lexique" << std::endl;



                            }
                           
                        break;
                        }
                        case 'f': // fonction affichant les statistique (le nombre de fois qu'un mot à été taper) 
                        {

                            if (lexique_creer) { // si le graph à été généré appel la fonction, sinon affiche un message d'erreur
                                banque_mot.AfficherStatistique();
                            
                            }
                            else {
                                std::cout << "Pas de lexique" << std::endl;
                            
                            
                            
                            }
                            
                        break;
                        }

                        case 'g'://option permettant de retourner au menu principal 
                        { 
                            quitter = true;
                        break;
                        }

                        default:
                        {
                            std::cout << "Entre invalide"<<std::endl;// message d'erreur si un autre caratère que d, e,f,g est entrée
                        break; 
                        }
                    }
                }
            break;
            }

            

            case 'c': // option permettant de fermer l'application 
            {
                quitterPrincipal = true;
            break;
            }

            default:
            {
                std::cout << "Entre invalide"<<std::endl; // message d'erreur si un autre caratère que a, b,c est entrée
            break;
            }
            
        }
    }
    
    

    return 0;
}