
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    int rows = 6;
    int columns = 5;

	sf::RenderWindow window(sf::VideoMode(columns * 64, rows * 64), "TestiPiirto");


//TilesVector is a vector containing the addresses of the pictures as a string
    std::vector<std::vector<std::string>> tilesVector;

    for (int i = 0; i < rows; i++) {
        std::vector<std::string> row;
        tilesVector.push_back(row);
    }

    tilesVector[0].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[0].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[0].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[0].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[0].push_back("../rsrc/tiles/background/tile001.png");

    tilesVector[1].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile001.png");

    tilesVector[2].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile001.png");

    tilesVector[3].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile001.png");

    tilesVector[4].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile001.png");

    tilesVector[5].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[5].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[5].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[5].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[5].push_back("../rsrc/tiles/background/tile001.png");


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
            if (!texturesVector[i][j].loadFromFile(tilesVector[i][j], sf::IntRect(0, 0, 64, 64))) {
                //Error
            }
            sprites[i][j].setPosition(j * 64, i * 64);
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
        }

        window.clear();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                window.draw(sprites[i][j]);
            }
        }
        window.display();
    }

    return 0;
}

