#include "joueur.h"

Joueur::Joueur(int startX, int startY, Labyrinthe* labyrinthe)
        : x(startX), y(startY), labyrinthe(labyrinthe) {}

int Joueur::getX() const {
    return x;
}

int Joueur::getY() const {
    return y;
}

void Joueur::moveUp() {
    y -= 1;
}

void Joueur::moveDown() {
    y += 1;
}

void Joueur::moveLeft() {
    x -= 1;
}

void Joueur::moveRight() {
    x += 1;
}
