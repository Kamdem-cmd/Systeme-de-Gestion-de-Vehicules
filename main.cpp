#include "header.h"

int main()
{
    Garage monGarage;

    cout << "Systeme de gestion des vehicules\n";

    // Ajouter de nouveaux vehicules
    monGarage.AjouterVehicule(new Voiture("CE065JD", 2023, 5000, 4));
    monGarage.AjouterVehicule(new Moto("LIT005KO", 2020, 1000, true));
    
    // Afficher les differents vehicules
    monGarage.AfficherVehicules();
    return(0);
}