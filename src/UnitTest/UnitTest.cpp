#include "pch.h"
#include "CppUnitTest.h"
#include "../include/libquat.h"

#pragma comment(lib,"libquat.lib")

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(QuaternionTest)
	{
		const float PI = 3.1415926535f;

	public:
		
		TEST_METHOD(TestIdentity)// �܂��́A�������ǂ���
		{
			quaternion q;
			q.identity();

			Assert::AreEqual(0.0f, q.x(), 0.0001f, L"x");// ���Ғl�A���ۂ̒l�A�덷�A�R�����g
			Assert::AreEqual(0.0f, q.y(), 0.0001f, L"y");
			Assert::AreEqual(0.0f, q.z(), 0.0001f, L"z");
			Assert::AreEqual(1.0f, q.w(), 0.0001f, L"w");
		}

		TEST_METHOD(TestNormalize) // ������1�ɂł��邩
		{
			quaternion q(1.0f, 2.0f, 2.0f, 4.0f);// ������sqrt(1+4+4+16)=sqrt(25)=5
			q.normalize();

			Assert::AreEqual(1.0f / 5.0f, q.x(), 0.0001f, L"x");
			Assert::AreEqual(2.0f / 5.0f, q.y(), 0.0001f, L"y");
			Assert::AreEqual(2.0f / 5.0f, q.z(), 0.0001f, L"z");
			Assert::AreEqual(4.0f / 5.0f, q.w(), 0.0001f, L"w");
		}

		TEST_METHOD(TestInverse) // �t�������邩?
		{
			// ���K�����ꂽ quaternion �̋t���͋���
			vector3 axis(1.0f, 2.0f, 3.0f);
			quaternion q(axis.normalize(), .1f * PI);
			quaternion c = q.inverse();

			Assert::AreEqual(-q.x(), c.x(), 0.0001f, L"x");
			Assert::AreEqual(-q.y(), c.y(), 0.0001f, L"y");
			Assert::AreEqual(-q.z(), c.z(), 0.0001f, L"z");
			Assert::AreEqual(+q.w(), c.w(), 0.0001f, L"w");
		}

		TEST_METHOD(TestApply)// �x�N�g�����`�L���Ɖ�]�ł��邩?
		{
			vector3 axis(1.0f, 1.0f, 1.0f);
			quaternion q(axis.normalize(), 2.0f * PI / 3.0f);// (1,1,1)�����Ƃ���1/3��]

			vector3 x2(2.0f, 0.0f, 0.0f);
			vector3 y2 = q * x2;
			Assert::AreEqual(0.0f, y2.x(), 0.0001f, L"y-x");
			Assert::AreEqual(2.0f, y2.y(), 0.0001f, L"y-y");
			Assert::AreEqual(0.0f, y2.z(), 0.0001f, L"y-z");

			vector3 z2 = q * y2;
			Assert::AreEqual(0.0f, z2.x(), 0.0001f, L"z-x");
			Assert::AreEqual(0.0f, z2.y(), 0.0001f, L"z-y");
			Assert::AreEqual(2.0f, z2.z(), 0.0001f, L"z-z");
		}

		TEST_METHOD(TestSlerp) // ���ʐ��`��Ԃ̌���
		{
			quaternion q0(vector3(1.0f, 0.0f, 0.0f), 0.5f * PI);// x�������90�x��]
			quaternion q1(vector3(0.0f, 1.0f, 0.0f), 0.5f * PI);// y�������90�x��]
			float t = 0.5f;// �^��
			quaternion qt = quaternion::slerp(q0, q1, t);

			// ���������N�I�[�^�j�I���ŕϊ�
			vector3 z1(0.0f, 0.0f, 1.0f);
			vector3 v = qt * z1;

			Assert::AreEqual(+0.6666f, v.x(), 0.0001f, L"x");
			Assert::AreEqual(-0.6666f, v.y(), 0.0001f, L"y");
			Assert::AreEqual(+0.3333f, v.z(), 0.0001f, L"z");
		}

		TEST_METHOD(TestSlerpParallel) // ����quaternion��Slerp���Ă�������Ɠ�����?
		{
			quaternion q0(vector3(1.0f, 0.0f, 0.0f), 1.0f * PI);// x�������180�x��]
			float t = 0.5f;// �^��
			quaternion qt = quaternion::slerp(q0, q0, t);

			// ���������N�I�[�^�j�I���ŕϊ�
			vector3 z1(0.0f, 0.0f, 1.0f);
			vector3 v = qt * z1;

			Assert::AreEqual( 0.0f, v.x(), 0.0001f, L"x");
			Assert::AreEqual( 0.0f, v.y(), 0.0001f, L"y");
			Assert::AreEqual(-1.0f, v.z(), 0.0001f, L"z");
		}
	};
}
