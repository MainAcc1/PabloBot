#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>

using namespace std;
vector<string> LeerArchivo(string frase){
    string salida;
    ifstream Leertxt("frases.txt");
    vector<string> frases;
    while(getline(Leertxt, salida)){
        frases.push_back(salida);
    }
    return frases;
}
string ElegirNumero(vector<string> frases, mt19937 &generador){
    uniform_int_distribution<> dis(0, frases.size() - 1);       // Establece el rango de generacion de numeros entre 0 y el indice del ultimo elemento del vector
    int num = dis(generador);
    string linea = frases[num];
    return linea;
}
void Mostrar(string linea){
    cout << ">> PabloBot dice: " << linea << endl;
}
int main(){
    vector<string> frases = LeerArchivo("frases.txt");
    string frase, linea;
    random_device rand;     // Genera cada vez que se ejecuta el programa una semilla aleatoria
    mt19937 generador(rand());      // Usa el generador Mersenne, rapido y de buena calidad
    cout << "¿En que puedo ayudarte hoy?" << endl;
    while(true){
        cout << ">> ";
        getline(cin, frase);
        linea = ElegirNumero(frases, generador);
        Mostrar(linea);
    }
    return 0;
}
