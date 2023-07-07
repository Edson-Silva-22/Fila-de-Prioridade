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
        Painel ultimasFichs[5];
        int index = 0;
        int tamanho = -1;

    public:
        void enfileirar(char preferencial, char operação){
            Ficha* newFicha = new Ficha(preferencial, operação);
            Ficha* atual = nullptr;
            if(front == nullptr){
                //newFicha é a instancia que esta sendo criada no momento
                //o proximo dessa instancia sera null pois é a primeira instancia criada
                newFicha->proximo = nullptr;
                

                //front apontara para essa nova instancia que foi criada
                front = newFicha;
                
            }
            //Se a nova instancia de ficha é uma ficha preferencial
            else if (newFicha->preferencial == 'P')
            {
                atual = front;
                int contador_deN = 0; 

                //Se a primeira instancia que foi criada for preferencial o contador recebe -1 para não contabilizar essa instancia
                if (front->preferencial == 'P')
                {
                    contador_deN = -1;
                }
                
                //Enquanto o proximo de atual for diferente de nullptr esse bloco será executado
                while (atual->proximo != nullptr)
                {
                    
                    contador_deN++;
                    if(contador_deN == 2){
                        //Se uma outra ficha preferencial já estiver presente depois do intervalo de duas fichas não preferenciais
                        if (atual->proximo->preferencial == 'P')
                        {
                            //o contador recebe -1 para não contabilizar essa instancia
                            contador_deN = -1;
                        }
                        else{
                            newFicha->proximo = atual->proximo;
                            atual->proximo = newFicha;
                            atual = newFicha;
                            contador_deN = 0;
                            //Quando a nova Ficha preferencial já foi posicionada o loop é interrompido para não contabilizar todas as outras instancias que já estão na fila depois.
                            break;
                        }
                    }
                    //Atual avançara para a proxima instancia da fila.
                    atual = atual->proximo;
                    
                } 

                // quando a nova Ficha preferencial não se encaixou em nenhum intervalo de não preferenciais ela será adicionada no final da fila.
                if (atual->proximo == nullptr)
                {
                    newFicha->proximo = atual->proximo;
                    atual->proximo = newFicha;
                }
                
                     
                
            }
            
            //Se a nova instancia de ficha é uma ficha não preferencial
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

                //realocando posições da fila para que a a exibição das ultimas 5 fichas chamadas seja atualizada
                //Quando a fila já conter 5 fichas
                //posição 0 da fila vai receber o que esta na posição 1 , posição 1 da fila vai receber o que esta na posição 2, posição 2 da fila vai receber o que esta na posição 3, posição 3 da fila vai receber o que esta na posição 4 e posição 4 da fila vai receber a nova ficha que chegou 
                if (tamanho >= 4) {
                    for (int i = 0; i < 4; i++) {
                        ultimasFichs[i] = ultimasFichs[i + 1];
                    }
                    ultimasFichs[4].preferencial = front->preferencial;
                    ultimasFichs[4].operação = front->operação;
                    ultimasFichs[4].numero = front->numero;
                }
                //Adicionado as primeiras 5 fichas que foram chamadas
                else{
                    //as fichas são adicionadas de acordo com o contador index
                    ultimasFichs[index].preferencial = front->preferencial;
                    ultimasFichs[index].operação = front->operação;
                    ultimasFichs[index].numero = front->numero;
                    index++;
                    tamanho++;
                }

                cout << "\nFicha Chamada: " << front->preferencial << front->operação << setfill('0') << setw(3) << front->numero << endl;

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
             
            for (int i = 0; i <= tamanho; i++) {
                cout << ultimasFichs[i].preferencial << ultimasFichs[i].operação << setfill('0') << setw(3) << ultimasFichs[i].numero << endl;
            } 
        }

        void print() {
        {
        }
    }
};


int main(){
    Fila filaDePrioridade;
    char inputOperação;
    char inputPreferencial;
    int menuOpção;

    while (menuOpção != 4)
    {
        cout << "\n-------------------Menu-------------------\n";
        cout << "\nDigite o número da ação que deseja realizar: \n1 - Retirar Senha   2 - Chamar Senha   3 - Mostrar Panel   4 - Sair\n";
        cin >> menuOpção;
        cout << "\n------------------------------------------\n";

        if (menuOpção == 1)
        {
            cout << "\n-------------------Operação-------------------\n";
            cout << "\nDigite a letra da operação que deseja realizar: \nS - Saque   D - Deposito   F - Financiamento   E - Empréstimo\n";
            cin >> inputOperação;
            cout << "\nInforme a prioridade dessa operação: \nP - Preferencial   N - Não Preferencial\n";
            cin >> inputPreferencial;
            cout << "\n----------------------------------------------\n";

            filaDePrioridade.enfileirar(inputPreferencial, inputOperação);
        }

        else if (menuOpção == 2)
        {
            cout << "\n----------------------------------------------\n";
            filaDePrioridade.desenfileirar();
            cout << "\n----------------------------------------------\n";
        }

        else if (menuOpção == 3)
        {
            cout << "\n-------------------Ultimas Fichas Chamadas-------------------\n";
            filaDePrioridade.mostrarPainel();
            cout << "\n--------------------------------------------------------------\n";
        }   
        
    }

    return 0;
}
