#include "GLExt.h"

/******************************************************************************\
*
* Extensions
*
\******************************************************************************/

// OpenGL 1.2
PFNGLBLENDCOLORPROC glBlendColor = NULL;
PFNGLBLENDEQUATIONPROC glBlendEquation = NULL;
PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements = NULL;
PFNGLTEXIMAGE3DPROC glTexImage3D = NULL;
PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D = NULL;
PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D = NULL;

// OpenGL 1.3
PFNGLACTIVETEXTUREPROC glActiveTexture = NULL;
PFNGLSAMPLECOVERAGEPROC glSampleCoverage = NULL;
PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D = NULL;
PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D = NULL;
PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D = NULL;
PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D = NULL;
PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage = NULL;

// OpenGL 1.4
PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate = NULL;
PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays = NULL;
PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements = NULL;
PFNGLPOINTPARAMETERFPROC glPointParameterf = NULL;
PFNGLPOINTPARAMETERFVPROC glPointParameterfv = NULL;
PFNGLPOINTPARAMETERIPROC glPointParameteri = NULL;
PFNGLPOINTPARAMETERIVPROC glPointParameteriv = NULL;

// OpenGL 1.5
PFNGLGENQUERIESPROC glGenQueries = NULL;
PFNGLDELETEQUERIESPROC glDeleteQueries = NULL;
PFNGLISQUERYPROC glIsQuery = NULL;
PFNGLBEGINQUERYPROC glBeginQuery = NULL;
PFNGLENDQUERYPROC glEndQuery = NULL;
PFNGLGETQUERYIVPROC glGetQueryiv = NULL;
PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv = NULL;
PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv = NULL;
PFNGLBINDBUFFERPROC glBindBuffer = NULL;
PFNGLDELETEBUFFERSPROC glDeleteBuffers = NULL;
PFNGLGENBUFFERSPROC glGenBuffers = NULL;
PFNGLISBUFFERPROC glIsBuffer = NULL;
PFNGLBUFFERDATAPROC glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC glBufferSubData = NULL;
PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData = NULL;
PFNGLMAPBUFFERPROC glMapBuffer = NULL;
PFNGLUNMAPBUFFERPROC glUnmapBuffer = NULL;
PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv = NULL;
PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv = NULL;

// OpenGL 2.0
PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate = NULL;
PFNGLDRAWBUFFERSPROC glDrawBuffers = NULL;
PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate = NULL;
PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate = NULL;
PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate = NULL;
PFNGLATTACHSHADERPROC glAttachShader = NULL;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation = NULL;
PFNGLCOMPILESHADERPROC glCompileShader = NULL;
PFNGLCREATEPROGRAMPROC glCreateProgram = NULL;
PFNGLCREATESHADERPROC glCreateShader = NULL;
PFNGLDELETEPROGRAMPROC glDeleteProgram = NULL;
PFNGLDELETESHADERPROC glDeleteShader = NULL;
PFNGLDETACHSHADERPROC glDetachShader = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray = NULL;
PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib = NULL;
PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform = NULL;
PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders = NULL;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation = NULL;
PFNGLGETPROGRAMIVPROC glGetProgramiv = NULL;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
PFNGLGETSHADERIVPROC glGetShaderiv = NULL;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog = NULL;
PFNGLGETSHADERSOURCEPROC glGetShaderSource = NULL;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation = NULL;
PFNGLGETUNIFORMFVPROC glGetUniformfv = NULL;
PFNGLGETUNIFORMIVPROC glGetUniformiv = NULL;
PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv = NULL;
PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv = NULL;
PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv = NULL;
PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv = NULL;
PFNGLISPROGRAMPROC glIsProgram = NULL;
PFNGLISSHADERPROC glIsShader = NULL;
PFNGLLINKPROGRAMPROC glLinkProgram = NULL;
PFNGLSHADERSOURCEPROC glShaderSource = NULL;
PFNGLUSEPROGRAMPROC glUseProgram = NULL;
PFNGLUNIFORM1FPROC glUniform1f = NULL;
PFNGLUNIFORM2FPROC glUniform2f = NULL;
PFNGLUNIFORM3FPROC glUniform3f = NULL;
PFNGLUNIFORM4FPROC glUniform4f = NULL;
PFNGLUNIFORM1IPROC glUniform1i = NULL;
PFNGLUNIFORM2IPROC glUniform2i = NULL;
PFNGLUNIFORM3IPROC glUniform3i = NULL;
PFNGLUNIFORM4IPROC glUniform4i = NULL;
PFNGLUNIFORM1FVPROC glUniform1fv = NULL;
PFNGLUNIFORM2FVPROC glUniform2fv = NULL;
PFNGLUNIFORM3FVPROC glUniform3fv = NULL;
PFNGLUNIFORM4FVPROC glUniform4fv = NULL;
PFNGLUNIFORM1IVPROC glUniform1iv = NULL;
PFNGLUNIFORM2IVPROC glUniform2iv = NULL;
PFNGLUNIFORM3IVPROC glUniform3iv = NULL;
PFNGLUNIFORM4IVPROC glUniform4iv = NULL;
PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv = NULL;
PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv = NULL;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv = NULL;
PFNGLVALIDATEPROGRAMPROC glValidateProgram = NULL;
PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d = NULL;
PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv = NULL;
PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f = NULL;
PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv = NULL;
PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s = NULL;
PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv = NULL;
PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d = NULL;
PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv = NULL;
PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f = NULL;
PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv = NULL;
PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s = NULL;
PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv = NULL;
PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d = NULL;
PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv = NULL;
PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f = NULL;
PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv = NULL;
PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s = NULL;
PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv = NULL;
PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv = NULL;
PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv = NULL;
PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv = NULL;
PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub = NULL;
PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv = NULL;
PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv = NULL;
PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv = NULL;
PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv = NULL;
PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d = NULL;
PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv = NULL;
PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f = NULL;
PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv = NULL;
PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv = NULL;
PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s = NULL;
PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv = NULL;
PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv = NULL;
PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv = NULL;
PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv = NULL;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer = NULL;

