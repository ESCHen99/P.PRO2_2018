#include "Warehouse.hh"
#include "Inventory.hh"
#include "Sala.hh"
using namespace std;


int main(){
	inventory inv;
	warehouse almacen;
    int n;
    cin>>n;
    almacen.specify(n);
	cout<<"He acabat d'inicialitzar"<<endl;
	int sala;
	string product;
	int quantity;
	cin>>sala>>product>>quantity;

	almacen.acces_sala2(sala) -> fila_columna();
	
	cout<<almacen.acces_sala2(sala) -> poner_items(product, quantity)<<endl;

	
	//cout<<almacen.poner_items(sala, product, quantity, inv)<<endl;
	
	
	//almacen.escribir(sala);
	
	almacen.acces_sala2(sala)->escribir();
	/*
	cin>>sala>>product>>quantity;
	cout<<almacen.quitar_items(sala, product, quantity, inv)<<endl;
	almacen.escribir(sala);
	*/
}
