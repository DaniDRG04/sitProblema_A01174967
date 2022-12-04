#include <iostream>
#include <cstring>

using namespace std;

class pyme {

protected:
    string empresa, razonSocial, direccion, director;
    int trabajadores;
    double cantidad;

public:
    pyme()
    { 
        empresa = "";
        razonSocial = "";
        direccion = "";
        director = "";
        trabajadores = 0;
        cantidad = 0;
    }

    pyme (string nombreEmpresa, string razonSocial, string direccion, string nombreDirector, int numTrabajadores, double cantidadGenerada)
    { // Constructor de la clase
        this->empresa = nombreEmpresa;
        this->razonSocial = razonSocial;
        this->direccion = direccion;
        this->director = director;
        this->trabajadores = trabajadores;
        this->cantidad = cantidad;
    }


    string getEmpresa() {
        return empresa;}
    string getrazonSocial() {
        return razonSocial;}
    string getdireccion() {
        return direccion; }
    string getDirector() {
        return director; }
    int getTrabajadores() {
        return trabajadores; }
    double getCantidad() {
        return cantidad; }

    void setempresa(string nombreEmpresa) {
        this->empresa = empresa; }
    void setrazonSocial(string razonSocial) {
        this->razonSocial = razonSocial; }
    void setdireccion(string direccion) {
        this->direccion = direccion; }
    void setdirector(string nombreDirector) {
        this->director = director; }
    void settrabajadores(int numTrabajadores) {
        this->trabajadores = trabajadores; }
    void setcantidad(double cantidadGenerada) {
        this->cantidad = cantidad; }
};

class trabajador: public pyme {

private:
    int edad;
    string nombre, puesto;
    double sueldo;

public:
    trabajador()
    { 
        nombre = "";
        edad = 0;
        puesto = "";
        sueldo = 0;
    }
    
    trabajador( string nombre, int edad, string puesto, double sueldo, string nombreEmpresa, string direccion, string razonSocial)
    {
        this->nombre = nombre;
        this->edad = edad;
        this->puesto = puesto;
        this->sueldo = sueldo;
        this->empresa = empresa;
        this->razonSocial = razonSocial;
        this->direccion = direccion;
    }

   
    int getedad(){
        return edad;
        }
    string getnombre(){ 
        return nombre;
        }
    string getpuesto(){ return puesto;
        }
    double getsueldo(){ return sueldo;
        }
    string getEmpresa(){ return empresa;
        }
    string getdireccion(){ return direccion;
        }
    string getrazonSocial(){ return razonSocial;
        }


    void setedad(int edad) {
        this->edad = edad; }
    void setnombre(string nombre) {
        this->nombre = nombre; }
    void setpuesto(string puesto) {
        this->puesto = puesto; }
    void setsueldo(double sueldo) {
        this->sueldo = sueldo; }
    void setempresa(string nombreEmpresa) {
        this->empresa = empresa; }
    void setdireccion(string direccion) {
        this->direccion = direccion; }
    void setrazonSocial(string razonSocial) {
        this->razonSocial = razonSocial; }
};

int readInt() {
    string cadena;
    getline(cin,cadena);

    return atoi(cadena.c_str());
}

double readDouble() {
    string cadena;
    getline(cin,cadena);
    return atof(cadena.c_str());
}

string readString() {
    string cadena;
    getline(cin,cadena);
    return cadena;
}

