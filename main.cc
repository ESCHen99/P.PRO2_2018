/** @file main.cc
	@brief Implementació del la rutina principal o 'main'.
 */


#include "Warehouse.hh"
#include "Inventory.hh"

int main(){
    warehouse almacen;
    int n;
    cin>>n;
    almacen.specify(n);
    inventory inv;
    string a;
    cout<<"He acabat d'especificar!"<<endl;
    while(cin>>a and a!="fin"){
        int sala;
        string p;
        if(a=="poner_items"){
            cin>>sala;
            cin>>p;
            int quantity;
            cin>>quantity;
            if(quantity>=0 and inv.exists(p)){
            cout<<"poner_items "<<sala<<' '<<p<<' '<<quantity<<endl;
            almacen.poner_items(sala, p, quantity, inv);
		}
		else cout<<"error"<<endl;
        }
        else if(a == "quitar_items"){
            cin>>sala;
            cin>>p;
            int quantity;
            cin>>quantity;
            if(quantity>=0 and inv.exists(p)){
            cout<<"quitar_items "<<sala<<' '<<p<<' '<<quantity<<endl;
            almacen.quitar_items(sala, p, quantity, inv);
		}
		else cout<<"error"<<endl;		
        }
        else if(a == "poner_prod"){
            cin>>p;
            if(not inv.exists(p)){
            cout<<"poner_prod "<<p<<endl;
            inv.poner_prod(p);
		}
		else cout<<"error"<<endl;
        }
        else if(a == "quitar_prod"){
            cin>>p;
            if(inv.exists(p)){
            cout<<"quitar_prod "<<p<<endl;
            inv.quitar_prod(p);
		}
			else cout<<"error"<<endl;
        }
        else if(a == "distribuir"){
             cin>>p;
             int quantity;
             cin>>quantity;
             if(inv.exists(p) and quantity>0){
             cout<<"distribuir "<<p<<' '<<quantity<<endl;
             almacen.distribuir(p, quantity, inv);
		 }
		 else cout<<"error"<<endl;
        }
        else if(a == "compactar"){
             cin>>sala;
             if(almacen.exists(sala)){
             cout<<"compactar "<<sala<<endl;
             almacen.compactar(sala);
		 }
		 else cout<<"error"<<endl;
        }
        else if(a == "reorganizar"){
             cin>>sala;
             if(almacen.exists(sala)){
             cout<<"reorganizar "<<sala<<endl;
             almacen.reorganizar(sala);
		 }
		 else cout<<"error"<<endl;
        }
        else if(a == "redimensionar"){
             cin>>sala;
             int files, columnes;
             cin>>files>>columnes;
             if(almacen.exists(sala) and (almacen.acces_sala(sala)).redimensionable(files, columnes)){
             cout<<"redimensionar "<< sala<<' '<<files<<' '<<columnes<<endl;
             almacen.redimensionar(sala, files, columnes);
		 }
		 else cout<<"error"<<endl;
        }
        else if(a == "inventario"){
            cout<<"inventario"<<endl;
            inv.inventario();
        }
        else if(a == "escribir"){
             cin>>sala;
             if(almacen.exists(sala)){
             cout<<"escribir "<<sala<<endl;
             almacen.escribir(sala);
		 }
		 else cout<<"error"<<endl;
        }
        else if(a == "consultar_pos"){
             cin>>sala;
             int fila, columna;
             cin>>fila>>columna;
             if(almacen.exists(sala) and (almacen.acces_sala(sala)).pos_valid(fila, columna)){
             cout<<"consultar_pos "<<sala<<' '<<fila<<' '<<columna<<endl;
             cout<<almacen.consultar_pos(sala, fila, columna)<<endl;
		 }
             else cout<<"error"<<endl;
        }
        else if(a == "consultar_prod"){
            cin>>p;
            
            if(inv.exists(p)){
            cout<<"consultar_prod "<<p<<endl;
            cout<<inv.consultar_prod(p)<<endl;
		}
            else cout<<"error"<<endl;
        }
    }
    cout<<"fin"<<endl;
}
