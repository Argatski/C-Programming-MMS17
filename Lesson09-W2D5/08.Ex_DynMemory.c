#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) 
{
  void *p= malloc(sizeof(double));
  //preporuchano e da se zadelq pamet s sizeof)
   ///zadelq pamet v heap i pazi adres ne vrushta nishto;

   double *d_p=p;         //ne e nujno da kastvame zashtoto to actomatichno se kastava

   *d_p=12.5;
   printf("%f\n",*d_p);

   free(p); // za osvobojdavane na pamet trqbva da podadem adresa
   //moje i d_p da podadem
   //nemojem edin obek da go asociirame s mnogo tipove
  //Ako podademe NULL pointer na free nqma da se sluchi nishto nqma problem da se pravi no nqa da se sluchi nishto
    
    //Mojem da izvikame malok s "0" bite.

    //Calloc raboti kato mallco samo che inicializira s pameta s nuli.
    void *p2=calloc(sizeof(double), sizeof(double));
    //moje da osvobodim s free
    //nemojem da dereferirame void(*p) pointera

    double *d_p2=p2;
    printf("%lf\n", *d_p2);

    //realloc podavame mu ukazatel i nov razmer i toi shte e prezadeli i tazi pamet moje da e uvelichena ili smalena za reazshirqvane i namalqne na masiva
    int *p_i =p2;
    p_i[0] = 123;
    p_i[1] = 123;
    p_i[2] = 123;

  int *p3=  realloc(p_i, sizeof(int)*300); //vrushta adresa na novo zadelenata dinamichna pamet.
    int *d_p3 = p;

    printf("%d\n", p3[0]);

    free(p3);
   return 0;
}