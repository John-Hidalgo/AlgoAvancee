int Min(int p_valeur1, int p_valeur2)
{
	int min = p_valeur1;
	if (p_valeur1 > p_valeur2)
	{
		min = p_valeur2;
	}
	return min;
}
int Max(int p_valeur1, int p_valeur2)
{
	int max = p_valeur1;
	if (p_valeur1 < p_valeur2)
	{
		max = p_valeur2;
	}
	return max;
}