#ifndef JOUEUR_H
#define JOUEUR_H

#include "Labyrinthe.h"

class Joueur {
public:
    Joueur(int startX, int startY, Labyrinthe* labyrinthe);

    int getX() const;
    int getY() const;

    // دوال الحركة بعد التأكد من إمكانيتها
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    int x; // الموقع الأفقي لللاعب
    int y; // الموقع العمودي لللاعب
    Labyrinthe* labyrinthe; // مؤشر إلى المتاهة للتحقق من الخلايا

    // التحقق من أن الحركة ممكنة
    bool canMove(int newX, int newY) const;
};

#endif // JOUEUR_H
