#pragma once
#include "../Math/Ray.h"
#include "../Math/Color.h"

class Material
{
public:
	virtual bool Scatter(const Ray& ray, const RaycastHit& hit, color3& attenuation, Ray& scattered) const = 0;
};