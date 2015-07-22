//
// Created by leafnsand on 2015/6/3.
//

#pragma once

#include "Vector.h"

namespace only2d
{
	class Matrix
	{
	public:
		Matrix();

		Matrix(float x, float y, float rotation, float scaleX, float scaleY, float offsetX, float offsetY, float skewX,
		       float skewY);

		~Matrix();

		void setOrthographic(float left, float right, float bottom, float top);

		void setIdentity();

		void setTranslation(float x, float y, float offsetX, float offsetY);

		void setRotation(float rotation);

		void setScale(float scaleX, float scaleY);

		void setSkew(float skewX, float skewY);

		void setTransformation(float x, float y, float rotation, float scaleX, float scaleY, float offsetX,
		                       float offsetY, float skewX, float skewY);

		Vector transform(const Vector vector) const;

		void translate(float x, float y, float offsetX, float offsetY);

		void rotate(float rotation);

		void scale(float scaleX, float scaleY);

		void skew(float skewX, float skewY);

		Matrix operator*(const Matrix &matrix) const;

		void operator*=(const Matrix &matrix);

		void assign(const float *buffer);

		const float *getBuffer() const;

	private:
		/**
         * |0 4  8 12|
         * |1 5  9 13|
         * |2 6 10 14|
         * |3 7 11 15|
         */
		float data[16];
	};
}