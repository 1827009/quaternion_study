#pragma once

class vector3
{
	float v_[3] = {};
public:
	vector3() {}
	vector3(float x, float y, float z) { v_[0] = x, v_[1] = y, v_[2] = z; }
	~vector3() {}

	vector3 &set(float x, float y, float z) {
		v_[0] = x; v_[1] = y; v_[2] = z;
		return *this;
	}

	float x() const { return v_[0]; }
	float y() const { return v_[1]; }
	float z() const { return v_[2]; }

	static float dot(const vector3 &lhs, const vector3 &rhs);
	
	vector3& normalize();
};


class quaternion
{
private:
	float x_, y_, z_, w_;

	quaternion operator + (const quaternion& rhs) const;

	float length_sq() const; // �傫����2��
	quaternion conjugate() const;// ������Ԃ�
public:
	quaternion();
	quaternion(float x, float y, float z, float w);
	quaternion(const vector3 &v, float arg);
	~quaternion();

	// �v�f�̎擾
	float x() const { return x_; }
	float y() const { return y_; }
	float z() const { return z_; }
	float w() const { return w_; }

	// ���Z�q�̒�`
	quaternion operator * (float f) const;
	quaternion operator / (float f) const;
	vector3 operator * (const vector3& rhs) const;
	quaternion operator * (const quaternion& rhs) const;

	// �ϊ�
	quaternion &identity();// �P�ʌ��ɂ���i�Ԃ�l�͎������g�j
	quaternion &normalize();// ���K������i�Ԃ�l�͎������g�j

	// ����
	quaternion inverse() const; // �t����Ԃ�
	static quaternion slerp(const quaternion &q0, const quaternion &q1, float t);// ���ʐ��`���
};


