
#include <SFML/Graphics.hpp>
#include <vector>

int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(320, 320), "TestiPiirto");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    std::vector<std::vector<std::string>> tilesVector;

    std::vector<std::string> zero;
    tilesVector.push_back(zero);
    std::vector<std::string> one;
    tilesVector.push_back(one);
    std::vector<std::string> two;
    tilesVector.push_back(two);
    std::vector<std::string> three;
    tilesVector.push_back(three);
    std::vector<std::string> four;
    tilesVector.push_back(four);


    tilesVector[0].push_back("../rsrc/tiles/background/tile001.png");
    tilesVector[0].push_back("../rsrc/tiles/background/tile002.png");
    tilesVector[0].push_back("../rsrc/tiles/background/tile003.png");
    tilesVector[0].push_back("../rsrc/tiles/background/tile004.png");
    tilesVector[0].push_back("../rsrc/tiles/background/tile005.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile006.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile007.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile008.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile009.png");
    tilesVector[1].push_back("../rsrc/tiles/background/tile010.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile011.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile012.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile013.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile014.png");
    tilesVector[2].push_back("../rsrc/tiles/background/tile015.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile016.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile017.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile018.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile019.png");
    tilesVector[3].push_back("../rsrc/tiles/background/tile020.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile021.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile022.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile023.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile024.png");
    tilesVector[4].push_back("../rsrc/tiles/background/tile025.png");

    std::vector<std::vector<sf::Texture>> texturesVector;

    std::vector<sf::Texture> zerot;
    texturesVector.push_back(zerot);
    std::vector<sf::Texture> onet;
    texturesVector.push_back(onet);
    std::vector<sf::Texture> twot;
    texturesVector.push_back(twot);
    std::vector<sf::Texture> threet;
    texturesVector.push_back(threet);
    std::vector<sf::Texture> fourt;
    texturesVector.push_back(fourt);

    sf::Texture tex1;
    texturesVector[0].push_back(tex1);
    sf::Texture tex2;
    texturesVector[0].push_back(tex2);
    sf::Texture tex3;
    texturesVector[0].push_back(tex3);
    sf::Texture tex4;
    texturesVector[0].push_back(tex4);
    sf::Texture tex5;
    texturesVector[0].push_back(tex5);
    sf::Texture tex6;
    texturesVector[1].push_back(tex6);
    sf::Texture tex7;
    texturesVector[1].push_back(tex7);
    sf::Texture tex8;
    texturesVector[1].push_back(tex8);
    sf::Texture tex9;
    texturesVector[1].push_back(tex9);
    sf::Texture tex10;
    texturesVector[1].push_back(tex10);
    sf::Texture tex11;
    texturesVector[2].push_back(tex11);
    sf::Texture tex12;
    texturesVector[2].push_back(tex12);
    sf::Texture tex13;
    texturesVector[2].push_back(tex13);
    sf::Texture tex14;
    texturesVector[2].push_back(tex14);
    sf::Texture tex15;
    texturesVector[2].push_back(tex15);
    sf::Texture tex16;
    texturesVector[3].push_back(tex16);
    sf::Texture tex17;
    texturesVector[3].push_back(tex17);
    sf::Texture tex18;
    texturesVector[3].push_back(tex18);
    sf::Texture tex19;
    texturesVector[3].push_back(tex19);
    sf::Texture tex20;
    texturesVector[3].push_back(tex20);
    sf::Texture tex21;
    texturesVector[4].push_back(tex21);
    sf::Texture tex22;
    texturesVector[4].push_back(tex22);
    sf::Texture tex23;
    texturesVector[4].push_back(tex23);
    sf::Texture tex24;
    texturesVector[4].push_back(tex24);
    sf::Texture tex25;
    texturesVector[4].push_back(tex25);


    std::vector<sf::Sprite> sprites;

    sf::Sprite sprite1;
    sprites.push_back(sprite1);
    sf::Sprite sprite2;
    sprites.push_back(sprite2);
    sf::Sprite sprite3;
    sprites.push_back(sprite3);
    sf::Sprite sprite4;
    sprites.push_back(sprite4);
    sf::Sprite sprite5;
    sprites.push_back(sprite5);
    sf::Sprite sprite6;
    sprites.push_back(sprite6);
    sf::Sprite sprite7;
    sprites.push_back(sprite7);
    sf::Sprite sprite8;
    sprites.push_back(sprite8);
    sf::Sprite sprite9;
    sprites.push_back(sprite9);
    sf::Sprite sprite10;
    sprites.push_back(sprite10);
    sf::Sprite sprite11;
    sprites.push_back(sprite11);
    sf::Sprite sprite12;
    sprites.push_back(sprite12);
    sf::Sprite sprite13;
    sprites.push_back(sprite13);
    sf::Sprite sprite14;
    sprites.push_back(sprite14);
    sf::Sprite sprite15;
    sprites.push_back(sprite15);
    sf::Sprite sprite16;
    sprites.push_back(sprite16);
    sf::Sprite sprite17;
    sprites.push_back(sprite17);
    sf::Sprite sprite18;
    sprites.push_back(sprite18);
    sf::Sprite sprite19;
    sprites.push_back(sprite19);
    sf::Sprite sprite20;
    sprites.push_back(sprite20);
    sf::Sprite sprite21;
    sprites.push_back(sprite21);
    sf::Sprite sprite22;
    sprites.push_back(sprite22);
    sf::Sprite sprite23;
    sprites.push_back(sprite23);
    sf::Sprite sprite24;
    sprites.push_back(sprite24);
    sf::Sprite sprite25;
    sprites.push_back(sprite25);

    
    for (int i = 0; i < 5; i++) {
        sf::Texture tex;

        if (!tex.loadFromFile(tilesVector[0][i], sf::IntRect((i * 64), 0, 64, 64))) {
        //Error
        }

        sprites[i].setTexture(tex);
    }

    for (int i = 0; i < 5; i++) {
        sf::Texture tex;

        if (!tex.loadFromFile(tilesVector[1][i], sf::IntRect((i * 64), 64, 64, 64))) {
        //Error
        }

        sprites[5 + i].setTexture(tex);
    }

    for (int i = 0; i < 5; i++) {
        sf::Texture tex;

        if (!tex.loadFromFile(tilesVector[2][i], sf::IntRect((i * 64), (2 * 64), 64, 64))) {
        //Error
        }

        sprites[10 + i].setTexture(tex);
    }

    for (int i = 0; i < 5; i++) {
        sf::Texture tex;

        if (!tex.loadFromFile(tilesVector[3][i], sf::IntRect((i * 64), (3 * 64), 64, 64))) {
        //Error
        }

        sprites[15 + i].setTexture(tex);
    }

    for (int i = 0; i < 5; i++) {
        sf::Texture tex;

        if (!tex.loadFromFile(tilesVector[4][i], sf::IntRect((i * 64), (4 * 64), 64, 64))) {
        //Error
        }

        sprites[20 + i].setTexture(tex);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int i = 0; i < 25; i++) {
            window.draw(sprites[i]);
        }
        window.display();
    }

    return 0;
}

