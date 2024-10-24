
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Person{
    int id_registro;
    char nombre[50];
    int cedula;
    int edad;
    float peso;
    float altura;
    char genero[2];
};

int main(){
    int p;
    cout<<"Ingrese la persona que desea leer: ";
    cin>>p;
    Person Persona;

    fstream File("personas.bin",ios::in|ios::binary);
    File.seekg(sizeof(Persona)*(p-1),ios::beg);
    File.read(reinterpret_cast<char*>(&Persona), sizeof(Persona));
    File.close();

    cout<<"ID de registro: "<<Persona.id_registro<<endl;
    cout<< "Nombre: " << Persona.nombre << endl;
    cout<< "Cedula: " << Persona.cedula << endl;
    cout<< "Edad: " << Persona.edad << endl;
    cout<< "Peso: " << Persona.peso << endl;
    cout<< "Altura: " << Persona.altura << endl;
    if(Persona.genero=="M" or Persona.genero=="m"){
        cout<<"Genero: Masculino";
    }
    else if (Persona.genero=="F" or Persona.genero=="f"){
        cout<<"Genero: Femenino";
    }
    return 0;
    File.close();
    return 0;
}