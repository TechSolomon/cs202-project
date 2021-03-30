#include <iostream>
#include <SFML\Graphics.hpp>
using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Hello, world." << endl;

    cout << "Jay-Mark has access and can contribute" << endl;
    cout << "Ben has access and can contribute" << endl;
    cout << "Adrian has access and can contribute" << endl;
    cout << "Press ENTER to quit... ";
    while (cin.get() != '\n');
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}