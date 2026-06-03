# Sistema de Notas v4.1
Sistema de gerenciamento de notas escolares desenvolvido em C++. Permite cadastrar alunos, registrar notas por disciplina, calcular médias, classificar alunos e salvar/ler relatórios em arquivo de texto.

# Funcionalidades
Cadastro de até 20 alunos com nome completo
Registro de notas em até 5 disciplinas por aluno
Cálculo automático da média de cada aluno

# Classificação por desempenho:
✅ Aprovado — média ≥ 7,0
⚠️ Recuperação — média entre 5,0 e 6,9
❌ Reprovado — média < 5,0

# Resumo geral com contagem de aprovados, em recuperação e reprovados
Salvar relatório em arquivo relatório.txt
Ler relatório salvo anteriormente
Ver informações sobre o sistema

# Pré-requisitos
Compilador C++ compatível com C++11 ou superior (ex: g++, clang++)
Como compilar e executar
bash# Compilar
g++ -o sistema_notas main.cpp

# Executar
./sistema_notas
No Windows, use sistema_notas.exe no lugar de ./sistema_notas.

# Como usar
Ao iniciar o programa, você verá o menu principal:

===== SISTEMA DE NOTAS v4.0 =====
1 - Novo Relatorio
2 - Ver relatorio salvo
3 - Sobre o sistema

# Escolha uma opcao:

# Opção 1 — Novo Relatório
Informe a quantidade de alunos (entre 1 e 20)
Digite o nome completo de cada aluno
Informe a quantidade de disciplinas (entre 1 e 5)
Digite as notas de cada aluno por disciplina (valores de 1 a 10)
O sistema exibe o relatório no terminal e salva em relatorio.txt com data e hora

# Opção 2 — Ver relatório salvo
Exibe o conteúdo do arquivo Relatorio.txt, caso ele exista no diretório atual.

# Opção 3 — Sobre o sistema
Exibe informações sobre o sistema, nome do desenvolvedor e turma.

# Estrutura do projeto
.
├── main.cpp         # Código-fonte principal
├── relatorio.txt    # Relatório gerado pelo programa (criado em tempo de execução)
└── README.md

# Observações
O arquivo lido na opção 2 é Relatorio.txt, enquanto o arquivo gerado é salvo como relatorio.txt — certifique-se de que os nomes coincidem no seu sistema operacional.
Notas devem estar entre 1 e 10; o programa solicita novamente se o valor for inválido.
Nomes com espaços são suportados (ex: "João da Silva").
O menu permanece ativo até que a opção 1 seja escolhida.
O relatório salvo inclui a data e hora de geração automaticamente.

# Contribuindo
Contribuições são bem-vindas! Sinta-se à vontade para abrir uma issue ou enviar um pull request com melhorias.
 
# Licença
Este projeto está sob a licença MIT.