#ifndef GLContex_H_
#define GLContex_H_

#include <windows.h>
#include "Shader.h"

   class GLContext
   {
   public:
      GLContext(const HWND& HWnd);
      ~GLContext();
	  void Clear();
	  void Swap();
	  void Resize(int w, int h);
	  void InitShader();

   private:
	   bool CreateContext(const HWND& HWnd);
   private:
	   struct SAppContext* m_pAppContext;
	   Shader* m_pShader;


   };

#endif /* GLContex_H_ */
