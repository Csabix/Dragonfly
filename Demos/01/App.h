#pragma once

// GLEW
#include <GL/glew.h>

// SDL
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>


//Dragonfly Runtime
#include <Dragonfly/editor.h>
#include <Dragonfly/detail/buffer.h>
#include <Dragonfly/detail/vao.h>

class App {

public:

	App() = default;

	bool Init(int width, int height);
	void Resize(int width, int height);

	void Update();
	void Render();

	void KeyboardDown(SDL_KeyboardEvent&);
	void KeyboardUp(SDL_KeyboardEvent&);
	void MouseMove(SDL_MouseMotionEvent&);
	void MouseDown(SDL_MouseButtonEvent&);
	void MouseUp(SDL_MouseButtonEvent&);
	void MouseWheel(SDL_MouseWheelEvent&);

private:

	int canvas_width=720;
	int canvas_height=480;
	float col_intensity = 0.15f;

	df::ProgramEditor<df::UniformEditor, df::ShaderEditor<df::SFile>,	   df::ShaderEditor<df::SFile>		> program  = "Side-Prog";
	df::ProgramEditor<df::UniformEditor, df::ShaderEditor<df::FileEditor>, df::ShaderEditor<df::FileEditor>	> program2 = "Main-Prog";
		

	eltecg::ogl::ArrayBuffer MyVBO;
	eltecg::ogl::VertexArray MyVAO;

	df::Camera cam;
	df::Camera cam2 = df::Camera("CameraWithName");

	void InitShaders();

	void InitGL();

	df::Texture2D<> testTex = df::Texture2D<>("Assets/scales.jpg");
	df::Texture2D<> testTex2;
	df::Texture2D<> testTex3;

	df::TextureCube<> testCubemap = df::TextureCube<>("Assets/xpos.png", "Assets/xneg.png", "Assets/ypos.png", "Assets/yneg.png", "Assets/zpos.png", "Assets/zneg.png");
	df::TextureCube<> testCubemap2;

	df::Texture2D<> testAlias;

	df::Texture3D<float> testField;
};