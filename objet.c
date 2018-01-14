#include "global.h"
/**
*\file main.c
*\brief Programme permettant de saisir et gérer une liste d'objet
*\version 1.0
*\author Victor Morgant
*\date 14/01/2018
*/
t_OBJ Copie_OBJ(t_OBJ OBJ){
/**
 * \fn Copie_OBJ(t_OBJ OBJ)
 * \brief Fonction permettant de réaliser la copie d'une OBJ
 * \param t_OBJ OBJ la OBJ à copier
 * \return t_OBJ copie : la copie de la OBJ fournie en paramètre
 */
    t_OBJ copie;
    strcpy(copie.nom,OBJ.nom);
    copie.type=OBJ.type;
    /*A completer*/
    return copie;

}

void Echanger_OBJ(t_OBJ* OBJ1,t_OBJ* OBJ2){
/**
 * \fn Echanger_OBJ(t_OBJ* OBJ1,t_OBJ* OBJ2)
 * \brief Fonction échangeant 2 OBJs
 * \param t_OBJ* OBJ1,t_OBJ* OBJ2 : les OBJs à échanger
 */
    t_OBJ tmp;
    tmp=Copie_OBJ(*OBJ1);
    *OBJ1=Copie_OBJ(*OBJ2);
    *OBJ2=Copie_OBJ(tmp);
}
void tri_bulle(t_OBJ * tab,int taille){
/**
 * \fn tri_bulle(t_OBJ * tab,int taille)
 * \brief Fonction triant le tableau de OBJ par CRITERE croissant au moyen d'un tri bulle
 * \param t_OBJ * tab : le tableau à trier ,int taille : la taille de ce tableau
 */
    int i,j;
    for (i=taille-1;i>0;i--){
        for(j=0;j<i;j++){
            if( tab[j+1].CRITERE < tab[j].CRITERE)
                Echanger_OBJ(&tab[j+1],&tab[j]);
        }
    }
}

void tri_insertion(t_OBJ * tab,int taille){
/**
 * \fn tri_insertion(t_OBJ * tab,int taille)
 * \brief Fonction triant le tableau de OBJ par CRITERE croissant au moyen d'un tri par insertion
 * \param t_OBJ * tab : le tableau à trier ,int taille : la taille de ce tableau
 */
    int i,j;
    t_OBJ tmp;/*Tampon pour échange*/
    for (i=0;i<taille;i++){
            tmp=Copie_OBJ(tab[i]);
            j=i;
            while( j>0 && (tab[j-1].CRITERE>tmp.CRITERE) ){
                Echanger_OBJ(&tab[j],&tab[j-1]);
                j=j-1;
            }
            Echanger_OBJ(&tab[j],&tmp);
    }
}

void tri_drapeau_hollandais(t_OBJ * tab,int taille){
/**
 * \fn tri_drapeau_hollandais(t_OBJ * tab,int taille)
 * \brief Fonction triant le tableau de OBJ par type au moyen d'un tri du tableau hollandais
 * \param t_OBJ * tab : le tableau à trier ,int taille : la taille de ce tableau
 */
    int b=0,v=0,s=taille-1;/*Indice correspondant à chaque OBJ*/
    while(v<= s){
        if(tab[v].type==vin)
            v++;
        else if(tab[v].type==biere){
            Echanger_OBJ(&tab[b],&tab[v]);
            b++;
            v++;
        }
        else{
            Echanger_OBJ(&tab[v],&tab[s]);
            s--;
        }

    }

}

int nbLigneFichier(FILE* fichier){
/**
 * \fn nbLigneFichier(FILE*fichier)
 * \brief Fonction renvoyant le nombre de ligne d'un fichier
 * \param FILE* fichier : le fichier dont on souhaite connaitre le nombre de ligne
 * \return ligne : le nombre de ligne du fichier
 */
    int ligne=0;
    int caractere=0;
    while(caractere!=EOF)
    {
        caractere=fgetc(fichier);
        if (caractere=='\n')
        ligne++;
    }
    return ligne;
}
void Ajout_OBJ(t_OBJ *OBJ){
/**
 * \fn Ajout_OBJ(t_OBJ *OBJ)
 * \brief Fonction permettant de saisir les différents attributs de la OBJ
 * \param t_OBJ *OBJ : la OBJ dont on veut saisir les caractéristiques
 */

    int type_OBJ;
    printf("\nEntrez le nom de la OBJ\n");
    scanf("%s",OBJ->nom);
    do{
        printf("\nEntrez le type de la OBJ 1 : vin 2: biere 3: spiritueux\n");
        scanf("%i",&type_OBJ);
    }while(type_OBJ <1 || type_OBJ>3);
    switch(type_OBJ){
        case 1 :
            OBJ->type=vin;
            break;
        case 2 :
            OBJ->type=biere;
            break;
        case 3 :
            OBJ->type=spiritueux;
            break;
        }

    printf("\nEntrez le degre de la OBJ\n");
    scanf("%f",&(OBJ->degre));
    printf("\nEntrez l'annee de la OBJ\n");
    scanf("%i",&(OBJ->annee));
}

void Saisie_OBJ(t_OBJ *tab,int taille,int debut){
/**
 * \fn Saisie_OBJ(t_OBJ *tab,int taille,int debut)
 * \brief Fonction permettant de saisir la liste des OBJs
 * \param t_OBJ *tab : le tableau des OBJs,int taille : la taille de ce tableau,int debut :l'indice à partir duquel on veut saisir les OBJs
 */
    int i=debut;
    while(i<taille){
        printf("\nOBJ %i : \n",i+1);
        Ajout_OBJ(&tab[i]);
        i++;
    }
}

