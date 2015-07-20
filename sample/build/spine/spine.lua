-------------------------------------------------------------------------------
-- Spine Runtimes Software License
-- Version 2.3
-- 
-- Copyright (c) 2013-2015, Esoteric Software
-- All rights reserved.
-- 
-- You are granted a perpetual, non-exclusive, non-sublicensable and
-- non-transferable license to use, install, execute and perform the Spine
-- Runtimes Software (the "Software") and derivative works solely for personal
-- or internal use. Without the written permission of Esoteric Software (see
-- Section 2 of the Spine Software License Agreement), you may not (a) modify,
-- translate, adapt or otherwise create derivative works, improvements of the
-- Software or develop new applications using the Software or (b) remove,
-- delete, alter or obscure any trademarks or any copyright, trademark, patent
-- or other intellectual property or proprietary rights notices on or in the
-- Software, including any copy thereof. Redistributions in binary or source
-- form must include this license and terms.
-- 
-- THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
-- IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
-- MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
-- EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
-- SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
-- PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
-- OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
-- WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
-- OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
-- ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
-------------------------------------------------------------------------------

spine = {}

spine.utils = require "spine.utils"
spine.SkeletonJson = require "spine.SkeletonJson"
spine.SkeletonData = require "spine.SkeletonData"
spine.BoneData = require "spine.BoneData"
spine.SlotData = require "spine.SlotData"
spine.IkConstraintData = require "spine.IkConstraintData"
spine.Skin = require "spine.Skin"
spine.RegionAttachment = require "spine.RegionAttachment"
spine.MeshAttachment = require "spine.MeshAttachment"
spine.SkinnedMeshAttachment = require "spine.SkinnedMeshAttachment"
spine.Skeleton = require "spine.Skeleton"
spine.Bone = require "spine.Bone"
spine.Slot = require "spine.Slot"
spine.IkConstraint = require "spine.IkConstraint"
spine.AttachmentType = require "spine.AttachmentType"
spine.AttachmentLoader = require "spine.AttachmentLoader"
spine.Animation = require "spine.Animation"
spine.AnimationStateData = require "spine.AnimationStateData"
spine.AnimationState = require "spine.AnimationState"
spine.EventData = require "spine.EventData"
spine.Event = require "spine.Event"
spine.SkeletonBounds = require "spine.SkeletonBounds"
spine.BlendMode = require "spine.BlendMode"

spine.utils.readFile = function (fileName, base)
	local path = fileName
	if base then path = base .. '/' .. path end
	local file = only2d.filesystem.openBinaryFile(only2d.filesystem.sourceDir .. path)
	local data = file:read(only2d.filesystem.FileReadMode.ALL)
	return data:getBuffer()
end

local json = require "spine.dkjson"
spine.utils.readJSON = function (text)
	return json.decode(text)
end

spine.Skeleton.failed = {} -- Placeholder for an image that failed to load.

spine.Skeleton.new_super = spine.Skeleton.new
function spine.Skeleton.new (skeletonData, group)
	local self = spine.Skeleton.new_super(skeletonData)

	-- createImage can customize where images are found.
	function self:createImage (attachment)
		local file = only2d.filesystem.openBinaryFile(only2d.filesystem.sourceDir .. "data/images/" .. attachment.name .. ".png")
		local fileData = file:read(only2d.filesystem.FileReadMode.ALL)
		local textureData = only2d.texture.createTextureData(fileData)
		local imageData = only2d.graphics.createImageData(textureData:getWidth(), textureData:getHeight(), textureData)
		return only2d.graphics.createImage(imageData)
	end

	-- updateWorldTransform positions images.
	local updateWorldTransform_super = self.updateWorldTransform
	function self:updateWorldTransform ()
		updateWorldTransform_super(self)

		if not self.images then self.images = {} end
		local images = self.images

		if not self.attachments then self.attachments = {} end
		local attachments = self.attachments

		for i,slot in ipairs(self.drawOrder) do
			local attachment = slot.attachment
			if not attachment then
				images[slot] = nil
			elseif attachment.type == spine.AttachmentType.region then
				local image = images[slot]
				if image and attachments[image] ~= attachment then -- Attachment image has changed.
					image = nil
				end
				if not image then -- Create new image.
					image = self:createImage(attachment)
					if image then
						local imageWidth = image:getWidth()
						local imageHeight = image:getHeight()
						attachment.widthRatio = attachment.width / imageWidth
						attachment.heightRatio = attachment.height / imageHeight
						attachment.originX = imageWidth / 2
						attachment.originY = imageHeight / 2
					else
						print("Error creating image: " .. attachment.name)
						image = spine.Skeleton.failed
					end
					images[slot] = image
					attachments[image] = attachment
				end
			end
		end
	end

	function self:draw()
		if not self.images then self.images = {} end
		local images = self.images

		local color = (self.r * 255) << 24 | (self.g * 255) << 16 | (self.b * 255) << 8 | (self.a * 255)

		for i,slot in ipairs(self.drawOrder) do
			local image = images[slot]
			if image and image ~= spine.Skeleton.failed then
				local attachment = slot.attachment
				local x = slot.bone.worldX + attachment.x * slot.bone.m00 + attachment.y * slot.bone.m01
				local y = slot.bone.worldY + attachment.x * slot.bone.m10 + attachment.y * slot.bone.m11
				local rotation = slot.bone.worldRotation + attachment.rotation
				local xScale = slot.bone.worldScaleX + attachment.scaleX - 1
				local yScale = slot.bone.worldScaleY + attachment.scaleY - 1
				if self.flipX then
					xScale = -xScale
					rotation = -rotation
				end
				if self.flipY then
					yScale = -yScale
					rotation = -rotation
				end
				image:setColor(color)
				if slot.data.blendMode == spine.BlendMode.normal then
					image:setBlendMode(only2d.graphics.BlendMode.ALPHA)
				elseif slot.data.blendMode == spine.BlendMode.additive then
					image:setBlendMode(only2d.graphics.BlendMode.ADD)
				elseif slot.data.blendMode == spine.BlendMode.multiply then
					image:setBlendMode(only2d.graphics.BlendMode.MULTIPLY)
				elseif slot.data.blendMode == spine.BlendMode.screen then
					image:setBlendMode(only2d.graphics.BlendMode.SCREEN)
				end
				image:setX(self.x + x)
				image:setY(self.y + y)
				image:setRotation(rotation * 3.1415927 / 180)
				image:setScaleX(xScale * attachment.widthRatio)
				image:setScaleY(yScale * attachment.heightRatio)
				image:setOffsetX(attachment.originX)
				image:setOffsetY(attachment.originY)
				image:draw()
			end
		end
	end

	return self
end

return spine