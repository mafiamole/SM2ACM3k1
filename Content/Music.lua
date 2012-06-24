currAudio = 0
music = 0

function init()
	math.randomseed( os.time() )
	currAudio = math.random(5)
	music = Music.Load("C:\\Content\\" .. currAudio .. ".ogg")
	--Music.SetLoop(true)
	Music.Play(music)
end


function update( events, elapsed )
	
end

function draw()

	
		

end
