#include<cstring>
#include<iostream>
#include<fstream>
#include<conio.h>
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
    cout<<"Ingrese la cantidad de personas que desea guardar";
    cin>>p;
    Person persona[p];
    for(int i =0; i<p; i++){
        persona[i].id_registro = i+1;
        cout<<"PERSONA "<<persona[i].id_registro<<"\n";
        cout<<"Ingrese el nombre: \n"; 
        cin.ignore();
        cin.getline(persona[i].nombre,50);
        cout<<"Ingrese la cedula: \n";
        cin>>persona[i].cedula;
        cout<<"Ingrese la edad: \n"; 
        cin>>persona[i].edad;
        cout<<"Ingrese el peso: \n";
        cin>>persona[i].peso;
        cout<<"Ingrese la altura: \n";
        cin>>persona[i].altura;
        cout<<"Ingrese el genero de la persona (M o F): \n";
        cin>>persona[i].genero;
    }  
    fstream Archivo("personas.bin", ios::out|ios::binary);
    if (!Archivo.is_open()){
        cout<<"No se pudo abrir ni crear el archivo";
        return 1;
    }
    Archivo.write(reinterpret_cast<char*>(persona), sizeof(Person)*p);
    Archivo.close();
    return 0;

}