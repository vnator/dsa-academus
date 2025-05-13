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
    // Listas para os jogos da nova geração
    Lista monster_hunter_world;
    Lista monster_hunter_rise;
    Lista monster_hunter_wilds;
    
    // Inicialização das listas
    inicializar(&monster_hunter_world);
    inicializar(&monster_hunter_rise);
    inicializar(&monster_hunter_wilds);
    
    // ===== Monster Hunter World =====
    printf("===== Populando Monster Hunter World =====\n");
    // Inserção em ordem aleatória para mostrar que a lista manterá a ordem alfabética
    inserir_chave(&monster_hunter_world, criar_wyvern("Nergigante", "Elder Dragon", "Monster Hunter World", 5));
    inserir_chave(&monster_hunter_world, criar_wyvern("Velkhana", "Elder Dragon", "Monster Hunter World", 5));
    inserir_chave(&monster_hunter_world, criar_wyvern("Alatreon", "Elder Dragon", "Monster Hunter World", 6));
    inserir_chave(&monster_hunter_world, criar_wyvern("Fatalis", "Elder Dragon", "Monster Hunter World", 7));
    inserir_chave(&monster_hunter_world, criar_wyvern("Rajang", "Fanged Beast", "Monster Hunter World", 5));
    inserir_chave(&monster_hunter_world, criar_wyvern("Zinogre", "Fanged Wyvern", "Monster Hunter World", 4));
    
    printf("\nLista ordenada de monstros de Monster Hunter World:\n");
    imprimir_lista(&monster_hunter_world);
    
    // ===== Monster Hunter Rise =====
    printf("\n===== Populando Monster Hunter Rise =====\n");
    inserir_chave(&monster_hunter_rise, criar_wyvern("Magnamalo", "Fanged Wyvern", "Monster Hunter Rise", 5));
    inserir_chave(&monster_hunter_rise, criar_wyvern("Goss Harag", "Fanged Beast", "Monster Hunter Rise", 4));
    inserir_chave(&monster_hunter_rise, criar_wyvern("Almudron", "Leviathan", "Monster Hunter Rise", 4));
    inserir_chave(&monster_hunter_rise, criar_wyvern("Rakna-Kadaki", "Temnoceran", "Monster Hunter Rise", 4));
    inserir_chave(&monster_hunter_rise, criar_wyvern("Crimson Glow Valstrax", "Elder Dragon", "Monster Hunter Rise", 6));
    inserir_chave(&monster_hunter_rise, criar_wyvern("Thunder Serpent Narwa", "Elder Dragon", "Monster Hunter Rise", 6));
    
    printf("\nLista ordenada de monstros de Monster Hunter Rise:\n");
    imprimir_lista(&monster_hunter_rise);
    
    // ===== Monster Hunter Wilds =====
    printf("\n===== Populando Monster Hunter Wilds (Previstos) =====\n");
    inserir_chave(&monster_hunter_wilds, criar_wyvern("Lomos Harag", "Fanged Beast", "Monster Hunter Wilds", 4));
    inserir_chave(&monster_hunter_wilds, criar_wyvern("Fertuos Magna", "Elder Dragon", "Monster Hunter Wilds", 6));
    inserir_chave(&monster_hunter_wilds, criar_wyvern("Doshaguma", "Fanged Beast", "Monster Hunter Wilds", 3));
    inserir_chave(&monster_hunter_wilds, criar_wyvern("Alpha Ceanataur", "Carapaceon", "Monster Hunter Wilds", 5));
    inserir_chave(&monster_hunter_wilds, criar_wyvern("Yuki Hitaki", "Flying Wyvern", "Monster Hunter Wilds", 5));
    
    printf("\nLista ordenada de monstros de Monster Hunter Wilds:\n");
    imprimir_lista(&monster_hunter_wilds);
    
    // Testando operações de busca e remoção
    printf("\n===== Testando operações de busca e remoção =====\n");
    
    // Busca de um monstro existente
    printf("Buscando Fatalis em MH World...\n");
    No* fatalis = buscar_chave(&monster_hunter_world, "Fatalis");
    if (fatalis != NULL) {
        printf("Encontrado: %s (%s) - Dificuldade: %d\n", 
               fatalis->monstro.nome, fatalis->monstro.jogo, fatalis->monstro.dificuldade);
    } else {
        printf("Wyvern não encontrado!\n");
    }
    
    // Busca de um monstro inexistente
    printf("\nBuscando Rathalos em MH Rise (não existe)...\n");
    No* rathalos = buscar_chave(&monster_hunter_rise, "Rathalos");
    if (rathalos != NULL) {
        printf("Encontrado: %s (%s)\n", rathalos->monstro.nome, rathalos->monstro.jogo);
    } else {
        printf("Wyvern não encontrado!\n");
    }
    
    // Remoção de um monstro existente
    printf("\nRemovendo Magnamalo de MH Rise...\n");
    if (remover_chave(&monster_hunter_rise, "Magnamalo")) {
        printf("Magnamalo removido com sucesso!\n");
        printf("\nLista atualizada de MH Rise:\n");
        imprimir_lista(&monster_hunter_rise);
    } else {
        printf("Falha ao remover: Wyvern não encontrado!\n");
    }
    
    // Remoção de um monstro inexistente
    printf("\nTentando remover Mizutsune de MH Wilds (não existe)...\n");
    if (remover_chave(&monster_hunter_wilds, "Mizutsune")) {
        printf("Mizutsune removido com sucesso!\n");
    } else {
        printf("Falha ao remover: Wyvern não encontrado!\n");
    }
    
    // Relatório final
    printf("\n===== Relatório Final =====\n");
    printf("Total de wyverns em MH World: %d\n", retornar_tamanho(&monster_hunter_world));
    printf("Total de wyverns em MH Rise: %d\n", retornar_tamanho(&monster_hunter_rise));
    printf("Total de wyverns em MH Wilds: %d\n", retornar_tamanho(&monster_hunter_wilds));
    
    // Liberando memória
    printf("\n===== Liberando memória =====\n");
    reinicializar_lista(&monster_hunter_world);
    reinicializar_lista(&monster_hunter_rise);
    reinicializar_lista(&monster_hunter_wilds);
    
    printf("Memória liberada com sucesso!\n");
    
    return 0;
}