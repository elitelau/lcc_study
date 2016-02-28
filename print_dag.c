#include "sglib.h"
#include "c.h"
#include "print_dag.h"
#include <stdio.h>


static void bfs_traverse_on_dag(Tree p, FILE* out_file);
static void reset();

typedef enum direction {
   DIR_LEFT = 0,
   DIR_RIGHT = 1
} direction;

void print_dag(struct tree* p) {
   FILE* dag_print_file = 0;
   static expr_dag_no_in_line = 1;
   char  dag_name[DAG_NAME_LENGTH];
   char  dag_print_file_name[260];
   char* str = NULL;

   if( NULL == p ) {
      return ;
   }
   
   str = getenv("LCC_DAG_DUMP_ENABLE");
   if( str && strcmp(str, "true") == 0 ) 
      ;
   else 
     return;

//   fprintf(stderr, "test ...\n");
   assert(file);
   
   // test.c_line100 => test_c_line100
   sprintf(dag_name, "%s_line%d", file, lineno);
   for( str = dag_name; *str != '\0'; ++str ) {
      if( *str == '.' ) {
         *str = '_';
         break;
      }
   }

//   fprintf(stderr, "test: dag_name = %s\n", dag_name);
//   fprintf(stderr, "test: prev_dag_name = %s\n", prev_dag_name);
   
   if( strncmp(dag_name, 
               prev_dag_name, 
               (strlen(dag_name) < strlen(prev_dag_name) ? 
                strlen(dag_name) : strlen(prev_dag_name))) == 0 
      && 
       strlen(prev_dag_name) > 0 ) 
   {
       sprintf(dag_name + strlen(dag_name), "_%d", expr_dag_no_in_line++);
   }
   else {
       expr_dag_no_in_line = 1;
       memset(prev_dag_name, 0, DAG_NAME_LENGTH);
       strcpy(prev_dag_name, dag_name);
   }

   str = getenv("LCC_DAG_DUMP_DIR");

   if( str ) {
      sprintf(dag_print_file_name, "%s/%s.dot", str, dag_name);
   }
   else {
      sprintf(dag_print_file_name, "%s.dot", dag_name);
   }

//   fprintf(stderr, "test: %s\n", dag_print_file_name);
   dag_print_file = fopen(dag_print_file_name, "w" );
   
   if( !dag_print_file )
      return;

   // clear queue for next use
   reset();
   bfs_traverse_on_dag(p, dag_print_file);

   fclose(dag_print_file);
}


typedef struct vertex {
   Tree   first;     // dag node
   int    second;    // number of dag node
} vertex;
// typedef std::pair<Tree, int> vertex;

typedef struct dllist {
   vertex*   v;
   struct dllist* next;
   struct dllist* prev;
} BFSQueue;

#define BFSQUEUE_COMPARATOR(e1, e2) (e1->v == e2->v)

SGLIB_DEFINE_DL_LIST_PROTOTYPES(BFSQueue, BFSQUEUE_COMPARATOR, prev, next);
SGLIB_DEFINE_DL_LIST_FUNCTIONS(BFSQueue, BFSQUEUE_COMPARATOR, prev, next);

static BFSQueue* popoff_node_list;
static BFSQueue* popoff_node_list_tail;
static BFSQueue* bfs_queue;
static BFSQueue* bfs_queue_tail;

static void reset(void)  {
    BFSQueue*  que;
    struct sglib_BFSQueue_iterator  it;

    // clear pop off node list
    for( que = sglib_BFSQueue_it_init(&it, popoff_node_list); 
         que != NULL; 
         que = sglib_BFSQueue_it_next(&it) )
    {
        free(que->v);
        free(que);
    }

    // clear queue for breadth-first search
    assert( sglib_BFSQueue_len(bfs_queue) == 0 );
    for( que = sglib_BFSQueue_it_init(&it, bfs_queue); 
         que != NULL; 
         que = sglib_BFSQueue_it_next(&it) )
    {
        free(que->v);
        // !!! must not, in case of duplicate deletion
        // free(que->v);
    }

    popoff_node_list  = NULL;
    popoff_node_list_tail = NULL;
    bfs_queue  = NULL;
    bfs_queue_tail = NULL;
}

static vertex* is_fell_on_list(Tree p, BFSQueue* que) {
    vertex*     v = NULL;
    BFSQueue*  item;
    struct sglib_BFSQueue_iterator  it;

    for( item = sglib_BFSQueue_it_init(&it, que); 
         item != NULL; 
         item = sglib_BFSQueue_it_next(&it) )
    {
        if( item->v->first == p ) {
            v = item->v;
            break;
        }
    }

    return v;
}

