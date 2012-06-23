
Test = 0
sound =0
function init()

  Test = Sprite.Load("paddle.png")
  sound = Sound.Load("mouthpop.wav")
end

function update(a,b)
 --Sound.Play(Test)	
end

function draw()
 print("herro")
 Sprite.Draw(Test)
end

