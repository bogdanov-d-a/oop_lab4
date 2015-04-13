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

const double CONE_TEST_BASE_RADIUS = 4.6;
const double CONE_TEST_HEIGHT = 13;
const double CONE_TEST_VOLUME = ((1.0 / 3) * (M_PI * pow(CONE_TEST_BASE_RADIUS, 2)) * CONE_TEST_HEIGHT);
const double CONE_TEST_MASS = SOLID_TEST_DENSITY * CONE_TEST_VOLUME;

const double CYLINDER_TEST_BASE_RADIUS = 3.8;
const double CYLINDER_TEST_HEIGHT = 7;
const double CYLINDER_TEST_VOLUME = (M_PI * pow(CYLINDER_TEST_BASE_RADIUS, 2) * CYLINDER_TEST_HEIGHT);
const double CYLINDER_TEST_MASS = SOLID_TEST_DENSITY * CYLINDER_TEST_VOLUME;


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


struct ConeFixture
{
	CCone cone;
	CSolid &coneAsSolid;
	CBody &coneAsBody;

	ConeFixture()
		:cone(SOLID_TEST_DENSITY, CONE_TEST_BASE_RADIUS, CONE_TEST_HEIGHT)
		,coneAsSolid(cone)
		,coneAsBody(cone)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Cone, ConeFixture)

BOOST_AUTO_TEST_CASE(ConeHasDensityBaseRadiusAndHeight)
{
	BOOST_CHECK_EQUAL(cone.GetBaseRadius(), CONE_TEST_BASE_RADIUS);
	BOOST_CHECK_EQUAL(cone.GetHeight(), CONE_TEST_HEIGHT);
	BOOST_CHECK_EQUAL(coneAsBody.GetDensity(), SOLID_TEST_DENSITY);
}

BOOST_AUTO_TEST_CASE(ConeHasVolume)
{
	BOOST_CHECK_EQUAL(coneAsBody.GetVolume(), CONE_TEST_VOLUME);
}

BOOST_AUTO_TEST_CASE(ConeHasMass)
{
	BOOST_CHECK_EQUAL(coneAsBody.GetMass(), CONE_TEST_MASS);
}

BOOST_AUTO_TEST_SUITE_END()


struct CylinderFixture
{
	CCylinder cylinder;
	CSolid &cylinderAsSolid;
	CBody &cylinderAsBody;

	CylinderFixture()
		:cylinder(SOLID_TEST_DENSITY, CYLINDER_TEST_BASE_RADIUS, CYLINDER_TEST_HEIGHT)
		,cylinderAsSolid(cylinder)
		,cylinderAsBody(cylinder)
	{}
};

BOOST_FIXTURE_TEST_SUITE(Cylinder, CylinderFixture)

BOOST_AUTO_TEST_CASE(CylinderHasDensityBaseRadiusAndHeight)
{
	BOOST_CHECK_EQUAL(cylinder.GetBaseRadius(), CYLINDER_TEST_BASE_RADIUS);
	BOOST_CHECK_EQUAL(cylinder.GetHeight(), CYLINDER_TEST_HEIGHT);
	BOOST_CHECK_EQUAL(cylinderAsBody.GetDensity(), SOLID_TEST_DENSITY);
}

BOOST_AUTO_TEST_CASE(CylinderHasVolume)
{
	BOOST_CHECK_EQUAL(cylinderAsBody.GetVolume(), CYLINDER_TEST_VOLUME);
}

BOOST_AUTO_TEST_CASE(CylinderHasMass)
{
	BOOST_CHECK_EQUAL(cylinderAsBody.GetMass(), CYLINDER_TEST_MASS);
}

BOOST_AUTO_TEST_SUITE_END()
