//-------LIBRAIRIES-------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#include <math.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
//----VARIABLE GLOBALE-------
#define TAILLE 1300
#define TAILLE_INVENTAIRE 34
char tab_futur[TAILLE][TAILLE] = {{' '}};
char tab_neser[TAILLE][TAILLE] = {{' '}};

#define ARROW_UP        72
#define ARROW_DOWN      80
#define ARROW_LEFT      75
#define ARROW_RIGHT     77
//------INITIALISATION FONCTION-------------
int main();
void continue_playing();
int protect_bug ();
void affiche_regle();
int cheat(char tab[TAILLE][TAILLE]);
void affiche_equipement(char tab[TAILLE][TAILLE],  int inventaire[TAILLE_INVENTAIRE], int equipement[14]);
void affiche_inventaire(char tab[TAILLE][TAILLE], int inventaire[TAILLE_INVENTAIRE], boolean four);
void affiche_tab(char tab[TAILLE][TAILLE], int col_player, int lig_player, float temps);
void init_tab(char tab[TAILLE][TAILLE]);
void mouvement(char tab[TAILLE][TAILLE], int col, int lig, int inventaire[TAILLE_INVENTAIRE], int equipement[14], int construction[8], int t1, int t2, float temps, boolean four, int life, int col_origine, int lig_origine, int game_over);
int jeu_exploration(char tab[TAILLE][TAILLE], int life, int resistance);
#include "continue_playing.h"
#include "protect_bug.h"
//--------FONCTION---------------
void affiche_regle(){
    int choix_chapitre = 99;
    system("cls");
    printf("-----------AIDE---------\n");
    printf("INDEX : \n");
    printf("I  - deplacement\n");
    printf("II - inventaire\n");
    printf("III- construction\n");
    printf("IV - equipement\n");
    printf("V - construction de base\n");
    printf("\nquel chapitre ? (9 pour quitter)");
    choix_chapitre = protect_bug();
    if(choix_chapitre == 1){
        system("cls");
        printf("----------I DEPLACEMENT----------\n");
        printf("Pour vous deplacer, utilisez les fleches directionelles.\n");
        printf("Pour miner ou couper des arbres, vous devez uilisez la touche espace. Vous ne pouvez miner que vers\n");
        printf("l'avant sans equipement. Vous ne pouvez pas marcher sur l'ocean ou sur des pierres sans equipement approprier\n");
        printf("Le jour et la nuit on lieu toutes les 2,08333 minutes environs.\n");
        int c = getch();
        affiche_regle();
    }
    if(choix_chapitre == 2){
        system("cls");
        printf("----------II INVENTAIRE----------\n");
        printf("En appuyant sur la touche i, vous pouvez ouvrir l'inventaire.\n");
        printf("L'inventaire vous renseigne sur le nombre d'objets dans votre sac.\n");
        printf("Les objets tels que les pioches et autres, sont retires du sac quand vous les equipers.\n");
        int c = getch();
        affiche_regle();
    }
    if(choix_chapitre == 3){
        system("cls");
        printf("----------III CONSTRUCTION----------\n");
        printf("Pour aller dans le menu de construction, aller dans l'inventaire.");
        printf("Ensuite, vous devez appuyez sur la touche espace.\n");
        printf("Le menu de construction vous permet de construire differents objets tels que des armes, des outils,\n");
        printf("des armures et autres utilitaires. \n");
        printf("vous devez etre munis des ressources necessaires pour construire un objet. Le plan de construction\n");
        printf("est devoiler quand vous avez assez de ressource pour construire l'objet. Pour construire un objet, \n");
        printf("vous devez appuyez sur la touche indiquer. Par exemple, pour construire une pioche en bois 'p',\n");
        printf("vous devez appuyer sur la touche 'p'\n");
        printf("Certains objets sont craftables uniquement en se situant  proximiter d'un outil\n");
        printf("Par exemple, pour construire des lingots(fer, or,...), vous devez etre a coter d'un four\n");
        int c = getch();
        affiche_regle();
    }
    if(choix_chapitre == 4){
        system("cls");
        printf("----------IV EQUIPEMENT----------\n");
        printf("Pour ouvrir le menu equipement, appuyez sur la touche 'e'. A cote de chaque emplacement\n");
        printf("il y a le nom des objets que vous pouvez vous equiper. Pour vous equiper d'un objet,\n");
        printf("vous devez ecrire le nom de l'objet indiquer entre parenthese.\n");
        printf("Par exemple , pour construire la pioche en bois(piocheb), ecrivez : piocheb\n");
        printf("L'item equipe figurera toujours dans l'inventaire. Une fois equiper, vous ne \n");
        printf("pouvez vous en desequiper uniquement en vous equipant d'un autre objet de la \n");
        printf("meme classe\n");
        int c = getch();
        affiche_regle();
    }
    if(choix_chapitre == 4){
        system("cls");
        printf("----------V CONSTRUCTION DE BASE----------\n");
        printf("\n");

        int c = getch();
        affiche_regle();
    }
}
void affiche_hp(int life){
    for(int i = 0 ; i < life ; i++){
        printf("\033[2;32m|\033[0m");
    }
    printf("\n");
}
void affiche_resistance(int resistance){
    for(int i = 0 ; i < resistance ; i++){
        printf("\033[2;33m|\033[0m");
    }
    printf("\n");
}

