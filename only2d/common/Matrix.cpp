//
// Created by leafnsand on 2015/6/3.
//

#include "Matrix.h"

#include <cmath>
#include <cstring>

namespace only2d
{
	Matrix::Matrix()
	{
		setIdentity();
	}

	Matrix::Matrix(float x, float y, float rotation, float scaleX, float scaleY, float offsetX, float offsetY,
	               float skewX, float skewY)
	{
		setTransformation(x, y, rotation, scaleX, scaleY, offsetX, offsetY, skewX, skewY);
	}

	Matrix::~Matrix()
	{
	}

	void Matrix::setOrthographic(float left, float right, float bottom, float top)
	{
		setIdentity();
		data[0] = 2.0f / (right - left);
		data[5] = 2.0f / (top - bottom);
		data[10] = -1.0f;
		data[12] = -(right + left) / (right - left);
		data[13] = -(top + bottom) / (top - bottom);
	}

	/**
     * |1 0 0 0|
     * |0 1 0 0|
     * |0 0 1 0|
     * |0 0 0 1|
     */
	void Matrix::setIdentity()
	{
		std::memset(data, 0, 16 * sizeof(float));
		data[0] = data[5] = data[10] = data[15] = 1.0f;
	}

	/**
     * |1 0 0 x-offsetX|
     * |0 1 0 y-offsetY|
     * |0 0 1     0    |
     * |0 0 0     1    |
     */
	void Matrix::setTranslation(float x, float y, float offsetX, float offsetY)
	{
		setIdentity();
		data[12] = x - offsetX;
		data[13] = y - offsetY;
	}

	/**
     * |cos(rotation) -sin(rotation) 0 0|
     * |sin(rotation)  cos(rotation) 0 0|
     * |      0              0       1 0|
     * |      0              0       0 1|
     */
	void Matrix::setRotation(float rotation)
	{
		setIdentity();
		auto cos = cosf(rotation);
		auto sin = sinf(rotation);
		data[0] = data[5] = cos;
		data[1] = sin;
		data[4] = -sin;
	}

	/**
     * |scaleX    0   0 0|
     * |   0   scaleY 0 0|
     * |   0      0   1 0|
     * |   0      0   0 1|
     */
	void Matrix::setScale(float scaleX, float scaleY)
	{
		setIdentity();
		data[0] = scaleX;
		data[5] = scaleY;
	}

	/**
     * |  1   skewY 0 0|
     * |skewX   1   0 0|
     * |  0     0   1 0|
     * |  0     0   0 1|
     */
	void Matrix::setSkew(float skewX, float skewY)
	{
		setIdentity();
		data[1] = skewX;
		data[4] = skewY;
	}

	void Matrix::setTransformation(float x, float y, float rotation, float scaleX, float scaleY, float offsetX,
	                               float offsetY, float skewX, float skewY)
	{
		std::memset(data, 0, 16 * sizeof(float));
		auto cos = cosf(rotation);
		auto sin = sinf(rotation);
		data[10] = data[15] = 1.0f;
		data[0] = cos * scaleX - skewY * sin * scaleY;
		data[1] = sin * scaleX + skewY * cos * scaleY;
		data[4] = skewX * cos * scaleX - sin * scaleY;
		data[5] = skewX * sin * scaleX + cos * scaleY;
		data[12] = x - offsetX * data[0] - offsetY * data[4];
		data[13] = y - offsetX * data[1] - offsetY * data[5];
	}

	Vector Matrix::transform(const Vector vector) const
	{
		return Vector(data[0] * vector.x + data[4] * vector.y + data[12],
		              data[1] * vector.x + data[5] * vector.y + data[13]);
	}

	void Matrix::translate(float x, float y, float offsetX, float offsetY)
	{
		Matrix matrix;
		matrix.setTranslation(x, y, offsetX, offsetY);
		*this *= matrix;
	}

