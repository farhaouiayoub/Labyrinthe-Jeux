#include <iostream> 
#include "Labyrinthe.h"
#include <iostream>
#include <vector>
#include <cstdlib>   // لـ rand و srand
#include <ctime>     // لـ time
#include <algorithm> // لـ std::shuffle
#include <random>    // لـ std::random_device و std::mt19937
using namespace std;

Labyrinthe::Labyrinthe(int largeur, int hauteur): largeur(largeur), hauteur(hauteur), grille(hauteur, vector<int>(largeur, 1)) {
    srand(time(0)); // تهيئة التوليد العشوائي (غير ضروري لـ std::shuffle ولكن جيد للإعدادات الأخرى)
}

void Labyrinthe::GenererLabyrinthe() {
    CreerChemin(1, 1); // بدء إنشاء المتاهة من نقطة (1،1)
}

void Labyrinthe::CreerChemin(int x, int y) { 
    grille[y][x] = 0; // جعل هذه النقطة ممرًا

    // ترتيب الاتجاهات بشكل عشوائي
    int directions[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    random_device rd;  // جهاز توليد الأرقام العشوائية
    mt19937 g(rd());   // مولد الأرقام العشوائية
    shuffle(begin(directions), end(directions), g);

    for (auto& dir : directions) {
        int nx = x + dir[0] * 2;
        int ny = y + dir[1] * 2;

        if (ny > 0 && ny < hauteur - 1 && nx > 0 && nx < largeur - 1 && grille[ny][nx] == 1) {
            grille[y + dir[1]][x + dir[0]] = 0; // فتح المسار بين النقاط
            CreerChemin(nx, ny); // متابعة إنشاء المسار من النقطة الجديدة
        }
    }
}

void Labyrinthe::AfficherLabyrinthe() const {
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            if (grille[y][x] == 1)
                cout << "#"; // يمثل الجدار
            else
               cout << " "; // يمثل الممر
        }
        cout << "\n";
    }
}

int Labyrinthe::getCell(int y, int x) const {
    return grille[y][x];
}
















