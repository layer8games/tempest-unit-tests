/*------------------------------------------------------------
This file will test the functionality of the Vector4 class which
will be used in the Killer1 Engine. Most of the examples and all
of the equations are from 3D Math Primer for Graphics and Game
Development by Dunn and Parberry (awesome book for those who
wish to learn).

Uses the boost test library.

Boost Software License - Version 1.0 - August 17th, 2003

Permission is hereby granted, free of charge, to any person or organization
obtaining a copy of the software and accompanying documentation covered by
this license (the "Software") to use, reproduce, display, distribute,
execute, and transmit the Software, and to prepare derivative works of the
Software, and to permit third-parties to whom the Software is furnished to
do so, all subject to the following:

The copyright notices in the Software and this entire statement, including
the above license grant, this restriction and the following disclaimer,
must be included in all copies of the Software, in whole or in part, and
all derivative works of the Software, unless such copies or derivative
works are solely in the form of machine-executable object code generated by
a source language processor.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.


Written by Maxwell Miller
-------------------------------------------------------------*/

#include "stdafx.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <UnitTests/TestHelper.h>
#include <Engine/Atom.h>
#include <Engine/Quaternion.h>


#include <math.h>
#include <string.h>
#include <stdlib.h>

namespace TM = TempestMath;

BOOST_AUTO_TEST_CASE(QuaternionDefaultConstructor)
{
    TM::Quaternion q{};

    BOOST_CHECK_EQUAL(q.w, 0.0f);
    BOOST_CHECK_EQUAL(q.x, 0.0f);
    BOOST_CHECK_EQUAL(q.y, 0.0f);
    BOOST_CHECK_EQUAL(q.z, 0.0f);
}

BOOST_AUTO_TEST_CASE(QuaternionSingleValueConstructor)
{
    TM::Quaternion q{1.0f};

    BOOST_CHECK_EQUAL(q.w, 1.0f);
    BOOST_CHECK_EQUAL(q.x, 1.0f);
    BOOST_CHECK_EQUAL(q.y, 1.0f);
    BOOST_CHECK_EQUAL(q.z, 1.0f);
}

BOOST_AUTO_TEST_CASE(QuaternionMultiValueConstructor)
{
    TM::Quaternion q{0.0f, 1.0f, 2.0f, 3.0f};

    BOOST_CHECK_EQUAL(q.w, 0.0f);
    BOOST_CHECK_EQUAL(q.x, 1.0f);
    BOOST_CHECK_EQUAL(q.y, 2.0f);
    BOOST_CHECK_EQUAL(q.z, 3.0f);	
}

BOOST_AUTO_TEST_CASE(QuaternionCopyConstructor)
{
    TM::Quaternion q{1.0f, 4.0f, 2.0f, 0.004f};
    TM::Quaternion q2 = q;

    BOOST_CHECK_EQUAL(q2.w, 1.0f);
    BOOST_CHECK_EQUAL(q2.x, 4.0f);
    BOOST_CHECK_EQUAL(q2.y, 2.0f);
    BOOST_CHECK_EQUAL(q2.z, 0.004f);
}

BOOST_AUTO_TEST_CASE(QuaternionMagnitude)
{
    TM::Quaternion q{0.5f, 10.0f, 20.0f, 30.0f};

    BOOST_CHECK_EQUAL(RoundReal(q.Magnitude()), RoundReal(37.41992f));
}

BOOST_AUTO_TEST_CASE(QuaternionConjugate)
{
    TM::Quaternion q1{1.0f, 3.0f, 5.0f, 2.0f};

    TM::Quaternion q2{-3.04f, 0.9435f, -0.8443f, -3.043234f};

    TM::Quaternion q3 = q1.Conjugate();

    TM::Quaternion q4 = q2.Conjugate();

    BOOST_CHECK_EQUAL(q3.w, 1.0f);
    BOOST_CHECK_EQUAL(q3.x, -3.0f);
    BOOST_CHECK_EQUAL(q3.y, -5.0f);
    BOOST_CHECK_EQUAL(q3.z, -2.0f);

    BOOST_CHECK_EQUAL(q4.w, -3.04f);
    BOOST_CHECK_EQUAL(q4.x, -0.9435f);
    BOOST_CHECK_EQUAL(q4.y, 0.8443f);
    BOOST_CHECK_EQUAL(q4.z, 3.043234f);
}

