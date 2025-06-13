#include "../includes/fdf.h"

static t_point	rotate_point(t_point p, t_fdf *data)
{
	t_point	point;
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;

	tmp_y = p.y * cos(degrees_to_radians(data->angle_x))
		- p.z * data->altitude * sin(degrees_to_radians(data->angle_x));
	tmp_z = p.y * sin(degrees_to_radians(data->angle_x))
		+ p.z * data->altitude * cos(degrees_to_radians(data->angle_x));
	p.y = tmp_y;
	p.z = tmp_z;
	tmp_x = p.x * cos(degrees_to_radians(data->angle_y))
		+ p.z * sin(degrees_to_radians(data->angle_y));
	tmp_z = -p.x * sin(degrees_to_radians(data->angle_y))
		+ p.z * cos(degrees_to_radians(data->angle_y));
	p.x = tmp_x;
	tmp_x = p.x * cos(degrees_to_radians(data->angle_z))
		- p.y * sin(degrees_to_radians(data->angle_z));
	tmp_y = p.x * sin(degrees_to_radians(data->angle_z))
		+ p.y * cos(degrees_to_radians(data->angle_z));
	point.x = tmp_x;
	point.y = tmp_y;
	point.z = tmp_z;
	return (point);
}

/**
 * Projects a point from 3D space to 2D space using isometric projection.
 */
static t_point	project_isometric(t_point p, t_fdf *data)
{
	t_point	rotated;
	t_point	point;
	double	angle;

	rotated = rotate_point(p, data);
	angle = degrees_to_radians(data->angle);
	point.x = (rotated.x - rotated.y) * cos(angle) * data->zoom
		+ data->offset_x;
	point.y = (rotated.x + rotated.y) * sin(angle) * data->zoom
		- (rotated.z * data->zoom) + data->offset_y;
	if (data->colored)
	{
		if (p.color != -1)
			point.color = p.color;
		else
			point.color = 0xFFFFFF;
	}
	else
	{
		point.color = get_terrain_color(p.z * data->altitude,
				-data->map_max * abs(data->altitude) * 0.9,
				data->map_max * abs(data->altitude) * 0.9);
	}
	return (point);
}

/**
 * Projects a point from 3D space to 2D space using perspective projection.
 */
static t_point	project_perspective(t_point p, t_fdf *data)
{
	t_point	point;
	double	view_distance;
	double	factor;

	view_distance = fmax(WIDTH, HEIGHT) * 1.5 + data->map_max * data->zoom;
	if (view_distance - p.z * data->altitude < 1)
		view_distance = p.z * data->altitude + 1;
	factor = view_distance / (view_distance - p.z * data->altitude);
	point.x = p.x * factor * data->zoom + data->offset_x;
	point.y = p.y * factor * data->zoom + data->offset_y;
	point.z = p.z * data->altitude;
	if (data->colored)
		point.color = p.color;
	else
		point.color = get_terrain_color(p.z * data->altitude,
				-data->map_max * abs(data->altitude) * 0.9,
				data->map_max * abs(data->altitude) * 0.9);
	return (point);
}

t_point	project_point(t_point p, t_fdf *data)
{
	if (data->projection_type == ISOMETRIC)
	{
		data->angle = ISOMETRIC_ANGLE;
		return (project_isometric(p, data));
	}
	else if (data->projection_type == PERSPECTIVE)
	{
		return (project_perspective(p, data));
	}
	else
	{
		data->angle = 180;
		return (project_isometric(p, data));
	}
}
