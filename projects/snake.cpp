#include <iostream>
#include <ctime>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

enum direction {Top, Left, Right, Down};
struct snake {int headX, headY, Tail_N; direction Dir;} snake1;
struct map {int width, height, FruitX, FruitY;} map1;
struct player {int Score; bool loss;} player1;

void generate_fruit(){
    srand(time(0));
    map1.FruitX = rand() % (map1.width - 1);
    map1.FruitY = rand() % (map1.width - 1);
}

void setup (){
    map1.width = 40;
    map1.height = 20;
    generate_fruit();
    snake1.headX = map1.width / 2;
    snake1.headY = map1.height / 2;
    snake1.Tail_N = 0;
    player1.Score = 0;
    player1.loss = false;
}

void draw (){
    system("clear && printf '\e[3J'");
    for (int i = 0; i <= map1.height; i++){
        for (int j = 0; j <= map1.width; j++){
            if (i == 0 || j == 0 || j == map1.width || i == map1.height)
                cout << "*";
            else if (i == snake1.headY && j == snake1.headX)
                cout << "O";
            else if (i == map1.FruitY && j == map1.FruitX)
                cout << "$";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void move(){
    switch (snake1.Dir){
        case Top:
            snake1.headY--;
            break;
        case Left:
            snake1.headX--;
            break;
        case Right:
            snake1.headX++;
            break;
        case Down:
            snake1.headY++;
            break;
    }

    if (snake1.headX <= 0 || snake1.headX >= map1.width || snake1.headY <= 0 || snake1.headY >= map1.height)
        player1.loss = true;

    if (snake1.headX == map1.FruitX && snake1.headY == map1.FruitY){
        generate_fruit();
        player1.Score += 1;
    }
}

void input(){
    int ch = getchar();
    switch (ch){
        case 'w':
            snake1.Dir = Top;
            break;
        case 'a':
            snake1.Dir = Left;
            break;
        case 's':
            snake1.Dir = Down;
            break;
        case 'd':
            snake1.Dir = Right;
            break;
        case 'x':
            exit(0);
            break;
    }
}


int main (){
    setup();
    while (!player1.loss){
        draw();
        input();
        move();
        sleep(1);

    }
 

    return 0;
}
