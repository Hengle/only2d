//
// Created by leafnsand on 2015/6/4.
//

#ifndef ONLY2D_SAMPLE_H
#define ONLY2D_SAMPLE_H

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
    std::shared_ptr<ImageBatch> batch;
};


#endif //ONLY2D_SAMPLE_H
