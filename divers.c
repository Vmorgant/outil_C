int Rand_Int(int min, int max){
/**
 * \fn Rand_Int(int min, int max)
 * \brief Fonction renvoyant un nombre compris entre min et max
 */
	int nombre_aleatoire = 0;
	srand(time(NULL));
        nombre_aleatoire = rand()%(max-min)+min;
	return nombre_aleatoire;
}