	void Matrix::rotate(float rotation)
	{
		Matrix matrix;
		matrix.setRotation(rotation);
		*this *= matrix;
	}

	void Matrix::scale(float scaleX, float scaleY)
	{
		Matrix matrix;
		matrix.setScale(scaleX, scaleY);
		*this *= matrix;
	}

	void Matrix::skew(float skewX, float skewY)
	{
		Matrix matrix;
		matrix.setSkew(skewX, skewY);
		*this *= matrix;
	}

	Matrix Matrix::operator*(const Matrix &matrix) const
	{
		Matrix temp;

		temp.data[0] = (data[0] * matrix.data[0]) + (data[4] * matrix.data[1]) + (data[8] * matrix.data[2]) +
			(data[12] * matrix.data[3]);
		temp.data[4] = (data[0] * matrix.data[4]) + (data[4] * matrix.data[5]) + (data[8] * matrix.data[6]) +
			(data[12] * matrix.data[7]);
		temp.data[8] = (data[0] * matrix.data[8]) + (data[4] * matrix.data[9]) + (data[8] * matrix.data[10]) +
			(data[12] * matrix.data[11]);
		temp.data[12] = (data[0] * matrix.data[12]) + (data[4] * matrix.data[13]) + (data[8] * matrix.data[14]) +
			(data[12] * matrix.data[15]);

		temp.data[1] = (data[1] * matrix.data[0]) + (data[5] * matrix.data[1]) + (data[9] * matrix.data[2]) +
			(data[13] * matrix.data[3]);
		temp.data[5] = (data[1] * matrix.data[4]) + (data[5] * matrix.data[5]) + (data[9] * matrix.data[6]) +
			(data[13] * matrix.data[7]);
		temp.data[9] = (data[1] * matrix.data[8]) + (data[5] * matrix.data[9]) + (data[9] * matrix.data[10]) +
			(data[13] * matrix.data[11]);
		temp.data[13] = (data[1] * matrix.data[12]) + (data[5] * matrix.data[13]) + (data[9] * matrix.data[14]) +
			(data[13] * matrix.data[15]);

		temp.data[2] = (data[2] * matrix.data[0]) + (data[6] * matrix.data[1]) + (data[10] * matrix.data[2]) +
			(data[14] * matrix.data[3]);
		temp.data[6] = (data[2] * matrix.data[4]) + (data[6] * matrix.data[5]) + (data[10] * matrix.data[6]) +
			(data[14] * matrix.data[7]);
		temp.data[10] = (data[2] * matrix.data[8]) + (data[6] * matrix.data[9]) + (data[10] * matrix.data[10]) +
			(data[14] * matrix.data[11]);
		temp.data[14] = (data[2] * matrix.data[12]) + (data[6] * matrix.data[13]) + (data[10] * matrix.data[14]) +
			(data[14] * matrix.data[15]);

		temp.data[3] = (data[3] * matrix.data[0]) + (data[7] * matrix.data[1]) + (data[11] * matrix.data[2]) +
			(data[15] * matrix.data[3]);
		temp.data[7] = (data[3] * matrix.data[4]) + (data[7] * matrix.data[5]) + (data[11] * matrix.data[6]) +
			(data[15] * matrix.data[7]);
		temp.data[11] = (data[3] * matrix.data[8]) + (data[7] * matrix.data[9]) + (data[11] * matrix.data[10]) +
			(data[15] * matrix.data[11]);
		temp.data[15] = (data[3] * matrix.data[12]) + (data[7] * matrix.data[13]) + (data[11] * matrix.data[14]) +
			(data[15] * matrix.data[15]);

		return temp;
	}

	void Matrix::operator*=(const Matrix &matrix)
	{
		auto temp = *this * matrix;
		std::memcpy(data, temp.data, 16 * sizeof(float));
	}

	void Matrix::assign(const float *buffer)
	{
		std::memcpy(data, buffer, 16 * sizeof(float));
	}

	const float *Matrix::getBuffer() const
	{
		return data;
	}
}