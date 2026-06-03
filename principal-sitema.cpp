#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{

    // ENTRADA (declara as variáveis)

    string nomes[20];
    int qtdAlunos;
    float notas[20][5];
    float media[20];
    int qtdDisciplinas;
    int opcaoInicial;

    // PROCESSAM4NTO
    // leitura de alunos( Comit 1)
    do
    {
        cout << "===== SISTEMA DE NOTAS v4.0 =====" << endl;
        cout << "1 - Novo Relatorio" << endl;
        cout << "2 - Ver relatorio salvo" << endl;
        cout << "3 - Sobre o sistema" << endl;
        cout << "Escolha uma opacao: " << endl;
        cin >> opcaoInicial;

        // LEITURA DE ARQUIVO (COMIT 5)
        if (opcaoInicial == 2)
        {
            ifstream leitura("Relatorio.txt");
            if (leitura.is_open())
            {
                string linha;
                cout << "\n";
                while (getline(leitura, linha))
                {
                    cout << linha << endl;
                }
                leitura.close();
            }
            else
            {
                cout << "Nenhum relatorio encontrado." << endl;
            }
        }

        if (opcaoInicial == 3)
        {
            cout << "\n=== SOBRE O SISTEMA ===" << endl;
            cout << "Sistemas de notas v4.0" << endl;
            cout << "Desenvolvido por: Maria Eduarda Pereira Dos Santos" << endl;
            cout << " Turma: LOPAL 2026 - SEANAI-SP3" << endl;
            cout << endl;
        }

    } while (opcaoInicial != 1);

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

    // notas e medias (comit 2)
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

    // classificaçãoe relatori (comit 3)
    cout << "\n======Relatorio ========" << endl;
    int aprovados = 0, recuperaçao = 0, reprovados = 0;

    for (int i = 0; i < qtdDisciplinas; i++)
    {
        cout << nomes[i] << " - Media: " << media[i] << " - ";
        if (media[i] >= 7)
        {
            cout << "Aprovado" << endl;
            aprovados++;
        }
        else if (media[i] >= 5)
        {
            cout << "Recuperaçao: " << endl;
            recuperaçao++;
        }
        else
        {
            cout << "Reprovado" << endl;
            reprovados++;
        }
    }

    cout << "\nResumo: " << aprovados << "Aprovados, " << recuperaçao << "Recuperaçao, " << reprovados << "Reprovados, " << endl;

    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open())
    {
        // Dentro da parte que salva o arquivo:
        time_t agora = time(0);
        char *dataHora = ctime(&agora);
        arquivo << "Data do relatorio: " << dataHora << endl;
       
        arquivo << "====RELATORIO====" << endl;
        for (int i = 0; i < qtdAlunos; i++)
        {
            arquivo << nomes[i] << " - Média: " << media[i] << " - ";
            if (media[i] >= 7)
            {
                arquivo << "Aprovado" << endl;
            }
            else if (media[i] >= 5)
            {
                arquivo << "Recuperaçao" << endl;
            }
            else
            {
                arquivo << "Reprovado" << endl;
            }
        }
        arquivo << "\nResumo: " << aprovados << "aprovados, " << recuperaçao << "em recuperaçao" << reprovados << "reporvados" << endl;

        arquivo.close();
        cout << "\nRelatório sem em relatorio.txt" << endl;
    }
    else
    {
        cout << "Erro ao criar arquivo. " << endl;
    }
    return 0;
}