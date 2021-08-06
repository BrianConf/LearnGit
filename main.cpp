#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace sf;

int main()
{
    //Game over Bool
    bool Game_over  = false;
    //player lives
    int lives = 6;
    //boundary
    RenderWindow window(sf::VideoMode(500, 400), "SFML works!");
    RectangleShape boundary(Vector2f(300.f, 300.f));
    boundary.setFillColor(Color::White);
    boundary.setPosition(Vector2f(50.f,50.f));

    //character
    CircleShape shape(12.f);
    shape.setFillColor(Color::Green);
    shape.setPosition(150,150);

    //enemy
    CircleShape enemy(20.f);
    enemy.setFillColor(Color::Red);
    enemy.setPosition(50.f, 50.f);

    //player speed
    float speed = 0.f;

    //enemy speed
    float enemySpeedx = 0.01f;
    float enemySpeedy = 0.01f;

    //fruit
    CircleShape fruit(6.f);
    fruit.setFillColor(Color::Yellow);
    fruit.setPosition(50.f, 50.f);
    bool fruitEaten = false;
    bool drawFruit = true;
    //random pos, for fruit generation
    srand(time(0));
    int fruitXpos = 0;
    int fruitYpos = 0;
    Clock clock;

    //print score
    int Score = 0;
    Font myFont;
    if(!myFont.loadFromFile("OpenSans-Italic.ttf")){return 0; }

    //score text
    Text myScore;
    myScore.setFillColor(Color::White);
    myScore.setFont(myFont);
    //death text
    Text myDeath;
    myDeath.setFont(myFont);
    myDeath.setColor(Color::Red);
    myDeath.setPosition(50,150);
    myDeath.setString("DEAD Monkey");
    myDeath.setCharacterSize(47);
    myDeath.Bold;

    //score counter
    int Counter = 1;

    //Title
    Font myTitle;
    if(!myTitle.loadFromFile("OpenSans-BoldItalic.ttf")){return 0;}
    Text title;
    title.setFont(myTitle);
    title.setString("The Hunt");
    title.setColor(Color::Blue);
    title.setPosition(50, 338);
    title.setCharacterSize(60);
    while (window.isOpen() && !Game_over)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            speed = 0.5;
            if(shape.getPosition().x >= 350 - 25){
                speed = 0;
            }
            shape.move(speed,0);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Left)){
            speed = -0.5;
            if(shape.getPosition().x <= 50){
                speed = 0;
            }
            shape.move(speed,0);
        }
        else if( Keyboard::isKeyPressed(Keyboard::Down)){
            speed = 0.5;
            if(shape.getPosition().y >= 350 - 25){
                speed = 0;
            }
            shape.move(0,speed);
        }
        else if(Keyboard::isKeyPressed(Keyboard::Up)){
            speed = -0.5;
            if(shape.getPosition().y <= 50){
                speed = 0;
            }
            shape.move(0,speed);
        }

        if(enemy.getPosition().x > shape.getPosition().x){
            enemySpeedx = -abs(enemySpeedx);
        }
        else{
            enemySpeedx = abs(enemySpeedx);
        }

        if(enemy.getPosition().y > shape.getPosition().y){
             enemySpeedy = -abs(enemySpeedy);
        }
        else{
            enemySpeedy = abs(enemySpeedy);
        }

        if(clock.getElapsedTime().asSeconds() < 0.1){
            drawFruit = false;
        }
        else{
            drawFruit = true;
        }
        //enemy got to player
        if(shape.getPosition().x >= enemy.getPosition().x && shape.getPosition().x <= enemy.getPosition().x + 10.0)
        if(shape.getPosition().y >= enemy.getPosition().y && shape.getPosition().y <= enemy.getPosition().y + 10.0){
            lives--;
            enemy.setPosition(50.f, 50.f);
        }

        if(shape.getPosition().x + 30 >= enemy.getPosition().x && shape.getPosition().x <= enemy.getPosition().x + 10.0)
        if(shape.getPosition().y >= enemy.getPosition().y && shape.getPosition().y <= enemy.getPosition().y + 10.0){
            lives--;
            enemy.setPosition(50.f, 50.f);
        }

        if(shape.getPosition().x >= enemy.getPosition().x && shape.getPosition().x <= enemy.getPosition().x + 10.0)
        if(shape.getPosition().y + 30 >= enemy.getPosition().y && shape.getPosition().y <= enemy.getPosition().y + 10.0){
            lives--;
            enemy.setPosition(50.f, 50.f);
        }

        if(shape.getPosition().x + 30 >= enemy.getPosition().x && shape.getPosition().x <= enemy.getPosition().x + 10.0)
        if(shape.getPosition().y + 30 >= enemy.getPosition().y && shape.getPosition().y <= enemy.getPosition().y + 10.0){
            lives--;
            enemy.setPosition(50.f, 50.f);
        }

        //player got to fruit
        if(shape.getPosition().x >= fruit.getPosition().x && shape.getPosition().x <= fruit.getPosition().x + 10.0)
        if(shape.getPosition().y >= fruit.getPosition().y && shape.getPosition().y <= fruit.getPosition().y + 10.0){
            fruitEaten = true;
        }

        if(shape.getPosition().x + 30 >= fruit.getPosition().x && shape.getPosition().x <= fruit.getPosition().x + 10.0)
        if(shape.getPosition().y >= fruit.getPosition().y && shape.getPosition().y <= fruit.getPosition().y + 10.0){
            fruitEaten = true;
        }

        if(shape.getPosition().x >= fruit.getPosition().x && shape.getPosition().x <= fruit.getPosition().x + 10.0)
        if(shape.getPosition().y + 30 >= fruit.getPosition().y && shape.getPosition().y <= fruit.getPosition().y + 10.0){
            fruitEaten = true;
        }

        if(shape.getPosition().x + 30 >= fruit.getPosition().x && shape.getPosition().x <= fruit.getPosition().x + 10.0)
        if(shape.getPosition().y + 30 >= fruit.getPosition().y && shape.getPosition().y <= fruit.getPosition().y + 10.0){
            fruitEaten = true;
        }

        if(fruitEaten == true){
            fruitXpos = 50 + rand()%(350 - 50 - 25);
            fruitYpos  = 50 + rand()%(350 - 50 - 25);
            fruit.setPosition(fruitXpos, fruitYpos);
            fruitEaten  = false;
            Score++;
            clock.restart();
        }

        myScore.setString("Score : " + to_string(Score) + " : Your Lives : " + to_string(lives)+ " : Level : " + to_string(Counter));


        enemy.move(enemySpeedx, enemySpeedy);

        if(Score/(1*Counter) == 1){
            enemySpeedx += 0.025;
            enemySpeedy += 0.025;
            Counter++;
        }
        if(lives < 0){lives = 0;}
        window.clear();
        window.draw(boundary);
        window.draw(title);
        window.draw(shape);
        window.draw(enemy);
        window.draw(myScore);
        if(lives == 0){window.draw(myDeath);}
        else if(drawFruit){ window.draw(fruit);}

        window.display();
        if(lives == 0){
            clock.restart();
            while(clock.getElapsedTime().asSeconds() < 30){continue;}
            Game_over = true;
        }
    }

    return 0;
}
