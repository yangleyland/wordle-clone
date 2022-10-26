#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>

 using namespace std;

bool iscorrect (char input[],char mystery[]);
void letterchecker (char input[],char mystery[], char colors[]);
bool isvalid (char input[],char* wordBank[]);
sf::RectangleShape colorchanger(sf::RectangleShape box, int number, char colors[]);

int main()
{
    //BACKEND
    ifstream ifile("./words.txt");
    srand (time(NULL));
    char* wordBank[5757];
    char mystery[6];
    char input[6];
    char colors[6];
    char colors1[6];
    char colors2[6];
    char colors3[6];
    char colors4[6];
    char colors5[6];
    for (int i=0; i<5; i++)
    {
        colors[i]='X';
        colors1[i]='X';
        colors2[i]='X';
        colors3[i]='X';
        colors4[i]='X';
        colors5[i]='X';
    }
    int counter=0;
    //creates array with all 5 letter words
    for (int i=0; i<5757; i++)
    {
        char buffer[41];
        ifile>>buffer;
        char*newarray=new char[strlen(buffer)+1];
        wordBank[i]=newarray; 
        strcpy(wordBank[i], buffer);
    }
    //picks random number to generate a random word
    int mysterynumber = rand()%5757;
    strcpy(mystery, wordBank[0]);
    mystery[5]='\0';
    bool gameon=true;
    string textentered;
    char line[6];
    char line1[6];
    char line2[6];
    char line3[6];
    char line4[6];
    char line5[6];
    for (int i=0; i<5; i++)
    {
        line[i]=' ';
        line1[i]=' ';
        line2[i]=' ';
        line3[i]=' ';
        line4[i]=' ';
        line5[i]=' ';
        line[5]='\0';
        line1[5]='\0';
        line2[5]='\0';
        line3[5]='\0';
        line4[5]='\0';
        line5[5]='\0';
    }


    //
    //
    //
    //DISPLAY

    sf::RenderWindow window(sf::VideoMode(1250, 2000), "Wordle", sf::Style::Close  |  sf::Style::Resize);

    window.setKeyRepeatEnabled(false);
    //font
    sf::Font font;

    if (!font.loadFromFile("./Roboto-Regular.ttf"))
    {
        std::cout<<"error loading file "<< std::endl;
        system("pause");
    }

    //text
    sf::Text text;
    text.setFont(font);
    text.setString("hello");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold);

    // //text1
    // sf::Text text1;
    // text1.setFont(font);
    // text1.setString("hello");
    // text1.setCharacterSize(40);
    // text1.setFillColor(sf::Color::Black);
    // text1.setStyle(sf::Text::Bold);


    //row 1
    sf::RectangleShape box1(sf::Vector2f(120.0f, 120.0f));
    box1.setFillColor(sf::Color::White);
    box1.setOutlineThickness(4.f);
    box1.setOutlineColor(sf::Color(200,200,200));
    box1.move(295,300);
    sf::RectangleShape box2(sf::Vector2f(120.0f, 120.0f));
    box2.setFillColor(sf::Color::White);
    box2.setOutlineThickness(4.f);
    box2.setOutlineColor(sf::Color(200,200,200));
    box2.move(430,300);
    sf::RectangleShape box3(sf::Vector2f(120.0f, 120.0f));
    box3.setFillColor(sf::Color::White);
    box3.setOutlineThickness(4.f);
    box3.setOutlineColor(sf::Color(200,200,200));
    box3.move(565,300);
    sf::RectangleShape box4(sf::Vector2f(120.0f, 120.0f));
    box4.setFillColor(sf::Color::White);
    box4.setOutlineThickness(4.f);
    box4.setOutlineColor(sf::Color(200,200,200));
    box4.move(700,300);
    sf::RectangleShape box5(sf::Vector2f(120.0f, 120.0f));
    box5.setFillColor(sf::Color::White);
    box5.setOutlineThickness(4.f);
    box5.setOutlineColor(sf::Color(200,200,200));
    box5.move(835,300);

    //row 2
    sf::RectangleShape box6(sf::Vector2f(120.0f, 120.0f));
    box6.setFillColor(sf::Color::White);
    box6.setOutlineThickness(4.f);
    box6.setOutlineColor(sf::Color(200,200,200));
    box6.move(295,435);
    sf::RectangleShape box7(sf::Vector2f(120.0f, 120.0f));
    box7.setFillColor(sf::Color::White);
    box7.setOutlineThickness(4.f);
    box7.setOutlineColor(sf::Color(200,200,200));
    box7.move(430,435);
    sf::RectangleShape box8(sf::Vector2f(120.0f, 120.0f));
    box8.setFillColor(sf::Color::White);
    box8.setOutlineThickness(4.f);
    box8.setOutlineColor(sf::Color(200,200,200));
    box8.move(565,435);
    sf::RectangleShape box9(sf::Vector2f(120.0f, 120.0f));
    box9.setFillColor(sf::Color::White);
    box9.setOutlineThickness(4.f);
    box9.setOutlineColor(sf::Color(200,200,200));
    box9.move(700,435);
    sf::RectangleShape box10(sf::Vector2f(120.0f, 120.0f));
    box10.setFillColor(sf::Color::White);
    box10.setOutlineThickness(4.f);
    box10.setOutlineColor(sf::Color(200,200,200));
    box10.move(835,435);

    //row 3
    sf::RectangleShape box11(sf::Vector2f(120.0f, 120.0f));
    box11.setFillColor(sf::Color::White);
    box11.setOutlineThickness(4.f);
    box11.setOutlineColor(sf::Color(200,200,200));
    box11.move(295,570);
    sf::RectangleShape box12(sf::Vector2f(120.0f, 120.0f));
    box12.setFillColor(sf::Color::White);
    box12.setOutlineThickness(4.f);
    box12.setOutlineColor(sf::Color(200,200,200));
    box12.move(430,570);
    sf::RectangleShape box13(sf::Vector2f(120.0f, 120.0f));
    box13.setFillColor(sf::Color::White);
    box13.setOutlineThickness(4.f);
    box13.setOutlineColor(sf::Color(200,200,200));
    box13.move(565,570);
    sf::RectangleShape box14(sf::Vector2f(120.0f, 120.0f));
    box14.setFillColor(sf::Color::White);
    box14.setOutlineThickness(4.f);
    box14.setOutlineColor(sf::Color(200,200,200));
    box14.move(700,570);
    sf::RectangleShape box15(sf::Vector2f(120.0f, 120.0f));
    box15.setFillColor(sf::Color::White);
    box15.setOutlineThickness(4.f);
    box15.setOutlineColor(sf::Color(200,200,200));
    box15.move(835,570);

    //row 4
    sf::RectangleShape box16(sf::Vector2f(120.0f, 120.0f));
    box16.setFillColor(sf::Color::White);
    box16.setOutlineThickness(4.f);
    box16.setOutlineColor(sf::Color(200,200,200));
    box16.move(295,705);
    sf::RectangleShape box17(sf::Vector2f(120.0f, 120.0f));
    box17.setFillColor(sf::Color::White);
    box17.setOutlineThickness(4.f);
    box17.setOutlineColor(sf::Color(200,200,200));
    box17.move(430,705);
    sf::RectangleShape box18(sf::Vector2f(120.0f, 120.0f));
    box18.setFillColor(sf::Color::White);
    box18.setOutlineThickness(4.f);
    box18.setOutlineColor(sf::Color(200,200,200));
    box18.move(565,705);
    sf::RectangleShape box19(sf::Vector2f(120.0f, 120.0f));
    box19.setFillColor(sf::Color::White);
    box19.setOutlineThickness(4.f);
    box19.setOutlineColor(sf::Color(200,200,200));
    box19.move(700,705);
    sf::RectangleShape box20(sf::Vector2f(120.0f, 120.0f));
    box20.setFillColor(sf::Color::White);
    box20.setOutlineThickness(4.f);
    box20.setOutlineColor(sf::Color(200,200,200));
    box20.move(835,705);

    //row 5
    sf::RectangleShape box21(sf::Vector2f(120.0f, 120.0f));
    box21.setFillColor(sf::Color::White);
    box21.setOutlineThickness(4.f);
    box21.setOutlineColor(sf::Color(200,200,200));
    box21.move(295,840);
    sf::RectangleShape box22(sf::Vector2f(120.0f, 120.0f));
    box22.setFillColor(sf::Color::White);
    box22.setOutlineThickness(4.f);
    box22.setOutlineColor(sf::Color(200,200,200));
    box22.move(430,840);
    sf::RectangleShape box23(sf::Vector2f(120.0f, 120.0f));
    box23.setFillColor(sf::Color::White);
    box23.setOutlineThickness(4.f);
    box23.setOutlineColor(sf::Color(200,200,200));
    box23.move(565,840);
    sf::RectangleShape box24(sf::Vector2f(120.0f, 120.0f));
    box24.setFillColor(sf::Color::White);
    box24.setOutlineThickness(4.f);
    box24.setOutlineColor(sf::Color(200,200,200));
    box24.move(700,840);
    sf::RectangleShape box25(sf::Vector2f(120.0f, 120.0f));
    box25.setFillColor(sf::Color::White);
    box25.setOutlineThickness(4.f);
    box25.setOutlineColor(sf::Color(200,200,200));
    box25.move(835,840);

    //row 6
    sf::RectangleShape box26(sf::Vector2f(120.0f, 120.0f));
    box26.setFillColor(sf::Color::White);
    box26.setOutlineThickness(4.f);
    box26.setOutlineColor(sf::Color(200,200,200));
    box26.move(295,975);
    sf::RectangleShape box27(sf::Vector2f(120.0f, 120.0f));
    box27.setFillColor(sf::Color::White);
    box27.setOutlineThickness(4.f);
    box27.setOutlineColor(sf::Color(200,200,200));
    box27.move(430,975);
    sf::RectangleShape box28(sf::Vector2f(120.0f, 120.0f));
    box28.setFillColor(sf::Color::White);
    box28.setOutlineThickness(4.f);
    box28.setOutlineColor(sf::Color(200,200,200));
    box28.move(565,975);
    sf::RectangleShape box29(sf::Vector2f(120.0f, 120.0f));
    box29.setFillColor(sf::Color::White);
    box29.setOutlineThickness(4.f);
    box29.setOutlineColor(sf::Color(200,200,200));
    box29.move(700,975);
    sf::RectangleShape box30(sf::Vector2f(120.0f, 120.0f));
    box30.setFillColor(sf::Color::White);
    box30.setOutlineThickness(4.f);
    box30.setOutlineColor(sf::Color(200,200,200));
    box30.move(835,975);


    while (window.isOpen())
    {
        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                    //std::cout<<"New window width: "<<event.size.width<<"New window height: "<<event.size.height<<std::endl;
                    printf("New window width: %i New window heigh: %i", evnt.size.width, evnt.size.height);
                    break;
                case sf::Event::TextEntered:
                    if (evnt.text.unicode==8)
                    {
                        if (textentered.size()>0)
                        {
                            textentered.pop_back();
                        }
                    }
                    else if (evnt.text.unicode==10)
                    {
                        textentered.size();
                    }
                    else if(evnt.text.unicode<128)
                    {
                        printf("%c", evnt.text.unicode);
                        if (textentered.size()<30)
                        {
                            textentered.push_back(evnt.text.unicode);     
                        }
                        
                    }
            }
        
        if (evnt.type == sf::Event::KeyPressed)
        {
            if (evnt.key.code==sf::Keyboard::Enter)
            {
                cout<<"Iterations"<<endl;
                if (counter==0)
                {
                    counter++;
                    for (int i=0; i<5; i++)
                    {
                        line[i]=textentered[i];
                    }
                    if (isvalid(line, wordBank))
                    {
                        gameon=!iscorrect(line, mystery);
                        letterchecker(line,mystery,colors);
                    }
                    else{
                        for (int i=0; i<5; i++)
                        {
                            colors[i]='R';
                        }
                        //counter--;
                    }
                    for (int i=0; i<5; i++)
                    {
                        cout<<colors[i]<<endl;
                    }
                }
                else if (counter==1)
                {
                    cout<<textentered<<" Counter: "<<counter;
                    counter++;
                    for (int i=0; i<5; i++)
                    {
                        line1[i]=textentered[i+5];
                    }
                    if (isvalid(line1, wordBank))
                    {
                        gameon=!iscorrect(line1, mystery);
                        letterchecker(line1,mystery,colors1);
                    }
                    else{
                        for (int i=0; i<5; i++)
                        {
                            colors1[i]='R';
                        }
                        //counter--;
                    }
                }
                else if (counter==2)
                {
                    cout<<textentered<<" Counter: "<<counter;
                    counter++;
                    for (int i=0; i<5; i++)
                    {
                        line2[i]=textentered[i+10];
                    }
                    if (isvalid(line2, wordBank))
                    {
                        gameon=!iscorrect(line2, mystery);
                        letterchecker(line2,mystery,colors2);
                    }
                    else{
                        for (int i=0; i<5; i++)
                        {
                            colors2[i]='R';
                        }
                        //counter--;
                    }
                }
                else if (counter==3)
                {
                    cout<<textentered<<" Counter: "<<counter;
                    counter++;
                    for (int i=0; i<5; i++)
                    {
                        line3[i]=textentered[i+15];
                    }
                    if (isvalid(line3, wordBank))
                    {
                        gameon=!iscorrect(line3, mystery);
                        letterchecker(line3,mystery,colors3);
                    }
                    else{
                        for (int i=0; i<5; i++)
                        {
                            colors3[i]='R';
                        }
                        //counter--;
                    }
                }
                else if (counter==4)
                {
                    cout<<textentered<<" Counter: "<<counter;
                    counter++;
                    for (int i=0; i<5; i++)
                    {
                        line4[i]=textentered[i+20];
                    }
                    if (isvalid(line4, wordBank))
                    {
                        gameon=!iscorrect(line4, mystery);
                        letterchecker(line4,mystery,colors4);
                    }
                    else{
                        for (int i=0; i<5; i++)
                        {
                            colors4[i]='R';
                        }
                        //counter--;
                    }
                }
                else if (counter==5)
                {
                    cout<<textentered<<" Counter: "<<counter;
                    counter++;
                    for (int i=0; i<5; i++)
                    {
                        line5[i]=textentered[i+25];
                    }
                    if (isvalid(line5, wordBank))
                    {
                        gameon=!iscorrect(line5, mystery);
                        letterchecker(line3,mystery,colors5);
                    }
                    else{
                        for (int i=0; i<5; i++)
                        {
                            colors5[i]='R';
                        }
                        //counter--;
                    }
                }
            }
        }
        }
        box1=colorchanger(box1,0,colors);
        box2=colorchanger(box2,1,colors);
        box3=colorchanger(box3,2,colors);
        box4=colorchanger(box4,3,colors);
        box5=colorchanger(box5,4,colors);
        box6=colorchanger(box6,0,colors1);
        box7=colorchanger(box7,1,colors1);
        box8=colorchanger(box8,2,colors1);
        box9=colorchanger(box9,3,colors1);
        box10=colorchanger(box10,4,colors1);
        box11=colorchanger(box11,0,colors2);
        box12=colorchanger(box12,1,colors2);
        box13=colorchanger(box13,2,colors2);
        box14=colorchanger(box14,3,colors2);
        box15=colorchanger(box15,4,colors2);
        box16=colorchanger(box16,0,colors3);
        box17=colorchanger(box17,1,colors3);
        box18=colorchanger(box18,2,colors3);
        box19=colorchanger(box19,3,colors3);
        box20=colorchanger(box20,4,colors3);
        box21=colorchanger(box21,0,colors4);
        box22=colorchanger(box22,1,colors4);
        box23=colorchanger(box23,2,colors4);
        box24=colorchanger(box24,3,colors4);
        box25=colorchanger(box25,4,colors4);
        box26=colorchanger(box26,0,colors5);
        box27=colorchanger(box27,1,colors5);
        box28=colorchanger(box28,2,colors5);
        box29=colorchanger(box29,3,colors5);
        box30=colorchanger(box30,4,colors5);
        

            
        
        


        window.clear(sf::Color::White);


        window.draw(box1);
        window.draw(box2);
        window.draw(box3);
        window.draw(box4);
        window.draw(box5);
        window.draw(box6);
        window.draw(box7);
        window.draw(box8);
        window.draw(box9);
        window.draw(box10);
        window.draw(box11);
        window.draw(box12);
        window.draw(box13);
        window.draw(box14);
        window.draw(box15);
        window.draw(box16);
        window.draw(box17);
        window.draw(box18);
        window.draw(box19);
        window.draw(box20);
        window.draw(box21);
        window.draw(box22);
        window.draw(box23);
        window.draw(box24);
        window.draw(box25);
        window.draw(box26);
        window.draw(box27);
        window.draw(box28);
        window.draw(box29);
        window.draw(box30);

        if (counter==0)
        {
            text.setPosition(210,342);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(textentered[i]));
                text.move(135,0);
                window.draw(text);
            }
        }
        else if (counter==1)
        {
            text.setPosition(210,342);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,477);
            for (int i=5; i<10; i++)
            {
                text.setString((char)toupper(textentered[i]));
                text.move(135,0);
                window.draw(text);
            }
        }
        else if (counter==2)
        {
            text.setPosition(210,342);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,477);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line1[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,612);
            for (int i=10; i<15; i++)
            {
                text.setString((char)toupper(textentered[i]));
                text.move(135,0);
                window.draw(text);
            }
        }
        else if (counter==3)
        {
            text.setPosition(210,342);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,477);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line1[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,612);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line2[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,747);
            for (int i=15; i<20; i++)
            {
                text.setString((char)toupper(textentered[i]));
                text.move(135,0);
                window.draw(text);
            }
        }
        else if (counter==4)
        {
            text.setPosition(210,342);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,477);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line1[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,612);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line2[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,747);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line3[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,882);
            for (int i=20; i<25; i++)
            {
                text.setString((char)toupper(textentered[i]));
                text.move(135,0);
                window.draw(text);
            }
        }
        else if (counter==5)
        {
            text.setPosition(210,342);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,477);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line1[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,612);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line2[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,747);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line3[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,882);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line4[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,1017);
            for (int i=20; i<25; i++)
            {
                text.setString((char)toupper(textentered[i]));
                text.move(135,0);
                window.draw(text);
            }
        }
        else if (counter==6)
        {
            text.setPosition(210,342);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,477);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line1[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,612);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line2[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,747);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line3[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,882);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line4[i]));
                text.move(135,0);
                window.draw(text);
            }
            text.setPosition(210,1017);
            for (int i=0; i<5; i++)
            {
                text.setString((char)toupper(line5[i]));
                text.move(135,0);
                window.draw(text);
            }
        }
        window.display();
    }

    return 0;
}

