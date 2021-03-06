/*------------------------------------------------------------
This file will test the functionality of the Vector3 class which
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
#include <UnitTests/TestHelper.h>
#include <Engine/Atom.h>
#include <Engine/Vector3.h>


namespace TM = TempestMath;

BOOST_AUTO_TEST_CASE(Vector3efaultConstructorAndAccessor) 
{
    TM::Vector3 v {};

    BOOST_CHECK_EQUAL(v.x, 0.0f);
    BOOST_CHECK_EQUAL(v.y, 0.0f);
    BOOST_CHECK_EQUAL(v.z, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector3SingleContructor) 
{
    TM::Vector3 v {5.0f};

    BOOST_CHECK_EQUAL(v.x, 5.0f);
    BOOST_CHECK_EQUAL(v.y, 5.0f);
    BOOST_CHECK_EQUAL(v.z, 5.0f);
}

BOOST_AUTO_TEST_CASE(Vector3TrippleContructor) 
{
    TM::Vector3 v {1.0f, 2.0f, 3.0f};

    BOOST_CHECK_EQUAL(v.x, 1.0f);
    BOOST_CHECK_EQUAL(v.y, 2.0f);
    BOOST_CHECK_EQUAL(v.z, 3.0f);
}

BOOST_AUTO_TEST_CASE(Vector3CopyContructor) 
{
    TM::Vector3 Vector31 {3.0f, 6.0f, 9.0f};

    TM::Vector3 Vector3(Vector31);

    BOOST_CHECK_EQUAL(Vector3.x, 3.0f);
    BOOST_CHECK_EQUAL(Vector3.y, 6.0f);
    BOOST_CHECK_EQUAL(Vector3.z, 9.0f);
}

BOOST_AUTO_TEST_CASE(Vector3Setters) 
{
    TM::Vector3 v{};

    v.x = 5.0f;
    v.y = 10.0f;
    v.z = 20.0f;

    BOOST_CHECK_EQUAL(v.x, 5.0f);
    BOOST_CHECK_EQUAL(v.y, 10.0f);
    BOOST_CHECK_EQUAL(v.z, 20.0f);
}

BOOST_AUTO_TEST_CASE(Vector3CopyAssignment) 
{
    TM::Vector3 v1 {4.5f, 5.4f, 6.8f};

    TM::Vector3 v2 = v1;

    BOOST_CHECK_EQUAL(v2.x, 4.5f);
    BOOST_CHECK_EQUAL(v2.y, 5.4f);
    BOOST_CHECK_EQUAL(v2.z, 6.8f);
}

BOOST_AUTO_TEST_CASE(Vector3Assignment) 
{
    TM::Vector3 v1{};
    v1 = 3.0f;

    BOOST_CHECK_EQUAL(v1.x, 3.0f);
    BOOST_CHECK_EQUAL(v1.y, 3.0f);
    BOOST_CHECK_EQUAL(v1.z, 3.0f);
}

BOOST_AUTO_TEST_CASE(Vector3AddVector3) 
{
    TM::Vector3 v1 {1.0f, 1.0f, 2.0f};
    TM::Vector3 v2 {2.0f, 3.0f, 4.0f};

    TM::Vector3 sum = v1 + v2;

    BOOST_CHECK_EQUAL(sum.x, 3.0f);
    BOOST_CHECK_EQUAL(sum.y, 4.0f);
    BOOST_CHECK_EQUAL(sum.z, 6.0f);
}

BOOST_AUTO_TEST_CASE(Vector3AddEqVector3) 
{
    TM::Vector3 v1 {1.0f, 1.0f, 2.0f};
    TM::Vector3 v2 {1.0f, 1.0f, 3.0f};

    v1 += v2;

    BOOST_CHECK_EQUAL(v1.x, 2.0f);
    BOOST_CHECK_EQUAL(v1.y, 2.0f);
    BOOST_CHECK_EQUAL(v1.z, 5.0f);
}

BOOST_AUTO_TEST_CASE(Vector3SubtractVector3) 
{
    TM::Vector3 v1 {20.0f, 30.0f, 40.0f};
    TM::Vector3 v2 {5.0f, 5.0f, 5.0f};

    TM::Vector3 difference = v1 - v2;

    BOOST_CHECK_EQUAL(difference.x, 15.0f);
    BOOST_CHECK_EQUAL(difference.y, 25.0f);
    BOOST_CHECK_EQUAL(difference.z, 35.0f);
}

BOOST_AUTO_TEST_CASE(Vector3SubtractEqVector3) 
{
    TM::Vector3 v1 {2.0f, 3.0f, 4.0f};
    TM::Vector3 v2 {1.0f, 1.0f, 1.0f};

    v1 -= v2;

    BOOST_CHECK_EQUAL(v1.x, 1.0f);
    BOOST_CHECK_EQUAL(v1.y, 2.0f);
    BOOST_CHECK_EQUAL(v1.z, 3.0f);
}

BOOST_AUTO_TEST_CASE(Vector3MultiplyVector3Scalar) 
{
    TM::Vector3 v1 {2.0f, 3.0f, 4.0f};
    F32 v2 {5.0f};

    TM::Vector3 product = v1 * v2;

    BOOST_CHECK_EQUAL(product.x, 10.0f);
    BOOST_CHECK_EQUAL(product.y, 15.0f);
    BOOST_CHECK_EQUAL(product.z, 20.0f);
}

BOOST_AUTO_TEST_CASE(Vector3MultiplyEqVector3Scalar) 
{
    TM::Vector3 v1 {8.0f, 10.0f, 15.0f};
    F32 v2 {5.0f};

    v1 *= v2;

    BOOST_CHECK_EQUAL(v1.x, 40.0f);
    BOOST_CHECK_EQUAL(v1.y, 50.0f);
    BOOST_CHECK_EQUAL(v1.z, 75.0f);
}

BOOST_AUTO_TEST_CASE(Vector3MultiplyByVector3)
{
    TM::Vector3 A {2.0f, 5.0f, 10.0f};
    TM::Vector3 B {6.0f, 8.0f, 9.0f};

    TM::Vector3 C = A * B;


    BOOST_CHECK_EQUAL(C.x, 12.0f);
    BOOST_CHECK_EQUAL(C.y, 40.0f);
    BOOST_CHECK_EQUAL(C.z, 90.0f);
}

BOOST_AUTO_TEST_CASE(Vector3DotMultiplication) 
{
    TM::Vector3 A {4.0f, 6.0f, 9.0f};
    TM::Vector3 B {-3.0f, 7.0f, 3.0f};

    BOOST_CHECK_EQUAL(A.Dot(B), 57.0f);

//===== TODO:: Need to add 2d dot product test =====
}

BOOST_AUTO_TEST_CASE(Vector3DivideVector3ByScalar) 
{
    TM::Vector3 v1 {10.0f, 20.0f, 30.0f};

    TM::Vector3 quotient = v1 / 2.0f;

    BOOST_CHECK_EQUAL(quotient.x, 5.0f);
    BOOST_CHECK_EQUAL(quotient.y, 10.0f);
    BOOST_CHECK_EQUAL(quotient.z, 15.0f);
}

BOOST_AUTO_TEST_CASE(Vector3DivideEqVector3ByScalar) 
{
    TM::Vector3 v1 {10.0f, 20.0f, 40.0f};
    F32 v2 {2.0f};

    v1 /= v2;

    BOOST_CHECK_EQUAL(v1.x, 5);
    BOOST_CHECK_EQUAL(v1.y, 10);
    BOOST_CHECK_EQUAL(v1.z, 20.0f);
}

BOOST_AUTO_TEST_CASE(Vector3_Comparison_Operators)
{
    TM::Vector3 midValue {5.0f, 10.0f, 15.0f};
    TM::Vector3 highValue {40.0f, 50.0f, 60.0f};
    TM::Vector3 lowValue {1.0f, 2.0f, 3.0f};
    TM::Vector3 equalValue = midValue;
    
    BOOST_CHECK_EQUAL(midValue > lowValue, true);
    BOOST_CHECK_EQUAL(midValue < highValue, true);
    BOOST_CHECK_EQUAL(midValue >= equalValue, true);
    BOOST_CHECK_EQUAL(midValue <= equalValue, true);
    BOOST_CHECK_EQUAL(midValue == equalValue, true);
    BOOST_CHECK_EQUAL(midValue != highValue, true);

    BOOST_CHECK_EQUAL(midValue < lowValue, false);
    BOOST_CHECK_EQUAL(midValue > highValue, false);
    BOOST_CHECK_EQUAL(midValue <= lowValue, false);
    BOOST_CHECK_EQUAL(midValue >= highValue, false);
    BOOST_CHECK_EQUAL(midValue == lowValue, false);	
    BOOST_CHECK_EQUAL(midValue != equalValue, false);

    highValue.x = 1.0f;

    BOOST_CHECK_EQUAL(midValue >= highValue, false);
}

BOOST_AUTO_TEST_CASE(Vector3Magnitude) {
    TM::Vector3 Vector3Test {5.0f, -4.0f, 10.0f};
    F32 mag = Vector3Test.Magnitude();

    BOOST_CHECK_EQUAL(RoundFloat(mag), 11.87434f);

//===== TODO:: Add 2D test =====	
}

BOOST_AUTO_TEST_CASE(Vector3Normalize) 
{
    TM::Vector3 Vector3Test {12.0f, -5.0f, 25.0f};
    Vector3Test.Normalize();

    BOOST_CHECK_EQUAL(RoundFloat(Vector3Test.x), 0.42586f);
    BOOST_CHECK_EQUAL(RoundFloat(Vector3Test.y), -0.17744f);
    BOOST_CHECK_EQUAL(RoundFloat(Vector3Test.z), 0.88722f);

//===== TODO:: Add 2D test =====	
}

BOOST_AUTO_TEST_CASE(Vector3Resetvoid) 
{
    TM::Vector3 Vector3Test {12.0f, -5.0f, 20.0f};

    BOOST_CHECK_EQUAL(Vector3Test.x, 12.0f);
    BOOST_CHECK_EQUAL(Vector3Test.y, -5.0f);
    BOOST_CHECK_EQUAL(Vector3Test.z, 20.0f);

    Vector3Test.Reset();

    BOOST_CHECK_EQUAL(Vector3Test.x, 0.0f);
    BOOST_CHECK_EQUAL(Vector3Test.y, 0.0f);
    BOOST_CHECK_EQUAL(Vector3Test.z, 0.0f);
}

BOOST_AUTO_TEST_CASE(Vector3AddScaledVector3) 
{
    TM::Vector3 Vector3Test {15.0f, 25.0f, 45.0f};
    TM::Vector3 scaled {45.0f, 10.0f, 20.0f};

    Vector3Test.AddScaledVector(scaled, 10);

    BOOST_CHECK_EQUAL(Vector3Test.x, 465.0f);
    BOOST_CHECK_EQUAL(Vector3Test.y, 125.0f);
    BOOST_CHECK_EQUAL(Vector3Test.z, 245.0f);
}

BOOST_AUTO_TEST_CASE(Vector3CrossProduct) 
{
    TM::Vector3 v1 {1, 3, 4};
    TM::Vector3 v2 {2, -5, 8};

    TM::Vector3 cross = v1.CrossProduct(v2);

    BOOST_CHECK_EQUAL(cross.x, 44.0f);
    BOOST_CHECK_EQUAL(cross.y, 0.0f);
    BOOST_CHECK_EQUAL(cross.z, -11.0f);
}

BOOST_AUTO_TEST_CASE(Vector3SetFunctionTest)
{
    TM::Vector3 v {};

    v.Set(10.0f, 15.0f, 20.0f);

    BOOST_CHECK_EQUAL(v.x, 10.0f);
    BOOST_CHECK_EQUAL(v.y, 15.0f);
    BOOST_CHECK_EQUAL(v.z, 20.0f);
}

BOOST_AUTO_TEST_CASE(Vector3Negation)
{
    TM::Vector3 v{1.0f, 2.0f, 3.0f};

    v = -v;

    BOOST_CHECK_EQUAL(v.x, -1.0f);
    BOOST_CHECK_EQUAL(v.y, -2.0f);
    BOOST_CHECK_EQUAL(v.z, -3.0f);
}

BOOST_AUTO_TEST_CASE(Vector3Pre_PostIncrement)
{
    TM::Vector3 v {1.0f, 2.0f, 3.0f};

    ++v;

    BOOST_CHECK_EQUAL(v.x, 2.0f);
    BOOST_CHECK_EQUAL(v.y, 3.0f);
    BOOST_CHECK_EQUAL(v.z, 4.0f);

    v++;

    BOOST_CHECK_EQUAL(v.x, 3.0f);
    BOOST_CHECK_EQUAL(v.y, 4.0f);
    BOOST_CHECK_EQUAL(v.z, 5.0f);

}

BOOST_AUTO_TEST_CASE(Vector3Pre_PostDecrement)
{
    TM::Vector3 v {10.0f, 20.0f, 30.0f};

    --v;

    BOOST_CHECK_EQUAL(v.x, 9.0f);
    BOOST_CHECK_EQUAL(v.y, 19.0f);
    BOOST_CHECK_EQUAL(v.z, 29.0f);

    v--;

    BOOST_CHECK_EQUAL(v.x, 8.0f);
    BOOST_CHECK_EQUAL(v.y, 18.0f);
    BOOST_CHECK_EQUAL(v.z, 28.0f);
}
