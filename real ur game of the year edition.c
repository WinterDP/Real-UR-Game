#include<stdio.h>
#include<stdlib.h>
#include<time.h>
char tabul[3][16]= {{' ',' ',' ',' ','*','_','_','_','_','_','_','_','_',' ','*',' '},
    {' ','_','_','_','_',' ',' ',' ','*',' ',' ',' ',' ','_','_','_'},
    {' ',' ',' ',' ','*','_','_','_','_','_','_','_','_',' ','*',' '}
};
char auxtabul[3][16]= {{' ',' ',' ',' ','*','_','_','_','_','_','_','_','_',' ','*',' '},
    {' ','_','_','_','_',' ',' ',' ','*',' ',' ',' ',' ','_','_','_'},
    {' ',' ',' ',' ','*','_','_','_','_','_','_','_','_',' ','*',' '}
};
char pinos[2][7]= {{'O','O','O','O','O','O','O'},
    {'X','X','X','X','X','X','X'}
};
int vez;
int pts[2]= {0,0};
int pecas[7][2];
int casas[16][2]= {{-1,-1},{0,3},{0,2},{0,1},{0,0},{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{0,7},{0,6},{0,5}
};
void menu();
void inicia()
{
    int i,j,n;
    for(i=0; i<7; i++)
    {
        pecas[i][0]=0;
        pecas[i][1]=0;
    }
}
void imptabu()
{
    int i,j;
    printf("1:[");
    for (i=0; i<7; i++)
    {
        printf("%c ",pinos[0][i]);
    }
    printf("]");
    printf("\n\n");
    for (i=0; i<8; i++)
    {
        printf("  %d ",i+1);
    }
    printf("\n1");
    for (i=4; i>=0; i--)
    {
        if(i==0)
        {
            printf("    ");
        }
        else
        {
            printf("[%c] ",tabul[0][i]);
        }
    }
    for (i=15; i>=13; i--)
    {
        if(i==15)
        {
            printf("    ");
        }
        else
        {
            printf("[%c] ",tabul[0][i]);
        }
    }
    printf("\n2");
    for(i=5; i<13; i++)
    {
        printf("[%c] ",tabul[1][i]);
    }
    printf("\n3");
    for (i=4; i>=0; i--)
    {
        if(i==0)
        {
            printf("    ");
        }
        else
        {
            printf("[%c] ",tabul[2][i]);
        }
    }
    for (i=15; i>=13; i--)
    {
        if(i==15)
        {
            printf("    ");
        }
        else
        {
            printf("[%c] ",tabul[2][i]);
        }
    }
    printf("\n\n");
    printf("2:[");
    for (i=0; i<7; i++)
    {
        printf("%c ",pinos[1][i]);
    }
    printf("]");
}
int dados()
{
    int d;
    d=rand()%2+rand()%2+rand()%2+rand()%2;
    if (d==0)
    {
        d=4;
    }
    return d;
}
int proxvez()
{
    if(vez==1)
    {
        vez=2;
    }
    else
    {
        vez=1;
    }
}
int verijogpos(int d, int linha,char pinoini)
{
    int lin,i;
    for(i=0; i<7; i++)
    {
        if(pecas[i][vez-1]+d<16)
        {
            if(pecas[i][vez-1]+d<5 || pecas[i][vez-1]+d>12)
            {
                lin=linha;
                if (tabul[lin][pecas[i][vez-1]+d]==' ' || tabul[lin][pecas[i][vez-1]+d]=='*' )
                {
                    return 1;
                }
            }
            else
                lin=1;
            if (tabul[lin][pecas[i][vez-1]+d]==' ' || tabul[lin][pecas[i][vez-1]+d]=='*' )
            {
                return 1;
            }
            else if (tabul[lin][pecas[i][vez-1]+d]==pinoini && pecas[i][vez-1]+d!=8)
            {
                return 1;
            }
        }
    }
    if(i==7)
    {
        return 0;
    }
}
int veripecafora()
{
    int i;
    for(i=0; i<7; i++)
    {
        if(pecas[i][vez-1]==0)
        {
            break;
        }
    }
    if(i<7)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void jogada()
{
    int i,j,n,d,lin,col,linha,z,b=1;
    char resp,pino,pinoini;
    if (vez==1)
    {
        pino='O';
        pinoini='X';
        linha=0;
        z=1;
    }
    else
    {
        pino='X';
        pinoini='O';
        linha=2;
        z=0;
    }
    printf("\n\nvez do jogador %d\n\n",vez);
    printf("jogue os dados");
    getchar();
    getchar();
    d=dados();
    printf("o jogador tirou %d\n\n",d);
    for(i=0; i<7; i++)
    {
        if(pinos[vez-1][i]=='-')
        {
            break;
        }
    }
    if(i==7)
    {
        printf("qual peca deseja mover? ");
        scanf("%s",&resp);
        n=resp-48;
        while(n<1 || n>7)
        {
            getchar();
            printf("digite um numero de 1 a 7\n");
            printf("qual peca deseja mover? ");
            scanf("%s",&resp);
            n=resp-48;
        }
        n--;
        if (tabul[linha][pecas[n][vez-1]+d]=='*')
        {
            tabul[linha][pecas[n][vez-1]+d]=pino;
            pinos[vez-1][n]='-';
            pecas[n][vez-1]=pecas[n][vez-1]+d;
            return;
        }
        else
        {
            tabul[linha][pecas[n][vez-1]+d]=pino;
            pinos[vez-1][n]='-';
            pecas[n][vez-1]=pecas[n][vez-1]+d;
            proxvez();
            return;
        }
    }
    if(verijogpos(d,linha,pinoini)==0)
    {
        printf("nao existem jogadas possiveis");
        getchar();
        getchar();
        proxvez();
        return;
    }
    while(b==1)
    {
        if(veripecafora()==1)
        {
            printf("deseja colocar uma peca (s)/(n) ");
            scanf("%s",&resp);
            getchar();
        }
        if(resp!='s' && resp!='n')
        {
            b=1;
        }
        else if(resp=='s')
        {
            printf("qual peca deseja mover ");
            scanf("%s",&resp);
            n=resp-48;
            if(n<1 || n>7)
            {
                printf("digite um numero de 1 a 7\n");
                getchar();
                b=1;
            }
            else
                n--;
            if(pinos[vez-1][n]=='-')
            {
                printf("peca ja esta no tabuleiro \n");
                getchar();
                getchar();
                b=1;
            }
            else if (tabul[linha][pecas[n][vez-1]+d]=='*')
            {
                tabul[linha][pecas[n][vez-1]+d]=pino;
                pinos[vez-1][n]='-';
                pecas[n][vez-1]=pecas[n][vez-1]+d;
                return;
            }
            else if(tabul[linha][pecas[n][vez-1]+d]==pino)
            {
                printf("\nmovimento nao e possivel\n");
                printf("\nja existe uma peca no local\n");
                getchar();
                getchar();
                b=1;
            }
            else
            {
                tabul[linha][pecas[n][vez-1]+d]=pino;
                pinos[vez-1][n]='-';
                pecas[n][vez-1]=pecas[n][vez-1]+d;
                proxvez();
                return;
            }
        }
        else
        {
            printf("digite a linha da peca que deseja mover ");
            scanf("%s",&resp);
            lin=resp-48;
            printf("digite a coluna da peca que deseja mover ");
            scanf("%s",&resp);
            col=resp-48;
            lin--;
            col--;
            for(i=0; i<16; i++)
            {
                if(lin!=1)
                {
                    if(casas[i][0]==0 && casas[i][1]==col)
                    {
                        break;
                    }
                }
                else
                {
                    if(casas[i][0]==1 && casas[i][1]==col)
                    {
                        break;
                    }
                }
            }
            col=i;
            for(i=0; i<7; i++)
            {
                if(pecas[i][vez-1]==col)
                {
                    n=i;
                }
            }
            if(tabul[lin][col]!=pino)
            {
                printf("\nmovimento nao e possivel\n");
                printf("nao existe peca do jogador %d nessa casa\n",vez);
                getchar();
                getchar();
                b=1;
            }
            else if(col+d<5 || col+d>12)
            {
                if(col+d>15)
                {
                    printf("\nmovimento nao e possivel\n");
                    printf("e necessario tirar o numero exato\n");
                    getchar();
                    getchar();
                    b=1;
                }
                else if(col+d==15)
                {
                    pts[vez-1]++;
                    tabul[lin][col]=auxtabul[lin][col];
                    printf("a peca foi retirada o jogador %d tem %d peca(s) fora do tabuleiro",vez,pts[vez-1]);
                    getchar();
                    getchar();
                    proxvez();
                    b=0;
                }
                else if(tabul[linha][col+d]==' ')
                {
                    tabul[linha][col+d]=pino;
                    tabul[lin][col]=auxtabul[lin][col];
                    pecas[n][vez-1]=col+d;
                    proxvez();
                    b=0;
                }
                else if(tabul[linha][col+d]=='*')
                {
                    tabul[linha][col+d]=pino;
                    tabul[lin][col]=auxtabul[lin][col];
                    pecas[n][vez-1]=col+d;
                    b=0;
                }
                else if(tabul[linha][col+d]==pino)
                {
                    printf("\nmovimento nao e possivel\n");
                    printf("\nja existe uma peca no local\n");
                    getchar();
                    getchar();
                    b=1;
                }
            }
            else if(tabul[1][col+d]==' ')
            {
                tabul[1][col+d]=pino;
                tabul[lin][col]=auxtabul[lin][col];
                pecas[n][vez-1]=col+d;
                proxvez();
                b=0;
            }
            else if(tabul[1][col+d]=='*')
            {
                tabul[1][col+d]=pino;
                tabul[lin][col]=auxtabul[lin][col];
                pecas[n][vez-1]=col+d;
                b=0;
            }
            else if(tabul[1][col+d]==pino)
            {
                printf("\nmovimento nao e possivel\n");
                printf("\nja existe uma peca no local\n");
                getchar();
                getchar();
                b=1;
            }
            else if(tabul[1][col+d]==pinoini)
            {
                if(col+d==8)
                {
                    printf("\nmovimento nao e possivel\n");
                    printf("\na peca esta protegida\n");
                    getchar();
                    getchar();
                    b=1;
                }
                else
                {
                    tabul[1][col+d]=pino;
                    tabul[lin][col]=auxtabul[lin][col];
                    pecas[n][vez-1]=col+d;
                    for(i=0; i<7; i++)
                    {
                        if(pecas[i][z]==col+d)
                        {
                            pinos[z][i]=pinoini;
                            pecas[i][z]=0;
                        }
                    }
                    proxvez();
                    b=0;
                }
            }
        }
    }
    return;
}
void jogo(){
int d1=0,d2=0;
    inicia();
    system("cls");
    while(d1==d2)
    {
        printf("jogador 1 jogue os dados");
        getchar();
        getchar();
        d1=dados();
        printf("o jogador tirou %d\n",d1);
        printf("jogador 2 jogue os dados");
        getchar();
        d2=dados();
        printf("o jogador tirou %d\n",d2);
        if(d1==d2)
        {
            printf("o numero dos dados foram iguais e necessario jogar novamente\n\n");
        }
    }
    if(d1>d2)
    {
        vez=1;
    }
    else
    {
        vez=2;
    }
    printf("\njogador %d comeca\n ",vez);
    getchar();
    while(vez>0 && pts[0]!=7 && pts[1]!=7)
    {
        system("cls");
        printf("   1:0%d X 0%d:2\n\n",pts[0],pts[1]);
        imptabu();
        jogada();
    }
    proxvez();
    printf("\no jogador %d venceu!!!",vez);
    getchar();
    getchar();
    menu();
}
void menu(){
    char resp;
system("cls");
printf("comecar o jogo(a)\nsair(b)\n");
scanf("%s",&resp);
while(resp!='a' && resp!='b'){
printf("comecar o jogo(a)\nsair(b)\n");
scanf("%s",&resp);
}
switch(resp){
case 'a':
    jogo();
    break;
case 'b':
    break;
default:
    printf("opcao nao existe");
    break;
}
}
int main (int argc,char*argv[])
{
    srand(time(NULL));
    printf(" made by jao corps(c) ");
    getchar();
    menu();
    return 0;
}
