#include "lista.h"

// Função auxiliar para criar um wyvern
Wyvern criar_wyvern(char *nome, char *tipo, char *jogo, int dificuldade) {
    Wyvern w;
    strcpy(w.nome, nome);
    strcpy(w.tipo, tipo);
    strcpy(w.jogo, jogo);
    w.dificuldade = dificuldade;
    return w;
}

int main() {
    // Listas para os jogos da velha geração
    Lista monster_hunter1;
    Lista monster_hunter2;
    Lista monster_hunter3;
    Lista monster_hunter4;
    
    // Inicialização das listas
    inicializar(&monster_hunter1);
    inicializar(&monster_hunter2);
    inicializar(&monster_hunter3);
    inicializar(&monster_hunter4);
    
    // ===== Monster Hunter 1 =====
    printf("===== Populando Monster Hunter 1 =====\n");
    inserir_final(&monster_hunter1, criar_wyvern("Rathalos", "Flying Wyvern", "Monster Hunter 1", 4));
    inserir_final(&monster_hunter1, criar_wyvern("Rathian", "Flying Wyvern", "Monster Hunter 1", 3));
    inserir_final(&monster_hunter1, criar_wyvern("Diablos", "Flying Wyvern", "Monster Hunter 1", 4));
    inserir_final(&monster_hunter1, criar_wyvern("Khezu", "Flying Wyvern", "Monster Hunter 1", 3));
    inserir_final(&monster_hunter1, criar_wyvern("Gravios", "Flying Wyvern", "Monster Hunter 1", 4));
    
    printf("\nLista de monstros de Monster Hunter 1:\n");
    imprimir_lista(&monster_hunter1);
    
    // ===== Monster Hunter 2 =====
    printf("\n===== Populando Monster Hunter 2 =====\n");
    inserir_final(&monster_hunter2, criar_wyvern("Tigrex", "Flying Wyvern", "Monster Hunter 2", 4));
    inserir_final(&monster_hunter2, criar_wyvern("Kushala Daora", "Elder Dragon", "Monster Hunter 2", 5));
    inserir_final(&monster_hunter2, criar_wyvern("Chameleos", "Elder Dragon", "Monster Hunter 2", 5));
    inserir_final(&monster_hunter2, criar_wyvern("Teostra", "Elder Dragon", "Monster Hunter 2", 5));
    inserir_final(&monster_hunter2, criar_wyvern("Akantor", "???", "Monster Hunter 2", 5));
    
    printf("\nLista de monstros de Monster Hunter 2:\n");
    imprimir_lista(&monster_hunter2);
    
    // ===== Monster Hunter 3 =====
    printf("\n===== Populando Monster Hunter 3 =====\n");
    inserir_final(&monster_hunter3, criar_wyvern("Lagiacrus", "Leviathan", "Monster Hunter 3", 4));
    inserir_final(&monster_hunter3, criar_wyvern("Ceadeus", "Elder Dragon", "Monster Hunter 3", 5));
    inserir_final(&monster_hunter3, criar_wyvern("Deviljho", "Brute Wyvern", "Monster Hunter 3", 5));
    inserir_final(&monster_hunter3, criar_wyvern("Alatreon", "Elder Dragon", "Monster Hunter 3", 5));
    inserir_final(&monster_hunter3, criar_wyvern("Barioth", "Flying Wyvern", "Monster Hunter 3", 4));
    
    printf("\nLista de monstros de Monster Hunter 3:\n");
    imprimir_lista(&monster_hunter3);
    
    // ===== Monster Hunter 4 =====
    printf("\n===== Populando Monster Hunter 4 =====\n");
    inserir_final(&monster_hunter4, criar_wyvern("Gore Magala", "???", "Monster Hunter 4", 4));
    inserir_final(&monster_hunter4, criar_wyvern("Shagaru Magala", "Elder Dragon", "Monster Hunter 4", 5));
    inserir_final(&monster_hunter4, criar_wyvern("Seregios", "Flying Wyvern", "Monster Hunter 4", 4));
    inserir_final(&monster_hunter4, criar_wyvern("Nerscylla", "Temnoceran", "Monster Hunter 4", 3));
    inserir_final(&monster_hunter4, criar_wyvern("Dalamadur", "Elder Dragon", "Monster Hunter 4", 5));
    
    printf("\nLista de monstros de Monster Hunter 4:\n");
    imprimir_lista(&monster_hunter4);
    
    // Testando operações de remoção e busca
    printf("\n===== Testando operações =====\n");
    printf("Buscando Deviljho...\n");
    No* deviljho = buscar_chave(&monster_hunter3, "Deviljho");
    if (deviljho != NULL) {
        printf("Encontrado: %s (%s)\n", deviljho->monstro.nome, deviljho->monstro.jogo);
    } else {
        printf("Wyvern não encontrado!\n");
    }
    
    printf("\nRemovendo Gore Magala do MH4...\n");
    if (remover_chave(&monster_hunter4, "Gore Magala")) {
        printf("Gore Magala removido com sucesso!\n");
        printf("\nLista atualizada de MH4:\n");
        imprimir_lista(&monster_hunter4);
    }
    
    printf("\nRemovendo o primeiro monstro de MH1...\n");
    if (remover_inicio(&monster_hunter1)) {
        printf("Primeiro monstro removido com sucesso!\n");
        printf("\nLista atualizada de MH1:\n");
        imprimir_lista(&monster_hunter1);
    }
    
    printf("\nRemovendo o último monstro de MH2...\n");
    if (remover_final(&monster_hunter2)) {
        printf("Último monstro removido com sucesso!\n");
        printf("\nLista atualizada de MH2:\n");
        imprimir_lista(&monster_hunter2);
    }
    
    // Relatório final
    printf("\n===== Relatório Final =====\n");
    printf("Total de wyverns em MH1: %d\n", retornar_tamanho(&monster_hunter1));
    printf("Total de wyverns em MH2: %d\n", retornar_tamanho(&monster_hunter2));
    printf("Total de wyverns em MH3: %d\n", retornar_tamanho(&monster_hunter3));
    printf("Total de wyverns em MH4: %d\n", retornar_tamanho(&monster_hunter4));
    
    // Liberando memória
    printf("\n===== Liberando memória =====\n");
    reinicializar_lista(&monster_hunter1);
    reinicializar_lista(&monster_hunter2);
    reinicializar_lista(&monster_hunter3);
    reinicializar_lista(&monster_hunter4);
    
    printf("Memória liberada com sucesso!\n");
    
    return 0;
}