#include<iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <random>

using namespace std; 

vector<string> arrayModalidade( string txt );
int numRandom(int min, int max);

int main() {

    string escolha; 
    vector<string> palavras;
    int min = 0;
    int max;

    cout << "Escolha a modalidade que dejesa jogar: Futebol/Filmes/Carros" << endl; 
    cin >> escolha; 

    for ( char& c : escolha ) {
        c = tolower(c);
    }

    escolha = escolha + ".txt";
  
    palavras = arrayModalidade( escolha );
    max = palavras.size( );

    int random = numRandom( min, max );

    cout << random;

    return 0;
}



 vector<string> arrayModalidade( string txt ){

    ifstream arquivo( txt );
    string linha;
    vector<string> palavras;
    

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
    }

    while ( getline( arquivo, linha ) ) {
        palavras.push_back(linha);
    }
       
    arquivo.close();

    return palavras;
 }

 int numRandom(int min, int max) {
    
    random_device rd;
    
    
    mt19937 gen(rd());
    
    
    uniform_int_distribution<int> dis(min, max);
    
    
    return dis(gen);
}
