# 📚 Sistema de Notas v4.1
Sistema de gerenciamento de notas escolares desenvolvido em (C++). Permite cadastrar alunos, registrar notas por disciplina, calcular médias, classificar alunos e salvar/ler relatórios em arquivos de texto.

# ✨ Funcionalidades
* Cadastro de até (20 alunos)
* Registro de notas em até (5 disciplinas) por aluno
* Cálculo automático da média de cada aluno
* Validação de nome em branco
* Exibição da (maior) e da (menor média)
* Relatório de alunos reprovados salvo em `reprovados.txt`
* Salvamento de relatório em `relatorio.txt`
* Leitura de relatórios salvos
* Informações sobre o sistema

# 📊 Classificação por desempenho
* ✅ Aprovado     — média ≥ 7,0
* ⚠️ Recuperação  — média entre 5,0 e 6,9
* ❌ Reprovado    — média < 5,0

# 📋 Resumo Geral
O sistema exibe:

* Quantidade de aprovados
* Quantidade de alunos em recuperação
* Quantidade de reprovados
* Aluno com maior média
* Aluno com menor média

# 💻 Pré-requisitos
Compilador C++ compatível com C++11 ou superior (g++, clang++, etc.)

# 🚀 Como compilar e executar

# Compilar

bash
g++ -o sistema_notas main.cpp

# Executar

bash
./sistema_notas


No Windows, utilize:

bash
sistema_notas.exe


# 📝 Como usar
Ao iniciar o programa, será exibido o menu:

===== SISTEMA DE NOTAS v4.1 =====
1 - Novo Relatorio
2 - Ver relatorio salvo
3 - Sobre o sistema
4 - Relatorio de reprovados

# Opção 1 — Novo Relatório
* Informe a quantidade de alunos (1 a 20)
* Digite o nome de cada aluno
* Informe a quantidade de disciplinas (1 a 5)
* Digite as notas (1 a 10)
* O sistema calcula as médias automaticamente
* O relatório é exibido e salvo em arquivo

# Opção 2 — Ver relatório salvo
Exibe o conteúdo de `relatorio.txt`, caso ele exista.

# Opção 3 — Sobre o sistema
Exibe informações sobre o sistema, desenvolvedor e turma.

# Opção 4 — Relatório de reprovados
Gera o arquivo `reprovados.txt` contendo os alunos com média inferior a 5,0.

# 📁 Estrutura do projeto
.
├── main.cpp
├── relatorio.txt
├── reprovados.txt
└── README.md

# 📌 Observações
* Notas devem estar entre (1 e 10)
* Nomes em branco não são permitidos
* Nomes com espaços são aceitos
* O relatório inclui data e hora da geração
* O programa utiliza `<windows.h>`

# 🤝 Contribuindo
Contribuições são bem-vindas. Sinta-se à vontade para abrir uma issue ou enviar um pull request.

# 📄 Licença
Este projeto está sob a licença MIT.
