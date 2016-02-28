struct Student{
   int id;
   char* name;
   float scores[5];
};


float get_average_score(struct Student a);

float get_average_score_2(a) struct Student a;
{
   int i = 0; 
   float avg_score = 0.0;
   for( ; i < 5; ++i ) {
      avg_score += a.scores[i]/5;
   }

   return avg_score;
}
