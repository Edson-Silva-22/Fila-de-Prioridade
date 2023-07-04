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

    public:
        void empilhar(char preferencial, char operação){
            Fixa* newFixa = new Fixa(preferencial, operação);
            //newFixa->print();

            if (front == nullptr || preferencial == 'N')
            {
                newFixa->proximo = front;
                newFixa->anterior = 
                front = newFixa;
            }
            else{

            }
            
        }
};


int main(){
    Fila filaDePrioridade;
    filaDePrioridade.empilhar('P', 'S');
    filaDePrioridade.empilhar('N', 'E');
    filaDePrioridade.empilhar('N', 'F');
    filaDePrioridade.empilhar('P', 'E');
    filaDePrioridade.empilhar('N', 'S');
    filaDePrioridade.empilhar('N', 'D');

    return 0;
}