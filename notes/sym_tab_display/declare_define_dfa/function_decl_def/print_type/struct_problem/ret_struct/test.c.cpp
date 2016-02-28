# 1 "test.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "test.c"
struct Student{
   int id;
   char* name;
   float avg_score;
} stu[2] = {
   101,
   "lily",
   83.5,
   102,
   "jane",
   90.4
};

struct Student get_s_by_id(int id);

struct Student get_s_by_id_2(id) int id; {
  assert(id >= 0 && id < 2);
  return stu[id];
}
