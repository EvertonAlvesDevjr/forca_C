#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Alunos: Ana Luísa Sousa Guimarães
        Daniel Gomes Januário Júnior
        Everton Alves da Silva
        Gustavo Mateus Machado Dornelas (lider)
        Ítalo Junior Rodrigues Trindade
        Victor Gabriel Santos de Oliveira

*/

int main (){

    char palavra[16]={}, letras_chutes[7]={}, chute;
    int menu, i, y, letras, verifica[16], erros, chutes_errados, chutes_certos, vitorias=0, derrotas=0;


    do{
        for (i=0; i<16; i++){ //zera o contador verifica toda vez que entra no menu
        verifica[i]=1; //verifica e um vetor do tipo logico onde 1 e falso e 0 e verdadeiro
        }

        system ("cls");
        printf ("==Menu=============================\n");
        printf ("1 - Cadastrar Palavra\n");
        printf ("2 - Adivinhar Palavra\n");
        printf ("3 - Quantidade de vitorias/derrotas\n");
        printf ("4 - Sair\n");
        printf ("===================================\n");
        printf ("Opcao: ");
        scanf ("%d", &menu);
        fflush(stdin);

        if (menu==1){ //cadastrar palavra
            system ("cls");
            printf ("Digite uma palavra de no maximo 15 letras: ");
            gets (palavra);
            fflush(stdin);
            strupr(palavra);
        }

        if (menu==2){
            system ("cls");//limpar tela

            if (strlen(palavra)==0){ //verificar se tem palavra cadastrada
                printf ("Palavra nao cadastrada!\n");
                system ("pause");
                system ("cls");
                continue;
            }
            //continuar opção 2

            //zerar contadores
            chutes_errados=0;
            chutes_certos=0;
            letras=strlen(palavra); //verifica a quantidade de letras da palavra cadastrada

            for (y=0; y<7; y++){
                letras_chutes[y]='\0'; //zera o vetor que mostra as letras digitadas erradas
            }

            do{ //iniciar forca

                system ("cls");

                erros=0; //armazena se a letra digitada esta errada em algum ponto do vetor

                switch (chutes_errados){  //imprimir desenho da forca de acordo com a quantidade de erros

                case 0:
                    printf ("   %c%c%c%c%c", 201, 205, 205, 205, 187);
                    printf ("\n   %c   ", 186);
                    printf ("\n   %c  ", 186);
                    printf ("\n   %c   ", 186);
                    printf ("\n   %c", 186);
                    printf ("\n   %c", 186);
                    printf ("\n%c%c%c%c%c%c%c%c%c%c%c\n\n",205,205,205, 202, 205, 205, 205, 205, 205, 205, 205, 205);

                break;

                case 1:
                    printf ("   %c%c%c%c%c", 201, 205, 205, 205, 187);
                    printf ("\n   %c   O", 186);
                    printf ("\n   %c  ", 186);
                    printf ("\n   %c   ", 186);
                    printf ("\n   %c", 186);
                    printf ("\n   %c", 186);
                    printf ("\n%c%c%c%c%c%c%c%c%c%c%c\n\n",205,205,205, 202, 205, 205, 205, 205, 205, 205, 205, 205);

                break;

                case 2:
                    printf ("   %c%c%c%c%c", 201, 205, 205, 205, 187);
                    printf ("\n   %c   O", 186);
                    printf ("\n   %c   |", 186);
                    printf ("\n   %c   ", 186);
                    printf ("\n   %c", 186);
                    printf ("\n   %c", 186);
                    printf ("\n%c%c%c%c%c%c%c%c%c%c%c\n\n",205,205,205, 202, 205, 205, 205, 205, 205, 205, 205, 205);

                break;

                case 3:
                    printf ("   %c%c%c%c%c", 201, 205, 205, 205, 187);
                    printf ("\n   %c   O", 186);
                    printf ("\n   %c  /|", 186);
                    printf ("\n   %c   ", 186);
                    printf ("\n   %c", 186);
                    printf ("\n   %c", 186);
                    printf ("\n%c%c%c%c%c%c%c%c%c%c%c\n\n",205,205,205, 202, 205, 205, 205, 205, 205, 205, 205, 205);

                break;

                case 4:
                    printf ("   %c%c%c%c%c", 201, 205, 205, 205, 187);
                    printf ("\n   %c   O", 186);
                    printf ("\n   %c  /|%c ", 186, 92);
                    printf ("\n   %c   ", 186);
                    printf ("\n   %c", 186);
                    printf ("\n   %c", 186);
                    printf ("\n%c%c%c%c%c%c%c%c%c%c%c\n\n",205,205,205, 202, 205, 205, 205, 205, 205, 205, 205, 205);

                break;

                case 5:
                    printf ("   %c%c%c%c%c", 201, 205, 205, 205, 187);
                    printf ("\n   %c   O", 186);
                    printf ("\n   %c  /|%c ", 186, 92);
                    printf ("\n   %c  /", 186);
                    printf ("\n   %c", 186);
                    printf ("\n   %c", 186);
                    printf ("\n%c%c%c%c%c%c%c%c%c%c%c\n\n",205,205,205, 202, 205, 205, 205, 205, 205, 205, 205, 205);

                break;
                }

                for (i=0;i<letras;i++){ //imprimir letras da forca

                    if(verifica[i]==0){ //imprimir letras acertadas
                        printf ("%c ", palavra[i]);
                    }else{              //imprimir _ para letras nao acertadas
                        printf ("_ ");
                    }

                }

                printf ("\n\nLetras erradas digitadas: ");

                for (y=0; y<7; y++){
                    printf ("%c ", letras_chutes[y]); //mostra as letras erradas ja digitadas
                }

                printf ("\n\nDigite uma Letra: ");
                scanf ("%c", &chute); //recebe a letra chutada pelo usuario
                fflush (stdin);
                chute=toupper(chute); //strtpr não funcionou então usamos o toupper para deixar a letra em maiuscula

                for (i=0;i<letras;i++){ //percorre o vetor da palavra cadastrada

                    if (verifica[i]!=0){ //verifica se a letra chutada ja foi acertada
                        if (chute==palavra[i]){
                            verifica[i]=0;
                            chutes_certos++;
                        }
                    }
                    if(chute!=palavra[i]){ //armazena +1 sempre que uma posição do vetor ta errada.
                        erros++;
                    }
                }

                if (erros==letras){ //so vai retornar erro caso todas as posições do vetor forem erradas.
                    chutes_errados++;
                    letras_chutes[chutes_errados]=chute; //armazena a letra errada digitada num vetor com posição igual ao numero do erro
                }

            }while(chutes_errados<6 && chutes_certos<letras); //repete ate o usuario errar 6 vezes ou acertar a palavra

            system ("cls");

            if (chutes_errados==6){ //mostra mensagem de derrota para caso o usuario erre 6 vezes
                printf ("   %c%c%c%c%c", 201, 205, 205, 205, 187);
                printf ("\n   %c   O", 186);
                printf ("\n   %c  /|%c ", 186, 92);
                printf ("\n   %c  / %c ", 186, 92);
                printf ("\n   %c", 186);
                printf ("\n   %c", 186);
                printf ("\n%c%c%c%c%c%c%c%c%c%c%c\n\n",205,205,205, 202, 205, 205, 205, 205, 205, 205, 205, 205);

                printf ("\n\nLetras erradas digitadas: ");

                for (y=0; y<7; y++){
                    printf ("%c ", letras_chutes[y]);
                }

                printf ("\nDerrota!\n");
                derrotas++;
            }

            if (chutes_certos==letras){ //mostra mensagem de vitoria para caso o usuario acerte a palavra

                printf ("Vitoria!\n");
                vitorias++;
            }

            printf ("\nA palavra era: %s\n", palavra);

            system("pause");

        }

        if (menu==3){ //mostra quantas vitorias e quantas derrotas
            system ("cls");
            printf ("Vitorias: %d\nDerrotas: %d\n",vitorias, derrotas);
            system ("pause");
        }

    }while(menu!=4); //sair

return 0;
}
