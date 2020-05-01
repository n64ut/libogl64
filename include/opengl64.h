#ifndef __opengl64__
#define __opengl64__
#include "../include/nus64.h"

// https://github.com/dcnieho/FreeGLUT/blob/git_master/freeglut/freeglut/src/fg_teapot.c
// https://github.com/dcnieho/FreeGLUT/blob/git_master/freeglut/freeglut/src/fg_teapot_data.h
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef int GLsizei;
typedef unsigned int GLuint;
typedef int GLint;
typedef unsigned char GLubyte;
typedef unsigned int GLbitfield;
typedef void GLvoid;
typedef signed char GLbyte;
typedef short GLshort;
typedef unsigned short GLushort;
#define TINYGL 1
#ifdef !TINYGL
#endif

#ifdef FLOATING
typedef float GLfloat;
typedef float GLclampf;
typedef float GLclampd;
typedef double GLdouble;
#endif

/*
typedef int GLintptrARB;
typedef int GLsizeiptrARB;
typedef int GLfixed;
typedef int GLclampx;
*/
#ifdef TINYGL
#ifdef FLOATING
void glAccum(GLenum	op, GLfloat	value);
#else
#endif
#endif
#ifdef FLOATING
void glAlphaFunc(GLenum	func, GLclampf ref);
#else
#endif
GLboolean glAreTexturesResident(GLsizei n, const GLuint *textures, GLboolean *residences);
void glArrayElement(GLint i);

void glBegin(GLenum	mode);
void glBindTexture(GLenum target, GLuint texture);
#ifdef FLOATING
void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat	yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
#else
#endif
#ifdef FLOATING
void glBlendColorEXT( GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#else
#endif
void glBlendFunc(GLenum sfactor, GLenum	dfactor);
GLint gluBuild1DMipmaps( GLenum	target, GLint component, GLsizei width, GLenum format, GLenum type, const void	*data);
GLint gluBuild2DMipmaps( GLenum	target, GLint component, GLsizei width, GLenum format, GLenum type, const void	*data);

void glCallList(GLuint list);
void glCallLists(GLsizei n, GLenum type, const GLvoid *lists);
void glClear(GLbitfield mask);
#ifdef FLOATING
void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat	alpha);
#else
#endif
#ifdef FLOATING
void glClearColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha);
#else
#endif
#ifdef FLOATING
void glClearDepth(GLclampd depth);
#else
#endif
#ifdef FLOATING
void glClearIndex(GLfloat c);
#else
#endif
void glClearStencil(GLint s);
#ifdef FLOATING
void glClipPlane(GLenum plane, const GLdouble *equation);
#else
#endif

void glColor3b(GLbyte red, GLbyte green, GLbyte blue);
#ifdef FLOATING
void glColor3d(GLdouble	 red, GLdouble	 green,    GLdouble	 blue);
#else
#endif
#ifdef FLOATING
void glColor3f(GLfloat red, GLfloat green, GLfloat blue);
#else
#endif
void glColor3i(GLint red, GLint green, GLint blue);
void glColor3s(GLshort red, GLshort green, GLshort blue);
void glColor3ub(GLubyte red, GLubyte green, GLubyte blue);
void glColor3ui(GLuint red, GLuint green, GLuint blue);
void glColor3us(GLushort red, GLushort green, GLushort blue);
void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
#ifdef FLOATING
void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
#else
#endif
#ifdef FLOATING
void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#else
#endif
void glColor4i(GLint red, GLint green, GLint blue, GLint alpha);
void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha);
void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha);
void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha);
void glColor3bv(const GLbyte *v);
#ifdef FLOATING
void glColor3dv(const GLdouble *v);
#else
#endif
#ifdef FLOATING
void glColor3fv(const GLfloat *v);
#else
#endif
void glColor3iv(const GLint *v);
void glColor3sv(const GLshort *v);
void glColor3ubv(const GLubyte *v);
void glColor3uiv(const GLuint *v);
void glColor3usv(const GLushort *v);
void glColor4bv(const GLbyte *v);
#ifdef FLOATING
void glColor4dv(const GLdouble *v);
#else
#endif
#ifdef FLOATING
void glColor4fv(const GLfloat *v);
#else
#endif
void glColor4iv(const GLint *v);
void glColor4sv(const GLshort *v);
void glColor4ubv(const GLubyte *v);
void glColor4uiv(const GLuint *v);
void glColor4usv(const GLushort *v);
void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
void glColorPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
void glCopyTexImage1D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLint border);
void glCopyTexImage2D(GLenum target, GLint level, GLenum internalFormat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width, GLsizei height);
void glCullFace(GLenum mode);