static void act_push_back(BFSQueue** que, BFSQueue** que_tail, BFSQueue* item) {
    if( NULL == *que ) {
        sglib_BFSQueue_add_after(que, item);
    }
    else {
        sglib_BFSQueue_add_after(que_tail, item);
    }
    *que_tail = item;
}

static void act_pop_off(BFSQueue** que) {
    BFSQueue* item = *que;
    sglib_BFSQueue_delete(que, item);
    free(item); // !!! must
}

static void start_to_generate_dot(FILE* out_file) {
    fprintf( out_file, "////////////////////////////////////////////////////////////////////////////////\n" );
    fprintf( out_file, "// Generate the dot file for drawing semantic structure of statements\n\n" );
    fprintf( out_file, "// File name: %s\n", file );
    fprintf( out_file, "// Line number: %d\n", lineno );
    fprintf( out_file, "////////////////////////////////////////////////////////////////////////////////\n\n" );

    fprintf( out_file, "digraph semantic_dag  {\n" );

    // set display format
    // fprintf( out_file, "    size=\"6,6\";\n" );
    fprintf( out_file, "    node [color=lightblue2, style=filled];\n\n" );
}

static void end_to_generate_dot(FILE* out_file) {
    fprintf(out_file, "}\n");
}

static void generate_dot_for_vertex(vertex* v, FILE* out_file)
{
    int display_in_box = 0;
//    fprintf(out_file, "v%d [label=\"%s\"];\n", v->second, );
    
    fprintf(out_file, "    v%d [label=\"", v->second);
    // fprint(out_file, "%s %t\"];\n", opname(v->first->op), v->first->type);
    fprint(out_file, "%s %t", opname(v->first->op), v->first->type);
    switch(generic(v->first->op)) {
    case COND:
       if( v->first->u.sym ) {  
          // tree for conditional expr have a generated symbol which stores the value of 
          // 2nd or 3rd expression
          fprintf(out_file, "\\n\\[gen:%s\\]", v->first->u.sym->name);
       }
       break;
    case ADDRF:
    case ADDRL:
    case ADDRG:
       display_in_box = 1;
       // in case of generated symbol for storage
       // f ? 0 : 1;    two temporaries for storing 0, 1
       // there are also generated symbols, for example:
       // char *s = "hello world!";  a generated symbol to be attached in idtree
       if( v->first->u.sym->generated ) {
           if( v->first->u.sym->temporary ) {
              fprintf(out_file, "\\n\\[tmp:%s\\]", v->first->u.sym->name);
           }
           else {
              fprintf(out_file, "\\n\\[gen:%s\\]", v->first->u.sym->name);
           }
           break;
       }
       if( !isarray(unqual(v->first->u.sym->type)) )  { // !!!
                                    // string literal is stored as an array of char
           fprintf(out_file, "\\n\\[%s\\]", v->first->u.sym->name);
       }
       break;
    case CNST:
       {
       display_in_box = 1;

       // floating constants
       if( v->first->type == doubletype || 
           v->first->type == longdouble ||
           v->first->type == floattype ) 
       {  // ???? how to print long double
          if( floattype == v->first->type ) {
              fprintf(out_file, "\\n\\(%f\\)", (float)v->first->u.v.d);
          }
          else if( doubletype == v->first->type ) {
              fprintf(out_file, "\\n\\(%g\\)", (double)v->first->u.v.d);
          }
          else {
              fprintf(out_file, "\\n\\(%Lg\\)", v->first->u.v.d);
          }
          break;
       }

       // integer constants
       switch(v->first->type->op) {
          case INT:
             fprintf(out_file, "\\n\\(%ld\\)", v->first->u.v.i);
             break;
          case UNSIGNED:
             fprintf(out_file, "\\n\\(%lu\\)", v->first->u.v.u);
             break;
          default:
             break;
       }

       // ?? how to print a string literal, since its operation is: ADDRLP/ADDRGP
       }
       break;
    default:
       break;
    }

    if( display_in_box ) {
       fprintf(out_file, "\", shape=box];\n");
    }
    else {
       fprintf(out_file, "\"];\n");
    }
}

static void generate_dot_for_edge(vertex* from, vertex* to, FILE* out_file, direction dir)
{
    if( RIGHT == generic(from->first->op) ) {
       if( DIR_LEFT == dir ) {
          fprintf(out_file, "    v%d -> v%d [label=\"L\"];\n", from->second, to->second);
       }
       else {
          fprintf(out_file, "    v%d -> v%d [label=\"R\"];\n", from->second, to->second);
       }
    }
    else {
       fprintf(out_file, "    v%d -> v%d;\n", from->second, to->second);
    }
}

