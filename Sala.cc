#include "Sala.hh"
#include <map>
using namespace std;

typedef map<string, int>::const_iterator const_it;
typedef map<string, int>::iterator it;

int sala::poner_items(string& product, int quantity){
	int cont=quantity;
	for(int i=0; cont>0 and i<files*columnes; ++i){
		if(stan[i]=="NULL"){
			 stan[i]=product;
			 --cont;
		 }
	}
	int afegits=quantity-cont;
	if(afegits!=0){
	inv.inv_sala_update(product, afegits);
	n_prods+=afegits;
	}
	return afegits;
}


int sala::quitar_items(string& product, int quantity){
	int cont=quantity;
	for(int i=0; cont>0 and i<files*columnes; ++i){
		if(stan[i]==product){
				stan[i]="NULL";
				--cont;
		}
	}
	int sustrets=quantity-cont;
	inv.inv_sala_update(product, -sustrets);
	n_prods-=sustrets;
	return sustrets;
}


void sala::compactar(){
	int i_1=0, i_2=0;
	while(i_1<int(stan.size()) and int(i_2<stan.size())){
		if(stan[i_1]!="NULL") ++i_1;
		if(stan[i_2]=="NULL" or i_2<=i_1) ++i_2;
		if(i_2<int(stan.size()) and stan[i_2]!="NULL" and stan[i_1]=="NULL") swap(stan[i_2], stan[i_1]);
	}
}

/*
void sala::reorganizar(){
	inv.llista(files, columnes).swap(stan);
}
*/

void sala::reorganizar(){
	const_it iterator=inv.const_it_begin();
	vector<string> s(files*columnes, "NULL");
	int i=0;
	while(iterator!=inv.const_it_end()){
		for(int j=0; j<iterator->second; ++j){
			s[i]=iterator->first;
			++i;
		}
		inv.next_const_it(iterator);
	}
	s.swap(stan);
}

void sala::redimensionar(int files, int columnes){
	this -> compactar();
	this -> files=files;
	this -> columnes=columnes;
	stan.resize(files*columnes, "NULL");
}

//Consultores

void sala::escribir() const
{
	if(files*columnes>0){
	for(int i=files-1; i>=0; --i){
		cout<<"  ";
		for(int j=0; j<columnes; ++j){
			if(j!=0) cout<<' ';
			cout<<stan[j+i*columnes];
		}
		cout<<endl;
	}
}
	cout<<"  "<<n_prods<<endl;
	inv.inventario();
}


string sala::consultar_pos(int fila ,int columna) const
{
	fila=files-1-fila;
	return stan[fila*columnes+columna];
}

bool sala::redimensionable(int fila, int columna) const
{
	return 0<=n_prods and n_prods<=fila*columna;
}

bool sala::pos_valida(int fila, int columna) const
{
	return 0<=fila and fila < this -> files and 0<=columna and columna < this -> columnes;
}







