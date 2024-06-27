#pragma once

class Liste {
public:
	Liste();
	void Ajouter(int p_element);
	//void Supprimer(int p_index);
	//int Obtenir(int p_index);
	//void Definir(int p_index, int p_element);
	int GetElementDuTableau(int p_index);
//private:
	int m_nombreDElements = 0;
	int m_elements[20];
};
