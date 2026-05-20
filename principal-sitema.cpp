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
        getline(cin, nomes[i]); // se a pessoa tiver nome composto o getline pega a linha toda ja o cin ele separa
    }

    do
    {
        cout << "Quantiade de disciplinas ( 1 a 5 ): " << endl;
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5);

    for (int i = 0; i < qtdDisciplinas; i++)
    {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for (int j = 0; j < qtdDisciplinas; j++)
        {
            do
            {
                cout << "Disciplina " << j + 1 << "(1 a 5): ";
                cin >> notas[i][j];
            } while (notas[i][j] < 1 || notas[i][j] > 10);
            soma += notas[i][j];
        }
        media[i] = soma / qtdDisciplinas;
    }

    // SAÍDA

    cout << "\nAlunos Cadastrados: " << endl;
    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << " " << i + 1 << ". " << nomes[i] << endl;
    }

    return 0;
}