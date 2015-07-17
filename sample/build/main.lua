sample = {}

only2d.initialize = function ()
	local file = only2d.filesystem.openBinaryFile(only2d.filesystem.sourceDir .. "mario.png")
	local fileData = file:read(only2d.filesystem.FileReadMode.ALL)
	local textureData = only2d.texture.createTextureData(fileData)
	local imageData = only2d.graphics.createImageData(textureData:getWidth(), textureData:getHeight(), textureData)
	sample.image = only2d.graphics.createImage(imageData)
end

only2d.finalize = function ()
	sample = nil
end

only2d.update = function ()
	only2d.window.setTitle("FPS: " .. only2d.timer.getFPS())
	sample.image:setX((sample.image:getX() + 1) % 1024)
	sample.image:draw()
end