#include <iostream>

int main()
{
    bool quitter = false;

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
                std::cout << "Création graphe." << std::endl << std::endl;
                break;

            case 'b':
                std::cout << "Affichage graphe." << std::endl << std::endl;
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