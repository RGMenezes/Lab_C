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

5. Instale o GCC (MinGW-w64 UCRT64):

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc
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
7. Feche e abra novamente o terminal para aplicar.

## 4) Extensões recomendadas no VS Code

Instale as extensões abaixo:

- **C/C++** (Microsoft)
- **C/C++ Themes**
- **Code Runner**

## 5) Comandos de verificação

No terminal, execute:

```bash
gcc --version
git --version
```

Se ambos retornarem versão, o ambiente está pronto.
