#pragma once

#include <core/RenderingContext.hpp>

using namespace Open3D::Render;

void clearColor(RenderingContext context, float RGBA_colors[4])
{
	context._gpuContext->ClearRenderTargetView(context._renderView, RGBA_colors);
}