#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} date_ness;

typedef struct {
    int id_dep;
    char nom_dep[40];
    float moyenne_generale;
} departement;

typedef struct {
    int numero_unique;
    char nom[30];
    char prenom[30];
    int id_departement;
    float note_generale;
    date_ness date;
} etudiant;

etudiant t[100];
departement v[11];
int dim = 0;
int dimm = 0;
int i,j;
void ajouter_etud() {
    int id_et;
    int found = 0;
    printf("Entrez l'id de l'etudiant (unique) : ");
    scanf("%d", &id_et);
    for (int i = 0; i < dim; i++) {
        if (t[i].numero_unique == id_et) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Cet ID est deja utilise !\n");
    } else {
        t[dim].numero_unique = id_et;
        printf("Entrez le nom : ");
        scanf(" %29[^\n]", t[dim].nom);
        printf("Entrez le prenom : ");
        scanf(" %29[^\n]", t[dim].prenom);
        printf("Date de naissance.\n");
        printf("Annee : ");
        scanf("%d", &t[dim].date.annee);
        printf("Mois : ");
        scanf("%d", &t[dim].date.mois);
        printf("Jour : ");
        scanf("%d", &t[dim].date.jour);
        printf("Entrez l'id du departement : ");
        scanf("%d", &t[dim].id_departement);
        printf("Entrez la note generale de l'etudiant : ");
        scanf("%f", &t[dim].note_generale);
        dim++;
    }
}
void ajouter_dep() {
    int id_dep;
    int found = 0;
    printf("entrez l'id de departement (unique) : ");
    scanf("%d", &id_dep);
    for (int i = 0; i < dimm; i++) {
        if ( v[i].id_dep== id_dep) {
        found = 1;
        break;
       }
    }
    if (found) {
        printf("Cet ID est deja utilise !\n");
    } else {
      v[dimm].id_dep== id_dep ;
    printf("\nEntrez le nom du departement : ");
    scanf(" %39[^\n]", v[dimm].nom_dep);
    v[dimm].moyenne_generale;
    dimm++;
}
}
void afficher_nbr_et_depa(){
    int count=0;
    for(i=0;i<dimm;i++){
        for(j=0;j<dim;j++){
          if(t[j].id_departement == v[i].id_dep){
              count++;
          }  
  }
   printf("le nbr des etudiant dans departement de %s est : %d\n",v[i].nom_dep,count);
   count=0;
   }
}
void modifier_info() {
    int nbr;
    printf("\nEntrez l'id de l'etudiant : ");
    scanf("%d", &nbr);
    for (int i = 0; i < dim; i++) {
        if (t[i].numero_unique == nbr) {
            printf("Entrez les informations de l'etudiant\n");
            printf("Nom : ");
            scanf(" %29[^\n]", t[i].nom);
            printf("Prenom : ");
            scanf(" %29[^\n]", t[i].prenom);
            printf("Date de naissance.\n");
            printf("Annee : ");
            scanf("%d", &t[i].date.annee);
            printf("Mois : ");
            scanf("%d", &t[i].date.mois);
            printf("Jour : ");
            scanf("%d", &t[i].date.jour);
            printf("Id du departement : ");
            scanf("%d", &t[i].id_departement);
            printf("Entrez la note generale : ");
            scanf("%f", &t[i].note_generale);
            return;
        }
    }
    printf("\nEtudiant introuvable !\n");
}

void supprimer_info() {
    int nbr;
    printf("Entrez l'id de l'etudiant a supprimer : ");
    scanf("%d", &nbr);
    for (int i = 0; i < dim; i++) {
        if (t[i].numero_unique == nbr) {
            for (int j = i; j < dim - 1; j++) {
                t[j] = t[j + 1];
            }
            dim--;
            printf("Suppression avec succes !\n");
            return;
        }
    }
    printf("Etudiant introuvable !\n");
}

void afficher_info() {
    int nbr;
    printf("Entrez l'id de l'etudiant pour afficher les informations :\n ");
    scanf("%d", &nbr);
    for (int i = 0; i < dim; i++) {
        if (t[i].numero_unique == nbr) {
            printf("Nom : %s\n", t[i].nom);
            printf("Prenom : %s\n", t[i].prenom);
            printf("Date de naissance : %d/%d/%d\n", t[i].date.jour, t[i].date.mois, t[i].date.annee);
            printf("Departement : ");
            for (int j = 0; j < dimm; j++) {
                if (t[i].id_departement == v[j].id_dep) {
                    printf("  %s\n", v[j].nom_dep);
                    break;
                }
            }
            printf("Note generale : %.2f\n", t[i].note_generale);
            return;
        }
    }
    printf("Etudiant introuvable !\n");
}

