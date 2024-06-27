#pragma once
template <class T>
class Liste
{
public:
	Liste();
	Liste(const Liste& p_listeAncienne);
	Liste(Liste&& p_listeADeplacer);
	~Liste();
	Liste& operator=(const Liste& p_listeACopier);
	Liste& operator=(Liste&& p_listeADeplacer);
	void AjouterFin(const T& p_valeur);
	void SupprimerFin();
	T Obtenir(const int& p_indice);
	int NombreElements() const;
	int Capacite() const;
	void Parcourir(void(*p_fonction(const int&)));
private:
	T* m_valeurs;
	int m_capacite;
	int m_nbElements;
};