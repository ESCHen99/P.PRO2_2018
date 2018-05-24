#include "Warehouse.hh"
#include "Inventory.hh"
using namespace std;


void poner_prod(inventory& inv){
	string product;
	cin>>product;
	cout<<"poner_prod "<<product<<endl;
	if(inv.exists(product)) cout<<"  error"<<endl;
	else inv.poner_prod(product);
}

void quitar_prod(inventory& inv){
	string product;
	cin>>product;
	cout<<"quitar_prod "<<product<<endl; //producto tiene que ser cero cantidad
	if(inv.exists(product) and inv.consultar_prod(product)==0) inv.quitar_prod(product);
	else cout<<"  error"<<endl;
}

void poner_items(warehouse& a, inventory& i){
	int sala;
	string product;
	int quantity;
	cin>>sala>>product>>quantity;
	cout<<"poner_items "<<sala<<' '<<product<<' '<<quantity<<endl;	
	--sala;
	if(i.exists(product) and a.exists(sala)) cout<<"  "<<a.poner_items(sala, product, quantity, i)<<endl;
	else cout<<"  error"<<endl;
}

void quitar_items(warehouse& a, inventory& i){
	int sala;
	string product;
	int quantity;
	cin>>sala>>product>>quantity;
	cout<<"quitar_items "<<sala<<' '<<product<<' '<<quantity<<endl;	
	--sala;
	if(i.exists(product) and a.exists(sala)) cout<<"  "<<a.quitar_items(sala, product, quantity, i)<<endl;
	else cout<<"  error"<<endl;
}

void distribuir(warehouse& w, inventory& i){
	string product;
	int quantity;
	cin>>product>>quantity;
	cout<<"distribuir "<<product<<' '<<quantity<<endl;
	if(i.exists(product)){
		cout<<"  "<<warehouse::distribuir(product, quantity, i, w, *(w.acces_tree()))<<endl;
		//cout<<quantity<<endl;
	}
	else cout<<"  error"<<endl;
}

void compactar(warehouse& a){
	int sala;
	cin>>sala;
	cout<<"compactar "<<sala<<endl;
	--sala;
	if(a.exists(sala)) a.compactar(sala);
	else cout<<"  error"<<endl;
}

void reorganizar(warehouse& a){
	int sala;
	cin>>sala;
	cout<<"reorganizar "<<sala<<endl;
	--sala;
	if(a.exists(sala)) a.reorganizar(sala);
	else cout<<"  error"<<endl;
}

void redimensionar(warehouse& a){
	int sala, files, columnes;
	cin>>sala>>files>>columnes;
	cout<<"redimensionar "<<sala<<' '<<files<<' '<<columnes<<endl;
	--sala;
	if(a.exists(sala) and (*a.acces_sala2(sala)).redimensionable(files, columnes)) a.redimensionar(sala, files, columnes);
	else cout<<"  error"<<endl;
}

void inventario(const inventory& i){
	cout<<"inventario"<<endl;
	i.inventario();
}

void escribir(const warehouse& a){
	int sala;
	cin>>sala;
	cout<<"escribir "<<sala<<endl;
	--sala;
	if(a.exists(sala)) a.escribir(sala);
	else cout<<"error"<<endl;
}

void consultar_pos(warehouse& a){
	int sala, fila, columna; //const MIRAR
	cin>>sala>>fila>>columna;
	cout<<"consultar_pos "<<sala<<' '<<fila<<' '<<columna<<endl;
	--sala;
	--fila; --columna;
	if(a.exists(sala) and (*a.acces_sala2(sala)).pos_valid(fila, columna)) cout<<"  "<<a.consultar_pos(sala, fila, columna)<<endl;
	else cout<<"  error"<<endl;
}

void consultar_prod(const inventory& inv){
	string product;
	cin>>product;
	cout<<"consultar_prod "<<product<<endl;
	if(inv.exists(product)) cout<<"  "<<inv.consultar_prod(product)<<endl;
	else cout<<"  error"<<endl;
}

int main(){
	warehouse almacen;
	int n_sales;
	cin>>n_sales;
	almacen.specify(n_sales);
	inventory inv;
	
	string option;
	
	while(cin>>option and option!="fin"){
		if(option=="poner_prod") poner_prod(inv);
		else if(option=="quitar_prod") quitar_prod(inv);
		else if(option=="poner_items") poner_items(almacen, inv);
		else if(option=="quitar_items") quitar_items(almacen, inv);
		else if(option=="distribuir") distribuir(almacen, inv);
		else if(option=="compactar") compactar(almacen);
		else if(option=="reorganizar") reorganizar(almacen);
		else if(option=="redimensionar") redimensionar(almacen);
		else if(option=="inventario") inventario(inv);
		else if(option=="escribir") escribir(almacen);
		else if(option=="consultar_pos") consultar_pos(almacen);
		else if(option=="consultar_prod") consultar_prod(inv);
	}
	cout<<"fin"<<endl;
}
