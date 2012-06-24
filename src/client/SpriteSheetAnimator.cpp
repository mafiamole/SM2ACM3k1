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


#include <client/SpriteSheetAnimator.h>
#include <iostream>
SpriteSheetAnimator::SpriteSheetAnimator(SpriteSheet* spriteSheet) : spriteSheet(spriteSheet),
clock(),
fps(1),
isPlaying(false),
currentIndex(0),
currentAnimation(""),
frameCount(0)
{
clock.restart();
}

SpriteSheetAnimator::~SpriteSheetAnimator()
{

}

void SpriteSheetAnimator::AddAnimation(std::string animation, int argCount, ... )
{
  std::vector<int> frameList;
  va_list vars;
  int itr;

  va_start(vars,argCount);
  for ( itr = 0; itr < argCount; itr++)
  {
    int arg = va_arg(vars,int);
    frameList.push_back( arg );
  }
  va_end(vars);
  std::pair< std::string,std::vector<int> > newAnimation(animation,frameList);
  this->animationLists.insert(newAnimation);
  std::vector<int>::iterator fitr;
 
}


void SpriteSheetAnimator::Play(std::string animation)
{
  if ( this->animationLists.find(animation) != this->animationLists.end() )
  {
    if ( !(this->currentAnimation == animation) )
    {
    this->frameCount = this->animationLists[animation].size();
    this->currentAnimation = animation;
    this->currentIndex = 0;
    this->isPlaying = true;
    clock.restart();
    }
  }
  else
  {
    throw "Animation does not exist.";
  }
}

void SpriteSheetAnimator::SetLoopSpeed(float fps)
{
  this->fps = fps;
}

void SpriteSheetAnimator::Stop()
{
  this->isPlaying = false;
}

void SpriteSheetAnimator::Update()
{
  
  if (isPlaying)
  {

  float timePosition = (clock.getElapsedTime().asSeconds() * fps);

  int temp1 = (currentIndex + ((int)timePosition) % this->frameCount);


    currentIndex = (int)timePosition % this->frameCount;

  
  std::cout << "Using frame " << currentIndex << " " << " " << (int)timePosition << std::endl;

  this->spriteSheet->SetFrame( this->animationLists[this->currentAnimation][currentIndex] );
   
  }
}