// OpenGL 2.1
PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv = NULL;
PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv = NULL;
PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv = NULL;
PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv = NULL;
PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv = NULL;
PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv = NULL;

// OpenGL 3.0
PFNGLCOLORMASKIPROC glColorMaski = NULL;
PFNGLGETBOOLEANI_VPROC glGetBooleani_v = NULL;
PFNGLGETINTEGERI_VPROC glGetIntegeri_v = NULL;
PFNGLENABLEIPROC glEnablei = NULL;
PFNGLDISABLEIPROC glDisablei = NULL;
PFNGLISENABLEDIPROC glIsEnabledi = NULL;
PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback = NULL;
PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback = NULL;
PFNGLBINDBUFFERRANGEPROC glBindBufferRange = NULL;
PFNGLBINDBUFFERBASEPROC glBindBufferBase = NULL;
PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings = NULL;
PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying = NULL;
PFNGLCLAMPCOLORPROC glClampColor = NULL;
PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender = NULL;
PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender = NULL;
PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer = NULL;
PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv = NULL;
PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv = NULL;
PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i = NULL;
PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i = NULL;
PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i = NULL;
PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i = NULL;
PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui = NULL;
PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui = NULL;
PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui = NULL;
PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui = NULL;
PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv = NULL;
PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv = NULL;
PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv = NULL;
PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv = NULL;
PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv = NULL;
PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv = NULL;
PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv = NULL;
PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv = NULL;
PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv = NULL;
PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv = NULL;
PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv = NULL;
PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv = NULL;
PFNGLGETUNIFORMUIVPROC glGetUniformuiv = NULL;
PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation = NULL;
PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation = NULL;
PFNGLUNIFORM1UIPROC glUniform1ui = NULL;
PFNGLUNIFORM2UIPROC glUniform2ui = NULL;
PFNGLUNIFORM3UIPROC glUniform3ui = NULL;
PFNGLUNIFORM4UIPROC glUniform4ui = NULL;
PFNGLUNIFORM1UIVPROC glUniform1uiv = NULL;
PFNGLUNIFORM2UIVPROC glUniform2uiv = NULL;
PFNGLUNIFORM3UIVPROC glUniform3uiv = NULL;
PFNGLUNIFORM4UIVPROC glUniform4uiv = NULL;
PFNGLTEXPARAMETERIIVPROC glTexParameterIiv = NULL;
PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv = NULL;
PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv = NULL;
PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv = NULL;
PFNGLCLEARBUFFERIVPROC glClearBufferiv = NULL;
PFNGLCLEARBUFFERUIVPROC glClearBufferuiv = NULL;
PFNGLCLEARBUFFERFVPROC glClearBufferfv = NULL;
PFNGLCLEARBUFFERFIPROC glClearBufferfi = NULL;
PFNGLGETSTRINGIPROC glGetStringi = NULL;

// OpenGL 3.1
PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced = NULL;
PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced = NULL;
PFNGLTEXBUFFERPROC glTexBuffer = NULL;
PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex = NULL;

// OpenGL 3.2
PFNGLGETINTEGER64I_VPROC glGetInteger64i_v = NULL;
PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v = NULL;
PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture = NULL;

// OpenGL 3.3
PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor = NULL;

// OpenGL 4.0
PFNGLMINSAMPLESHADINGPROC glMinSampleShading = NULL;
PFNGLBLENDEQUATIONIPROC glBlendEquationi = NULL;
PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei = NULL;
PFNGLBLENDFUNCIPROC glBlendFunci = NULL;
PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei = NULL;

// ARB framebuffer object
PFNGLISRENDERBUFFERPROC glIsRenderbuffer = NULL;
PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer = NULL;
PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers = NULL;
PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers = NULL;
PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv = NULL;
PFNGLISFRAMEBUFFERPROC glIsFramebuffer = NULL;
PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer = NULL;
PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers = NULL;
PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus = NULL;
PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D = NULL;
PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D = NULL;
PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D = NULL;
PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv = NULL;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap = NULL;
PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample = NULL;
PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer = NULL;