void glDeleteLists(GLuint list, GLsizei range);
void glDeleteTextures(GLsizei n, const GLuint *textures);
void glDepthFunc(GLenum func);
void glDepthMask(GLboolean flag);
#ifdef FLOATING
void glDepthRange(GLclampd zNear, GLclampd zFar);
#else
#endif
void glDisable(GLenum cap);
void glDisableClientState(GLenum cap);
void glDrawArrays(GLenum mode, GLint first, GLsizei count);
void glDrawBuffer(GLenum mode);
void glDrawElements(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);

void glEdgeFlag(GLboolean flag);
void glEdgeFlagv(const GLboolean *flag);
void glEdgeFlagPointer(GLsizei stride, const GLvoid *pointer);
#ifdef TINYGL
void glEnable(GLenum cap);
#endif
void glEnableClientState(GLenum cap);
void glEndList(void);
#ifdef FLOATING
void glEvalCoord1d(GLdouble u);
#else
#endif
#ifdef FLOATING
void glEvalCoord1f(GLfloat u);
#else
#endif
#ifdef FLOATING
void glEvalCoord2d(GLdouble u, GLdouble v);
#else
#endif
#ifdef FLOATING
void glEvalCoord2f(GLfloat u, GLfloat v);
#else
#endif
#ifdef FLOATING
void glEvalCoord1dv(const GLdouble *u);
#else
#endif
#ifdef FLOATING
void glEvalCoord1fv(const GLfloat *u);
#else
#endif
#ifdef FLOATING
void glEvalCoord2dv(const GLdouble *u);
#else
#endif
#ifdef FLOATING
void glEvalCoord2fv(const GLfloat *u);
#else
#endif
void glEvalMesh1(GLenum mode, GLint i1, GLint i2);
void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
void glEvalPoint1(GLint i);
void glEvalPoint2(GLint i, GLint j);

#ifdef FLOATING
void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat *buffer);
#else
#endif
void glFinish(void);
void glFlush(void);
#ifdef FLOATING
void glFogf(GLenum pname, GLfloat param);
#else
#endif
void glFogi(GLenum pname, GLint param);
#ifdef FLOATING
void glFogfv(GLenum pname, const GLfloat *params);
#else
#endif
void glFogiv(GLenum pname, const GLint *params);
void glFrontFace(GLenum mode);
#ifdef FLOATING
void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#else
#endif

GLuint glGenLists(GLsizei range);
void glGenTextures(GLsizei n, GLuint *textures);
void glGetBooleanv(GLenum pname, GLboolean *params);
#ifdef FLOATING
void glGetDoublev(GLenum pname, GLdouble *params);
#else
#endif
#ifdef FLOATING
void glGetFloatv(GLenum pname, GLfloat *params);
#else
#endif
void glGetIntegerv(GLenum pname, GLint *params);
#ifdef FLOATING
void glGetClipPlane(GLenum plane, GLdouble *equation);
#else
#endif
GLenum glGetError(void);
#ifdef FLOATING
void glGetLightfv(GLenum light, GLenum pname, GLfloat *params);
#else
#endif
void glGetLightiv(GLenum light, GLenum pname, GLint *params);
#ifdef FLOATING
void glGetMapdv(GLenum target, GLenum query, GLdouble *v);
#else
#endif
#ifdef FLOATING
void glGetMapfv(GLenum target, GLenum query, GLfloat *v);
#else
#endif
void glGetMapiv(GLenum target, GLenum query, GLint *v);
#ifdef FLOATING
void glGetMaterialfv(GLenum face, GLenum pname, GLfloat *params);
#else
#endif
void glGetMaterialiv(GLenum face, GLenum pname, GLint *params);
#ifdef FLOATING
void glGetPixelMapfv(GLenum map, GLfloat *values);
#else
#endif
void glGetPixelMapuiv(GLenum map, GLuint *values);
void glGetPixelMapusv(GLenum map, GLushort *values);
void glGetPointerv(GLenum pname, GLvoid* *params);
void glGetPolygonStipple(GLubyte *mask);
const GLubyte *glGetString(GLenum name);
#ifdef FLOATING
void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat *params);
#else
#endif
void glGetTexEnviv(GLenum target, GLenum pname, GLint *params);
#ifdef FLOATING
void glGetTexGendv(GLenum coord, GLenum pname, GLdouble *params);
#else
#endif
#ifdef FLOATING
void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat *params);
#else
#endif
void glGetTexGeniv(GLenum coord, GLenum pname, GLint *params);
void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, GLvoid *pixels);
#ifdef FLOATING
void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat *params);
#else
#endif
void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint *params);
#ifdef FLOATING
void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat *params);
#else
#endif
void glGetTexParameteriv(GLenum target, GLenum pname, GLint *params);

