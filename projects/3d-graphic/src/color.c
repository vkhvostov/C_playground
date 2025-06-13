#include "../includes/fdf.h"

#define WHITE 0xFFFFFF
#define YELLOW 0xFFFF00
#define ORANGE 0xFFA500
#define RED 0xFF0000
#define VIOLET 0x8B00FF
#define GREEN 0x00FF00
#define LIGHT_BLUE 0x00FFFF
#define BLUE 0x0000FF
#define DARK_BLUE 0x00008B

static t_color	init_colors(void)
{
	t_color	color;

	color.pos_colors[0] = WHITE;
	color.pos_colors[1] = YELLOW;
	color.pos_colors[2] = ORANGE;
	color.pos_colors[3] = RED;
	color.pos_colors[4] = VIOLET;
	color.neg_colors[0] = WHITE;
	color.neg_colors[1] = GREEN;
	color.neg_colors[2] = LIGHT_BLUE;
	color.neg_colors[3] = BLUE;
	color.neg_colors[4] = DARK_BLUE;
	color.thresholds[0] = 0.0;
	color.thresholds[1] = 0.25;
	color.thresholds[2] = 0.5;
	color.thresholds[3] = 0.75;
	color.thresholds[4] = 1.0;
	return (color);
}

/**
 * Interpolates between two colors based on a given factor.
 * @param color1 The first color.
 * @param color2 The second color.
 * @param f The interpolation factor.
 * @return The interpolated color.
 */
uint32_t	interpolate_color(uint32_t color1, uint32_t color2, double f)
{
	int	red;
	int	green;
	int	blue;

	red = ((color1 >> 16) & 0xFF) * (1 - f) + ((color2 >> 16) & 0xFF) * f;
	green = ((color1 >> 8) & 0xFF) * (1 - f) + ((color2 >> 8) & 0xFF) * f;
	blue = (color1 & 0xFF) * (1 - f) + (color2 & 0xFF) * f;
	return ((red << 16) | (green << 8) | blue);
}

/**
 * Returns a color based on the altitude of a point.
 * @param z The altitude of the point.
 * @param z_min The minimum altitude in the map.
 * @param z_max The maximum altitude in the map.
 * @return The color of the point.
 */
uint32_t	get_terrain_color(int z, int z_min, int z_max)
{
	t_color		data;
	double		normalized_z;
	uint32_t	*colors;
	double		t;
	int			index;

	if (z_max == z_min)
		return (WHITE);
	data = init_colors();
	normalized_z = 2.0 * (z - z_min) / (z_max - z_min) - 1.0;
	if (normalized_z >= 0)
		colors = data.pos_colors;
	else
		colors = data.neg_colors;
	t = fabs(normalized_z);
	index = 0;
	while (index < 4)
	{
		if (t < data.thresholds[index + 1])
			return (interpolate_color(colors[index], colors[index + 1],
					(t - data.thresholds[index]) / (data.thresholds[index + 1]
						- data.thresholds[index])));
		index++;
	}
	return (colors[4]);
}