// ARB map buffer range
PFNGLMAPBUFFERRANGEPROC glMapBufferRange = NULL;
PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange = NULL;

// ARB vertex array object
PFNGLBINDVERTEXARRAYPROC glBindVertexArray = NULL;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays = NULL;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays = NULL;
PFNGLISVERTEXARRAYPROC glIsVertexArray = NULL;

// ARB uniform buffer object
PFNGLGETUNIFORMINDICESPROC glGetUniformIndices = NULL;
PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv = NULL;
PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName = NULL;
PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex = NULL;
PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv = NULL;
PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName = NULL;
PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding = NULL;

// ARB copy buffer
PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData = NULL;

// ARB blend func extended
PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed = NULL;

// ARB draw elements base vertex
PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex = NULL;
PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex = NULL;
PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex = NULL;
PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex = NULL;

// ARB texture multisample
PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample = NULL;
PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample = NULL;
PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv = NULL;
PFNGLSAMPLEMASKIPROC glSampleMaski = NULL;

// ARB tessellation shader
PFNGLPATCHPARAMETERIPROC glPatchParameteri = NULL;
PFNGLPATCHPARAMETERFVPROC glPatchParameterfv = NULL;

// ARB debug output
PFNGLDEBUGMESSAGECONTROLARBPROC glDebugMessageControlARB = NULL;
PFNGLDEBUGMESSAGEINSERTARBPROC glDebugMessageInsertARB = NULL;
PFNGLDEBUGMESSAGECALLBACKARBPROC glDebugMessageCallbackARB = NULL;
PFNGLGETDEBUGMESSAGELOGARBPROC glGetDebugMessageLogARB = NULL;

// ARB compute shader
PFNGLDISPATCHCOMPUTEPROC glDispatchCompute = NULL;
PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect = NULL;

/******************************************************************************\
*
* GLExt
*
\******************************************************************************/

/*
 */
#define GL_EXT_NUM_TEXTURES	32

/*
 */
static const char *gl_vendor = NULL;
static const char *gl_renderer = NULL;
static const char *gl_version = NULL;
static const char *gl_shading_language = NULL;
static char *gl_extensions = NULL;
//static GLFfp *gl_ffp = NULL;

/*
 */
static int gl_multisample = 0;
static int gl_viewport[4] = { 0, };
static GLuint gl_program_id = 0;
static GLuint gl_texture_target[GL_EXT_NUM_TEXTURES] = { 0, };
static GLuint gl_texture_id[GL_EXT_NUM_TEXTURES] = { 0, };
static int gl_texture_unit = 0;

/*
 */
#ifndef USE_GL_WRAPPER
	#ifdef _MACOS
		static const char *gl_name = "/System/Library/Frameworks/OpenGL.framework/OpenGL";
		static void *gl_handle = NULL;
		static void *glGetProcAddress(const char *name) {
			if(gl_handle == NULL) gl_handle = dlopen(gl_name,RTLD_LAZY);
			if(gl_name != NULL) return dlsym(gl_handle,name);
			return NULL;
		}
	#endif
#endif

/*
 */
GLExt::GLExt() {
	
}

/*
 */
