currAudio = 0
isPlaying = 0
sound = 0

function init()



end

function update( events, elapsed )
	
end

function draw()
isPlaying = 0
if isPlaying == 0 then
		if currAudio == 0 then
			sound = Sound.Load("mouthpop.wav")
			Sound.Play(sound)
		elseif currAudio == 1 then

		else

		end		
		isPlaying = 1
end

end
