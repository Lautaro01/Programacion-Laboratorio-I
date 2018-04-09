void ordenar (int vec[], int TAM, int criterio)
{
    int i;
    int j;
    int aux;

    for(i=0;i<TAM-1;i++)
    {
    for(j=i+1;j<TAM;j++)
        {
            if(criterio == 0)
            {
                if(vec[i]>vec[j])
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
            else if (criterio == 1)
            {
                if(vec[i]<vec[j])
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }

        }
    }
}

void mostrarVector(int vec[],int tam){

for(int i=0; i< tam; i++)
    {

        printf("%d ", vec[i]);
    }
    printf("\n\n");
}
