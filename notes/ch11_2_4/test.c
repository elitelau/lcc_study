static int i;

struct st {
  static int i;
  register int j;
  typedef struct st_internal {
     int i;
     int j;
  } internal;
};
