#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Ficha {
    char preferencial;
    char operação;
    int numero;
    //Criando um contador para cada tipo de operação
    static int contador_E;
    static int contador_S;
    static int contador_D;
    static int contador_F;
    //ponteiro que aponta para um nova instancia do tipo Ficha que será a proxima no fila
    Ficha* proximo = nullptr;

    Ficha(char preferencial, char operação){
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

struct Painel{
        char preferencial;
        char operação;
        int numero;
};


//Iniciando contadores estáticos
int Ficha::contador_E = -1;
int Ficha::contador_S = -1;
int Ficha::contador_D = -1;
int Ficha::contador_F = -1;

class Fila {
    private:
        Ficha* front = nullptr;
        
        Ficha* ultimo_P = nullptr;
        Painel painel[5];
        int index = 0;

    public:
        void enfileirar(char preferencial, char operação){
            Ficha* newFicha = new Ficha(preferencial, operação);
            Ficha* atual = nullptr;
            if(front == nullptr){
                //newFicha é a instancia que esta sendo criada no momento
                //o proximo e anterior dessa instancia sera null pois é a primeira instancia criada
                newFicha->proximo = nullptr;
                

                //front apontara para essa nova instancia que foi criada
                front = newFicha;
                
            }

            else if (newFicha->preferencial == 'P')
            {
                atual = front;
                int contador_deN = 0; 

                while (atual->proximo != nullptr)
                {
                    
                    if (atual->preferencial == 'P')
                    {
                        contador_deN = 0;
                    }

                    else{
                        contador_deN++;
                        if(contador_deN == 2){
                            if (atual->proximo->preferencial == 'P')
                            {
                                atual = atual->proximo;
                            }
                            else{
                                newFicha->proximo = atual->proximo;
                                atual->proximo = newFicha;
                                atual = newFicha->proximo;
                                contador_deN = 0;
                            }
                        }
                    }
                    atual = atual->proximo;
                    
                }      
                
            }
            

            else{
                atual = front;

                while (atual->proximo != nullptr)
                {                   
                    atual = atual->proximo;
                }
 
                newFicha->proximo = atual->proximo;
                atual->proximo = newFicha;
                
            }
            cout << endl;

        }
        



         //desenfileirar
        void desenfileirar() {
            if (!isEmpty()) {
                painel[index].preferencial = front->preferencial;
                painel[index].operação = front->operação;
                painel[index].numero = front->numero;
                index++;

                cout << "\nFicha Atual: " << front->preferencial << front->operação << setfill('0') << setw(3) << front->numero << endl;

                Ficha* nodeToDelete = front;
                front = front->proximo;
                delete nodeToDelete;
            }
            else{
                cout << "A fila está vazia" << endl;
            }
        }
        
        //checa se está vazia
        bool isEmpty(){
            return front == nullptr;
        }

        void mostrarPainel(){
            for (int i = 0; i <= index; i++)
            {
                cout << painel[i].preferencial << painel[i].operação << setfill('0') << setw(3) << painel[i].numero << endl;
            }
            
        }
};


int main(){
    Fila filaDePrioridade;
    char inputOperação;
    char inputPreferencial;
    int menuOpção;

    while (true)
    {
        cout << "\nDigite o número da ação que deseja realizar: \n1 - Retirar Senha   2 - Chamar Senha   3 - Mostrar Panel   4 - Sair\n";
        cin >> menuOpção;

        if (menuOpção == 1)
        {
            cout << "\nDigite a letra da operação que deseja realizar: \nS - Saque   D - Deposito   F - Financiamento   E - Empréstimo\n";
            cin >> inputOperação;
            cout << "\nInforme a prioridade dessa operação: \nP - Preferencial   N - Não Preferencial\n";
            cin >> inputPreferencial;

            filaDePrioridade.enfileirar(inputPreferencial, inputOperação);
        }

        else if (menuOpção == 2)
        {
            filaDePrioridade.desenfileirar();
        }

        else if (menuOpção == 3)
        {
            filaDePrioridade.mostrarPainel();
        }

        else{
            cout << "Sair" << endl;
            break;
        }
        
        
    }

    return 0;
}