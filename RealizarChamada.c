// Chamada
void realizarChamada(Aluno *lista, int posicao) {
    if (posicao > 0) {
        int dia, mes, ano; // Variaveis da data
        char dataChamada[11];
        
        do {
            printf("Digite a data da chamada (formato dd/mm/yyyy):\n");
            if (fgets(dataChamada, sizeof(dataChamada), stdin) != NULL) {
                dataChamada[strcspn(dataChamada, "\n")] = '\0'; // Remove o caractere de nova linha
            // Tentei adicionar uma mensagem caso a data seja inserida de maneira errada so que a mensagem não sai se quiser pode excluir ou conserta esse bo -Otton
            } else {
                printf("Erro na leitura da data. Chamada nao realizada.\n"); 
                return;
            }
            // Impedimento para que data não seja introduzida de qualquer jeito
        } while (sscanf(dataChamada, "%2d/%2d/%4d", &dia, &mes, &ano) != 3 || dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1000 || ano > 9999);

        printf("Realizar chamada em %s:\n", dataChamada);
        for (int i = 0; i < posicao; i++) {
            printf("%d. %s - Presenca (P/F): ", i + 1, lista[i].nome);
            char presenca;
            scanf(" %c", &presenca);

            // Caso seja entregue algo diferente de P ou F
            while (presenca != 'P' && presenca != 'F') {
                printf("Entrada invalida. Digite P para presente ou F para faltoso: ");
                scanf(" %c", &presenca);
            }

            lista[i].presenca = presenca;
            strncpy(lista[i].dataChamada, dataChamada, sizeof(lista[i].dataChamada));
        }
    } else {
        printf("A lista de chamada esta vazia\n");
    }
}

int main() {
    Aluno listaDeChamada[100];
    int tamanhoDaLista = 0;  // Troquei para zero pois estava bugando e não sabia o motivo -Otton
    int escolha;