// use breadth first search when traversal all edges of dag, 
// because of fewest influence on the dag tree data structure and extra space consume
static void bfs_traverse_on_dag(Tree p, FILE* out_file) {
   vertex* is_fall_in_popoff_list = NULL;
   vertex* is_fall_in_queue = NULL;
   BFSQueue* item;

   int node_id = 1;

   item = malloc(sizeof(BFSQueue));
   item->v = malloc(sizeof(vertex));
   item->v->first = p;
   item->v->second = node_id++;

   act_push_back( &bfs_queue, &bfs_queue_tail, item );

   start_to_generate_dot(out_file);   
   generate_dot_for_vertex(item->v, out_file);
   
   while( NULL != bfs_queue ) {
      vertex* parent = bfs_queue->v;
      vertex *child_left, *child_right;
      child_left = child_right = NULL;

      // ! add to popoff list for the poped off item
      item = malloc(sizeof(BFSQueue));
      item -> v = bfs_queue->v;
      act_push_back( &popoff_node_list, &popoff_node_list_tail, item );
      
      act_pop_off( &bfs_queue ); // pop off an item
      
      // !!! notice: it's special to RIGHT operaion, since its 1st child
      //     maybe empty, however, the 2nd one is not.
      //     e.g.   a, ++b;    // 1st child is "a", however without side-effort
      if( parent->first->kids[1] != NULL || parent->first->kids[0] != NULL ) {
         /* assert( parent->first->kids[0] ); */
        
         if( parent->first->kids[0] ) {  // !!! RIGHT's 1st child maybe empty, the 2nd not
            is_fall_in_popoff_list = is_fell_on_list(parent->first->kids[0], popoff_node_list);
            is_fall_in_queue = is_fell_on_list(parent->first->kids[0], bfs_queue);

            if( !is_fall_in_popoff_list && !is_fall_in_queue ) {
               // add to queue, only the vertex has not been visited before
               item = malloc(sizeof(BFSQueue));
               item->v = child_left = malloc(sizeof(vertex));
               child_left->first = parent->first->kids[0];
               child_left->second = node_id++;

               act_push_back( &bfs_queue, &bfs_queue_tail, item );

               generate_dot_for_vertex(child_left, out_file);
            }
            child_left = is_fall_in_popoff_list ? is_fall_in_popoff_list : 
                       is_fall_in_queue ? is_fall_in_queue : child_left;
         }

         if( parent->first->kids[1] ) {
            is_fall_in_popoff_list = is_fell_on_list(parent->first->kids[1], popoff_node_list);
            is_fall_in_queue = is_fell_on_list(parent->first->kids[1], bfs_queue);

            if( !is_fall_in_popoff_list && !is_fall_in_queue ) {
               // add to queue, only the vertex has not been visited before
               item = malloc(sizeof(BFSQueue));
               item->v = child_right = malloc(sizeof(vertex));
               child_right->first = parent->first->kids[1];
               child_right->second = node_id++;
               
               act_push_back( &bfs_queue, &bfs_queue_tail, item);

               generate_dot_for_vertex(child_right, out_file);
            }
            child_right = is_fall_in_popoff_list ? is_fall_in_popoff_list : 
                        is_fall_in_queue ? is_fall_in_queue : child_right;
         }
      }

      // print edges a parental node streches from
      if( parent->first->kids[0] ) {
         generate_dot_for_edge(parent, child_left, out_file, DIR_LEFT);
      }
      if( parent->first->kids[1] ) {
         generate_dot_for_edge(parent, child_right, out_file, DIR_RIGHT);
      }

      if( parent->first->kids[0] || parent->first->kids[1] ) {
         fprintf(out_file, "\n");
      }
   }

   end_to_generate_dot(out_file);
}


/*****************************************************************************/
/*  module for dumping symbol information at various scopes                  */
/*****************************************************************************/
static FILE* sym_print_file = 0;
static int sym_print_in_detail = 0;
static int function_switch = 1;  // 0: open  1: close

static const char* get_sclass_str(int sclass) {
   const char *p = NULL;

   switch(sclass) {
   case STATIC: 
       p = "static";
       break;
   case EXTERN:
       p = "extern";
       break;
   case REGISTER:
       p = "register";
       break;
   case TYPEDEF:
       p = "typedef";
       break;
   case AUTO:
       break;
       assert(0);
   }

   return p;
}

