// PhysicalBodiesTester.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../PhysicalBodies/Bodies.h"


const double SOLID_TEST_DENSITY = 8920;

const double SPHERE_TEST_RADIUS = 3.5;
const double SPHERE_TEST_VOLUME = ((4.0 / 3) * M_PI * pow(SPHERE_TEST_RADIUS, 3));
const double SPHERE_TEST_MASS = SOLID_TEST_DENSITY * SPHERE_TEST_VOLUME;

const double PARALLELEPIPED_TEST_WIDTH = 13;
const double PARALLELEPIPED_TEST_HEIGHT = 4;
const double PARALLELEPIPED_TEST_DEPTH = 0.5;

const double PARALLELEPIPED_TEST_VOLUME =
	PARALLELEPIPED_TEST_WIDTH * PARALLELEPIPED_TEST_HEIGHT * PARALLELEPIPED_TEST_DEPTH;

const double PARALLELEPIPED_TEST_MASS = SOLID_TEST_DENSITY * PARALLELEPIPED_TEST_VOLUME;


struct SphereFixture
{
	CSphere sphere;
	CSolid &sphereAsSolid;
	CBody &sphereAsBody;

	SphereFixture()
		:sphere(SOLID_TEST_DENSITY, SPHERE_TEST_RADIUS)
		,sphereAsSolid(sphere)
		,sphereAsBody(sphere)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Sphere, SphereFixture)

BOOST_AUTO_TEST_CASE(SphereHasDensityAndRadius)
{
	BOOST_CHECK_EQUAL(sphereAsBody.GetDensity(), SOLID_TEST_DENSITY);
	BOOST_CHECK_EQUAL(sphere.GetRadius(), SPHERE_TEST_RADIUS);
}

BOOST_AUTO_TEST_CASE(SphereHasVolume)
{
	BOOST_CHECK_EQUAL(sphereAsBody.GetVolume(), SPHERE_TEST_VOLUME);
}

BOOST_AUTO_TEST_CASE(SphereHasMass)
{
	BOOST_CHECK_EQUAL(sphereAsBody.GetMass(), SPHERE_TEST_MASS);
}

BOOST_AUTO_TEST_SUITE_END()


struct ParallelepipedFixture
{
	CParallelepiped parallelepiped;
	CSolid &parallelepipedAsSolid;
	CBody &parallelepipedAsBody;

	ParallelepipedFixture()
		:parallelepiped(SOLID_TEST_DENSITY, PARALLELEPIPED_TEST_WIDTH,
			PARALLELEPIPED_TEST_HEIGHT, PARALLELEPIPED_TEST_DEPTH)
		,parallelepipedAsSolid(parallelepiped)
		,parallelepipedAsBody(parallelepiped)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Parallelepiped, ParallelepipedFixture)

BOOST_AUTO_TEST_CASE(ParallelepipedHasDimensionsAndDensity)
{
	BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), PARALLELEPIPED_TEST_WIDTH);
	BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), PARALLELEPIPED_TEST_HEIGHT);
	BOOST_CHECK_EQUAL(parallelepiped.GetDepth(), PARALLELEPIPED_TEST_DEPTH);
	BOOST_CHECK_EQUAL(parallelepipedAsBody.GetDensity(), SOLID_TEST_DENSITY);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasVolume)
{
	BOOST_CHECK_EQUAL(parallelepipedAsBody.GetVolume(), PARALLELEPIPED_TEST_VOLUME);
}

BOOST_AUTO_TEST_CASE(ParallelepipedHasMass)
{
	BOOST_CHECK_EQUAL(parallelepipedAsBody.GetMass(), PARALLELEPIPED_TEST_MASS);
}

BOOST_AUTO_TEST_SUITE_END()
