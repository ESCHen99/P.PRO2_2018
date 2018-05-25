/** @file Inventory.hh
    @brief Especificación de la classe inventory.
 */
#ifndef _INVENTORY_
#define _INVENTORY_

#ifndef NO_DIAGRAM
#include <map>
#include <iostream>
#include <vector>
using namespace std;
#endif
typedef map<string, int>::const_iterator const_it;
typedef map<string, int>::iterator it;
/**
 @class inventory
 @brief Aquesta classe representa l'inventari del magatzem.
 
 */

class inventory{
private:
    map<string, int> products;
    const_it iterador=products.begin();
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
    
    
    void inv_sala_update(string& product, int quantity);
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
	
	const_it const_it_begin() const;

	void next_const_it(const_it& iterador_const);
	
	//void reset_const_it();
	
	const_it const_it_end() const;
	
    //vector<string> llista(int files, int columnes) const;
};

#endif
