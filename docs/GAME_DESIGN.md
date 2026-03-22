# 👾 Game Design Document (GDD) - Projeto Deadlock

## 1. Narrativa e Atmosfera

- **O Cenário:** Escritório de uma empresa de tecnologia com salas divididas por setores.
- **O Antagonista:** Uma "presença digital" invasora que se manifesta através de alertas críticos, chamas nos servidores e glitches na tela.
- **A Trama:** Você é o novo estagiário de segurança no plantão. O sistema está sob ataque massivo e só o seu deck de ferramentas físicas (cartões NFC) pode salvar os dados.

## 2. Máquina de Estados (FSM - Finite State Machine)

A arquitetura de software é dividida nos seguintes estados:

1. `START_SCREEN`: Menu inicial.
2. `MAP_EXPLORATION`: Movimentação livre 2D e execução de Tarefas Verdes (Prevenção).
3. `TERMINAL_INTERACTION`: Alerta Vermelho acionado. Jogador posicionado no local da invasão.
4. `NFC_READING`: Interrupção de hardware aguardando o escaneamento do cartão físico via PN532.
5. `ACTION_PROGRESS`: Action Lock. Animação de barra de progresso após uso do cartão.
6. `GAME_OVER`: Condição de vitória (18h00 alcançadas) ou derrota (Setores destruídos).

## 3. Classificação de Tarefas

- **Tarefas Verdes:** Rotina. Atualizar senhas, configurar firewalls.
- **Tarefas Amarelas:** Anomalias e alertas de segurança. Devem ser verificados para evitar escalada de privilégios.
- **Tarefas Vermelhas:** Ataques em curso (Ransomware, DDoS, Sniffing). Requerem deslocamento imediato e uso do cartão NFC correspondente.