void calcule_moyenne() {
    for (int i = 0; i < dimm; i++) {
        int count = 0;
        float sum = 0;
        for (int j = 0; j < dim; j++) {
            if (t[j].id_departement == v[i].id_dep) {
                sum += t[j].note_generale;
                count++;
            }
        }
        if (count > 0) {
            v[i].moyenne_generale = sum / count;
        } else {
            v[i].moyenne_generale = 0;
        }
    }
    printf("Moyenne generale des departements :\n");
    for (int i = 0; i < dimm; i++) {
        printf("%s : %.2f\n", v[i].nom_dep, v[i].moyenne_generale);
    }
    float t_sum = 0;
    int t_count = 0;
    for (int i = 0; i < dimm; i++) {
        t_sum += v[i].moyenne_generale;
        t_count++;
    }
    if (t_count > 0) {
        printf("Moyenne generale de l'universite : %.2f\n", t_sum / t_count);
    } else {
        printf("Aucun departement pour calculer la moyenne.\n");
    }
}

void afficher_statistiques() {
    float seuil;
    printf("Entrez le seuil de note :\n ");
    scanf("%f", &seuil);
    printf("Les etudiants ayant une note superieure ou egale a %.2f :\n", seuil);
    for (int i = 0; i < dim; i++) {
        if (t[i].note_generale >= seuil) {
            printf("%s %s : %.2f\n", t[i].nom, t[i].prenom, t[i].note_generale);
        }
    }
    etudiant tri_meilleur[100];
    tri_meilleur[100]=t[100];
    for (int i = 0; i < dim - 1; i++) {
        for (int j = i + 1; j < dim; j++) {
            if (tri_meilleur[i].note_generale < tri_meilleur[j].note_generale) {
                etudiant temp = tri_meilleur[i];
                tri_meilleur[i] = tri_meilleur[j];
                tri_meilleur[j] = temp;
            }
        }
    }
    printf("Les 3 meilleurs etudiants :\n");
    for (int i = 0; i < 3 && i < dim; i++) {
        printf("%s %s : %.2f\n", tri_meilleur[i].nom, tri_meilleur[i].prenom, tri_meilleur[i].note_generale);
    }
    printf("Nombre d'etudiants reussi (note >= 10) :\n");
    for (int i = 0; i < dimm; i++) {
        int reussit_count = 0;
        for (int j = 0; j < dim; j++) {
            if (t[j].id_departement == v[i].id_dep && t[j].note_generale >= 10) {
                reussit_count++;
            }
        }
        printf("%s : %d\n", v[i].nom_dep, reussit_count);
    }
}

void chercher() {
    int choix;
    char nom_cherche[30];
    printf("Choisissez une option de recherche :\n");
    printf("1 : Recherche par nom.\n");
    printf("2 : Lister les etudiants d'un departement.\n");
    printf("3 : Annuler\n");
    scanf("%d", &choix);
    switch (choix) {
        case 1:
            printf("Entrez le nom pour rechercher : ");
            scanf(" %29s", nom_cherche);
            for (int i = 0; i < dim; i++) {
                if (strcmp(t[i].nom, nom_cherche) == 0) {
                    afficher_info();
                    return;
                }
            }
            printf("Etudiant introuvable !\n");
            break;
        case 2:
            printf("entrez l'id du departement : ");
            int dept_id;
            scanf("%d", &dept_id);
            printf("Etudiants dans le departement :\n");
            for (int i = 0; i < dim; i++) {
                if (t[i].id_departement == dept_id) {
                    printf("%s %s : %.2f\n", t[i].nom, t[i].prenom, t[i].note_generale);
                }
            }
            break;
        case 3:
            break;
        default:
            printf("Choix invalide !\n");
            break;
    }
}

