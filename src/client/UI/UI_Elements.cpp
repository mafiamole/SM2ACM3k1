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

bool UI_Element::Activated(MB::EventList* events)
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

UI_Button::UI_Button(sf::RenderTarget* target,std::string imagefile, std::string name, std::string text) : UI_Element(name), text(text), renderTarget(target)
{
  this->buttonSprite.setTexture(MB::Content::Load<sf::Texture>(imagefile) );
  
}

UI_Button::~UI_Button()
{
  
}

bool UI_Button::Activated(MB::EventList* events)
{

  MB::EventList::iterator eventItr;
  
 // std::cout << events->size() << std::endl;
  
  for (eventItr = events->begin(); eventItr != events->end(); eventItr++ )
  {
    sf::Event event = (*eventItr).second;
    //std::cout << event.mouseButton.button << std::endl;
  }
  
  if (events->find(sf::Event::MouseButtonPressed) != events->end())
  {
    std::cout << "Mouse Button pressed!" << std::endl;
    
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
  
  this->renderTarget->draw(this->buttonSprite);
  
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

bool UI_Radio::Activated(MB::EventList* events)
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

bool UI_TextBox::Activated(MB::EventList* events)
{
  return false;
}

void UI_TextBox::Draw()
{
}