//function checks if inputted word matches the mystery word
bool iscorrect (char input[],char mystery[]) {
    for (int i=0; i<5;i++)
    {   
        if (input[i]!=mystery[i])
        {
            return false;
        }
    }
    return true;
}
//function checks if the inputted word is a valid 5 letter word
bool isvalid (char input[],char* wordBank[]) {
    if (strlen(input)>5)
    {
        return false;
    }
    for (int j=0; j<5757; j++){
        bool wordfound=true;
        for (int i=0; i<5;i++)
        {
            if (input[i]!=(wordBank[j])[i])
            {
                wordfound=false;
                break;
            }
        }
        if (wordfound)
        {
            return true;
        }
    }
    return false;
}

//function couts which letters are correct
void letterchecker (char input[],char mystery[], char colors[]) {
    char output2[5];
    for (int i=0; i<5; i++)
    {
        colors[i]='-';
        output2[i]='-';
    }
    colors[5]='\0';
    for (int i=0; i<5; i++)
    {
        if (input[i]==mystery[i])
        {
            colors[i]='G';
            output2[i]='X';
        }
    }
    for (int i=0; i<5; i++)
    {
        if (colors[i]!='G')
        {
            for (int j=0; j<5; j++)
            {
                if (output2[j]!='X')
                {
                    if (input[i]==mystery[j])
                    {
                        colors[i]='Y';
                        output2[j]='X';
                    }
                }
            }
        }
    }
}

sf::RectangleShape colorchanger (sf::RectangleShape box, int number, char colors[])
{
    if (colors[number]=='Y')
    {
        box.setFillColor(sf::Color::Yellow);
    }
    else if (colors[number]=='G')
    {
        box.setFillColor(sf::Color::Green);
    }
    else if (colors[number]=='-')
    {
        box.setFillColor(sf::Color(200,200,200));
    }
    else if (colors[number]=='R') {
        box.setFillColor(sf::Color::Red);
    }
    else
    {
        box.setFillColor(sf::Color::White);
    }
    return box;
}