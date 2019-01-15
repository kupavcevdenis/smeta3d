#include "GLContext.h"

#include "../extern/glew/include/GL/glew.h"
#include "../extern/glew/include/GL/wglew.h"
/*
#include "../extern/glew/include/GL/eglew.h"
#include "../extern/glew/include/GL/wglew.h"

#include <gl/GL.h>*/




namespace smeta3d
{	
	struct SAppContext
	{
		SAppContext()
		{
			hdc = NULL;
			context = NULL;
			wglChoosePixelFormatARB = NULL;
		}

		HDC hdc;
		HGLRC context;
		PFNWGLCHOOSEPIXELFORMATARBPROC wglChoosePixelFormatARB;
	};

	GLContext::GLContext(const HWND& HWnd)
	{
		m_pAppContext = new SAppContext();
		bool bOk = CreateContext(HWnd);
		if (!bOk)
			throw int(1);
	}
	GLContext::~GLContext()
	{
		delete m_pAppContext;
		m_pAppContext = NULL;
	}
	bool GLContext::CreateContext(const HWND& HWnd)
	{
		if (m_pAppContext->context != NULL)

			if (m_pAppContext->context != NULL)
			{
				wglMakeCurrent(m_pAppContext->hdc, NULL);
				wglDeleteContext(m_pAppContext->context);
				m_pAppContext->context = NULL;

			}

		// get new hdc
		if (m_pAppContext->hdc != NULL)
		{
			ReleaseDC(HWnd, m_pAppContext->hdc);
			m_pAppContext->hdc = NULL;
		}
		m_pAppContext->hdc = GetDC(HWnd);
		if (m_pAppContext->hdc == NULL)
		{

			return 0;
		}

		// pixel format descriptor
		PIXELFORMATDESCRIPTOR pfd =
		{
			sizeof(PIXELFORMATDESCRIPTOR), 1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_SWAP_EXCHANGE,
			PFD_TYPE_RGBA, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 24, 8, 0, PFD_MAIN_PLANE, 0, 0, 0, 0
		};

		// create simple opengl context
		if (m_pAppContext->wglChoosePixelFormatARB == NULL) {

			// choose pixel format
			int pixelformat = ChoosePixelFormat(m_pAppContext->hdc, &pfd);
			SetPixelFormat(m_pAppContext->hdc, pixelformat, &pfd);

			// create simple context
			HGLRC old_context = m_pAppContext->context;
			m_pAppContext->context = wglCreateContext(m_pAppContext->hdc);
			if (m_pAppContext->context == NULL) {

				ReleaseDC(HWnd, m_pAppContext->hdc);
				m_pAppContext->hdc = NULL;
				return 0;
			}

			// share context
			if (old_context && wglShareLists(old_context, m_pAppContext->context) == 0) {

				wglDeleteContext(m_pAppContext->context);
				ReleaseDC(HWnd, m_pAppContext->hdc);
				m_pAppContext->context = NULL;
				m_pAppContext->hdc = NULL;
				return 0;
			}

			// set current context
			if (wglMakeCurrent(m_pAppContext->hdc, m_pAppContext->context) == 0) {

				wglDeleteContext(m_pAppContext->context);
				ReleaseDC(HWnd, m_pAppContext->hdc);
				m_pAppContext->context = NULL;
				m_pAppContext->hdc = NULL;
				return 0;
			}

			// get proc address
			m_pAppContext->wglChoosePixelFormatARB = (PFNWGLCHOOSEPIXELFORMATARBPROC)wglGetProcAddress("wglChoosePixelFormatARB");
			if (m_pAppContext->wglChoosePixelFormatARB == NULL) {

				wglMakeCurrent(m_pAppContext->hdc, NULL);
				wglDeleteContext(m_pAppContext->context);
				ReleaseDC(HWnd, m_pAppContext->hdc);
				m_pAppContext->context = NULL;
				m_pAppContext->hdc = NULL;
				return 0;
			}

			// destroy context
			wglMakeCurrent(m_pAppContext->hdc, NULL);
			wglDeleteContext(m_pAppContext->context);
			m_pAppContext->context = NULL;
		}

		// attributes
		GLint attributes[] = {
			WGL_DRAW_TO_WINDOW_ARB, GL_TRUE,
			WGL_ACCELERATION_ARB, WGL_FULL_ACCELERATION_ARB,
			WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
			WGL_COLOR_BITS_ARB, 32,
			WGL_DEPTH_BITS_ARB, 24,
			WGL_STENCIL_BITS_ARB, 8,
			0,
		};

		// choose pixel format
		int pixelformat;
		unsigned int num_formats;
		m_pAppContext->wglChoosePixelFormatARB(m_pAppContext->hdc, attributes, NULL, 1, &pixelformat, &num_formats);
		if (num_formats == 0) pixelformat = ChoosePixelFormat(m_pAppContext->hdc, &pfd);

		// set pixel format
		SetPixelFormat(m_pAppContext->hdc, pixelformat, &pfd);

		HGLRC old_context = m_pAppContext->context;

		// create context
		m_pAppContext->context = wglCreateContext(m_pAppContext->hdc);
		if (m_pAppContext->context == NULL) {

			ReleaseDC(HWnd, m_pAppContext->hdc);
			m_pAppContext->hdc = NULL;
			return 0;
		}

		// share context
		if (old_context && wglShareLists(old_context, m_pAppContext->context) == 0) {

			wglDeleteContext(m_pAppContext->context);
			ReleaseDC(HWnd, m_pAppContext->hdc);
			m_pAppContext->context = NULL;
			m_pAppContext->hdc = NULL;
			return 0;
		}

		// set current context
		if (wglMakeCurrent(m_pAppContext->hdc, m_pAppContext->context) == 0) {

			wglDeleteContext(m_pAppContext->context);
			ReleaseDC(HWnd, m_pAppContext->hdc);
			m_pAppContext->context = NULL;
			m_pAppContext->hdc = NULL;
			return 0;
		}

		glewInit();


		return true;
		//Resize(0, 0);

	}
	void GLContext::Clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 1, 1);
	}
	void GLContext::Swap()
	{
		SwapBuffers(m_pAppContext->hdc);
	}
	void GLContext::Resize(int w, int h)
	{
		glViewport(0, 0, w, h);
	}
}
