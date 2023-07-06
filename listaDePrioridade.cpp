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
        
        Fixa* ultimo_P = nullptr;

    public:
        void empilhar(char preferencial, char operação){
            Fixa* newFixa = new Fixa(preferencial, operação);
            //Fixa* ant_atnterior = nullptr;
            if(front == nullptr){
                //newFixa é a instancia que esta sendo criada no momento
                //o proximo e anterior dessa instancia sera null pois é a primeira instancia criada
                newFixa->proximo = nullptr;
                

                //front apontara para essa nova instancia que foi criada
                front = newFixa;

                if (front->preferencial == 'P')
                {
                    ultimo_P = newFixa;
                    ultimo_P->proximo = newFixa->proximo;
                    
                }
                
            }

            else if (newFixa->preferencial == 'P')
            {
                Fixa* atual = front;
                int contador_deN = 0;

                while (atual->proximo->preferencial == 'N')
                {
                    atual = atual->proximo;
                    contador_deN++;

                    

                    if (contador_deN == 2)
                    {
                        if (atual->proximo == )
                        {
                            /* code */
                        }
                        
                        contador_deN = 0;
                    }
                    
                }
                
                

                
                        
                    
                    
            }
            

            else{
                //fixaAnterior recebe instanciaAnterior que por sua vez apota para a ultima instancia de Fixa que foi criada
                Fixa* atual = front;

                while (atual->proximo != nullptr)
                {
                    atual = atual->proximo;
                }

                newFixa->proximo = atual->proximo;
                atual->proximo = newFixa;

                
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
    filaDePrioridade.empilhar('N', 'S');
    filaDePrioridade.empilhar('N', 'E');
    filaDePrioridade.empilhar('N', 'F');
    filaDePrioridade.empilhar('N', 'S');
    filaDePrioridade.empilhar('N', 'E');
    filaDePrioridade.empilhar('N', 'D');
    filaDePrioridade.empilhar('N', 'E');
    filaDePrioridade.empilhar('N', 'D');
    filaDePrioridade.empilhar('N', 'F');
    filaDePrioridade.empilhar('P', 'D');


    filaDePrioridade.print();
    filaDePrioridade.dequeue();

    return 0;
}