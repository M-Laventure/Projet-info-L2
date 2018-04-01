# Projet-info-L2 

# **The Witcher Tactics Arena**

 Notre Projet consiste en le développement d'un jeu du style Tactics Arena (dont les personnages sont inspirés de l'oeuvre "The Witcher").

Un Tactics Arena est un jeu de stratégie où deux joueurs s'affrontent au tour par tour en manipulant un ensemble d'unités sur un plateau.
Chaque joueur a en début de partie plusieurs unités différentes à sa disposition pour former une équipe. Chaque type d'unité dispose de caractéristiques différentes ( déplacement, attaque, défense etc..).  
Le but du jeu est d'utiliser à bon escient les spécificités de ses unités afin d'éliminer toutes les unités adverses. 

## *Index*

 **I/[Règles du jeu](#Règles-du-jeu)**  
 
 **II/[Insructions d'utilisation](#Instructions-d'utilisation)**  
 
 **III/[Conception](#Etapes-de-conception)**  
 
 **V/[Documentation](#Documentation)**  
 
 **VI/[Contributeurs](#Contributeurs)**  

 
 - - -
 ## Règles du jeu
  
  1. Constitution de l'équipe  
  
     Le jeu débute par une sélection et un placement sur le plateau successif des unités de chaque joueur.  
     Les joueurs sélectionnent un crédit limite qui déterminera la constitution de leur équipe : Chaque type d'unité coûte un    certain crédit et la seule restriction pour le joueur est de ne pas former une équipe dépassant le crédit maximum définit au préalable.  
     La liste des personnages, leur identifiant et leur coût en crédit est affiché à l'écran avant chaque composition d'équipe d'un joueur. (*voir tableau statistiques*)  
    
  2. Déroulement du tour  
  
     Le joueur 1 commence à jouer, alternativement le joueur 2.   
     L'ordre de jeu des unités est définit selon l'ordre de déploiement de celles-ci :   
     Ordre de jeu  
      -Tour 1. Unité N°1 joueur1  
      -Tour 2. Unité N°1 joueur2  
      -Tour 3 Unité N°2 joueur1  
      -Tour 4 Unité N°2 joueur2  
      etc..  
      Pendant un tour, le joueur peut effectuer un déplacement et/ou une attaque contre une unité adverse allié ou adverse. Le joueur à le choix entre l'attaque normale et spéciale propre à son unité courante.  ( Attaque 
      Tout déplacement devra être réalisé avant une attaque si le joueur compte déplacer son unité pendant le tour.  
      Une unité ayant attaqué pendant le tour ne peut plus être déplacé durant le même tour.

  3. Fin de partie 
  
     Lorsque un des deux joueurs a éliminé toutes les unités adverses, il remporte la partie et celle-ci prend fin. 
     Si un joueur passe son tour 4 fois de suite, le joueur adverse remporte la partie.
    
  
  4. Tableau  des caractéristiques des personnages
  
   
  | Personnage : Id   | Crédit        | Points de vie | Attaque | Défense | Points déplacement*   | Portée attaque*| Type*|
  |:------------------|:--------------|:--------------|:--------|:--------|:----------------------|:---------------|:-----| 
  | Witcher : 0       |     20        |       10      |   4     |   40    |         3             |      3/3       |   3  |
  | Mage    : 1       |     15        |       6       |   6     |   20    |         2             |      3/3       |   1  | 
  | Scoia'tel: 2      |     10        |       6       |   3     |   20    |         3             |      3/2       |   1  | 
  | Nains   : 3       |     10        |       7       |   4     |   30    |         3             |      2/2       |   1  | 
  | Spectre : 4       |     10        |       6       |   2     |   40    |         3             |      2/3       |   2  | 
  | Wyvern  : 5       |     20        |       10      |   3     |   40    |         3             |      3/3       |   2  | 
  | Leshen  : 6       |     15        |       8       |   4     |   40    |         2             |      2/2       |   2  |
  | Cyclope : 7       |     15        |       10      |   4     |   30    |         2             |      2/2       |   2  |  
  | Doppler : 8       |     10        |       5       |   2     |   30    |         4             |      2/3       |   3  | 
  
  5. Particularités
  
   + Points déplacement : Les classes Wyvern et Spectre peuvent se déplacer au travers des obstacles et des autres unités.
    
   + Portée attaque : La portée d'attaque est définie par une certaine portée verticale et horizontale, ici :     Horizontale/Verticale
   
   + Type : Les classes peuvent être de type humanoide, monstre ou hybride, respectivement représentées ici par 1, 2 et 3
            Les unités de type 1 infligent plus de dégats à celles de type 2 et réciproquement.
            Les unités de type 3 infligent plus de dégats à celles de type 1 et 2.
            
    
    
  - - - 
  ## Instructions d'utilsation 
  
  
  - - - 
  
  ## Conception ( *Voir rapport pour plus de détails )
  
  * Noyau de jeu  
  
       * Génération de la matrice plateau 
       
       * Génération des obstacles    
    
       * Mises en oeuvres  
   
           * Déploiement des unités/ définition de l'ordre de jeu
           * Attaque / Déplacement d'une unité
           * Fin de partie  
   
   * Menu de jeu ( dans le terminal)
   
   * Sauvegarde/Chargement 
    
  + Interface graphique (SDL) 
     
    
  
  
  - - - 
  
  ## Documentation 
  
  - - -    
  
  
  ## Contributeurs 
  
  + Aurelien Dad
  + Ossan Kassegne
  + Marin Laventure
  
  
  
  
  
 
  
 
 
 



