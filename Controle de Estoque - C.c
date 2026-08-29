#include <stdio.h>

// 5 produtos e 7 dias da semana
int mat[5][7]; // matriz do estoque
int op;
int i, j; // variaveis pra rodar o for 
int total; // guardar as somas aqui
int maior, quem;
int limite;

int main() {

    // looping pro menu ficar repetindo ate a pessoa cansar e digitar 0
    do {
        printf("\n========================================\n");
        printf("     SISTEMA DE CONTROLE DE ESTOQUE\n");
        printf("========================================\n");
        printf("1- Cadastrar estoque\n");
        printf("2- Exibir estoque\n");
        printf("3 - Calcular estoque total por produto\n");
        printf("4- Calcular estoque total por dia\n");
        printf("5- Encontrar produto com maior estoque\n");
        printf("6- Encontrar dia com maior estoque\n");
        printf("7 - Verificar produtos com estoque baixo\n");
        printf("0 - Sair\n");
        printf("========================================\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        if (op == 1) {
            // hora de preencher tudo na marra
            printf("\n--- CADASTRANDO TUDO ---\n");
            for(i = 0; i < 5; i++) {
                printf("\nProduto %d:\n", i + 1); // +1 pq pro usuario nao existe produto zero 
                for(j = 0; j < 7; j++) {
                    // preguica de fazer vetor de texto, vai no switch msm
                    if(j == 0) printf("Segunda: ");
                    if(j == 1) printf("Terca: ");
                    if(j == 2) printf("Quarta: ");
                    if(j == 3) printf("Quinta: ");
                    if(j == 4) printf("Sexta: ");
                    if(j == 5) printf("Sabado: ");
                    if(j == 6) printf("Domingo: ");
                    scanf("%d", &mat[i][j]); // salva na matriz
                }
            }
            printf("\nSalvo com sucesso, acho eu!\n");
        }
        else if (op == 2) {
            // printando a matriz na tela com espaco
            printf("\n| Seg\tTer\tQua\tQui\tSex\tSab\tDom\n");
            for(i = 0; i < 5; i++) {
                printf("Produto %d | ", i + 1);
                for(j = 0; j < 7; j++) {
                    printf("%d\t", mat[i][j]);
                }
                printf("\n"); // pula a linha do produto
            }
        }
        else if (op == 3) {
            // somando linha por linha (produtos)
            printf("\n--- TOTAL POR PRODUTO ---\n");
            for(i = 0; i < 5; i++) {
                total = 0; // zera senao vai acumulando tudo errado
                for(j = 0; j < 7; j++) {
                    total = total + mat[i][j];
                }
                printf("Produto %d: %d unidades\n", i + 1, total);
            }
        }
        else if (op == 4) {
            // somando coluna por coluna (dias)
            printf("\n--- TOTAL POR DIA ---\n");
            for(j = 0; j < 7; j++) {
                total = 0; // zera de novo
                for(i = 0; i < 5; i++) {
                    total = total + mat[i][j];
                }
                // printando o dia na mao
                if(j == 0) printf("Segunda: %d unidades\n", total);
                if(j == 1) printf("Terca: %d unidades\n", total);
                if(j == 2) printf("Quarta: %d unidades\n", total);
                if(j == 3) printf("Quinta: %d unidades\n", total);
                if(j == 4) printf("Sexta: %d unidades\n", total);
                if(j == 5) printf("Sabado: %d unidades\n", total);
                if(j == 6) printf("Domingo: %d unidades\n", total);
            }
        }
        else if (op == 5) {
            // achar o maior produto
            maior = -1; // comeca bem baixo pra qualquer um ganhar
            quem = 0;
            for(i = 0; i < 5; i++) {
                total = 0;
                for(j = 0; j < 7; j++) {
                    total = total + mat[i][j];
                }
                // se esse for maior que o antigo campeao, ele ganha
                if (total > maior) {
                    maior = total;
                    quem = i + 1; // salva o numero do produto
                }
            }
            printf("\nProduto com maior estoque:\nProduto %d\nQuantidade total:\n%d unidades\n", quem, maior);
        }
        else if (op == 6) {
            // achar o maior dia da semana
            maior = -1;
            quem = 0;
            for(j = 0; j < 7; j++) {
                total = 0;
                for(i = 0; i < 5; i++) {
                    total = total + mat[i][j];
                }
                if (total > maior) {
                    maior = total;
                    quem = j; // guarda o dia
                }
            }
            printf("\nDia com maior estoque:\n");
            if(quem == 0) printf("Segunda-feira\n");
            if(quem == 1) printf("Terca-feira\n");
            if(quem == 2) printf("Quarta-feira\n");
            if(quem == 3) printf("Quinta-feira\n");
            if(quem == 4) printf("Sexta-feira\n");
            if(quem == 5) printf("Sabado\n");
            if(quem == 6) printf("Domingo\n");
            printf("Quantidade:\n%d unidades\n", maior);
        }
        else if (op == 7) {
            // checar quem ta acabando
            printf("\nInforme o limite de estoque: ");
            scanf("%d", &limite);
            printf("\nALERTA DE ESTOQUE\n");
            for(i = 0; i < 5; i++) {
                for(j = 0; j < 7; j++) {
                    // se for menor ou igual o limite que digitou
                    if (mat[i][j] <= limite) {
                        printf("Produto %d - ", i + 1);
                        if(j == 0) printf("Segunda: ");
                        if(j == 1) printf("Terca: ");
                        if(j == 2) printf("Quarta: ");
                        if(j == 3) printf("Quinta: ");
                        if(j == 4) printf("Sexta: ");
                        if(j == 5) printf("Sabado: ");
                        if(j == 6) printf("Domingo: ");
                        printf("%d unidades\n", mat[i][j]);
                    }
                }
            }
        }
        else if (op == 0) {
            printf("\nSaindo... vlw flw!\n");
        }
        else {
            printf("\nOpcao errada amigo, tenta de novo!\n");
        }

    } while (op != 0); // fica aqui ate digitar 0

    return 0;
}