int cheat(char tab[TAILLE][TAILLE]){
    char cheat[] = {0};
    char cheat_tp[] = "london";
    char cheat_objet[] = "oslo";
    char cheat_life[] = "paris";
    int i =5;
    int j = 0;
    printf("_______________CHEAT CODE____________\n");
    printf("|     ENTREZ LE CHEAT :              |\n");
    printf("|                                    |\n");
    printf("|                                    |\n");
    printf("|                                    |\n");
    printf("|____________________________________|\n");
    while((cheat != "oslo")&&(cheat != "londre") &&(i!= 0)&&(cheat != "paris")){
        scanf("%s", &cheat);
        if(strcmp(cheat, cheat_tp) == 0){
            printf("VALIDE\n");
            
            j = 1;
            break;
        }
        if(strcmp(cheat, cheat_objet) == 0){
            printf("VALIDE\n");
            
            j = 2;
            break;
        }
        if(strcmp(cheat, cheat_life) == 0){
            printf("VALIDE\n");
            j = 3;
            break;
        }
        else{
            printf("FAUX (plus que %d essais)\n", i);
        }
        i--;
    }
    return j;
}
boolean verification(int col, int lin, int COL, int LIN, char tab[COL][LIN]) { 
  int imin = -6;
  int jmin = -6;
  int imax = 6;
  int jmax = 6;
  for (int i = imin; i < imax; i++) { 
    for (int j = jmin; j < jmax; j++) {
      if (tab[col + i][lin + j] == 'J') {
        return TRUE;
      }
    }
  }
  return FALSE;
}
void affiche_construction(char tab[TAILLE][TAILLE],  int inventaire[TAILLE_INVENTAIRE], int construction[8]){
    printf("______CHOIX MATERIAU DE CONSTRUCTION____\n");
    if(inventaire[4] > 0){
        printf("| 1 planche : %d\n", inventaire[4]);
    }
    if(inventaire[12] > 0){
        printf("| 2 four : %d\n", inventaire[12]);
    }
    int choix = 0;
    choix = protect_bug();
    if((choix == 1)&&(inventaire[4] > 0)){
        construction[1]=1;
        construction[2]= 0;
    }
    if((choix == 2)&&(inventaire[12] > 0)){
        construction[1]=0;
        construction[2]= 1;
    }

}
void affiche_equipement(char tab[TAILLE][TAILLE],  int inventaire[TAILLE_INVENTAIRE], int equipement[14]){
    printf("_____EQUIPEMENT___\n");
    printf("casque : ");
    if(equipement[5] == 1){
        printf("\033[1;31m casque en bois \033[0m");
    }
    if(equipement[6] == 1){
        printf("\033[1;31m casque en fer \033[0m");
    }
    if(equipement[7] == 1){
        printf("\033[1;31m casque en or \033[0m");
    }
    if(inventaire[18] > 0){
        printf(" \033[0;34m%d\033[0m : casque en bois (casqueb) | ", inventaire[18]);
    }
    if(inventaire[19] > 0){
        printf(" \033[0;34m%d\033[0m : casque en fer (casquef) | ", inventaire[19]);
    }
    if(inventaire[20] > 0){
        printf(" \033[0;34m%d\033[0m : casque en or (casqueo) | ", inventaire[20]);
    }
    
    printf("\nplastron : ");
    if(equipement[8] == 1){
        printf("\033[1;31m plastron en bois \033[0m");
    }
    if(equipement[9] == 1){
        printf("\033[1;31m plastron en fer \033[0m");
    }
    if(equipement[10] == 1){
        printf("\033[1;31m plastron en or \033[0m");
    }
    if(inventaire[21] > 0){
        printf(" \033[0;34m%d\033[0m : plastron en bois (plastronb) | ", inventaire[21]);
    }
    if(inventaire[22] > 0){
        printf(" \033[0;34m%d\033[0m : plastron en fer (plastronf) | ", inventaire[22]);
    }
    if(inventaire[23] > 0){
        printf(" \033[0;34m%d\033[0m : plastron en or (plastrono) | ", inventaire[23]);
    }
    printf("\njambiere : ");
    if(equipement[11] == 1){
        printf("\033[1;31m bottes en bois \033[0m");
    }
    if(equipement[12] == 1){
        printf("\033[1;31m bottes en fer \033[0m");
    }
    if(equipement[13] == 1){
        printf("\033[1;31m bottes en or \033[0m");
    }
    if(inventaire[24] > 0){
        printf(" \033[0;34m%d\033[0m : bottes en bois (bottesb) | ", inventaire[24]);
    }
    if(inventaire[25] > 0){
        printf(" \033[0;34m%d\033[0m : bottes en fer (bottesf) | ", inventaire[25]);
    }
    if(inventaire[26] > 0){
        printf(" \033[0;34m%d\033[0m : bottes en or (botteso) | ", inventaire[26]);
    }
    printf("\narme : ");
    if(equipement[1] == 1){
        printf("\033[1;31m pioche en bois \033[0m");
    }
    if(equipement[2] == 1){
        printf("\033[1;31m pioche en pierre \033[0m");
    }
    if(equipement[3] == 1){
        printf("\033[1;31m pioche en fer \033[0m");
    }
    if(equipement[4] == 1){
        printf("\033[1;31m pioche en or \033[0m");
    }
    if(inventaire[5] > 0){
        printf(" \033[0;34m%d\033[0m : pioche en bois (piocheb) |", inventaire[5]);
    }
    if(inventaire[8] > 0){
        printf(" \033[0;34m%d\033[0m : pioche en pierre (piochep) | ", inventaire[8]);
    }
    if(inventaire[16] > 0){
        printf(" \033[0;34m%d\033[0m : pioche en fer (piochef) |", inventaire[16]);
    }
    if(inventaire[17] > 0){
        printf(" \033[0;34m%d\033[0m : pioche en or (piocheo) | ", inventaire[17]);
    }
    //afiche casque
    if(equipement[5] == 1){
        printf("\n\033[0;32m  ____ \033[0m\n");
        printf("\033[0;32m |    |\033[0m\n");
        printf("\033[0;32m | oo |\033[0m\n");
        printf("\033[0;32m  |  |\033[0m\n");
        printf("\033[0;32m   --\033[0m\n");
        printf("\n");
        
    }
    if(equipement[6] == 1){
        printf("\n\033[0;37m  ____ \033[0m\n");
        printf("\033[0;37m |    |\033[0m\n");
        printf("\033[0;37m | oo |\033[0m\n");
        printf("\033[0;37m  |  |\033[0m\n");
        printf("\033[0;37m   --\033[0m\n");
        printf("\n");
        
    }
    if(equipement[7] == 1){
        printf("\n\033[0;33m  ____ \033[0m\n");
        printf("\033[0;33m |    |\033[0m\n");
        printf("\033[0;33m | oo |\033[0m\n");
        printf("\033[0;33m  |  |\033[0m\n");
        printf("\033[0;33m   --\033[0m\n");
        printf("\n");
    }
    //affiche plastron
    if(equipement[8] == 1){
        printf("\033[0;32m __   __\033[0m\n");
        printf("\033[0;32m| |   | |\033[0m\n");
        printf("\033[0;32m| |   | |\033[0m\n");
        printf("\033[0;32m -|   |-\033[0m\n");
        printf("\033[0;32m   ---\033[0m\n");
        printf("\n");
    }
    if(equipement[9] == 1){
        printf("\033[0;37m __   __\033[0m\n");
        printf("\033[0;37m| |   | |\033[0m\n");
        printf("\033[0;37m| |   | |\033[0m\n");
        printf("\033[0;37m -|   |-\033[0m\n");
        printf("\033[0;37m   ---\033[0m\n");
        printf("\n");
    }
    if(equipement[10] == 1){
        printf("\033[0;33m __   __\033[0m\n");
        printf("\033[0;33m| |   | |\033[0m\n");
        printf("\033[0;33m| |   | |\033[0m\n");
        printf("\033[0;33m -|   |-\033[0m\n");
        printf("\033[0;33m   ---\033[0m\n");
        printf("\n");
    }
    //afiche jambiere
    if(equipement[11] == 1){
        printf("\033[0;32m  ___\033[0m\n");
        printf("\033[0;32m | | |\033[0m\n");
        printf("\033[0;32m | | |\033[0m\n");
        printf("\033[0;32m|__|__|\033[0m\n");
        printf("\n");
    }
    if(equipement[12] == 1){
        printf("\033[0;37m  ___\033[0m\n");
        printf("\033[0;37m | | |\033[0m\n");
        printf("\033[0;37m | | |\033[0m\n");
        printf("\033[0;37m|__|__|\033[0m\n");
        printf("\n");
    }
    if(equipement[13] == 1){
        printf("\033[0;33m  ___\033[0m\n");
        printf("\033[0;33m | | |\033[0m\n");
        printf("\033[0;33m | | |\033[0m\n");
        printf("\033[0;33m|__|__|\033[0m\n");
        printf("\n");
    }
    if(equipement[4] == 1){
        printf("\n\033[0;33m    *** \033[0m\n");
        printf("\033[0;33m ********\033[0m\n");
        printf("    /    \033[0;33m*\033[0m\n");
        printf("   /\n");
        printf("  /");
    }
    if(equipement[3] == 1){
        printf("\n    *** \n");
        printf(" ********\n");
        printf("    /    *\n");
        printf("   /\n");
        printf("  /");
    }
    if(equipement[2] == 1){
        printf("\n\033[1;30m    *** \033[0m\n");
        printf("\033[1;30m ********\033[0m\n");
        printf("    /    \033[1;30m*\033[0m\n");
        printf("   /\n");
        printf("  /");
    }
    if(equipement[1] == 1){
        printf("\n\033[0;32m    *** \033[0m\n");
        printf("\033[0;32m ********\033[0m\n");
        printf("    /    \033[0;32m*\033[0m\n");
        printf("   /\n");
        printf("  /");
    }
    printf("\nDE QUOI VOULEZ VOUS VOUS EQUIPEZ ?(entrez le nom de l'item)");
    char nom_item[] = {0};
    char pioche[] = "piocheb";
    char pioche_pierre[] = "piochep";
    char pioche_fer[] = "piochef";
    char pioche_or[] = "piocheo";
    char casque_bois[] = "casqueb";
    char casque_fer[] = "casquef";
    char casque_or[] = "casqueo";
    char plastron_bois[] = "plastronb";
    char plastron_fer[] = "plastronf";
    char plastron_or[] = "plastrono";
    char bottes_bois[] = "bottesb";
    char bottes_fer[] = "bottesf";
    char bottes_or[] = "botteso";
    scanf("%s", &nom_item);
    if((strcmp(nom_item, pioche) == 0) && (inventaire[5] > 0)){
        printf("pioche en bois equipe\n");
        sleep(3);
        //AJOUTER L EQUIPEMENT
        equipement[3] = 0;
        equipement[4] = 0;
        equipement[2] = 0;
        equipement[1] = 1;//ENLEVER LES AUTRES EQUIPEMENTS DEJA EQUIPE

    }
    //EQUIPEMENT
    if((strcmp(nom_item, pioche_pierre) == 0) &&( inventaire[8] > 0)){
        printf("pioche en pierre equipe\n");
        sleep(3);
        equipement[3] = 0;
        equipement[4] = 0;
        equipement[2] = 1;
        equipement[1] = 0;
        

    }
    if((strcmp(nom_item, pioche_fer) == 0) &&( inventaire[16] > 0)){
        printf("pioche en fer equipe\n");
        sleep(3);
        equipement[3] = 1;
        equipement[4] = 0;
        equipement[2] = 0;
        equipement[1] = 0;
    }
    if((strcmp(nom_item, pioche_or) == 0) &&( inventaire[17] > 0)){
        printf("pioche en or equipe\n");
        sleep(3);
        equipement[3] = 0;
        equipement[4] = 1;
        equipement[2] = 0;
        equipement[1] = 0;
    }
    //CASQUE
    if((strcmp(nom_item, casque_bois) == 0) &&( inventaire[18] > 0)){
        printf("casque en bois equipe\n");
        sleep(3);
        equipement[5] = 1;
        equipement[6] = 0;
        equipement[7] = 0;
    }
    if((strcmp(nom_item, casque_fer) == 0) &&( inventaire[19] > 0)){
        printf("casque en fer equipe\n");
        sleep(3);
        equipement[5] = 0;
        equipement[6] = 1;
        equipement[7] = 0;
    }
    if((strcmp(nom_item, casque_or) == 0) &&( inventaire[20] > 0)){
        printf("casque en or equipe\n");
        sleep(3);
        equipement[5] = 0;
        equipement[6] = 0;
        equipement[7] = 1;
    }
    //PLASTRON
    if((strcmp(nom_item, plastron_bois) == 0) &&( inventaire[21] > 0)){
        printf("plastron en bois equipe\n");
        sleep(3);
        equipement[8] = 1;
        equipement[9] = 0;
        equipement[10] = 0;
    }
    if((strcmp(nom_item, plastron_fer) == 0) &&( inventaire[22] > 0)){
        printf("plastron en fer equipe\n");
        sleep(3);
        equipement[8] = 0;
        equipement[9] = 1;
        equipement[10] = 0;
    }
    if((strcmp(nom_item, plastron_or) == 0) &&( inventaire[23] > 0)){
        printf("plastron en or equipe\n");
        sleep(3);
        equipement[8] = 0;
        equipement[9] = 0;
        equipement[10] = 1;
    }
    //BOTTES
    if((strcmp(nom_item, bottes_bois) == 0) &&( inventaire[24] > 0)){
        printf("bottes en bois equipe\n");
        sleep(3);
        equipement[11] = 1;
        equipement[12] = 0;
        equipement[13] = 0;
    }
    if((strcmp(nom_item, bottes_fer) == 0) &&( inventaire[25] > 0)){
        printf("bottes en fer equipe\n");
        sleep(3);
        equipement[11] = 0;
        equipement[12] = 1;
        equipement[13] = 0;
    }
    if((strcmp(nom_item, bottes_or) == 0) &&( inventaire[26] > 0)){
        printf("bottes en or equipe\n");
        sleep(3);
        equipement[11] = 0;
        equipement[12] = 0;
        equipement[13] = 1;
    }
    int c = getch();
    
}

