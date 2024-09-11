
 #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
   int jour;
   int mois;
   int anee;
   }date_ness;

   typedef struct {
   int id_dep;
   char nom_dep[40];
   float moyenne_générale;
}departement;

typedef struct {
int Numéro_unique;
char Nom[30];
char prenom[30];
int id_Département;
float Note_générale;
date_ness date;
} etudiant;
etudiant t[100000];
departement v[11];
departement copie[11];
int dim=0;
int dimm=0;
int nbr;
int i,j;
int choix;





void ajouter_etud (){
    printf("enter le id d'etudiant(unique): ");
    scanf("%d",&t[dim].Numéro_unique);
    printf("enter le nom d'etudiant");
    scanf("%29[^\n]",t[dim].Nom);
    printf("enter le prenom d'etudiant");
    scanf("%29[^\n]",t[dim].prenom);
    printf("enter l'anne de nessance: ");
    scanf("%d",&t[dim].date.anee);
    printf("enter le mois de nessance");
    scanf("%d",&t[dim].date.mois);
    printf("enter le jour de nessance");
    scanf("%d",&t[dim].date.jour);
    printf("enter le id de deppartement");
    scanf("%d",&t[dim].id_Département);
    printf("enter la note generale de l'etudiant");
    scanf("%d",&t[dim].Note_générale);
    dim++;
}




void ajouter_dep (){
    printf("enter le id de departement(unique): ");
    scanf("%d",&v[dimm].id_dep);
    printf("enter le nom de departement");
    scanf("%49[^\n]",v[dimm].nom_dep);
    dimm++;
}
void modifier_info(){
    printf("entrer le numero d'etudiant por fair modification");
    scanf("%d",&nbr);
    for(i=0;i<dim;){
        if(t[i].Numéro_unique==nbr){
     printf("enter le nom d'etudiant");
    scanf("%29[^\n]",t[i].Nom);
    printf("enter le prenom d'etudiant");
    scanf("%29[^\n]",t[i].prenom);
    printf("enter l'anne de nessance: ");
    scanf("%d",&t[i].date.anee);
    printf("enter le mois de nessance");
    scanf("%d",&t[i].date.mois);
    printf("enter le jour de nessance");
    scanf("%d",&t[i].date.jour);
    printf("enter le id de deppartement");
    scanf("%d",&t[i].id_Département);
    printf("enter la note generale de l'etudiant");
    scanf("%d",&t[i].Note_générale);
    break;
        }
        else
printf("l'étudiant n'existe pas!");
    }
}



void suprimer_info(){
    printf("entrer le numero d'etudiant pour supprimer ");
    scanf("%d",&nbr);
    for(i=0;i<dim;){
        if(t[i].Numéro_unique==nbr){
            t[i]=t[i+1];
            i--;
}
else
printf("l'étudiant n'existe pas!");
}
}



void afficher_info(){
    printf("entrer votre numero d'etudiant pour afficher");
    scanf("%d",&nbr);
    for(i=0;i<dim;){
        if(t[i].Numéro_unique==nbr){
    printf(" nom: %d\n",t[i].Nom);
    printf(" prenom: %d\n",t[i].prenom);
    printf(" dat essence nessance: %d/%d%/d\n",t[i].date.anee,t[i].date.mois,t[i].date.jour);
    for(j=0;j<dimm;j++){
       if(t[i].id_Département==v[j].id_dep)
       printf(" iscrit dans la département de: %d\n",v[j].nom_dep);
    }
    printf("la note generale:",t[i].Note_générale);
    break;


}
}
int count=0;
int sum=0;
void calcule_moyyene(){
for(i=0;i<dimm;i++){
   for(j=0;j<dim;j++){
    if(t[j].id_Département==v[i].id_dep){
    sum=sum+t[j].Note_générale;
    count++;
   }
   }
 copie[i].moyenne_générale=sum/count;
}
printf("les moyenne generale de chaque deppartement sont: \n");
for(i=0;i<dimm;i++){
    printf("%s : %f ",v[i].nom_dep,copie[i].moyenne_générale);
    float cn=0;
for(i=0;i<dimm;i++){
    cn=cn+copie[i].moyenne_générale;
}
printf("la moyenne general au université est: %f\n",cn/dimm);
}

void to_lowercase(char z[]) {
    for (int i = 0; z[i]; i++) {
        z[i] = tolower((unsigned char)z[i]);
    }
}
void chercher() {
    char nom_cherche[30];
    char nom_lower[30];
    printf("vous aper le choix de recherche tapez:\n1: rechercher et afficher par nom.\n 2: aficher une list des etudiant dans une departement.\n 3: anuller le choix ");
    scanf("%d",&choix);
    switch (choix) {
    case 1:
    printf("Enter the last name of the student to search: ");
    scanf("%29s", nom_cherche);
    to_lowercase(nom_cherche);
    for (i = 0; i < dim; i++) {
strcpy(nom_lower, t[i].Nom);
to_lowercase(nom_lower);
if (strcmp(nom_lower, nom_cherche) == 0) {
     printf(" nom: %d\n",t[i].Nom);
    printf(" prenom: %d\n",t[i].prenom);
    printf(" dat essence nessance: %d/%d%/d\n",t[i].date.anee,t[i].date.mois,t[i].date.jour);
    for(j=0;j<dimm;j++){
       if(t[i].id_Département==v[j].id_dep)
       printf(" iscrit dans la département de: %d\n",v[j].nom_dep);
    }
    printf("la note generale:",t[i].Note_générale);
    break;
               }
            }
            printf("etudiant n'existe pas!\n");
            break;
        default:
            printf("Invalid choix!\n");
            break;
        case 2:

    printf("Enter le numero de departement: ");
    scanf("%d",&nbr);
    to_lowercase(nom_cherche);
    for (i = 0; i < dimm; i++) {
        if (t[i].id_Département==nbr) {
             printf("les etudiant insctit dans departement de %s sont:\n",v[i].nom_dep);
     printf("nom\tprenom\tdate de naissance\note generale\n");
        for (j = 0; j < dim; j++) {
if (t[i].id_Département==v[i].id_dep) {
        printf("%s\t%s\t%d/%d/%d\t%f",t[i].Nom,t[i].prenom,t[i].date.anee,t[i].date.mois,t[i].date.jour,t[i].Note_générale);
    }
        }
        }
    }
    break;
    case 3:
    break;
}
void afficher_par_alpha() {
    etudiant b[100000];
    etudiant temp;
    for (int i = 0; i < dim; i++) {
        b[i] = t[i];
    }
    for (int i = 0; i < dim; i++) {
        to_lowercase(t[i].Nom);
    }

    for (int i = 0; i < dim - 1; i++) {
        for (int j = i + 1; j < dim; j++) {
            if (strcmp(b[i].Nom, b[j].Nom) > 0) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    printf("les liste des etudiantes en ordre alphabetique :\n");
    for (int i = 0; i < dim - 1; i++) {
        printf("%s\t%s\t%d/%d/%d\t%f",t[i].Nom,t[i].prenom,t[i].date.anee,t[i].date.mois,t[i].date.jour,t[i].Note_générale);}
}

void trie(){


}
int main(){
    return 0;
}
