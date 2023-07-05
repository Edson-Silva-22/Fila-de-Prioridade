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
        Fixa* ultimo_P = nullptr;

    public:
        void empilhar(char preferencial, char operação){
            Fixa* newFixa = new Fixa(preferencial, operação);
            Fixa* fixaAnterior = nullptr;
            Fixa* ant_atnterior = nullptr;
            if(front == nullptr){
                //newFixa é a instancia que esta sendo criada no momento
                //o proximo e anterior dessa instancia sera null pois é a primeira instancia criada
                newFixa->proximo = nullptr;
                newFixa->anterior = nullptr;

                //front apontara para essa nova instancia que foi criada
                front = newFixa;
                instanciaAnterior = newFixa;

                if (front->preferencial == 'P')
                {
                    ultimo_P = newFixa;
                    ultimo_P->proximo = newFixa->proximo;
                    ultimo_P->anterior = newFixa->anterior;
                }
                
            }
            else{
                //fixaAnterior recebe instanciaAnterior que por sua vez apota para a ultima instancia de Fixa que foi criada
                fixaAnterior = instanciaAnterior;

                //o proximo da instancia anterior vai apota para a nova instancia que está sendo criada
                fixaAnterior->proximo = newFixa;

                //o anterior da instancia anterior vai apota para instanciaAnterior que por sua vez apota para a ultima instancia de Fixa que foi criada
                fixaAnterior->anterior = instanciaAnterior->anterior;


                newFixa->proximo = nullptr;
                newFixa->anterior = fixaAnterior;

                instanciaAnterior = newFixa;
            }

            cout << endl;
        }


         //desenfileirar
        void dequeue() {
            if (!isEmpty()) {
                Fixa* nodeToDelete = front;
                front = front->proximo;
                delete nodeToDelete;
            }
        }
        
        //checa se está vazia
        bool isEmpty(){
            return front == nullptr;
        }
        
        //imprimir elementos
        void print(){
            if (isEmpty()) {
                cout << "Priority queue is empty." << endl;
                return;
            }

            Fixa* current = front;
            while (current != nullptr) {
                cout << "Fixa Atual: " << current->preferencial << current->operação << setfill('0') << setw(3) << current->numero << endl;
                current = current->proximo;
            }
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
    filaDePrioridade.empilhar('P', 'E');
    filaDePrioridade.empilhar('N', 'D');
    filaDePrioridade.empilhar('N', 'F');
    filaDePrioridade.empilhar('P', 'D');


    filaDePrioridade.print();
    filaDePrioridade.dequeue();

    return 0;
}

/* if (newFixa->preferencial == 'P') {
                    if ( ultimo_P->proximo->preferencial == 'N' && ultimo_P->proximo->proximo->preferencial == 'N') {
                        newFixa->proximo = ultimo_P->proximo->proximo->proximo;
                        newFixa->anterior = ultimo_P->proximo->proximo;

                        ultimo_P->proximo->proximo->proximo->anterior = newFixa;
                        ultimo_P->proximo->proximo->proximo = newFixa;

                        ultimo_P = newFixa;

                        fixaAnterior->proximo = nullptr;
                        fixaAnterior->anterior = newFixa;

                        cout << "Fixa Atual: " << ultimo_P->preferencial << ultimo_P->operação << setfill('0') << setw(3) << ultimo_P->numero << endl;
                        cout << "Fixa Anterior: " << ultimo_P->anterior->preferencial << ultimo_P->anterior->operação << setfill('0') << setw(3) << ultimo_P->anterior->numero << endl;
                        
                    } 
                    else {
                        newFixa->proximo = ultimo_P->proximo;
                        newFixa->anterior = ultimo_P;

                        ultimo_P->proximo->anterior = newFixa;

                        ultimo_P = newFixa;

                        fixaAnterior->proximo = nullptr;
                        fixaAnterior->anterior = newFixa;

                        cout << "Fixa Atual: " << ultimo_P->preferencial << ultimo_P->operação << setfill('0') << setw(3) << ultimo_P->numero << endl;
                        cout << "Fixa Anterior: " << ultimo_P->anterior->preferencial << ultimo_P->anterior->operação << setfill('0') << setw(3) << ultimo_P->anterior->numero << endl;
                    }
                } 
                else {
                    newFixa->proximo = nullptr;
                    newFixa->anterior = fixaAnterior;

                    instanciaAnterior = newFixa;
                } */