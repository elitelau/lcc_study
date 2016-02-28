#ifndef PRINT_DAG_H 
#define PRINT_DAG_H

#define DAG_NAME_LENGTH 100

struct tree; 
extern char* file;
extern int lineno;
// extern FILE* dag_print_file; 

static char prev_dag_name[DAG_NAME_LENGTH];

// void print_dag(Tree p);
void print_dag(struct tree* t);

///////////////////////////////////////////////////////////////////////////////

void init_symbol_dump_file(void);

void print_global_symbols(void);
void print_local_symbols(void);

#endif
