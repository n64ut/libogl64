#include "../include/nus64.h"
#include "../include/assert64.h"
FILENUM(4)
#include "ogl64.h"
#include "ogl64_internal.h"
#include "glu64.h"

// This libraries native format is int16_t
//		The use of floats WILL affect Display List Compile time
//		The use of floats WILL affect Immediate Mode execution time
//		The use of floats will NOT affect Display List Execution
// This library is also VERY strongly typed.
//		Because the code/compile/test cycle can be long and the 
//		debugging situation isn't great, catching code errors
//		at compile time should really help.
// Some variable types are shrunk to account for limited memory, 
//		these should still be within reasonable ranges, 
//		if larger ranges are needed ask.

// TODO: The following items will be implemented in the RSP
// Triangles
// Matrixes
// Lighting
// LookAt aka Camera

// TODO: OpenGL Implementation Sequence
// glViewport
// glMatrixMode
// glLoadIdentity
// glShadeModel
// glClearColor
// glClearDepth
// glDepthFunc
// glHint
// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// glTranslatef();
// glBegin
// glVertex2f
// glVertex3f
// glEnd

// glEnable
// glDisable
// glGenLists
// glNewList
// glEndList
// glLightfv	- RSP
// glMaterialfv
// glViewport	- RSP
// glMatrixMode	- RSP
// glLoadIdentity
// glFrustum	- RSP
// glTranslatef	- RSP
// glClear
// glPushMatrix	- RSP
// glRotatef	- RSP
// glCallList
// glPopMatrix	- RSP
// glBegin
// glEnd
// glNormal3f
// glVertex3f
// glShadeModel
// glTexCoord2f	- RSP
// glColor3f
// glScalef	- RSP
// glLightf	- RSP



void glInit(void *pzbuffer, void * pscratch_area, int32_t pscratch_length)
{
	ASSERT(zbuffer);
	ASSERT(pscratch_area);
	ASSERT(pscratch_length > 0);
	zbuffer = pzbuffer;
	scratch_area = pscratch_area;
	scratch_length = pscratch_length;
}

void glDisable(glmode_t cap)
{	
	if (cap > 0)
	{
		GLContext *c = gl_get_context();
		if ((cap & c->SupportedModes) > 0)
			c->EnabledModes &= ~cap;
	}
}

void glEnable(glmode_t cap)
{
	if (cap > 0)
	{
		GLContext *c = gl_get_context();
		if ((cap & c->SupportedModes) > 0)
			c->EnabledModes |= cap;
	}
}

void glNormal3f(GLfloat x,GLfloat y,GLfloat z)
{
  GLParam p[4];

  p[0].op=OP_Normal;
  p[1].i=mapf2i(x, -1.0f, 1.0f, -32768, 32767);
  p[2].i=mapf2i(y, -1.0f, 1.0f, -32768, 32767);
  p[3].i=mapf2i(z, -1.0f, 1.0f, -32768, 32767);

  gl_add_op(p);
}

void glNormal3fv(const GLfloat *v) 
{
  glNormal3f(v[0],v[1],v[2]);
}

void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w)
{
  GLParam p[5];

  p[0].op=OP_Vertex;
  p[1].i=x;
  p[2].i=y;
  p[3].i=z;
  p[4].i=w;

  gl_add_op(p);
}

void glVertex3s(GLshort x, GLshort y, GLshort z)
{
	glVertex4s(x,y,z,32767);
}

void glVertex2s(GLshort x, GLshort y)
{
	glVertex4s(x,y,0,32767);
}

void glVertex4i(GLint x, GLint y, GLint z, GLint w)
{
  GLParam p[5];

  p[0].op=OP_Vertex;
  p[1].i=map2l(x, -2147483648 , 2147483647, -32768, 32767);
  p[2].i=map2l(y, -2147483648 , 2147483647, -32768, 32767);
  p[3].i=map2l(z, -2147483648 , 2147483647, -32768, 32767);
  p[4].i=map2l(w, -2147483648 , 2147483647, -32768, 32767);

  gl_add_op(p);
}

