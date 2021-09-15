#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main (void){
    fstream arquivo;
    arquivo.open ("test.json");
    if (arquivo.is_open()){
        vector <string> conteudo;
        string teste;
        while (teste != "}"){
            arquivo >> teste;
            conteudo.push_back(teste);
        }

        vector <string> infos;
        for (string frase : conteudo){
            if(frase[0] != '{' && frase[0] != '"'){
                string palavra = frase;
                for(char letra : palavra){
                    if (letra == '[' || letra == ']'){
                        int x = palavra.find(letra);
                        palavra.erase(x,1);
                    }
                }
                /*if (palavra[0] == '['){
                    palavra.erase(0,1);
                }*/
                palavra.pop_back();
                infos.push_back(palavra);
            }
        }

        for (string num : infos){
            cout << num << endl;
        }
        arquivo.close();
    }
}