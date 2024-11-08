#ifndef LABYRINTHE_H
#define LABYRINTHE_H 
#include <vector>
using namespace std;

class Labyrinthe {
public:
    Labyrinthe(int largeur, int hauteur);
    void GenererLabyrinthe();
    void AfficherLabyrinthe() const;


    int getCell(int y, int x) const; // دالة جديدة للوصول إلى خلايا الشبكة
    int getLargeur() const { return largeur; }
    int getHauteur() const { return hauteur; }

private:
    int largeur;
    int hauteur;
    vector<vector<int>> grille;
    void CreerChemin(int x, int y);
};

#endif // LABYRINTHE_H
/*largeur و hauteur: يمثلان عرض وارتفاع المتاهة.
grille: مصفوفة ثنائية الأبعاد تمثل المتاهة؛ حيث تكون القيم (1) للجدران و(0) للممرات.
الدوال:
GenererLabyrinthe(): دالة توليد المتاهة.
AfficherLabyrinthe(): لعرض المتاهة في الواجهة الرسومية.
CreerChemin(int x, int y): دالة مساعدة لتكوين ممرات المتاهة.*/

// Labyrinthe.h

