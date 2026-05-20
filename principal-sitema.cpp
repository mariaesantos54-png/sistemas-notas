#include <iostream>
#include <string>
using namespace std;

int main()
{

    // ENTRADA (declara as variáveis)

    string nomes[20];
    int qtdAlunos;

    // PROCESSAM4NTO

    cout << "===== SISTEMA DE NOTAS v4.0 =====" << endl;

    do
    {
        cout << "Qunatidade de alunos ( 1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore(); // se tiver coisa separada ele ignora

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "Nome do Aluno: " << i + 1 << ": ";
        getline(cin, nomes[i]); // se a pessoa tiver nome composto o getline pega a lnha toda ja o cin ele separa
    }

    // SAIDA

    cout << "\nAlunos Cadastrados: " << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << " " << i + 1 << ". " << nomes[i] << endl;
    }

    return 0;
}