void affiche_inventaire(char tab[TAILLE][TAILLE], int inventaire[TAILLE_INVENTAIRE], boolean four){
    printf(" ______INVENTAIRE_____\n");
    printf("|                     \n");
    if(inventaire[1] > 0){
        printf("| bois : %d\n", inventaire[1]);
    }
    if(inventaire[2] > 0){
        printf("| gland : %d\n", inventaire[2]);
    }
    if(inventaire[3] > 0){
        printf("| gland d'or : %d\n", inventaire[3]);
    }
    if(inventaire[4] > 0){
        printf("| planche : %d\n", inventaire[4]);
    }
    if(inventaire[5] > 0){
        printf("| pioche en bois : %d\n", inventaire[5]);
    }
    if(inventaire[6] > 0){
        printf("| pierre : %d\n", inventaire[6]);
    }
    if(inventaire[7] > 0){
        printf("| minerai de fer : %d\n", inventaire[7]);
    }
    if(inventaire[8] > 0){
        printf("| pioche en pierre : %d\n", inventaire[8]);
    }
    if(inventaire[9] > 0){
        printf("| or : %d\n", inventaire[9]);
    }
    if(inventaire[10] > 0){
        printf("| diamant : %d\n", inventaire[10]);
    }
    if(inventaire[11] > 0){
        printf("| coeur de pierre : %d\n", inventaire[11]);
    }
    if(inventaire[12] > 0){
        printf("| four : %d\n", inventaire[12]);
    }
    if(inventaire[13] > 0){
        printf("| pierre de lune : %d\n", inventaire[13]);
    }
    if(inventaire[14] > 0){
        printf("| lingot de fer : %d\n", inventaire[14]);
    }
    if(inventaire[15] > 0){
        printf("| lingot d'or : %d\n", inventaire[15]);
    }
    if(inventaire[16]>0){
        printf("| pioche en fer : %d\n", inventaire[16]);
    }
    if(inventaire[17]>0){
        printf("| pioche en or : %d\n", inventaire[17]);
    }
    if(inventaire[18]>0){
        printf("| casque en bois : %d\n", inventaire[18]);
    }
    if(inventaire[19]>0){
        printf("| casque en fer : %d\n", inventaire[19]);
    }
    if(inventaire[20]>0){
        printf("| casque en or : %d\n", inventaire[20]);
    }
    if(inventaire[21]>0){
        printf("| plastron en bois : %d\n", inventaire[18]);
    }
    if(inventaire[22]>0){
        printf("| plastron en fer : %d\n", inventaire[19]);
    }
    if(inventaire[23]>0){
        printf("| plastron en or : %d\n", inventaire[20]);
    }
    if(inventaire[24]>0){
        printf("| bottes en bois : %d\n", inventaire[24]);
    }
    if(inventaire[25]>0){
        printf("| bottes en fer : %d\n", inventaire[25]);
    }
    if(inventaire[26]>0){
        printf("| bottes en or : %d\n", inventaire[26]);
    }
    if(inventaire[27]>0){
        printf("| viande : %d\n", inventaire[27]);
    }
    printf("|_____________________\n");
    int j = getch();
    if(j == ' '){//CONSTRUCTION
        system("cls");
        printf("--------CONSTRUCTIBLE-------\n");
        if(inventaire[1] >= 10){
            printf("\033[1;31m a \033[1;33m planche                     |        %d/10 bois\n", inventaire[1]);
        }
        if(inventaire[4] >= 10){
            printf("\033[1;31m b \033[1;33m pioche en bois              |        %d/10 planche\n", inventaire[4]);      
        }
        if(inventaire[6] >= 100){
            printf("\033[1;31m c \033[1;33m pioche en pierre            |        %d/100 pierre\n", inventaire[6]);
        }
        if((inventaire[6] >= 300)&&(inventaire[7] >= 100)){
            printf("\033[1;31m d \033[1;33m four en pierre            |        %d/300 pierre, %d/100\n", inventaire[6], inventaire[7]);
        }
        if((inventaire[14] >= 10)&&(inventaire[6] >= 100)){
            printf("\033[1;31m g \033[1;33m pioche en fer            |        %d/10 lingot de fer, %d/100 pierre\n", inventaire[14], inventaire[6]);
        }
        if((inventaire[15] >= 10)&&(inventaire[6] >= 100)){
            printf("\033[1;31m h \033[1;33m pioche en or            |        %d/10 lingot d'or, %d/100 pierre\n", inventaire[15], inventaire[6]);
        }
        if((inventaire[1] >= 100)){
            printf("\033[1;31m i \033[1;33m casque en bois           |        %d/100 bois\n", inventaire[1]);
        }
        if((inventaire[14] >= 20)){
            printf("\033[1;31m j \033[1;33m casque en fer           |        %d/20 lingot de fer\n", inventaire[14]);
        }
        if((inventaire[15] >= 20)){
            printf("\033[1;31m k \033[1;33m casque en or           |        %d/20 lingot d'or\n", inventaire[15]);
        }
        if((inventaire[1] >= 200)){
            printf("\033[1;31m l \033[1;33m plastron en bois           |        %d/200 bois\n", inventaire[1]);
        }
        if((inventaire[14] >= 40)){
            printf("\033[1;31m m \033[1;33m plastron en fer           |        %d/40 lingot de fer\n", inventaire[14]);
        }
        if((inventaire[15] >= 40)){
            printf("\033[1;31m n \033[1;33m plastron en or           |        %d/40 lingot d'or\n", inventaire[15]);
        }
        if((inventaire[1] >= 200)){
            printf("\033[1;31m o \033[1;33m bottes en bois           |        %d/200 bois\n", inventaire[1]);
        }
        if((inventaire[14] >= 40)){
            printf("\033[1;31m p \033[1;33m bottes en fer           |        %d/40 lingot de fer\n", inventaire[14]);
        }
        if((inventaire[15] >= 40)){
            printf("\033[1;31m q \033[1;33m bottes en or           |        %d/40 lingot d'or\n", inventaire[15]);
        }
        if(four == TRUE){//FOUR
            if(inventaire[7] >= 10){
                printf("\033[1;31m e \033[1;33m lingot de fer            |        %d/10 fer\n", inventaire[7]);
            }
            if(inventaire[9] >= 10){
                printf("\033[1;31m f \033[1;33m lingot d'or            |        %d/10 or\n", inventaire[9]);
            }
        }
        int c = getch();
        while((c == 'a') && (inventaire[1] >= 10)){
            printf(" -10 bois ");
            inventaire[4]++;
            inventaire[1] = inventaire[1] - 10;
            c = getch();
        }
        while((c == 'c') && (inventaire[6] >= 100)){
            printf(" -100 pierre ");
            inventaire[8]++;
            inventaire[6] = inventaire[6] - 100;
            c = getch();
        }
        while((c == 'b') && (inventaire[4] >= 10)){
            printf(" -10 planche ");
            inventaire[5]++;
            inventaire[4] = inventaire[4] - 10;
            c = getch();
        }
        while((c == 'd') &&(inventaire[6] >= 300)&&(inventaire[7] >= 100)){
            printf(" -300 pierres -100 fer ");
            inventaire[12]++;
            inventaire[6] = inventaire[6] - 300;
            inventaire[7] = inventaire[7] - 100;
            c = getch();
        }
        while((c == 'e') &&(inventaire[7] >= 10)){
            printf(" -10 fer ");
            inventaire[14]++;
            inventaire[7] = inventaire[7] - 10;
            c = getch();
        }
        while((c == 'f') &&(inventaire[9] >= 10)){
            printf(" -10 or ");
            inventaire[7]++;
            inventaire[9] = inventaire[9] - 10;
            c = getch();
        }
        while((c == 'g') &&(inventaire[14] >= 10)&&(inventaire[6] >= 100)){
            printf(" -100 pierres -10 lingot de fer ");
            inventaire[16]++;
            inventaire[6] = inventaire[6] - 100;
            inventaire[14] = inventaire[14] - 10;
            c = getch();
        }
        while((c == 'h') &&(inventaire[15] >= 10)&&(inventaire[6] >= 100)){
            printf(" -100 pierres -10 lingot de fer ");
            inventaire[17]++;
            inventaire[6] = inventaire[6] - 100;
            inventaire[15] = inventaire[15] - 10;
            c = getch();
        }
        while((c == 'i') &&(inventaire[1] >= 100)){
            printf(" -100 bois");
            inventaire[18]++;
            inventaire[1] = inventaire[1] - 100;
            c = getch();
        }
        while((c == 'j') &&(inventaire[14] >= 20)){
            printf(" -20 fer");
            inventaire[19]++;
            inventaire[14] = inventaire[14] - 20;
            c = getch();
        }
        while((c == 'k') &&(inventaire[15] >= 20)){
            printf(" -20 or");
            inventaire[20]++;
            inventaire[15] = inventaire[15] - 20;
            c = getch();
        }
        while((c == 'l') &&(inventaire[1] >= 200)){
            printf(" -200 bois");
            inventaire[21]++;
            inventaire[1] = inventaire[1] - 200;
            c = getch();
        }
        while((c == 'm') &&(inventaire[14] >= 40)){
            printf(" -40 fer");
            inventaire[22]++;
            inventaire[14] = inventaire[14] - 40;
            c = getch();
        }
        while((c == 'n') &&(inventaire[15] >= 40)){
            printf(" -40 or");
            inventaire[23]++;
            inventaire[15] = inventaire[15] - 40;
            c = getch();
        }
        while((c == 'o') &&(inventaire[1] >= 200)){
            printf(" -200 bois");
            inventaire[24]++;
            inventaire[1] = inventaire[1] - 200;
            c = getch();
        }
        while((c == 'p') &&(inventaire[14] >= 40)){
            printf(" -40 fer");
            inventaire[25]++;
            inventaire[14] = inventaire[14] - 40;
            c = getch();
        }
        while((c == 'q') &&(inventaire[15] >= 40)){
            printf(" -40 or");
            inventaire[26]++;
            inventaire[15] = inventaire[15] - 40;
            c = getch();
        }
        
        system("cls");
    }
}

