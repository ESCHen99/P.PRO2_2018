/** @file Sala.hh
    @brief Descripció de la classe sala.
 */
#ifndef _SALA_
#define _SALA_
 
//#include "Inventory.hh"
 
#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include "Inventory.hh"
#endif
using namespace std;

/** @class sala
 @brief Aquesta classe representa una sala del magatzem.
 
 Dintre de les sales hi haurà una única estanteria i la prosició relativa dels productes vindrà donada per la següent definició:
 
 Direm que un prodcute 'a' està en una posició superior a un producte 'b' si la fila d''a' és menor que la fila de 'b' i en cas d'estar a la mateixa fila direm que 'a' està en una posició superior si està en una columna menor.
 */

class sala{

private:
    int n_prods;
    vector<string> stan;
    int files, columnes;
	bool compactada;
	bool full;
	inventory inv;
public:
    //Constructores
    
     /** @brief Constructa per decfecte.
     \pre <em>true</em>
     \post S'inicialitza una sala buida.
     */
    sala(){};
    
    sala(int a, int b){
		n_prods=0;
		files=a;
		columnes=b;
		compactada=true;
		if(a*b!=0) full=false;
		stan.resize(a*b, "NULL");
	}
    //Modificadores
    
    /** @brief Posar una quantitat 'quantity' de productes.
     \pre El 'product' és un producte vàlid i la quantitat és no negativa.
     \post A la sala s'afegirà una quantitat no superior a 'quantity' en funció de l'espai buit que té.
     */
    int poner_items(string& product, int quantity);
    
    
    //Si la sala nop està compactada i té espais buits però no consecutius, llavors es col·loquen productes en aquests espais?.
    
    /** @brief Treu una quantitat 'quantity' de productes.
     \pre El 'product' és un producte vàlid i la quantitat és no negativa.
     \post Es treuran de la sala una quantitat màxima 'quantity' de productes en funció de la quantitat disponible.
     */
    int quitar_items(string& product, int quantity);
    
    /** @brief Es compactarà la sala.
     \pre <em>true</em>
     \post El magatzem serà compatada de la següent manera: Si 'a,b' són prodcutes i sense pèrdua de generalitat suposem que 'a' està en una posició superior (abans de compactar) respecte 'b', llavors el compactat manté l'ordre relatiu entre els dos productes. Si entre dos productes hi havia espai buit aquesta serà omplerta seguint la norma anterior.
     */
    void compactar();
    
    /** @brief Es reorganitzarà el magatzem.
     \pre <em>true</em>
     \post Es reordenarà l'estanteria de la sala alfabèticament i la deixarà compactada.
     */
    void reorganizar();
    
    /** @brief Es redimensionarà l'estanteria de la sala.
     \pre files*columnes haurà de ser com a mínim la de la quantitat de productes.
     \post L'estanteria tindrà dimensions 'fila' x 'columna', la regla per compactar és que si 'a' i 'b' són productes qualsevols de l'estanteria i sense pèrdua de generalitat suposem que 'a' està en una posició superior respecte 'b' llavors es conservarà aquest ordre relatiu. Redimensionar també compacta l'estanteria.
     */
    void redimensionar(int files, int columnes);
    
    //Consultores
    
    /** @brief S'ecriurà el contingut de l'estanteria de la sala.
     \pre <em>true </em>
     \post S'escriurà a el contingut de les estanteries, si hi ha un producte s'escriurà l'identificador del producte, si no hi ha cap producte s'escriurà "NULL".
     */
    void escribir() const;
    
    /** @brief S'escriurà el contingut de l'estanteria continguda dintre de la posicó que es desitja.
     \pre 'fila' i 'columna' és una posició vàlida de l'estanteria.
     \post S'escriurà, si hi ha un producte, el seu identificador i si no hi ha cap producte s'escriurà "NULL".
     */
    string consultar_pos(int fila, int columna) const;
    
    /** @brief Consultar si és redimensionable amb les noves mesures.
     \pre <em>true</em>
     \post Retornarà <em>true</em> si el paràmetre implícits pot redimensionar-se amb les noves dimensions. En cas contrari retornarà <em>false</em>
     */
    bool redimensionable(int fila, int columna) const;
    
    /** @brief Consultar si una posició de l'estanteria és vàlida.
     \pre <em>true</em>
     \post Retorna <em>true</em> si la posició és vàlida. En cas contrari retornarà <em>false</em>
     */
    bool pos_valida(int fila, int columna) const;
    

    
};
#endif
