# Sistema de Gerenciamento de Companhias Aéreas ✈️

Este é um sistema de gerenciamento de companhias aéreas desenvolvido em **C++**. O objetivo do sistema é gerenciar passageiros, tripulantes, voos e reservas de forma simples e eficiente.

## Funcionalidades

O sistema oferece as seguintes funcionalidades:

1. **Cadastrar Passageiro:** Adiciona um novo passageiro ao sistema.
2. **Cadastrar Tripulante:** Permite o cadastro de pilotos e copilotos.
3. **Cadastrar Voo:** Permite registrar voos, associando tripulantes e detalhes do voo.
4. **Criar Reserva:** Permite a criação de uma nova reserva, associando um passageiro e um assento a um voo.
5. **Listar Voos para Passageiro:** Exibe todos os voos disponíveis para o passageiro.
6. **Pesquisar Passageiro:** Permite procurar um passageiro específico pelo nome ou código.
7. **Pesquisar Tripulante:** Permite buscar por tripulantes (piloto, copiloto ou comissários).
8. **Salvar e Carregar Dados:** O sistema salva os dados em um arquivo e pode carregá-los quando necessário.

## Como Usar

### Pré-requisitos

Certifique-se de ter uma IDE ou outro ambiente C++ configurado corretamente. Você precisará também de um compilador C++ (como o GCC).

### Passos para Rodar

1. **Clone o repositório:**

   ```bash
   git clone https://github.com/seu-usuario/sistema-companhia-aerea.git

2. **Abra o projeto na sua IDE ou outro ambiente C++ de sua preferência.**

3. **Compile e execute o projeto.**

4. **Interaja com o menu:**
 - O sistema apresentará um menu interativo no terminal onde você pode escolher as opções de cadastro, pesquisa e outras funcionalidades.

## Estrutura das Classes:

- **Voo:** Gerencia os detalhes dos voos, incluindo informações como código, origem, destino, tripulantes e assentos.
- **Passageiro:** Armazena os dados dos passageiros, como código, nome, endereço e telefone.
- **Tripulacao:** Gerencia os dados dos tripulantes, incluindo pilotos, copilotos e comissários.
- **Reserva:** Representa a reserva feita por um passageiro para um voo específico.
- **Sistema:** Responsável pela carga e salvamento de dados do sistema, além de gerenciar a execução das funcionalidades.

## Membros do Grupo ✨
- **Lucas Fonseca, Mariana Tavares e Tiago Benevenuto.**
- Estudantes de Engenharia de Software na PUC Minas.
