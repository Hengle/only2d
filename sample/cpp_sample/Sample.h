#pragma once

#include "Only2D.h"

using namespace only2d;

class Sample : public Application
{
public:
	Sample();

	virtual ~Sample();

	virtual void initialize() override;

	virtual void update(float delta) override;

	virtual void finalize() override;

private:
	std::shared_ptr<Image> image;
	std::shared_ptr<Image> image2;
};