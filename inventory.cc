#include "Inventory.hh"

typedef map<string, int>::const_iterator const_it;
typedef map<string, int>::iterator it;

void inventory::poner_prod(string& name_product){
	products.insert(pair<string, int> (name_product, 0));
}

void inventory::quitar_prod(string& name_product){
	products.erase(name_product);
}

void inventory::update_quantity(string& product, int quantity){
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
vector<string> inventory::llista(int files, int columnes) const
{
	map<string, int>::const_iterator it=products.begin();
	vector<string> s(files*columnes, "NULL");
	int i=0;
	while(it!=products.end()){
		for(int j=0; j<it->second; ++j){
			s[i]=it->first;
			++i;
		}
		++it;
	}
	return s;
}
*/
const_it inventory::const_it_begin() const
{
	return products.begin();
}

void inventory::next_const_it(const_it& iterador_const)
{
	if(iterador_const!=products.end()) ++iterador_const;
}
/*
void inventory::reset_const_it()
{
	iterador=products.begin();
}
*/
const_it inventory::const_it_end() const
{
	return products.end();
}