void Afficher_OBJ(t_OBJ OBJ){
/**
 * \fn Afficher_OBJ(t_OBJ OBJ)
 * \brief Fonction permettant d'afficher une OBJ
 * \param t_OBJ *OBJ : la OBJ que l'on veut afficher
 */
    printf("\n %s \n",OBJ.nom);
     switch(OBJ.type){
        case 0 :
            printf("\n Vin \n");
            break;
        case 1 :
            printf("\n Biere \n");
            break;
        case 2 :
            printf("\n Spiritueux \n");
            break;
        }
    printf("\n %.1f degres \n",OBJ.degre);
    printf("\n Annee : %i \n",OBJ.annee);

}
void Afficher_tab_OBJ(t_OBJ * tab,int taille){
/**
 * \fn Afficher_tab_OBJ(t_OBJ * tab,int taille)
 * \brief Fonction permettant d'afficher le tableau des OBJs
 * \param t_OBJ *tab : le tableau des OBJs,int taille : la taille de ce tableau
 */
    int i=0;
    if(tab != NULL){
        printf("Le tableau contient : \n");
        for(i=0;i<taille;i++){
            Afficher_OBJ(tab[i]);
        }
    }
    else
      printf("Il n'y a aucune OBJ \n");

}
int Denombrer_type(t_OBJ * tab,int taille,t_type_OBJ type){
/**
 * \fn Denombrer_type(t_OBJ * tab,int taille,t_type_OBJ type)
 * \brief Fonction permettant de déterminer le nombre de OBJ pour un type
 * \param t_OBJ *tab : le tableau des OBJs,int taille : la taille de ce tableau,t_type_OBJ type : le type que l'on souhaite dénombrer
 * \return total : le nombre d'élément possédant le type type
 */
    int i=0;
    int total=0;
    for(i=0;i<taille;i++){
        if(tab[i].type == type)
            total++;
    }
    return total;

}

float Calculer_moyenne_type(t_OBJ * tab,int taille,t_type_OBJ type){
/**
 * \fn Calculer_moyenne_type(t_OBJ * tab,int taille,t_type_OBJ type)
 * \brief Fonction permettant de calculer le degré moyen pour un type
 * \param t_OBJ *tab : le tableau des OBJs,int taille : la taille de ce tableau,t_type_OBJ type : le type dont l'on souhaite connaitre le degré moyen
 * \return moyenne : le degré moyen pour le type type
 */
    float moyenne=0;
    int i,nb;
    nb=Denombrer_type(tab,taille,type);
    if(nb>0){
        for(i=0;i<taille;i++){
            if(tab[i].type == type)
                moyenne+=tab[i].degre;
        }
        moyenne/=nb;
    }
    return moyenne;
}
void Calculer_moyenne_vin(t_OBJ * tab,int taille){
/**
 * \fn Calculer_moyenne_type(t_OBJ * tab,int taille)
 * \brief Fonction permettant de calculer le degré moyen par vin identique
 * \param t_OBJ *tab : le tableau des OBJs,int taille : la taille de ce tableau
 */
    float moyenne=0;
    char nom[TAILLE_NOM];
    int i,nb,j;
    for(i=0;i<taille;i++){
        if(tab[i].type == vin && strcmp(nom,tab[i].nom) != 0){
            strcpy(nom,tab[i].nom);
            nb=1;
            for(j=i+1;j<taille;j++){
                if(strcmp(nom,tab[i].nom) == 0){
                    moyenne+=tab[i].degre;//on fait la somme des degres de tous les vins avec le meme nom
                    nb++;
                }
            }
            moyenne/=nb;
            printf("\nLe vin %s a un degre moyen de %1.f \n", nom,moyenne);
        }
    }

}

void Save_tab(t_OBJ *tab,int taille){
/**
 * \fn Save_tab(t_OBJ *tab,int taille)
 * \brief Fonction permettant de sauvegarder le tableau dans un fichier
 * \param t_OBJ *tab : le tableau des OBJs,int taille : la taille de ce tableau
 */
    int i=0;
    t_OBJ tmp;
    FILE *fic=NULL;
    fic=fopen("liste_OBJ","w");
    for(i=0;i<taille;i++){
        tmp=tab[i];
        fprintf(fic,"%s ",tmp.nom);
        switch(tab[i].type){
        case vin :
            fprintf(fic,"0 ");
            break;
        case biere :
            fprintf(fic,"1 ");
            break;
        case spiritueux :
            fprintf(fic,"2 ");
            break;
        }
        fprintf(fic,"%1.f ",tmp.degre);
        fprintf(fic,"%i \n",tmp.annee);
    }
    fclose(fic);
}

t_OBJ* Lire_tab(int * taille){
/**
 * \fn Save_tab(int taille)
 * \brief Fonction permettant de charger le tableau à partir d'un fichier
 * \param int taille : la taille du ce tableau
 */
    FILE *fic=NULL;
    int i=0;
    int tmp;
    t_OBJ *tab=NULL;
    fic=fopen("liste_OBJ","r");
    if (fic==NULL){
        printf ("Erreur d'ouverture de fichier");
    }
    *taille=nbLigneFichier(fic);
    tab=calloc(*taille,sizeof(t_OBJ));
    fseek(fic,0,SEEK_SET);/*Positionnement au debut du fichier texte*/
    while( !feof(fic)){

        fscanf(fic,"%s ",tab[i].nom);

        fscanf(fic,"%i ",&tmp);
        switch(tmp){
        case 0 :
            tab[i].type=vin;
            break;
        case 1 :
            tab[i].type=biere;
            break;
        case 2 :
            tab[i].type=spiritueux;
            break;
        }

        fscanf(fic,"%f ",&(tab[i].degre));
        fscanf(fic,"%i ",&(tab[i].annee));
        i++;

    }
    fclose(fic);
    return tab;
    
}
 