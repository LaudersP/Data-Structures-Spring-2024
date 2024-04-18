#define DO_UNIT_TEST 0
#if DO_UNIT_TEST
#include <gtest/gtest.h>
#else
#include <SFML/Graphics.hpp>
#include <visual_graph.h>
#endif

#if !DO_UNIT_TEST
void printTraversals(const ssuds::ArrayList<std::pair<int, int>>& traversalMap) {
    std::cout << "{";

    for (unsigned int i = 0; i < traversalMap.size(); i++) {
        if (i == traversalMap.size() - 1) {
            std::cout << traversalMap[i].first << ":" << traversalMap[i].second << "}\n";
            continue;
        }
        else if (i == 0)
            std::cout << traversalMap[i].first << ":None, ";
        else
        std::cout << traversalMap[i].first << ":" << traversalMap[i].second << ", ";
    }
}

#endif

int main()
{
#if DO_UNIT_TEST
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
#else
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Graph Creator");
    
    sf::Font status_font, circle_font;
    if (!status_font.loadFromFile("../../../media/fonts/Courier_Prime/CourierPrime-Regular.ttf") ||
        !circle_font.loadFromFile("../../../media/fonts/Open_Sans/static/OpenSans-Regular.ttf"))
        std::cout << "Error loading fonts\n";

    misc::VisualGraph GC(circle_font, "../../../media/output.txt");
    ssuds::ArrayList<int> selectedNodes;

    ssuds::ArrayList<std::string> userMessages = { "Please select the starting node!", "Please select the end node!", "Press 'B' for Breadth-First traversal!\nPress 'D' for Depth-First traversal!" };
    sf::Text userMessage;
    userMessage.setFont(status_font);
    userMessage.setString(userMessages[0]);
    userMessage.setCharacterSize(24);
    userMessage.setFillColor(sf::Color::White);
    userMessage.setPosition(10, 0);

    // Main loop
    while (window.isOpen()) {
        sf::Event event;

        // Event handling loop
        while (window.pollEvent(event)) {
            // Check if the window needs to be close
            if (event.type == sf::Event::Closed || 
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();

            // Check if a node was attempted to be selected
            if ((event.type == sf::Event::MouseButtonPressed) && (event.mouseButton.button == sf::Mouse::Left)) {
                float mouseX = event.mouseButton.x;
                float mouseY = event.mouseButton.y;
                selectedNodes = GC.handleMouseClick(mouseX, mouseY);

                if (selectedNodes.size() > 0)
                    userMessage.setString(userMessages[2]);
                else
                    userMessage.setString(userMessages[0]);
            }

            // Check if a breath first traversal is desired
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::B) {
                ssuds::ArrayList<std::pair<int, int>> traversals;
                GC.breadthFirstTraversal(traversals);
                std::cout << "Breadth Traversal: ";
                printTraversals(traversals);
            }

            // Check if a deapth first traversal is desired
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                ssuds::ArrayList<std::pair<int, int>> traversals;
                GC.depthFirstTraversal(traversals);
                std::cout << "Depth Traversal: ";
                printTraversals(traversals);
            }
        }

        window.clear();
        GC.draw(window);
        window.draw(userMessage);
        window.display();
    }
   
    return 0;
#endif
}