int GLExt::init() {
	
//	assert(gl_ffp == NULL && "GLExt::init(): is already initialized");
	
	// load functions
	#ifdef _WIN32
		#define GET_PROC_ADDRESS(NAME) { \
			*((unsigned char**)&NAME) = (unsigned char*)wglGetProcAddress(#NAME); \
			if(NAME == NULL) *((unsigned char**)&NAME) = (unsigned char*)wglGetProcAddress(#NAME "ARB"); \
			if(NAME == NULL) *((unsigned char**)&NAME) = (unsigned char*)wglGetProcAddress(#NAME "EXT"); \
		}
	#elif _LINUX
		#define GET_PROC_ADDRESS(NAME) { \
			*((unsigned char**)&NAME) = (unsigned char*)glXGetProcAddressARB((const GLubyte*)#NAME); \
			if(NAME == NULL) *((unsigned char**)&NAME) = (unsigned char*)glXGetProcAddressARB((const GLubyte*)#NAME "ARB"); \
			if(NAME == NULL) *((unsigned char**)&NAME) = (unsigned char*)glXGetProcAddressARB((const GLubyte*)#NAME "EXT"); \
		}
	#elif _MACOS
		#define GET_PROC_ADDRESS(NAME) { \
			*((unsigned char**)&NAME) = (unsigned char*)glGetProcAddress(#NAME); \
			if(NAME == NULL) *((unsigned char**)&NAME) = (unsigned char*)glGetProcAddress(#NAME "ARB"); \
			if(NAME == NULL) *((unsigned char**)&NAME) = (unsigned char*)glGetProcAddress(#NAME "EXT"); \
		}
	#endif
	
	// OpenGL 1.2
	GET_PROC_ADDRESS(glBlendColor)
	GET_PROC_ADDRESS(glBlendEquation)
	GET_PROC_ADDRESS(glDrawRangeElements)
	GET_PROC_ADDRESS(glTexImage3D)
	GET_PROC_ADDRESS(glTexSubImage3D)
	GET_PROC_ADDRESS(glCopyTexSubImage3D)
	
	// OpenGL 1.3
	GET_PROC_ADDRESS(glActiveTexture)
	GET_PROC_ADDRESS(glSampleCoverage)
	GET_PROC_ADDRESS(glCompressedTexImage3D)
	GET_PROC_ADDRESS(glCompressedTexImage2D)
	GET_PROC_ADDRESS(glCompressedTexImage1D)
	GET_PROC_ADDRESS(glCompressedTexSubImage3D)
	GET_PROC_ADDRESS(glCompressedTexSubImage2D)
	GET_PROC_ADDRESS(glCompressedTexSubImage1D)
	GET_PROC_ADDRESS(glGetCompressedTexImage)
	
	// OpenGL 1.4
	GET_PROC_ADDRESS(glBlendFuncSeparate)
	GET_PROC_ADDRESS(glMultiDrawArrays)
	GET_PROC_ADDRESS(glMultiDrawElements)
	GET_PROC_ADDRESS(glPointParameterf)
	GET_PROC_ADDRESS(glPointParameterfv)
	GET_PROC_ADDRESS(glPointParameteri)
	GET_PROC_ADDRESS(glPointParameteriv)
	
	// OpenGL 1.5
	GET_PROC_ADDRESS(glGenQueries)
	GET_PROC_ADDRESS(glDeleteQueries)
	GET_PROC_ADDRESS(glIsQuery)
	GET_PROC_ADDRESS(glBeginQuery)
	GET_PROC_ADDRESS(glEndQuery)
	GET_PROC_ADDRESS(glGetQueryiv)
	GET_PROC_ADDRESS(glGetQueryObjectiv)
	GET_PROC_ADDRESS(glGetQueryObjectuiv)
	GET_PROC_ADDRESS(glBindBuffer)
	GET_PROC_ADDRESS(glDeleteBuffers)
	GET_PROC_ADDRESS(glGenBuffers)
	GET_PROC_ADDRESS(glIsBuffer)
	GET_PROC_ADDRESS(glBufferData)
	GET_PROC_ADDRESS(glBufferSubData)
	GET_PROC_ADDRESS(glGetBufferSubData)
	GET_PROC_ADDRESS(glMapBuffer)
	GET_PROC_ADDRESS(glUnmapBuffer)
	GET_PROC_ADDRESS(glGetBufferParameteriv)
	GET_PROC_ADDRESS(glGetBufferPointerv)
	
	// OpenGL 2.0
	GET_PROC_ADDRESS(glBlendEquationSeparate)
	GET_PROC_ADDRESS(glDrawBuffers)
	GET_PROC_ADDRESS(glStencilOpSeparate)
	GET_PROC_ADDRESS(glStencilFuncSeparate)
	GET_PROC_ADDRESS(glStencilMaskSeparate)
	GET_PROC_ADDRESS(glAttachShader)
	GET_PROC_ADDRESS(glBindAttribLocation)
	GET_PROC_ADDRESS(glCompileShader)
	GET_PROC_ADDRESS(glCreateProgram)
	GET_PROC_ADDRESS(glCreateShader)
	GET_PROC_ADDRESS(glDeleteProgram)
	GET_PROC_ADDRESS(glDeleteShader)
	GET_PROC_ADDRESS(glDetachShader)
	GET_PROC_ADDRESS(glDisableVertexAttribArray)
	GET_PROC_ADDRESS(glEnableVertexAttribArray)
	GET_PROC_ADDRESS(glGetActiveAttrib)
	GET_PROC_ADDRESS(glGetActiveUniform)
	GET_PROC_ADDRESS(glGetAttachedShaders)
	GET_PROC_ADDRESS(glGetAttribLocation)
	GET_PROC_ADDRESS(glGetProgramiv)
	GET_PROC_ADDRESS(glGetProgramInfoLog)
	GET_PROC_ADDRESS(glGetShaderiv)
	GET_PROC_ADDRESS(glGetShaderInfoLog)
	GET_PROC_ADDRESS(glGetShaderSource)
	GET_PROC_ADDRESS(glGetUniformLocation)
	GET_PROC_ADDRESS(glGetUniformfv)
	GET_PROC_ADDRESS(glGetUniformiv)
	GET_PROC_ADDRESS(glGetVertexAttribdv)
	GET_PROC_ADDRESS(glGetVertexAttribfv)
	GET_PROC_ADDRESS(glGetVertexAttribiv)
	GET_PROC_ADDRESS(glGetVertexAttribPointerv)
	GET_PROC_ADDRESS(glIsProgram)
	GET_PROC_ADDRESS(glIsShader)
	GET_PROC_ADDRESS(glLinkProgram)
	GET_PROC_ADDRESS(glShaderSource)
	GET_PROC_ADDRESS(glUseProgram)
	GET_PROC_ADDRESS(glUniform1f)
	GET_PROC_ADDRESS(glUniform2f)
	GET_PROC_ADDRESS(glUniform3f)
	GET_PROC_ADDRESS(glUniform4f)
	GET_PROC_ADDRESS(glUniform1i)
	GET_PROC_ADDRESS(glUniform2i)
	GET_PROC_ADDRESS(glUniform3i)
	GET_PROC_ADDRESS(glUniform4i)
	GET_PROC_ADDRESS(glUniform1fv)
	GET_PROC_ADDRESS(glUniform2fv)
	GET_PROC_ADDRESS(glUniform3fv)
	GET_PROC_ADDRESS(glUniform4fv)
	GET_PROC_ADDRESS(glUniform1iv)
	GET_PROC_ADDRESS(glUniform2iv)
	GET_PROC_ADDRESS(glUniform3iv)
	GET_PROC_ADDRESS(glUniform4iv)
	GET_PROC_ADDRESS(glUniformMatrix2fv)
	GET_PROC_ADDRESS(glUniformMatrix3fv)
	GET_PROC_ADDRESS(glUniformMatrix4fv)
	GET_PROC_ADDRESS(glValidateProgram)
	GET_PROC_ADDRESS(glVertexAttrib1d)
	GET_PROC_ADDRESS(glVertexAttrib1dv)
	GET_PROC_ADDRESS(glVertexAttrib1f)
	GET_PROC_ADDRESS(glVertexAttrib1fv)
	GET_PROC_ADDRESS(glVertexAttrib1s)
	GET_PROC_ADDRESS(glVertexAttrib1sv)
	GET_PROC_ADDRESS(glVertexAttrib2d)
	GET_PROC_ADDRESS(glVertexAttrib2dv)
	GET_PROC_ADDRESS(glVertexAttrib2f)
	GET_PROC_ADDRESS(glVertexAttrib2fv)
	GET_PROC_ADDRESS(glVertexAttrib2s)
	GET_PROC_ADDRESS(glVertexAttrib2sv)
	GET_PROC_ADDRESS(glVertexAttrib3d)
	GET_PROC_ADDRESS(glVertexAttrib3dv)
	GET_PROC_ADDRESS(glVertexAttrib3f)
	GET_PROC_ADDRESS(glVertexAttrib3fv)
	GET_PROC_ADDRESS(glVertexAttrib3s)
	GET_PROC_ADDRESS(glVertexAttrib3sv)
	GET_PROC_ADDRESS(glVertexAttrib4Nbv)
	GET_PROC_ADDRESS(glVertexAttrib4Niv)
	GET_PROC_ADDRESS(glVertexAttrib4Nsv)
	GET_PROC_ADDRESS(glVertexAttrib4Nub)
	GET_PROC_ADDRESS(glVertexAttrib4Nubv)
	GET_PROC_ADDRESS(glVertexAttrib4Nuiv)
	GET_PROC_ADDRESS(glVertexAttrib4Nusv)
	GET_PROC_ADDRESS(glVertexAttrib4bv)
	GET_PROC_ADDRESS(glVertexAttrib4d)
	GET_PROC_ADDRESS(glVertexAttrib4dv)
	GET_PROC_ADDRESS(glVertexAttrib4f)
	GET_PROC_ADDRESS(glVertexAttrib4fv)
	GET_PROC_ADDRESS(glVertexAttrib4iv)
	GET_PROC_ADDRESS(glVertexAttrib4s)
	GET_PROC_ADDRESS(glVertexAttrib4sv)
	GET_PROC_ADDRESS(glVertexAttrib4ubv)
	GET_PROC_ADDRESS(glVertexAttrib4uiv)
	GET_PROC_ADDRESS(glVertexAttrib4usv)
	GET_PROC_ADDRESS(glVertexAttribPointer)
	
	// OpenGL 2.1
	GET_PROC_ADDRESS(glUniformMatrix2x3fv)
	GET_PROC_ADDRESS(glUniformMatrix3x2fv)
	GET_PROC_ADDRESS(glUniformMatrix2x4fv)
	GET_PROC_ADDRESS(glUniformMatrix4x2fv)
	GET_PROC_ADDRESS(glUniformMatrix3x4fv)
	GET_PROC_ADDRESS(glUniformMatrix4x3fv)
	
	// OpenGL 3.0
	GET_PROC_ADDRESS(glColorMaski)
	GET_PROC_ADDRESS(glGetBooleani_v)
	GET_PROC_ADDRESS(glGetIntegeri_v)
	GET_PROC_ADDRESS(glEnablei)
	GET_PROC_ADDRESS(glDisablei)
	GET_PROC_ADDRESS(glIsEnabledi)
	GET_PROC_ADDRESS(glBeginTransformFeedback)
	GET_PROC_ADDRESS(glEndTransformFeedback)
	GET_PROC_ADDRESS(glBindBufferRange)
	GET_PROC_ADDRESS(glBindBufferBase)
	GET_PROC_ADDRESS(glTransformFeedbackVaryings)
	GET_PROC_ADDRESS(glGetTransformFeedbackVarying)
	GET_PROC_ADDRESS(glClampColor)
	GET_PROC_ADDRESS(glBeginConditionalRender)
	GET_PROC_ADDRESS(glEndConditionalRender)
	GET_PROC_ADDRESS(glVertexAttribIPointer)
	GET_PROC_ADDRESS(glGetVertexAttribIiv)
	GET_PROC_ADDRESS(glGetVertexAttribIuiv)
	GET_PROC_ADDRESS(glVertexAttribI1i)
	GET_PROC_ADDRESS(glVertexAttribI2i)
	GET_PROC_ADDRESS(glVertexAttribI3i)
	GET_PROC_ADDRESS(glVertexAttribI4i)
	GET_PROC_ADDRESS(glVertexAttribI1ui)
	GET_PROC_ADDRESS(glVertexAttribI2ui)
	GET_PROC_ADDRESS(glVertexAttribI3ui)
	GET_PROC_ADDRESS(glVertexAttribI4ui)
	GET_PROC_ADDRESS(glVertexAttribI1iv)
	GET_PROC_ADDRESS(glVertexAttribI2iv)
	GET_PROC_ADDRESS(glVertexAttribI3iv)
	GET_PROC_ADDRESS(glVertexAttribI4iv)
	GET_PROC_ADDRESS(glVertexAttribI1uiv)
	GET_PROC_ADDRESS(glVertexAttribI2uiv)
	GET_PROC_ADDRESS(glVertexAttribI3uiv)
	GET_PROC_ADDRESS(glVertexAttribI4uiv)
	GET_PROC_ADDRESS(glVertexAttribI4bv)
	GET_PROC_ADDRESS(glVertexAttribI4sv)
	GET_PROC_ADDRESS(glVertexAttribI4ubv)
	GET_PROC_ADDRESS(glVertexAttribI4usv)
	GET_PROC_ADDRESS(glGetUniformuiv)
	GET_PROC_ADDRESS(glBindFragDataLocation)
	GET_PROC_ADDRESS(glGetFragDataLocation)
	GET_PROC_ADDRESS(glUniform1ui)
	GET_PROC_ADDRESS(glUniform2ui)
	GET_PROC_ADDRESS(glUniform3ui)
	GET_PROC_ADDRESS(glUniform4ui)
	GET_PROC_ADDRESS(glUniform1uiv)
	GET_PROC_ADDRESS(glUniform2uiv)
	GET_PROC_ADDRESS(glUniform3uiv)
	GET_PROC_ADDRESS(glUniform4uiv)
	GET_PROC_ADDRESS(glTexParameterIiv)
	GET_PROC_ADDRESS(glTexParameterIuiv)
	GET_PROC_ADDRESS(glGetTexParameterIiv)
	GET_PROC_ADDRESS(glGetTexParameterIuiv)
	GET_PROC_ADDRESS(glClearBufferiv)
	GET_PROC_ADDRESS(glClearBufferuiv)
	GET_PROC_ADDRESS(glClearBufferfv)
	GET_PROC_ADDRESS(glClearBufferfi)
	GET_PROC_ADDRESS(glGetStringi)
	
	// OpenGL 3.1
	GET_PROC_ADDRESS(glDrawArraysInstanced)
	GET_PROC_ADDRESS(glDrawElementsInstanced)
	GET_PROC_ADDRESS(glTexBuffer)
	GET_PROC_ADDRESS(glPrimitiveRestartIndex)
	
	// OpenGL 3.2
	GET_PROC_ADDRESS(glGetInteger64i_v)
	GET_PROC_ADDRESS(glGetBufferParameteri64v)
	GET_PROC_ADDRESS(glFramebufferTexture)
	
	// OpenGL 3.3
	GET_PROC_ADDRESS(glVertexAttribDivisor)
	
	// OpenGL 4.0
	GET_PROC_ADDRESS(glMinSampleShading)
	GET_PROC_ADDRESS(glBlendEquationi)
	GET_PROC_ADDRESS(glBlendEquationSeparatei)
	GET_PROC_ADDRESS(glBlendFunci)
	GET_PROC_ADDRESS(glBlendFuncSeparatei)
	
	// ARB framebuffer object
	GET_PROC_ADDRESS(glIsRenderbuffer)
	GET_PROC_ADDRESS(glBindRenderbuffer)
	GET_PROC_ADDRESS(glDeleteRenderbuffers)
	GET_PROC_ADDRESS(glGenRenderbuffers)
	GET_PROC_ADDRESS(glRenderbufferStorage)
	GET_PROC_ADDRESS(glGetRenderbufferParameteriv)
	GET_PROC_ADDRESS(glIsFramebuffer)
	GET_PROC_ADDRESS(glBindFramebuffer)
	GET_PROC_ADDRESS(glDeleteFramebuffers)
	GET_PROC_ADDRESS(glGenFramebuffers)
	GET_PROC_ADDRESS(glCheckFramebufferStatus)
	GET_PROC_ADDRESS(glFramebufferTexture1D)
	GET_PROC_ADDRESS(glFramebufferTexture2D)
	GET_PROC_ADDRESS(glFramebufferTexture3D)
	GET_PROC_ADDRESS(glFramebufferRenderbuffer)
	GET_PROC_ADDRESS(glGetFramebufferAttachmentParameteriv)
	GET_PROC_ADDRESS(glGenerateMipmap)
	GET_PROC_ADDRESS(glBlitFramebuffer)
	GET_PROC_ADDRESS(glRenderbufferStorageMultisample)
	GET_PROC_ADDRESS(glFramebufferTextureLayer)
	
	// ARB map buffer range
	GET_PROC_ADDRESS(glMapBufferRange)
	GET_PROC_ADDRESS(glFlushMappedBufferRange)
	
	// ARB vertex array object
	GET_PROC_ADDRESS(glBindVertexArray)
	GET_PROC_ADDRESS(glDeleteVertexArrays)
	GET_PROC_ADDRESS(glGenVertexArrays)
	GET_PROC_ADDRESS(glIsVertexArray)
	
	// ARB uniform buffer object
	GET_PROC_ADDRESS(glGetUniformIndices)
	GET_PROC_ADDRESS(glGetActiveUniformsiv)
	GET_PROC_ADDRESS(glGetActiveUniformName)
	GET_PROC_ADDRESS(glGetUniformBlockIndex)
	GET_PROC_ADDRESS(glGetActiveUniformBlockiv)
	GET_PROC_ADDRESS(glGetActiveUniformBlockName)
	GET_PROC_ADDRESS(glUniformBlockBinding)
	
	// ARB copy buffer
	GET_PROC_ADDRESS(glCopyBufferSubData)
	
	// ARB blend func extended
	GET_PROC_ADDRESS(glBindFragDataLocationIndexed)
	
	// ARB draw elements base vertex
	GET_PROC_ADDRESS(glDrawElementsBaseVertex)
	GET_PROC_ADDRESS(glDrawRangeElementsBaseVertex)
	GET_PROC_ADDRESS(glDrawElementsInstancedBaseVertex)
	GET_PROC_ADDRESS(glMultiDrawElementsBaseVertex)
	
	// ARB texture multisample
	GET_PROC_ADDRESS(glTexImage2DMultisample)
	GET_PROC_ADDRESS(glTexImage3DMultisample)
	GET_PROC_ADDRESS(glGetMultisamplefv)
	GET_PROC_ADDRESS(glSampleMaski)
	
	// ARB tessellation shader
	GET_PROC_ADDRESS(glPatchParameteri)
	GET_PROC_ADDRESS(glPatchParameterfv)
	
	// ARB debug output
	GET_PROC_ADDRESS(glDebugMessageControlARB)
	GET_PROC_ADDRESS(glDebugMessageInsertARB)
	GET_PROC_ADDRESS(glDebugMessageCallbackARB)
	GET_PROC_ADDRESS(glGetDebugMessageLogARB)
	
	// ARB compute shader
	GET_PROC_ADDRESS(glDispatchCompute)
	GET_PROC_ADDRESS(glDispatchComputeIndirect)
	
	#undef GET_PROC_ADDRESS
	
	// version
	gl_vendor = (const char*)glGetString(GL_VENDOR);
	gl_renderer = (const char*)glGetString(GL_RENDERER);
	gl_version = (const char*)glGetString(GL_VERSION);
	gl_shading_language = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);
	
	// extensions
	int size = 0;
	int capacity = 128;
	int num_extensions = 0;
	gl_extensions = new char[capacity];
	glGetIntegerv(GL_NUM_EXTENSIONS,&num_extensions);
	for(int i = 0; i < num_extensions; i++) {
		const char *extension = (const char*)glGetStringi(GL_EXTENSIONS,i);
		int length = (int)strlen(extension);
		if(size + length + 2 > capacity) {
			capacity = capacity * 2 + 1;
			char *extensions = new char[capacity];
			memcpy(extensions,gl_extensions,sizeof(char) * size + 1);
			delete [] gl_extensions;
			gl_extensions = extensions;
		}
		memcpy(gl_extensions + size,extension,length);
		gl_extensions[size++ + length] = ' ';
		gl_extensions[size + length] = '\0';
		size += length;
	}
	
	// current state
	gl_multisample = 0;
	gl_viewport[0] = 0;
	gl_viewport[1] = 0;
	gl_viewport[2] = 0;
	gl_viewport[3] = 0;
	gl_program_id = 0;
	clearTextures();
	
    //gl_ffp = new GLFfp();
	
	// set default options
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_DEPTH_TEST);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);
	
	return 1;
}

int GLExt::shutdown() {
	
    //delete gl_ffp;
    //gl_ffp = NULL;
	
	gl_vendor = NULL;
	gl_renderer = NULL;
	gl_version = NULL;
	gl_shading_language = NULL;
	
	delete [] gl_extensions;
	gl_extensions = NULL;
	
	gl_multisample = 0;
	gl_viewport[0] = 0;
	gl_viewport[1] = 0;
	gl_viewport[2] = 0;
	gl_viewport[3] = 0;
	gl_program_id = 0;
	clearTextures();
	
	return 1;
}

/*
 */
int GLExt::isInitialized() {
    return (/*gl_ffp != */NULL);
}

/*
 */
const char *GLExt::getVendor() {
	return gl_vendor;
}

const char *GLExt::getRenderer() {
	return gl_renderer;
}

const char *GLExt::getVersion() {
	return gl_version;
}

const char *GLExt::getShadingLanguage() {
	return gl_shading_language;
}

/*
 */
const char *GLExt::getExtensions() {
	return gl_extensions;
}

int GLExt::checkExtension(const char *extension) {
	if(gl_extensions == NULL) return 0;
	return (strstr(gl_extensions,extension) != NULL);
}

/*
 */
void GLExt::setMultisample(int multisample) {
	gl_multisample = multisample;
	if(gl_multisample) glEnable(GL_MULTISAMPLE);
	else glDisable(GL_MULTISAMPLE);
}

int GLExt::getMultisample() {
	return gl_multisample;
}

/*
 */
void GLExt::setViewport(int x,int y,int width,int height) {
	gl_viewport[0] = x;
	gl_viewport[1] = y;
	gl_viewport[2] = width;
	gl_viewport[3] = height;
	glViewport(x,y,width,height);
}

void GLExt::getViewport(int *viewport) {
	viewport[0] = gl_viewport[0];
	viewport[1] = gl_viewport[1];
	viewport[2] = gl_viewport[2];
	viewport[3] = gl_viewport[3];
}

/*
 */
void GLExt::setProgramID(GLuint program_id) {
	if(gl_program_id != program_id) {
		gl_program_id = program_id;
		glUseProgram(program_id);
	}
}

GLuint GLExt::getProgramID() {
	return gl_program_id;
}

/*
 */
void GLExt::clearTextures() {
	gl_texture_unit = 0;
	glActiveTexture(GL_TEXTURE0);
	for(int i = 0; i < GL_EXT_NUM_TEXTURES; i++) {
		gl_texture_target[i] = GL_TEXTURE_2D;
		gl_texture_id[i] = 0;
	}
}

void GLExt::deleteTexture(GLuint target,GLuint texture_id) {
	if(glIsTexture(texture_id)) glDeleteTextures(1,&texture_id);
	for(int i = 0; i < GL_EXT_NUM_TEXTURES; i++) {
		if(gl_texture_id[i] == texture_id) {
			gl_texture_target[i] = GL_TEXTURE_2D;
			gl_texture_id[i] = 0;
			break;
		}
	}
}

void GLExt::setTexture(int unit,GLuint target,GLuint texture_id) {
    //assert((unsigned int)unit < GL_EXT_NUM_TEXTURES && "GLExt::setTexture(): bad texture unit");
	if(gl_texture_id[unit] != texture_id) {
		gl_texture_target[unit] = target;
		gl_texture_id[unit] = texture_id;
		if(gl_texture_unit != unit) {
			gl_texture_unit = unit;
			glActiveTexture(GL_TEXTURE0 + unit);
		}
		glBindTexture(target,texture_id);
	}
}

void GLExt::setTextureUnit(int unit,GLuint target,GLuint texture_id) {
    //assert((unsigned int)unit < GL_EXT_NUM_TEXTURES && "GLExt::setTextureUnit(): bad texture unit");
	if(gl_texture_unit != unit) {
		gl_texture_unit = unit;
		glActiveTexture(GL_TEXTURE0 + unit);
	}
	if(gl_texture_id[unit] != texture_id) {
		gl_texture_target[unit] = target;
		gl_texture_id[unit] = texture_id;
		glBindTexture(target,texture_id);
	}
}

GLuint GLExt::getTextureTarget(int unit) {
//	assert((unsigned int)unit < GL_EXT_NUM_TEXTURES && "GLExt::getTextureTarget(): bad texture unit");
	return gl_texture_target[unit];
}

GLuint GLExt::getTextureID(int unit) {
//	assert((unsigned int)unit < GL_EXT_NUM_TEXTURES && "GLExt::getTextureID(): bad texture unit");
	return gl_texture_id[unit];
}

/*
 */
int GLExt::error(GLenum result) {
	
	if(result == GL_NO_ERROR) return 0;
	
    if(result == GL_INVALID_ENUM)return 0;
    else if(result == GL_INVALID_VALUE) return 0;
    else if(result == GL_INVALID_OPERATION) return 0;
    else if(result == GL_INVALID_FRAMEBUFFER_OPERATION) return 0;
    else if(result == GL_STACK_OVERFLOW)return 0;
    else if(result == GL_STACK_UNDERFLOW)return 0;
    else if(result == GL_OUT_OF_MEMORY) return 0;
    else return 0;
	
	return 1;
}

int GLExt::error() {
	int ret = 0;
	while(error(glGetError())) ret = 1;
	return ret;
}
