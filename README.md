# Projet-info-L2 : 

# **The Witcher Tactics Arena**

 Notre Projet consiste en le développement d'un jeu du style Tactics Arena (dont les personnages sont inspirés de l'oeuvre "The Witcher").

Un Tactics Arena est un jeu de stratégie où deux joueurs s'affrontent au tour par tour en manipulant un ensemble d'unités sur un plateau.
Chaque joueur a en début de partie plusieurs unités différentes à sa disposition pour former une équipe. Chaque type d'unité dispose de caractéristiques différentes ( déplacement, attaque, défense etc..).  
Le but du jeu est d'utiliser à bon escient les spécificités de ses unités afin d'éliminer toutes les unités adverses. 

## *Index*

 **I/[Règles du jeu](#Règlesdujeu)**  
 **II/[Insructions d'utilisation](#Instructionsd'utilisation)**  
 **III/[Conception](#Etapesdeconception)**  
 **V/[Documentation](#Documentation)**  
 **VI/[Contributeurs](#Contributeur)**  

 
 
 ### *Règles du jeu*
  
  1. Constitution de l'équipe  
    Le jeu débute par une sélection et un placement sur le plateau simultané des unités de chaque joueur.  
    Les joueurs sélectionnent un crédit limite qui déterminera la constitution de leur équipe : Chaque type d'unité coûte un   certain crédit et la seule restriction pour le joueur est de ne pas former une équipe dépassant le crédit maximum définit au préalable.  
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
     Pendant un tour, le joueur dispose d'un temps limité ( 1 minute) pour effectuer un déplacement et/ou une attaque contre une unité adverse ou pas. Le joueur à le choix entre l'attaque normale et spéciale propre à son unité courante.  
     Tout déplacement devra être réalisé avant une attaque si le joueur compte déplacer son unité pendant le tour.  
     Une unité ayant attaqué pendant le tour ne peut plus être déplacé durant le temps restant.  
    
       

     
      
  3. Fin de partie 
  
   Lorsque un des deux joueurs a éliminé toutes les unités adverses, il remporte ainsi la partie et celle-ci prend fin.
  
  4. Tableau  des caractéristiques des personnages
  
   
  | Personnage/       | Crédit| Points de vie | Attaque | Défense | Portée déplacement    | Portée attaque | Type |
  | Id_Personnage     |               |               |         |         |(Verticale/Horizontale)| (Idem depla)   |      |
  |:----------------  |:--------------|:--------------|:--------|:--------|:-------------------|:---------------|:-----| 
  | Witcher : 0       |   20          |   10       | 4       |4  |titre 5             | titre 6        |      |
  | Mage    : 1       |   15          | 6         | 6       |2|titre 4 |titre 5 | titre 6 | titre 7|
  | Scoia'tel: 2      |     10        | 6        | 3   |2|titre 4 |titre 5 | titre 6 | titre 7| 
  | Nains   : 3       |       10      | 8         | 4   | 3|titre 4 |titre 5 | titre 6 | titre 7| 
  | Spectre : 4       |     10        | 6          | 2   | 4|titre 5 | titre 6 | titre 7| 
  | Wyvern  : 5       |    20         | 10        | 3   | 4|titre 4 |titre 5 | titre 6 | titre 7| 
  | Leshen  : 6         |    15       | 8         | 4   | 4|titre 4 |titre 5 | titre 6 | titre 7| 
  | Cyclope : 7        |    15        | 10        | 4   | 3Titre 3|titre 4 |titre 5 | titre 6 | titre 7| 
  | Doppler : 8        |    10        | 5          | 2    | 3Titre 3|titre 4 |titre 5 | titre 6 | titre 7| 
  
  ### *Instructions d'utilsation*  
  
  
  
  ### *Conception*   
  
  + Noyau de jeu  
        +  
   
  + SDL  
   
  + Mise en réseau  
   
  + Idées d'améliorations  
    
  
  
  
  
  ### *Documentation*  
  
  ### *Contributeurs*  
  
  + Aurelien Dad
  + Ossan Kassegne
  + Marin Laventure
  
  
  
  
  
 
  
 
 
 



