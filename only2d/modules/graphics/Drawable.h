//
// Created by leafnsand on 2015/6/1.
//

#ifndef ONLY2D_DRAWABLE_H
#define ONLY2D_DRAWABLE_H

#include "BlendMode.h"
#include "OpenGL.h"

#include "common/Color.h"
#include "common/Matrix.h"

namespace only2d
{
	class Drawable
	{
	public:
		Drawable();

		virtual ~Drawable();

		virtual void draw();

		float getX() const;

		void setX(float x);

		float getY() const;

		void setY(float y);

		float getRotation() const;

		void setRotation(float rotation);

		float getScaleX() const;

		void setScaleX(float scaleX);

		float getScaleY() const;

		void setScaleY(float scaleY);

		float getOffsetX() const;

		void setOffsetX(float offsetX);

		float getOffsetY() const;

		void setOffsetY(float offsetY);

		float getSkewX() const;

		void setSkewX(float skewX);

		float getSkewY() const;

		void setSkewY(float skewY);

		float getAlpha() const;

		void setAlpha(float alpha);

		bool isVisible() const;

		void setVisible(bool visible);

		const Matrix &getMatrix();

		const Color &getColor() const;

		void setColor(const Color &color);

		const BlendMode &getBlendMode() const;

		void setBlendMode(const BlendMode &mode);

	protected:
		float x;
		float y;
		float rotation;
		float scaleX;
		float scaleY;
		float offsetX;
		float offsetY;
		float skewX;
		float skewY;
		float alpha;
		bool visible;
		Color color;

	private:
		bool update;
		Matrix matrix;
		BlendMode mode;
		std::shared_ptr<OpenGL> gl;
	};
}

#endif //ONLY2D_DRAWABLE_H

