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

	image->setOffsetX(image->getWidth() / 2.0f);
	image->setOffsetY(image->getHeight() / 2.0f);

	image->setRotation(45.0f * 3.14f / 180.0f);

	image->setScaleX(0.5f);
	image->setScaleY(0.5f);
}

void Sample::update(float delta)
{
	image->draw();
}

void Sample::finalize()
{
	image.reset();
}
