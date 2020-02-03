//Calculator application

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>

using namespace std;
using namespace sf;

int main()
{
    srand(time(0));

    //Vectors
    vector<RectangleShape> Game_BG;
    vector<Texture> Cursor;
    vector<Font> Game_Font;
    vector<Text> Game_Text,Vars_Text;
    vector<float> Vars;
    bool New=true;

    //Bools
    bool Game=true;
    bool Game_Once=true;
    bool Game_Clicked,Game_Mouse,C_Subtract;

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

                C_Subtract=false;

                Vars.push_back(0);

                Vars_Text.push_back(Text(to_string(Vars.back()),Game_Font[0],50));
                Vars_Text.back().setPosition(Vector2f(100,25));

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
                    Game_Text[i].setOutlineThickness(5);

                Vars_Text[0].setOutlineThickness(5);

                Game_Once=false;
            }
            window.draw(Game_BG[0]); //White background

            Game_Clicked=false;
if(Keyboard::isKeyPressed(Keyboard::C)==true){
    Vars.clear();
    Vars.push_back(0);
}
            for(int i=1; i<=2; i++)
            {
                if(Game_Text[0].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[0].getFillColor().g))==255)
                        Game_Text[0].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=0)
                            Vars.back()=0;
                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[0].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[0].setFillColor(Color::White);

                if(Game_Text[1].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[1].getFillColor().g))==255)
                        Game_Text[1].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=1)
                            Vars.back()=1;
                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[1].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[1].setFillColor(Color::White);

                if(Game_Text[2].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[2].getFillColor().g))==255)
                        Game_Text[2].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=2)
                            Vars.back()=2;
                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[2].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[2].setFillColor(Color::White);

                if(Game_Text[3].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[3].getFillColor().g))==255)
                        Game_Text[3].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=3)
                            Vars.back()=3;
                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[3].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[3].setFillColor(Color::White);

                if(Game_Text[4].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[4].getFillColor().g))==255)
                        Game_Text[4].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=4)
                            Vars.back()=4;
                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[4].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[4].setFillColor(Color::White);

                if(Game_Text[5].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[5].getFillColor().g))==255)
                        Game_Text[5].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=5)
                            Vars.back()=5;
                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[5].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[5].setFillColor(Color::White);

                if(Game_Text[6].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[6].getFillColor().g))==255)
                        Game_Text[6].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=6)
                            Vars.back()=6;
                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[6].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[6].setFillColor(Color::White);

                if(Game_Text[7].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[7].getFillColor().g))==255)
                        Game_Text[7].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=0){
                                Vars.back()=((Vars.back()*7)+(Vars.back()*2)+Vars.back());
                                Vars.back()+=7;
                        }
                        if(Vars.back()==0) Vars.back()=7;

                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[7].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[7].setFillColor(Color::White);
//append(Vars_Text.back(),)
//if 1 is picked, vars is 1, then 7 is picked, vars is 17
//if 1, add 10 then add 7, if 17 add 100 then add 7 177
//if 2, add 10, 20, then add 7, 27.
// if 27, add to get 270
//if 33, got to get to 330

                if(Game_Text[8].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[8].getFillColor().g))==255)
                        Game_Text[8].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=0){
                                Vars.back()=((Vars.back()*(Vars.back()/10))+(Vars.back()*2)+Vars.back());
                                Vars.back()+=8;
                        }

                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[8].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[8].setFillColor(Color::White);

                if(Game_Text[9].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[9].getFillColor().g))==255)
                        Game_Text[9].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(Vars.back()!=0) Vars.back()=((Vars.back()*9)+(Vars.back())+9);
                        if(Vars.back()==0) Vars.back()=9;
                        cout<<Vars.back()<<endl;
                        if(New!=true)
                            New=true;
                    }
                }
                else if(!Game_Text[9].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[9].setFillColor(Color::White);


            Vars_Text[0].setString(to_string(Vars.back()));

////////////////////////

            if(Game_Text[10].getGlobalBounds().contains(Vector2f(Game_BG[i].getPosition().x,Game_BG[i].getPosition().y)))
                {
                    Game_Clicked=true;
                    if((static_cast<int>(Game_Text[10].getFillColor().g))==255)
                        Game_Text[10].setFillColor(Color::Red);
                    if(Game_Mouse==true)
                    {
                        if(C_Subtract!=true)
                            C_Subtract=true;
                        if(New==true){
                            Vars.push_back(0);
                        if(New!=false)
                            New=false;
                    }
                }
                else if(!Game_Text[10].getGlobalBounds().contains(Vector2f(Game_BG[2].getPosition().x,Game_BG[2].getPosition().y)))
                    Game_Text[10].setFillColor(Color::White);
            }
            }






//            for(int i=10; i<=16; i++)
//            {
//                if(Game_Text[i].getGlobalBounds().contains(Vector2f(Game_BG[1].getPosition().x,Game_BG[1].getPosition().y)))
//                {
//                    Game_Text[i].setFillColor(Color::Red);
//                    if(Game_Mouse==true)
//                    {
//                        if(New==true){
//                            Vars.push_back(0);
//                         if(New!=false)
//                            New=false;
//                        }
//                    }
//                }
//                else
//                    Game_Text[i].setFillColor(Color::White);
//            }
























            for(auto i : Game_Text)
                window.draw(i); //0123456789
            window.draw(Vars_Text[0]);

            // Mouse hand & pointer images
            if(Game_Clicked==false)
            {
                if(Game_BG[2].getPosition().x!=0)
                    Game_BG[2].setPosition(Vector2f(0,0));
                Game_BG[1].setPosition(Vector2f(Mouse::getPosition().x-468,Mouse::getPosition().y-171));
                window.draw(Game_BG[1]);
            }
            if(Game_Clicked==true)
            {
                if(Game_BG[1].getPosition().x!=0)
                    Game_BG[1].setPosition(Vector2f(0,0));
                Game_BG[2].setPosition(Vector2f(Mouse::getPosition().x-474,Mouse::getPosition().y-171));
                window.draw(Game_BG[2]);
            }






        }

















        window.display();
    }

    return 0;
}

