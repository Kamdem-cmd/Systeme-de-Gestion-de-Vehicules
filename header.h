#ifndef ___HEADER_H__
#define __HEADER_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicule
{
    private:
        string _immatriculation;
        int _annee;
        double _prix;

    public:
        Vehicule()
        {
            cout << "constructeur de vehicule\n";
        }

        ~Vehicule(){
            cout << "destructeur de vehicule\n"; 
        }

        virtual void Affichier()
        {
            // Affiche infos(immatriculation, annee, prix)
        }

        string Immatriculation(){ return (this->_immatriculation);};
        int Annee(){ return (this->_annee);};
        double Prix(){ return (this->_prix);};
};

class Voiture : public Vehicule
{
    private:
        int _nbPorte;

    public:
        Voiture()
        {
            cout << "constructeur de voiture\n";
        }

        ~Voiture(){
            cout << "destructeur de voiture\n"; 
        }

};

class Moto : public Vehicule
{
    private:
        bool _estEquipeCasque;

    public:
        Moto()
        {
            cout << "constructeur de moto\n";
        }

        ~Moto(){
            cout << "destructeur de moto\n"; 
        }

};

class Camion : public Vehicule
{
    private:
        double _poidsMaxCharge;
        double _longueurRemorque;

    public:
        Camion()
        {
            cout << "constructeur de camion\n";
        }

        ~Camion(){
            cout << "destructeur de camion\n"; 
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
        void AfficherVehicules();

        ~Garage()
        {
            // Liberation de la memoire pour chaque vehicule ajouter, delete v;

        }
};

#endif