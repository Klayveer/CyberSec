# 🛡️ CyberSec: Network Defender (Projeto Deadlock)

Console embarcado interativo para simulação de defesa cibernética.
Projeto integrador de Eletrônica Aplicada e Sistemas Embarcados.

## 📖 Sobre o Projeto

O CyberSec: Network Defender é um simulador de sobrevivência em formato de console portátil (edutainment).
O jogador assume o papel de um analista de TI durante um expediente crítico (08h às 18h), defendendo a rede da empresa contra ataques reais, como ransomware, DDoS e espionagem.

A proposta usa uma mecânica phygital (físico + digital): em vez de menus abstratos, o jogador usa um deck físico de 20 cartões NFC para aplicar contramedidas.

## 🎮 Mecânicas Principais

- **Mapa 2D Top-Down:** a rede é representada pela planta física da empresa (servidores, RH, financeiro etc.).
- **Ação local:** para mitigar ataques, o personagem deve ir até o setor afetado via joystick.
- **Leitura NFC (Cyber-Deck):** no terminal sob ataque, o jogador escaneia a carta correta.
- **Action lock e penalidades:** ações corretas consomem tempo; cartas erradas agravam o ataque.
- **Sistema de vidas:** perda de setores compromete a empresa e pode levar ao game over.

## 🛠️ Arquitetura de Hardware

- **Microcontrolador:** ESP32-S3 DevKitC-1
- **Memória de massa:** NAND Flash W25N01G (128MB) via SPI
- **Display:** TFT SPI 3.5" (LVGL)
- **Leitor NFC:** PN532
- **Controles:** joystick analógico + 4 push-buttons
- **Feedback:** buzzer passivo + LED RGB
- **Energia:** bateria Li-Po + TP4056 + regulador LDO

## ⚡ Fundamentação em Eletrônica Analógica

1. **Entradas analógicas (ADC):** leitura dos eixos X/Y do joystick para movimentação fluida.
2. **Chaveamento com transistor NPN:** acionamento do buzzer nas regiões de corte/saturação.
3. **Debounce em hardware (filtro RC):** redução de ruído mecânico nos botões.
4. **Lei de Ohm:** dimensionamento de resistores para LEDs de status.

## 🚀 Como Começar

### Pré-requisitos

- Git
- Node.js + npm

### Clonar o repositório

```bash
git clone https://github.com/Klayveer/CyberSec.git
cd CyberSec
```

### Instalar dependências

```bash
npm install
```

## 🧪 Simulador V1 (Wokwi)

A versão inicial do simulador está na pasta `worki/`.

- Link do projeto no Wokwi: https://wokwi.com/projects/459240224531439617
- Sketch principal: `worki/sketch.ino`
- Bibliotecas usadas no simulador:
  - Adafruit ILI9341
  - Adafruit GFX Library

### Como abrir a V1

1. Acesse o link do Wokwi acima.
2. Use os arquivos da pasta `worki/` como referência da montagem e lógica.
3. Rode a simulação para validar fluxo de menu, mapa, alerta e resposta NFC.

## 📋 Padrão de Commits (Commitlint)

Este projeto usa **Conventional Commits** com validação automática via hooks.

Formato esperado:

```text
<type>(<scope>): <subject>
```

`scope` é opcional.

### Tipos permitidos

- feat
- fix
- docs
- style
- refactor
- perf
- test
- chore
- ci
- revert

### Regras ativas

- tipo obrigatório e em minúsculas
- subject obrigatório
- subject sem ponto final
- subject não pode estar em Start Case
- tamanho máximo do header: 72 caracteres

### Exemplos válidos

```bash
git commit -m "feat: adicionar leitor nfc ao console"
git commit -m "fix: corrigir leitura do joystick"
git commit -m "docs: atualizar visão geral do hardware"
git commit -m "chore(ci): ajustar pipeline de validação"
```

## ✅ Qualidade de Código (Husky + Lint-Staged)

Antes de cada commit:

- **pre-commit:** roda `lint-staged`
  - `eslint --fix` em arquivos `*.js, *.jsx, *.ts, *.tsx`
  - `prettier --write` em `*.js, *.jsx, *.ts, *.tsx, *.json, *.css, *.md`
- **commit-msg:** roda `commitlint` para validar a mensagem

Isso garante padrão de histórico e formatação consistente no repositório.

## 📁 Estrutura do Projeto

```text
CyberSec/
├── assets/         # Imagens, sprites e recursos
├── docs/           # Documentação do projeto
├── hardware/       # Documentação e esquemáticos do hardware
├── src/            # Código-fonte principal
├── worki/          # Simulador V1 (Wokwi)
│   ├── sketch.ino
│   ├── diagram.json
│   ├── libraries.txt
│   ├── link.txt
│   ├── circuito.png
│   └── problema.png
├── commitlint.config.js
├── eslint.config.js
├── package.json
└── README.md
```

## 👥 Equipe de Desenvolvimento

- Caio Godoy
- Iris Costa
- Klayveer Silva
- João Gabriel

---

Projeto acadêmico desenvolvido durante o semestre letivo.