void glHint(GLenum target, GLenum mode);
#ifdef FLOATING
void glIndexd(GLdouble c);
#else
#endif
#ifdef FLOATING
void glIndexf(GLfloat c);
#else
#endif
void glIndexi(GLint c);
void glIndexs(GLshort c);
void glIndexub(GLubyte c);
#ifdef FLOATING
void glIndexdv(const GLdouble *c);
#else
#endif
#ifdef FLOATING
void glIndexfv(const GLfloat *c);
#else
#endif
void glIndexiv(const GLint *c);
void glIndexsv(const GLshort *c);
void glIndexubv(const GLubyte *c);
void glIndexMask(GLuint mask);
void glIndexPointer(GLenum type, GLsizei stride, const GLvoid *pointer);
void glInitNames(void);
void glInterleavedArrays(GLenum format, GLsizei stride, const GLvoid *pointer);
GLboolean glIsEnabled(GLenum cap);
GLboolean glIsList(GLuint list);
GLboolean glIsTexture(GLuint texture);
#ifdef FLOATING
void glLightf(GLenum light, GLenum pname, GLfloat param);
#else
#endif
void glLighti(GLenum light, GLenum pname, GLint param);
#ifdef FLOATING
void glLightfv(GLenum light, GLenum pname, const GLfloat *params);
#else
#endif
void glLightiv(GLenum light, GLenum pname, const GLint *params);
#ifdef FLOATING
void glLightModelf(GLenum pname, GLfloat param);
#else
#endif
void glLightModeli(GLenum pname, GLint param);
#ifdef FLOATING
void glLightModelfv(GLenum pname, const GLfloat *params);
#else
#endif
void glLightModeliv(GLenum pname, const GLint *params);
void glLineStipple(GLint factor, GLushort pattern);
#ifdef FLOATING
void glLineWidth(GLfloat width);
#else
#endif
void glListBase(GLuint base);
void glLoadIdentity(void);
#ifdef FLOATING
void glLoadMatrixd(const GLdouble *m);
#else
#endif
#ifdef FLOATING
void glLoadMatrixf(const GLfloat  *m);
#else
#endif
void glLoadName(GLuint name);
void glLogicOp(GLenum opcode);
#ifdef FLOATING
void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
#else
#endif
#ifdef FLOATING
void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat  *points);
#else
#endif
#ifdef FLOATING
void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
#else
#endif
#ifdef FLOATING
void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat  *points);
#else
#endif
#ifdef FLOATING
void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2);
#else
#endif
#ifdef FLOATING
void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2);
#else
#endif
#ifdef FLOATING
void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
#else
#endif
#ifdef FLOATING
void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
#else
#endif
#ifdef FLOATING
void glMaterialf(GLenum face, GLenum pname, GLfloat param);
#else
#endif
void glMateriali(GLenum face, GLenum pname, GLint param);
#ifdef FLOATING
void glMaterialfv(GLenum face, GLenum pname, const GLfloat *params);
#else
#endif
void glMaterialiv(GLenum face, GLenum pname, const GLint *params);
void glMatrixMode(GLenum mode);
#ifdef FLOATING
void glMultMatrixd(const GLdouble *m);
#else
#endif
#ifdef FLOATING
void glMultMatrixf(const GLfloat  *m);
#else
#endif
	
void glNewList(GLuint list, GLenum mode);
void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz);
#ifdef FLOATING
void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz);
#else
#endif
#ifdef FLOATING
void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz);
#else
#endif
void glNormal3i(GLint nx, GLint ny, GLint nz);
void glNormal3s(GLshort nx, GLshort ny, GLshort nz);
void glNormal3bv(const GLbyte *v);
#ifdef FLOATING
void glNormal3dv(const GLdouble *v);
#else
#endif
#ifdef FLOATING
void glNormal3fv(const GLfloat *v);
#else
#endif
void glNormal3iv(const GLint *v);
void glNormal3sv(const GLshort *v);
void glNormalPointer(GLenum type, GLsizei stride, const GLvoid *pointer);

#ifdef FLOATING
void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
#else
#endif

