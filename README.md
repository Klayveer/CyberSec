# 🛡️ CyberSec: Network Defender (Projeto Deadlock)

**Console Embarcado Interativo para Simulação de Defesa Cibernética.** Projeto Integrador de Eletrônica Aplicada e Sistemas Embarcados.

## 📖 Sobre o Projeto

O **CyberSec: Network Defender** é um simulador de sobrevivência gamificado em formato de console portátil (Edutainment). O jogador assume o papel de um analista de TI durante um expediente crítico (08h às 18h). O objetivo é defender a infraestrutura de rede da empresa contra ataques hackers reais (Ransomware, DDoS, Espionagem) utilizando uma mecânica **"Phygital"** (Físico + Digital).

Em vez de menus abstratos na tela, o jogador utiliza um deck físico de **20 cartões NFC** para aplicar contramedidas de cibersegurança.

## 🎮 Mecânicas Principais (Core Loop)

- **Mapa 2D Top-Down:** A rede é representada pela planta física da empresa (Sala de Servidores, RH, Financeiro).
- **Ação Local:** Para mitigar um ataque, o jogador deve movimentar o personagem fisicamente até a sala afetada através do Joystick.
- **Leitura NFC (Cyber-Deck):** Ao chegar no terminal sob ataque, o jogador deve escanear a carta física correta (ex: Carta de "Backup de Emergência" para conter um Ransomware).
- **Action Lock & Penalidades:** Ações corretas consomem tempo de processamento. Cartões incorretos agravam o ataque do hacker e aceleram a queda do setor.
- **Sistema de Vidas:** A perda de um setor compromete a integridade da empresa. A perda total resulta em "Demissão por Justa Causa" (Game Over).

## 🛠️ Arquitetura de Hardware

O console foi projetado com foco em performance gráfica e tempo de resposta:

- **Microcontrolador:** ESP32-S3 DevKitC-1.
- **Memória de Massa:** NAND Flash W25N01G (128MB) via SPI para armazenamento de assets (sprites/áudios) sem sobrecarregar a RAM.
- **Display:** Tela TFT SPI 3.5" (com biblioteca gráfica LVGL).
- **Leitor NFC:** Módulo PN532.
- **Controles:** Joystick Analógico e 4 Push-buttons.
- **Feedback:** Buzzer Passivo e LED RGB.
- **Energia:** Bateria Li-Po com Módulo TP4056 e Regulador LDO.

## ⚡ Fundamentação em Eletrônica Analógica

O hardware físico foi desenvolvido aplicando os conceitos rigorosos da disciplina:

1. **Entradas Analógicas (ADC):** Leitura dos eixos X/Y do Joystick via divisores de tensão internos para movimentação fluida no mapa.
2. **Dispositivos de Chaveamento:** Transistor NPN operando nas regiões de corte e saturação para amplificar a corrente e acionar o Buzzer Passivo.
3. **Hardware Debounce (Filtro RC):** Implementação de capacitores e resistores criando um filtro passa-baixa nos botões de ação, garantindo um sinal digital sem repique (ruído mecânico).
4. **Lei de Ohm:** Dimensionamento preciso de resistores limitadores de corrente para os LEDs de status do sistema.

## � Como Começar

### Clonar o Repositório

```bash
git clone https://github.com/Klayveer/CyberSec.git
cd CyberSec
```

### Instalar Dependências

```bash
npm install
```

## 📋 Contribuição & Commits

Este projeto utiliza **Conventional Commits** para manter um histórico claro e organizado. Todos os commits devem seguir o padrão abaixo:

### Formato de Commit

```
<type>(<scope>): <subject>
```

### Tipos Permitidos

- **feat**: Uma nova funcionalidade
- **fix**: Correção de bug
- **docs**: Alterações na documentação
- **style**: Formatação de código (sem mudança de lógica)
- **refactor**: Reorganização de código
- **perf**: Melhorias de performance
- **test**: Adição ou alteração de testes
- **chore**: Tarefas de build, dependências, etc.
- **ci**: Alterações em CI/CD
- **revert**: Reverter um commit anterior

### Exemplos de Commits Válidos

```bash
git commit -m "feat: adicionar leitor NFC ao console"
git commit -m "fix: corrigir mapeamento de joystick analógico"
git commit -m "docs: atualizar documentação do hardware"
git commit -m "refactor: reorganizar estrutura de pastas do projeto"
git commit -m "perf: otimizar renderização gráfica da tela"
```

### Regras Importantes

- ⚠️ Mensagens de commit **NÃO** podem terminar com ponto final
- ⚠️ Use sempre **minúsculas** no tipo e escopo
- ⚠️ Máximo de **72 caracteres** no subject
- ⚠️ Commits são validados automaticamente pelo `commitlint` + `husky`

### Ferramentas de Desenvolvimento

Este projeto utiliza as seguintes ferramentas para manter a qualidade do código:

- **husky**: Gerencia Git hooks
- **commitlint**: Valida as mensagens de commit
- **lint-staged**: Executa linters automaticamente nos arquivos alterados

Essas ferramentas rodam **automaticamente** antes de cada commit, garantindo que apenas código de qualidade seja integrado.

## 📁 Estrutura do Projeto

```
CyberSec/
├── src/              # Código-fonte principal
├── hardware/         # Documentação e esquemáticos do hardware
├── docs/             # Documentação do projeto
├── assets/           # Imagens, sprites e recursos
├── package.json      # Dependências do projeto
├── commitlint.config.js  # Configuração do commitlint
└── README.md         # Este arquivo
```

## �👥 Equipe de Desenvolvimento

- Caio Godoy
- Iris Costa
- Klayveer Silva
- João Gabriel

---

_Projeto acadêmico desenvolvido durante o semestre letivo._
