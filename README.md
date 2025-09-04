# Cub3D

Projet graphique basé sur la même méthode 3D que Wolfenstein. On peut se déplacer sur une carte avec des textures mises dans le fichier carte.

---

## 🚀 Lancer le programme

1. **Compiler** le programme :
   ```bash
   make
   ```
   (dans le dossier où se situe le `Makefile`)

2. **Exécuter** le serveur :
   ```bash
   ./Cub3D <map>
   ```

---

## 🎮 Jouer
## 📝 Les déplacements

| Commandes | Descriptions |
|-----------|-------------|
|   **W**   |   Avancer   |
|   **S**   |   Reculer   |
|   **A**   |   Gauche    |
|   **D**   |   Droite    |
|  **➡️**   | Tourner la caméra à droite |
|  **⬅️**   | Tourner la caméra à gauche |

## 🗒️ Partie Mandatory
## 🎥 Visuel

![manda1](https://github.com/user-attachments/assets/c67da25d-b0cd-4171-88e8-da296d184be5

On peut traverser les murs en se déplaçant et en bougeant la caméra.

## ⭐ Partie bonus
## 🎥 Visuel

![bonus1](https://github.com/user-attachments/assets/5fad19f3-4063-4408-9a86-9ad642d5edc4)

Quelques ajouts ont été faits :

-Colisions ajoutées

-Mini carte en haut de l'écran (avec la touche "tab", on peut échanger la vision de jeu pour avoir la carte en grand)

-Optimisation pour les grandes cartes (la mini carte se charge autour du joueur seulement et pas entièrement)
