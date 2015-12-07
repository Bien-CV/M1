/**
 * @class Robot
 *
 * @brief Classe contenant les differentes actions et senseurs du robot
 *
 * @author Groupe MarcoPolo
 *
 */

#ifndef ROBOT_HPP
#define	ROBOT_HPP

#include<vector>

class Robot {
public:
    
    Robot();
    Robot(const Robot& orig);
    virtual ~Robot();
    
    //----------Fonctions en rapport avec la Carte----------
    /**
     * \brief Retourne le contenu d'une cellule d'id cell.
     * @param cell L'id de la cellule dont le contenu sera retourné.
     * @return Le contenu de la cellule cell dont les valeurs peuvent etre:\
     * CELL_UNKNOWN\
     * CELL_OBSTACLE\
     * CELL_EMPTY\
     * valant respectivement -1, 0, 1
     * */
    int getCellContent(int cell);
    
    /**
     * \brief Indique sur quel cellule votre robot se trouve.
     * @return la cellule où se trouve votre robot.
     */
    int getCell();
    
    /**
     * \brief Retourne la distance entre deux cellules cell1 et cell2.
     * La distance retournée est exprimée en nombre de cellules, et ne tient pas compte des divers obstacles entre les deux cellules. 
     * @param cell1 L'id de la cellule de départ.
     * @param cell2 L'id de la cellule d'arrivée.
     * @return La distance entre les deux cellules cell1 et cell2.
     */
    int getCellDistance(int cell1, int cell2);
    
    /**
     * \brief Détermine si une cellule est vide.
     * @param cell La cellule à tester.
     * @return vrai si la cellule est vide, faux sinon.
     */
    bool isEmptyCell(int cell);
    
    /**
     * \brief Détermine si le contenu de la cellule cell est un obstacle.
     * @param cell  La cellule à tester.
     * @return vrai si la cellule contient un obstacle, faux sinon.
     */
    bool isObstacle(int cell);
    
    /**
     * \brief Détermine si la cellule cell est inexploré.
     * @param cell La cellule à tester.
     * @return vrai si la cellule est encore inconnue, faux sinon.
     */
    bool isUnknown(int cell);
    
    /**
     * \brief Détermine si deux cellules cell1 et cell2 sont sur la même ligne.
     * @param cell1 La première cellule.
     * @param cell2 La deuxième cellule
     * @return vrai si les deux cellules sont sur la même ligne, faux sinon.
     */
    bool isOnSameLine(int cell1, int cell2);
    
    /**
     * @brief Retourne un vector qui contient toutes les cellules qui sont à la distance en parametre
     * @param distance
     * @return les cellule a la distance en paramètre
     */
    vector<int> getCelluleALaDistance(int distance);
    
    //----------Fonctions en rapport avec la Mission----------
    
    /**
     * \brief Détermine combien de cellules ont déjà été explorées.
     * @return le nombre de cellules connues.
     */
    int getCellsDiscoveredSize();
    
    /**
     * \brief Détermine combien de cellules sont encore inexplorées.
     * @return le nombre de cellules inconnues.
     */
    int getCellsUnknownSize();
    
    /**
     * \brief Détermine les cellules encore inexplorées.
     * @return le tableau contenant les cellules inconnues.
     */
    vector<int> getCellsUnknown();
    
    /**
     * \brief Détermine les cellules découvertes.
     * @return le tableau contenant les cellules connues.
     */
    vector<int> getCellsDiscovered();
    
    /**
     * \brief Détermine le nombre total de cellule dans la carte.
     * @return le nombre de cellules total.
     */
    int getMapSize();
    
    
    //----------Fonctions en rapport avec le Mouvement----------
    
    
    // à voir si on laisse sachant qu'il faudra calculer des chemins
    /**
     * \brief Rapproche votre robot d'une cellule cell.
     * @param cell la cellule vers laquelle votre robot doit se rapprocher.
     * @return  Le nombre de cellules franchies.
     */
    int moveTowardCell( int cell);
    
    /**
     * \brief Avance le robot vers le Haut.
     * @return Le nombre de cellules franchies.
     */
    int avancerHaut();
    
    /**
     * \brief Avance le robot vers le Haut d'un nombre de cases données.
     * @param nb le nombre de cases à avancer.
     * @return Le nombre de cellules franchies.
     */
    int avancerHaut(int nb);
    
    /**
     * \brief Avance le robot vers le Bas.
     * @return Le nombre de cellules franchies.
     */
    int avancerBas();
    