#ifdef FLOATING
void glPassThrough(GLfloat token);
#else
#endif
#ifdef FLOATING
void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat *values);
#else
#endif
void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint *values);
void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort *values);
#ifdef FLOATING
void glPixelStoref(GLenum pname, GLfloat param);
#else
#endif
void glPixelStorei(GLenum pname, GLint param);
#ifdef FLOATING
void glPixelTransferf(GLenum pname, GLfloat param);
#else
#endif
void glPixelTransferi(GLenum pname, GLint param);
#ifdef FLOATING
void glPixelZoom(GLfloat xfactor, GLfloat yfactor);
#else
#endif
#ifdef FLOATING
void glPointSize(GLfloat size);
#else
#endif
void glPolygonMode(GLenum face, GLenum mode);
#ifdef FLOATING
void glPolygonOffset(GLfloat factor, GLfloat	 units);
#else
#endif
void glPolygonStipple(const GLubyte *mask);
void glPopAttrib(void);
void glPopClientAttrib(void);
void glPopMatrix(void);
void glPopName(void);
#ifdef FLOATING
void glPrioritizeTextures(GLsizei n, const GLuint *textures, const GLclampf *priorities);
#else
#endif
void glPushAttrib(GLbitfield mask);
void glPushClientAttrib(GLbitfield mask);
void glPushMatrix(void);
void glPushName(GLuint name);

#ifdef FLOATING
void glRasterPos2d(GLdouble x, GLdouble y);
#else
#endif
#ifdef FLOATING
void glRasterPos2f(GLfloat x, GLfloat y);
#else
#endif
void glRasterPos2i(GLint x, GLint y);
void glRasterPos2s(GLshort x, GLshort y);
#ifdef FLOATING
void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z);
#else
#endif
#ifdef FLOATING
void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z);
#else
#endif
void glRasterPos3i(GLint x, GLint y, GLint z);
void glRasterPos3s(GLshort x, GLshort y, GLshort z);
#ifdef FLOATING
void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w);
#else
#endif
#ifdef FLOATING
void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
#else
#endif
void glRasterPos4i(GLint x, GLint y, GLint z, GLint w);
void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w);
#ifdef FLOATING
void glRasterPos2dv(const GLdouble *v);
#else
#endif
#ifdef FLOATING
void glRasterPos2fv(const GLfloat *v);
#else
#endif
void glRasterPos2iv(const GLint *v);
void glRasterPos2sv(const GLshort *v);
#ifdef FLOATING
void glRasterPos3dv(const GLdouble *v); 
#else
#endif
#ifdef FLOATING
void glRasterPos3fv(const GLfloat *v);
#else
#endif
void glRasterPos3iv(const GLint *v);
void glRasterPos3sv(const GLshort *v);
#ifdef FLOATING
void glRasterPos4dv(const GLdouble *v);
#else
#endif
#ifdef FLOATING
void glRasterPos4fv(const GLfloat *v);
#else
#endif
void glRasterPos4iv(const GLint *v);
void glRasterPos4sv(const GLshort *v);
void glReadBuffer(GLenum mode);
void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLvoid *pixels);
#ifdef FLOATING
void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
#else
#endif
#ifdef FLOATING
void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
#else
#endif
void glRecti(GLint x1, GLint y1, GLint x2, GLint y2);
void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort	 y2);
#ifdef FLOATING
void glRectdv(const GLdouble *v1, const GLdouble *v2);
#else
#endif
#ifdef FLOATING
void glRectfv(const GLfloat *v1, const GLfloat *v2);
#else
#endif
void glRectiv(const GLint *v1, const GLint *v2);
void glRectsv(const GLshort *v1, const GLshort *v2);
GLint glRenderMode(GLenum mode);
#ifdef FLOATING
void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
#else
#endif
#ifdef FLOATING
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
#else
#endif

#ifdef FLOATING
void glScaled(GLdouble x, GLdouble y, GLdouble z);
#else
#endif
#ifdef FLOATING
void glScalef(GLfloat x, GLfloat y, GLfloat z);
#else
#endif
void glScissor(GLint x, GLint y, GLsizei width, GLsizei height);
void glSelectBuffer(GLsizei size, GLuint *buffer);
void glShadeModel(GLenum mode);
void glStencilFunc(GLenum func, GLint ref, GLuint mask);
void glStencilMask(GLuint mask);
void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass);

