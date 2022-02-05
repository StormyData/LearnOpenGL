#pragma once



class Shader
{
private:
public:
	unsigned int ID;
	void use();
	Shader(const char * vertex_source, const char * fragment_source);
	~Shader();
};