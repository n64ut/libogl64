#ifndef __OGL64__
#define __OGL64__

#include "../include/nus64.h"

typedef enum glmodes {
	atomic_prim,	
	cycle_single,
	cycle_two,
	cycle_copy,
	cycle_fill,
	tex_persp,
	tex_detail,
	tex_sharpen,
	tex_lod,
	tlut,
	tlut_rgba16,
	tlut_ia,
	sample_point,
	sample_2x2,
	mid_texel,
	bi_lerp_0,
	bi_lerp_1,
	convert_one,
	chroma_key,
	dither_rgb_magic,
	dither_rgb_bayer_matrix,
	dither_rgb_noise,
	dither_rgb_none,
	dither_alpha_pattern,
	dither_alpha_inverse_pattern,
	dither_alpha_noise,
	dither_alpha_none,
	blend_1a_cycle0,
	blend_1a_cycle1,
	blend_1b_cycle0,
	blend_1b_cycle1,
	blend_2a_cycle0,
	blend_2a_cycle1,
	blend_2b_cycle0,
	blend_2b_cycle1,
	blend_force,
	alpha_cvg,
	cvg_times_alpha,
	zmode_opaque,
	zmode_interpenetrating,
	zmode_transparent,
	zmode_decal,
	cvg_destination_clamp,
	cvg_destination_wrap,
	cvg_destination_zap,
	cvg_destination_save,
	color_on_cvg,
	image_read,
	z_update,
	z_compare,
	antialias,
	z_source,
	dither_alpha,
	alpha_compare
} glmode_t;

typedef enum glcompile_mode {
	GL_IMMEDIATE = 0x0,
	GL_COMPILE = 0x1,
	GL_COMPILE_AND_EXECUTE = -2147483647, // aka 0x80000001
} glcompile_mode_t;

typedef enum glprimative {
	GL_POINTS, 
	GL_LINES, 
	GL_LINE_STRIP, 
	GL_LINE_LOOP, 
	GL_TRIANGLES, 
	GL_TRIANGLE_STRIP, 
	GL_TRIANGLE_FAN, 
	GL_QUADS, 
	GL_QUAD_STRIP, 
	GL_POLYGON
} glprimative_t;

typedef enum glerror {
	GL_NO_ERROR = 0,
	GL_INVALID_ENUM,
	GL_INVALID_VALUE,
	GL_INVALID_OPERATION,
	GL_STACK_OVERFLOW,
	GL_STACK_UNDERFLOW,
	GL_OUT_OF_MEMORY
} glerror_t;

typedef enum glboolValues {
	GL_ALPHA_TEST	,
	GL_AUTO_NORMAL	,
	GL_BLEND	,
	GL_CLIP_PLANEi	,
	GL_COLOR_ARRAY	,
	GL_COLOR_LOGIC_OP	,
	GL_COLOR_MATERIAL	,
	GL_CULL_FACE	,
	GL_DEPTH_TEST	,
	GL_DITHER	,
	GL_EDGE_FLAG_ARRAY	,
	GL_FOG	,
	GL_INDEX_ARRAY	,
	GL_INDEX_LOGIC_OP	,
	GL_LIGHTi	,
	GL_LIGHTING	,
	GL_LINE_SMOOTH	,
	GL_LINE_STIPPLE	,
	GL_MAP1_COLOR_4	,
	GL_MAP2_TEXTURE_COORD_2	,
	GL_MAP2_TEXTURE_COORD_3	,
	GL_MAP2_TEXTURE_COORD_4	,
	GL_MAP2_VERTEX_3	,
	GL_MAP2_VERTEX_4	,
	GL_NORMAL_ARRAY	,
	GL_NORMALIZE	,
	GL_OCCLUSION_TEST_HP	,
	GL_POINT_SMOOTH	,
	GL_POLYGON_SMOOTH	,
	GL_POLYGON_OFFSET_FILL	,
	GL_POLYGON_OFFSET_LINE	,
	GL_POLYGON_OFFSET_POINT	,
	GL_POLYGON_STIPPLE	,
	GL_RESCALE_NORMAL_EXT	,
	GL_SCISSOR_TEST	,
	GL_STENCIL_TEST	,
	GL_TEXTURE_1D	,
	GL_TEXTURE_2D	,
	GL_TEXTURE_3D_EXT,
	GL_TEXTURE_COORD_ARRAY	,
	GL_TEXTURE_GEN_Q	,
	GL_TEXTURE_GEN_R	,
	GL_TEXTURE_GEN_S	,
	GL_TEXTURE_GEN_T	,
	GL_VERTEX_ARRAY,
} glboolValues_t;

typedef enum glshademodel {
	GL_FLAT,
	GL_SMOOTH
} glshademodel_t;

typedef enum glclear {
	GL_COLOR_BUFFER_BIT = 1,
	GL_DEPTH_BUFFER_BIT = 2,
	GL_ACCUM_BUFFER_BIT = 4,
	GL_STENCIL_BUFFER_BIT = 8
} glclear_t;

typedef enum gldepth {
	GL_NEVER = 0,
	GL_LESS,
	GL_EQUAL,
	GL_LEQUAL,
	GL_GREATER,
	GL_NOTEQUAL,
	GL_GEQUAL,
	GL_ALWAYS,
} gldepth_t;

