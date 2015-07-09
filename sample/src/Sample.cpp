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
    image2 = graphics->createImage(imagedata);
    image2->setX(100);

    batch = graphics->createImageBatch();
    batch->addImage(image);
	batch->addImage(image2);

    file.reset();
    filedata.reset();
    imagedata.reset();
    texturedata.reset();

    image->setAlpha(0.2f);
//    image->setWidth(1024.0f);
}

void Sample::update(float delta)
{
//    batch->draw();
    image->draw();
//    image2->draw();
}

void Sample::finalize()
{
    image.reset();
}
