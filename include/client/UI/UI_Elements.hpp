#ifndef UI_ELEMENTS_H
#define UI_ELEMENTS_H

#include <SFML/Window.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <MoleBox/ContainerDefinitions.hpp>

class UI_Element
{
 std::string name;
 sf::Vector2f position;
public:
    UI_Element(std::string name);
    
    ~UI_Element();
    void Set_Position(sf::Vector2f position);
    virtual bool Activated(MB::Types::EventList* events);
    virtual void Draw();
};

class UI_Button : public UI_Element
{
  sf::Sprite  buttonSprite;
  std::string text;
  sf::RenderTarget* renderTarget;
public:
  UI_Button(sf::RenderTarget* target,std::string imagefile, std::string name, std::string text);
  ~UI_Button();
    virtual bool Activated(MB::Types::EventList* events);
    virtual void Draw();
};

class UI_Radio : public UI_Element
{
  std::string text;
public:
  UI_Radio(std::string name, std::string text);
  ~UI_Radio();
  virtual bool Activated(MB::Types::EventList* events);
    virtual void Draw();
};

class UI_TextBox : public UI_Element
{
  std::string text;
public:
  UI_TextBox(std::string name);
  ~UI_TextBox();
  virtual bool Activated(MB::Types::EventList* events);
    virtual void Draw();  
};

typedef std::list<UI_Element*> UI_ELEMENTS;
#endif