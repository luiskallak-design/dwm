# ⌬ MATRIZ DE CONFIGURAÇÃO SIMPLIFICADA (SIMPLECONFIG)

> ⚠️ **[!] AVISO CRUCIAL DE SEGURANÇA ── LEIA ANTES DE DIGITAR**
>
> SE VOCÊ JÁ POSSUI UM ARQUIVO `~/.xinitrc` CONFIGURADO NO SEU LINUX, **NÃO SOBRESCREVA SEU ARQUIVO!** 
> Se você sobrescrever às cegas, perderá instantaneamente todas as suas configurações atuais de monitores, bateria e papéis de parede.

---

## 📦 IMPLANTAÇÃO DA MATRIZ

A pasta `simpleconfig` contém as variáveis de ambiente essenciais para não quebrar temas GTK/Qt, além de presets minimalistas para os terminais do arsenal (`kitty`, `terminator`, `qterminal`).

### ➔ PASSO 1: Configurar o seu ambiente gráfico (O xinitrc)

Escolha a **SITUAÇÃO** que se aplica ao seu sistema atual:

* **SITUAÇÃO A: Você JÁ TEM um arquivo `~/.xinitrc` customizado**
  Rode o comando abaixo para apenas **anexar** as nossas variáveis `XDG_` e o ecossistema de avisos no final do seu arquivo existente, sem apagar nada:
  ```bash
  cat simpleconfig/xinitrc >> ~/.xinitrc
  ```
  *Importante: Abra o seu `~/.xinitrc` logo em seguida e garanta que a linha `exec dwm` continue sendo estritamente a última linha do documento.*

* **SITUAÇÃO B: Você NÃO TEM um arquivo `~/.xinitrc` no sistema**
  Se o seu ambiente está limpo e sem nenhum arquivo de inicialização para o comando `startx`, copie o nosso modelo completo diretamente:
  ```bash
  cp simpleconfig/xinitrc ~/.xinitrc
  chmod +x ~/.xinitrc
  ```

---

### ➔ PASSO 2: Injetar presets dos terminais do Arsenal

Para implantar as configurações de exemplo dos terminais na sua pasta de usuário:

```bash
# O parâmetro '-i' garante que o sistema vai PERGUNTAR antes de sobrescrever se você já tiver a pasta
cp -ri simpleconfig/kitty simpleconfig/terminator simpleconfig/qterminal ~/.config/
```

---

## 🛰️ ECOSSISTEMA PROTOGNUM (INTEGRAÇÃO COMPLETA)

Se você quiser instalar o gerenciador tático Protognum de forma 100% automática, nós já deixamos um script de um clique dentro da sua pasta de configurações. 

Basta abrir o seu terminal e rodar o comando abaixo:

```bash
sh ~/.config/install_protognum.sh
```

O script vai baixar o código do repositório, compilar através do Makefile, checar e forjar o ArchonPlayer automaticamente caso necessário, pedir o sudo para instalar globalmente e limpar os arquivos temporários sozinho.
