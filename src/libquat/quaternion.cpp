#include "pch.h"
#include <cmath>
#include "../include/libquat.h"

// �R���X�g���N�^
quaternion::quaternion()
{
	// todo: �������ĉ�����
}

quaternion::quaternion(float x, float y, float z, float w)
{
	// todo: �������ĉ�����
}

quaternion::quaternion(const vector3 &v, float arg)
{
	// todo: �������ĉ�����
}

// �f�X�g���N�^
quaternion::~quaternion()
{
}

quaternion quaternion::operator*(float f) const
{
	return quaternion(x_ * f, y_ * f, z_ * f, w_ * f);
}

quaternion quaternion::operator/(float f) const
{
	return quaternion(x_ / f, y_ / f, z_ / f, w_ / f);
}

vector3 quaternion::operator*(const vector3& v) const
{
	// todo: �������ĉ�����
	return vector3();
}

quaternion quaternion::operator*(const quaternion& rhs) const
{
	// todo: �������ĉ�����
	return quaternion();
}

quaternion quaternion::operator+(const quaternion& rhs) const
{
	return quaternion(x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_, w_ + rhs.w_);
}


// �P�ʌ��ɂ���
quaternion &quaternion::identity()
{
	// todo: �������ĉ�����
	return *this;
}

// ���K������
quaternion &quaternion::normalize()
{
	// todo: �������ĉ�����
	return *this;
}

// �傫����2��
float quaternion::length_sq() const
{
	return x_ * x_ + y_ * y_ + z_ * z_ + w_ * w_;
}

// ������Ԃ�
quaternion quaternion::conjugate() const
{
	// todo: �������ĉ�����
	return quaternion();
}

// �t����Ԃ�
quaternion quaternion::inverse() const
{
	// todo: �������ĉ�����
	return quaternion();
}

// ���ʐ��`���
quaternion quaternion::slerp(const quaternion& q0, const quaternion& q1, float t)
{
	// todo: �������ĉ�����
	return quaternion();
}

