#include <ioStream>

int Recherche(int p_tableau[], int p_element)
{
	int longeur = sizeof(p_tableau); /// sizeof(int);
	int i = 0;
	int place = -1;
	for (i = 0; i <= longeur; i++)
	{
		if (p_tableau[i] == p_element)
		{
			place = i;
			break;
		}
	}
	return place;
}

int RechercheDichotamiqueRecurrance(int p_tableau[], int p_element,int inf, int sup)
{
	if (inf > sup)
		return - 1;
	
	int milieu = (inf + sup) / 2;
	//int* pMilieu = &milieu;

	if (p_tableau[milieu] == p_element)
		return milieu;
	else if (p_tableau[milieu] > p_element)
	{
		return RechercheDichotamiqueRecurrance(p_tableau, p_element, inf, milieu - 1);
	}
	else
	{
		//printf("%d\n", pMilieu);
		return RechercheDichotamiqueRecurrance(p_tableau, p_element, milieu + 1, sup);
	}
}
int RechercheDichotamique(int p_tableau[], int p_element)
{
	int longeur = sizeof(p_tableau);
	return RechercheDichotamiqueRecurrance(p_tableau,p_element,0,10);
}
void Echanger(int p_tableau[], int p_element1, int p_element2) 
{
	int temp = p_tableau[p_element2];
	p_tableau[p_element2] = p_tableau[p_element1];
	p_tableau[p_element1] = temp;
}
int TrierParPivot(int p_tableau[],int inf,int sup)
{
	int pivot = p_tableau[sup];
	int moinsPivot = inf - 1;
	int plusPivot = inf;
	for (plusPivot = inf; plusPivot < sup; plusPivot++)
	{
		if (p_tableau[moinsPivot] < pivot)
		{
			moinsPivot++;
			Echanger(p_tableau,plusPivot,moinsPivot);
		}
		
	}
	Echanger(p_tableau, sup, plusPivot - 1);
	return plusPivot - 1;
}
void Partitioner(int p_tableau[], int inf, int sup)
{
	if (inf < sup)
	{
		int indicePivot = TrierParPivot(p_tableau, inf, sup);
		Partitioner(p_tableau, indicePivot + 1, sup);
		Partitioner(p_tableau, inf, indicePivot - 1);
	}
}
void TriRapide(int p_tableau[])
{
	int longeur = sizeof(p_tableau);// / sizeof(int);
	Partitioner(p_tableau, 0, 10);
}




