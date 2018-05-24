#include "Inventory.hh"

void inventory::poner_prod(string& name_product){
	products.insert(pair<string, int> (name_product, 0));
}

void inventory::quitar_prod(string& name_product){
	products.erase(name_product);
}

void inventory::update_quantity(string& product, int quantity){
//sempre suma perquè és enter, i.e amb signe.
	products[product]+=quantity;
}


void inventory::inv_sala_update(string& product, int quantity){
	products[product]+=quantity;
	if(products[product]==0) products.erase(product);
}


bool inventory::exists(string& product) const
{
	return products.find(product) != products.end();
}

int inventory::consultar_prod(string& p) const
{
	return products.find(p) -> second;
}

void inventory::inventario() const
{
	map<string , int>::const_iterator it=products.begin();
	while(it!=products.end()){
		cout<<"  ";
		cout<<it -> first<<' '<<it -> second<<endl;
		++it;
	}
}

/*
map<string, int>* inventory::acces_map(){
	return &products;
}
*/
