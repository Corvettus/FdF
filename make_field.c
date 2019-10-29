# include "fdf.h"

t_koord	**make_field(int len_i, int len_j, int **matr)
{
	t_koord	**vertex;
	int	i;
	int	j;

	vertex = (t_koord **)malloc(sizeof(t_koord *) * len_i);
	i = -1;
	while (++i < len_i)
		vertex[i] = (t_koord *)malloc(sizeof(t_koord) * len_j);
	i = 0;
	while (i < len_i)
	{
		j = 0;
		while (j < len_j)
		{
			//vertex[len_i - i - 1][len_j - j - 1].x = i * 30;
			//vertex[len_i - i - 1][len_j - j - 1].y = j * 30;
			//vertex[len_i - i - 1][len_j - j - 1].z = matr[i][j] * 3;
			vertex[i][j].x = i * 10;
			vertex[i][j].y = j * 10;
			vertex[i][j].z = matr[i][len_j - j - 1] * 3;
			j++;
		}
		i++;
	}
	return (vertex);
}