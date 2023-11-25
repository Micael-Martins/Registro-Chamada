void listarAluno(Aluno *lista, int posicao) {
    if (posicao > 0) {
        printf("Lista de chamada:\n");
        for (int i = 0; i < posicao; i++) {
            printf("%d. %s - Presenca: ", i + 1, lista[i].nome);

            // Mostrar "Presente" se a presença for 'P', caso contrário, mostrar "Faltoso"
            if (lista[i].presenca == 'P') {
                printf("Presente");
            } else if (lista[i].presenca == 'F') {
                printf("Faltoso");
            } else {
                printf("Desconhecido");  // Caso não se saiba a situação do aluno
            }

            // Mostrar a data da chamada ou desconhecido se não estiver definida
            if (strlen(lista[i].dataChamada) > 0) {
                printf(" - Data da chamada: %s\n", lista[i].dataChamada);
            } else {
                printf(" - Data da chamada: Desconhecido\n");
            }
        }
    } else {
        printf("A lista de chamada está vazia\n");
    }
}