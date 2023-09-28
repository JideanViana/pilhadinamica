

        typedef struct No{
            int x;
            No* proximo;
        }No;

        No* topo = NULL;

        void inserir(int valor){

            No* novoNO = malloc(sizeof(No));
            if (novoNo == NULL){
                printf("Erro.\n");
                return;
            }

            novoNo->x = valor;
            novoNo->proximo = topo;
            topo = novoNo;
            return;
        }
        void remover() {
            if(topo == NULL) {
                printf("Vazia.\n");
                return;
            }
            No* removido = topo;
            topo = topo->proximo;

            int y = removido->x;

            free(removido);

            printf("%d foi tirado.\n", y);
            return;
        }