BOOST_AUTO_TEST_CASE(QuaternionInverse)
{
    TM::Quaternion q1{1.0f, 6.0f, 8.0f, 12.0f};

    TM::Quaternion q2 = q1.Inverse();

    BOOST_CHECK_EQUAL(RoundReal(q2.w), RoundReal(0.06389f));
    BOOST_CHECK_EQUAL(RoundReal(q2.x), RoundReal(-0.38333f));
    BOOST_CHECK_EQUAL(RoundReal(q2.y), RoundReal(-0.51110f));
    BOOST_CHECK_EQUAL(RoundReal(q2.z), RoundReal(-0.76665f));
}

BOOST_AUTO_TEST_CASE(QuaternionDivideByScalar)
{
    TM::Quaternion q1{2.0f, 4.0f, 6.0f, 8.0f};

    q1 = q1 / 2.0f;

    TM::Quaternion q2{3.0f, 6.0f, 9.0f, 12.0f};

    q2 /= 3.0f;

    BOOST_CHECK_EQUAL(q1.w, 1.0f);
    BOOST_CHECK_EQUAL(q1.x, 2.0f);
    BOOST_CHECK_EQUAL(q1.y, 3.0f);
    BOOST_CHECK_EQUAL(q1.z, 4.0f);

    BOOST_CHECK_EQUAL(q2.w, 1.0f);
    BOOST_CHECK_EQUAL(q2.x, 2.0f);
    BOOST_CHECK_EQUAL(q2.y, 3.0f);
    BOOST_CHECK_EQUAL(q2.z, 4.0f);
}

BOOST_AUTO_TEST_CASE(QuaternionMultipliedByScalar)
{
    TM::Quaternion q1{1.0f, 6.0f, 9.0f, 4.0f};

    q1 = q1 * 5.0f;

    TM::Quaternion q2{1.0f, 3.0f, 0.0f, 2.0f};

    q2 *= 14.0f;

    BOOST_CHECK_EQUAL(q1.w, 5.0f);
    BOOST_CHECK_EQUAL(q1.x, 30.0f);
    BOOST_CHECK_EQUAL(q1.y, 45.0f);
    BOOST_CHECK_EQUAL(q1.z, 20.0f);

    BOOST_CHECK_EQUAL(q2.w, 14.0f);
    BOOST_CHECK_EQUAL(q2.x, 42.0f);
    BOOST_CHECK_EQUAL(q2.y, 0.0f);
    BOOST_CHECK_EQUAL(q2.z, 28.0f);
}

BOOST_AUTO_TEST_CASE(QuaternionMultipliedByQuaternion)
{
    TM::Quaternion q1{5.0f, 3.0f, 8.0f, 6.0f};

    TM::Quaternion q2{6.0f, 12.0f, 1.0f, 5.0f};

    TM::Quaternion q3 = q1 * q2;

    TM::Quaternion q4{5.0f, 3.0f, 8.0f, 6.0f};

    q4 *= q2;

    BOOST_CHECK_EQUAL(q3.w, -44.0f);
    BOOST_CHECK_EQUAL(q3.x, 112.0f);
    BOOST_CHECK_EQUAL(q3.y, 110.0f);
    BOOST_CHECK_EQUAL(q3.z, -32.0f);

    BOOST_CHECK_EQUAL(q4.w, -44.0f);
    BOOST_CHECK_EQUAL(q4.x, 112.0f);
    BOOST_CHECK_EQUAL(q4.y, 110.0f);
    BOOST_CHECK_EQUAL(q4.z, -32.0f);
}

BOOST_AUTO_TEST_CASE(QuaternionDifference)
{
    TM::Quaternion q1{1.0f, 2.0f, 3.0f, 2.0f};

    TM::Quaternion q2{1.0f, 3.0f, 2.0f, 3.0f};

    TM::Quaternion q3 = q1.Difference(q2);

    BOOST_CHECK_EQUAL(RoundReal(q3.w), 4.47834f);
    BOOST_CHECK_EQUAL(RoundReal(q3.x), 1.41421f);
    BOOST_CHECK_EQUAL(RoundReal(q3.y), -0.2357f);
    BOOST_CHECK_EQUAL(RoundReal(q3.z), -0.94281f);
}

