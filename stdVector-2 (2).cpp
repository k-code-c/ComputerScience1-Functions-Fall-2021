#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
using namespace std;
using std ::cout;
using std ::endl;


//a function named initAstroids() that accepts arrays or other containers as formal parameters. 20 balls, random size between (10,100), random color, position to be random.
// a function named updateAsteroid(), updates each ball's position and resets the asteroid's position if they go off screen.
// a function named playerCollision() that returns the index of the asteroid that collided with the player or -1, if no collision. 


void initAstroids(vector<sf::CircleShape> & initAstroids){ //draws vector balls ;)
    srand((unsigned) time (0));
  
    for (int i = 0; i < initAstroids.size(); i++){
    
        initAstroids[i].setRadius(rand() % 100 + 10); //gives the asteroids random sizes from 10 to 100
    
        initAstroids[i].setFillColor(sf::Color(rand()%255+1, rand() % 255 +1, rand() % 255 + 1, 255)); // will give the shapes a random color between 1 and 255
                
        initAstroids[i].setPosition(rand()% 1500, rand()% 600); // i want it to be random on the window 
    
    }

    return ;
}
//hopefully this updates my circles when they go off screeennn
void updateAstroid(vector<sf::CircleShape>){
    
    for(int i = 0; i < circle.size(); i++){
        bool deleted = false;
    
    if (circle[i].getPosition().y > window.getSize().y){
            deleted = true;
        }
        if(deleted){
            circle.erase(initAstroids.begin() + i);
        }
    }
}

//player collision 
void playerCollision(vector<sf::CircleShape> & initAstroids, sf::RectangleShape player1){
    //helps with the index of the asteroids 
    auto it = find(initAstroids.begin(), initAstroids.end());

    for (int i = 0; i < initAstroids.size(); i++) {
     //if player 1 does not collide with astroids then it should return -1   
 if (!player1.getGlobalBounds().intersects(circle[i].getGlobalBounds())){

     
     std::cout << "-1" << std::endl; 
     return ; 

 }
 //otherwise it will retrun the index of the asteroid if they do collide
 else if (circle[i].getGlobalBounds().intersects(player1.getGlobalBounds())){
     int index = it - initAstroids.begin();
     std::cout << "KC" << std::endl; 

}
    }

        }
        



int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(2024, 1000), "SFML window");
    vector<sf::CircleShape> circle(20);
   //calling my functions
    initAstroids(circle);
    updateAstroid(circle);
    playerCollision();

   /* playerCollision(player1); */

    //player1 attributes
    sf::RectangleShape player1(sf::Vector2f(100.f,50.f));
    player1.setFillColor(sf::Color::White);
    player1.getGlobalBounds();

    int position_x {}; //this is the x direction of the player1
    int Position_y {};// this is the y direction of the player1
    player1.setPosition(500, 900); // this sets the position of player1
    int delta_x = 10; // this causes the player one to move left to right
    int delta_y = 3; // this causes the player to move up and down
    

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //the left controls for player 1
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            sf::Vector2f coor = player1.getPosition();
                if(coor.x >= 0+0.f){
                player1.move(-10.f,0.f);

            }
        }
        //the right controls for player2
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
           sf::Vector2f coor = player1.getPosition();
           if(coor.x < 1920.f){
               player1.move(10.f,0.f);
            }
        }

        // Clear screen
        window.clear();
        
        for (int i = 0; i < circle.size(); i++){
            circle[i].move(0.f,1.f); // move the asteroids// it works but needs to fix
            window.draw(circle[i]); // draws circles 
        }

        //draw player 1
        window.draw(player1);
        
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}