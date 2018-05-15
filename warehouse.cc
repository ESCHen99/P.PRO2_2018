#include "Warehouse.hh"

void BinTreeIO(BinTree<int>& T){
	int a;
	cin>>a;
	if(a!=0){
	BinTree<int> aux_left;
	BinTreeIO(aux_left);
	BinTree<int> aux_right;
	BinTreeIO(aux_right);
	T=BinTree<int> (a, aux_left, aux_right);
	}
}

void warehouse::specify(int n){
	//Entrada de la distribució del magatzem en PREORDRE.
	this -> alm_size=n;
	BinTreeIO(index);
	alm.resize(alm_size);
	int a, b;
	for(int i=0; i<alm_size; ++i){
		cin>>a>>b;
		sala s(a,b);
		alm[i]=s;
	}
}

int warehouse::poner_items(int sala, string& p, int quantity, inventory& inv){
	int resta=alm[sala-1].poner_items(p, quantity);
	inv.update_quantity(p, quantity-resta);
	return resta;
}

int warehouse::quitar_items(int sala, string& p, int quantity, inventory& inv){
	int resta=alm[sala-1].quitar_items(p, quantity);
	inv.update_quantity(p, -(quantity-resta)); //S'ha de trure elements
	return resta;
}

int warehouse::distribuir(string& p, int quantity, inventory& inv){
	
}

void warehouse::compactar(int sala){
	alm[sala-1].compactar();
}

void warehouse::redimensionar(int sala, int files, int columnes){
	alm[sala-1].redimensionar(files, columnes);
}

void warehouse::reorganizar(int sala){
	
}
//Consultores

void warehouse::escribir(int sala) const
{
	alm[sala-1].escribir();
}

string warehouse::consultar_pos(int sala, int fila, int columna) const
{
	return alm[sala-1].consultar_pos(fila, columna);
}

bool warehouse::exists(int sala) const
{
	return 0<sala-1<alm_size;
}

sala /* * */ warehouse::acces_sala(int sala)
{
	return alm[sala-1];
}





//-D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare 
