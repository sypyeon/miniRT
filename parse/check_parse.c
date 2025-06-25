#include "rt_minirt.h"

void	check_parse_data(t_rt_info *info)
{
	printf("amb ratio:\t%f\n", info->amb.amb_ratio);
	printf("amb color r:\t%f\n", info->amb.color.r);
	printf("amb color g:\t%f\n", info->amb.color.g);
	printf("amb color b:\t%f\n\n", info->amb.color.b);
	printf("cam focal length:\t%f\n", info->cam.focal_len);
	printf("cam horizontal x:\t%f\n", info->cam.horizontal.x);
	printf("cam horizontal y:\t%f\n", info->cam.horizontal.y);
	printf("cam horizontal z:\t%f\n", info->cam.horizontal.x);
	printf("cam left bottom x:\t%f\n", info->cam.left_bottom.x);
	printf("cam left bottom y:\t%f\n", info->cam.left_bottom.y);
	printf("cam left bottom z:\t%f\n", info->cam.left_bottom.z);
	printf("cam origin x:\t%f\n", info->cam.orig.x);
	printf("cam origin y:\t%f\n", info->cam.orig.y);
	printf("cam origin z:\t%f\n", info->cam.orig.z);
	printf("cam vertical x:\t%f\n", info->cam.vertical.x);
	printf("cam vertical y:\t%f\n", info->cam.vertical.y);
	printf("cam vertical z:\t%f\n", info->cam.vertical.z);
	printf("cam viewpoint width:\t%f\n", info->cam.viewport_w);
	printf("cam viewpoint height:\t%f\n\n", info->cam.viewport_h);
	printf("light brightness:\t%f\n", info->light.bright);
	printf("light color r:\t%f\n", info->light.color.r);
	printf("light color g:\t%f\n", info->light.color.g);
	printf("light color b:\t%f\n", info->light.color.b);
	printf("light origin x:\t%f\n", info->light.orig.y);
	printf("light origin y:\t%f\n", info->light.orig.z);
	printf("light origin z:\t%f\n\n", info->light.orig.x);
	t_obj *object = info->obj.head;
	char *id;
	while (object)
	{
		if (object->identifier == PLANE)
			id = "Plane";
		if (object->identifier == SPHERE)
			id = "Sphere";
		if (object->identifier == CYLINDER)
			id = "Cylinder";
		printf("%s center.x\t%f\n", id, object->center.x);
		printf("%s center.y\t%f\n", id, object->center.y);
		printf("%s center.z\t%f\n", id, object->center.z);
		printf("%s color.r\t%f\n", id, object->color.r);
		printf("%s color.g\t%f\n", id, object->color.g);
		printf("%s color.b\t%f\n", id, object->color.b);
		printf("%s vector.x\t%f\n", id, object->vector.x);
		printf("%s vector.y\t%f\n", id, object->vector.y);
		printf("%s vector.z\t%f\n", id, object->vector.z);
		printf("%s diameter\t%f\n", id, object->diameter);
		printf("%s height\t%f\n\n", id, object->height);
		object = object->next;
	}
}