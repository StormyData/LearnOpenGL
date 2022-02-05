#pragma once

class Object
{
	unsigned int VAO, EBO, VBO;
public:
	Object(float* vertex_tab,int vertex_num, unsigned int* index_tab,int index_num);
	void use();
	~Object();
};