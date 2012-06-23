#include <client/UI/UI_Elements.hpp>
#include <MoleBox/Content/Content.hpp>
/**
 * 
 * 
 *  Base class
 * 
 * 
 * 
 **/

UI_Element::UI_Element(std::string name) : name(name)
{
}

UI_Element::~UI_Element()
{

}

void UI_Element::Set_Position(sf::Vector2f position)
{
  this->position = position;
}

bool UI_Element::Activated(MB::Types::EventList* events)
{
  return false;
}

void UI_Element::Draw()
{
  
}
/**
 * 
 * Button
 * 
 **/

UI_Button::UI_Button(std::string imagefile, std::string name, std::string text) : UI_Element(name), text(text)
{
  this->buttonSprite.setTexture(MB::Content::Load<sf::Texture>(imagefile) ); 
}

UI_Button::~UI_Button()
{
  
}

bool UI_Button::Activated(MB::Types::EventList* events)
{
  
  if (events->find(sf::Event::MouseButtonReleased) != events->end())
  {
    sf::Event ev = events->at(sf::Event::MouseButtonReleased);
    if ( ev.mouseButton.button == sf::Mouse::Left )
    {
      sf::Rect<int> mousePosRect;
      mousePosRect.left 	= ev.mouseButton.x;
      mousePosRect.top 		= ev.mouseButton.y;
      mousePosRect.width 	= 1;
      mousePosRect.height 	= 1;
      
      return this->buttonSprite.getTextureRect().intersects(mousePosRect);
      
    }
  }
  return false;
}

void UI_Button::Draw()
{
}

/**
 * 
 * 
 * Radio
 * 
 * 
 * 
 **/

UI_Radio::UI_Radio(std::string name, std::string text) : UI_Element(name), text(text)
{
  
}

UI_Radio::~UI_Radio()
{
  
}

bool UI_Radio::Activated(MB::Types::EventList* events)
{
  return false;
}

void UI_Radio::Draw()
{
}

/**
 * 
 * UI_TextBox
 * 
 **/

UI_TextBox::UI_TextBox(std::string name) : UI_Element(name)
{
}

UI_TextBox::~UI_TextBox()
{
  
}

bool UI_TextBox::Activated(MB::Types::EventList* events)
{
  return false;
}

void UI_TextBox::Draw()
{
}