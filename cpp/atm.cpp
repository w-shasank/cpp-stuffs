#include <SFML/Graphics.hpp>
#include <sstream>

int main() {
    sf::RenderWindow window(sf::VideoMode(600, 400), "ATM Simulator - Add Two Numbers");

    sf::Font font;
    if (!font.loadFromFile("assets/DejaVuSans.ttf")) {
        return -1;
    }

    std::string input1 = "";
    std::string input2 = "";
    std::string result = "";

    int currentInput = 1; // Track whether we're entering the first or second number

    sf::Text prompt1("Enter first number: ", font, 20);
    prompt1.setPosition(50, 50);

    sf::Text prompt2("Enter second number: ", font, 20);
    prompt2.setPosition(50, 100);

    sf::Text inputText1("", font, 20);
    inputText1.setPosition(300, 50);
    inputText1.setFillColor(sf::Color::Cyan);

    sf::Text inputText2("", font, 20);
    inputText2.setPosition(300, 100);
    inputText2.setFillColor(sf::Color::Cyan);

    sf::Text resultText("", font, 24);
    resultText.setPosition(50, 160);
    resultText.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                if (std::isdigit(event.text.unicode)) {
                    if (currentInput == 1)
                        input1 += static_cast<char>(event.text.unicode);
                    else
                        input2 += static_cast<char>(event.text.unicode);
                }
                else if (event.text.unicode == 8) { // Backspace
                    if (currentInput == 1 && !input1.empty())
                        input1.pop_back();
                    else if (currentInput == 2 && !input2.empty())
                        input2.pop_back();
                }
                else if (event.text.unicode == 13) { // Enter key
                    if (currentInput == 1) {
                        currentInput = 2;
                    } else {
                        // Compute the sum
                        int sum = std::stoi(input1) + std::stoi(input2);
                        result = "Sum: " + std::to_string(sum);
                    }
                }
            }
        }

        inputText1.setString(input1);
        inputText2.setString(input2);
        resultText.setString(result);

        window.clear(sf::Color::Black);
        window.draw(prompt1);
        window.draw(prompt2);
        window.draw(inputText1);
        window.draw(inputText2);
        window.draw(resultText);
        window.display();
    }

    return 0;
}
