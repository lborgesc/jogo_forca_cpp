#include<iostream>
#include <fstream>
#include <locale>
#include <vector>
#include <ctime>  
#include <random>

using namespace std; 

vector<string> arrayModalidade( string txt );
int numRandom( int min, int max );

int main( ) {

    
    string escolha, forca; 
    vector< string > palavras;
    int min = 0, max, loop;

    cout << "Escolha a modalidade que dejesa jogar: Futebol/Filmes/Carros" << endl; 
    cin >> escolha; 

    for ( char& c : escolha ) {
        c = tolower( c );
    }

    escolha = escolha + ".txt";
  
    palavras = arrayModalidade( escolha );
    max = ( sizeof( palavras ) / sizeof( int ) );

    srand( time( NULL ) );
    int random = ( min + rand( ) % max );

    forca = palavras[ random ];

    loop = round( forca.length( ) / 2 );

    int arrayForca[ loop ];
    
    for ( int i = 0; i < loop; i++ ){
        srand( time( NULL ) * i );
        cout << forca << endl; 
        cout << forca[ min + rand( ) % random ] << endl;        
        arrayForca[ i ] = forca[ min + rand( ) % random ];

    }

    cout << "array: " << arrayForca[ 0 ];

    return 0;
}





 vector< string > arrayModalidade( string txt ){

    ifstream arquivo( txt );
    string linha;
    vector< string > palavras;
    

    if ( !arquivo.is_open( ) ) {
        cerr << "Erro ao abrir o arquivo." << endl;
    }

    while ( getline( arquivo, linha ) ) {
        palavras.push_back( linha );
    }
       
    arquivo.close( );

    return palavras;
 }