void afficher_par_alpha() {
    etudiant b[100];

    for (int i = 0; i < dim; i++) {
        b[i] = t[i];
    }

    for (int i = 0; i < dim - 1; i++) {
        for (int j = i + 1; j < dim; j++) {
            if (strcmp(b[i].nom, b[j].nom) > 0) {
                etudiant temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    printf("Etudiants par ordre alphabetique :\n");
    for (int i = 0; i < dim; i++) {
        printf("%s %s : %.2f\n", b[i].nom, b[i].prenom, b[i].note_generale);
    }
}


void trier_par_note_dep() {
    etudiant b[100];
    for (int i = 0; i < dim; i++) {
        b[i] = t[i];
    }
    for ( i = 0; i < dim - 1; i++) {
        for ( j = i + 1; j < dim; j++) {
            if (b[i].note_generale < b[j].note_generale) {
                etudiant temp = b[i];
                b[i] = b[j];
                b[j] = temp;
                
            }
        }
    }
    printf("etudiants tries par note (de la plus haute a la plus basse) :\n");
for (int y = 0; y < dimm; y++) {
 printf("eepartement : %s\n", v[y].nom_dep);
for (int i = 0; i < dim; i++) {
  if (b[i].id_departement == v[y].id_dep) {
 printf("%s %s : %.2f\n", b[i].nom, b[i].prenom, b[i].note_generale);
  }
 }
}
}

void trier_par_statut() {
    printf("Les etudiants passes par departement :\n");
    for (int j = 0; j < dimm; j++) {
        printf("\n");
        printf("*****Departement %s*****\n", v[j].nom_dep);
        for (int i = 0; i < dim; i++) {
            if (t[i].note_generale >= 10 &&t[i].note_generale < 12&& t[i].id_departement == v[j].id_dep) {
                printf("%s %s : %.2f passable \n", t[i].nom, t[i].prenom, t[i].note_generale);
            }
            if (t[i].note_generale >= 12 &&t[i].note_generale < 14 && t[i].id_departement == v[j].id_dep) {
                printf("%s %s : %.2f assez_bien \n", t[i].nom, t[i].prenom, t[i].note_generale);
            }
            if (t[i].note_generale >= 14 &&t[i].note_generale < 16  && t[i].id_departement == v[j].id_dep) {
                printf("%s %s : %.2f bien \n", t[i].nom, t[i].prenom, t[i].note_generale);
            }
            if (t[i].note_generale >= 16 && t[i].note_generale < 18 && t[i].id_departement == v[j].id_dep) {
                printf("%s %s : %.2f tres bien \n", t[i].nom, t[i].prenom, t[i].note_generale);
            }
            if (t[i].note_generale >= 16&&t[i].note_generale < 18 && t[i].id_departement == v[j].id_dep) {
                printf("%s %s : %.2f exellent \n", t[i].nom, t[i].prenom, t[i].note_generale);
            }
        }
        printf("*******************************");
        printf("\n");
    }
}


void menu() {
    printf("*******************************Menu*******************************\n");
    printf("** Liste des choix**\n");
    printf("1. Ajouter etudiant\n");
    printf("2. Ajouter departement\n");
    printf("3. Modifier les informations pour un etudiant\n");
    printf("4. Supprimer les informations pour un etudiant\n");
    printf("5. Afficher les informations d'un etudiant\n");
    printf("6. Calculer la moyenne generale pour un departement et pour l'universite\n");
    printf("7. Afficher les statistiques de l'universite\n");
    printf("\t\t8. Chercher un etudiant\n");
    printf("9. Afficher les etudiants par ordre alphabetique\n");
    printf("10. Trier les etudiants par moyenne generale\n");
    printf("\t11. Afficher le statut de reussite\n");
    printf("12. afficher le nombre total des etudiant dans chaque departement\n");
    printf("\t\t\t   13. Quitter\n");
    printf("******************************************************************\n");
}

int main() {
    int choix;
   strcpy(v[0].nom_dep, "Informatique");
    v[0].id_dep = 1;
    v[0].moyenne_generale = 0;
    strcpy(v[1].nom_dep, "Mathematiques");
    v[1].id_dep = 2;
    v[1].moyenne_generale = 0;
    strcpy(v[2].nom_dep, "Physique");
    v[2].id_dep = 3;
    v[2].moyenne_generale = 0;
    dimm = 3;
    t[0].numero_unique = 1001;
    strcpy(t[0].nom, "Ahmed");
    strcpy(t[0].prenom, "Ali");
    t[0].date.jour = 15;
    t[0].date.mois = 6;
    t[0].date.annee = 2000;
    t[0].id_departement = 1;
    t[0].note_generale = 14.5;
    t[1].numero_unique = 1002;
    strcpy(t[1].nom, "Sara");
    strcpy(t[1].prenom, "Fatma");
    t[1].date.jour = 22;
    t[1].date.mois = 3;
    t[1].date.annee = 2001;
    t[1].id_departement = 2;
    t[1].note_generale = 12.0;

    t[2].numero_unique = 1003;
    strcpy(t[2].nom, "Youssef");
    strcpy(t[2].prenom, "Mahmoud");
    t[2].date.jour = 10;
    t[2].date.mois = 12;
    t[2].date.annee = 1999;
    t[2].id_departement = 3;
    t[2].note_generale = 11.0;

    dim = 3;

    do {
        printf("\n\n");
        menu();
        printf("\t\tEntrez un choix pour continuer :\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                ajouter_etud();
                break;
            case 2:
                ajouter_dep();
                break;
            case 3:
                modifier_info();
                break;
            case 4:
                supprimer_info();
                break;
            case 5:
                afficher_info();
                break;
            case 6:
                calcule_moyenne();
                break;
            case 7:
                afficher_statistiques();
                break;
            case 8:
                chercher();
                break;
            case 9:
                afficher_par_alpha();
                break;
            case 10:
                trier_par_note_dep();
                break;
            case 11:
                trier_par_statut();
                break;
            case 12:
            afficher_nbr_et_depa();
            break;
            case 13:
                printf("vous avez quitte le programme. A la prochaine fois !\n");
                break;
        }
    } while (choix != 13);

    return 0;
}
