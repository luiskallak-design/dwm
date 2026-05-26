#!/bin/bash
# install_protognum.sh - Script de um clique para o peão

CYAN='\033[0;36m'
GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD='\033[1m'
RESET='\033[0m'

clear
echo -e "${CYAN}${BOLD}⌬ [FORJA PROTOGNUM] Iniciando instalação local automatizada...${RESET}"

# 1. Cria uma pasta temporária isolada
TEMP_DIR="/tmp/protognum-local-build"
rm -rf "$TEMP_DIR"
mkdir -p "$TEMP_DIR"

# 2. Clona o repositório oficial da central de comando
echo -e "${CYAN}❱❱ Baixando fontes da central de comando...${RESET}"
git clone https://github.com/luiskallak-design/protognum "$TEMP_DIR" &>/dev/null

# 3. Entra na subpasta correta onde residem o Makefile e o código fonte
cd "$TEMP_DIR/protognum" || {
    echo -e "${RED}[!] Erro crítico: Falha ao acessar a pasta do código-fonte.${RESET}"
    rm -rf "$TEMP_DIR"
    exit 1
}

echo -e "${CYAN}❱❱ Compilando módulos e integrando o ecossistema...${RESET}"
echo -e "${CYAN}(Insira sua senha sudo para concluir a instalação no sistema)${RESET}"

# 4. Executa a compilação e instalação global
if make && sudo make install; then
    rm -rf "$TEMP_DIR"
    echo -e "\n${GREEN}${BOLD}⌬ [PROTOGNUM] PROTOCOLO ATIVADO COM SUCESSO!${RESET}"
    echo -e "${CYAN}❱❱ O gerenciador já está pronto. Digite 'protognum' para testar.${RESET}\n"
else
    echo -e "${RED}[!] Erro na compilação. Verifique suas dependências (ncurses).${RESET}"
    rm -rf "$TEMP_DIR"
    exit 1
fi

