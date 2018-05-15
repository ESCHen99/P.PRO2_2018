/** @file Inventory.hh
    @brief Especificación de la classe inventory.
 */
#ifndef _INVENTORY_
#define _INVENTORY_

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
using namespace std;
#endif

/**
 @class inventory
 @brief Aquesta classe representa l'inventari del magatzem.
 
 */

class inventory{
private:
    map<string, int> products;
public:
    //Constructoras
    
    /** @brief Constructa per decfecte.
     \pre <em>true</em>
     \post S'inicialitza un inventari buit.
     */
    
    inventory(){};
    
    //Modificadoras
    
    /** @brief Crear una entrada per un producte de codi 'product'.
     \pre El producte 'name_product' no estava registrat.
     \post El producte 'name_product' es registrarà.
     */
    void poner_prod(string& name_product);
    
    /** @brief Des-registrar un producte.
     \pre El producte 'name_product' existeix.
     \post El producte 'name_product' deixarà d'estar registrat. 
     */
    void quitar_prod(string& name_product);
    
    /** @brief Actualitza la quantitat d'un producte.
     \pre El producte 'product' existeix i la quantititat 'quantity' és la nova que hi ha al magatzem.
     \post La quantitat 'quantity' del producte 'product' serà actualitzada.
     */
    void update_quantity(string& product, int quantity);
    
    //Consultoras
    
    /** @brief Determinar si el producte 'product' està a l'inventari.
     \pre <em>true</em>
     \post Retorna 'true' si el producte existeix i 'false' si no existeix.
     */
    bool exists(string& product) const;
    
    /** @brief Consultar la quantitat de productes amb identificador 'p'.
     \pre El producte 'p' existeix.
     \post Retorna la quantitat de productes 'p'.
     */
    int consultar_prod(string& p) const;
    
     /** @brief Imprimeix l'inventari.
     \pre <em>true</em>
     \post S'imprimeix per ordre alfabètic els productes amb la quantitat que hi ha al magatzem.
     */
    void inventario() const;
	
	map<string, int>* acces_map();
};

#endif
