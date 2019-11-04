# include "fdf.h"

t_koord	**make_field(int len_i, int len_j, int **matr, int *max_z)
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
			vertex[i][j].x = i + len_i / 2;
			vertex[i][j].y = j + len_j / 2;
			vertex[i][j].z = matr[i][len_j - j - 1];
			if (vertex[i][j].z > *max_z)
				*max_z = vertex[i][j].z;
			//vertex[i][j].color = 0xFF0000;
			//((matr[i][len_j - j - 1] * 3) 
			j++;
		}
		i++;
	}
	return (vertex);
}

void	fill_color(int len_i, int len_j, t_koord **vertex, int max_z, int zero_color, int max_color)
{
	int	i;
	int	j;

	i = 0;
	while (i < len_i)
	{
		j = 0;
		while (j < len_j)
		{
			vertex[i][j].color = zero_color + (max_color - zero_color) * vertex[i][j].z / max_z;
			//((matr[i][len_j - j - 1] * 3) * (16 * 16 + 16 + 1)) % (16 * 16 * 16)
			j++;
		}
		i++;
	}
}