    /**
     * \brief Avance le robot vers le bas d'un nombre de cases données.
     * @param nb le nombre de cases à avancer.
     * @return Le nombre de cellules franchies.
     */
    int avancerBas(int nb);
    
    /**
     * \brief Avance le robot vers la gauche.
     * @return Le nombre de cellules franchies.
     */
    int avancerGauche();
    
    /**
     * \brief Avance le robot vers la gauche d'un nombre de cases données.
     * @param nb le nombre de cases à avancer.
     * @return Le nombre de cellules franchies.
     */
    int avancerGauche(int nb);
    
    /**
     * \brief Avance le robot vers la droite.
     * @return Le nombre de cellules franchies.
     */
    int avancerDroite();
    
    /**
     * \brief Avance le robot vers la droite d'un nombre de cases données.
     * @param nb le nombre de cases à avancer.
     * @return Le nombre de cellules franchies.
     */
    int avancerDroite(int nb);
    
    /**
     * Permet d'obtenir l'identifiant de la cellule située a droite de la notre
     * @return l'id de la cellule de droite
     */
    int getDroiteCell();
    
    /**
     * Permet d'obtenir l'identifiant de la cellule située a droite de la cellule passée en paramètre
     * @param cell la cell cible
     * @return l'identifiant de la cellule de droite
     */
    int getDroiteCell(int cell);
    
    /**
     * Permet d'obtenir l'identifiant de la cellule située a gauche de la notre
     * @return l'id de la cellule de droite
     */
    int getGaucheCell();
    
    /**
     * Permet d'obtenir l'identifiant de la cellule située a gauche de la cellule passée en paramètre
     * @param cell la cell cible
     * @return l'identifiant de la cellule de gauche
     */
    int getGaucheCell(int cell);
    
    /**
     * Permet d'obtenir l'identifiant de la cellule située en bas de la notre
     * @return l'id de la cellule du bas
     */
    int getBasCell();
    
    /**
     * Permet d'obtenir l'identifiant de la cellule située en bas de la cellule passée en paramètre
     * @param cell la cell cible
     * @return l'identifiant de la cellule du bas
     */
    int getBasCell(int cell);
    
    /**
     * Permet d'obtenir l'identifiant de la cellule située en haut de la notre
     * @return l'id de la cellule du haut
     */
    int getHautCell();
    
    /**
     * Permet d'obtenir l'identifiant de la cellule située en haut de la cellule passée en paramètre
     * @param cell la cell cible
     * @return l'identifiant de la cellule du haut
     */
    int getHautCell(int cell);
    
    /**
     * Permet de savoir si le robot peut se déplacer vers la droite ou s'il y a un obstacle
     * @return true si la case de droite est accessible, false sinon
     */
    bool peutAllerADroite();

    /**
     * Permet de savoir si le robot peut se déplacer vers la gauche ou s'il y a un obstacle
     * @return true si la case de droite est accessible, false sinon
     */    
    bool peutAllerAGauche();

    /**
     * Permet de savoir si le robot peut se déplacer vers le bas ou s'il y a un obstacle
     * @return true si la case de droite est accessible, false sinon
     */    
    bool peutAllerEnBas();

    /**
     * Permet de savoir si le robot peut se déplacer vers le haut ou s'il y a un obstacle
     * @return true si la case de droite est accessible, false sinon
     */    
    bool peutAllerEnHaut();
    
    /**
     * Effectue les déplacements correspondant au vector en parametre
     * @param directions, cf enum direction dans IA_HPP (Voir s'il faut la déplacer ailleur)
     * @return true si le robot a effectué la totalité des mouvements
     */
    bool effectuerDeplacements(vector<direction> directions);
    
private:
    /**
     * Permet d'avancer d'une case vers le haut
     * @return true si on a pu avancer, false sinon
     */
    bool avancerHautUneFois();
    
    /**
     * Permet d'avancer d'une case vers le bas
     * @return true si on a pu avancer, false sinon
     */
    bool avancerBasUneFois();
    
    /**
     * Permet d'avancer d'une case vers la droite
     * @return true si on a pu avancer, false sinon
     */
    bool avancerDroiteUneFois();
    
    /**
     * Permet d'avancer d'une case vers la gauche
     * @return true si on a pu avancer, false sinon
     */
    bool avancerGaucheUneFois();

};

#endif	/* ROBOT_HPP */

