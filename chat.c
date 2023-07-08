#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar uma resposta aleatória
char* gerarRespostaAleatoria() {
    char* respostas[] = {
        "Entendo.",
        "Interessante!",
        "Diga-me mais.",
        "Isso é intrigante.",
        "Não tenho certeza, poderia explicar melhor?",
        "Eu concordo.",
        "Como posso ajudar?"
    };
    int numRespostas = sizeof(respostas) / sizeof(respostas[0]);
    int indiceAleatorio = rand() % numRespostas;
    return respostas[indiceAleatorio];
}

// Função para responder à entrada do usuário
char* responder(char* entrada) {
    // Verificar se a entrada do usuário corresponde a algum padrão predefinido
    if (strcmp(entrada, "Olá") == 0 || strcmp(entrada, "Oi") == 0) {
        return "Olá! Como posso ajudar?";
    }

    // Realizar análise de palavras-chave ou análise sintática para identificar o tópico da pergunta

    // Geração de respostas aleatórias
    char* respostaAleatoria = gerarRespostaAleatoria();
    return respostaAleatoria;
}


int main() {
    srand(time(NULL));
    // Loop para continuar interagindo com o usuário até receber o comando de saída
    char entrada[256];
    while (1) {
        // Receber a entrada do usuário
        printf("Usuário: ");
        fgets(entrada, sizeof(entrada), stdin);

        // Remover o caractere de nova linha no final da entrada
        entrada[strcspn(entrada, "\n")] = '\0';

        // Verificar se o usuário digitou o comando de saída
        if (strcmp(entrada, "sair") == 0) {
            printf("Chat encerrado. Até logo!\n");
            break;
        }

        // Obter a resposta gerada
        char* resposta = responder(entrada);

        // Exibir a resposta para o usuário
        printf("Bot: %s\n", resposta);
    }

    return 0;
}