typedef enum hinttarget {
	GL_FOG_HINT,
	GL_LINE_SMOOTH_HINT, 
	GL_PERSPECTIVE_CORRECTION_HINT, 
	GL_POINT_SMOOTH_HINT, 
	GL_POLYGON_SMOOTH_HINT,
	HINT_TARGET_LEN
} hinttarget_t;

typedef enum hintmode {
	GL_DONT_CARE = 0,
	GL_FASTEST, 
	GL_NICEST,
} hintmode_t;

void glArrayElement(GLint i);
void glBegin(glprimative_t type);
void glBindTexture(GLenum target, GLuint texture);
void glCallList(GLuint list);
void glClear(glclear_t mask);
void glClearAccum(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glClearColor(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glClearDepth(GLushort depth);
void glClearStencil(GLubyte s);
void glClose(void);
// void glColorMaterial(GLint mode,GLint type);
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glCullFace(GLenum mode);
// void glDebug(int mode);
void glDeleteTextures(GLsizei n, const GLuint *textures);
void glDepthFunc(gldepth_t func);
void glDisable(glmode_t code);
void glDisableClientState(GLenum array);
void glEdgeFlag(GLboolean flag);
void glEnable(glmode_t code);
void glEnableClientState(GLenum array);
void glEnd(void);
void glEndList(void);
glerror_t glGetError(void);
GLubyte *gluErrorString(glerror_t error);
void glFlush(void);
void glFrontFace(GLenum mode);
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near,GLdouble far);
GLuint glGenLists(GLsizei range);
void glGenTextures(GLsizei n, GLuint *textures);
void glGetBooleanv(glboolValues_t pname, GLboolean *params);
void glGetDoublev(GLenum pname, GLdouble *params);
void glGetFloatv(GLenum pname, GLfloat *params);
void glGetIntegerv(GLenum pname, GLint *params);
void glHint(hinttarget_t target, hintmode_t mode);
void glInit(void *zbuffer, void * pscratch_area, int32_t pscratch_length);
void glInitNames(void);
GLboolean glIsEnabled(glboolValues_t cap);
GLboolean glIsList(GLuint list);
void glLightf(GLenum light, GLenum type, GLfloat v);
void glLightfv(GLenum light, GLenum type, const GLfloat *v);
void glLightModelfv(GLenum pname, GLfloat *param);
void glLightModeli(GLenum pname, GLint param);
void glLoadIdentity(void);
void glLoadMatrixf(const GLfloat *m);
void glLoadName(GLuint name);
void glMaterialf(GLenum mode, GLenum type, GLfloat v);
void glMaterialfv(GLenum mode, GLenum type, const GLfloat *v);
void glMatrixMode(GLenum mode);
void glMultMatrixf(const GLfloat *m);
void glNewList(GLuint list, glcompile_mode_t mode);
void glNormal3f(GLfloat x, GLfloat y, GLfloat z);
void glNormal3fv(const GLfloat *v);
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
void glPixelStorei(GLenum pname, GLint param);
void glPolygonMode(GLenum face, GLenum mode);
void glPolygonOffset(GLfloat factor, GLfloat units);
void glPopMatrix(void);
void glPopName(void);
void glPushMatrix(void);
void glPushName(GLuint name);
GLint glRenderMode(GLenum mode);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glScalef(GLfloat x, GLfloat y, GLfloat z);
void glSelectBuffer(GLsizei size, GLuint *buf);
void glShadeModel(glshademodel_t mode);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glTexEnvi(GLenum target,GLenum pname,GLint param);
void glTexImage2D(GLenum target, GLint level, GLint components, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glTexParameteri(GLenum target, GLenum pname, GLint param);
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);

void glVertex2s(GLshort x, GLshort y);
void glVertex3s(GLshort x, GLshort y, GLshort z);
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w);

void glVertex2i(GLint x, GLint y);
void glVertex3i(GLint x, GLint y, GLint z);
void glVertex4i(GLint x, GLint y, GLint z, GLint w);

void glVertex2f(GLfloat x, GLfloat y);
void glVertex3f(GLfloat x, GLfloat y, GLfloat z);
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
void glVertex3fv(const GLfloat *v);

void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

/* not implemented, just added to compile  */
  /*
inline void glPointSize(GLfloat) {}
inline void glLineWidth(GLfloat) {}
inline void glDeleteLists(int, int) {}
inline void glDepthFunc(int) {}
inline void glBlendFunc(int, int) {}
inline void glTexEnvf(int, int, int) {}
inline void glOrtho(GLfloat,GLfloat,GLfloat,GLfloat,GLfloat,GLfloat){}
inline void glVertex2i(int,int) {}
inline void glDepthMask(int) {}
inline void glFogi(int, int) {}
inline void glFogfv(int, const GLfloat*) {}
inline void glFogf(int, GLfloat) {}
inline void glRasterPos2f(GLfloat, GLfloat) {}
inline void glPolygonStipple(void*) {}
inline void glTexParameterf(int, int, int) {};
  */
#endif //__OGL64__