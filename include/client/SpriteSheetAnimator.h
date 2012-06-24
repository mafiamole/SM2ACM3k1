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


#ifndef SPRITESHEETANIMATOR_H
#define SPRITESHEETANIMATOR_H
#include <client/SpriteSheet.h>
#include <vector>
#include <map>
#include <cstdarg>

typedef std::map< std::string,std::vector<int> > FrameLists;

class SpriteSheetAnimator
{
private:
  
  SpriteSheet* 				spriteSheet;
  FrameLists 				animationLists;
  sf::Clock 				clock;
  float 				fps;
  bool 					isPlaying;
  int					currentIndex;
  std::string 				currentAnimation;
  int					frameCount;
  
public:

    SpriteSheetAnimator			(SpriteSheet* spriteSheet);
    virtual ~SpriteSheetAnimator	();
    void AddAnimation			(std::string animation,int argCount, ...);
    void Play				(std::string animation);
    void Stop				();
    void SetLoopSpeed			( float fps);
    void Update				();
};

#endif // SPRITESHEETANIMATOR_H
