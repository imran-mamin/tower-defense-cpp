
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

int main()
{
    int windowWidth = 20 * 64;
    int windowHeight = 12 * 64;
    
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "TestiPiirto");

    // Toolbar parameters
    int toolbarWidth = 200;
    int toolbarHeight = window.getSize().y;
    
    // Create a vertical toolbar on the right side using a rectangle
    sf::RectangleShape toolbar(sf::Vector2f(toolbarWidth, toolbarHeight));
    toolbar.setPosition(window.getSize().x - toolbarWidth, 0);
    toolbar.setFillColor(sf::Color(200, 200, 200));

    // Towers to protect base: Cannon, MissileLauncher and FighterPlane
    std::vector<std::string> towersVec = {
                                            "../rsrc/tiles/enemies/tank.png",
                                            "../rsrc/tiles/enemies/tank-gun.png",
                                            "../rsrc/tiles/enemies/fighterplane.png"       
                                        };

    // Add buttons to the toolbar (tower buttons)
    sf::Texture tankTexture, tankGunTexture, planeTexture;

    // Load tank texture
    if (!tankTexture.loadFromFile(towersVec[0])) {
        std::cout << "tankTexture loadFromFile problem." << std::endl;
        return -1;
    }

    // Load tank-gun texture
    if (!tankGunTexture.loadFromFile(towersVec[1])) {
        std::cout << "tankGunTexture loadFromFile problem." << std:: endl;
        return -1;
    }

    // Load plane texture
    if (!planeTexture.loadFromFile(towersVec[2])) {
        std::cout << "planeTexture loadFromFile problem." << std::endl;
        return -1;
    }

    // Creating sprites for the towers.
    sf::Sprite tankSprite(tankTexture);
    sf::Sprite tankGunSprite(tankGunTexture);
    sf::Sprite planeSprite(planeTexture);

    // Set positions of the buttons
    tankSprite.setPosition(window.getSize().x  - toolbarWidth + 20, 80); // Toolbar x-coordinate + 20
    tankGunSprite.setPosition(window.getSize().x - toolbarWidth + 20, 80); // Toolbar x-coordinate + 20
    // 20 + tank x-coordinate + tank width + 20
    planeSprite.setPosition(2 * 20 + tankSprite.getPosition().x + tankTexture.getSize().x, 80);
    
    // Creating board of tiles
    int rows = 12;
    int columns = 20;

    double tileWidth = (window.getSize().x - toolbarWidth) / (1.0 * columns);
    double tileHeight = tileWidth;

//TilesVector is a vector containing the addresses of the pictures as a string
    std::vector<std::vector<std::string>> tilesVector;

    for (int i = 0; i < rows; i++) {
        std::vector<std::string> row;
        tilesVector.push_back(row);
    }

//Row1
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[0].push_back("../rsrc/tiles/background/grass.png");


//Row2
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[1].push_back("../rsrc/tiles/background/grass.png");


//Row3
    tilesVector[2].push_back("../rsrc/tiles/background/path.png");
    tilesVector[2].push_back("../rsrc/tiles/background/path.png");
    tilesVector[2].push_back("../rsrc/tiles/background/path.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/path.png");
    tilesVector[2].push_back("../rsrc/tiles/background/path.png");
    tilesVector[2].push_back("../rsrc/tiles/background/path.png");


//Row4
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");


//Row5
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/path.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/path.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");


//Row6
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/path.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/path.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");


//Row7
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/path.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/path.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");


//Row8
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/path.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/path.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");


//Row9
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/path.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/path.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");


//Row10
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");

    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");

    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");

    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/path.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");


//Row11
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[10].push_back("../rsrc/tiles/background/grass.png");


//Row12
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[11].push_back("../rsrc/tiles/background/grass.png");

//TexturesVector contains the corresponding textures
    std::vector<std::vector<sf::Texture>> texturesVector;

    for (int i = 0; i < rows; i++) {
        std::vector<sf::Texture> row;
        texturesVector.push_back(row);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sf::Texture tex;
            texturesVector[i].push_back(tex);
        }
    }

//Sprites contains the textures converted to sprites

    std::vector<std::vector<sf::Sprite>> sprites;

    for (int i = 0; i < rows; i++) {
        std::vector<sf::Sprite> row;
        sprites.push_back(row);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            sf::Sprite sprite;
            sprites[i].push_back(sprite);
        }
    }


//Load sprites
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (!texturesVector[i][j].loadFromFile(tilesVector[i][j], sf::IntRect(0, 0, tileWidth, tileHeight))) {
                // ERROR
                std::cout << "Error in texturesVector[i][j].loadFromFile()." << std::endl;
            }
            sprites[i][j].setPosition(j * tileWidth, i * tileHeight);
            sprites[i][j].setTexture(texturesVector[i][j]);
        }
    }

    
//Load window
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Button click handling
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    // Is mouse over the button?
                    if (tankGunSprite.getGlobalBounds().contains(mousePos)) {
                        std::cout << "tank button was clicked." << std::endl;
                        // TODO: When clicking on this button the program should create a new tank instance.
                    } else if (planeSprite.getGlobalBounds().contains(mousePos)) {
                        std::cout << "plane button was clicked." << std::endl;
                        // TODO: When clicking on this button the program should create a new plane instance.
                    }


                }
            }
        }

        window.clear(sf::Color(200, 200, 200));
        
        // Draw the tiles
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                window.draw(sprites[i][j]);
            }
        }

        
        // Draw the toolbar and buttons inside it.
        window.draw(toolbar);
        window.draw(tankSprite);
        window.draw(tankGunSprite);
        window.draw(planeSprite);

        window.display();
    }

    return 0;
}

