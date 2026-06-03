#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <ctime>
using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    // ENTRADA (declara as variáveis)
    string nomes[20];
    int qtdAlunos = 0; 
    float media[20] = {0}; 
    int qtdDisciplinas;
    int opcaoInicial;
    float notas[20][5];

    // PROCESSAMENTO
    // leitura de alunos( Comit 1)
    do
    {
        cout << "===== SISTEMA DE NOTAS v4.1 =====" << endl;
        cout << "1 - Novo Relatorio" << endl;
        cout << "2 - Ver relatorio salvo" << endl;
        cout << "3 - Sobre o sistema" << endl;
        cout << "4 - Relatorio de reprovados" << endl; // --- SEÇÃO MODIFICADA (OPCIONAL C) ---
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
            cout << "Desenvolvido por: Isa Ferreira da Silva" << endl;
            cout << " Turma: LOPAL 2026 - SENAI-SP" << endl;
            cout << endl;
        }

        // --- SEÇÃO MODIFICADA: LOGICA DA OPÇÃO 4 (OPCIONAL C) ---
        if (opcaoInicial == 4)
        {
            ofstream arqReprovados("reprovados.txt");
            if (arqReprovados.is_open())
            {
                arqReprovados << "==== RELATÓRIO DE REPROVADOS ====" << endl;
                int contReprovados = 0;

                for (int i = 0; i < qtdAlunos; i++)
                {
                    if (media[i] < 5 && nomes[i] != "")
                    {
                        arqReprovados << "Aluno: " << nomes[i] << " - Média: " << media[i] << endl;
                        contReprovados++;
                    }
                }
                
                if (contReprovados == 0)
                {
                    arqReprovados << "Nenhum aluno reprovado cadastrado nesta sessão." << endl;
                }

                arqReprovados.close();
                cout << "\nArquivo 'reprovados.txt' gerado com sucesso!" << endl;
            }
            else
            {
                cout << "Erro ao criar o arquivo de reprovados." << endl;
            }
        }

    } while (opcaoInicial != 1);

    do
    {
        cout << "Quantidade de alunos ( 1 a 20): ";
        cin >> qtdAlunos;
    } while (qtdAlunos < 1 || qtdAlunos > 20);

    cin.ignore(); 

    //Nome em branco
    for (int i = 0; i < qtdAlunos; i++)
    {
        do 
        {
            cout << "Nome do Aluno " << i + 1 << ": ";
            getline(cin, nomes[i]);

            if (nomes[i] == "") 
            {
                cout << "Erro: O nome nao pode ser vazio! Tente novamente.\n";
            }
        } while (nomes[i] == ""); 
    }

    // notas e medias (comit 2)
    do
    {
        cout << "Quantidade de disciplinas ( 1 a 5): " << endl; // Ajustado de acordo com o limite do vetor notas[20][5]
        cin >> qtdDisciplinas;
    } while (qtdDisciplinas < 1 || qtdDisciplinas > 5); 

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << "\nNotas de " << nomes[i] << ":" << endl;
        float soma = 0;
        for (int j = 0; j < qtdDisciplinas; j++)
        {
            do
            {
                cout << "Disciplina " << j + 1 << " (1 a 10): ";
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

    // classificação e relatorio (comit 3)
    cout << "\n====== Relatorio ========" << endl;
    int aprovados = 0, recuperacao = 0, reprovados = 0;

    int indiceMaior = 0;
    int indiceMenor = 0;

    for (int i = 0; i < qtdAlunos; i++)
    {
        cout << nomes[i] << " - Media: " << media[i] << " - ";
        if (media[i] >= 7)
        {
            cout << "Aprovado" << endl;
            aprovados++;
        }
        else if (media[i] >= 5)
        {
            cout << "Recuperaçao" << endl;
            recuperacao++;
        }
        else
        {
            cout << "Reprovado" << endl;
            reprovados++;
        }

        // --- CORREÇÃO DE SINTAXE DAS CHAVES (MAIOR/MENOR) ---
        if (media[i] > media[indiceMaior])
        {
            indiceMaior = i; 
        }
        if (media[i] < media[indiceMenor])
        {
            indiceMenor = i; 
        }
    }

    // Exibe o resumo na tela
    cout << "\nResumo: " << aprovados << " Aprovados, " << recuperacao << " Recuperação, " << reprovados << " Reprovados" << endl;

    cout << "Maior media: " << nomes[indiceMaior] << " (" << media[indiceMaior] << ")" << endl;
    cout << "Menor media: " << nomes[indiceMenor] << " (" << media[indiceMenor] << ")" << endl;
    
    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open())
    {
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
        arquivo << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperacao, " << reprovados << " reprovados" << endl;
        arquivo << "Maior media: " << nomes[indiceMaior] << " (" << media[indiceMaior] << ")" << endl;
        arquivo << "Menor media: " << nomes[indiceMenor] << " (" << media[indiceMenor] << ")" << endl;

        arquivo.close();
        cout << "\nRelatório salvo em relatorio.txt" << endl;
    }
    else
    {
        cout << "Erro ao criar arquivo. " << endl;
    }
    return 0;
}
