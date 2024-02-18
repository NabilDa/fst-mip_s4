#include <stdio.h>


typedef struct testsville
{
	char ville[30];
	int NT;
	int NTP;
} TestsVille;


/**
 * chargerfichierTab - charge un fichier dans un tableau
 * @nomfichier: le nom du fichier
 * @T: le tableau
 * @taille: la taille du tableau
 */
void chargerFichierTab(char *nomfichier, TestsVille *T, int *taille)
{
	FILE *f;
	int i;

	f = fopen(nomfichier, "r");
	if (f == NULL)
	{
		printf("Le fichier n'existe pas.\n");
		return;
	}

	fscanf(f, "%d", taille);

	for (i = 0; i < *taille; i++)
	{
		fscanf(f, "%s%d%d", T[i].ville, &T[i].NT, &T[i].NTP);
	}
}


/**
 * afficherTestsVille - affiche les tests d'une ville
 * @T: variable de type structure TestsVille
 */
void afficherTestsVille(TestsVille T)
{
	printf("Ville : %12s\t", T.ville);
	printf("NT : %d\t", T.NT);
	printf("NTP : %d\n", T.NTP);
}


/**
 * afficherTestsVille - affiche un tableau de TestsVille
 * @T: le tableau
 * @taille: la taille du tableau.
 */
void afficherTabTests(TestsVille *T, int taille)
{
	int i;

	for (i = 0; i < taille; i++)
	{
		afficherTestsVille(T[i]);
	}
}


/**
 * tauxPositivite - calcule le taux de positivite dans une ville
 * @t: structure TestsVille
 *
 * Return: le taux de positivite dans la ville t.
 */
float tauxPositivite(TestsVille t)
{
	float TP;

	TP = ((float) t.NTP / t.NT) * 100;

	return (TP);
}


void afficherTauxPositivite(TestsVille *T, int taille)
{
	int i;

	for (i = 0; i < taille; i++)
	{
		printf("Ville : %s\t", T[i].ville);
		printf("TP : %.2f\n", tauxPositivite(T[i]));
	}
}


void stockerTPFichier(TestsVille *T, int taille, char *nomfichier)
{
	FILE *f;
	int i;

	f = fopen(nomfichier, "w");
	if (f == NULL)
	{
		printf("Le fichier n'existe pas.\n");
		return;
	}

	for (i = 0; i < taille; i++)
	{
		fprintf(f, "%12s\t", T[i].ville);
		fprintf(f, "%.2f\n", tauxPositivite(T[i]));
	}
}


/**
 * main - fonction principale
 *
 * Return: toujours 0.
 */
int main(void)
{
	int taille;
	TestsVille T[100];

	chargerFichierTab("testCovid19.txt", T, &taille);

	afficherTabTests(T, taille);

	stockerTPFichier(T, taille, "taux_positivite.txt");

	return (0);
}
