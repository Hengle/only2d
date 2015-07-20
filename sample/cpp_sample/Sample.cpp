//
// Created by leafnsand on 2015/6/4.
//

#include "Sample.h"

Sample::Sample()
{
}

Sample::~Sample()
{
}

void Sample::initialize()
{
	auto fileSystem = Module::getInstance<FileSystem>(ModuleType::FILESYSTEM);
	auto texture = Module::getInstance<Texture>(ModuleType::TEXTURE);
	auto graphics = Module::getInstance<Graphics>(ModuleType::GRAPHICS);

	graphics->setBackgroundColor(ColorGray);

	auto file = fileSystem->openBinaryFile(fileSystem->getSourceDir() + "mario.png");
	auto filedata = file->read(FileReadMode::ALL);
	auto texturedata = texture->createTextureData(filedata);
	auto imagedata = graphics->createImageData(texturedata->getWidth(), texturedata->getHeight(), texturedata);
	image = graphics->createImage(imagedata);

	file.reset();
	filedata.reset();
	imagedata.reset();
	texturedata.reset();

	fileSystem.reset();
	texture.reset();
	graphics.reset();

	image->setX(500);
	image->setY(500);

	image->setOffsetX(image->getWidth() / 2);
	image->setOffsetY(image->getHeight() / 2);

	image->setRotation(45 * 3.14 / 180);

	image->setScaleX(0.5);
	image->setScaleY(0.5);
}

void Sample::update(float delta)
{
	image->draw();
}

void Sample::finalize()
{
	image.reset();
}
