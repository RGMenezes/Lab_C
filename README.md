# Introdução à Programação em C e Lógica

Repositório de apoio para alunos do 1º período de Ciência da Computação.

## Estrutura

```text
.
├── INSTALL.md
├── README.md
├── conceitos
│   ├── 01_ola_mundo.c
│   └── 02_variaveis_e_entrada.c
└── exercicios
    └── 01_media_notas.c
```

## Como compilar e executar no terminal

Exemplo geral:

```bash
gcc arquivo.c -o programa
./programa
```

Exemplo com um arquivo da pasta `conceitos`:

```bash
gcc conceitos/01_ola_mundo.c -o ola_mundo
./ola_mundo
```

No Windows (Prompt de Comando/PowerShell), pode ser:

```bash
gcc conceitos/01_ola_mundo.c -o ola_mundo
.\ola_mundo.exe
```

## Fluxo básico com Git

```bash
git add .
git commit -m "Adiciona exemplos iniciais de C"
git push origin main
```

## Objetivo didático

- Entender a estrutura básica de um programa em C.
- Praticar entrada e saída de dados.
- Reforçar lógica de programação com exercícios simples.