void affiche_tab(char tab[TAILLE][TAILLE], int col_player, int lig_player, float temps){
    for(int ligne = lig_player-13 ; ligne < lig_player+13 ; ligne++){
        for(int colonne = col_player-13 ; colonne < col_player+13 ; colonne++){
            if(tab[colonne][ligne] == 'J'){
                printf("\033[1;31m");
                printf("J");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == 'T'){
                if(sin(temps/40) < 0){
                    printf("\033[2;32m");
                    printf("T");
                    printf("\033[0m");
                }
                else{
                    printf("\033[0;32m");
                    printf("T");
                    printf("\033[0m");
                }

            }
            else if(tab[colonne][ligne] == '@'){
                printf("\033[1;30m");
                printf("@");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == '!'){
                printf("\033[1;33m");
                printf("!");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == '#'){
                if(sin(temps/40) < 0){//OCEAN
                    printf("\033[2;34m");
                    printf("#");
                    printf("\033[0m");
                }
                else{
                    printf("\033[0;44m");
                    printf(" ");
                    printf("\033[0m");
                }
            }
            else if(tab[colonne][ligne] == '_'){
                printf("\033[0;33m");
                printf("_");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == '['){
                printf("\033[0;33m");
                printf("[");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == ']'){
                printf("\033[0;33m");
                printf("]");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == '^'){
                printf("\033[0;33m");
                printf("^");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == '~'){
                printf("\033[0;33m");
                printf("~");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == '|'){
                printf("\033[0;33m");
                printf("|");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == '+'){
                printf("\033[0;35m");
                printf("+");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == '-'){
                printf("\033[0;33m");
                printf("-");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == 'B'){
                printf("\033[3;33m");
                printf("@");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == 'C'){//sand
                if(sin(temps/40) < 0){
                    printf("\033[2;33m");
                    printf("#");
                    printf("\033[0m");
                }
                else{
                    printf("\033[0;43m");
                    printf(" ");
                    printf("\033[0m");
                }
            }
            else if(tab[colonne][ligne] == 'f'){//four
                printf("\033[0;33m");
                printf("F");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == 'a'){//cactus
                printf("\033[2;32m");
                printf("*");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == 'b'){//golem
                printf("\033[5;31m");
                printf("$");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == 'c'){//tombe
                printf("\033[1;30m");
                printf("+");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == 'd'){//lava
                printf("\033[0;41m");
                printf(" ");
                printf("\033[0m");
            }
            else if(tab[colonne][ligne] == 'e'){//cochons
                printf("\033[1;35m");
                printf("O");
                printf("\033[0m");
            }
            else{
                printf("%c", tab[colonne][ligne]);
            }
        }
        printf("\n");
    }
}

