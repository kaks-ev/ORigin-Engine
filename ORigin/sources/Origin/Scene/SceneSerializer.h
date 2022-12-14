// Copyright (c) 2022 Evangelion Manuhutu | ORigin Engine

#pragma once
#include "Scene.h"
#include <filesystem>

namespace Origin
{
	class SceneSerializer
	{
	public:
		SceneSerializer(const std::shared_ptr<Scene>& scene);

		void Serialize(const std::string& filepath);
		void Serialize(const std::filesystem::path& filepath);
		void SerializeRuntime(const std::string& filepath);

		bool Deserialize(const std::string& filepath);
		bool DeserializeRuntime(const std::string& filepath);


	private:
		std::shared_ptr<Scene> m_Scene;
	};
}


