#ifndef ___HEADER_H__
#define __HEADER_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicule
{
    private:
        string _type;
        string _immatriculation;
        int _annee;
        double _prix;

    public:
        Vehicule()
        {
            cout << "constructeur de vehicule\n";
        }

        Vehicule(string imma, int annee, double prix)
        {
            this->_immatriculation = imma;
            this->_annee = annee;
            this->_prix = prix;
        }

        Vehicule(string imma, int annee, double prix, string type)
        {
            this->_immatriculation = imma;
            this->_annee = annee;
            this->_prix = prix;
            _type = type;
        }

        ~Vehicule(){
            cout << "destructeur de vehicule\n"; 
        }

        // Affiche infos(immatriculation, annee, prix)
        virtual void Afficher()
        {  
            cout << "Immatriculation: " << Immatriculation() << "\n";
            cout << "Annee de fabrication: " << Annee() << "\n";
            cout << "Prix: " << Prix() << "FCFA\n";
            cout << "Type: " << Type() << "\n";
        }

        virtual string Type(){ return(this->_type);}
        string Immatriculation(){ return (this->_immatriculation);};
        int Annee(){ return (this->_annee);};
        double Prix(){ return (this->_prix);};
};

class Voiture : public Vehicule
{
    private:
        int _nbPorte;

    public:
        Voiture():Vehicule()
        {
            cout << "constructeur de voiture\n";
        }

        Voiture(string imma, int annee, double prix, int nbPorte): Vehicule(imma, annee, prix, Type()){
            this->_nbPorte = nbPorte;
        }

        ~Voiture(){
            cout << "destructeur de voiture\n"; 
        }

        string Type(){ return("Voiture");}

        void Afficher()
        {
            Vehicule::Afficher();
            cout << "Nombre de portes: " << nbPorte() << "\n";
            
        }

        int nbPorte()
        {
            return (this->_nbPorte);
        }
};

class Moto : public Vehicule
{
    private:
        bool _estEquipeCasque;

    public:
        Moto():Vehicule()
        {
            cout << "constructeur de moto\n";
        }

        Moto(string imma, int annee, double prix, bool casque): Vehicule(imma, annee, prix, Type()){
            this->_estEquipeCasque = casque;
        }

        ~Moto(){
            cout << "destructeur de moto\n"; 
        }

        void Afficher()
        {
            Vehicule::Afficher();

            (estEquipeCasque() == true) ? cout << "possede un casque: Oui\n" : cout << "possede un casque: Non\n";  
        }

        string Type(){ return("Moto");}

        bool estEquipeCasque()
        {
            return (this->_estEquipeCasque);
        }

};

class Camion : public Vehicule
{
    private:
        double _poidsMaxCharge;
        double _longueurRemorque;

    public:
        Camion():Vehicule()
        {
            cout << "constructeur de camion\n";
        }

        Camion(string imma, int annee, double prix, double chargeMax, double longueurRemorque): Vehicule(imma, annee, prix, Type())
        {
            this->_poidsMaxCharge = chargeMax;
            this->_longueurRemorque = longueurRemorque;
        }

        ~Camion(){
            cout << "destructeur de camion\n"; 
        }

        void Afficher()
        {
            Vehicule::Afficher();
            cout << "Charge Maximale: " << poidsMaxCharge() << "\n";
            cout << "Longueur de la remorque: " << longueurRemorque() << "\n";

        }

        string Type(){ return("Camion");}

        double poidsMaxCharge(){
            return (_poidsMaxCharge);
        }

        double longueurRemorque(){
            return (_longueurRemorque);
        }

};

class Garage
{
    private:
        // tableau de vehicules
        vector<Vehicule*> vehicules;

    public:
        void AjouterVehicule(Vehicule* v)
        {
            vehicules.push_back(v);
        }

        // Affiche les details du vehicule et le coût annuel d'entretien
        void AfficherVehicules()
        {
            for(size_t i = 0; i < sizeof(vehicules); i++)
            {
                vehicules[i]->Afficher();
                cout << "_____________________________________\n";
            }
        }

        ~Garage()
        {
            // Liberation de la memoire pour chaque vehicule ajouter, delete v;
            for(size_t i = 0; i < sizeof(vehicules); i++)
            {
                delete vehicules[i];
                vehicules[i] = nullptr;
            }

        }
};

#endif