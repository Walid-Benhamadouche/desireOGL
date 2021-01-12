#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
//layout(location = 1) in vec2 texCoored;

//out vec2 v_TexCoored;

uniform mat4 u_MVP;

void main()
{
	//position = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	gl_Position = u_MVP * position;
	//v_TexCoored = texCoored;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

//in vec2 v_TexCoored;

uniform vec4 u_Color;
//uniform sampler2D u_Texture;

void main()
{
	//vec4 texColor = texture(u_Texture, v_TexCoored);
	color = vec4(1.0f, 0.5f, 0.3f, 1.0f);
};