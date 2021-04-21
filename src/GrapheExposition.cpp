#include "grapheExposition.h"

GrapheExposition::GrapheExposition(){}

bool GrapheExposition::GetExist() const
{
    return graphe_existe_;
}

void GrapheExposition::CreerGrapheExposition(std::string individu, std::string contact)
{
if(!graphe_existe_)
{
    //enregistres les informations relative l'infection des individues au covid-19
    std::ifstream fichier1 (individu);// ouverture du fichier
    if (fichier1.is_open()) // vérification que le fichier est bien ouvert
    {
        std::string nom;
        std::string covid;
        int index = 0;
        while(std::getline(fichier1, nom, ','))// verifie qu'il existe encore une ligne non vide 
        { 
            
            std::getline(fichier1,covid); // accede à la prochaine ligne
            int statut = std::stoi(covid);
            if (statut == 0) {
              Individu nouveau(index, nom, false); // ajout de l'individue n'ayant pas le covid
              population_.push_back(nouveau);
            }
            else {
              Individu nouveau(index, nom, true);  // ajout de l'individue ayant le covid
              population_.push_back(nouveau);
            }
            index++;
        }
        fichier1.close();
    }

    //enregistres les informations relative au contact des individues entre eux du fichier txt
    std::ifstream fichier2 (contact);
    if (fichier2.is_open()) // vérification que le fichier est bien ouvert
    {
        std::string nom_individu;
        std::string nom_voisin;
        std::string distance_string;
        Individu individu;
        Individu voisin;
        while(std::getline(fichier2, nom_individu, ' '))// verifie qu'il existe encore une ligne non vide 
        {
            std::getline(fichier2, distance_string, ' ');
            std::getline(fichier2,nom_voisin);
            if(nom_voisin.back() == '\r') //correction des caractères de retour à la ligne parfois présente à la fin de certaine ligne
            {
                nom_voisin.pop_back();
            }
            while(nom_voisin.back() == ' ')  //correction des caractères d'espace parfois présente à la fin de certaine ligne
            {
                nom_voisin.pop_back();
            }
            
            float distance = std::stof(distance_string);
            int indexIndividu = GetIndexParNom(nom_individu); //création de l'index de l'individue
            int indexVoisin = GetIndexParNom(nom_voisin); //création de l'index de ces voisins
            population_[indexIndividu].AddVoisin(indexVoisin, distance); //ajout des voisins à l'individue afin de pouvoir facilement connaitre les contacts
            population_[indexVoisin].AddVoisin(indexIndividu, distance); //ajout des individue au voisin afin de pouvoir facilement connaitre les contacts
        }

        fichier2.close();
    }
    graphe_existe_ = true;
    std::cout << "Le graphe a ete genere";
}
else
{
    std::cout << "Le graphe est deja genere";
}

}

//cette fonction retourne l'index associé à l'indivie en fonction de son nom
//retourne -1 si aucun indivue portant ce nom n'est trouvé
size_t GrapheExposition::GetIndexParNom(std::string nom) 
{
    for(size_t i = 0; i < population_.size(); i++)
    {
        if (population_[i].GetNom() == nom)
        {
            return i;
        }
    }
    return -1; 
}
//cette fonction affiche l'ensemble des voisins ainsi que la distance entre l'individue et son voisin
void GrapheExposition::AfficherGrapheExposition()
{
    for(Individu individu : population_)
    {
        for(std::pair<int , float> voisDist : individu.GetVoisins())
        {
            std::cout << "(" << individu.GetNom() << " "; //affiche le nom de l'individue
            std::cout << population_[voisDist.first].GetNom() << " "; //affiche le nom du voisin
            std::cout << "(" << voisDist.second << "))" << std::endl; // affiche la distance les séparents
        }
    }
    std::cout << std::endl;
}
// fonction permettant de déterminer si la distance entre 2 individu
//indiquant ainsi si l'individue à été exposé au covid ou non. 
bool GrapheExposition::IdentifierExposition(std::string x, std::string y)
{
    std::set<std::pair<float, int>> ensemble; //ensemble des distance non minimal connue entre x et tous point du graphe
    std::map<int, float> distance; //ensemble des chemins "final" minimal entre x et tout autre points du graph
    int indexX;
    for (int i = 0; i<population_.size(); i++) // passe au travers de l'ensemble de la population
    {
        distance[population_[i].GetIndex()] = 10000; // remplis 
        if(population_[i].GetNom() == x) 
        {
            distance[population_[i].GetIndex()] = 0; // fixe la distance entre x et x à 0. 
            indexX = i;
        }
    }
    ensemble.insert(std::make_pair(0, indexX)); //ajoute la distance de x à x qui est la seule distance connue. 
    
    
    while(!ensemble.empty()) //tant qu'il y ait des voisins non explorer sur le graph on continue d'itérer 
    {
        int individu = ensemble.begin()->second; //individu non-fixé ce trouvant le moin loin du point initial
        if(population_[individu].GetNom() == y) 
        {
            if(population_[individu].GetCovid() == true && distance[individu] < 2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        ensemble.erase(ensemble.begin()); //enlève l'individu non-fixé ce trouvant le moin loin du point initial
        

        for(std::pair<int, float> voisin : population_[individu].GetVoisins()) //regarde l'ensemble des voisins de l'individe venant d'etre retirer de l'ensemble
        {
            if(voisin.second < 2) // si la distance est plus de 2 mètres, pas besoin de calculer car il n'y aura jamais d'exposition
            {
                if(distance[voisin.first] > distance[individu] + voisin.second) //si la distance vers ce points est plus petite, la remplace dans les chemins "fixé" 
                {
                    if(distance[voisin.first] != 10000) // si la distance à ce voisin à déjà été initialisé par une valeur présente dans le graph
                    {
                        ensemble.erase(ensemble.find(std::make_pair(distance[voisin.first], voisin.first))); //retire ce chemin de l'ensemble
                    }
                    distance[voisin.first] = distance[individu] + voisin.second;  //ajoute la distanche au chemin "fixé" 
                    ensemble.insert(std::make_pair(distance[voisin.first], voisin.first)); // ajoute le chemin vers le voisin du node si la distance entre x et ce voisin est plus petite que ce que nous avons déjà trouver
                    
                }
            }
        }
    }
    return false;
}
// fonction permettant d'afficher l'exposition d'un individue dans l'application.
void GrapheExposition::NotifierExposition(std::string individu) {

    int index=GetIndexParNom(individu); // on trouve l'index relié a cete personne
    //en cas qu'il n'y ait aucun individu portant ce nom et donc qu'index =-1, on affiche un message en conséquence 
    if (index == -1) {
        std::cout << "Aucunes donnes sur cette personne" << std::endl << std::endl;
        return;
    }
    for (size_t i = 0; i < population_.size(); i++) // on passe au travers de l'ensemble de la population 
    {  

        if (i==index){
    //int i = index;
            if (population_[i].GetCovid()) {// si l'individu à la covid on peux directement afficher le message
                std::cout << individu << ", vous avez ete expose au cours des 14 derniers jours" << std::endl << std::endl;
                return;
            }

        }
        else {
            if (IdentifierExposition(individu, population_[i].GetNom())) {//appel la fonction vérifiant l'exposition entre 2 individu, en appelant cette fonction sur tous les individus on 
                //peux donc déterminer l'exposition 
                std::cout << individu << ", vous avez ete expose au cours des 14 derniers jours" << std::endl << std::endl;
                return;
            }
        }

    }
    std::cout << "Aucune exposition detecte" << std::endl << std::endl; //si il n'est pas exposé ou n'a pas la covid, affiche ce message 

}
