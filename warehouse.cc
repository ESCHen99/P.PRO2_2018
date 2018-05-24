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
	int afegits=alm[sala].poner_items(p, quantity);
	inv.update_quantity(p, afegits);
	return quantity-afegits;
}

int warehouse::quitar_items(int sala, string& p, int quantity, inventory& inv){
	int sustrets=alm[sala].quitar_items(p, quantity);
	inv.update_quantity(p, -sustrets); //S'ha de trure elements
	return quantity-sustrets;
}

int warehouse::i_distribuir(string& p, int& quantity, inventory& inv, warehouse& w, const BinTree<int>& t){
	if(t.empty() or quantity==0) return quantity;
	else{
		quantity=w.poner_items(t.value()-1, p, quantity, inv);
		BinTree<int> esq=t.left();
		BinTree<int> dre=t.right();
			int a, b;
			b=quantity/2;
			a=quantity-b;
			return i_distribuir(p, a, inv, w, esq)+i_distribuir(p, b, inv, w, dre);
	}
}

int warehouse::distribuir(string& p, int& quantity, inventory& inv, warehouse& w){
	return i_distribuir(p, quantity, inv, w, w.index);
}

void warehouse::compactar(int sala){
	alm[sala].compactar();
}

void warehouse::redimensionar(int sala, int files, int columnes){
	alm[sala].redimensionar(files, columnes);
}

void warehouse::reorganizar(int sala){
	alm[sala].reorganizar();
}
//Consultores

void warehouse::escribir(int sala) const
{
	alm[sala].escribir();
}

string warehouse::consultar_pos(int sala, int fila, int columna) const
{
	return alm[sala].consultar_pos(fila, columna);
}

bool warehouse::exists(int sala) const
{
	return 0<=sala and sala<alm_size;
}

bool warehouse::sala_redimensionable(int sala, int files, int columnes) const
{
	return alm[sala].redimensionable(files, columnes);
}

bool warehouse::pos_valid(int sala, int fila, int columna) const
{
	return alm[sala].pos_valid(fila, columna);
}


//-D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare 
