#include <stdio.h>

float lsd(float n)
{
        return ((int) n) % 10;
}

float msd(float n)
{
        return ((int) n) / 10;
}

int main(int argc, char *argv[])
{
        for(float den  = 13.0; den < 100.0; den++)
        {
                for(float num = 12.0; num < den; num++)
                {
                        const float frac = num/den;

                        const float num_lsd = lsd(num);
                        const float num_msd = msd(num);
                        const float den_lsd = lsd(den);
                        const float den_msd = msd(den);

                        if(num_lsd == 0 || den_lsd == 0) continue;

                        if(num_lsd == den_lsd &&
                                num_msd/den_msd == frac)
                                printf("%g/%g = %g/%g\n",
                                        num_msd,den_msd, num, den);



                        if(num_lsd == den_msd &&
                                num_msd/den_lsd == frac)
                                printf("%g/%g = %g/%g\n",num_msd,den_lsd,num,den);

                        if(num_msd == den_lsd &&
                                num_lsd/den_msd == frac)
                                printf("%g/%g = %g/%g\n",num_lsd,den_msd, num, den);

                        if(num_msd == den_msd &&
                                num_lsd/den_msd == frac)
                                printf("%g/%g = %g/%g\n",num_lsd,den_msd, num, den);
                }
        }
        return 0;
}
