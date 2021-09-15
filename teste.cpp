#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class transforma_json {
public:
    vector <string> conteudo;
    vector <string> infos;
    vector <float> dados;
    fstream arquivo;

transforma_json(string nome_arquivo){
    arquivo.open (nome_arquivo);
}
~transforma_json(){
    arquivo.close();
}
public:
    void filtro(){
        string cont_json;
        while (cont_json != "}"){
            arquivo >> cont_json;
            conteudo.push_back(cont_json);
        }

        for (string frase : conteudo){
            if(frase[0] != '{' && frase[0] != '}' && frase[0] != '"'){
                string palavra = frase;
                for(char letra : palavra){
                    if (letra == '[' || letra == ']'){
                        int x = palavra.find(letra);
                        palavra.erase(x,1);
                    }
                }
                if (frase.back() == ','){
                    palavra.pop_back();
                }
                infos.push_back(palavra);
            }
        }

        int i = 0;
        for (string num_string : infos){
            float dado = stof(num_string);
            dados.push_back(dado);
            i++;
        }
    }
    void envia_dados() {
        int i = 0;
        for (float dado : dados){
            cout << dado << ',';
            i++;
        }
        cout << i*sizeof(float) << endl;
    }
};

int main (void){
    transforma_json test("test.json");
    test.filtro();
    test.envia_dados();
}