#pragma once

#include<string>
#include<unordered_map>
#include<glm/glm.hpp>

struct ShaderProgramSource
{
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader
{
private:
	std::unordered_map<std::string, int> m_UniformLocationCache;
public:
	unsigned int m_RendererID;
	Shader(const std::string& filepath);
	~Shader();
	unsigned int getShaderPrograme();
private:
	ShaderProgramSource ParseShader(const std::string& filepath);
	unsigned int CreateShader(const std::string& vertexShader, const std::string fragmentShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
	int GetUniformLocation(const std::string& name);
};