
typedef struct student {
   unsigned int id;
   const char* name;
   float avg_score;
} student;

//extern student S[];
//extern int student_struct_size;
//extern int num_of_student;
student  S[3] = {
  201, "lily", 80.3, 
  107, "lucy", 86.4,
  302, "christophe", 94.7
};

void print_student(student* person) {
   printf( "%s has average score of %f.\n", person->name, person->avg_score);
}

extern int student_struct_size;
int student_struct_size = sizeof(student);
int num_of_student = 3;

void print_all_student_info(void);

int main(int argc, char** argv) {
   print_all_student_info();
   return 0;
}