void glVertex3i(GLint x, GLint y, GLint z)
{
	glVertex4i(x,y,z,32767);
}

void glVertex2i(GLint x, GLint y)
{
	glVertex4i(x,y,0,32767);
}

void glVertex4d(GLdouble x,GLdouble y,GLdouble z,GLdouble w)
{
  GLParam p[5];

  p[0].op=OP_Vertex;
  p[1].i=mapd2i(x, -2.0f, 2.0f, -32768, 32767);
  p[2].i=mapd2i(y, -2.0f, 2.0f, -32768, 32767);
  p[3].i=mapd2i(z, -2.0f, 2.0f, -32768, 32767);
  p[4].i=mapd2i(w, -2.0f, 2.0f, -32768, 32767);

  gl_add_op(p);
}

void glVertex2d(GLdouble x,GLdouble y) 
{
	glVertex4d(x,y,0,1);
}

void glVertex3d(GLdouble x,GLdouble y,GLdouble z) 
{
	glVertex4d(x,y,z,1);
}

void glVertex4f(GLfloat x,GLfloat y,GLfloat z,GLfloat w)
{
  GLParam p[5];

  p[0].op=OP_Vertex;
  p[1].i=mapf2i(x, -1.0f, 1.0f, -32768, 32767);
  p[2].i=mapf2i(y, -1.0f, 1.0f, -32768, 32767);
  p[3].i=mapf2i(z, -1.0f, 1.0f, -32768, 32767);
  p[4].i=mapf2i(w, -1.0f, 1.0f, -32768, 32767);

  gl_add_op(p);
}

void glVertex2f(GLfloat x,GLfloat y) 
{
	glVertex4f(x,y,0,1);
}

void glVertex3f(GLfloat x,GLfloat y,GLfloat z) 
{
	glVertex4f(x,y,z,1);
}

void glVertex3fv(const GLfloat *v)
{
	glVertex4f(v[0],v[1],v[2],1);
}

void glNewList(GLuint list, glcompile_mode_t mode)
{
	ASSERT(list);
	GLContext *c = gl_get_context();
	c->compile_mode = mode;
}

void glClearColor(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	
	uint32_t color = alpha | (blue << 8) | (green << 16) | (red << 24);
	if (color == 0)
	{
	}
}
	
void glClearDepth(GLushort depth)
{
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	if (depth == 0)
	{
	}

}
	
void glClearAccum(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	uint32_t color = alpha | (blue << 8) | (green << 16) | (red << 24);
	if (color == 0)
	{
	}
}

void glClearStencil(GLubyte s)
{
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	if (s == 0)
	{
	}

}

void glClear(glclear_t mask)
{
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	if ((mask & GL_COLOR_BUFFER_BIT) > 0)
	{
		glClearColor(0, 0, 0, 0);
	}
	if ((mask & GL_DEPTH_BUFFER_BIT) > 0)
	{
		glClearDepth(1);
	}
	if ((mask & GL_ACCUM_BUFFER_BIT) > 0)
	{
		// Unsupported?
		glClearAccum(0, 0, 0, 0);
	}
	if ((mask & GL_STENCIL_BUFFER_BIT) > 0)
	{
		// Unsupported?
		glClearStencil(0);
	}
}

void glDepthFunc(gldepth_t func)
{
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	switch(func)
	{
		default:
		break;
	}
}

void glEndList(void)
{
	GLContext *ctx = gl_get_context();
	
	// ctx->compile_mode = GL_IMMEDIATE;
	if (ctx->compile_mode < 0)//aka ctx->compile_mode == GL_COMPILE_AND_EXECUTE)
	{
		// DMA the list to RDP now
	}

}

