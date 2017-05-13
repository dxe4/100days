#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <glib.h>
#include <omp.h>

// libgsl0-dev
#include <gsl/gsl_math.h>
#include <gsl/gsl_rng.h>
#include <sys/time.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_sort_double.h>


double pi(int n, int batch) {
    const gsl_rng_type * T;
    gsl_rng * r;
    gsl_rng_env_setup();


    T = gsl_rng_default;
    r = gsl_rng_alloc (T);

    int end = (n / batch);
    double sum = 0;

    int i, j;
    // GRand * grand = g_rand_new ();
    //g_rand_double(grand);
    #pragma omp parallel for default(shared)  firstprivate(r) private(j)  reduction (+:sum)
    for (i = 0; i < end; i++) {
        for (j=0; j<batch; j++) {
            double a = gsl_rng_uniform_pos (r);
            double b = gsl_rng_uniform_pos (r);
            double c = (a * a) + (b * b);

            if (c <= 1) {
                sum += c;
            }
        }
    }
    return 8 * sum / n;
}

int main () {
    printf("%0.15f\n", pi(100000000, 1000));
}
