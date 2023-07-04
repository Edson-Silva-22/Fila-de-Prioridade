#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Fixa {
    char preferencial;
    char operação;
    int numero;
    //Criando um contador para cada tipo de operação
    static int contador_E;
    static int contador_S;
    static int contador_D;
    static int contador_F;
    //ponteiro que aponta para um nova instancia do tipo Fixa que será a proxima no fila
    Fixa* proximo = nullptr;
    Fixa* anterior = nullptr;

    Fixa(char preferencial, char operação){
        this->preferencial = preferencial;
        this->operação = operação;

        //Separando um contador para cada operação bancária
        if (this->operação == 'E')
        {
            this->contador_E++;
            this->numero = this->contador_E;
        }

        if (this->operação == 'S')
        {
            this->contador_S++;
            this->numero = this->contador_S;
        }

        if (this->operação == 'D')
        {
            this->contador_D++;
            this->numero = this->contador_D;
        }

        if (this->operação == 'F')
        {
            this->contador_F++;
            this->numero = this->contador_F;
        }
        
    }

    void print(){
        cout << this->preferencial << this->operação << setfill('0') << setw(3) << this->numero << endl;
    }
};

//Iniciando contadores estáticos
int Fixa::contador_E = -1;
int Fixa::contador_S = -1;
int Fixa::contador_D = -1;
int Fixa::contador_F = -1;

class Fila {
    private:
        Fixa* front = nullptr;
        Fixa* instanciaAnterior = nullptr;

    public:
        void empilhar(char preferencial, char operação){
            Fixa* newFixa = new Fixa(preferencial, operação);
            Fixa* fixaAnterior = nullptr;
            if(front == nullptr){
                //newFixa é a instancia que esta sendo criada no momento
                //o proximo e anterior dessa instancia sera null pois é a primeira instancia criada
                newFixa->proximo = nullptr;
                newFixa->anterior = nullptr;

                //front apontara para essa nova instancia que foi criada
                front = newFixa;
                instanciaAnterior = newFixa;
            }
            else{
                //fixaAnterior recebe front que por sua vez apota para a ultima instancia de Fixa que foi criada
                fixaAnterior = instanciaAnterior;

                //o proximo da instancia anterior vai apota para a nova instancia que está sendo criada
                fixaAnterior->proximo = newFixa;

                //o anterior da instancia anterior vai apota para instanciaAnterior que por sua vez apota para a ultima instancia de Fixa que foi criada
                fixaAnterior->anterior = instanciaAnterior->anterior;

                //o proximo da instancia que esta sendo criada no momento vai apota para nullptr pois ela sempre será a ultima instancia de Fixa criada
                newFixa->proximo = nullptr;

                //o anterior da instancia que esta sendo criada no momento vai apontar para a instancia anterior que no caso é fixaAnterior
                newFixa->anterior = fixaAnterior;


                instanciaAnterior = newFixa;
                
                cout << "Fixa Atual: " << fixaAnterior->preferencial << fixaAnterior->operação << setfill('0') << setw(3) << fixaAnterior->numero;

                cout << " Proximo: " << fixaAnterior->proximo->preferencial << fixaAnterior->proximo->operação << setfill('0') << setw(3) << fixaAnterior->proximo->numero << " " << "Anterior: " << fixaAnterior->anterior << " ";

                cout << "Front: " << front->preferencial << front->operação << setfill('0') << setw(3) << front->numero << " ";
            }

            cout << endl;
        }
};


int main(){
    Fila filaDePrioridade;
    filaDePrioridade.empilhar('P', 'S');
    filaDePrioridade.empilhar('N', 'E');
    filaDePrioridade.empilhar('N', 'F');
    filaDePrioridade.empilhar('N', 'S');
    filaDePrioridade.empilhar('P', 'E');
    filaDePrioridade.empilhar('N', 'D');

    return 0;
}