void glBegin(glprimative_t type)
{	
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	switch(type)
	{
		case GL_TRIANGLES: 
		case GL_TRIANGLE_STRIP: 
		case GL_TRIANGLE_FAN: 
		case GL_QUADS: 
		case GL_QUAD_STRIP: 
		// Only shapes that can be made with Triangles, sorry
		default: // GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_POLYGON
			ctx->error = GL_INVALID_OPERATION;
			return;
		break;
	}
	if (ctx->compile_mode == GL_IMMEDIATE)
	{
		GLImmediateState *imm = gl_get_immediate();
		imm->primative = type;
		ASSERT(imm);
	}
	else
	{
	}
}

void glEnd(void)
{
	GLContext *ctx = gl_get_context();
	if (!ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	GLImmediateState *imm = gl_get_immediate();
	switch(imm->primative)
	{
		case GL_TRIANGLES: 
			if ((imm->vertexCount % 3) != 0)
			{
				ctx->error = GL_INVALID_OPERATION;
				return;
			}
		break;
		case GL_TRIANGLE_STRIP:
			if (imm->vertexCount < 4)
			{
				ctx->error = GL_INVALID_OPERATION;
				return;
			}
		break;
		case GL_TRIANGLE_FAN: 
			if (imm->vertexCount < 4)
			{
				ctx->error = GL_INVALID_OPERATION;
				return;
			}
		break;
		case GL_QUADS: 
			if ((imm->vertexCount % 4) != 0)
			{
				ctx->error = GL_INVALID_OPERATION;
				return;
			}
		break;
		case GL_QUAD_STRIP:
			if ((imm->vertexCount % 2) != 0)
			{
				ctx->error = GL_INVALID_OPERATION;
				return;
			}		break;
		// Only shapes that can be made with Triangles, sorry
		default: // GL_POINTS, GL_LINES, GL_LINE_STRIP, GL_LINE_LOOP, GL_POLYGON
		
		break;
	}
	ctx->insidePrimative = false;	
}

void glHint(hinttarget_t target, hintmode_t mode)
{
	GLContext *ctx = gl_get_context();
	if (!ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	ctx->hints[target] = mode;
}

glerror_t glGetError(void)
{
	GLContext *ctx = gl_get_context();
	return ctx->error;
}

GLubyte *gluErrorString(glerror_t error)
{
	switch(error)
	{
		case GL_NO_ERROR: break;		
		case GL_INVALID_ENUM: break;
		case GL_INVALID_VALUE: break;
		case GL_INVALID_OPERATION: break;
		case GL_STACK_OVERFLOW: break;
		case GL_STACK_UNDERFLOW: break;
		case GL_OUT_OF_MEMORY: break;
	}
	return NULL;
}
GLuint glGenLists(GLint range)
{
  //GLContext *c=gl_get_context();
  int count,i,list;
  GLList **lists = NULL;

  //lists=c->shared_state.lists;
  count=0;
  for(i=0;i<MAX_DISPLAY_LISTS;i++) {
    if (lists[i]==NULL) {
      count++;
      if (count == range) {
	list=i-range+1;
	for(i=0;i<range;i++) {
	  //alloc_list(c,list+i);
	}
	return list;
      }
    } else {
      count=0;
    }
  }
  return 0;
}

GLboolean glIsEnabled(glboolValues_t cap)
{
	GLboolean result = false;
	GLContext *ctx = gl_get_context();
	if (!ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return result;
	}
	switch(cap)
	{
		case GL_ALPHA_TEST: result = false; break;	// glAlphaFunc
		case GL_AUTO_NORMAL: result = false; break;	// glEvalCoord
		case GL_BLEND: result = false; break;	// glBlendFunc, glLogicOp
		case GL_CLIP_PLANEi: result = false; break;	// glClipPlane
		case GL_COLOR_ARRAY: result = false; break;	// glColorPointer
		case GL_COLOR_LOGIC_OP: result = false; break;	// glLogicOp
		case GL_COLOR_MATERIAL: result = false; break;	// glColorMaterial
		case GL_CULL_FACE: result = false; break;	// glCullFace
		case GL_DEPTH_TEST: result = false; break;	// glDepthFunc, glDepthRange
		case GL_DITHER: result = false; break;	// glEnable
		case GL_EDGE_FLAG_ARRAY: result = false; break;	// glEdgeFlagPointer
		case GL_FOG: result = false; break;	// glFog
		case GL_INDEX_ARRAY: result = false; break;	// glIndexPointer
		case GL_INDEX_LOGIC_OP: result = false; break;	// glLogicOp
		case GL_LIGHTi: result = false; break;	// glLightModel, glLight
		case GL_LIGHTING: result = false; break;	// glMaterial, glLightModel, glLight
		case GL_LINE_SMOOTH: result = false; break;	// glLineWidth
		case GL_LINE_STIPPLE: result = false; break;	// glLineStipple
		case GL_MAP1_COLOR_4: result = false; break;	// glMap1, glMap2
		case GL_MAP2_TEXTURE_COORD_2: result = false; break;	// glMap2
		case GL_MAP2_TEXTURE_COORD_3: result = false; break;	// glMap2
		case GL_MAP2_TEXTURE_COORD_4: result = false; break;	// glMap2
		case GL_MAP2_VERTEX_3: result = false; break;	// glMap2
		case GL_MAP2_VERTEX_4: result = false; break;	// glMap2
		case GL_NORMAL_ARRAY: result = false; break;	// glNormalPointer
		case GL_NORMALIZE: result = false; break;	// glNormal
		case GL_OCCLUSION_TEST_HP: result = false; break;	// glEnable
		case GL_POINT_SMOOTH: result = false; break;	// glPointSize
		case GL_POLYGON_SMOOTH: result = false; break;	// glPolygonMode
		case GL_POLYGON_OFFSET_FILL: result = false; break;	// glPolygonOffset
		case GL_POLYGON_OFFSET_LINE: result = false; break;	// glPolygonOffset
		case GL_POLYGON_OFFSET_POINT: result = false; break;	// glPolygonOffset
		case GL_POLYGON_STIPPLE: result = false; break;	// glPolygonStipple
		case GL_RESCALE_NORMAL_EXT: result = false; break;	// glEnable
		case GL_SCISSOR_TEST: result = false; break;	// glScissor
		case GL_STENCIL_TEST: result = false; break;	// glStencilFunc, glStencilOp
		case GL_TEXTURE_1D: result = false; break;	// glTexImage1D
		case GL_TEXTURE_2D: result = false; break;	// glTexImage2D
		case GL_TEXTURE_3D_EXT: result = false; break; // (if 3D texturing is supported)	// glTexImage3DEXT
		case GL_TEXTURE_COORD_ARRAY: result = false; break;	// glTexCoordPointer
		case GL_TEXTURE_GEN_Q: result = false; break;	// glTexGen
		case GL_TEXTURE_GEN_R: result = false; break;	// glTexGen
		case GL_TEXTURE_GEN_S: result = false; break;	// glTexGen
		case GL_TEXTURE_GEN_T: result = false; break;	// glTexGen
		case GL_VERTEX_ARRAY: result = false; break;	// glVertexPointer
	}
	return result;
}

void glGetBooleanv(glboolValues_t pname, GLboolean *params)
{
	*params = glIsEnabled(pname);
}

void glGetDoublev(GLenum pname, GLdouble *params)
{
	ASSERT(pname);
	*params = 0.0L;
}

void glGetFloatv(GLenum pname, GLfloat *params)
{
	ASSERT(pname);
	*params = 0.0f;
}

void glGetIntegerv(GLenum pname, GLint *params)
{
	ASSERT(pname);
	*params = 1;
}

void glShadeModel(glshademodel_t mode)
{
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	ctx->shademodel = mode;
}

void glViewport(GLint x, GLint y, GLsizei width, GLsizei height)
{
	GLContext *ctx = gl_get_context();
	if (ctx->insidePrimative)
	{
		ctx->error = GL_INVALID_OPERATION;
		return;
	}
	if (width < 0 || height < 0 || x < 0 || y < 0)
	{
		ctx->error = GL_INVALID_VALUE ;
		return;
	}
	
	// TODO: Not sure what to do with this yet
}