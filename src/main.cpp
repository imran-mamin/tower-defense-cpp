
#include <SFML/Graphics.hpp>
#include <vector>

int main()
{
    int rows = 12;
    int columns = 20;

	sf::RenderWindow window(sf::VideoMode(columns * 64, rows * 64), "TestiPiirto");


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
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[2].push_back("../rsrc/tiles/background/grass.png");


//Row4
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");

    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");

    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");

    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");
    tilesVector[3].push_back("../rsrc/tiles/background/path.png");


//Row5
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
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[4].push_back("../rsrc/tiles/background/grass.png");


//Row6
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
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[5].push_back("../rsrc/tiles/background/grass.png");


//Row7
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
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[6].push_back("../rsrc/tiles/background/grass.png");


//Row8
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
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[7].push_back("../rsrc/tiles/background/grass.png");


//Row9
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
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[8].push_back("../rsrc/tiles/background/grass.png");


//Row10
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");

    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
    tilesVector[9].push_back("../rsrc/tiles/background/grass.png");
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