void init_tab(char tab[TAILLE][TAILLE]){//INTIALISATION DU MONDE
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
            int random = rand() % 10000;
            if((0<=random) &&(random<= 400)){
                tab[colonne][ligne] = 'T';
            }
            else if((510<=random) &&(random<= 520)){ 
                tab[colonne][ligne] = '@';
            }
            else if((random== 530)){
                tab[colonne][ligne] = '!';
            }
            else if((random== 531)){
                tab[colonne][ligne] = '#';
            }
            else if(random == 532){
                tab[colonne][ligne] = 'A';
            }
            else if((random== 533)){
                tab[colonne][ligne] = 'C';
            }
            else{
                tab[colonne][ligne] = ' ';
            }
        }
    }
    for(int i = 0 ; i < 3; i++){//GENERATION ROCK
        for(int ligne = 0 ; ligne < TAILLE ; ligne++){
            for(int colonne = 0 ; colonne < TAILLE ; colonne++){
                if((tab[colonne][ligne] == '@')&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                    int random_water = rand() % 3;
                    if((random_water == 0)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne-1][ligne-1] = '@';
                    }
                    if((random_water == 1)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne+1][ligne-1] = '@';
                    }
                    if((random_water == 2)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne][ligne-1] = '@';
                    }
                    tab[colonne][ligne-1] = '@';
                }
            }
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//GENERATION ROCK GOLD
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
            if(tab[colonne][ligne] == '@'){
                int random_rock_gold = rand()%10;
                if(random_rock_gold == 0){
                    tab[colonne][ligne] = 'B';
                }
            }
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//GENERATION MAISON
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
            if(tab[colonne][ligne] == 'A'){
                tab[colonne-3][ligne-2] = ' ',tab[colonne-2][ligne-2] = '-',tab[colonne-1][ligne-2] = '^',tab[colonne][ligne-2] = ' '; 
                tab[colonne-3][ligne-1] = '|',tab[colonne-2][ligne-1] = ' ',tab[colonne-1][ligne-1] = ' ',tab[colonne][ligne-1] = '|'; 
                tab[colonne-3][ligne] = '|',tab[colonne-2][ligne] = '|',tab[colonne-1][ligne] = '|',tab[colonne][ligne] = '|'; 
            }
        }
    }
    for(int i = 0 ; i < 50; i++){//GENERATION WATER
        for(int ligne = 0 ; ligne < TAILLE ; ligne++){
            for(int colonne = 0 ; colonne < TAILLE ; colonne++){
                if((tab[colonne][ligne] == '#')&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                    int random_water = rand() % 4;
                    if((random_water == 0)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne-1][ligne-1] = '#';
                    }
                    if((random_water == 1)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne+1][ligne-1] = '#';
                    }
                    if((random_water == 2)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne][ligne-2] = '#';
                    }
                    if((random_water == 3)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3) &&(colonne>0)&&(ligne>0)){
                        tab[colonne][ligne] = '#';
                    }
                    tab[colonne][ligne-1] = '#';
                }
            }
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//GENERATION TEMPLE SOUS MARIN
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
            if(tab[colonne][ligne] == '#'){
                int random_temple_water = rand() % 599999;
                if(random_temple_water == 0){
                    tab[colonne-4][ligne-5] = ' ',tab[colonne-3][ligne-5] = '_',tab[colonne-2][ligne-5] = '^',tab[colonne-1][ligne-5] = '_',tab[colonne][ligne-5] = ' ';
                    tab[colonne-4][ligne-4] = '|',tab[colonne-3][ligne-4] = ' ',tab[colonne-2][ligne-4] = ' ',tab[colonne-1][ligne-4] = ' ',tab[colonne][ligne-4] = '|';
                    tab[colonne-4][ligne-3] = '|',tab[colonne-3][ligne-3] = ' ',tab[colonne-2][ligne-3] = ' ',tab[colonne-1][ligne-3] = ' ',tab[colonne][ligne-3] = '|';
                    tab[colonne-4][ligne-2] = '|',tab[colonne-3][ligne-2] = '[',tab[colonne-2][ligne-2] = ' ',tab[colonne-1][ligne-2] = ']',tab[colonne][ligne-2] = '|';
                    tab[colonne-4][ligne-1] = '|',tab[colonne-3][ligne-1] = '[',tab[colonne-2][ligne-1] = ' ',tab[colonne-1][ligne-1] = ']',tab[colonne][ligne-1] = '|';
                    tab[colonne-4][ligne] = ' ',tab[colonne-3][ligne] = '~',tab[colonne-2][ligne] = '~',tab[colonne-1][ligne] = '~',tab[colonne][ligne] = ' ';
                }
            }
        }
    }
    for(int i = 0 ; i < 50; i++){//GENERATION SAND
        for(int ligne = 0 ; ligne < TAILLE ; ligne++){
            for(int colonne = 0 ; colonne < TAILLE ; colonne++){
                if((tab[colonne][ligne] == 'C')&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                    int random_water = rand() % 4;
                    if((random_water == 0)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne-1][ligne-1] = 'C';
                    }
                    if((random_water == 1)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne+1][ligne-1] = 'C';
                    }
                    if((random_water == 2)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne][ligne-2] = 'C';
                    }
                    if((random_water == 3)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3) &&(colonne>0)&&(ligne>0)){
                        tab[colonne][ligne] = 'C';
                    }
                    tab[colonne][ligne-1] = 'C';
                }
            }
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//GENERATION CACTUS
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
            if(tab[colonne][ligne] == 'C'){
                int random_cactus = rand() % 260;
                if(random_cactus == 0){
                    tab[colonne][ligne] = 'a';
                }
                else if(random_cactus == 1){
                    tab[colonne][ligne] = 'a';
                    tab[colonne][ligne-1] = 'a';
                }
            }
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//GENERATION GOLEM  + LAVA  
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
            if(tab[colonne][ligne] == ' '){
                int random_golem = rand() % 600;
                int random_lava = rand() % 3000;
                int random_porc = rand() % 600;
                if(random_golem == 0){
                    tab[colonne][ligne] = 'b'; 
                }
                if(random_porc == 0){
                    tab[colonne][ligne] = 'e'; 
                }
                if((random_lava == 0) && (tab[colonne][ligne] != '#')){
                    tab[colonne][ligne] = 'd'; 
                }
                
            }
        }
    }
    for(int i = 0 ; i < 2; i++){//GENERATION LAVA
        for(int ligne = 0 ; ligne < TAILLE ; ligne++){
            for(int colonne = 0 ; colonne < TAILLE ; colonne++){
                if((tab[colonne][ligne] == 'd')&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                    int random_water = rand() % 4;
                    if((random_water == 0)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne-1][ligne-1] = 'd';
                    }
                    if((random_water == 1)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne+1][ligne-1] = 'd';
                    }
                    if((random_water == 2)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3)&&(colonne>0)&&(ligne>0)){
                        tab[colonne][ligne-2] = 'd';
                    }
                    if((random_water == 3)&&(colonne<TAILLE-3)&&(ligne< TAILLE-3) &&(colonne>0)&&(ligne>0)){
                        tab[colonne][ligne] = 'd';
                    }
                    tab[colonne][ligne-1] = 'd';
                }
            }
        }
    }

}

