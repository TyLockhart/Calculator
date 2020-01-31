//Calculator application

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
    srand(time(0));

    //Vectors
    vector<RectangleShape> Game_BG;
    vector<Texture> Cursor;
    vector<Font> Game_Font;
    vector<Text> Game_Text;
    vector<float> Vars;
    bool New=true;

    //Bools
    bool Game=true;
    bool Game_Once=true;
    bool Game_Clicked,Game_Mouse;

    //Textures
    Cursor.push_back(Texture());
    Cursor.back().loadFromFile("Game_MouseCursor.png");
    Cursor.push_back(Texture());
    Cursor.back().loadFromFile("Game_HandCursor.png");

    //Fonts
    Game_Font.push_back(Font());
    Game_Font.back().loadFromFile("Game_Font1.ttf");

    RenderWindow window(VideoMode(1000,800),"Calculator");
    window.setFramerateLimit(60);
    window.setMouseCursorGrabbed(false); // Dont let mouse cursor leave window
    window.setMouseCursorVisible(false);

    while(window.isOpen()&&!Keyboard::isKeyPressed(Keyboard::Escape))
    {
        Game_Mouse=false;
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();
            if(event.type==Event::MouseButtonReleased&&event.mouseButton.button==Mouse::Left)
                Game_Mouse=true;
        }
        window.clear();

        if(Game==true)
        {
            if(Game_Once==true)
            {
                Game_Clicked=false;

//                New.resize(9);
//                for(int i=0;i<=9;i++) New[i]=true;

                Vars.push_back(0);

                Game_BG.push_back(RectangleShape(Vector2f(1000,800)));
                Game_BG.back().setFillColor(Color::White);

                Game_BG.push_back(RectangleShape(Vector2f(12,19)));
                Game_BG.back().setTexture(&Cursor[0]);

                Game_BG.push_back(RectangleShape(Vector2f(17,22)));
                Game_BG.back().setTexture(&Cursor[1]);

                Game_Text.push_back(Text("0",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(100,100));

                Game_Text.push_back(Text("1",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(200,100));

                Game_Text.push_back(Text("2",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(300,100));

                Game_Text.push_back(Text("3",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(100,200));

                Game_Text.push_back(Text("4",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(200,200));

                Game_Text.push_back(Text("5",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(300,200));

                Game_Text.push_back(Text("6",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(100,300));

                Game_Text.push_back(Text("7",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(200,300));

                Game_Text.push_back(Text("8",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(300,300));

                Game_Text.push_back(Text("9",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(200,400));

                Game_Text.push_back(Text("-",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(400,100));

                Game_Text.push_back(Text("+",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(400,200));

                Game_Text.push_back(Text("x",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(400,300));

                Game_Text.push_back(Text("/",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(400,400));

                Game_Text.push_back(Text("^2",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(500,100));

                Game_Text.push_back(Text("^3",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(500,200));

                Game_Text.push_back(Text("sqrt",Game_Font[0],50));
                Game_Text.back().setPosition(Vector2f(500,300));

                for(int i=0; i<Game_Text.size(); i++)
                {
                    Game_Text[i].setFillColor(Color::White);
                    Game_Text[i].setOutlineThickness(5);
                }

                Game_Once=false;
            }
            window.draw(Game_BG[0]); //White background

            if(Game_Text[0].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[0].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=0)Vars.back()=0;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[0].setFillColor(Color::White);

            if(Game_Text[1].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[1].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=1)Vars.back()=1;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[1].setFillColor(Color::White);

            if(Game_Text[2].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[2].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=2)Vars.back()=2;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[2].setFillColor(Color::White);

            if(Game_Text[3].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[3].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=3)Vars.back()=3;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[3].setFillColor(Color::White);

            if(Game_Text[4].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[4].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=4)Vars.back()=4;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[4].setFillColor(Color::White);

            if(Game_Text[5].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[5].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=5)Vars.back()=5;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[5].setFillColor(Color::White);

            if(Game_Text[6].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[6].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=6)Vars.back()=6;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[6].setFillColor(Color::White);

            if(Game_Text[7].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[7].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=7)Vars.back()=7;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[7].setFillColor(Color::White);

            if(Game_Text[8].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                if((static_cast<int>(Game_Text[0].getFillColor().g))==255){
                        Game_Text[8].setFillColor(Color::Red);//so .r outputs a char? change it to an int
                cout<<(static_cast<int>(Game_Text[0].getFillColor().g))<<endl;
                }
                if(Game_Mouse==true){
                    if(Vars.back()!=8)Vars.back()=8;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[8].setFillColor(Color::White);

            if(Game_Text[9].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[9].setFillColor(Color::Red);
                if(Game_Mouse==true){
                    if(Vars.back()!=9)Vars.back()=9;
                    if(New!=true)New=true;
                }
            }
            else Game_Text[9].setFillColor(Color::White);




            for(int i=10;i<=16;i++){
            if(Game_Text[i].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y))){
                Game_Text[i].setFillColor(Color::Red);
                if(Game_Mouse==true){
                if(New==true) Vars.push_back(0);
                }
            }
            else Game_Text[i].setFillColor(Color::White);

            }

























            // Mouse hand & pointer images
            if(Game_Clicked==false)
            {
                Game_BG[1].setPosition(Vector2f(Mouse::getPosition().x-468,Mouse::getPosition().y-171));
                window.draw(Game_BG[1]);
            }
            if(Game_Clicked==true)
            {
                Game_BG[2].setPosition(Vector2f(Mouse::getPosition().x-474,Mouse::getPosition().y-171));
                window.draw(Game_BG[2]);
            }





            for(auto i : Game_Text)
                window.draw(i); //0123456789
        }

















        window.display();
    }

    return 0;
}