BOOST_AUTO_TEST_CASE(QuaternionDot)
{
    TM::Quaternion q1{6.0f, 4.0f, 12.0f, 0.0f};

    TM::Quaternion q2{1.0f, 6.0f, 8.0f, 3.0f};

    real dot = q1.Dot(q2);

    BOOST_CHECK_EQUAL(dot, 126.0f);
}

BOOST_AUTO_TEST_CASE(QuaternionNegationAndOpposite)
{
    TM::Quaternion q1{2.0f, -3.0f, 4.0f, -5.0f};

    q1.Negate();

    TM::Quaternion q2{-3.0f, 2.0f, -3.0f, -5.0f};

    TM::Quaternion q3 = q2.Opposite();

    BOOST_CHECK_EQUAL(RoundReal(q1.w), -2.0f);
    BOOST_CHECK_EQUAL(RoundReal(q1.x), 3.0f);
    BOOST_CHECK_EQUAL(RoundReal(q1.y), -4.0f);
    BOOST_CHECK_EQUAL(RoundReal(q1.z), 5.0f);

    BOOST_CHECK_EQUAL(RoundReal(q3.w), 3.0f);
    BOOST_CHECK_EQUAL(RoundReal(q3.x), -2.0f);
    BOOST_CHECK_EQUAL(RoundReal(q3.y), 3.0f);
    BOOST_CHECK_EQUAL(RoundReal(q3.z), 5.0f);
}

BOOST_AUTO_TEST_CASE(QuaternionNormalization)
{
    TM::Quaternion q1{4.0f, 2.0f, 6.0f, 2.0f};

    q1.Normalize();

    BOOST_CHECK_EQUAL(RoundReal(q1.Magnitude()), 1.0f);
}

BOOST_AUTO_TEST_CASE(QuaternionSetEuler)
{
    TM::Quaternion q1{0.0f};
    TM::Vector3 vec{15.0f, 45.0f, 90.0f};

    q1.RotateByEuler(vec);

    BOOST_CHECK_CLOSE(q1.w, -0.547861636f, 0.001);
    BOOST_CHECK_CLOSE(q1.x, -0.0175278038f, 0.001);
    BOOST_CHECK_CLOSE(q1.y, -0.785737991f, 0.001);
    BOOST_CHECK_CLOSE(q1.z, -0.286628932f, 0.001);

    q1.RotateByEuler(45.0f, 65.0f, 180.0f);

    BOOST_CHECK_CLOSE(q1.w, -0.201928511f, 0.001);
    BOOST_CHECK_CLOSE(q1.x, -0.558113098f, 0.001);
    BOOST_CHECK_CLOSE(q1.y, 0.142150357f, 0.001);
    BOOST_CHECK_CLOSE(q1.z, 0.792166591f, 0.001);
}

BOOST_AUTO_TEST_CASE(QuaternionAddEuler)
{
    TM::Quaternion q{0.0f};
    q.RotateByEuler(15.0f, 20.0f, 36.0f);
    q.AddEuler(10.0f, 34.0f, 90.0f);

    BOOST_CHECK_CLOSE(q.w, 0.655196905f, 0.001);
    BOOST_CHECK_CLOSE(q.x, 0.534287393f, 0.001);
    BOOST_CHECK_CLOSE(q.y, 0.520725489f, 0.001);
    BOOST_CHECK_CLOSE(q.z, -0.118739009f, 0.001);

    TM::Vector3 vec{15.0f, 45.0f, 90.0f};
    q.AddEuler(vec);

    BOOST_CHECK_CLOSE(q.w, 0.0255273655f, 0.001);
    BOOST_CHECK_CLOSE(q.x, -0.546752453f, 0.001);
    BOOST_CHECK_CLOSE(q.y, -0.644875228f, 0.001);
    BOOST_CHECK_CLOSE(q.z, -0.53342855f, 0.001);
}