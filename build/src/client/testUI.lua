
Test = 0
sound =0
function init()

  Test = Sprite.Load("paddle.png")
  sound = Sound.Load("mouthpop.wav")
end

function update(a,b)
win ={Window.Size()}
print( "Window x:", win[1])
	
end

function draw()
 print("herro")
 Sprite.Draw(Test)
end

