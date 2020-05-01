#ifndef __OGL64INTERNAL__
#define __OGL64INTERNAL__

#define OP_Normal 1
#define OP_Vertex 2

#define OP_BUFFER_MAX_SIZE 512
#define MAX_DISPLAY_LISTS 1024

typedef union {
  int op;
  float f;
  int i;
  unsigned int ui;
  void *p;
} GLParam;

typedef struct GLParamBuffer {
  GLParam ops[OP_BUFFER_MAX_SIZE];
  struct GLParamBuffer *next;
} GLParamBuffer;

typedef struct GLList {
  GLParamBuffer *first_op_buffer;
  /* TODO: extensions for an hash table or a better allocating scheme */
} GLList;

typedef struct GLContext {
	uint64_t EnabledModes;
	uint64_t SupportedModes;
	int exec_flag,compile_flag,print_flag;
	glcompile_mode_t compile_mode;
	glerror_t error;
	glshademodel_t shademodel;
	hintmode_t hints[HINT_TARGET_LEN];
	bool insidePrimative;
} GLContext;

typedef struct GLImmediateState {
	glprimative_t primative;
	uint16_t vertexCount;
	float pointSize;
	uint32_t color;
} GLImmediateState;

void * zbuffer;
void * scratch_area;
int32_t scratch_length;
extern GLImmediateState *gl_imm;
extern GLContext *gl_ctx;

void gl_add_op(GLParam *p);
GLContext *gl_get_context(void);
GLImmediateState *gl_get_immediate(void);
#endif // __OGL64INTERNAL__