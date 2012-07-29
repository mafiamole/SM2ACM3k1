/*
    Copyright (c) 2012 Paul Brown <email>

    Permission is hereby granted, free of charge, to any person
    obtaining a copy of this software and associated documentation
    files (the "Software"), to deal in the Software without
    restriction, including without limitation the rights to use,
    copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following
    conditions:

    The above copyright notice and this permission notice shall be
    included in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
    OTHER DEALINGS IN THE SOFTWARE.
*/


#include <client/SpriteSheet.h>
#include <iostream>

SpriteSheet::SpriteSheet()
{

}


SpriteSheet::SpriteSheet(const sf::Texture& texture, unsigned int spriteWidth, unsigned int spriteHeight) : sf::Sprite(texture), 
  columnCount( 0 ),
  rowCount(0),
  frameCount(0),
  currentFrame(0),
  currentFrameRect(0,0,spriteWidth,spriteHeight)
{
  columnCount 	= texture.getSize().x / spriteWidth;
  rowCount 	= texture.getSize().y / spriteHeight;
  //std::cout << columnCount << "-" << rowCount << std::endl;
  frameCount	= rowCount * columnCount;
  this->SetFrame(0);
}

SpriteSheet::~SpriteSheet()
{

}

unsigned int SpriteSheet::GetRowCount()
{
  return this->rowCount;
}

unsigned int SpriteSheet::GetColumnCount()
{
  return this->columnCount;
}

unsigned int SpriteSheet::GetFrameCount()
{
  return this->frameCount;
}

void SpriteSheet::SetFrame(unsigned int frame)
{
  this->currentFrame = frame;

  this->setTextureRect(this->GetFramePostion(frame));
}

sf::IntRect SpriteSheet::GetFramePostion(unsigned int frame)
{
  unsigned int tileXPosition = frame % this->columnCount;
  unsigned int tileYPosition = frame / this->columnCount;
  //unsigned int xPos = tileXPosition * this->currentFrameRect.width;
  //unsigned int yPos = tileYPosition * this->currentFrameRect.height;
  //std::cout << xPos << " " << yPos << std::endl;
  sf::IntRect result (
	      tileXPosition * this->currentFrameRect.width,
	      tileYPosition * this->currentFrameRect.height,
	      this->currentFrameRect.width,
	      this->currentFrameRect.height
	      );
  return result;
}

sf::IntRect SpriteSheet::GetCurrentFramePosition()
{
  return this->currentFrameRect;
}
