
typedef struct student student;
extern student S[];
extern int student_struct_size;
extern int num_of_student;

void print_student(void* );

void print_all_student_info(void) {
   int i = 0; 
   for( ; i < num_of_student; ++i ) {
      // note: it's invisible to know the sizeof (struct student)
      print_student( (void*)((char*)(student*)S + student_struct_size*i) );
   }
}
