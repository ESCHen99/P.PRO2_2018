#include "Sala.hh"
using namespace std;

int sala::poner_items(string& product, int quantity){
	int afegits=0;
	for(int i=0; i<files*columnes and quantity>0; ++i){
		if(stan[i]=="NULL"){
			 stan[i]=product;
			 ++afegits;
		 }
	}
	map<string, int>* m=inv.acces_map();
	(*m)[product]+=afegits;
	n_prods+=afegits;
	return quantity-afegits;
}

int sala::quitar_items(string& product, int quantity){
	int sustrets=0;
	for(int i=int(stan.size())-1; i>=0 and quantity>0; --i){
			if(stan[i]==product){
				stan[i]="NULL";
				++sustrets;
			}
	}
	map<string, int>* m=inv.acces_map();
	if((*m)[product]==sustrets) m->erase(product);
	else (*m)[product]-=sustrets; 
	n_prods-=sustrets;
	return sustrets;
}

void sala::compactar(){
	int i_1=0, i_2=0;
	while(i_1<int(stan.size()) and int(i_2<stan.size())){
		//cout<<i_1<<' '<<i_2<<' '<<stan[i_1]<<' '<<stan[i_2]<<endl;
		if(stan[i_1]!="NULL") ++i_1;
		if(stan[i_2]=="NULL" or i_2<=i_1) ++i_2;
		if(i_2<int(stan.size()) and stan[i_2]!="NULL" and stan[i_1]=="NULL") swap(stan[i_2], stan[i_1]);
	}
}

void sala::reorganizar(){
	map<string, int>* m=inv.acces_map();
	map<string , int>::iterator it= m -> begin();
	vector<string> s(files*columnes);
	while(it!= m -> end()){
		for(int i=0; i< it -> second; ++i) s[i]=it -> first;
		++it;
	}
	stan=s;
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
	for(int i=0; i<files; ++i){
		for(int j=0; j<columnes; ++j){
			if(j!=0) cout<<' ';  //Revisar on hi han els espais però funciona.
			cout<<stan[j+i*columnes];
		}
		cout<<endl;
	}
	cout<<n_prods<<endl;
	inv.inventario();
	// Escriure QUANTITAT DE PRODS i el MAP.
}


string sala::consultar_pos(int fila ,int columna) const
{
	return stan[fila+columna];
}

bool sala::redimensionable(int fila, int columna) const
{
	return n_prods<=fila*columna;
}

bool sala::pos_valid(int fila, int columna) const
{
	return fila <= this -> files and columna <= this -> columnes;
}







