```markdown
# TP1 - Jogo Magic6

![C Language](https://img.shields.io/badge/Linguagem-C-blue.svg)
![GitHub last commit](https://img.shields.io/github/last-commit/seu-usuario/TP1-Magic6)
![License](https://img.shields.io/badge/Licença-MIT-green.svg)

Implementação em C do jogo Magic6, trabalho prático para a disciplina de Programação em Sistemas Computacionais.

## 📝 Descrição

O Magic6 é um jogo de adivinhação baseado na representação binária de números:
- **Modo 1**: O computador adivinha seu número (1-63) analisando em quais cartões ele aparece
- **Modo 2**: Você adivinha o número do computador observando os cartões onde ele aparece

## 🛠️ Como Compilar e Executar

### Pré-requisitos
- Compilador GCC (`sudo apt install gcc` no Linux)

### Passos:
```bash
# Clone o repositório
git clone https://github.com/seu-usuario/TP1-Magic6.git
cd TP1-Magic6/src

# Compile (Linux/macOS)
gcc magic6.c -o magic6

# Execute
./magic6
```

## Como Jogar

1. **Modo Computador Adivinha**:
   - Pense em um número entre 1-63
   - Para cada cartão exibido, digite:
     - `1` se seu número estiver no cartão
     - `0` caso contrário
   - O computador revelará seu número!

2. **Modo Você Adivinha**:
   - O computador gera um número secreto
   - Todos os cartões são exibidos, indicando onde o número aparece
   - Tente adivinhar o número!

## Estrutura do Projeto
```
TP1-Magic6/
├── src/
│   └── magic6.c        # Código fonte principal
├── docs/
│   └── RELATORIO.md    # Documentação técnica
└── README.md           # Este arquivo
```

## Exemplo de Saída
```
=== Jogo Magic6 ===
1. Computador adivinha o seu numero
2. Voce adivinha o numero do computador
3. Sair
Escolha: 1

=== Cartão 1 ===
   1   3   5   7   9  11  13  15
  17  19  21  23  25  27  29  31
  ...
O número está neste cartão? (1-Sim, 0-Não): 1
```