#ifdef FLOATING
void glTexCoord1d(GLdouble s);
#else
#endif
#ifdef FLOATING
void glTexCoord1f(GLfloat s);
#else
#endif
void glTexCoord1i(GLint s);
void glTexCoord1s(GLshort s);
#ifdef FLOATING
void glTexCoord2d(GLdouble s, GLdouble t);
#else
#endif
#ifdef FLOATING
void glTexCoord2f(GLfloat s, GLfloat t);
#else
#endif
void glTexCoord2i(GLint s, GLint t);
void glTexCoord2s(GLshort s, GLshort t);
#ifdef FLOATING
void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r);
#else
#endif
#ifdef FLOATING
void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r);
#else
#endif
void glTexCoord3i(GLint s, GLint t, GLint r);
void glTexCoord3s(GLshort s, GLshort t, GLshort r);
#ifdef FLOATING
void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q);
#else
#endif
#ifdef FLOATING
void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q);
#else
#endif
void glTexCoord4i(GLint s, GLint t, GLint r, GLint q);
void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q);
#ifdef FLOATING
void glTexCoord1dv(const GLdouble *v);
#else
#endif
#ifdef FLOATING
void glTexCoord1fv(const GLfloat *v);
#else
#endif
void glTexCoord1iv(const GLint *v);
void glTexCoord1sv(const GLshort *v);
#ifdef FLOATING
void glTexCoord2dv(const GLdouble *v); 
#else
#endif
#ifdef FLOATING
void glTexCoord2fv(const GLfloat *v);
#else
#endif
void glTexCoord2iv(const GLint *v);
void glTexCoord2sv(const GLshort *v);
#ifdef FLOATING
void glTexCoord3dv(const GLdouble *v); 
#else
#endif
#ifdef FLOATING
void glTexCoord3fv(const GLfloat *v);
#else
#endif
void glTexCoord3iv(const GLint *v);
void glTexCoord3sv(const GLshort *v);
#ifdef FLOATING
void glTexCoord4dv(const GLdouble *v);
#else
#endif
#ifdef FLOATING
void glTexCoord4fv(const GLfloat *v);
#else
#endif
void glTexCoord4iv(const GLint *v);
void glTexCoord4sv(const GLshort *v);
void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
#ifdef FLOATING
void glTexEnvf(GLenum target, GLenum pname, GLfloat param);
#else
#endif
void glTexEnvi(GLenum target, GLenum pname, GLint param);
#ifdef FLOATING
void glTexEnvfv(GLenum target, GLenum pname, const GLfloat *params);
#else
#endif
void glTexEnviv(GLenum target, GLenum pname, const GLint   *params);
#ifdef FLOATING
void glTexGend(GLenum coord, GLenum pname, GLdouble param);
#else
#endif
#ifdef FLOATING
void glTexGenf(GLenum coord, GLenum pname, GLfloat param);
#else
#endif
void glTexGeni(GLenum coord, GLenum pname, GLint param);
#ifdef FLOATING
void glTexGendv(GLenum coord, GLenum pname, const GLdouble *params);
#else
#endif
#ifdef FLOATING
void glTexGenfv(GLenum coord, GLenum pname, const GLfloat *params);
#else
#endif
void glTexGeniv(GLenum coord, GLenum pname, const GLint *params);
void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const GLvoid *pixels);
#ifdef FLOATING
void glTexParameterf(GLenum target, GLenum pname, GLfloat param);
#else
#endif
void glTexParameteri(GLenum target, GLenum pname, GLint param);
#ifdef FLOATING
void glTexParameterfv(GLenum target, GLenum pname, const GLfloat *params);
#else
#endif
void glTexParameteriv(GLenum target, GLenum pname, const GLint   *params);
void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const GLvoid *pixels);
void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const GLvoid *pixels);
#ifdef FLOATING
void glTranslated(GLdouble x, GLdouble y, GLdouble z);
#else
#endif
#ifdef FLOATING
void glTranslatef(GLfloat x, GLfloat y, GLfloat z);
#else
#endif

#ifdef FLOATING
void glVertex2d(GLdouble x, GLdouble y);
#else
#endif
#ifdef FLOATING
void glVertex2f(GLfloat x, GLfloat y );
#else
#endif
void glVertex2i(GLint x, GLint y );
void glVertex2s(GLshort x, GLshort y );
#ifdef FLOATING
void glVertex3d(GLdouble x, GLdouble y, GLdouble z );
#else
#endif
#ifdef FLOATING
void glVertex3f(GLfloat x, GLfloat y, GLfloat z );
#else
#endif
void glVertex3i(GLint x, GLint y, GLint z );
void glVertex3s(GLshort x, GLshort y, GLshort z );
#ifdef FLOATING
void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w );
#else
#endif
#ifdef FLOATING
void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w );
#else
#endif
void glVertex4i(GLint x, GLint y, GLint z, GLint w );
void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w );
void glVertexPointer(GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
void glViewport(GLint x, GLint y, GLsizei width, GLsizei height);

#endif //__opengl64__