void mouvement(char tab[TAILLE][TAILLE], int col, int lig, int inventaire[TAILLE_INVENTAIRE], int equipement[14], int construction[8], int t1, int t2, float temps, boolean four, int life, int col_origine, int lig_origine, int game_over){
    t1=clock();
    int c = getch();
    int resistance = 0;
    system("cls");
    //EQUIPEMENT RESISTANCE
    if(equipement[5] == 1){//casque en bois
        resistance = resistance+5;
        printf("casque en bois\n");
    }
    if(equipement[6] == 1){//casque en fer
        resistance = resistance+10;
        printf("casque en fer\n");
    }
    if(equipement[7] == 1){//casque en or
        resistance = resistance+15;
        printf("casque en or\n");
    }
    if(equipement[8] == 1){//plastron en bois
        resistance = resistance+5;
        printf("plastron en bois\n");
    }
    if(equipement[9] == 1){//plastron en fer
        resistance = resistance+10;
        printf("plastron en fer\n");
    }
    if(equipement[10] == 1){//plastron en or
        resistance = resistance+15;
        printf("plastron en or\n");
    }
    if(equipement[11] == 1){//bottes en bois
        resistance = resistance+5;
        printf("bottes en bois\n");
    }
    if(equipement[12] == 1){//bottes en fer
        resistance = resistance+10;
        printf("bottes en fer\n");
    }
    if(equipement[13] == 1){//bottes en or
        resistance = resistance+15;
        printf("bottes en or\n");
    }
    char memoire;
    printf("(%d ; %d) \n", col, lig);
    printf("hp : %d\n", life);
    affiche_hp(life);
    printf("resistance : %d\n", resistance);
    affiche_resistance(resistance);
    if((c == ARROW_UP)){
        if((tab[col][lig-1] == ' ')||(tab[col][lig-1] == 'C')||(tab[col][lig-1] == 'd')){
            char memoire = tab[col][lig-1];
            tab[col][lig-1] = 'J';
            tab[col][lig] = memoire;
            lig--;
        }
        
    }
    if((c == ARROW_DOWN)){
        if((tab[col][lig+1] == ' ')||(tab[col][lig+1] == 'C')||(tab[col][lig+1] == 'd')){
            char memoire = tab[col][lig+1];
            tab[col][lig+1] = 'J';
            tab[col][lig] = memoire;
            lig++;
        }
        
    }  
    if((c == ARROW_LEFT)){
        if((tab[col-1][lig] == ' ')||(tab[col-1][lig] == 'C')||(tab[col-1][lig] == 'd')){
            char memoire = tab[col-1][lig];
            tab[col-1][lig] = 'J';
            tab[col][lig] = memoire;
            col--;
        }       
        
        
    }  
    if((c == ARROW_RIGHT)){
        if((tab[col+1][lig] == ' ')||(tab[col+1][lig] == 'C')||(tab[col+1][lig] == 'd')){
            char memoire = tab[col+1][lig];
            tab[col+1][lig] = 'J';
            tab[col][lig] = memoire;
            col++;
        }    
        
    }
    if((tab[col-1][lig] == 'd')||(tab[col+1][lig] == 'd')||(tab[col][lig-1] == 'd')||(tab[col][lig+1] == 'd')){//ENLEVER HP LAVE
        life = life-5;
    }
    if(c == 'c'){//CHEAT CODE
        int situation_cheat = cheat(tab);
        if(situation_cheat == 1){
            system("cls");
            printf("CHEAT DE TP\n");
            int p = 2;
            while (p != 0) {
                printf("x : ");
                scanf("%d", &col);
                printf("\n");
                printf("y : ");
                scanf("%d", &lig);
                p = 0;
            }
        }
        if(situation_cheat == 2){
            system("cls");
            printf("CHEAT DE OBJET INFINIT\n");
            sleep(1);
            inventaire[1] = inventaire[1] + 1000;
            inventaire[2] = inventaire[2] + 1000;
            inventaire[3] = inventaire[3] + 1000;
            inventaire[4] = inventaire[4] + 1000;
            inventaire[5] = inventaire[5] + 1;
            inventaire[6] = inventaire[6] + 1000;
            inventaire[7] = inventaire[7] + 1000;
            inventaire[8] = inventaire[8] + 1;
            inventaire[9] = inventaire[9] + 1000;
            inventaire[10] = inventaire[10] + 1000;
            inventaire[11] = inventaire[11] + 1000;
            inventaire[12] = inventaire[12] + 1;
            inventaire[13] = inventaire[13] + 1000;
            inventaire[14] = inventaire[14] + 1000;
            inventaire[15] = inventaire[15] + 1000;
            inventaire[16] = inventaire[16] + 1;
            inventaire[17] = inventaire[17] + 1;
            inventaire[18] = inventaire[18] + 1;
            inventaire[19] = inventaire[19] + 1;
            inventaire[20] = inventaire[20] + 1;
            inventaire[21] = inventaire[21] + 1;
            inventaire[22] = inventaire[22] + 1;
            inventaire[23] = inventaire[23] + 1;
            inventaire[24] = inventaire[24] + 1;
            inventaire[25] = inventaire[25] + 1;
            inventaire[26] = inventaire[26] + 1;
        }
        if(situation_cheat == 3){
            system("cls");
            printf("CHEAT DE VIE \n");
            sleep(1);
            life = life+300;
        }
    }
    if(c == ' '){
        char memoire = tab[col][lig-1];
        tab[col][lig-1] = '^';
        system("cls");
        printf("(%d ; %d) \n", col, lig);
        affiche_tab(tab, col, lig, temps);
        tab[col][lig-1] = memoire;
        system("cls");
        printf("(%d ; %d) \n", col, lig);
        affiche_tab(tab, col, lig, temps);
        system("cls");
        printf("(%d ; %d) \n", col, lig);
    }
    if((c == ' ') &&(tab[col][lig-1] == 'T') ){//couper arbre
        tab[col][lig-1] = ' ';
        int random_gland = rand() % 4;
        int random_glandor = rand() % 40;
        if(random_gland == 0){
            inventaire[2]++;
        }
        if(random_glandor == 0){
            inventaire[3]++;
        }
        inventaire[1]++; 
    }
    if((c == ' ') && (tab[col][lig-1] == '@')){//miner pierre
        if((equipement[1]==1)||(equipement[2]==1)){//equipement : pioche en pierre ou pioche en bois
            tab[col][lig-1] = ' ';
            int random_pierre = rand() % 4;
            int random_fer = rand() % 2;
            int random_pierre_de_lune = rand() %20;
            inventaire[6] = inventaire[6] + random_pierre;
            inventaire[7] = inventaire[7] + random_fer;
            if(sin(temps/40) <0){//nuit
                if(random_pierre_de_lune == 0){
                    inventaire[13]++;
                }
            }
        }
        if(equipement[3] == 1){//equipement : pioche en fer
            tab[col][lig-1] = ' ';
            int random_pierre = rand() % 4;
            int random_fer = rand() % 4;
            int random_pierre_de_lune = rand() %20;
            inventaire[6] = inventaire[6] + random_pierre;
            inventaire[7] = inventaire[7] + random_fer;
            if(sin(temps/40) <0){//nuit
                if(random_pierre_de_lune == 0){
                    inventaire[13]++;
                }
            }
        }
        if(equipement[4] == 1){//equipement : pioche en or
            tab[col][lig-1] = ' ';
            int random_pierre = rand() % 4;
            int random_fer = rand() % 4;
            int random_pierre_de_lune = rand() %10;
            inventaire[6] = inventaire[6] + random_pierre;
            inventaire[7] = inventaire[7] + random_fer;
            if(sin(temps/40) <0){//nuit
                if(random_pierre_de_lune == 0){
                    inventaire[13]++;
                }
            }
        }
    }
    if((c == ' ') && (tab[col][lig-1] == 'B')){//miner or
        if((equipement[2]==1)){//equipement : pioche en pierre
            tab[col][lig-1] = ' ';
            int random_or = rand()%4;
            int random_diamant = rand()%10;
            int random_coeur_de_pierre = rand()%20;
            inventaire[9] = inventaire[9]+random_or;
            if(random_diamant==0){
                inventaire[10]++;
            }
            if(random_coeur_de_pierre == 0){
                inventaire[11]++;
            }
        }
        if((equipement[3]==1)){//equipement : pioche en fer
            tab[col][lig-1] = ' ';
            int random_or = rand()%4;
            int random_diamant = rand()%10;
            int random_coeur_de_pierre = rand()%20;
            inventaire[9] = inventaire[9]+random_or;
            if(random_or == 0){
                inventaire[9]++;
            }
            if(random_diamant==0){
                inventaire[10]++;
            }
            if(random_coeur_de_pierre == 0){
                inventaire[11]++;
            }
        }
    }
    if((c == ' ') && (tab[col][lig-1] == 'e')){//tuer cochons
        tab[col][lig-1] = ' ';
        int viande = rand()%5;
        inventaire[27] = inventaire[27] + viande;
    }
    if((c == 'z')){//CONSTRUCTION
        if((construction[2] == 1) && (inventaire[12]>0)){
            if(tab[col][lig-1] == ' '){
                tab[col][lig-1] = 'f';
                inventaire[12]--;
            }
            else if((tab[col][lig-1] == 'f')){
                tab[col][lig-1] = ' ';
                inventaire[12]++;
            }
        }
        else if((construction[1] == 1) && (inventaire[4]>0)){
            if((tab[col][lig-1] == ' ')){
                tab[col][lig-1] = '+';
                inventaire[4]--;
            }
            else if((tab[col][lig-1] == '+')){
                tab[col][lig-1] = ' ';
                inventaire[4]++;
            }
        }
    }
    if(c == 'a'){//CHOIX MATERIAUX CONSTRUCTION
        affiche_construction(tab,inventaire,construction);
    }
    if(c == 'i'){//INVENTAIRE
        system("cls");
        affiche_inventaire(tab, inventaire, four);
        

    }
    if(c == 'e'){//EQUIPEMENT
        system("cls");
        affiche_equipement(tab , inventaire, equipement);
    }
    if((tab[col][lig-1] == 'f')||(tab[col][lig+1]=='f')||(tab[col-1][lig]=='f')||(tab[col+1][lig]=='f')||(tab[col+1][lig-1]=='f')||(tab[col-1][lig+1]=='f')||(tab[col-1][lig-1]=='f')||(tab[col+1][lig+1]=='f')){//FOUR A PROXIMITE
        four = TRUE;
    }
    else if((tab[col][lig-1] != 'f')||(tab[col][lig+1]!='f')||(tab[col-1][lig]!='f')||(tab[col+1][lig]!='f')||(tab[col+1][lig-1]!='f')||(tab[col-1][lig+1]!='f')||(tab[col-1][lig-1]!='f')||(tab[col+1][lig+1]!='f')){
        four = FALSE;
    }
    if(c == 'w'){//REGLE
        affiche_regle();
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//INITIALISATION IA GOLEM    
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
                tab_futur[colonne][ligne] = ' ';
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//IA MOUVEMENT GOLEM    
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
            if((tab[colonne][ligne] == 'b') && (verification(colonne,ligne,TAILLE, TAILLE,tab) == TRUE)){
                int alea_golem = rand()%2;
                if(alea_golem == 0){
                    if((tab[colonne+1][ligne] == 'J') ||(tab[colonne-1][ligne] == 'J')||(tab[colonne][ligne+1]=='J')||(tab[colonne][ligne-1]=='J')){
                        if(resistance<40){
                            life = (life - (400/(resistance+1)));    
                        }
                        break;
                    }
                    else if(colonne <col){//a gauche
                        tab_futur[colonne+1][ligne] = 'b';
                        tab[colonne][ligne] = tab[colonne+1][ligne];
                    }
                    else if(colonne >col){//a droite
                        tab_futur[colonne-1][ligne] = 'b';
                        tab[colonne][ligne] = tab[colonne-1][ligne];
                    }
                    else if(ligne > lig){//en dessous
                        tab_futur[colonne][ligne-1] = 'b';
                        tab[colonne][ligne] = tab[colonne][ligne-1];
                    }
                    else if(ligne <lig){//au dessus
                        tab_futur[colonne][ligne+1] = 'b';
                        tab[colonne][ligne] = tab[colonne][ligne+1];
                    }
                }
            }
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//IA GOLEM    
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){//TAB FUTUR
            if(tab_futur[colonne][ligne] == 'b'){
                tab[colonne][ligne] = 'b';
            }
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//IA MOUVEMENT COCHON   
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){
            if((tab[colonne][ligne] == 'e') && (verification(colonne,ligne,TAILLE, TAILLE,tab) == TRUE)){
                int alea_cochon = rand()%4;
                if((alea_cochon == 0)){
                    if((tab[colonne+1][ligne] != '#') &&(tab[colonne-1][ligne] != '#')&&(tab[colonne][ligne+1]!='#')&&(tab[colonne][ligne-1]!='#')&&(tab[colonne+1][ligne-1] != '#') &&(tab[colonne-1][ligne+1] != '#')&&(tab[colonne+1][ligne+1]!='#')&&(tab[colonne-1][ligne-1]!='#')){
                        if(colonne >col){//a gauche
                            tab_futur[colonne+1][ligne] = 'e';
                            tab[colonne][ligne] = tab[colonne+1][ligne];
                        }
                        else if(colonne <col){//a droite
                            tab_futur[colonne-1][ligne] = 'e';
                            tab[colonne][ligne] = tab[colonne-1][ligne];
                        }
                        else if(ligne < lig){//en dessous
                            tab_futur[colonne][ligne-1] = 'e';
                            tab[colonne][ligne] = tab[colonne][ligne-1];
                        }
                        else if(ligne >lig){//au dessus
                            tab_futur[colonne][ligne+1] = 'e';
                            tab[colonne][ligne] = tab[colonne][ligne+1];
                        }
                    }
                }
            }
        }
    }
    for(int ligne = 0 ; ligne < TAILLE ; ligne++){//IA COCHON  
        for(int colonne = 0 ; colonne < TAILLE ; colonne++){//TAB FUTUR
            if(tab_futur[colonne][ligne] == 'e'){
                tab[colonne][ligne] = 'e';
            }
        }
    }
    if(life < 0){//game over
        game_over++;
        tab[col][lig] = 'c';//tombe case
        tab[col_origine][lig_origine] = 'J';
        life = 50;
        mouvement(tab, col_origine, lig_origine,inventaire, equipement, construction, t1,t2, temps, four, life,col_origine,lig_origine, game_over);
        
    }
    if(sin(temps/40) == 0){//NIGHT GENERATION
        for(int ligne = 0 ; ligne < TAILLE ; ligne++){//GENERATION GOLEM
            for(int colonne = 0 ; colonne < TAILLE ; colonne++){
                if(tab[colonne][ligne] == 'b'){
                    tab[colonne][ligne] = ' '; 
                }
                if(tab[colonne][ligne] == ' '){
                    int random_golem = rand() % 600;
                    if(random_golem == 0){
                        tab[colonne][ligne] = 'b'; 
                    }
                }
                //cochons
                if(tab[colonne][ligne] == 'e'){
                    tab[colonne][ligne] = ' '; 
                }
                if(tab[colonne][ligne] == ' '){
                    int random_cochon = rand() % 600;
                    if(random_cochon == 0){
                        tab[colonne][ligne] = 'e'; 
                    }
                }
            }
        }
    }
    affiche_tab(tab, col, lig, temps);
    t2 = clock();
    temps = temps +  ((float)(t2-t1)/CLOCKS_PER_SEC);
    printf("time : %f\n", temps);
    mouvement(tab, col, lig,inventaire, equipement, construction, t1,t2, temps, four, life,col_origine,lig_origine, game_over);
}
/*INVENTAIRE: 
1   bois
2   gland
3   glandor
4   planche de bois
5   pioche en bois
6   pierre
7   fer
8   pioche en pierre
9   or
10  diamant
11  coeur de pierre
12  four
13  pierre de lune
14  lingot de fer
15  lingot d'or
16  pioche en fer
17  pioche en or
18  casque en bois
19  casque en fer
20  casque en or
21  plastron en bois
22  plastron en fer
23  plastron en or
24  bottes en bois
25  bottes en fer
26  bottes en or
27  viande de porc

EQUIPEMENT : 
0   RIEN
1   pioche en bois
2   pioche en pierre
3   pioche en fer
4   pioche en or
5   casque en bois
6   casque en fer
7   casque en or
8   plastron en bois
9   plastron en fer
10  plastron en or
11  bottes en bois
12  bottes en fer
13  bottes en or

CONSTRUCTION :
1   planche
2   four
*/
int jeu_exploration(char tab[TAILLE][TAILLE], int life, int resistance){
    init_tab(tab);
    clock_t t1, t2;
    float temps = 0;
    int inventaire[TAILLE_INVENTAIRE] = {0};
    int construction[8] = {0};
    int equipement[14] = {0};
    boolean four = FALSE;
    for (int i = 0; i< TAILLE_INVENTAIRE ; i++){
        inventaire[i] = 0;
        equipement[i] = 0;
    }
    int fin = 0;
    //RESSOURCES

    int score = 0;
    int col = 15;
    int lig = 15;
    while(tab[col][lig] != ' '){
        system("cls");
        col = rand()% TAILLE;
        lig = rand()% TAILLE;
        printf("reteleportation...\n");
        sleep(1);
    }
    int col_origine = col;
    int lig_origine = lig;
    int game_over = 0;
    
    //POINT DE SPAWN
    tab[col-1][lig-1] = '|',tab[col][lig-1] = ' ',tab[col+1][lig-1] = '|';
    tab[col-1][lig] = '|',tab[col][lig] = 'J',tab[col+1][lig] = '|';
    tab[col-1][lig-1] = '|',tab[col][lig-1] = ' ',tab[col+1][lig-1] = '|';
    while(score < 3552523){
        mouvement(tab,col, lig,inventaire, equipement, construction, t1,t2, temps,four,life, col_origine, lig_origine, game_over);
        score++;
    }
    printf("nombre de pas : %d\n", score);
    return score;

}