void print_decl(Symbol p, Type ty, FILE* out_file) {
	assert(ty);
    switch (p->sclass) {
	case AUTO: case TYPEDEF:
		fprint(out_file, "%s", typestring(ty, p->name));
		break;
	case STATIC: case EXTERN: case REGISTER:
		fprint(out_file, "%k %s", p->sclass, typestring(ty, p->name));
		break;
	default: //assert(0);
        break;
	}
}


/*
static void print_array_type(Type ty, FILE* f) {
   if( !isarray(ty) ) {
       if( ty->size > 0)
          fprint(f, "%t", ty );
       else 
          fprintf(f, "incomplete type" );

       return;   
   }

   if (ty->size > 0 && ty->type && ty->type->size > 0) {
        fprintf(f, "array(");
        print_array_type(ty->type, f);
        fprintf(f, ", %d, %d)", ty->size, ty->align)
        
        // while (ty->type && isarray(ty->type) && ty->type->type->size > 0) {
        // }
        fprintf(f, ", %d, %d)", ty1->size, ty1->align);
   }
   else {
        fprintf(f, "incomplete array");
   }



   if (ty->size > 0 && ty->type && ty->type->size > 0) { 
        ty1 = ty;
        while (ty->type && isarray(ty->type) && ty->type->type->size > 0) {
           print_array_type(ty->type, f);
           ty = ty->type;
        }

        fprintf("array(%s, %d, %d", ty1->size, ty1->align);
        fprint(f, "array %d", ty->size/ty->type->size);

   if (ty->size > 0 && ty->type && ty->type->size > 0) {
        fprint(f, "array %d", ty->size/ty->type->size);
        while (ty->type && isarray(ty->type) && ty->type->type->size > 0) {
   		    ty = ty->type;
   		    fprint(f, ",%d", ty->size/ty->type->size);
   	    }
   } else
        fprint(f, "incomplete array");
   if (ty->type)
        fprint(f, " of %t", ty->type);
}
*/

static void print_symbol(Symbol sym, void* cl) {
   extern int sym_print_in_detail;
   const char* sclass_str;
   int old_style_flag = -1;

   assert(sym_print_file);
   sclass_str = get_sclass_str(sym->sclass);
   // assert(sym->type);
   if( sym->type && sym->type->op == FUNCTION ) {
       old_style_flag = sym->type->u.f.oldstyle;
   }
   fprintf(sym_print_file, "   %s: %s%s%s[defined=%d]%s%s%s%s[ref=%.1f]", 
           sym->name,
           sclass_str ? "[" : "",
           sclass_str ? sclass_str : "",
           sclass_str ? "]" : "",
           sym->defined,
           (sym->generated ? "[gen]" : ""),
           (sym->temporary ? "[tmp]" : ""),
           (sym->addressed ? "[addressed]" : ""),
           (old_style_flag >= 0 ? (old_style_flag == 1 ? "[oldstyle]" : "[newstyle]")
               : ""),
           sym->ref
          );

   fprintf(sym_print_file, " | ");
   if( sym->type )  {
      print_decl(sym, sym->type, sym_print_file);
      if( sym_print_in_detail ) {
         // print type info in sym->type{->type} order
         fprint(sym_print_file, " | %t", sym->type);
      }
   }  
   fprintf(sym_print_file, "\n");
}

void init_symbol_dump_file(void) {
   char  sym_print_file_name[260];
   char* str = NULL;

   str = getenv("LCC_SYM_DUMP_ENABLE");
   if( str && strcmp(str, "true") == 0 ) 
      ;
   else 
     return;
   
   str = getenv("LCC_SYM_DUMP_DETAIL");
   if( str && strcmp(str, "true") == 0 ) 
      sym_print_in_detail = 1;

   memset(sym_print_file_name, 0, 260);
   assert(file);
   strcpy(sym_print_file_name, file);
   for( str = sym_print_file_name; *str != '.'; ++str)
      ;

   strcpy(++str, "sym");
   sym_print_file = fopen(sym_print_file_name, "w" );
}

