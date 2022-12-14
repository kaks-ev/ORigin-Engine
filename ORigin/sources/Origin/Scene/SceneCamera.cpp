// Copyright (c) 2022 Evangelion Manuhutu | ORigin Engine

#include "pch.h"
#include "SceneCamera.h"
#include <glm\gtc\matrix_transform.hpp>

namespace Origin
{
	SceneCamera::SceneCamera()
	{
		RecalculateProjection();
	}

	void SceneCamera::SetPerspective(float verticalFov, float nearClip, float farClip)
	{
		m_ProjectionType = ProjectionType::Perspective;
		m_PerspectiveFOV = verticalFov;
		m_PerspectiveNear = nearClip;
		m_PerspectiveFar = farClip;

		RecalculateProjection();
	}

	void SceneCamera::SetOrthographic(float size, float nearClip, float farClip)
	{
		m_ProjectionType = ProjectionType::Orthographic;
		m_OrthographicSize = size;
		m_OrthographicNear = nearClip;
		m_OrthographicFar = farClip;

		RecalculateProjection();
	}

	void SceneCamera::SetViewportSize(uint32_t width, uint32_t height)
	{
		m_AspectRatio = (float)width / (float)height;
		RecalculateProjection();
	}

	void SceneCamera::RecalculateProjection()
	{
		switch (m_ProjectionType)
		{
			case ProjectionType::Perspective:
			{
				m_Projection = glm::perspective(m_PerspectiveFOV, m_AspectRatio, m_PerspectiveNear, m_PerspectiveFar);
				break;
			}

			case ProjectionType::Orthographic:
			{
				float OrthoLeft = -m_OrthographicSize * m_AspectRatio * 0.5f;
				float OrthoRight = m_OrthographicSize * m_AspectRatio * 0.5f;
				float OrthoTop = -m_OrthographicSize * 0.5f;
				float OrthoBottom = m_OrthographicSize * 0.5f;

				m_Projection = glm::ortho(OrthoLeft, OrthoRight, OrthoTop, OrthoBottom,
					m_OrthographicNear, m_OrthographicFar);
				break;
			}

		}
	}
}
