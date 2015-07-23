local spine = require "spine"

local json = spine.SkeletonJson.new()
local skeletonData = json:readSkeletonDataFile("data/spineboy.json")

local skeleton = spine.Skeleton.new(skeletonData)
skeleton.x = 500
skeleton.y = 0
skeleton.flipX = false
skeleton.flipY = false
skeleton.debugBones = false -- Omit or set to false to not draw debug lines on top of the images.
skeleton.debugSlots = false
skeleton:setToSetupPose()

-- AnimationStateData defines crossfade durations between animations.
local stateData = spine.AnimationStateData.new(skeletonData)
stateData:setMix("walk", "jump", 0.2)
stateData:setMix("jump", "run", 0.2)

-- AnimationState has a queue of animations and can apply them with crossfading.
local state = spine.AnimationState.new(stateData)
-- state:setAnimationByName(0, "test")
state:setAnimationByName(0, "walk", true)
state:addAnimationByName(0, "jump", true, 3)
state:addAnimationByName(0, "run", true, 0)

-- state.onStart = function (trackIndex)
-- 	print(trackIndex.." start: "..state:getCurrent(trackIndex).animation.name)
-- end
-- state.onEnd = function (trackIndex)
-- 	print(trackIndex.." end: "..state:getCurrent(trackIndex).animation.name)
-- end
-- state.onComplete = function (trackIndex, loopCount)
-- 	print(trackIndex.." complete: "..state:getCurrent(trackIndex).animation.name..", "..loopCount)
-- end
-- state.onEvent = function (trackIndex, event)
-- 	print(trackIndex.." event: "..state:getCurrent(trackIndex).animation.name..", "..event.data.name..", "..event.intValue..", "..event.floatValue..", '"..(event.stringValue or "").."'")
-- end

function only2d.update ()
	-- Update the state with the delta time, apply it, and update the world transforms.
	state:update(only2d.timer.getDelta())
	state:apply(skeleton)
	skeleton:updateWorldTransform()
	skeleton:draw()

	only2d.window.setTitle("FPS: " .. only2d.timer.getFPS() .. " drawcalls: " .. only2d.graphics.getDrawCalls())
end