int main(){
    const int N_PYMES = 100; 
    const int N_TRABS = 100; 
    int kp = 0, kt = 0;
    pyme pymes[N_PYMES];
    trabajador trabs[N_TRABS];
    string nombre, puesto, nombreEmpresa, direccion, razonSocial, nombreDirector;
    int edad, numTrabajadores;
    double sueldo, cantidadGenerada;
    bool pyme_encontrada, trab_encontrado;
    int op = 1;
    while(op != 5){
        cout << "---------------------------------------------------" << endl;
        cout << "1. Agregar PYME" << endl;
        cout << "2. Agregar trabajador" << endl;
        cout << "3. Consultar PYME" << endl;
        cout << "4. Consultar trabajador" << endl;
        cout << "5. Cerrar" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Ingrese una opción: ";
        op = readInt();
        switch(op){
            case 1:
                cout << "Ingrese el nombre de la empresa: ";
                nombreEmpresa = readString();
                cout << "Ingrese la razón social de la empresa: ";
                razonSocial = readString();
                cout << "Ingrese la dirección de la empresa: ";
                direccion = readString();
                cout << "Ingrese el nombre del director de la empresa: ";
                nombreDirector = readString();
                cout << "Ingrese el numero de trabajadores de la empresa: ";
                numTrabajadores = readInt();
                cout << "Ingrese la cantidad de pesos que genera al año la empresa: ";
                cantidadGenerada = readDouble();
                pymes[kp].setempresa(nombreEmpresa);
                pymes[kp].setrazonSocial(razonSocial);
                pymes[kp].setdireccion(direccion);
                pymes[kp].setdirector(nombreDirector);
                pymes[kp].settrabajadores(numTrabajadores);
                pymes[kp].setcantidad(cantidadGenerada);
                kp++;
                break;
            case 2:
                cout << "Ingrese el nombre del trabajador: ";
                nombre = readString();
                cout << "Ingrese la edad del trabajador: ";
                edad = readInt();
                cout << "Ingrese el puesto del trabajador: ";
                puesto = readString();
                cout << "Ingrese el sueldo del trabajador: ";
                sueldo = readDouble();
                cout << "Ingrese el nombre de la empresa: ";
                nombreEmpresa = readString();
                cout << "Ingrese la dirección de la empresa: ";
                direccion = readString();
                cout << "Ingrese la razón social de la empresa: ";
                razonSocial = readString();
                trabs[kt].setnombre(nombre);
                trabs[kt].setedad(edad);
                trabs[kt].setpuesto(puesto);
                trabs[kt].setsueldo(sueldo);
                trabs[kt].setempresa(nombreEmpresa);
                trabs[kt].setdireccion(direccion);
                trabs[kt].setrazonSocial(razonSocial);
                kt++;
                break;
            case 3:
                cout << "Ingrese el nombre de la PYME a buscar: ";
                nombreEmpresa = readString();
                pyme_encontrada = false;
                for(int i = 0; i < kp; i++) {
                    if(nombreEmpresa == pymes[i].getEmpresa()) {
                        pyme_encontrada = true;
                        cout << "PYME encontrada." << endl;
                        cout << "Nombre: " << pymes[i].getEmpresa() << endl;
                        cout << "Razón social: " << pymes[i].getrazonSocial() << endl;
                        cout << "Dirección: " << pymes[i].getdireccion() << endl;
                        cout << "Nombre del director: " << pymes[i].getDirector() << endl;
                        cout << "Número de trabajadores: " << pymes[i].getTrabajadores() << endl;
                        cout << "Cantidad generada anual: " << pymes[i].getCantidad() << endl;
                    }
                }
                if(!pyme_encontrada) {
                    cout << "PYME no encontrada en los registros." << endl;
                }
                break;
            case 4:
                cout << "Ingrese el nombre del trabajador a buscar: ";
                nombre = readString();
                trab_encontrado = false;
                for(int i = 0; i < kt; i++) {
                    if(nombre == trabs[i].getnombre()) {
                        trab_encontrado = true;
                        cout << "Trabajador encontrado." << endl;
                        cout << "Nombre: " << trabs[i].getnombre() << endl;
                        cout << "Edad: " << trabs[i].getedad() << endl;
                        cout << "Puesto: " << trabs[i].getpuesto() << endl;
                        cout << "Sueldo: " << trabs[i].getsueldo() << endl;
                        cout << "Nombre de la empresa: " << trabs[i].getEmpresa() << endl;
                        cout << "Dirección de la empresa: " << trabs[i].getdireccion() << endl;
                        cout << "Razón social de la empresa: " << trabs[i].getrazonSocial() << endl;
                    }
                }
                if(!trab_encontrado) {
                    cout << "Trabajador no encontrado en los registros." << endl;
                }
                break;
            case 5:
                cout << "Programa finalizado" << endl;
                cout << "---------------------------------------------------" << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
        }
    }
    return 0;
}