# Guia de Configuração no Windows

Este guia prepara seu ambiente para programar em C no Windows.

## 1) Instalar o Git

1. Acesse o site oficial:
   - https://git-scm.com/download/win
2. Baixe o instalador e execute como padrão (Next, Next, Finish).
3. Abra o terminal (PowerShell ou Prompt de Comando) e configure seu nome e e-mail:

```bash
git config --global user.name "Seu Nome"
git config --global user.email "seuemail@exemplo.com"
```

4. Verifique as configurações:

```bash
git config --global --list
```

## 2) Instalar o Visual Studio Code

1. Acesse:
   - https://code.visualstudio.com/
2. Baixe a versão para Windows.
3. Durante a instalação, marque opções úteis como:
   - Adicionar "Abrir com Code" no menu de contexto.
   - Registrar o VS Code como editor padrão (opcional).

## 3) Instalar o compilador C (MinGW-w64 via MSYS2)

1. Acesse:
   - https://www.msys2.org/
2. Baixe e instale o MSYS2 no caminho padrão (`C:\msys64`).
3. Abra o terminal **MSYS2 UCRT64** pelo menu Iniciar.
4. Atualize os pacotes:

```bash
pacman -Syu
```

Observação: em alguns casos, será necessário fechar e abrir o terminal novamente e repetir o comando.

5. Instale o GCC e o GDB (MinGW-w64 UCRT64):

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-gdb
```

6. Passo crucial: adicionar o compilador ao PATH do Windows.

Caminho que deve ser adicionado:

```text
C:\msys64\ucrt64\bin
```

### Como adicionar ao PATH

1. Pesquise no Windows por: **Variáveis de Ambiente**.
2. Abra: **Editar as variáveis de ambiente do sistema**.
3. Clique em **Variáveis de Ambiente...**.
4. Em **Variáveis do Sistema**, selecione **Path** e clique em **Editar...**.
5. Clique em **Novo** e cole:

```text
C:\msys64\ucrt64\bin
```

6. Confirme em **OK** em todas as janelas.
7. Feche e abra novamente o terminal (e o VS Code) para aplicar.

> **Atenção:** se o VS Code já estava aberto durante a configuração do PATH, feche-o completamente e reabra. Terminais abertos antes da mudança não herdam o novo PATH.

## 4) Extensões recomendadas no VS Code

Instale as extensões abaixo:

- **C/C++** (Microsoft)
- **Code Runner**

## 5) Configurar o VS Code para compilar e depurar

O repositório já inclui a pasta `.vscode` com dois arquivos de configuração prontos:

- `.vscode/tasks.json` — compila o arquivo `.c` aberto com `gcc -g`
- `.vscode/launch.json` — executa e depura com `gdb` (F5)

Se precisar recriar esses arquivos manualmente, veja o conteúdo abaixo.

### tasks.json

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "gcc: compilar arquivo atual",
      "type": "shell",
      "command": "gcc",
      "args": ["-g", "${file}", "-o", "${fileDirname}\\${fileBasenameNoExtension}.exe"],
      "group": { "kind": "build", "isDefault": true },
      "problemMatcher": ["$gcc"]
    }
  ]
}
```

### launch.json

```json
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "(gdb) Rodar",
      "type": "cppdbg",
      "request": "launch",
      "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
      "args": [],
      "stopAtEntry": false,
      "cwd": "${fileDirname}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "miDebuggerPath": "C:\\msys64\\ucrt64\\bin\\gdb.exe",
      "preLaunchTask": "gcc: compilar arquivo atual"
    }
  ]
}
```

Para rodar um arquivo `.c`, abra-o e pressione **F5**.

## 6) Comandos de verificação

No terminal, execute:

```bash
gcc --version
gdb --version
git --version
```

Se todos retornarem versão, o ambiente está pronto.
