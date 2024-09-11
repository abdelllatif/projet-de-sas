#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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

etudiant t[100000];
departement v[11];
departement copie[11];
int dim = 0;
int dimm = 0;
int i, j, nbr;
etudiant temp;

void ajouter_etud() {
    printf("Entrez l'id de l'etudiant (unique) : ");
    scanf("%d", &t[dim].numero_unique);
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
    printf("\nEntrez la note generale de l'etudiant : ");
    scanf("%f", &t[dim].note_generale);
    dim++;
}

void ajouter_dep() {
    printf("\nEntrez l'id du departement (unique) : ");
    scanf("%d", &v[dimm].id_dep);
    printf("\nEntrez le nom du departement : ");
    scanf(" %39[^\n]", v[dimm].nom_dep);
    dimm++;
}

void modifier_info() {
    int nbr;
    printf("\nEntrez l'id de l'etudiant : ");
    scanf("%d", &nbr);
    for (int i = 0; i < dim; i++) {
        if (t[i].numero_unique == nbr) {
            printf("entrez les informations de l'etudiant\n");
            printf("Nom : ");
            scanf(" %29[^\n]", t[i].nom);
            printf("Prenom : ");
            scanf(" %29[^\n]", t[i].prenom);
            printf("Date de naissance.\n");
            printf("Annee de naissance : ");
            scanf("%d", &t[i].date.annee);
            printf("Mois : ");
            scanf("%d", &t[i].date.mois);
            printf("Jour : ");
            scanf("%d", &t[i].date.jour);
            printf("Id du d�partement : ");
            scanf("%d", &t[i].id_departement);
            printf("Entrez la note g�n�rale : ");
            scanf("%f", &t[i].note_generale);
            return;
        }
    }
    printf("\netudiant introuvable !\n");
}

void supprimer_info() {
    int nbr;
    printf("Entrez l'id de l'�tudiant � supprimer : ");
    scanf("%d", &nbr);
    for (int i = 0; i < dim; i++) {
        if (t[i].numero_unique == nbr) {
            for (int j = i; j < dim - 1; j++) {
                t[j] = t[j + 1];
            }
            dim--;
            printf("suprimer avec sucsses!");
            return;
        }
    }
    printf("etudiant introuvable !\n");
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
            printf("Note g�n�rale : %.2f\n", t[i].note_generale);
            return;
        }
    }
    printf("�tudiant introuvable !\n");
}

void calcule_moyenne() {
    int count;
    int sum = 0;
    count = 0;
    for (int i = 0; i < dimm; i++) {
        for (int j = 0; j < dim; j++) {
            if (t[j].id_departement == v[i].id_dep) {
                sum =sum+t[j].note_generale;
                count++;
            }
        }
        if (count > 0) {
            v[i].moyenne_generale = sum / count;
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
    printf("Moyenne generale de l'universit : %.2f\n", t_sum / t_count);
}

void afficher_statistiques() {
    float seuil;
    printf("Entrez le seuil de note :\n ");
    scanf("%f", &seuil);
    printf("Les etudiants ayant une note superieure ou egale a %.2f :\n", seuil);
    for (int i = 0; i < dim; i++) {
        if (t[i].note_generale > seuil) {
            printf("%s %s : %.2f\n", t[i].nom, t[i].prenom, t[i].note_generale);
        }
    }
    etudiant tri_meilleur[100000];
    for (int i = 0; i < dim; i++)
     tri_meilleur[i] = t[i];
    for (int i = 0; i < dim - 1; i++) {
        for (int j = i + 1; j < dim; j++) {
         if (tri_meilleur[i].note_generale < tri_meilleur[j].note_generale) {
         temp = tri_meilleur[i];
        tri_meilleur[i] = tri_meilleur[j];
        tri_meilleur[j] = temp;
     }
    }
    }
    printf("Les 3 meilleurs etudiants :\n");
    for (int i = 0; i < 3 && i < dim; i++) {
        printf("%s %s : %.2f\n", tri_meilleur[i].nom, tri_meilleur[i].prenom, tri_meilleur[i].note_generale);
    }
    int reussit_count;
    printf("Nombre d'etudiants reussi (note >= 10) :\n");
    for (int i = 0; i < dimm; i++) {
        reussit_count = 0;
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
                if (strcasecmp(t[i].nom, nom_cherche) == 0) {
                    afficher_info();
                    return;
                }
            }
            printf("etudiant introuvable !\n");
            break;
        case 2:
            printf("Entrez l'id du departement : ");
            int dept_id;
            scanf("%d", &dept_id);
            printf("etudiants dans le departement :\n");
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
    etudiant b[100000];
   b[i]=t[i] ;
    etudiant temp;
    for (int i = 0; i < dim - 1; i++) {
        for (int j = i + 1; j < dim; j++) {
            if (strcmp(b[i].nom, b[j].nom) > 0) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    printf("etudiants par ordre alphabetique :\n");
    for (int i = 0; i < dim; i++) {
        printf("%s %s : %.2f\n", b[i].nom, b[i].prenom, b[i].note_generale);
    }
}

void trier_par_note() {
    etudiant b[100000];
    for (int i = 0; i < dim - 1; i++)
    b[i]=t[i];
    etudiant temp;
    for (int i = 0; i < dim - 1; i++) {
        for (int j = i + 1; j < dim; j++) {
            if (b[i].note_generale < b[j].note_generale) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    printf("�tudiants tri�s par note (de la plus haute � la plus basse) :\n");
    for (int i = 0; i < dim; i++) {
        printf("%s %s : %.2f\n", b[i].nom, b[i].prenom, b[i].note_generale);
    }
}

void trier_par_statut() {
    etudiant b[100000];
    memcpy(b, t, sizeof(t));
    etudiant temp;
    int count = 0;
    for (int i = 0; i < dim - 1; i++) {
        for (int j = i + 1; j < dim; j++) {
            if (b[i].note_generale < b[j].note_generale) {
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    printf("etudiants ayant reussi (note >= 10) :\n");
    for (int i = 0; i < dim; i++) {
        if (b[i].note_generale >= 10) {
            printf("%s %s : %.2f\n", b[i].nom, b[i].prenom, b[i].note_generale);
        }
    }
}

void menu() {
    printf("****************Menu :****************\n");
    printf("\t\t**** Liste des choix ****\n");
    printf("\t\t1. Ajouter etudiant\n");
    printf("\t\t2. Ajouter departement\n");
    printf("3. Modifier les informations pour un etudiant\n");
    printf("4. Supprimer les informations pour un etudiant\n");
    printf("5. Afficher les informations d'un etudiant\n");
    printf("6. Calculer la moyenne generale pour un departement\n\t\t\t et pour l'universite\n");
    printf("7. Afficher les statistiques de l'universite\n");
    printf("\t\t\t8. Chercher un etudiant\n");
    printf("9. Afficher les etudiants par ordre alphabetique\n");
    printf("10. Trier les etudiants par moyenne generale\n");
    printf("\t11. Afficher le statut de reussite\n");
    printf("\t\t\t   12. Quitter\n");
    printf("****************************************\n");
}

int main() {
    int choix;
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
                trier_par_note();
                break;
            case 11:
                trier_par_statut();
                break;
            case 12:
                printf("Vous avez quitte le programme. a la prochaine fois !\n");
                break;
            default:
                printf("Choix invalide !\n");
                break;
        }
    } while (choix != 12);
    return 0;
}
