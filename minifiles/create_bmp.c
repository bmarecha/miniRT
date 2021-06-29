#include "minirt.h"
#define HEAD_SIZE 54
#define TYPE_BITMAP1 0x42
#define TYPE_BITMAP2 0x4D
#define PERSONAL_SIGN 0
#define OFFSET 0x36
#define IMG_START 40
#define BPP 32
#define PPM 2835

void	assign_int(char *octets, int nbr)
{
	octets[0] = nbr & 255;
	octets[1] = (nbr >> 8) & 255;
	octets[2] = (nbr >> 16) & 255;
	octets[3] = (nbr >> 24) & 255;
}

void	header_bmp(char *data, t_scene *scene, int size)
{
	int	i;
	char	*img;

	data[0] = TYPE_BITMAP1;
	data[1] = TYPE_BITMAP2;
	assign_int(data + 2, size + HEAD_SIZE);
	assign_int(data + 6, PERSONAL_SIGN);
	assign_int(data + 10, OFFSET);
	assign_int(data + 14, 40);
	assign_int(data + 18, scene->xsize);
	assign_int(data + 22, -scene->ysize);
	data[26] = 1;
	data[28] = BPP;
	assign_int(data + 30, 0);
	assign_int(data + 34, size);
	assign_int(data + 38, PPM);
	assign_int(data + 42, PPM);
	assign_int(data + 46, 0);
	assign_int(data + 50, 0);
	i = -1;
	img = scene->img->data;
	while (++i < scene->img->sizeline * scene->ysize)
		data[i + 54] = img[i];
}

int	export_bmp(char *filename, t_scene *scene)
{
	int		fd;
	unsigned int	size;
	unsigned int	i;
	char		*data;

	size = scene->xsize * scene->ysize * 4;
	data = malloc((size + HEAD_SIZE) + 1);
	if (!(data))
		return (EXIT_FAILURE);
	i = 0;
	while (i < size + HEAD_SIZE + 1)
		data[i++] = 0;
	header_bmp(data, scene, size);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd <= 0)
		error_exit(-5);
	write(fd, data, (size + HEAD_SIZE));
	close(fd);
	free(data);
	return (EXIT_SUCCESS);
}