void print_function_symbols(Symbol* callee, Symbol* caller) {
   const char* str = NULL;
   int i = 0;
   if( !sym_print_file )
      return;
   
   if( !checkemptytable(stmtlabs, LABELS) )
   {
      fprintf(sym_print_file, "   ++++++++++ stmtlabs symbols ++++++++++\n");
      foreach(stmtlabs, LABELS, print_symbol, NULL);
   }
   
   if( !checkemptytable(labels, LABELS) )
   {
      fprintf(sym_print_file, "   ++++++++++ labels symbols ++++++++++\n");
      foreach(labels, LABELS, print_symbol, NULL);
   }
   fprintf(sym_print_file, "\n");
   
   fprintf(sym_print_file, "\n   [function defn] ");
   //str = get_sclass_str(cfunc->sclass);
   //fprintf(sym_print_file, "%s ", str ? str : "" );
   
   print_decl(cfunc, cfunc->type, sym_print_file);
   fprintf(sym_print_file, " %s\n", (cfunc->type->u.f.oldstyle ? "oldstyle" : ""));
   
   fprintf(sym_print_file, "   [function callee] ");
   if( callee[0] || !cfunc->type->u.f.oldstyle ) {
      fprintf(sym_print_file, "{");
      for( ; callee[i]; ++i ) {
         print_decl(callee[i], callee[i]->type, sym_print_file);

         if( callee[i+1] != NULL ) {
            fprintf(sym_print_file, ", ");
         }
      }
      fprintf(sym_print_file, "}\n");
   }
   else {
      fprintf(sym_print_file, "NULL\n");
   }
   
   fprintf(sym_print_file, "   [function caller] ");
   if( caller[0] || !cfunc->type->u.f.oldstyle ) {
      fprintf(sym_print_file, "{");
      for( i = 0; caller[i]; ++i ) {
         if( caller[i]->sclass == REGISTER ) {
            fprintf(sym_print_file, "register");
         }
         print_decl(caller[i], caller[i]->type, sym_print_file);
         if( caller[i+1] != NULL ) {
            fprintf(sym_print_file, ", ");
         }
      }
      fprintf(sym_print_file, "}\n");
   }
   else {
      fprintf(sym_print_file, "NULL\n");
   }
   
   fprintf(sym_print_file, "-------------------end a function definition----------------\n\n");
   function_switch = 1;
}
void print_local_symbols(void) {
   if( !sym_print_file )
      return;
   // assert( level >= LOCAL );

   if( function_switch ) {  // when print on a closed function, function starts
      function_switch = 0;
      fprintf(sym_print_file, "-----------------start a function definition----------------\n");
   }

   if ( !checkemptytable(identifiers, level) ) 
   {
      if( level == PARAM ) {
         fprintf(sym_print_file, "   ++++++ PARAM identifier symbols ++++++\n");
      }
      else if( level == LOCAL ) {
         fprintf(sym_print_file, "   ++++++ LOCAL identifier symbols ++++++\n");
      }
      else {
         fprintf(sym_print_file, "   ++++++ LOCAL+%d identifier symbols ++++++\n", level-LOCAL);
      }
      foreach(identifiers, level, print_symbol, NULL);
   }
   
   if( !checkemptytable(types, level) )
   {
      if( level == PARAM ) {
         fprintf(sym_print_file, "   ++++++ PARAM type symbols ++++++\n");
      }
      else if( level == LOCAL ) {
         fprintf(sym_print_file, "   ++++++ LOCAL type symbols ++++++\n");
      }
      else {
         fprintf(sym_print_file, "   ++++++ LOCAL+%d type symbols ++++++\n", level-LOCAL);
      }
      foreach(types, level, print_symbol, NULL);
   }
   fprintf(sym_print_file, "\n");
   
}

void print_global_symbols(void)
{
   if( !sym_print_file )
      return;
  
   fprintf(sym_print_file, "\n");
   if( !checkemptytable(externals, GLOBAL) ) {
      fprintf(sym_print_file, "--------------------------`externals' symbols -----------------------------------\n");
      foreach(externals, GLOBAL, print_symbol, NULL);
   }
   
   if( !checkemptytable(globals, GLOBAL) ) {
      fprintf(sym_print_file, "\n------------------------ `globals' symbols ------------------------------\n");
      foreach(globals, GLOBAL, print_symbol, NULL);
   }

   if( !checkemptytable(constants, GLOBAL) ) {
      fprintf(sym_print_file, "\n-------------------------- `constants' symbols ---------------------------------\n");
      foreach(constants, CONSTANTS, print_symbol, NULL);   
   }
   
   if( !checkemptytable(types, GLOBAL) ) {
      fprintf(sym_print_file, "\n--------------------------- `types' symbols --------------------------------------\n");
      foreach(types, GLOBAL, print_symbol, NULL);   
   }

   /*
   fprintf(sym_print_file, "\n--------------------------- labels symbols -------------------------------------\n");
   if( labels ) {
      foreach(labels, GLOBAL, print_symbol, NULL);   
   }
   */
   
   fprintf(sym_print_file, "-------------------------------------------------------------------------------\n");   
   fclose(sym_print_file);
}

