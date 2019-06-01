#include <iostream>
#include <vector>

using namespace std;


#define MAX 255
#define tam_instrucao 10
#define tam_opcode 6
#define tam_total 16

class CPU{

public:
    enum {
        LOAD_MQ,
        LOAD_MQ_X,
        STOR,
        LOAD_X,
        ADD_X,
        SUB_X,
        MUL_X,
        DIV_X
    };

private:
    char MQ[tam_instrucao];
    char AC[tam_instrucao];
    char R0[tam_instrucao]; // registrador auxiliar
    char PC[tam_instrucao];
    char IR[tam_total];

    // Ainda sem saber onde usar MBR e MAR
    char MBR[tam_instrucao];
    char MAR[tam_instrucao];

    // Transfere o conteúdo do MQ para AC
    void LOADMQ(){
        transferir(AC,MQ);
    }

    // Tranfere o conteúdo da memória no endereço X para MQ
    // memoria[] é pra ser um vetor de char que será passada para
    // que seja acessada a sua posição x
    void LOADMQX(char *x[], char *memoria[]){
        //converte o endereço X para decimal
        // x_decimal = converterBinarioDecimal(x);

        // Acessa a memória na posicao X e colocar o valor
        // em um registrador auxiliar R0
        // R0 = memoria[x_decimal]

        //Transfere o conteúdo de R0 para MQ
        transferir(R0, MQ);

    }

    //Transfere o conteúdo de AC para o local X da memória
    void STORX(char *x[], char *memoria[]){

        //converte o endereço X para decimal
        // x_decimal = converterBinarioDecimal(x);

        // Acessa a memória na posicao X e colocar o valor
        // em um registrador auxiliar R0
        // R0 = memoria[x_decimal]

        transferir(R0, AC);

    }

    //Transfere conteúdo do local X da memória para AC
    void LOADX(char *x[], char *memoria[]){
        //converte o endereço X para decimal
        // x_decimal = converterBinarioDecimal(x);

        // Acessa a memória na posicao X e colocar o valor
        // em um registrador auxiliar R0
        // R0 = memoria[x_decimal]

        transferir(AC, R0);
    }

    //Soma o conteúdo da memória no endereço X
    // com AC. O resultado é gravado em AC.
    void ADDX(char *x[], char *memoria[]){
        //converte o endereço X para decimal
        // x_decimal = converterBinarioDecimal(x);

        // Acessa a memória na posicao X e colocar o valor
        // em um registrador auxiliar R0
        // R0 = memoria[x_decimal]

        //converte AC e R0 para decimal para somar
        // AC_decimal = converterBinarioDecimal(AC)
        // R0_decimal = converterBinarioDecimal(R0)
        // float soma = AC_decimal + R0_decimal

        // if(soma > 255){ erro() }
        // else { AC = converterDecimalBinario(soma)}

    }

    //Subtrai o conteúdo da memória no endereço X com AC
    // O resultado é gravado em AC
    void SUBX(char *x[], char *memoria[]){
        //converte o endereço X para decimal
        // x_decimal = converterBinarioDecimal(x);

        // Acessa a memória na posicao X e colocar o valor
        // em um registrador auxiliar R0
        // R0 = memoria[x_decimal]

        //converte AC e R0 para decimal para subtrair
        // AC_decimal = converterBinarioDecimal(AC)
        // R0_decimal = converterBinarioDecimal(R0)
        // float sub = R0_decimal - AC_decimal

        // if(soma < 0){ erro() }
        // else { AC = converterDecimalBinario(sub)}

    }


    //Multiplica o conteúdo da memória que está no endereço X por MQ.
    // Bits mais significativos em AC e menos significativos em MQ
    void MULX(char *x[], char *memoria[]){
        //converte o endereço X para decimal
        // x_decimal = converterBinarioDecimal(x);

        // Acessa a memória na posicao X e colocar o valor
        // em um registrador auxiliar R0
        // R0 = memoria[x_decimal]

        //converte MQ e R0 para decimal para subtrair
        // MQ_decimal = converterBinarioDecimal(MQ)
        // R0_decimal = converterBinarioDecimal(R0)
    }

    //Divide AC pelo conteúdo da memória no endereço X.
    // Quociente fica em MQ e o resto em AC
    void DIVX(char *x[], char *memoria[]){
        //converte o endereço X para decimal
        // x_decimal = converterBinarioDecimal(x);

        // Acessa a memória na posicao X e colocar o valor
        // em um registrador auxiliar R0
        // R0 = memoria[x_decimal]

        //converte AC e R0 para decimal para subtrair
        // AC_decimal = converterBinarioDecimal(AC)
        // R0_decimal = converterBinarioDecimal(R0)
    }


    void erro(){
        cout << "Erro!";
    }

    //transfere dado para dado1
    void transferir(char *dado1[], char *dado2[]){
        for(int i=0; i<tam_instrucao;i++){
            dado1[i] = dado2[i];
        }
    }

public:
    // Execucao() recebe como parâmetro o programa, que se refere à sequência
    // intruções que serão executadas
    void Execucao(vector<char> *programa){

        while(converteBinarioDecimal(PC) < programa.size()){

            IR = programa[converteBinarioDecimal(PC)];
            // PC++ => o valor de PC em decimal é incrementado e depois convetido para binário
            // separa a parte da instrução de IR => "instrucao = IR[7:16]"
            switch (IR) {
            case LOAD_MQ:
                LOADMQ();
                break;
            case LOAD_MQ_X:
                LOADMQX(instrucao, memoria);
                break;
            case STOR:
                STORX(instrucao, memoria);
                break;
            case LOAD_X:
                LOADX(instrucao, memoria);
                break;
            case ADD_X:
                ADDX(instrucao, memoria);
                break;
            case SUB_X:
                SUBX(instrucao, memoria);
                break;
            case MUL_X:
                MULX(instrucao, memoria);
                break;
            case DIV_X:
                DIVX(instrucao, memoria);
                break;
            default:
                erro();
                break;
            }

        }
    }

};

int main()
{

    CPU *cpu = new CPU();

    // --- Exemplo do código usado como base para a implementação ----

    //     vector<byte> inst;

    //     inst.push_back(CPU::LOAD0);
    //     inst.push_back(0);
    //     inst.push_back(CPU::LOAD1);
    //     inst.push_back(7);
    //     inst.push_back(CPU::ADD);
    //     inst.push_back(CPU::STORE0);
    //     inst.push_back(255);


    delete cpu;

    return 0;
}
