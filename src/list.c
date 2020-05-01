#include "../include/nus64.h"
#include "../include/assert64.h"
FILENUM(2)
#define FLOATING
#include "ogl64.h"
#include "ogl64_internal.h"

GLContext *gl_get_context(void)
{
  return gl_ctx;
}

GLImmediateState *gl_get_immediate(void)
{
	return gl_imm;
}
/*
void gl_compile_op(GLContext *c,GLParam *p)
{
  int op,op_size;
  GLParamBuffer *ob,*ob1;
  int index,i;

  op_size=op_table_size[op];
  index=c->current_op_buffer_index;
  ob=c->current_op_buffer;
*/
  /* we should be able to add a NextBuffer opcode */
 /*
  if ((index + op_size) > (OP_BUFFER_MAX_SIZE-2)) {

    ob1=gl_zalloc(sizeof(GLParamBuffer));
    ob1->next=NULL;

    ob->next=ob1;
    ob->ops[index].op=OP_NextBuffer;
    ob->ops[index+1].p=(void *)ob1;

    c->current_op_buffer=ob1;
    ob=ob1;
    index=0;
  }
  op=p[0].op;

  for(i=0;i<op_size;i++) {
    ob->ops[index]=p[i];
    index++;
  }
  c->current_op_buffer_index=index;
} */

//static char op_table_str[]=
//{
	//'a'
//#define ADD_OP(a,b,c) "gl" #a " " #c,

// #include "opinfo.h"
//};

//static void (*op_table_func[])(GLContext *,GLParam *)=
//{
//#define ADD_OP(a,b,c) glop ## a ,

// #include "opinfo.h"
//};

void gl_print_op(GLParam *p)
{
  //int op;
  char *s = 0;

  //op=p[0].op;
  p++;
  //s=op_table_str[op];
  while (*s != 0) {
    if (*s == '%') {
      s++;
      switch (*s++) {
      case 'f':
	//fprintf(f,"%g",p[0].f);
	break;
      default:
	//fprintf(f,"%d",p[0].i);
	break;
      }
      p++;
    } else {
      //fputc(*s,f);
      s++;
    }
  }
  //fprintf(f,"\n");
}

void gl_add_op(GLParam *p)
{
	ASSERT(p);
	GLContext *ctx = gl_get_context();
	if (ctx->compile_mode == GL_IMMEDIATE)
	{
		// Add to Scratch Display List
		GLImmediateState *imm = gl_get_immediate();
		ASSERT(imm);
		if (p[0].op == OP_Vertex)
		{			
			imm->vertexCount++;
		}
		if (p[0].op == OP_Normal)
		{
			imm->vertexCount++;
		}
	}
	else // GL_COMPILE || GL_COMPILE_AND_EXECUTE
	{
		// Add to Active Display List
	}

	//op=p[0].op;
	if (ctx->exec_flag) {
		//op_table_func[op](c,p);
	}
	if (ctx->compile_flag) {
		//gl_compile_op(c,p);
	}
	if (ctx->print_flag) {
		//gl_print_op(p);
	}
}