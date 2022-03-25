#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAXNUMWORDS 2048
#define MAXWORDLENGTH 64

void rysowanieLudzika(int lives);
void title();
void petlaGry(char words[MAXNUMWORDS][MAXWORDLENGTH],int index,int length);
FILE* wczytywanieSlowa(int mode);

int main(){

    srand(time(NULL));
    char words[MAXNUMWORDS][MAXWORDLENGTH];
    int WordsReadIn = 0;
    int restart=1;
    char input[64];
    int mode=0; //kontrola menu
    int length;
    int index;
    int temp=0;
    

    

    while(restart==1){

        while(mode==0){//menu
        system("cls");
        title();
        printf("\t\tWitaj w grze!\n\t\t1.Graj\n\t\t2.Wyjdz\n");
            scanf("%d",&mode);
            if(mode==2)return 0;
            

            if(mode==1){
                mode=0;
                system("cls");
                title();
                printf("\t\tWybierz kategorie: \n\t\t1.Warzywa\n\t\t2.Owoce\n\t\t3.Zwierzeta\n");
                
                while(mode!=1 && mode!=2 && mode!=3){
                    scanf(" %d",&mode);
                    if(mode!=1 && mode!=2 && mode!=3)
                    printf("\t\tWpisz poprawna liczbe!\n");
                    
                }
                system("cls");
                title();
                printf("\t\tWybierz jezyk: \n\t\t1.Polski\n\t\t2.Angielski\n\t\t3.Wloski\n");
                while(temp!=1 && temp!=2 && temp!=3){
                    scanf(" %d",&temp);
                    if(temp!=1 && temp!=2 && temp!=3)
                    printf("\t\tWpisz poprawna liczbe!\n");
                }
                if(temp==1){
                    if(mode==1)mode=11;
                    else if(mode==2)mode=21;
                    else mode=31;
                }
                else if(temp==2){
                    if(mode==1)mode=12;
                    else if(mode==2)mode=22;
                    else mode=32;
                }
                else{
                    if(mode==1)mode=13;
                    else if(mode==2)mode=23;
                    else mode=3;
                }
                temp=0;
                FILE *pToFile=wczytywanieSlowa(mode);
                while(fgets(input, 63, pToFile)) {
		            sscanf(input, "%s", words[WordsReadIn]);
		            WordsReadIn++;
	            }
                index=rand()%WordsReadIn; //pozycja slowa
                length=strlen(words[index]);   
                fclose(pToFile);
                mode=1;
                system("cls");
                petlaGry(words,index,length);//PETLA GRY
                WordsReadIn=0;
                }     
            
            else if(mode==2)mode=0;
            else{ 
                printf("Wpisz poprawna liczbe!");
                mode=0;
            }
        }
             

    restart=0;

    printf("\t\t\tChcesz grac dalej? Wpisz 1 lub 0\n");
            scanf("%d",&restart);
            mode=0;   
    }

    

    return 0;
}

void rysowanieLudzika(int lives){
    system("cls");
    switch(lives){

     case 9 :
      printf("\t\t\t\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n");
     break;

     case 8 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n");
     break;

     case 7 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n");
     break;

     case 6 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n");
     break;

     case 5 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |    |\n");
      printf("\t\t\t  |    |\n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n");
     break;

     case 4 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n");
     break;

     case 3 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |\n");
      printf("\t\t\t__|_________\n");
     break;

     case 2 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |   /\n");
      printf("\t\t\t__|_________\n");
     break;

     case 1 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    O \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |   / \\\n");
      printf("\t\t\t__|_________\n");
     break;

     case 0 :
      printf("\t\t\t  _______\n");
      printf("\t\t\t  |/   | \n");
      printf("\t\t\t  |    X \n");
      printf("\t\t\t  |   \\|/\n");
      printf("\t\t\t  |    | \n");
      printf("\t\t\t  |   / \\\n");
      printf("\t\t\t__|_________\n");
     break;
    }

}
void title()
{
        printf("\t\t_ _ _ _ ____ _ ____ _    ____ ____\n"); 
        printf("\t\t| | | | [__  | |___ |    |___ |\n");    
        printf("\t\t|_|_| | ___] | |___ |___ |___ |___\n\n");
}
void petlaGry(char words[MAXNUMWORDS][MAXWORDLENGTH],int index,int length){

    int correct=0; //ilosc zgadnietych liter
    int oldCorrect;
    int quit;
    int lives=10; //pozostale zycia
    int loopIndex=0;
    char letter; // zgadniete litery   
    int guessed[8]={0,0,0,0,0,0,0,0}; //pomocnicza do sprawdzania czy litera byla zgadnieta
    char guess[16];

    while(correct<length){
        
        printf("\t\t\tPozostale zycia: %d\n\t\t\tSlowo: ",lives);

        for(loopIndex=0;loopIndex<length;loopIndex++){ //wypełnianie

            if(guessed[loopIndex]==1){
                printf("%c",words[index][loopIndex]);
            }
            else{
                printf("_ ");
            }

        } //KONIEC

        putchar('\n');
        printf("Zgadnij litere: \n");
        scanf(" %c",&guess);

        if(strncmp(guess,"quit",4)==0){ //sprawdzanie czy gracz wyszedl
            quit=1;
            break;
        }

        letter=guess[0];
        oldCorrect=correct;

        for(loopIndex=0;loopIndex<length;loopIndex++){ //SPRAWDZANIE SLOWA

            if(guessed[loopIndex]==1){
                continue;
            }
            if(letter==words[index][loopIndex]){
                guessed[loopIndex]=1;
                correct++;
            }
            
        } //KONIEC

        if(oldCorrect == correct){           
           lives--;
           rysowanieLudzika(lives);
           printf("\t\t\tZle\n");
           if(lives==0)break;
        }
        else{         
            rysowanieLudzika(lives);   
            printf("\t\t\tDobrze\n");            
        }

    } //KONIEC PETLI
    if(quit==1){
        rysowanieLudzika(lives);
        printf("\t\t\tGracz wyszedl/n");
    }
    else if(lives==0){
        rysowanieLudzika(lives);
        printf("\t\t\tPrzegrales, slowo to: %s\n",words[index]);
    }
    else{
        rysowanieLudzika(lives);
        printf("\t\t\tWygrales, slowo to: %s\n",words[index]);
    }
    return;
}
FILE* wczytywanieSlowa(int mode){

    if     (mode==11)return fopen("warzywa-polski.txt","r");   
    else if(mode==12)return fopen("warzywa-angielski.txt","r");
    else if(mode==13)return fopen("warzywa-wloski.txt","r");
    else if(mode==21)return fopen("owoce-polski.txt","r");
    else if(mode==22)return fopen("owoce-angielski.txt","r");
    else if(mode==23)return fopen("owoce-wloski.txt","r");
    else if(mode==31)return fopen("zwierzeta-polski.txt","r");
    else if(mode==32)return fopen("zwierzeta-angielski.txt","r");
    else if(mode==33)return fopen("zwierzeta-wloski.txt","r");

}