/** @file Warehouse.hh
    @brief Especificació de la Classe warehouse.
*/
#ifndef _WAREHOUSE_
#define _WAREHOUSE_


#include "Sala.hh"
#include "Inventory.hh"

#ifndef NO_DIAGRAM

#include <vector>
#include <string>
#include "BinTree.hh"

#endif

using namespace std;
/** @class warehouse
    @brief Aquesta classe representa als magatzems.
*/

class warehouse{
    
private:
    BinTree<int> index;
    vector<sala> alm;
    int alm_size;
public:
    //Constructores
      /** @brief Constructora per defecte.

      Es crea un objecte de la classe warehouse buida.
      \pre <em>true</em>
      \post Es crea una 'warehouse' sense sales.
      \coste N/A
  */
    warehouse(){};
    
    /** @brief Constructora per còpia.
     
        Es crea una nova 'warehouse' idèntica a un altre.
        \pre <em>true</em>
        \post S'inicialitza una 'warehouse' idèntica a un altre.
     */
    warehouse(const warehouse& w);
    
    
    //Modificadores
    /** @brief Entrada per el canal iostream els identificadors de les sales.
        \pre <em>true</em>
        \post La warehouse tindrà la distribució de sales que s'ha entrat.
     */
    
    void specify(int n);
    
    /** @brief S'afegeix a la sala una quantitat de productes.
     \pre La sala 'sala' i el prodcute 'p' existeixen, 'quantity' és no negativa i l'inventory 'inv' existeix.
     \post Consultar el mètode homònim de la classe sala
    */
    int poner_items(int sala, string& p, int quantity, inventory& inv); 
    
    /** @brief Mètode que permet treure una quantitat de productes d'una sala.
     \pre La sala 'sala' i el prodcute 'p' existeixen, 'quantity' és no negativa i l'inventory 'inv' existeix.
     \post Consultar el mètode homònim de la classe sala
     */
    int quitar_items(int sala, string& p, int quantity, inventory& inv);
    
    /** @brief Mètode que distribueix, en tant que càpiga, un producte en sales consecutives del warehouse.
     \pre El prodcute 'p' existeix, la quantitat 'quantity' és no negativa i l'inventori 'inv' exiseix.
     \post Es col·loca sequancialement la quantitat de productes i es retorna el nombre de productes que no s'han pogut col·locar i s'actualitza l'inventari.
     */
    static int distribuir(string& p, int& quantity, inventory& inv, warehouse& w, const BinTree<int>& t);
    
    /** @brief Mètode que compacta una sala.
     \pre La sala 'sala' exiseix
     \post Consultar el mètode homònim de la classe sala
     */
    void compactar(int sala);
    
    /** @brief Reorganitza la sala desitjada.
     \pre La sala 'sala' existeix
     \post Consultar el mètode homònim de la classe sala
     */
    void reorganizar(int sala);
    
    /** @brief Redimensionar l'estanteria de la sala desitjada.
     \pre La sala 'sala' existeix (consultar a la classe sala el mètode homònim).
     \post Consultar el mètode homònim de la classe sala
     */
    void redimensionar(int sala, int files, int columnes);
    
    
    //Consultores
    
    /** @brief S'escriu els productes de la sala desitjada.
     \pre La sala 'sala' existeix.
     \post Consultar mètode homònima de la classe sala
     */
    void escribir(int sala) const;
    
    /** @brief Consulta el producte (si n'hi ha) a la posició de la fila i columna de l'estanteria de la sala desitjada.
     \pre La 'sala' existeix (consultar a la classe sala el mètode homònim).
     \post Consultar el mètode homònim de la classe sala.
     */
    string consultar_pos(int sala, int fila, int columna) const;
    
    /** @brief Consultar si una sala existeix.
     \pre <em>true</em>
     \post Si la sala 'sala' existeix retorna <em>true</em> i <em>false</em> si no existeix.
     */
    bool exists(int sala) const;
    
    /** @brief Accedir una sala.
     \pre La sala 'sala' existeix.
     \post Retorna per la sala per referència.
     */
    sala/* * */ acces_sala(int sala);
    
    sala* acces_sala2(int sala){
	return &alm[sala];
}
	BinTree<int>* acces_tree(){
		return & (this->index);
	}
};
#endif