int main(){
    srand(time(NULL));
    char tab[TAILLE][TAILLE];
    char chain[82] = "";
    int choice = 0;
    int score = 0;
    int life = 50;
    int resistance = 0;
    FILE *spr_title = NULL;
    spr_title = fopen("spr_title.txt", "r+");
    if (spr_title != NULL)
    {
        while (fgets(chain, 82, spr_title) != NULL) 
        {
        printf("%s", chain); 
        }
        fclose(spr_title);
    }
    sleep(1);
    printf("\033[H\033[2J");

    printf(" _______________________MODE DE JEU_____________________\n");
    printf("|       exploration                                     |\n");
    printf("|           1                                           |\n");
    printf("|_______________________________________________________|\n");
    int random = rand() % 11;
    printf("ASTUCE : ");
    if(random == 0){
        printf("Il est vraiment tres rare de croiser un temple sous marin !\n");
        printf("                             _^_ \n");
        printf("                            |   |\n");
        printf("                            |[ ]|\n");
        printf("                            |[_]|\n");
        printf("                             ~~~ \n");
    }
    if(random == 1){
        printf("Avez vous obtenu un gland d'or en coupant des arbres ?\n");
    }
    if(random == 2){
        printf("l'other world est un monde chaotique qui se trouve a la limite du monde\n");
    }
    if(random == 3){
        printf("besoin d'aide ? appuie sur W !\n");
    }
    if(random == 4){
        printf("toutes les 2 minutes il fait nuit\n");
    }    
    if(random == 5){
        printf("les pierres de lunes ne sont trouvables que la nuit\n");
    }    
    if(random == 6){
        printf("la pioche en or permet de miner deux foix plus de pierres de lunes\n");
    }   
    if(random == 7){
        printf("la pioche en fer permet de recuperer de l'or en minant\n");
    }
    if(random == 8){
        printf("la lave est tellement chaude que vous ne pouvez meme pas vous en approcher !\n");
    }  
    if(random == 9){
        printf("Certains golems peuvent vous fuire\n");
        printf("\033[1;31m");
        printf("$");
        printf("\033[0m");
    }  
    if(random == 10){
        printf("Essayez de fuir un golem par la diagonale. Il ne peut pas vous attaquez de cet endroit\n");
        printf("\033[1;31m");
        printf("$");
        printf("\033[0m");
    } 
    if(random == 11){
        printf("Les cochons ne savents pas nager\n");
        printf("\033[1;35m");
        printf("O");
        printf("\033[0m");
    } 
    while ((choice != 1)) {
    printf("\nCHOIX : ");
    choice = protect_bug();
    if ((choice == 1)) {

        score = jeu_exploration(tab, life, resistance);

        break;

    }
  }
    continue_playing();
    return 0;
}