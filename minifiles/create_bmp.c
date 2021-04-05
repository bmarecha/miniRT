#include "minirt.h"
#define HEAD_SIZE 122




void	export_bmp(char *filename, t_scene *scene)
{
	int		fd;
	unsigned int	size;
	unsigned int	i;
	char		*data;

	size = scene->xsize * scene->ysize * 3;
	data = malloc((size + HEAD_SIZE));
	if (!(data))
		return;
	i = 0;
	while (i < size + HEAD_SIZE)
		data[i++] = 0;
//	header_bmp(&data, scene);
//	fill_bmp(&data, scene);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd <= 0)
		error_exit(-5);
	write(fd, data, (size + HEAD_SIZE));
	close(fd);
	free(data);
}
