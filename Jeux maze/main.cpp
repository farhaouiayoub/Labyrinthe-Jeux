#include <iostream>
#include "Labyrinthe.h"
#include "Joueur.h"
#include "raylib.h" // مكتبة Raylib للرسم ومعالجة الإدخال

const int tileSize = 30;     // حجم كل خلية في الشبكة
const int wallThickness = 3; // سمك الجدار لجعله رفيعاً

int main() {
    // إعداد المتاهة واللاعب
    Labyrinthe labyrinthe(41, 31);
    labyrinthe.GenererLabyrinthe();
    
    Joueur joueur(2, 2, &labyrinthe); // بدء اللاعب عند نقطة (1,1)

    // إعداد نافذة Raylib
    InitWindow(labyrinthe.getLargeur() * tileSize, labyrinthe.getHauteur() * tileSize, "Labyrinthe");
    SetTargetFPS(60); // ضبط معدل الإطارات

    while (!WindowShouldClose()) { // حلقة اللعبة الأساسية
        // معالجة الإدخال لتحريك اللاعب
        if (IsKeyPressed(KEY_UP)) joueur.moveUp();
        if (IsKeyPressed(KEY_DOWN)) joueur.moveDown();
        if (IsKeyPressed(KEY_LEFT)) joueur.moveLeft();
        if (IsKeyPressed(KEY_RIGHT)) joueur.moveRight();

        // بدء عملية الرسم
        BeginDrawing();
        ClearBackground(WHITE); // تغيير الخلفية إلى اللون الأبيض لجعل الجدران واضحة

        // رسم المتاهة
        for (int y = 0; y < labyrinthe.getHauteur(); y++) {
            for (int x = 0; x < labyrinthe.getLargeur(); x++) {
                if (labyrinthe.getCell(y, x) == 1) {
                    // تحديد موضع الخلية
                    int startX = x * tileSize;
                    int startY = y * tileSize;

                    // رسم الجدران حول الخلية
                    if (y > 0 && labyrinthe.getCell(y - 1, x) == 0) { // جدار علوي
                        DrawRectangle(startX, startY, tileSize, wallThickness, BLACK);
                    }
                    //if (y < labyrinthe.getHauteur() - 1 && labyrinthe.getCell(y + 1, x) == 0) { // جدار سفلي
                     //   DrawRectangle(startX, startY + tileSize - wallThickness, tileSize, wallThickness, BLACK);
                  //  }
                    if (x > 0 && labyrinthe.getCell(y, x - 1) == 0) { // جدار أيسر
                        DrawRectangle(startX, startY, wallThickness, tileSize, BLACK);
                    }
                   // if (x < labyrinthe.getLargeur() - 1 && labyrinthe.getCell(y, x + 1) == 0) { // جدار أيمن
                  //      DrawRectangle(startX + tileSize - wallThickness, startY, wallThickness, tileSize, BLACK);
                  //  }
                }
            }
        }

        // رسم اللاعب كنقطة زرقاء
        DrawCircle(joueur.getX() * tileSize + tileSize / 2, joueur.getY() * tileSize + tileSize / 2, tileSize / 3, YELLOW);

        // إنهاء الرسم
        EndDrawing();
    }

    // إغلاق النافذة وتحرير الموارد
    CloseWindow();

    return 0;
}
